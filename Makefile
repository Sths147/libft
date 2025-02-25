# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 12:41:53 by sithomas          #+#    #+#              #
#    Updated: 2025/01/20 11:27:39 by sithomas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \

INC = libft.h \
	get_next_line/get_next_line.h

OFILES = $(SRC:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OFILES)
	@$(MAKE) -s -C printf
	@cp printf/*.o .
	@ar rcs $(NAME) *.o
	@ranlib $(NAME)
	@echo 'libft.a created'

%.o: %.c $(INC) printf/*.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) fclean -s -C printf
	@rm -f *.o get_next_line/*.o ft_printf/*.o
	@echo 'libft objs cleaned'

fclean: clean
	@rm -f $(NAME)
	@echo 'libft all cleaned'

re:	fclean all

.PHONY: all clean fclean re bonus
