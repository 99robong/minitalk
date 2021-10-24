CC= gcc
CFLAGS= -Wextra -Wall -Werror -g3
CLI= client
SER= server
SRC_C= client.c
SRC_S= server.c
OBJ_C= ${SRC_C:.c=.o}
OBJ_S= ${SRC_S:.c=.o}
MAKE= make
LIBFT= libft.a
LIBFT_PATH= ./libft

all: $(CLI) $(SER)

$(CLI): $(LIBFT) $(OBJ_C)
	$(CC) $(CFLAGS) -o $@ $^

$(SER): $(LIBFT) $(OBJ_S)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/$(LIBFT) ./$(LIBFT)

clean:
	$(MAKE) clean -C $(LIBFT_PATH)
	rm -rf $(OBJ_C) $(OBJ_S)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	rm -rf $(LIBFT)
	rm -rf $(CLI)
	rm -rf $(SER)

re: fclean all
.PHONY: all clean fclean re
