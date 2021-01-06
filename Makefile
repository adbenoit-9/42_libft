# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 18:38:18 by adbenoit          #+#    #+#              #
#    Updated: 2021/01/06 03:24:51 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

INC			=	inc/

HEADER		=	$(INC)libft.h

SRC_PATH	=	src/

SRC			=	ft_memset.c			ft_bzero.c			ft_memcpy.c \
				ft_memccpy.c		ft_memmove.c		ft_memchr.c \
				ft_memcmp.c			ft_strlen.c			ft_isalpha.c \
				ft_isdigit.c		ft_isalnum.c		ft_isascii.c \
				ft_isprint.c		ft_toupper.c		ft_tolower.c \
				ft_strchr.c			ft_strrchr.c		ft_strncmp.c \
				ft_strlcpy.c		ft_strlcat.c		ft_strnstr.c \
				ft_atoi.c			ft_calloc.c			ft_strdup.c \
				ft_substr.c			ft_strjoin.c		ft_strtrim.c \
				ft_split.c			ft_itoa.c			ft_strmapi.c \
				ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c \
				ft_putnbr_fd.c		ft_lstnew.c			ft_lstadd_front.c \
				ft_lstsize.c		ft_lstlast.c		ft_lstadd_back.c \
				ft_lstdelone.c		ft_lstclear.c		ft_lstiter.c \
				ft_lstmap.c			ft_puttab_fd.c		ft_realloc_tab.c \
				ft_tabdup.c			ft_freetab.c		ft_realloc.c \
				ft_strcat.c			ft_tabsize.c		ft_strcpy.c \
				ft_strncpy.c		get_next_line.c		get_next_line_utils.c \
				ft_strndup.c

OBJ_PATH	=	obj/

OBJ_NAME	=	${SRC:.c=.o}

OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

${NAME} : ${OBJ}
	@ar rc ${NAME} ${OBJ}
	@printf "\n"
	@echo "Compilation of \033[33;1mLibft\033[0;1m: [\033[1;32mOK\0]"

all:	${NAME}

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@${RM} ${OBJ_PATH}
	@echo "\033[33;1mLibft\033[0;1m: objects deleted\033[0m"

fclean: clean
	@${RM} ${NAME} 
	@echo "\033[33;1mLibft\033[0;1m: $(NAME) deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus
