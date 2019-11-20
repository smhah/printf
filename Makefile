# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smhah <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 15:14:20 by smhah             #+#    #+#              #
#    Updated: 2019/11/20 15:14:21 by smhah            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror
SRC = ft_acflag.c ft_activec.c ft_activepercent.c ft_actives.c ft_count.c ft_flag.c ft_functions1.c ft_functions2.c ft_functions3.c ft_functions4.c ft_functions5.c ft_functions6.c ft_printadresse.c ft_printf.c ft_printhexa.c ft_printhexa.c ft_subprintf.c ft_trimarg.c ft_untoa.c 
NAME = libftprintf.a
LIBFT = libft.a

all: $(NAME)

$(LIBFT):
	make -C libft/ 
	cp libft/libft.a .

$(NAME): $(LIBFT)
	ar -x libft.a
	$(G) -c $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	@echo $(NAME) is created

clean: 
	make -C libft/ clean
	rm -f *.o

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
