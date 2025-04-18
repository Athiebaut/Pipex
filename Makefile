SRC = pipex.c utils.c
OBJ = ${SRC:.c=.o}
NAME = pipex

LIBFT = Libft/libft.a
CC = cc 
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	make -C Libft
	${CC} ${FLAGS} ${OBJ} ${LIBFT} -o ${NAME}

clean:
	make clean -C Libft
	${RM} ${OBJ}

fclean: clean
	make fclean -C Libft
	${RM} ${NAME}
	${RM} ${LIBFT}

re: fclean all

.PHONY: all clean fclean