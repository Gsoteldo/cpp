# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 19:38:47 by gsoteldo          #+#    #+#              #
#    Updated: 2025/08/12 19:52:08 by gsoteldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CURRENT_FILE = 0
TOTAL_FILES = $(words $(FILES))
CLEAN = \033[2K\r


NAME = animal
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


FILES = main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp


OBJS = $(FILES:.cpp=.o)

all: show_progress $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(CLEAN) $(GREEN)\n 🚀 Compilation finished! $(NC)👍"

%.o: %.cpp
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	$(eval PERCENT=$(shell echo $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES)))))
	@echo "$(CLEAN) 🚀 Compiling $<... $(PERCENT)%"
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