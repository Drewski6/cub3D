# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 10:49:04 by dpentlan          #+#    #+#              #
#    Updated: 2023/12/08 14:46:58 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc

SRC				=	args/arg_parsing.c \
					debug/map_debug.c \
					engine/drawing/colors.c \
					engine/drawing/line.c \
					engine/drawing/rectangle.c \
					engine/engine/init_free_engine.c \
					engine/engine/keys.c \
					engine/engine/map.c \
					engine/engine/render.c \
					engine/image_utils/create_rect.c \
					engine/image_utils/get_or_send_image.c \
					engine/image_utils/init_free_image.c \
					engine/image_utils/textures.c \
					engine/player/player.c \
					engine/rays/draw_textures.c \
					engine/rays/fill_image_with_rays.c \
					engine/rays/horiz_rays.c \
					engine/rays/misc_utils.c \
					engine/rays/rays.c \
					engine/rays/vert_rays.c \
					map_parsing/map_data_load.c \
					map_parsing/map_data_valid.c \
					map_parsing/map_elements.c \
					map_parsing/map_readin.c \
					map_parsing/map_validation.c \
					map_parsing/map_crawl.c \
					main/close.c \
					main/hooks.c \
					main/main.c \

NAME			=	cub3D

NAME_BONUS		=	cub3D_bonus

OBJ_FOLDER		=	objs/

OBJ_FOLDER_BONUS	=	objs_bonus/

CFLAGS			=	-Wall -Wextra -Werror -g

# Link to libft, mlx, and math libraries
LINKS			:=	-Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm

LIBS			=	libft/libft.a \
					minilibx-linux/libmlx_Linux.a \

SUBMODULES		=	minilibx-linux/.git \
					libft/.git \

SRC_FOLDER		=	srcs/

SRC_FOLDER_BONUS	=	srcs_bonus/

HEADERS_FOLDER	=	includes/ \
					libft/includes \
					minilibx-linux \

DEPENDS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.d,$(SRC))
OBJS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.o,$(SRC))
OBJS_BONUS	:=	$(patsubst %.c,$(OBJ_FOLDER_BONUS)%.o,$(SRC))
COMMANDS	:=	$(patsubst %.c,$(OBJ_FOLDER)%.cc,$(SRC))

all: $(NAME) compile_commands.json

bonus: $(NAME_BONUS) compile_commands.json

-include $(DEPENDS)

$(SUBMODULES) :
	git submodule update --init --recursive minilibx-linux
	git submodule update --init --recursive libft

%.a: $(SUBMODULES)
	make -C $(@D)

$(NAME): $(LIBS) $(OBJS) $(SUBMODULES)
	$(CC) $(CFLAGS) $(OBJS) $(LINKS) -o $@

$(NAME_BONUS): $(LIBS) $(OBJS_BONUS) $(SUBMODULES)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LINKS) -o $@

COMP_COMMAND = $(CC) -c $(CFLAGS) $(addprefix -I,$(HEADERS_FOLDER)) -MMD -MP $< -o $@
CONCAT = awk 'FNR==1 && NR!=1 {print ","}{print}'

$(OBJ_FOLDER_BONUS)%.o $(OBJ_FOLDER_BONUS)%.cc: $(SRC_FOLDER_BONUS)%.c
	@mkdir -p $(dir $@)
	$(COMP_COMMAND)
	@printf '{\n\t"directory" : "$(shell pwd)",\n\t"command" : "$(COMP_COMMAND)",\n\t"file" : "$<"\n}' > $(OBJ_FOLDER_BONUS)$*.cc

$(OBJ_FOLDER)%.o $(OBJ_FOLDER)%.cc: $(SRC_FOLDER)%.c
	@mkdir -p $(dir $@)
	$(COMP_COMMAND)
	@printf '{\n\t"directory" : "$(shell pwd)",\n\t"command" : "$(COMP_COMMAND)",\n\t"file" : "$<"\n}' > $(OBJ_FOLDER)$*.cc

compile_commands.json : $(COMMANDS) Makefile $(SUBMODULES)
	@echo "Making compile_commands.json"
	@echo "[" > compile_commands.json
	$(CONCAT) $(COMMANDS) >> compile_commands.json
	@echo "]" >> compile_commands.json

norm:
	@find . \( -name "*.c" -o -name "*.h" \) -not -path "./minilibx-linux/*" -exec norminette {} +

clean: $(SUBMODULES)
	@rm -rf $(OBJ_FOLDER) $(OBJ_FOLDER_BONUS)
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean $(SUBMODULES)
	rm -f $(NAME) $(NAME_BONUS) compile_commands.json
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus norm
.SUFFIXES:
# MAKEFLAGS += --warn-undefined-variables
# MAKEFLAGS += --no-builtin-rules
