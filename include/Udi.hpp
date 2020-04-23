/**
 * File              : Udi.hpp
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 12.03.2020
 * Last Modified Date: 16.04.2020
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef UDI_HPP_
# define UDI_HPP_

#include <map>
#include <vector>
#include <filesystem>
#include <raylib.h>
#include "Api.hpp"
#include "PiBoy.hpp"

/**
 * @brief User developpement interface
 */
class Udi
{

  static Color		getColor(int color)
  {
    static std::map<int, Color> colors = {
      {1, LIGHTGRAY},
      {2, GRAY},
      {3, DARKGRAY},
      {4, YELLOW},
      {5, GOLD},
      {6, ORANGE},
      {7, PINK},
      {8, RED},
      {9, MAROON},
      {10, GREEN},
      {11, LIME},
      {12, DARKGREEN},
      {13, SKYBLUE},
      {14, BLUE},
      {15, DARKBLUE},
      {16, PURPLE},
      {17, VIOLET},
      {18, DARKPURPLE},
      {19, BEIGE},
      {20, BROWN},
      {21, DARKBROWN},
      {22, WHITE},
      {23, BLACK},
      {24, BLANK},
      {25, MAGENTA},
      {26, RAYWHITE}
    }; 
    return (colors[color]);
  }

  static void		initTextFunctions(PiBoy *pb)
  {
    // Test function
    pb->getLua().set_function("hello", []() -> void {std::cout << "Hello world !" << std::endl;});
    // Draw text function
    pb->getLua().set_function("drawText", [=](std::string const &text, int x, int y, int size, int color) -> void {
	DrawTextEx(pb->getFont(), text.c_str(), { static_cast<float>(x), static_cast<float>(y) }, size, 3, getColor(color));
	});
  }

  static void		initInputFunctions(PiBoy *pb)
  {
    // Setting key macros
    pb->getLua().script("BUTTON_UP = 0\nBUTTON_DOWN = 1\nBUTTON_RIGHT = 2\nBUTTON_LEFT = 3\nBUTTON_A = 4\nBUTTON_B = 5");
    // Key down function
    pb->getLua().set_function("isButtonDown", [=](int key) -> bool {
	return (Api::isButtonDown(pb, key));
	});
  }

  static void		initColor(PiBoy *pb)
  {
    pb->getLua().script("LIGHTGRAY = 1\nGRAY = 2\nDARKGRAY = 3\nYELLOW = 4\nGOLD = 5\nORANGE = 6");
    pb->getLua().script("PINK = 7\nRED = 8\nMAROON = 9\nGREEN = 10\nLIME = 11\nDARKGREEN = 12");
    pb->getLua().script("SKYBLUE = 13\nBLUE = 14\nDARKBLUE = 15\nPURPLE = 16\nVIOLET = 17");
    pb->getLua().script("DARKPURPLE = 18\nBEIGE = 19\nBROWN = 20\nDARKBROWN = 21\nWHITE = 22");
    pb->getLua().script("BLACK = 23\nBLANK = 24\nMAGENTA = 25\nRAYWHITE = 26");
  }

  static void		initUtils(PiBoy *pb)
  {
    pb->getLua().set_function("clearBackground", [=](int color) -> void {
	ClearBackground(getColor(color));
	});
    pb->getLua().set_function("loadFile", [=](std::string const &path) -> void {
	pb->getLua().script_file(path);
	});
    pb->getLua().set_function("listDirectory", [&](std::string const &path) -> std::vector<std::string> {
	std::vector<std::string> dirs;
	std::cout << "PATH" << path << std::endl;
	for (const auto &e : std::filesystem::directory_iterator(path))
	{
	  std::cout << e.path() << std::endl;
	  dirs.push_back(e.path());
	}
	return (dirs);
	});
  }

  static void		initTextureFunctions(PiBoy *pb)
  {
    pb->getLua().set_function("loadTexture", [=](std::string const &path) -> Texture2D {
	return (LoadTexture(path.c_str()));
	});
    pb->getLua().set_function("resizeTexture", [=](Texture2D t, int width, int height) -> Texture2D {
	Image img = GetTextureData(t);
	ImageResize(&img, width, height);
	return (LoadTextureFromImage(img));
	});
    pb->getLua().set_function("drawTexture", [=](Texture2D t, int x, int y, int color) -> void {
	DrawTexture(t, x, y, getColor(color));
	});
  }

  static void		initDrawFunctions(PiBoy *pb)
  {
    pb->getLua().set_function("drawPixel", [=](int x, int y, int color) -> void {
	DrawPixel(x, y, getColor(color));
	});
    pb->getLua().set_function("drawLine", [=](int start_x, int start_y, int end_x, int end_y, int color) -> void {
	DrawLine(start_x, start_y, end_x, end_y, getColor(color));
	});
    pb->getLua().set_function("drawCirle", [=](int x, int y, float radius, int color) -> void {
	DrawCircle(x, y, radius, getColor(color));
	});
    pb->getLua().set_function("drawRectangle", [=](int x, int y, int width, int height, int color) -> void {
	DrawRectangle(x, y, width, height, getColor(color));
	});
    pb->getLua().set_function("drawRectangleLines", [=](int x, int y, int width, int height, int color) -> void {
	DrawRectangleLines(x, y, width, height, getColor(color));
	});
  }

  static void		initCollisionFunctions(PiBoy *pb)
  {
    pb->getLua().set_function("createRectangle", [=](float x, float y, float width, float height) -> Rectangle {
	Rectangle r = {x, y, width, height};
	return (r);
	});
    pb->getLua().set_function("checkCollisionRecs", [=](Rectangle r1, Rectangle r2) -> bool {
	return (CheckCollisionRecs(r1, r2));
	});
  }

  public:
  static void		init(PiBoy *pb)
  {
    pb->getLua().script("SCREEN_WIDTH = 640\nSCREEN_HEIGHT = 480");
    initTextFunctions(pb);
    initInputFunctions(pb);
    initColor(pb);
    initUtils(pb);
    initTextureFunctions(pb);
    initDrawFunctions(pb);
    initCollisionFunctions(pb);
  }
};

#endif /* !UDI_HPP_ */
