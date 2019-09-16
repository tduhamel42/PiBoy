/**
 * File              : piboy_interface.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.09.2019
 * Last Modified Date: 11.09.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef PIBOY_INTERFACE_H_
# define PIBOY_INTERFACE_H_

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

int			piboy_interface_init(int width, int height);
int			piboy_interface_run();

#endif /* !PIBOY_INTERFACE_H_ */
