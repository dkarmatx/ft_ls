# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgranule <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 13:49:17 by hgranule          #+#    #+#              #
#    Updated: 2019/06/11 14:13:29 by hgranule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
FLAGS = -Wall -Werror -Wextra -O
LIBFT = libft.a

CUR_DIR = $(shell pwd)
O_DIR = $(CUR_DIR)/objs
LIBFT_DIR = $(CUR_DIR)/libft

HEADERS = $(LIBFT_DIR)/includes $(CUR_DIR)/includes

FILES = ls_error \
		ls_fileinfo_cmp \
		ls_getfi \
		ls_input_parser \
		ls_lcol_time \
		ls_lib_upd \
		ls_main \
		ls_mcolput \
		ls_moreput \
		ls_opendir \
		ls_put1col \
		ls_putfiles \
		ls_putlcol \
		ls_sort \
		ls_xxx

O_FILES = $(patsubst %, $(O_DIR)/%.o, $(FILES))
C_FILES = $(patsubst %, $(CUR_DIR)/%.c, $(FILES))

all: $(NAME)

o_dir:
	@if ! [ -d $(O_DIR) ]; then mkdir $(O_DIR); fi;

$(NAME): $(LIBFT) $(O_FILES)
	$(CC) $(FLAGS) $(patsubst %, -I %, $(HEADERS)) $(patsubst lib%.a, -l%, $(LIBFT)) \
	-L$(LIBFT_DIR) $(O_FILES) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) $(LIBFT)

$(O_DIR)/%.o: $(CUR_DIR)/%.c
	@make o_dir
	@$(CC) $(CCFLAGS) -c $< -o $@ $(patsubst %, -I%, $(HEADERS));

clean:
	@rm -rf $(O_DIR)
	@make -C $(LIBFT_DIR) $@

fclean: clean
	@rm -rf $(CUR_DIR)/$(NAME)
	@make -C $(LIBFT_DIR) $@

re: fclean all
