# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solivari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 15:30:28 by solivari          #+#    #+#              #
#    Updated: 2019/06/12 17:30:04 by solivari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_atoi.c ft_putchar.c\
	   ft_putnbr.c ft_putstr.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_memset.c\
	   ft_strchr.c ft_strrchr.c ft_bzero.c ft_strcat.c ft_strncat.c ft_strlcat.c\
	   ft_memcpy.c ft_memccpy.c ft_strnstr.c ft_memmove.c ft_memchr.c ft_memcmp.c\
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
	   ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c\
	   ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strsub.c\
	   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_abs.c ft_itoa.c ft_putendl.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c\
	   ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_wordcount.c\
	   ft_wordlen.c ft_maxminrange.c ft_strnequ.c ft_swap.c ft_atol.c Get_Next_Line.c

OBJECTS = ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_atoi.o ft_putchar.o\
		  ft_putnbr.o ft_putstr.o ft_strcmp.o ft_strncmp.o ft_strstr.o ft_memset.o\
		  ft_strchr.o ft_strrchr.o ft_bzero.o ft_strcat.o ft_strncat.o ft_strlcat.o\
		  ft_memcpy.o ft_memccpy.o ft_strnstr.o ft_memmove.o ft_memchr.o ft_memcmp.o\
		  ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o\
		  ft_tolower.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o\
		  ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strsub.o\
		  ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_abs.o ft_itoa.o ft_putendl.o\
		  ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o\
		  ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_wordcount.o\
		  ft_wordlen.o ft_maxminrange.o ft_strnequ.o ft_swap.o ft_atol.o Get_Next_Line.o

FLAGS = -Wall -Wextra -Werror

HEAD = libft.h

GHEAD = libft.h.gch

all: $(NAME)

$(NAME):
	gcc -c $(SRCS) $(FLAGS) $(HEAD)
	ar rc $(NAME) $(OBJECTS) $(GHEAD)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJECTS)
	/bin/rm -f $(GHEAD)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

