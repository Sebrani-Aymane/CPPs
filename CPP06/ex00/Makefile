CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = CST

INC = ScalarConverter.hpp 

SRCS = main.cpp ScalarConverter.cpp helpers.cpp
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