NAME	= cub3D
CFLAGS	= -Wall -Wextra -Werror

LIBMLX	= ./lib/MLX42
RPTINTF	= ./lib/ft_rprintf
GNL		= ./lib/get_next_line
LIBFT	= ./lib/libft42

HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= $(LIBFT)/libft.a $(GNL)/gnl.a $(RPTINTF)/libftprintf.a $(LIBMLX)/libmlx42.a -ldl -lglfw -L "/users/"$$USER"/.brew/opt/glfw/lib/" -pthread -lm

SRCS =	src/main.c\
		src/copy_file.c\
		src/parsing_map_utils.c\
		src/stock_data.c
		
OBJS	= ${SRCS:.c=.o}
OBJS_BN	= ${SRCS_BN:.c=.o}

all: gnl rprintf libmlx $(NAME)

bonus: gnl rprintf libmlx $(NAME)

gnl:
	@$(MAKE) -C $(GNL)

rprintf:
	@$(MAKE) -C $(RPTINTF)

	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)


clean:
	@rm -f $(OBJS) $(OBJS_BN)
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(RPTINTF) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(RPTINTF) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx