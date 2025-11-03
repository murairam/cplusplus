NAME = RPN

CXX = c++

CXXFLAGS = -Werror -Wall -Wextra -std=c++98
DEPFLAGS = -MMD -MP

SRC = main.cpp RPN.cpp

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
