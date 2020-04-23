/**
 * File              : PiBoy.cpp
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.03.2020
 * Last Modified Date: 15.04.2020
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include "SplashScreen.hpp"
#include "Api.hpp"
#include "Udi.hpp"
#include "PiBoy.hpp"

PiBoy::PiBoy()
  : _running(true)
{
  // Lua initialization
  _lua.open_libraries(sol::lib::base, sol::lib::io, sol::lib::math, sol::lib::os);
  // Loading config file
  _lua.script_file(CONFIG_FILE);
  // Raylib initialization
  InitWindow(_lua["config"]["resolution"]["x"],
      _lua["config"]["resolution"]["y"],
      "PiBoy");
  // Sets FPS
  SetTargetFPS(_lua["config"]["fps"]);
  // Hides the cursor
  HideCursor();
  if (_lua["config"]["fullscreen"])
    ToggleFullscreen();
  // Loads the default font from the config
  std::string font_path = _lua["config"]["font"];
  std::cout << "Loading font at:" << font_path << std::endl;
  _font = LoadFont(font_path.c_str());

  // Creates the splash screen
  current_screen = new SplashScreen(this);

  // Api initialization
  Api::init(this);
  // Udi initialization
  Udi::init(this);
}

int		PiBoy::run()
{
  while (_running && !WindowShouldClose())
  {
    // Updates the current screen
    current_screen->update(GetFrameTime());
    BeginDrawing();
    // Clears the background
    ClearBackground(RAYWHITE);
    // Renders the current screen
    current_screen->render(GetFrameTime());
    // Draws fps if param in config is true
    if (_lua["config"]["show_fps"])
      DrawFPS(0, 0);
    EndDrawing();
  }
  return (0);
}
