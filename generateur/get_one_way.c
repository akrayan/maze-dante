/*
** get_one_way.c for get_one_way.c in /home/thenascrazy/C_-_Prog_Elem/dante/generateur
**
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
**
** Started on  Sat May 21 11:43:36 2016 Afou Nacerdine
** Last update Sun May 22 12:42:45 2016 Afou Nacerdine
*/

#include "generate.h"

int	check_way(t_struct *mv)
{
  int	y;
  int	x;
  int	save;

  y = 0;
  save = mv->map[0][0];
  while (mv->map[y] != NULL)
    {
      x = 0;
      while (mv->map[y][x] != -1)
	{
	  if (mv->map[y][x] != 0)
	    {
	      if (mv->map[y][x] != save)
		return (-1);
	    }
	  x = x + 1;
	}
      y = y + 1;
    }
  return (0);
}

int	fill_map2(t_struct *mv, int a2, int a3)
{
  int	posx;
  int	posy;

  posy = 0;
  while (mv->map[posy] != NULL)
    {
      posx = 0;
      while (mv->map[posy][posx] != -1)
	{
	  if (mv->map[posy][posx] == a3)
	    mv->map[posy][posx] = a2;
	  posx = posx + 1;
	}
      posy = posy + 1;
    }
  return (0);
}

int	fill_map(t_struct *mv, int y, int x, int a)
{
  int	a2;
  int	a3;

  if (a == 0)
    {
      a2 = mv->map[y + 1][x];
      a3 = mv->map[y - 1][x];
    }
  else
    {
      a2 = mv->map[y][x + 1];
      a3 = mv->map[y][x - 1];
    }
  mv->map[y][x] = a2;
  fill_map2(mv, a2, a3);
  return (0);
}

int	get_one_way(t_struct *mv)
{
  int	x;
  int	y;

  y = 0;
  while (check_way(mv) == -1)
    {
      x = rand() % mv->largeur;
      y = rand() % mv->hauteur;
      if (mv->map[y + 1] && y > 0 && mv->map[y + 1][x] != 0 &&
	  mv->map[y - 1][x] != 0 && mv->map[y][x] == 0 &&
	  mv->map[y + 1][x] != mv->map[y - 1][x])
	fill_map(mv, y, x, 0);
      else if (x < mv->largeur - 1 && x > 0 && mv->map[y][x + 1] != 0
	       && mv->map[y][x - 1] != 0 && mv->map[y][x] == 0
	       && mv->map[y][x + 1] != mv->map[y][x - 1])
	fill_map(mv, y, x, 1);
    }
}
