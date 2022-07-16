NAME 		= containers
CPPFILE 	= main.cpp
FLAGS 		= -Werror -Wall -Wextra -std=c++98

all: $(NAME)

$(NAME): $(CPPFILE)
	@echo "\033[0;33mLinking process..."
	c++ $(FLAGS) $(CPPFILE) -o $(NAME)
	@echo "\033[0;32m-----------------------------------"
	@echo "\033[0;32m|              DONE               |"
	@echo "\033[0;32m-----------------------------------"

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re