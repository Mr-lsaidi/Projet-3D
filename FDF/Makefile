# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 22:15:58 by ebatchas          #+#    #+#              #
#    Updated: 2018/12/25 18:45:53 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=srcs
LIBDIR=libs
HEADDIR=includes
CFLAGS=-Wall -Wextra -I$(HEADDIR)
LDFLAGS= $(CFLAGS) -I$(HEADDIR) -L$(LIBDIR)/ -lmlx -lft -lm -framework OpenGL \
		 -framework AppKit 

SRC=$(SRCDIR)/main.c\
	$(SRCDIR)/utils.c\
	$(SRCDIR)/mlx_draw.c\
	$(SRCDIR)/tools.c\
	$(SRCDIR)/input.c\
	$(SRCDIR)/fdf.c\
	$(SRCDIR)/read_file.c\
	$(SRCDIR)/mlx_keycode.c

OBJ=$(LIBDIR)/main.o\
	$(LIBDIR)/utils.o\
	$(LIBDIR)/tools.o\
	$(LIBDIR)/input.o\
	$(LIBDIR)/mlx_draw.o\
	$(LIBDIR)/fdf.o\
	$(LIBDIR)/read_file.o\
	$(LIBDIR)/mlx_keycode.o

NAME=fdf

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)/libft/ fclean && make -C $(LIBDIR)/libft
	cp $(LIBDIR)/libft/libft.a $(LIBDIR)/
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBDIR)/%.o:$(HEADDIR)/%.h

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY:clean fclean

clean:
	rm -rf $(LIBDIR)/*.o
	make -C $(LIBDIR)/libft clean

fclean:clean
	rm -rf $(NAME)
	make -C $(LIBDIR)/libft fclean

re : fclean all
