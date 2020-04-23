/**
 * File              : PiBoy.hpp
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.03.2020
 * Last Modified Date: 14.04.2020
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef PIBOY_HPP_
# define PIBOY_HPP_

#include <sol.hpp>
#include <raylib.h>
#include "Screen.hpp"

# define CONFIG_FILE "config.lua"

class PiBoy
{

  bool		_running;
  sol::state	_lua;

  Font		_font;

  public:
    Screen	*current_screen;
    PiBoy();

    int		run();
    sol::state	&getLua()
    {
      return (_lua);
    }
    Font	const &getFont() const
    {
      return (_font);
    }
};

#endif /* !PIBOY_HPP_ */
