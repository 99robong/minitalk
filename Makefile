CC= gcc
CFLAGS= -Wextra -Wall -Werror -g3
CLI= client
SER= server
SRC_C= client.c
SRC_S= server.c
OBJ_C= ${SRC_C:.c=.o}
OBJ_S= ${SRC_S:.c=.o}

all: $(CLI) $(SER)

$(CLI): $(OBJ_C)
	$(CC) $(CFLAGS) -o $@ $^

$(SER): $(OBJ_S)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJ_C) $(OBJ_S)

fclean:
	rm -rf $(CLI)
	rm -rf $(SER)

re: fclean all
