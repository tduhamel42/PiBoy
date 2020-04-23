--[[--
File              : gamesscreen.lua
Author            : Tanguy Duhamel <tanguydu@gmail.com>
Date              : 15.04.2020
Last Modified Date: 16.04.2020
Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
--]]--

local games = {}
-- Scanning directory
print(config["games_dir"])
games = listDirectory(config["games_dir"])
local selected_game = 1
loadFile(games[selected_game] .. "/infos.lua")
img = resizeTexture(loadTexture(games[selected_game] .. "/" .. infos["img"]), 213, 160)

function getLen(array)
  nbr = 0
  for i, val in pairs(games) do
    nbr = nbr + 1
  end
  return (nbr)
end

function update()
  if (isButtonDown(BUTTON_B))
    then
      loadFile("./srcs/lua/mainscreen.lua")
    end
  if (isButtonDown(BUTTON_A))
    then
      CURRENT_DIR = games[selected_game] .. "/"
      -- This is important in order to have smooth movements in game
      config["button_timer_enable"] = false
      loadFile(games[selected_game] .. "/" .. infos["starting_script"])
    end
  if (isButtonDown(BUTTON_UP))
    then
      selected_game = selected_game - 1
      if (selected_game < 1)
	then
	  selected_game = getLen(games)
	end
	loadFile(games[selected_game] .. "/infos.lua")
	img = resizeTexture(loadTexture(games[selected_game] .. "/" .. infos["img"]), 213, 160)
    end
  if (isButtonDown(BUTTON_DOWN))
    then
      selected_game = selected_game + 1
      if (selected_game > getLen(games))
	then
	  selected_game = 1
	end
	loadFile(games[selected_game] .. "/infos.lua")
	img = resizeTexture(loadTexture(games[selected_game] .. "/" .. infos["img"]), 213, 160)
    end
end

function render()
  drawText("Games", (SCREEN_WIDTH / 2) - 130, 10, 50, SKYBLUE)
  -- Games list
  drawRectangleLines(15, 80, 200, 300, BLACK)
  for i, val in pairs(games) do
    if (i == selected_game)
      then
	drawText(val, 20, 70 + (30 * i), 20, GREEN)
      else
	drawText(val, 20, 70 + (30 * i), 20, BLACK)
    end
  end
  drawText(infos["title"], 270, 70, 40, infos["color"])
  drawText(infos["desc"], 270, 120, 15, BLACK)
  drawTexture(img, 280, 150, RAYWHITE)
end
