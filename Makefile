CPP	=  Gkrellm/

SRC	=  $(CPP)main.cpp \
	   $(CPP)Module.cpp \
	   $(CPP)IMonitorModule.cpp \
	   $(CPP)Display.cpp

OBJS	= $(SRC:.cpp=.o)

CC	= g++

RM	= rm -f

I_DIR	= include/

CFLAGS	= -W -Wall -Wextra -Werror -Wfatal-errors -I./Class

LIB	= -lncurses

NAME	= mygkrellm

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
