CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
INCS =  helpers.hpp ScalarConverter.hpp
SRCS=main.cpp helpers.cpp ScalarConverter.cpp
OBJS=$(SRCS:.cpp=.o)
NAME=ScalarConverter
all: $(NAME)
$(NAME): $(OBJS) $(INCS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
%.o: %.cpp $(INCS)
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)