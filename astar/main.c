/*
** main.c for main.c in /home/Rayan/Init_ia/cercle1
**
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
**
** Started on  Mon Mar 14 14:54:44 2016 AKKACHE Kaci
** Last update Sat May 28 17:09:56 2016 Afou Nacerdine
*/

#include "lab.h"

char	**init_t()
{
  int	i;
  int	j;
  char	**t;

  j = 0;
  t = malloc(sizeof(char *) * 11);
  while (j < 10)
    {
      i = 0;
      t[j] = malloc(31);
      while (i < 30)
	{
	  t[j][i] = 'X';
	  i++;
	}
      t[j][i] = '\0';
      j++;
    }
  t[j] = NULL;
  return (t);
}

char	*s_c(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*r;

  r = malloc(my_strlen(s1) + my_strlen(s2) + 1);
  i = 0;
  while (s1[i] != '\0')
    {
      r[i] = s1[i];
      i++;
    }
  j = 0;
  while (s2[j] != '\0')
    {
      r[i] = s2[j];
      i++;
      j++;
    }
  r[i] = '\0';
  free(s1);
  return (r);
}

char	**get_tab(char *f)
{
  int	fd;
  char	*s;
  char	b[10];
  int	r;

  fd = open(f, O_RDONLY);
  r = read(fd, b, 9);
  b[r] = '\0';
  s = my_strdup(b);
  while ((r = read(fd, b, 9)) > 0)
    {
      b[r] = '\0';
      s = s_c(s, b);
    }
  return (s_t_w(s, '\n'));
}

int	tab_len(char **t)
{
  int	i;

  i = -1;
  while (t[++i] != NULL);
  return (i);
}

int	main(int ac, char **av)
{
  t_s	s;

  s.t = get_tab(av[1]);
  s = solv_3(s);
  if (s.r == 0)
    {
      s.l = add_elem(s.l, s.i, s.j);
      while (s.l != NULL)
	{
	  s.t[s.l->y][s.l->x] = 'o';
	  s.l = sup_elem(s.l);
	}
    }
  else
    my_printf("insolvable\n");
  show(s.t);
  return (0);
}
