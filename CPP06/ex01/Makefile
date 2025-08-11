CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = serialize

SRCS = main.cpp Serialize.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Serialize.hpp

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