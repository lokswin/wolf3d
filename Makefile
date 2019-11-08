# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <drafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/11/08 19:20:22 by drafe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror#-g --std=c99 -m64 -D_THREAD_SAFE

NAME = wolf3d

INCLUDES = ./include/

HEADERS = $(addprefix $(INCLUDES)/, constants.h keys.h wolf3d.h)

#GO = $(shell pkg-config --libs --cflags $(INCLUDES)sdl2lib/pkgconfig/sdl2.pc) #$(LIBFT)
SDL2 = ./include/sdl/SDL2.framework/Versions/A/SDL2

LIBS = -L$(INCLUDES)libft/ -lft\
	-I$(INCLUDES)SDL2\
	-F$(INCLUDES)sdl/ -framework SDL2#-lSDL2 -lm

SRCDIR := srcdir

OBJDIR := objdir

OBJS := $(addprefix $(OBJDIR)/, main.o ft_save_line.o ft_map.o ft_engine.o\
	ft_config.o ft_draw.o ft_ui.o ft_screen.o)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDES) $(LIBS) -o $(NAME) $(OBJS)
	install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 $(SDL2) $(NAME)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

LIBFT := $(shell cd $(INCLUDES)libft && $(MAKE))

clean:
	(cd $(INCLUDES)libft && $(MAKE) clean)
	rm -rf $(OBJS)

fclean: clean
	(cd $(INCLUDES)libft && $(MAKE) fclean)
	rm -f $(NAME)

re: fclean all