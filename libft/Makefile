# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 18:45:08 by ssurilla          #+#    #+#              #
#    Updated: 2023/04/18 15:44:23 by ssurilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MY_SOURCES = ft_isalpha.c \
			 ft_isdigit.c \
			 ft_isalnum.c \
			 ft_isascii.c \
			 ft_isprint.c \
			 ft_strlen.c \
			 ft_memset.c \
			 ft_bzero.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_strlcpy.c \
			 ft_strlcat.c \
			 ft_toupper.c \
			 ft_tolower.c \
			 ft_strchr.c \
			 ft_strrchr.c \
			 ft_strncmp.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_strnstr.c \
			 ft_atoi.c \
			 ft_calloc.c \
			 ft_strdup.c \
			 ft_substr.c \
			 ft_strjoin.c \
			 ft_strtrim.c \
			 ft_split.c \
			 ft_itoa.c \
			 ft_strmapi.c \
			 ft_striteri.c \
			 ft_putchar_fd.c \
			 ft_putstr_fd.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 get_next_line.c \
			 get_next_line_utils.c \
			 

MY_OBJECTS = $(MY_SOURCES:.c=.o)

AR = ar crs

CC = cc

CFLAGS += -Wall -Wextra -Werror

CUR_DIR = $(shell pwd)

$(NAME): $(MY_OBJECTS)
		-make -C ft_printf
		$(AR) $(NAME) ft_printf/ft_printf.a $(MY_OBJECTS) 
		

all: $(NAME)

clean:
	rm -f *.o ft_printf/*.o

fclean: clean
	rm -f $(NAME) ft_printf/ft_printf.a

re: fclean all

.PHONY = clean fclean re all
