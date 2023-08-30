CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

EXEC = bsq

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
