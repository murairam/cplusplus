NAME = interface

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Character.cpp AMateria.cpp Cure.cpp Ice.cpp MateriaSource.cpp MateriaManager.cpp

OBJ = $(SRC:.cpp=.o)

BBlue=\033[1;34m 
RESET = \033[00m

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(BBlue)compiled! $(RESET)"
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re