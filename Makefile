# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/09 19:27:02 by bwanlin           #+#    #+#              #
#    Updated: 2015/06/28 15:50:20 by bwanlin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC = clang++
CFLAGS = -Wall -Wextra -Werror
#--------------Name-------------------------#
NAME = ft_gkrellm

#--------------Sources----------------------#
SRCS =	main.cpp					\
		graphic/ModuleRow.cpp		\
		graphic/MonitorModule.cpp	\
		graphic/Window.cpp			\
		modules/OSinfo.class.cpp	\
		modules/CPUmod.class.cpp	\
		modules/RAMModule.cpp		\
		modules/FooBar.cpp			\
		modules/TimeModule.cpp		\
		modules/Tools.class.cpp		\
		modules/NameModule.cpp		\
		modules/PonyModule.cpp		\
		modules/NyanCatModule.cpp	\
		modules/NetworkModule.cpp

INC = 	includes

OBJS	=	$(SRCS:.cpp=.o)

#--------------Actions----------------------#

all: $(NAME)

EXE		=	ft_gkrellm

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INC) -lncurses -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, fclean, clean, re 
