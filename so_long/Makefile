MLX_PATH	=	./minilibx_mms/mlx.h

HEAD		= 	so_long.h

SRC			=	utils.c \
				movies.c \
				parser.c \
				so_long.c \
				messages.c \
				lets_play.c \
				exit_sprites.c \
				coin_sprites.c \
				enemy_sprites.c \
				get_next_line.c \
				player_movies.c \
				initialisations.c \
				lets_play_funcs.c \
				stay_left_sprites.c \
				stay_right_sprites.c \
				final_ghost_sprites.c \
				get_next_line_utils.c \

SRC2		=	utils.c \
				movies.c \
				parser.c \
				messages.c \
				lets_play.c \
				exit_sprites.c \
				coin_sprites.c \
				so_long_bonus.c \
				enemy_sprites.c \
				get_next_line.c \
				player_movies.c \
				initialisations.c \
				lets_play_funcs.c \
				stay_left_sprites.c \
				stay_right_sprites.c \
				final_ghost_sprites.c \
				get_next_line_utils.c \

MLX			=	$(MLX_PATH)libmlx.dylib

NAME		=	so_long

OBJS		=	$(SRC:.c=.o)
OBJS2		=	$(SRC2:.c=.o)

CC			=	gcc

RM			= 	rm -rf

CFLAGS		= 	-Wall -Wextra -Werror

$(NAME)		:	$(OBJS)
				$(MAKE) -C ./minilibx_mms
				$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS)		:	$(HEAD)

bonus		:	$(OBJS2)
				$(MAKE) -C ./minilibx_mms
				$(CC) $(CFLAGS) $(OBJS2) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS2)	:	$(HEAD)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS) $(OBJS2)
				$(MAKE) clean -C ./minilibx_mms

fclean		:	clean
				$(RM) $(NAME)
				$(RM) ./minilibx_mms/libmlx.dylib

re			:	fclean	all

.PHONY		:	all clean fclean re bonus
