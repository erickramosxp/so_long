# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erramos <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 22:36:50 by erramos           #+#    #+#              #
#    Updated: 2023/11/08 14:50:07 by erramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_strlen.c ft_tolower.c ft_isdigit.c ft_isascii.c ft_isalpha.c \
		ft_isalnum.c ft_bzero.c ft_isprint.c \
		ft_toupper.c ft_strncmp.c ft_strlcat.c ft_strlcpy.c \
		ft_strchr.c ft_strrchr.c ft_memchr.c ft_memset.c \
		ft_memcpy.c ft_memmove.c ft_memcmp.c ft_atoi.c ft_calloc.c \
		ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c

OBJECTS = ft_strlen.o ft_tolower.o ft_isdigit.o ft_isascii.o ft_isalpha.o \
		  ft_isalnum.o ft_bzero.o ft_isprint.o \
		  ft_toupper.o ft_strncmp.o ft_strlcat.o ft_strlcpy.o \
		  ft_strchr.o ft_strrchr.o ft_memchr.o ft_memset.o \
		  ft_memcpy.o ft_memmove.o ft_memcmp.o ft_atoi.o ft_calloc.o \
		  ft_strnstr.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o \
		  ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o \
		  ft_putendl_fd.o ft_putstr_fd.o ft_putnbr_fd.o

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(FILES) libft.h
	cc -Wextra -Werror -Wall -c $(FILES)
	ar rc $(NAME) $(OBJECTS)
	
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
