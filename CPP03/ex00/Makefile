NAME = ClapTrap

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJ_DIR = obj/

SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
OBJ_PRE = $(addprefix $(OBJ_DIR), $(OBJS))

all: $(NAME)

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJ_PRE)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re