/*
** solv.c for solv.c in /home/Rayan/Init_ia/copie de m_solv
**
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
**
** Started on  Sun May 22 07:20:09 2016 AKKACHE Kaci
** Last update Sun May 22 18:56:40 2016 Afou Nacerdine
*/

#include "lab.h"

char	is_not_pass(t_l *l, int i, int j)
{
  t_l	*p;

  p = l;
  while (p != NULL)
    {
      if (i == p->x && j == p->y)
	return (0);
      p = p->next;
    }
  return (1);
}

t_s	stock(t_s s)
{
  s.l = add_elem(s.l, s.i, s.j);
  s.h = add_elem(s.h, s.i, s.j);
  s.i++;
  s.k = 0;
  return (s);
}

t_s	solv_1(t_s s)
{
  if (s.k == 0 && is_not_pass(s.h, s.i + 1, s.j) == 1 &&
      s.t[s.j][s.i + 1] != 10 && s.t[s.j][s.i + 1] != 0 &&
      s.t[s.j][s.i + 1] != 88)
    s = stock(s);
  else if (s.k == 1 && is_not_pass(s.h, s.i, s.j + 1) == 1 &&
	   s.t[s.j + 1] != NULL && s.t[s.j + 1][s.i] != 'X')
    {
      s.l = add_elem(s.l, s.i, s.j);
      s.h = add_elem(s.h, s.i, s.j);
      s.j++;
      s.k = 0;
    }
  else if (s.k == 2 && is_not_pass(s.h, s.i - 1, s.j) == 1 &&
	   s.i - 1 >= 0 && s.t[s.j][s.i - 1] != 'X')
    {
      s.l = add_elem(s.l, s.i, s.j);
      s.h = add_elem(s.h, s.i, s.j);
      s.i--;
      s.k = 0;
    }
  return (s);
}

t_s	solv_2(t_s s)
{
  if (s.k == 3 && is_not_pass(s.h, s.i, s.j - 1) == 1 && s.j - 1 >= 0 &&
      s.t[s.j - 1][s.i] != 'X')
    {
      s.l = add_elem(s.l, s.i, s.j);
      s.h = add_elem(s.h, s.i, s.j);
      s.j--;
      s.k = 0;
    }
  else if (s.k < 3)
    s.k++;
  else if (s.l != NULL)
    {
      if (s.i - s.l->x == 1)
	s.k = 1;
      else if (s.j - s.l->y == 1)
	s.k = 2;
      else if (s.i - s.l->x == - 1)
	s.k = 3;
      else if (s.j - s.l->y == - 1)
	s.k = 4;
      s.i = s.l->x;
      s.j = s.l->y;
      s.l = sup_elem(s.l);
    }
  return (s);
}

t_s	solv_3(t_s s)
{
  s.l = NULL;
  s.h = NULL;
  s.i = 0;
  s.j = 0;
  s.k = 0;
  s.r = 0;
  while ((s.i != my_strlen(s.t[0]) - 1 || s.j != tab_len(s.t) - 1) && s.r == 0)
    {
      if ((s.k == 0 && is_not_pass(s.h, s.i + 1, s.j) == 1 &&
	   s.t[s.j][s.i + 1] != '\n' && s.t[s.j][s.i + 1] != '\0'
	   && s.t[s.j][s.i + 1] != 'X') ||
	  (s.k == 1 && is_not_pass(s.h, s.i, s.j + 1) == 1 &&
	   s.t[s.j + 1] != NULL && s.t[s.j + 1][s.i] != 'X') ||
	  (s.k == 2 && is_not_pass(s.h, s.i - 1, s.j) == 1 &&
	   s.i - 1 >= 0 && s.t[s.j][s.i - 1] != 'X'))
	s = solv_1(s);
      else if ((s.k == 3 && is_not_pass(s.h, s.i, s.j - 1) == 1 &&
		s.j - 1 >= 0 && s.t[s.j - 1][s.i] != 'X') || (s.k < 3) || (s.l != NULL))
	s = solv_2(s);
      else
	s.r = 1;
    }
  return (s);
}
