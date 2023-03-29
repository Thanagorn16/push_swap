FLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT_PATH = libft/

ACTIONS_PATH = actions/

SWAP_SRCS = ft_lstadd_back.c ft_lstsize.c sort_five.c util.c \
			ft_lstfront.c sort_three.c ft_lstlast.c push_swap.c sort_two.c \
			check_err.c ft_lstnew.c sorting.c sort_big_stack.c sort_five_utils.c \

LIBFT_SRCS = ft_strlen.c ft_split.c ft_putstr_fd.c ft_strdup.c ft_atoi.c

ACTIONS_SRCS = s_actions.c r_actions.c rr_actions.c p_actions.c

SRCS = $(SWAP_SRCS)\
			$(addprefix $(ACTIONS_PATH), $(ACTIONS_SRCS))\
			$(addprefix $(LIBFT_PATH), $(LIBFT_SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%o:%c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus