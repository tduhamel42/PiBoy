--[[--
File              : config.lua
Author            : Tanguy Duhamel <tanguydu@gmail.com>
Date              : 11.03.2020
Last Modified Date: 16.04.2020
Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
--]]--

config = {
  version = "0.2",
  fullscreen = true,
  resolution = {width = 800, height = 480},
  fps = 30,
  -- Pins of the buttons
  pins = { UP = 5, DOWN = 3, RIGHT = 0, LEFT = 2, A = 1, B = 4},
  -- Default font
  font = "./assets/font.ttf",
  -- Show FPS
  show_fps = true,
  -- Games directory
  games_dir = "./games",
  -- Enables time between clicks
  button_timer_enable = true
}
