/**
 * File              : MainScreen.cpp
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 14.04.2020
 * Last Modified Date: 15.04.2020
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include "Api.hpp"
#include "MainScreen.hpp"

MainScreen::MainScreen(PiBoy *pb)
  : _pb(pb)
{
  _pb->getLua().script_file("./srcs/lua/mainscreen.lua");
  _pb->getLua().script("init()");
}

int		MainScreen::update(float /*delta*/)
{
  _pb->getLua().script("update()");
  return (0);
}

int		MainScreen::render(float /*delta*/)
{
  _pb->getLua().script("render()");
  return (0);
}
