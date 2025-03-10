# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:00:00 by mmiilpal          #+#    #+#              #
#    Updated: 2025/03/10 13:32:48 by mmiilpal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = megaphone

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source and object files
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

# Colors for output
GREEN = \033[0;32m
RESET = \033[00m

# Compilation rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Megaphone compiled successfully!$(RESET)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
