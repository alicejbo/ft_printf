# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abossard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 18:13:04 by abossard          #+#    #+#              #
#    Updated: 2018/12/30 18:29:38 by abossard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = big_c.c\
	  big_s.c\
	  boucle_ppale.c\
	  direction.c\
	  display.c\
	  flag_c.c\
	  flag_i.c\
	  flag_i2.c\
	  flag_o.c\
	  flag_o2.c\
	  flag_s.c\
	  flag_u.c\
	  flag_u2.c\
	  flag_x.c\
	  flag_x2.c\
	  flag_f.c\
	  flag_f2.c\
	  ft_printf.c\
	  list_args.c\
	  list_params.c\
	  parse_args.c\
	  parse_args_2.c\
	  struct_infos.c\
	  which_arg.c

SRC_LIB = libft/ft_atoi.c\
		  libft/ft_itoa.c\
		  libft/ft_itoa_base.c\
		  libft/ft_itoa_base_ll.c\
		  libft/ft_memalloc.c\
		  libft/ft_memmove.c\
		  libft/ft_putstr.c\
		  libft/ft_putnbr.c\
		  libft/ft_strcat.c\
		  libft/ft_strcmp.c\
		  libft/ft_strcpy.c\
		  libft/ft_strdel.c\
		  libft/ft_strdup.c\
		  libft/ft_strlcat.c\
		  libft/ft_strlen.c\
		  libft/ft_strstr.c\
		  libft/ft_strsub.c\
		  libft/ft_str_upper.c\
		  libft/ft_val_wchar.c\
		  libft/ft_memcpy.c\
		  libft/ft_toupper.c\
		  libft/ft_bzero.c\
		  libft/ft_putchar.c\
		  libft/ft_memdel.c\
		  libft/ft_printbits.c

OBJ_LIB = ft_atoi.o\
		  ft_itoa.o\
		  ft_itoa_base.o\
		  ft_itoa_base_ll.o\
		  ft_memalloc.o\
		  ft_memmove.o\
		  ft_putstr.o\
		  ft_strcat.o\
		  ft_strcmp.o\
		  ft_strcpy.o\
		  ft_strdel.o\
		  ft_strdup.o\
		  ft_strlcat.o\
		  ft_strlen.o\
		  ft_strstr.o\
		  ft_strsub.o\
		  ft_str_upper.o\
		  ft_val_wchar.o\
		  ft_memcpy.o\
		  ft_toupper.o\
		  ft_bzero.o\
		  ft_putnbr.o\
		  ft_putchar.o\
		  ft_memdel.o\
		  ft_printbits.o

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ_LIB): $(SRC_LIB)
	@gcc -Wall -Wextra -c $(SRC_LIB)

$(OBJ): $(SRC)
	@gcc -Wall -Wextra -c $(SRC)

$(NAME): $(OBJ) $(SRC) $(OBJ_LIB) ft_printf.h
	@ar rc $(NAME) $(OBJ) $(OBJ_LIB)

clean:
	@rm -Rf $(OBJ) $(OBJ_LIB)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
