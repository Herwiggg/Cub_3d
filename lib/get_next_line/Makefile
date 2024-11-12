NAME = gnl.a

SOURCES = get_next_line.c\
		  get_next_line_utils.c\

OBJECTS = $(SOURCES:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = gcc $(FLAGS)

all: $(NAME)

clean:
	rm -f $(OBJECTS) $(OBJBONUS)
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(SRCBONUS) $(OBJBONUS) $(NAME)
	ar rc $(NAME) $(OBJBONUS)

$(NAME): $(SOURCES) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)