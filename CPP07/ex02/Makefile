CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98


NAME = ex02

INC = Array.hpp Array.tpp
 
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
%.o : %.cpp $(INC)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all