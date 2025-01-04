SRCS		=	main.c \
				general_stack_functions.c \
				swap_functions.c \
				push_functions.c \
				sort.c \
				rotate_functions.c \
				reverse_rotate_functions.c \

SRCS_F		=	srcs/
OBJS_F		=	objs/

LIBFT		= includes/libft/
HEADER		= includes/push_swap.h

OBJS		=	$(SRCS:.c=.o)
OBJS_P		=	$(addprefix $(OBJS_F), $(OBJS))
NAME		= 	push_swap

all:$(NAME)

$(OBJS_F)%.o: $(SRCS_F)%.c Makefile $(HEADER) | $(OBJS_F)
	@echo "Working on: $<"
	@$(CC) $(CC_FLAGS) -O3 -c $< -o $@ -I.

$(OBJS_F):
	@mkdir -p $(OBJS_F)

$(NAME): $(OBJS_P)
	@$(MAKE) -C $(LIBFT) 
	@$(CC) $(CC_FLAGS) -O3 -o $(NAME) $(OBJS_P) $(LIBFT)/libft.a 
	@echo "Push_swap compiled successfully!"

clean:
	@rm -rf $(OBJS_F)
	@$(MAKE) fclean -C $(LIBFT) 
	@echo "Push_swap objects removed!"

fclean:	clean
	@rm -rf $(NAME)
	@echo "Push_swap removed!"

re:		fclean all

.PHONY:	all clean fclean re