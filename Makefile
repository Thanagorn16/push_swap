FLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT_PATH = libft/

SWAP_SRCS = pipex.c pipex_utils.c

LIBFT_SRCS = ft_strlen.c ft_strjoin_path.c ft_split.c ft_strtrim.c \
			ft_putstr_fd.c ft_strdup.c ft_strncmp.c

SRCS = $(PIPE_SRCS) $(addprefix $(LIBFT_PATH), $(LIBFT_SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%o:%c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus