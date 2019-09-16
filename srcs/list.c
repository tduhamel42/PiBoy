/**
 * File              : list.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.09.2019
 * Last Modified Date: 11.09.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include "list.h"

int			list_append(t_list **l, void *data)
{
  t_list		*n;

  if ((n = malloc(sizeof(t_list))) == NULL)
    return (1);
  n->data = data;
  n->next = NULL;
  n->prev = (*l);
  if ((*l))
    (*l)->next = n;
  (*l) = n;
  return (0);
}
