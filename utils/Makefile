# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysitkevi <ysitkevi@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 22:01:40 by ysitkevi          #+#    #+#              #
#    Updated: 2024/08/07 22:01:47 by ysitkevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(shell find . -name "*.c")
OBJS		=	$(SRCS:.c=.o)

NAME 		= 	42collection.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS) 
				
fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
