/**
 * File              : MainScreen.hpp
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 14.04.2020
 * Last Modified Date: 15.04.2020
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef MAINSCREEN_HPP_
# define MAINSCREEN_HPP_

#include <vector>
#include <raylib.h>
#include "Screen.hpp"
#include "PiBoy.hpp"

class MainScreen : public Screen
{

  PiBoy			*_pb;

  public:
    MainScreen(PiBoy *pb);

    virtual int		render(float delta);
    virtual int		update(float delta);
};

#endif /* !MAINSCREEN_HPP_ */
