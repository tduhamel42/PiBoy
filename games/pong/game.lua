--[[--
File              : game.lua
Author            : Tanguy Duhamel <tanguydu@gmail.com>
Date              : 16.04.2020
Last Modified Date: 16.04.2020
Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
--]]--

-- Players
player1 = SCREEN_HEIGHT / 2
player2 = SCREEN_HEIGHT / 2
player1_score = 0
player2_score = 0
-- Ball
ball_x = SCREEN_WIDTH / 2
ball_y = SCREEN_HEIGHT / 2
ball_vx = 5
ball_vy = 5

function update()

  -- Player 1
  if (isButtonDown(BUTTON_UP))
    then
      player1 = player1 - 4
      if (player1 < 0)
	then
	  player1 = 0
	end
    end
  if (isButtonDown(BUTTON_DOWN))
    then
      player1 = player1 + 4
      if (player1 + 70 > SCREEN_HEIGHT)
	then
	  player1 = SCREEN_HEIGHT - 70
	end
    end
  -- Player 2
  if (isButtonDown(BUTTON_A))
    then
      player2 = player2 - 4
      if (player2 < 0)
	then
	  player2 = 0
	end
    end
  if (isButtonDown(BUTTON_B))
    then
      player2 = player2 + 4
      if (player2 + 70 > SCREEN_HEIGHT)
	then
	  player2 = SCREEN_HEIGHT - 70
	end
    end
  -- Ball
  ball_x = ball_x + ball_vx
  ball_y = ball_y + ball_vy
  if (ball_x <= 15 and (ball_y >= player1 and ball_y <= player1 + 70))
    then
      ball_vx = -ball_vx
      ball_x = ball_x + ball_vx
    end
  if (ball_x >= SCREEN_WIDTH - 15 and (ball_y >= player2 and ball_y <= player2 + 70))
    then
      ball_vx = -ball_vx
      ball_x = ball_x + ball_vx
    end
  if (ball_y < 0 or ball_y > SCREEN_HEIGHT)
    then
      ball_vy = -ball_vy
      ball_y = ball_y + ball_vy
    end
  -- Update scores
  if (ball_x >= SCREEN_WIDTH)
    then
      player1_score = player1_score + 1
      ball_x = SCREEN_WIDTH / 2
      ball_y = SCREEN_HEIGHT / 2
    end
  if (ball_x <= 0)
    then
      player2_score = player2_score + 1
      ball_x = SCREEN_WIDTH / 2
      ball_y = SCREEN_HEIGHT / 2
    end
  -- Return to menu
  if (isButtonDown(BUTTON_RIGHT))
    then
      config["button_timer_enable"] = true
      loadFile("./srcs/lua/gamesscreen.lua")
    end

end

function render()
  clearBackground(BLACK)

  -- Net
  drawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE)
  -- Players
  drawRectangle(5, player1, 10, 70, WHITE)
  drawRectangle(SCREEN_WIDTH - 15, player2, 10, 70, WHITE)
  -- Ball
  drawRectangle(ball_x, ball_y, 10, 10, WHITE)
  -- Scores
  drawText("" .. player1_score, SCREEN_WIDTH / 2 - 50, 10, 40, WHITE)
  drawText("" .. player2_score, SCREEN_WIDTH / 2 + 50, 10, 40, WHITE)

end
