# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 12:02:56 by ikozhina          #+#    #+#              #
#    Updated: 2025/03/16 22:39:43 by ikozhina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Names of the executables
SERVER = server
CLIENT = client

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft -I./include

# Source files and object files
SRCS = client.c server.c
OBJS = $(SRCS:.c=.o)

# Library location
LIBFT = libft/libft.a
LIBFT_PATH = libft

# Default target (all)
all: $(LIBFT) $(SERVER) $(CLIENT) 

# Server target
$(SERVER): server.o $(LIBFT)
	$(CC) $(CFLAGS) server.o $(LIBFT) -o $(SERVER)

# Client target
$(CLIENT): client.o $(LIBFT)
	$(CC) $(CFLAGS) client.o $(LIBFT) -o $(CLIENT)

# Compile library
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Compile .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f server.o client.o
	$(MAKE) -C $(LIBFT_PATH) clean

# Clean all, including executables and library files
fclean: clean
	rm -f $(SERVER) $(CLIENT) 
	$(MAKE) -C $(LIBFT_PATH) fclean

# Rebuild everything
re: fclean all

# Declare non-file targets
.PHONY: all clean fclean re
