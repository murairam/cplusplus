NAME = realtype
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Base.cpp

HDR = Base.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "compiled!"

%.o : %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY : all clean fclean re