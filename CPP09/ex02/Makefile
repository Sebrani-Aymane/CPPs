CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3


NAME = PmergeMe
INC = PmergeMe.hpp
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o : %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
