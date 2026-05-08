CC = cc
CFLAGS = -Wall -Wextra -Werror
DBG = -g

INCLUDES = .
SRC_PATH = .
SRCS =	quicksort.c \
		stack.c \
		main.c \
		test_quicksort.c \
		test_stack.c \
		test_utils.c

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
