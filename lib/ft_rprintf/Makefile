LIBFT = libft/libft.a

NAME = libftprintf.a

SOURCES = ft_printf.c\
		  ft_printf_result.c\
		  ft_printf_argu_a.c\
		  ft_printf_argu_b.c\
		  ft_printf_tools_lst.c\
		  ft_printf_tools_hexa.c\
		  ft_printf_tools_itoa.c\
		  ft_printf_flag.c\
		  ft_printf_flag_checker.c\
		  ft_printf_flag_a.c\
		  ft_printf_flag_b.c\
		  ft_printf_flag_tools.c\
		  ft_printf_flag_tools_parse_s.c\
		  ft_printf_flag_tools_parse_d.c

OBJECTS = $(SOURCES:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc $(FLAGS)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJECTS) $(OBJBONUS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(NAME)

$(NAME): $(SOURCES) $(OBJECTS)
	$(MAKE) bonus -C ./libft
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJECTS)