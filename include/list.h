/**
 * File              : list.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.09.2019
 * Last Modified Date: 11.09.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef LIST_H_
# define LIST_H_

/*
** Maybe better if the functions return the pointer directly
*/

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

/**
** @brief Adds a new element a the end of the list
*/
int			list_append(t_list **l, void *data);
/**
** @brief Removes the given element from the list
*/
int			list_remove(t_list **l, void *data);
/**
** @brief Goes to the beginning of the list
*/
int			list_first(t_list **l);
/**
** @brief Goes to the end of the list
*/
int			list_end(t_list **l);

#endif /* !LIST_H_ */
