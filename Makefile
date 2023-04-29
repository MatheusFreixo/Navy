##
## EPITECH PROJECT, 2022
## BSQ
## File description:
## Makefile
##

SRC	=	./src/main/navy.c	\
		./src/file_management/read_file.c	\
		./src/file_management/write_file.c	\
		./src/display/usage.c	\
		./src/display/error.c	\
		./src/ship_information/ship_info.c	\
		./src/players/first_player.c	\
		./src/players/second_player.c	\
		./src/players/sig_handler/sig_handler.c	\
		./src/display/map/map.c	\
		./src/display/map/enemy_map.c	\
		./src/display/map/player_map.c	\
		./src/display/endgame/endgame.c

OBJ	=	$(SRC:.c=.o)

LIBRARY	=	./lib/my/

LIB	=	libmy.a

FLAG	=	-Wall -g -o

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIBRARY)
		gcc $(FLAG) $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIB)

re: fclean all
