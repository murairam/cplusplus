# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/15 19:45:56 by mmiilpal          #+#    #+#              #
#    Updated: 2025/08/15 19:47:19 by mmiilpal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp

OBJ = $(SRC:.cpp=.o)
BBlue=\033[1;34m 
RESET = \033[00m

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(BBlue)compiled! $(RESET)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re