# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <drafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/10/31 21:01:47 by drafe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror#-g --std=c99 -m64 -D_THREAD_SAFE

NAME = wolf3d

INCLUDES = ./includes/

HEADERS = $(INCLUDES)wolf3d.h\
	$(INCLUDES)keys.h\
	$(INCLUDES)constants.h

GO = $(shell pkg-config --libs --cflags $(INCLUDES)sdl2lib/pkgconfig/sdl2.pc)

LIBS = -L$(INCLUDES)libft/ -lft\
	-lSDL2 -lm

SRCDIR := srcdir

OBJDIR := objdir

OBJS := $(addprefix $(OBJDIR)/, main.o ft_map_save.o ft_map.o ft_sdl_run.o\
	ft_ray.o ft_draw.o ft_ui.o )

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(GO) $(CFLAGS) -I$(INCLUDES) $(LIBS) -o $(NAME) $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR): | libft
	mkdir $(OBJDIR)

libft:
	make -C ./includes/libft/

clean:
	make -C ./includes/libft/ clean
	rm -rf $(OBJS)

fclean: clean
	make -C ./includes/libft/ fclean
	rm -f $(NAME)

re: fclean all