# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 10:49:04 by dpentlan          #+#    #+#              #
#    Updated: 2023/11/17 15:11:21 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc

SRC 			=	main/main.c \

NAME			=	cub3D

OBJ_FOLDER		=	objs/

CFLAGS			=	-Wall -Wextra -Werror -g

# Link to libft, mlx, and math libraries
LINKS			=	-Llibft -lft -Lmlx -lmlx -lXext -lX11 -lm

LIBS			=	libft/libft.a \
					minilibx/libmlx_Linux.a \

SUBMODULES		=	minilibx/.git \

SRC_FOLDER		=	srcs/

HEADERS_FOLDER	=	includes/ \
					libft/includes \
					minilibx \

DEPENDS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.d,$(SRC))
OBJS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.o,$(SRC))
COMMANDS	:=	$(patsubst %.c,$(OBJ_FOLDER)%.cc,$(SRC))

all: $(NAME) compile_commands.json

-include $(DEPENDS)

$(SUBMODULES) :
	git submodule update --init --recursive minilibx-linux

%.a: $(SUBMODULES)
	make -C $(@D)

$(NAME): $(LIBS) $(OBJS) $(SUBMODULES)
	make -C libft
#	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LINKS) -o $@

COMP_COMMAND = $(CC) -c $(CFLAGS) $(addprefix -I,$(HEADERS_FOLDER)) $(LINKS) -MMD -MP $< -o $@
CONCAT = awk 'FNR==1 && NR!=1 {print ","}{print}'

$(OBJ_FOLDER)%.o $(OBJ_FOLDER)%.cc: $(SRC_FOLDER)%.c
	$(COMP_COMMAND)
	@printf '{\n\t"directory" : "$(shell pwd)",\n\t"command" : "$(COMP_COMMAND)",\n\t"file" : "$<"\n}' > $(OBJ_FOLDER)$*.cc

compile_commands.json : $(COMMANDS) Makefile $(SUBMODULES)
	@echo "Making compile_commands.json"
	@echo "[" > compile_commands.json
	$(CONCAT) $(COMMANDS) >> compile_commands.json
	@echo "]" >> compile_commands.json

norm:
	find . \( -name "*.c" -o -name "*.h" \) -not -path "./minilibx-linux/*" -exec norminette {} +

clean: $(SUBMODULES)
	make -C libft clean
	rm -f $(OBJS) $(DEPENDS) $(COMMANDS)

fclean: clean $(SUBMODULES)
	make -C libft fclean
	rm -f $(NAME) compile_commands.json

re: fclean all

.PHONY: all clean fclean re bonus norm
.SUFFIXES:
# MAKEFLAGS += --warn-undefined-variables
# MAKEFLAGS += --no-builtin-rules
