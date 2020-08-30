/*
** generate.h for generate.h in /home/thenascrazy/C_-_Prog_Elem/dante/generateur
**
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
**
** Started on  Sat May 21 09:56:56 2016 Afou Nacerdine
** Last update Sun May 22 17:46:18 2016 Afou Nacerdine
*/

#ifndef GENERATE_H_
# define GENERATE_H_

#include <time.h>
#include "my.h"
#include "lab.h"

typedef struct	s_struct
{
  int		hauteur;
  int		largeur;
  int		cell;
  int		**map;
}		t_struct;

int	check_way(t_struct *mv);
int	fill_map2(t_struct *mv, int a2, int a3);
int	fill_map(t_struct *mv, int y, int x, int a);
int	get_one_way(t_struct *mv);
int	main(int ac, char **av);
char	**init_t(int x, int y);
t_s	gen_1(t_s s);
t_s	gen_2(t_s s);
int	imparfait(int ac, char **av);
void	disp_map(t_struct *mv);
int	generate_start(t_struct *mv);
int	parfait(t_struct *mv);
int	create_line_same(t_struct *mv, int y);
int	create_line(t_struct *mv, int y);

#endif /* !GENERATE_H_ */
