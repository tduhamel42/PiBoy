/**
 * File              : piboy_lexer.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.09.2019
 * Last Modified Date: 11.09.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef PIBOY_LEXER_H_
# define PIBOY_LEXER_H_

#include <stdio.h>
#include "list.h"

int		piboy_lex(FILE *f, t_list **list);

#endif /* !PIBOY_LEXER_H_ */
