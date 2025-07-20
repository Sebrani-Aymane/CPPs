CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98


NAME = IRT

INC = A.hpp    B.hpp    Base.hpp C.hpp

SRCS = Base.cpp main.cpp
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