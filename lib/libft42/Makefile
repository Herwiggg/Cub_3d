NAME = libft.a

SOURCES =   ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_memset.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strrchr.c \
			ft_toupper.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strchr.c \
			ft_strlcpy.c \
			ft_strncmp.c \
			ft_tolower.c \
			ft_strnstr.c \
			ft_calloc.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_strlcat.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_split.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_itoa.c \
			ft_strtrim.c 

SOURCE_BONUS = 	ft_lstnew.c \
				ft_lstsize.c \
				ft_lstadd_front.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c 

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCE_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc $(FLAGS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)

$(NAME): $(SOURCES) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

bonus: $(SOURCES) $(OBJECTS) $(SOURCES_BONUS) $(OBJECTS_BONUS)
	ar rc $(NAME) $(OBJECTS) $(OBJECTS_BONUS)