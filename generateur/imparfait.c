/*
** main.c for main.c in /home/Rayan/Init_ia/cercle1
**
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
**
** Started on  Mon Mar 14 14:54:44 2016 AKKACHE Kaci
** Last update Sun May 29 00:20:39 2016 AKKACHE Kaci
*/

#include "generate.h"

void	my_show(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_printf("%s", tab[i]);
      if (tab[i + 1] != NULL)
	my_putchar('\n');
      i = i + 1;
    }
}

char	**init_t(int x, int y)
{
  int	i;
  int	j;
  char	**t;

  j = 0;
  t = malloc(sizeof(char *) * (y + 1));
  while (j < y)
    {
      i = 0;
      t[j] = malloc(x + 1);
      while (i < x)
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

t_s	gen_1(t_s s)
{
  srand(time(NULL));
  s.t = init_t(s.w, s.h);
  s.i = 0;
  s.j = 0;
  s.t[s.j][s.i] = '*';
  while (s.j != s.h - 1 || s.i != s.w - 1)
    {
      s.n = rand() % 6;
      if (s.n < 2 && s.j < s.h - 1)
	s.j++;
      else if (s.n > 3 && s.i < s.w - 1)
	s.i++;
      else if (s.n == 2 && s.j > 0)
	s.j--;
      else if (s.n == 3 && s.i > 0)
	s.i--;
      s.t[s.j][s.i] = '*';
    }
  return (s);
}

t_s	gen_2(t_s s)
{
  s.k = 0;
  while (s.k < (s.h + s.w) / 10)
    {
      s.mxi = rand() % s.w;
      s.mxj = rand() % s.h;
      s.i = rand() % s.w;
      s.j = rand() % s.h;
      while (s.j != s.mxj || s.i != s.mxi)
	{
	  s.n = rand() % 6;
	  if (s.n < 2 && s.j < s.mxj)
	    s.j++;
	  else if (s.n > 3 && s.i < s.mxi)
	    s.i++;
	  else if (s.n == 2 && s.j > 0)
	    s.j--;
	  else if (s.n == 3 && s.i > 0)
	    s.i--;
	  s.t[s.j][s.i] = '*';
	}
      s.k++;
    }
  return (s);
}

int	imparfait(int ac, char **av)
{
  t_s	s;

  s.w = my_getnbr(av[1]);
  s.h = my_getnbr(av[2]);
  if (s.w < 1 || s.h < 1)
    {
      my_printf("Error: x y\n");
      return (-1);
    }
  s = gen_1(s);
  s = gen_2(s);
  my_show(s.t);
}
