CC = cc
CFLAGS = -Wall -Wextra -Werror
DBG = -g

INCLUDES = .
SRC_PATH = .
SRCS =	lst_utils.c \
		main.c \
		optimizations.c \
		quicksort.c \
		stack.c \
		test_stack_A.c \
		test_stack_B.c \
		test_utils.c \
		utils_operations.c \
		utils_operations_stack_a.c \
		utils_operations_stack_a_b.c \
		utils_operations_stack_b.c
		# test_quicksort.c \
		# test_stack.c \

OBJS = $(SRCS:%.c=%.o)

NAME = a.out

.PHONY: all
all: $(NAME)

.PHONY: debug
debug: CFLAGS += -DDEBUG -g
debug: re

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
