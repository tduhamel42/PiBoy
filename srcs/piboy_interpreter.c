/**
 * File              : piboy_interpreter.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.09.2019
 * Last Modified Date: 11.09.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "piboy_lexer.h"
#include "piboy_interpreter.h"

static FILE		*open_file(const char *file)
{
  FILE			*f;

  if ((f = fopen(file, "r")) == NULL)
    {
      dprintf(2, "Could not open %s !\n", file);
      return (NULL);
    }
  return (f);
}

int			piboy_interprete(const char *file)
{
  FILE			*f;

  if ((f = open_file(file)) == NULL)
    return (1);
  piboy_lex(f, NULL);
  fclose(f);
  return (0);
}
