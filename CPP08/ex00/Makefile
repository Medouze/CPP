CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = container

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = easyfind.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 