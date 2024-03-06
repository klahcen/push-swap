CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror
NAME	=	push_swap
LIB		= 	push_swap.a

CHECKER	=	checker

SRC		=	ft_storage.c ft_putstr.c ft_sort_stack.c\
         	ft_swap.c ft_atoi.c ft_reverse_rotate.c \
			ft_test_sort.c ft_errore.c ft_rotate.c \
			main.c ft_push.c ft_split.c ft_sort_arrya.c\
			ft_index.c

OBJC	=	${SRC:.c=.o}

B_SRCS	=	ft_checker/get_next_line.c \
            ft_checker/get_next_line_utils.c \
			ft_checker/ft_operation.c \
            ft_checker/ft_bonus_chekcer.c \
            ft_storage.c ft_putstr.c ft_sort_stack.c\
         	ft_swap.c ft_atoi.c ft_reverse_rotate.c \
			ft_test_sort.c ft_errore.c ft_rotate.c \
			ft_push.c ft_split.c ft_sort_arrya.c\
			ft_index.c
            
B_OBJS	=	$(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(CHECKER)

clean:
	rm -rf $(OBJC)
	rm -rf $(B_OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
