/**
 * File              : SplashScreen.cpp
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.03.2020
 * Last Modified Date: 15.04.2020
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <iostream>
#include "Api.hpp"
#include "MainScreen.hpp"
#include "SplashScreen.hpp"

SplashScreen::SplashScreen(PiBoy *pb)
  : _pb(pb), _time(0)
{
  _background = LoadTexture("./assets/piboy_white.png");
}

int		SplashScreen::update(float delta)
{
  _time += delta;
  if (_time >= 3)
  {
    _pb->current_screen = new MainScreen(_pb);
  }
  return (0);
}

int		SplashScreen::render(float /*delta*/)
{
  DrawTexture(_background, 0, 0, RAYWHITE);
  return (0);
}
