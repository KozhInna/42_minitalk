# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 12:02:56 by ikozhina          #+#    #+#              #
#    Updated: 2025/03/19 12:09:28 by ikozhina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Names of the executables
SERVER = server
CLIENT = client
SERVER_B = server_bonus
CLIENT_B = client_bonus

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft -I./include

# Source files and object files
SRCS = client.c server.c
SRCS_UTILS = utils.c
SRCS_B = client_bonus.c server_bonus.c
SRCS_UTILS_B = utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_UTILS = $(SRCS_UTILS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
OBJS_UTILS_B = $(SRCS_UTILS_B:.c=.o)

# Header files
HEADERS = include/minitalk.h
HEADERS_B = include/minitalk_bonus.h

# Library location
LIBFT = libft/libft.a
LIBFT_PATH = libft

# Default target (all)
all: $(LIBFT) $(SERVER) $(CLIENT)

# Server executable
$(SERVER): server.o $(OBJS_UTILS) $(LIBFT)
	$(CC) $(CFLAGS) server.o $(OBJS_UTILS) $(LIBFT) -o $(SERVER)

# Client executable
$(CLIENT): client.o $(OBJS_UTILS) $(LIBFT)
	$(CC) $(CFLAGS) client.o $(OBJS_UTILS) $(LIBFT) -o $(CLIENT)

# Compile library
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Bonus rules
bonus: $(SERVER_B) $(CLIENT_B)

$(SERVER_B): server_bonus.o $(OBJS_UTILS_B) $(LIBFT)
	$(CC) $(CFLAGS) server_bonus.o $(OBJS_UTILS_B) $(LIBFT) -o $(SERVER_B)

$(CLIENT_B): client_bonus.o $(OBJS_UTILS_B)  $(LIBFT)
	$(CC) $(CFLAGS) client_bonus.o $(OBJS_UTILS_B)  $(LIBFT) -o $(CLIENT_B)

# Compile .o files
%.o: %.c $(HEADERS) $(HEADERS_B)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS) $(OBJS_B) $(OBJS_UTILS) $(OBJS_UTILS_B)
	$(MAKE) -C $(LIBFT_PATH) clean

# Clean all, including executables and library files
fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	$(MAKE) -C $(LIBFT_PATH) fclean

# Rebuild everything
re: fclean all

# Rebuild bonus
rebonus: fclean bonus

# Declare non-file targets
.PHONY: all clean fclean re bonus rebonus
