SRCS		=	srcs/main.c
INCLUDES	=	includes/push_swap.h

OBJS		=	${SRCS:.c=.o}
NAME		=	push_swap

CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

all:				${NAME}

.c.o:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${OBJS}:			${INCLUDES}

$(NAME):			${INCLUDES} ${OBJS}
					${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
					${RM} ${OBJS}

fclean:				clean
					${RM} ${NAME}

re:					fclean all

.PHONY:				all bonus clean fclean re