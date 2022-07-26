GAME_DIR = game/
SRC_GAME = draw.c event_utils.c game_init.c \
			main.c movement_utils.c movements.c \
			sprite.c
GAME_PRE = $(addprefix $(GAME_DIR), $(SRC_GAME))

PARSING_DIR = map_parsing/
SRC_PARSING = error_handling.c map_extension.c norm_helper.c \
				parsing_helpers.c parsing_utils.c
PARSING_PRE = $(addprefix $(PARSING_DIR), $(SRC_PARSING))

GNL_DIR = gnl/
SRC_GNL = get_next_line.c get_next_line_utils.c
GNL_PRE = $(addprefix $(GNL_DIR), $(SRC_GNL))

SRC_FILES = $(GAME_PRE) $(PARSING_PRE) $(GNL_PRE)

PRINTF_DIR = ft_printf/
NAME_PRINTF = libftprintf.a
PRINTF_PRE = $(addprefix $(PRINTF_DIR), $(NAME_PRINTF))

OBJS = *.o

CC = gcc

MLX_DIR = minilibx/
CFLAGS = -D BUFFER_SIZE=20 -Wall -Wextra -Werror
LDFLAGS = -Lminilibx -Iminilibx -lmlx_Linux -lX11 -lXext

NAME = so_long 

	
$(NAME): $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(MLX_DIR)
	gcc $(CFLAGS) $(OBJS) $(PRINTF_PRE) $(LDFLAGS) -o $(NAME)

$(OBJS): $(SRC_FILES)
	gcc $(CFLAGS) -c $(SRC_FILES) -I$(MLX_DIR)

all: $(NAME)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all