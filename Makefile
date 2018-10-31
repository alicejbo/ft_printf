# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abossard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 18:13:04 by abossard          #+#    #+#              #
#    Updated: 2018/10/31 18:17:25 by abossard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = big.c\
	  big.s\
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
	  ft_printf.c\
	  list_args.c\
	  list_params.c\
	  mb_cur.c\
	  parse_args.c\
	  parse_args_2.c\
	  struct_infos.c\
	  which_arg.c

SRC_LIB = libft/ft_atoi.c\
		  libft/ft_itoa.c\
		  libft/ft_itoa_base.c\
		  libft/ft_itoa_base_neg.c\
		  libft/ft_len_wchar_to_char.c\
		  libft/ft_memalloc.c\
		  libft/ft_memmove.c\
		  libft/ft_putstr.c\
		  libft/ft_strcat.c\
		  libft/ft_strcmp.c\
		  libft/ft_strcpy.c\
		  libft/ft_strdel.c\
		  libft/ft_strdup.c\
		  libft/ft_strlcat.c\
		  libft/ft_strlen.c\
		  libft/ft_strstr.c\
		  libft/ft_strsub.c\
		  libft/ft_strupper.c\
		  libft/ft_val_wchar.c\
		  libft/ft_memcpy.c\
		  libft/ft_toupper.c\
		  libft/ft_bzero.c\

OBJ_LIB = ft_atoi.o\
		  ft_itoa.o\
		  ft_itoa_base.o\
		  ft_itoa_base_neg.o\
		  ft_len_wchar_to_char.o\
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
		  ft_strupper.o\
		  ft_val_wchar.o\
		  ft_memcpy.o\
		  ft_toupper.o\
		  ft_bzero.o\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ_LIB): $(SRC_LIB)
	@gcc -Wall -Wextra -Werror -c -O3 $(SRC_LIB)

$(OBJ): $(SRC)
	@gcc -Wall -Wextra -Werror -c -O3 $(SRC)

$(NAME): $(OBJ) $(SRC) $(OBJ_LIB) includes/ft_printf.h includes/ft_errno.h
	@ar rc $(NAME) $(OBJ) $(OBJ_LIB)

clean:
	@rm -Rf $(OBJ) $(OBJ_LIB)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
