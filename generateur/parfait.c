/*
** parfait.c for parfait.c in /home/thenascrazy/C_-_Prog_Elem/dante/generateur
**
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
**
** Started on  Sat May 21 10:15:17 2016 Afou Nacerdine
** Last update Sun May 22 12:47:38 2016 Afou Nacerdine
*/

#include "generate.h"

void	disp_map(t_struct *mv)
{
  int	x;
  int	y;

  y = 0;
  while (mv->map[y] != NULL)
    {
      x = 0;
      while (mv->map[y][x] != -1)
	{
	  if (mv->map[y][x] != 0)
	    my_printf("*");
	  else
	    my_printf("X");
	  x = x + 1;
	}
      if (mv->map[y + 1] != NULL)
	my_printf("\n");
      y = y + 1;
    }
}

int	generate_start(t_struct *mv)
{
  int	y;

  y = 0;
  mv->cell = 1;
  if (mv->hauteur < 1 || mv->largeur < 1)
    {
      my_printf("Error: x y\n");
      return (-1);
    }
  if ((mv->map = malloc(sizeof(int *) * (mv->hauteur + 1))) == NULL)
    return (-1);
  while (y < mv->hauteur)
    {
      if (y % 2 == 0)
	create_line(mv, y);
      else
	create_line_same(mv, y);
      y = y + 1;
    }
  mv->map[y] = NULL;
  return (0);
}

int	parfait(t_struct *mv)
{
  int	save;

  if (generate_start(mv) == -1)
    return (-1);
  if (mv->hauteur % 2 == 0)
    {
      save = mv->map[mv->hauteur - 2][mv->largeur - 2];
      mv->map[mv->hauteur - 1][mv->largeur - 1] = save;
      mv->map[mv->hauteur - 1][mv->largeur - 2] = save;
      save = mv->map[mv->hauteur - 2][mv->largeur - 1];
      if (mv->largeur % 2 != 0)
	mv->map[mv->hauteur - 1][mv->largeur - 1] = save;
    }
  else
    {
      save = mv->map[mv->hauteur - 1][mv->largeur - 2];
      if (mv->largeur % 2 == 0)
	mv->map[mv->hauteur - 1][mv->largeur - 1] = save;
    }
  get_one_way(mv);
  disp_map(mv);
}
