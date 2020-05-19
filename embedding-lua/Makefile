CC = gcc
CFLAGS += -std=c99 -pedantic -Wall -Wextra -Werror
CPPFLAGS += -I/usr/include/lua5.3
LDLIBS += -llua5.3

NAME = starry
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(NAME)
	$(RM) $(OBJ)
