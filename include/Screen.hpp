/**
 * File              : Screen.hpp
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.03.2020
 * Last Modified Date: 11.03.2020
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef SCREEN_HPP_
# define SCREEN_HPP_

class Screen
{
  public:
    virtual ~Screen() {}

    virtual int		render(float delta) = 0;
    virtual int		update(float delta) = 0;
};

#endif /* !SCREEN_HPP_ */
