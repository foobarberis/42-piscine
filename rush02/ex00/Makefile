SRCS = main.c utils.c char.c dict.c num.c
OBJS = ${SRCS:.c=.o}
NAME = rush-02
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
