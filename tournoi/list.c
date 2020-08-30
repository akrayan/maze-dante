/*
** list.c for list.c in /home/Rayan/Init_ia/cercle1
**
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
**
** Started on  Thu May 12 16:26:09 2016 AKKACHE Kaci
** Last update Sun May 22 17:52:58 2016 Afou Nacerdine
*/

#include "lab.h"

t_l	*add_elem(t_l *l, int x, int y)
{
  t_l	*n;

  if ((n = malloc(sizeof(t_l))) == NULL)
    return (NULL);
  n->x = x;
  n->y = y;
  if (l == NULL)
    {
      n->next = NULL;
      return (n);
    }
  n->next = l;
  l = n;
  return (l);
}

t_l	*sup_elem(t_l *l)
{
  t_l	*n;

  n = l;
  l = l->next;
  free(n);
  return (l);
}
