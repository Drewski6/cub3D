# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:36:56 by dpentlan          #+#    #+#              #
#    Updated: 2023/11/17 23:56:35 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

NAME = libft.a

# ***** Sources *****

SRCS =				mandatory/ft_isalpha.c \
					mandatory/ft_isdigit.c \
					mandatory/ft_isalnum.c \
					mandatory/ft_isascii.c \
					mandatory/ft_isprint.c \
					mandatory/ft_strlen.c \
					mandatory/ft_memset.c \
					mandatory/ft_bzero.c \
					mandatory/ft_memcpy.c \
					mandatory/ft_memmove.c \
					mandatory/ft_strlcpy.c \
					mandatory/ft_strlcat.c \
					mandatory/ft_toupper.c \
					mandatory/ft_tolower.c \
					mandatory/ft_strchr.c \
					mandatory/ft_strrchr.c \
					mandatory/ft_strncmp.c \
					mandatory/ft_memchr.c \
					mandatory/ft_memcmp.c \
					mandatory/ft_strnstr.c \
					mandatory/ft_atoi.c \
					mandatory/ft_calloc.c \
					mandatory/ft_strdup.c \
					mandatory/ft_substr.c \
					mandatory/ft_strjoin.c \
					mandatory/ft_strtrim.c \
					mandatory/ft_split.c \
					mandatory/ft_itoa.c \
					mandatory/ft_strmapi.c \
					mandatory/ft_striteri.c \
					mandatory/ft_putchar_fd.c \
					mandatory/ft_putstr_fd.c \
					mandatory/ft_putendl_fd.c \
					mandatory/ft_putnbr_fd.c \
					bonus/ft_lstnew.c \
					bonus/ft_lstadd_front.c \
					bonus/ft_lstsize.c \
					bonus/ft_lstlast.c \
					bonus/ft_lstadd_back.c \
					bonus/ft_lstdelone.c \
					bonus/ft_lstclear.c \
					bonus/ft_lstiter.c \
					bonus/ft_lstmap.c \
					gnl/get_next_line.c \
					ft_printf/ft_printf_bonus.c \
					ft_printf/ft_printf_utils_1_bonus.c \
					ft_printf/ft_printf_utils_2_bonus.c \
					ft_printf/ft_printf_utils_3_bonus.c \
					ft_printf/ft_printf_utils_format_switch_bonus.c \
					ft_printf/ft_printf_utils_subseq_helpers_bonus.c \
					ft_printf/ft_printf_utils_t_flags_bonus.c \
					ft_printf/ft_printf_utils_use_flags_bonus.c \

SRCS_DIR = srcs/

# ***** Includes *****

INCS_DIR = includes/

# ***** Objects *****

OBJS_DIR = objs/

DEPENDS			:= $(patsubst %.c,$(OBJS_DIR)%.d,$(SRCS))
OBJS			:= $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))
COMMANDS		:= $(patsubst %.c,$(OBJS_DIR)%.cc,$(SRCS))

# ***** Compiler and Archiver *****

CFLAGS = -Wall -Wextra -Werror -g
CC = cc
ARC = ar rcs
COMP_COMMAND = $(CC) -c $(CFLAGS) $(addprefix -I,$(INCS_DIR)) -MMD -MP $< -o $@
CONCAT = awk 'FNR==1 && NR!=1 {print ","}{print}'

# ***** Build *****

all: $(NAME) compile_commands.json

$(NAME): $(OBJS)
	$(ARC) $(NAME) -o $(OBJS)

$(OBJS_DIR)%.o $(OBJS_DIR)%.cc: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(COMP_COMMAND)
	@printf '\t{\n\t\t"directory" : "$(shell pwd)",\n\t\t"command" : "$(COMP_COMMAND)",\n\t\t"file" : "$<"\n\t}' > $(OBJS_DIR)$*.cc

clean:
	@rm -rf $(OBJS_DIR)

fclean:	clean
	@rm -f $(NAME) compile_commands.json

re:	fclean all

compile_commands.json: $(COMMANDS) Makefile
	@echo "[" > compile_commands.json
	@$(CONCAT) $(COMMANDS) >> compile_commands.json
	@echo "]" >> compile_commands.json

.PHONY:		all clean fclean re bonus norm
.SUFFIXES:
