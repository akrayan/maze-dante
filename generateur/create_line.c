/*
** create_line.c for create_line.c in /home/thenascrazy/C_-_Prog_Elem/dante/generateur
**
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
**
** Started on  Sat May 21 11:19:58 2016 Afou Nacerdine
** Last update Sat May 21 11:51:05 2016 Afou Nacerdine
*/

#include "generate.h"

int	create_line_same(t_struct *mv, int y)
{
  int	x;

  x = 0;
  if ((mv->map[y] = malloc(sizeof(int ) * (mv->largeur + 1))) == NULL)
    return (-1);
  while (x < mv->largeur)
    {
      mv->map[y][x] = 0;
      x = x + 1;
    }
  mv->map[y][x] = -1;
  return (0);
}

int	create_line(t_struct *mv, int y)
{
  int	x;

  x = 0;
  if ((mv->map[y] = malloc(sizeof(int ) * (mv->largeur + 1))) == NULL)
    return (-1);
  while (x < mv->largeur)
    {
      if (x % 2 == 0)
	{
	  mv->map[y][x] = mv->cell;
	  mv->cell = mv->cell + 1;
	}
      else
	mv->map[y][x] = 0;
      x = x + 1;
    }
  mv->map[y][x] = -1;
  return (0);
}
