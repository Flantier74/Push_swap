CC = cc
CFLAGS = -Wall -Wextra -Werror
DBG = -g

INCLUDES = .
SRC_PATH = .
SRCS =	lst_utils.c \
		main.c \
		optimizations.c \
		quicksort.c \
		utils_operations.c \
		utils_operations_stack_a.c \
		utils_operations_stack_a_b.c \
		utils_operations_stack_b.c
OBJS = 	$(SRCS:%.c=%.o) \
		tests/test_quicksort.o \
		tests/test_stack_A.o \
		tests/test_stack_B.o \
		tests/test_utils.o

TESTS =	tests/test_quicksort.c \
		tests/test_stack_A.c \
		tests/test_stack_B.c \
		tests/test_utils.c
TESTS_OBJS = $(TESTS:%.c=%.o)

NAME = a.out

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $@

.PHONY: debug
debug: CFLAGS += -DDEBUG -g
debug: re

.PHONY: test
test: $(OBJS) $(TESTS_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_OBJS) -o $@ && ./test

.PHONY: clean
clean:
	rm -f $(OBJS) $(TESTS_OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
