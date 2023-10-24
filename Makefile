SRC = pipex.c utils.c
OBJ = ${SRC:.c=.o}
NAME = pipex

#SRCB = pipex_bonus.c utils_bonus.c
#OBJB = ${SRCB:.c=.o}
#NAMEB = pipex_bonus

LIBFT = Libft/libft.a
CC = cc 
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	make -C Libft
	${CC} ${FLAGS} ${OBJ} ${LIBFT} -o ${NAME}

#bonus: 

clean:
	make clean -C Libft
	${RM} ${OBJ}

fclean: clean
	make fclean -C Libft
	${RM} ${NAME}
	${RM} ${LIBFT}

re: fclean all

.PHONY: all clean fclean