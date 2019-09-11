/**
 * File              : piboy_lexer.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.09.2019
 * Last Modified Date: 11.09.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include "piboy_lexer.h"

int		piboy_lex(FILE *f, t_list **list)
{
  int		c;

  (void) list;
  while (1)
    {
      c = fgetc(f);
      if(feof(f))
	{ 
	  break ;
	}
      printf("%c", c);
    }
  return (0);
}
