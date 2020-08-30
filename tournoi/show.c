/*
** show.c for show.c in /home/thenascrazy/C_-_Prog_Elem/dante/astar
**
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
**
** Started on  Sun May 22 18:42:09 2016 Afou Nacerdine
** Last update Sun May 22 19:02:49 2016 Afou Nacerdine
*/

#include "lab.h"

void	show_x(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(1, &str[i], 1);
      i = i + 1;
    }
}

void	show(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      show_x(tab[i]);
      if (tab[i + 1] != NULL)
	write(1, "\n", 1);
      i = i + 1;
    }
}
