# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysitkevi <ysitkevi@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 21:56:17 by ysitkevi          #+#    #+#              #
#    Updated: 2024/08/07 21:56:24 by ysitkevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRC		=	server.c
CLIENT_SRC		=	client.c
42_COLLECTION	=	./utils/42collection.a

SERVER_OBJ	=	$(SERVER_SRC:.c=.o)
CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)

RM	=	rm -rf
CC	=	gcc
CFLAGS	= -Wall -Wextra -Werror

all:	client server

$(42_COLLECTION):
	@make -s -C ./utils

client: $(CLIENT_OBJ) $(42_COLLECTION)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) -o client $(42_COLLECTION)

server: $(SERVER_OBJ) $(42_COLLECTION)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) -o server $(42_COLLECTION)

clean:
	@make clean -C ./utils
	@$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	@make fclean -C ./utils
	@$(RM) server client

re: fclean all

.PHONY: all clean fclean re
