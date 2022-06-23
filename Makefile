NAME = cub3D

HEADER = cub3D.h

INCLUDE = -I ./include/

FOLDER = ./src/

FOLDER_OBJS = ./objs/

SRC =	$(addprefix $(FOLDER), \
		exit.c \
		cub3D.c \
		make_image.c \
		commands.c \
		my_img_pixel_put.c \
		error.c \
		verify_map.c \
		verify_tex.c \
		utils.c \
		check_walls.c \
		free_cub.c \
		raycast.c \
		init.c \
		validate.c)

OBJS	= $(patsubst $(FOLDER)%.c, $(FOLDER_OBJS)%.o, $(SRC))

CC = gcc

LIB = -lbsd -lmlx -lXext -lX11 -lm -lz

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Werror -Wextra -g

all:$(NAME)

$(FOLDER_OBJS)%.o: $(FOLDER)%.c
	@mkdir -p $(FOLDER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@rm -f $(NAME)
	@$(CC) $(CFLAGS ) $(INCLUDE) -o $(NAME) $(OBJS) $(LIB) $(LIBFT)

$(LIBFT):
	@make -C ./libft

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
