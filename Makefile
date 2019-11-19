G = gcc -Wall -Wextra -Werror
SRC = *.c
O = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): 
		$(G) -c $(SRC)
		ar rc $(NAME) $(O)
		ranlib $(NAME)
		@echo $(NAME) is created

clean: 
		rm -f $(O) $(OB)

fclean: clean
		rm -f $(NAME)

re: fclean all
