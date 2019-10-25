# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <drafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/10/25 18:15:05 by drafe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc

CFLAGS = -Wall -Wextra -Werror -g # -m64 -D_THREAD_SAFE

NAME = wolf3d

HEADERS = wolf3d.h\
	keys.h\
	constants.h

INCLUDES = -I include

LIBS = -L./Libft/ -lft\
	-L./sdl2lib -l SDL2-2.0.0 -framework Metal

OBJS = main.o\
	ft_map.o\
	ft_sdl_run.o\
	ft_draw.o

all: $(NAME)

$(NAME):$(OBJS) | lib
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(NAME) $(OBJS) 

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
 