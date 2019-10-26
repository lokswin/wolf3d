# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <drafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/10/26 19:20:19 by drafe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc

CFLAGS = -Wall -Wextra -Werror -g# --std=c99 -m64 -D_THREAD_SAFE

NAME = wolf3d

HEADERS = wolf3d.h\
	keys.h\
	constants.h

INCLUDES = -I include

GO = $(shell pkg-config --libs --cflags ./sdl2lib/pkgconfig/sdl2.pc)

LIBS = -L./Libft/ -lft\
	-lSDL2 -lm
	#-L./sdl2lib -l SDL2-2.0.0\
	#-framework OpenGL -framework AppKit# -framework cocoa -framework Metal -framework OpenGL -framework AppKit

#FRAMEWORKS = -F . -framework cocoa -framework Metal -framework OpenGL -framework AppKit

OBJS = main.o\
	ft_map.o\
	ft_sdl_run.o\
	ft_draw.o\
	ft_ui.o

all: $(NAME)

$(NAME):$(OBJS) | lib
	
	$(CC) $(GO) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(NAME) $(OBJS) 

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
lib:
	@make -f Makefile.libft

clean:
	@make -f Makefile.libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -f Makefile.libft fclean
	@rm -f $(NAME)

re: fclean all
 