CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = EF
INC = easyfind.hpp easyfind.tpp

SRCS = main.cpp 
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
