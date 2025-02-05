# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 21:47:46 by ismherna          #+#    #+#              #
#    Updated: 2025/02/05 01:27:42 by ismherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
LIBFT_DIR = $(shell find .. -name "libft" -type d) # Find libft directory
LIBFT = $(LIBFT_DIR)/libft.a
TESTS = $(SRC_DIR)/test_atoi.c $(SRC_DIR)/test_bzero.c $(SRC_DIR)/test_calloc.c # ... otros tests
EXECUTABLES = $(TESTS:$(SRC_DIR)/%.c=%)


# Reglas
all: $(LIBFT) $(EXECUTABLES)

$(LIBFT):
	@echo "Compilando libft desde: $(LIBFT_DIR)"
	$(MAKE) -C $(LIBFT_DIR)

flag_tests: $(EXECUTABLES)

%: $(SRC_DIR)/%.c $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@ $(LIBFT)

libft_tester: $(LIBFT) $(SRC_DIR)/main.c $(TESTS)
	$(CC) $(CFLAGS) $(SRC_DIR)/main.c $(TESTS) -o $(LIBFT_TESTER) $(LIBFT)

run_libft_tester: $(LIBFT_TESTER)
	./$(LIBFT_TESTER)

clean:
	rm -f $(EXECUTABLES) $(LIBFT_TESTER)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(LIBFT)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all