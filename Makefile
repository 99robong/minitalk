CC=gcc
CFLAGS=-Wextra -Wall -Werror -g3
CLI=client
SER=server
SRC_C=client.c
SRC_S=server.c

all: $(CLI) $(SER)

$(CLI): $(SRC_C)
	$(CC) $(CFLAGS) $(SRC_C) -o $@

$(SER): $(SRC_S)
	$(CC) $(CFLAGS) $(SRC_S) -o $@

clean: fclean

fclean:
	rm -rf $(CLI)
	rm -rf $(SER)

re: fclean all
