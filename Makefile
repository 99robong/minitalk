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

$(CLI): $(OBJ_C) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(SER): $(OBJ_S) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	$(MAMKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/$(LIBFT) ./$(LIBFT)

clean:
	$(MAKE) clean -C $(LIBFT_PATH)
	rm -rf $(OBJ_C) $(OBJ_S)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	rm -rf $(CLI)
	rm -rf $(SER)

re: fclean all
.PHONY: all clean fclean re
