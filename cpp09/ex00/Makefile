NAME = btc

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g
DEPFLAGS = -MMD -MP

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "compiled"

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEP)

clean :
	@rm -f $(OBJ) $(DEP)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
