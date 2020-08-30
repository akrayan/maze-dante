##
## Makefile for Makefile in /home/thenascrazy/C_-_Prog_Elem/CPE_2015_Lemin
## 
## Made by AFOU Nacerdine
## Login   <afou_n@epitech.net>
## 
## Started on  Mon Apr 18 10:49:12 2016 AFOU Nacerdine
## Last update Sat May 28 17:18:47 2016 Afou Nacerdine
##

CC	=	gcc

RM	=	rm -f

NAME	=	./astar/solver
NAME2	=	./profondeur/solver
NAME3	=	./largeur/solver
NAME4	=	./tournoi/solver
NAME5	=	./generateur/generateur

SRCS	=	./astar/main.c \
		./astar/s_t_w.c \
		./astar/solv.c \
		./astar/list.c \
		./astar/show.c
SRCS2	=	./profondeur/main.c \
		./profondeur/s_t_w.c \
		./profondeur/solv.c \
		./profondeur/list.c \
		./profondeur/show.c
SRCS3	=	./largeur/main.c \
		./largeur/s_t_w.c \
		./largeur/solv.c \
		./largeur/list.c \
		./largeur/show.c
SRCS4	=	./tournoi/main.c \
		./tournoi/s_t_w.c \
		./tournoi/solv.c \
		./tournoi/list.c \
		./tournoi/show.c
SRCS5	=	./generateur/main.c \
		./generateur/parfait.c \
		./generateur/imparfait.c \
		./generateur/create_line.c \
		./generateur/get_one_way.c

OBJS	=	$(SRCS:.c=.o)
OBJS2	=	$(SRCS2:.c=.o)
OBJS3	=	$(SRCS3:.c=.o)
OBJS4	=	$(SRCS4:.c=.o)
OBJS5	=	$(SRCS5:.c=.o)

LIB	=	-lmy -L.

all:		$(NAME) $(NAME2) $(NAME3) $(NAME4) $(NAME5)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIB)

$(NAME2):	$(OBJS2)
		$(CC) -o $(NAME2) $(OBJS2) $(LIB)

$(NAME3):	$(OBJS3)
		$(CC) -o $(NAME3) $(OBJS3) $(LIB)

$(NAME4):	$(OBJS4)
		$(CC) -o $(NAME4) $(OBJS4) $(LIB)

$(NAME5):	$(OBJS5)
		$(CC) -o $(NAME5) $(OBJS5) $(LIB)

clean:
		$(RM) $(OBJS) $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS5)

fclean:		clean
		$(RM) $(NAME) $(NAME2) $(NAME3) $(NAME4) $(NAME5)

re:		fclean all

.PHONY:		all clean fclean re
