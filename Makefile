NAME = push_swap

SRCS = \
	main.c \
	push_swap_errors.c \
	push_swap_operations.c \
	push_swap_utils.c \
	push_swap_refinement.c \
	push_swap_optimization.c \
	push_swap_count.c \
	push_swap_apply_counter.c \
	push_swap_operations_factory.c \
	manage_rotate.c \
	manage_reverse_rotate.c \
	manage_swap.c \
	manage_push.c 

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Define color codes
COLOR_RESET = \033[0m
COLOR_RED = \033[0;31m
COLOR_GREEN = \033[0;32m
COLOR_YELLOW = \033[0;33m
COLOR_BLUE = \033[0;34m
COLOR_MAGENTA = \033[0;35m
COLOR_CYAN = \033[0;36m
COLOR_WHITE = \033[0;37m

# Define format functions
PRINT_INFO = printf "$(COLOR_CYAN)%s$(COLOR_RESET)\n" "$1"
PRINT_SUCCESS = printf "$(COLOR_GREEN)%s$(COLOR_RESET)\n" "$1"
PRINT_WARNING = printf "$(COLOR_YELLOW)%s$(COLOR_RESET)\n" "$1"
PRINT_ERROR = printf "$(COLOR_RED)%s$(COLOR_RESET)\n" "$1"

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(call PRINT_INFO,"Building main project...")
	cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@$(call PRINT_SUCCESS,"Main project built successfully")

$(LIBFT):
	@$(call PRINT_INFO,"Building libraries...")
	make -C $(LIBFT_PATH) all
	@$(call PRINT_SUCCESS,"Libraries built successfully")
	
.c.o:
	cc $(FLAGS) -c -o $@ $<

clean:
	@$(call PRINT_INFO,"Cleaning...")
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean
	@$(call PRINT_SUCCESS,"Cleaned successfully")

fclean: clean
	@$(call PRINT_INFO,"Cleaning...")
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	@$(call PRINT_SUCCESS,"Cleaned successfully")

re: clean fclean all

.PHONY: all clean fclean re