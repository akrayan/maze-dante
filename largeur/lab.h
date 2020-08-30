/*
** lab.h for lab.h in /home/Rayan/Init_ia/m_solv
**
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
**
** Started on  Thu May 19 10:45:50 2016 AKKACHE Kaci
** Last update Sun May 22 17:53:51 2016 Afou Nacerdine
*/

#ifndef LAB_H
 #define LAB_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"

typedef struct	s_l
{
  struct s_l	*next;
  struct s_l	*last;

  int		x;
  int		y;
}		t_l;

typedef struct	s_s
{
  int		i;
  int		j;
  int		k;
  char		r;
  char		**t;
  t_l		*l;
  t_l		*h;
}		t_s;

char	**s_t_w(char *s, char c);
t_l	*add_elem(t_l *l, int x, int y);
t_l	*sup_elem(t_l *l);
char	is_not_pass(t_l *l, int i, int j);
t_s	solv_1(t_s s);
t_s	solv_2(t_s s);
t_s	solv_3(t_s s);

#endif
