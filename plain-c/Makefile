CC = gcc
CFLAGS += -pedantic -Wall -Wextra -Werror

NAME = starry
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^

.PHONY: clean
clean:
	$(RM) $(OBJ)
	$(RM) $(NAME)
