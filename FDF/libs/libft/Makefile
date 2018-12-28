# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 17:03:06 by ebatchas          #+#    #+#              #
#    Updated: 2018/11/28 23:07:27 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR = .
LIBDIR = .
HEADDIR = .

CFLAGS=-I$(HEADDIR) -Wall -Wextra -Werror

SRC=$(SRCDIR)/ft_atoi.c\
	$(SRCDIR)/ft_isalnum.c\
	$(SRCDIR)/ft_isascii.c\
	$(SRCDIR)/ft_isalpha.c\
	$(SRCDIR)/ft_isdigit.c\
	$(SRCDIR)/ft_isprint.c\
	$(SRCDIR)/ft_bzero.c\
	$(SRCDIR)/ft_lstnew.c\
	$(SRCDIR)/ft_lstadd.c\
	$(SRCDIR)/ft_lstadd2.c\
	$(SRCDIR)/ft_lstdelone.c\
	$(SRCDIR)/ft_lstdel.c\
	$(SRCDIR)/ft_lstiter.c\
	$(SRCDIR)/ft_lstdup.c\
	$(SRCDIR)/ft_lstjoin.c\
	$(SRCDIR)/ft_lstlen.c\
	$(SRCDIR)/ft_lstmap.c\
	$(SRCDIR)/ft_memalloc.c\
	$(SRCDIR)/ft_memcpy.c\
	$(SRCDIR)/ft_memchr.c\
	$(SRCDIR)/ft_memccpy.c\
	$(SRCDIR)/ft_memdel.c\
	$(SRCDIR)/ft_memcmp.c\
	$(SRCDIR)/ft_memset.c\
	$(SRCDIR)/ft_memmove.c\
	$(SRCDIR)/ft_putchar.c\
	$(SRCDIR)/ft_putchar_fd.c\
	$(SRCDIR)/ft_putendl.c\
	$(SRCDIR)/ft_putendl_fd.c\
	$(SRCDIR)/ft_putnbr.c\
	$(SRCDIR)/ft_putnbr_fd.c\
	$(SRCDIR)/ft_putstr.c\
	$(SRCDIR)/ft_putstr_fd.c\
	$(SRCDIR)/ft_strclr.c\
	$(SRCDIR)/ft_strcat.c\
	$(SRCDIR)/ft_strcpy.c\
	$(SRCDIR)/ft_strchr.c\
	$(SRCDIR)/ft_strcmp.c\
	$(SRCDIR)/ft_strdel.c\
	$(SRCDIR)/ft_strdup.c\
	$(SRCDIR)/ft_striter.c\
	$(SRCDIR)/ft_strequ.c\
	$(SRCDIR)/ft_striteri.c\
	$(SRCDIR)/ft_strlen.c\
	$(SRCDIR)/ft_strlcat.c\
	$(SRCDIR)/ft_strmap.c\
	$(SRCDIR)/ft_strjoin.c\
	$(SRCDIR)/ft_strmapi.c\
	$(SRCDIR)/ft_strncat.c\
	$(SRCDIR)/ft_strncpy.c\
	$(SRCDIR)/ft_strncmp.c\
	$(SRCDIR)/ft_strnequ.c\
	$(SRCDIR)/ft_strns.c\
	$(SRCDIR)/ft_strncat.c\
	$(SRCDIR)/ft_strnstr.c\
	$(SRCDIR)/ft_strnew.c\
	$(SRCDIR)/ft_strrchr.c\
	$(SRCDIR)/ft_strstr.c\
	$(SRCDIR)/ft_tolower.c\
	$(SRCDIR)/ft_toupper.c\
	$(SRCDIR)/ft_strsub.c\
	$(SRCDIR)/ft_strsplit.c\
	$(SRCDIR)/ft_strtrim.c\
	$(SRCDIR)/ft_itoa.c\
	$(SRCDIR)/ft_get_next_line.c
OBJ=$(LIBDIR)/ft_atoi.o\
	$(LIBDIR)/ft_isalnum.o\
	$(LIBDIR)/ft_isascii.o\
	$(LIBDIR)/ft_isalpha.o\
	$(LIBDIR)/ft_isdigit.o\
	$(LIBDIR)/ft_isprint.o\
	$(LIBDIR)/ft_bzero.o\
	$(LIBDIR)/ft_lstnew.o\
	$(LIBDIR)/ft_lstadd.o\
	$(LIBDIR)/ft_lstadd2.o\
	$(LIBDIR)/ft_lstdelone.o\
	$(LIBDIR)/ft_lstdel.o\
	$(LIBDIR)/ft_lstiter.o\
	$(LIBDIR)/ft_lstdup.o\
	$(LIBDIR)/ft_lstjoin.o\
	$(LIBDIR)/ft_lstlen.o\
	$(LIBDIR)/ft_lstmap.o\
	$(LIBDIR)/ft_memalloc.o\
	$(LIBDIR)/ft_memcpy.o\
	$(LIBDIR)/ft_memchr.o\
	$(LIBDIR)/ft_memccpy.o\
	$(LIBDIR)/ft_memdel.o\
	$(LIBDIR)/ft_memcmp.o\
	$(LIBDIR)/ft_memset.o\
	$(LIBDIR)/ft_memmove.o\
	$(LIBDIR)/ft_putchar.o\
	$(LIBDIR)/ft_putchar_fd.o\
	$(LIBDIR)/ft_putendl.o\
	$(LIBDIR)/ft_putendl_fd.o\
	$(LIBDIR)/ft_putnbr.o\
	$(LIBDIR)/ft_putnbr_fd.o\
	$(LIBDIR)/ft_putstr.o\
	$(LIBDIR)/ft_putstr_fd.o\
	$(LIBDIR)/ft_strclr.o\
	$(LIBDIR)/ft_strcat.o\
	$(LIBDIR)/ft_strcpy.o\
	$(LIBDIR)/ft_strchr.o\
	$(LIBDIR)/ft_strcmp.o\
	$(LIBDIR)/ft_strdel.o\
	$(LIBDIR)/ft_strdup.o\
	$(LIBDIR)/ft_striter.o\
	$(LIBDIR)/ft_strequ.o\
	$(LIBDIR)/ft_striteri.o\
	$(LIBDIR)/ft_strlen.o\
	$(LIBDIR)/ft_strlcat.o\
	$(LIBDIR)/ft_strmap.o\
	$(LIBDIR)/ft_strjoin.o\
	$(LIBDIR)/ft_strmapi.o\
	$(LIBDIR)/ft_strncat.o\
	$(LIBDIR)/ft_strncpy.o\
	$(LIBDIR)/ft_strncmp.o\
	$(LIBDIR)/ft_strnequ.o\
	$(LIBDIR)/ft_strns.o\
	$(LIBDIR)/ft_strncat.o\
	$(LIBDIR)/ft_strnstr.o\
	$(LIBDIR)/ft_strnew.o\
	$(LIBDIR)/ft_strrchr.o\
	$(LIBDIR)/ft_strstr.o\
	$(LIBDIR)/ft_tolower.o\
	$(LIBDIR)/ft_toupper.o\
	$(LIBDIR)/ft_strsub.o\
	$(LIBDIR)/ft_strsplit.o\
	$(LIBDIR)/ft_strtrim.o\
	$(LIBDIR)/ft_itoa.o\
	$(LIBDIR)/ft_get_next_line.o
NAME=libft.a

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -c
	ar rc $@ $(OBJ)
	ranlib $@

.PHONY: clean fclean

clean:
	rm -rf *.o
fclean : clean
	rm -rf $(NAME)
re: fclean all
