# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dim <dim@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 05:48:39 by yoojlee           #+#    #+#              #
#    Updated: 2021/10/28 19:13:41 by dim              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libft.a
AR = ar rcs

SRCS = ft_atof.c \
	   ft_isdigit.c \
	   ft_chrsplit.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strlen.c \
	   ft_split.c \
	   ft_strcmp.c \
	   get_next_line.c \
	   get_next_line_utils.c


OBJS = ft_atof.o \
	   ft_isdigit.o \
	   ft_chrsplit.o \
	   ft_strchr.o \
	   ft_strdup.o \
	   ft_strlen.o \
	   ft_split.o \
	   ft_strcmp.o \
	   get_next_line.o \
	   get_next_line_utils.o

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

bonus_: $(OBJS)
	$(AR) $(NAME) $^

bonus: bonus_

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
