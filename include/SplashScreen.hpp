/**
 * File              : SplashScreen.hpp
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.03.2020
 * Last Modified Date: 11.03.2020
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef SPLASH_SCREEN_HPP_
# define SPLASH_SCREEN_HPP_

#include <raylib.h>
#include "Screen.hpp"
#include "PiBoy.hpp"

class SplashScreen : public Screen
{

  PiBoy			*_pb;
  Texture2D		_background;
  float			_time;

  public:
    SplashScreen(PiBoy *pb);

    virtual int		render(float delta);
    virtual int		update(float delta);
};

#endif /* !SPLASH_SCREEN_HPP_ */
