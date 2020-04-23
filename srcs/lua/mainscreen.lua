--[[--
File              : mainscreen.lua
Author            : Tanguy Duhamel <tanguydu@gmail.com>
Date              : 15.04.2020
Last Modified Date: 16.04.2020
Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
--]]--

local menus = {"Games", "Settings", "Infos"}
local selected = 1
local background = loadTexture("./assets/title_screen.png")

function init()
end

function update()
  if (isButtonDown(BUTTON_RIGHT))
    then
      selected = selected + 1
      if (selected > 3)
	then
	  selected = 1
	end
      end
  if (isButtonDown(BUTTON_LEFT))
    then
      selected = selected - 1
      if (selected < 1)
	then
	  selected = 3
	end
      end
  if (isButtonDown(BUTTON_A))
    then
      if (selected == 1)
	then
	  loadFile("./srcs/lua/gamesscreen.lua")
	end
    end
end

function render()
  -- Background
  drawTexture(background, 0, 0, RAYWHITE)
  -- Version
  drawText("Version " .. config["version"], SCREEN_WIDTH - 140, SCREEN_HEIGHT - 30, 20, BLACK)
  if (selected == 1)
    then
      drawText(menus[1], 50, (SCREEN_HEIGHT / 2), 50, GREEN)
    else
      drawText(menus[1], 50, (SCREEN_HEIGHT / 2), 50, BLACK)
    end
  if (selected == 2)
    then
      drawText(menus[2], 225, (SCREEN_HEIGHT / 2), 50, GREEN)
    else
      drawText(menus[2], 225, (SCREEN_HEIGHT / 2), 50, BLACK)
    end
  if (selected == 3)
    then
      drawText(menus[3], 450, (SCREEN_HEIGHT / 2), 50, GREEN)
    else
      drawText(menus[3], 450, (SCREEN_HEIGHT / 2), 50, BLACK)
    end
end
