NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUF = -D BUFFER_SIZE=32
AR = ar -rcs
SRCS = ft_toupper.c \
		ft_tolower.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_atoi.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_memccpy.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line.c \
		get_next_line_utils.c

SRCS_B = ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstadd_back.c \
		 ft_lstdelone.c \
		 ft_lstclear.c \
		 ft_lstiter.c \
		 ft_lstmap.c

OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS) $(OBJS_B)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $(DEBUF) -c $^ -o $@

bonus : $(OBJS) $(OBJS_B)
	 $(AR) $(NAME) $^

so :
	$(CC) -fPIC $(CFLAGS) $(DEBUF) -c $(SRCS)
	gcc -shared -o libft.so $(OBJS)

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean bonus
