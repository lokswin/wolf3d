# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <drafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/10/23 15:32:24 by drafe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#vulkansdk/macOS/lib. vulkan-headers 1.1.125

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -m64

NAME = wolf3d

HEADERS = wolf3d.h\
	keys.h\
	constants.h

INCLUDES = -I/Users/drafe/.brew/Cellar/cglm/0.6.0/include\
	-I/Users/drafe/.brew/Cellar/glfw/3.3/include
	

LIBS = -L./Libft/ -lft\
	-lmlx -framework OpenGL -framework AppKit -lvulkan\
	-L/Users/drafe/.brew/Cellar/cglm/0.6.0/lib -lcglm -lm\
	-L/Users/drafe/.brew/Cellar/glfw/3.3/lib -lglfw

OBJS = main.o\
	ft_run_glfw.o\
	ft_run_vk.o\
	ft_run_pd.o\
	ft_map.o

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
 