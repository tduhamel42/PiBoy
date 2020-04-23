/**
 * File              : Api.hpp
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 12.03.2020
 * Last Modified Date: 15.04.2020
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef API_HPP_
# define API_HPP_

#include <wiringPi.h>
#include <raylib.h>
#include "PiBoy.hpp"

# define isButtonDownA(button) Api::isButtonDown(_pb, button)
# define getButtonPin(button) pb->getLua()["config"]["pins"][button]

class Api
{
  public:

    enum	e_buttons
    {
      BUTTON_UP,
      BUTTON_DOWN,
      BUTTON_RIGHT,
      BUTTON_LEFT,
      BUTTON_A,
      BUTTON_B
    };

    static void		init(PiBoy *pb)
    {
      wiringPiSetup();
      pinMode(pb->getLua()["config"]["pins"]["UP"], INPUT);
      pinMode(pb->getLua()["config"]["pins"]["DOWN"], INPUT);
      pinMode(pb->getLua()["config"]["pins"]["RIGHT"], INPUT);
      pinMode(pb->getLua()["config"]["pins"]["LEFT"], INPUT);
      pinMode(pb->getLua()["config"]["pins"]["A"], INPUT);
      pinMode(pb->getLua()["config"]["pins"]["B"], INPUT);
    }

    static bool		isButtonDown(PiBoy *pb, int button)
    {
      static float	time = 0;
      bool		clicked = false;

      time += GetFrameTime();
      switch (button)
      {
	case BUTTON_UP:
	  clicked = digitalRead(getButtonPin("UP"));
	  break;
	case BUTTON_DOWN:
	  clicked = digitalRead(getButtonPin("DOWN"));
	  break;
	case BUTTON_RIGHT:
	  clicked = digitalRead(getButtonPin("RIGHT"));
	  break;
	case BUTTON_LEFT:
	  clicked = digitalRead(getButtonPin("LEFT"));
	  break;
	case BUTTON_A:
	  clicked = digitalRead(getButtonPin("A"));
	  break;
	case BUTTON_B:
	  clicked = digitalRead(getButtonPin("B"));
	  break;
      }
      if (clicked && (time > 0.5 || !pb->getLua()["config"]["button_timer_enable"]))
      {
	time = 0;
	return (true);
      }
      return (false);
    }
};

#endif /* !API_HPP_ */
