/*
** main.c for main.c in /home/thenascrazy/C_-_Prog_Elem/dante/generateur
**
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
**
** Started on  Sat May 21 09:56:18 2016 Afou Nacerdine
** Last update Sun May 22 17:46:52 2016 Afou Nacerdine
*/

#include "generate.h"

int		main(int ac, char **av)
{
  t_struct	mv;

  srand(time(NULL));
  if (ac != 4)
    {
      if (ac != 3)
	{
	  my_printf("Error: %s x y type\n", av[0]);
	  return (0);
	}
      imparfait(ac, av);
      return (0);
    }
  mv.largeur = my_getnbr(av[1]);
  mv.hauteur = my_getnbr(av[2]);
  if (my_strcmp(av[3], "parfait") == 0)
    parfait(&mv);
  else if (my_strcmp(av[3], "imparfait") == 0)
    imparfait(ac, av);
  else
    my_printf("Error: inconue\n");
}
