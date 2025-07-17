# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 19:38:47 by gsoteldo          #+#    #+#              #
#    Updated: 2025/07/17 18:57:31 by gsoteldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CURRENT_FILE = 0
TOTAL_FILES = $(words $(FILES))
CLEAN = \033[2K\r


NAME = Weapon
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


FILES = main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp


OBJS = $(FILES:.cpp=.o)

all: show_progress $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(CLEAN) $(GREEN)\n 🚀 Compilation finished! $(NC)👍"

%.o: %.cpp
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "$(CLEAN_SHELL) 🚀 Compiling $<... $(shell echo $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES))))%%"
	@$(CC) $(CFLAGS) -c $< -o $@

show_progress:
	@if [ -f $(NAME) ]; then \
		echo "$(GREEN)The compiled code is already updated.$(NC)"; \
	fi

clean:
	@rm -f $(OBJS)
	@echo "Cleaning finished! 🧹"

fclean: clean
	@rm -f $(NAME)
	@echo " Deleting finished! 🗑"

git:
	@git add .
	@git commit
	@git push

re: fclean all

.PHONY: all clean fclean re upload norm