/**
 * File              : main.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.09.2019
 * Last Modified Date: 11.09.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include "piboy_interpreter.h"
#include "piboy_interface.h"

int		main(int argc, char **argv)
{
  if (argc == 2)
    {
      //piboy_interprete(argv[1]);
      piboy_interface_init(SCREEN_WIDTH, SCREEN_HEIGHT);
      piboy_interface_run();
    }
  else
    dprintf(2, "You need to give a file !\n");
  return (0);
}
