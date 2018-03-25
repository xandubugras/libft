# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubugra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 18:20:10 by adubugra          #+#    #+#              #
#    Updated: 2018/03/25 12:32:54 by adubugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIB		= ar rc

RLIB	= ranlib

# src / obj files
SRC		= ft_printf.c \
		  set_descriptor.c \
		  set_descriptor2.c \
		  handling.c \
		  handling2.c \
		  arguments.c \
		  arguments_u.c \
		  unknown_chars.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./src/
INCDIR	= ./include/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -c $<

$(FT_LIB):
	make -C $(FT)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

comp: obj $(FT_LIB) $(OBJ)
	$(CC) -c src/main.c
	$(CC) $(OBJ) main.o $(FT_LNK) -lm -o ft_printf

clean:
	rm -rf $(OBJDIR)
	rm main.o
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
