/**
 * File              : piboy_interface.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.09.2019
 * Last Modified Date: 11.09.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <raylib.h>
#include "piboy_interface.h"

int			piboy_interface_init(int width, int height)
{
  InitWindow(width, height, "PiBoy v0.1");
  HideCursor();
  return (0);
}

int			piboy_interface_run()
{
  Texture2D		textures[3];
  float			e;
  int			i = 0;

  textures[0] = LoadTexture("assets/piboy_white.png");
  textures[1] = LoadTexture("assets/piboy_glitch2.png");
  textures[2] = LoadTexture("assets/piboy_glitch1.png");
  e = 0;
  while (!WindowShouldClose())
    {
      e += GetFrameTime();
      if (e > 0.3)
	{
	  ++i;
	  e = 0;
	}
      if (i > 2)
	i = 0;
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawTexture(textures[i], 0, 0, RAYWHITE);
      EndDrawing();
    }
  return (0);
}
