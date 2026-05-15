CC = cc
CFLAGS = -Wall -Wextra -Werror
DBG = -g

INCLUDES = tests
SRC_PATH = .
SRCS =	calc_disorder.c \
		bubble_sort.c \
		insertion_sort_adaptation.c \
		chunk_based_sorting.c \
		lst_utils.c \
		lst_utils2.c \
		utils_operations.c \
		utils_operations_stack_a.c \
		utils_operations_stack_a_b.c \
		radix_sort.c \
		utils.c \
		utils_operations_stack_b.c

OBJS = 	$(SRCS:%.c=%.o)

TESTS =	tests/test_500_1000.c

TESTS_OBJS = $(TESTS:%.c=%.o)

NAME = push_swap

.PHONY: all
all: $(NAME)

$(NAME): $(NAME).o $(OBJS)
	$(CC) $(CFLAGS) $(NAME).o $(OBJS) -o $@

$(NAME).o: $(NAME).c
	$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $@

.PHONY: debug
debug: CFLAGS += -DDEBUG -g
debug: re

.PHONY: test
test: CFLAGS += -DDEBUG -g
test: $(OBJS)
test: tests/test.o $(TESTS_OBJS)
	$(CC) $(CFLAGS) tests/test.o $(OBJS) $(TESTS_OBJS) -o tests/$@
	./tests/test

tests/test.o: tests/test.c
	$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $@

.PHONY: clean
clean:
	rm -f $(NAME).o $(OBJS) tests/test.o $(TESTS_OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME) tests/test

.PHONY: re
re: fclean all
