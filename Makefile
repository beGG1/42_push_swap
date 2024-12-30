SRCS		=	srcs/main.c \
				srcs/general_stack_functions.c \
				srcs/swap_functions.c \
				srcs/push_functions.c \
				srcs/sort.c \
				srcs/rotate_functions.c \
				srcs/reverse_rotate_functions.c \
				srcs/converters.c \
				srcs/ft_printf.c \
				srcs/hex_functions.c \
				srcs/number_functions.c \
				srcs/print_format.c \
				srcs/ptr_functions.c \
				srcs/string_functions.c \
				srcs/unumber_functions.c \
				srcs/utils.c

INCLUDES	=	includes/push_swap.h \
				includes/ft_printf.h

OBJS		=	${SRCS:.c=.o}
NAME		=	push_swap

CC			=	cc
RM			=	rm -f
CFLAGS		=	#-Wall -Wextra -Werror

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