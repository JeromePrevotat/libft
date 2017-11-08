# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 19:00:31 by jprevota          #+#    #+#              #
#    Updated: 2017/11/08 21:07:03 by jprevota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \x1b[31m
GREY = \x1b[30m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE = \x1b[37m

CC = @gcc
CFLAGS = -Wall -Werror -Wextra
MAKE = make
NAME = libft.a

SRCS += ./ft_isalpha.c
SRCS += ./ft_isdigit.c
SRCS += ./ft_isalnum.c
SRCS += ./ft_isascii.c
SRCS += ./ft_toupper.c
SRCS += ./ft_tolower.c
SRCS += ./ft_isprint.c

SRCS += ./ft_putchar.c
SRCS += ./ft_putchar_fd.c
SRCS += ./ft_putstr.c
SRCS += ./ft_putstr_fd.c
SRCS += ./ft_putnbr.c
SRCS += ./ft_putnbr_fd.c
SRCS += ./ft_putendl.c
SRCS += ./ft_putendl_fd.c

SRCS += ./ft_atoi.c
SRCS += ./ft_itoa.c

SRCS += ./ft_strlen.c
SRCS += ./ft_strcmp.c
SRCS += ./ft_strncmp.c
SRCS += ./ft_strcpy.c
SRCS += ./ft_strncpy.c
SRCS += ./ft_strcat.c
SRCS += ./ft_strncat.c
SRCS += ./ft_strlcat.c
SRCS += ./ft_strstr.c
SRCS += ./ft_strnstr.c
SRCS += ./ft_strdup.c
SRCS += ./ft_strchr.c
SRCS += ./ft_strrchr.c
SRCS += ./ft_strnew.c
SRCS += ./ft_strdel.c
SRCS += ./ft_strclr.c
SRCS += ./ft_striter.c
SRCS += ./ft_striteri.c
SRCS += ./ft_strmap.c
SRCS += ./ft_strmapi.c
SRCS += ./ft_strequ.c
SRCS += ./ft_strnequ.c
SRCS += ./ft_strsub.c
SRCS += ./ft_strjoin.c
SRCS += ./ft_strtrim.c
SRCS += ./ft_strsplit.c

SRCS += ./ft_bzero.c
SRCS += ./ft_memset.c
SRCS += ./ft_memdel.c
SRCS += ./ft_memalloc.c
SRCS += ./ft_memcpy.c
SRCS += ./ft_memccpy.c
SRCS += ./ft_memmove.c
SRCS += ./ft_memchr.c
SRCS += ./ft_memcmp.c

SRCS += ./ft_lstnew.c
SRCS += ./ft_lstdelone.c
SRCS += ./ft_lstdel.c
SRCS += ./ft_lstadd.c
SRCS += ./ft_lstiter.c
SRCS += ./ft_lstmap.c

SRCS += ./ft_bonus_sort_inttab.c
SRCS += ./ft_bonus_tabrev.c
SRCS += ./ft_bonus_isprime.c
SRCS += ./ft_bonus_pow.c
SRCS += ./ft_bonus_strrev.c
SRCS += ./ft_bonus_strreplace.c
SRCS += ./ft_bonus_str_wc.c
SRCS += ./ft_bonus_lstadd_end.c
SRCS += ./ft_bonus_lstadd_n.c

SRCS += ./get_next_line.c

INC += ./libft.h
INC += ./get_next_line.h

OBJ = $(SRCS:.c=.o)

.PHONY : ft_printf clean fclean

all: ft_printf $(NAME)

ft_printf:
	@cd ./ft_printf && $(MAKE)

$(NAME): $(OBJ) $(INC)
	@echo "$(BLUE)>>$(WHITE) Building $(NAME) $(BLUE)<<$(WHITE)"
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)SUCCESS$(WHITE)"

clean:
	@cd ./ft_printf && $(MAKE) clean
	rm -rf $(OBJ)

fclean: clean
	@cd ./ft_printf && $(MAKE) fclean
	rm -rf $(NAME)

re:	fclean all
