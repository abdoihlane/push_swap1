NAME = push_swap

SRC = main.c swap.c operations.c helpers.c helpers2.c ft_split.c ss.c push_swap.c parsing1.c rot.c push.c moreoperations.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : 
	rm -f $(NAME) $(OBJS)

re : fclean all