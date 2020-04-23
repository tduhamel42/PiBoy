--[[--
File              : game.lua
Author            : Tanguy Duhamel <tanguydu@gmail.com>
Date              : 15.04.2020
Last Modified Date: 15.04.2020
Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
--]]--

local player = loadTexture(CURRENT_DIR .. "player.png")
local laser = loadTexture(CURRENT_DIR .. "laser.png")
local meteor = loadTexture(CURRENT_DIR .. "meteor.png")
local lasers = {}
local meteors = {}
local x = SCREEN_WIDTH / 2
local y = SCREEN_HEIGHT / 2
-- Resets seed
math.randomseed(os.time())

function update()
  if (isButtonDown(BUTTON_UP))
    then
      y = y - 3
      if (y < 0)
	then
	  y = 0
	end
    end
  if (isButtonDown(BUTTON_DOWN))
    then
      y = y + 3
      if (y > SCREEN_HEIGHT - 75)
	then
	  y = SCREEN_HEIGHT - 75
	end
    end
  if (isButtonDown(BUTTON_RIGHT))
    then
      x = x + 3
      if (x + 99 > SCREEN_WIDTH)
	then
	  x = SCREEN_WIDTH - 99
	end
    end
  if (isButtonDown(BUTTON_LEFT))
    then
      x = x - 3
      if (x < 0)
	then
	  x = 0
	end
    end
  if (isButtonDown(BUTTON_A))
    then
      lasers[#lasers + 1] = {x = x + 45, y = y - 30}
    end
  -- Updates lasers
  for i in pairs(lasers) do
    lasers[i]["y"] = lasers[i]["y"] - 7
  end
  --Updates meteors
  if (math.random(100) < 5)
    then
      meteors[#meteors + 1] = {x = math.random(SCREEN_WIDTH), y = -300}
    end
  for i in pairs(meteors) do
    meteors[i]["y"] = meteors[i]["y"] + 5
  end
  -- Returns to menu
  if (isButtonDown(BUTTON_B))
    then
      -- Reset input timer
      config["button_timer_enable"] = true
      loadFile("./srcs/lua/gamesscreen.lua")
    end
end

function render()
  clearBackground(DARKBLUE)
  drawTexture(player, x, y, RAYWHITE)
  for i, val in pairs(lasers) do
    drawTexture(laser, val["x"], val["y"], RAYWHITE)
  end
  for i, val in pairs(meteors) do
    drawTexture(meteor, val["x"], val["y"], RAYWHITE)
  end
end
