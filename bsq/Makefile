SRCS = main.c map.c map_check.c char.c matrix.c print.c solve.c
OBJS = ${SRCS:.c=.o}
NAME = bsq
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY: all clean fclean re
