CLIENT_NAME = client

SERVER_NAME = server

all : $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) : server.c minitalk.h
		make -C libft
		gcc -Wall -Wextra -Werror server.c libft/libft.a -o $(SERVER_NAME)

$(CLIENT_NAME) : main_client.c minitalk.h
		make -C libft
		gcc -Wall -Wextra -Werror main_client.c libft/libft.a -o $(CLIENT_NAME)

clean:
		make clean -C libft

fclean:	clean
		make fclean -C libft
		rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re:		fclean all

PHONY:	all clean fclean re