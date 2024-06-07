##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Makefile for zappy
##

NAME	= zappy

all: $(NAME)

$(NAME):
	@make -C server
	@make -C ai
	@make -C gui

clean:
	@make clean -C server
	@make clean -C ai
	@make clean -C gui

fclean:
	@make fclean -C server
	@make fclean -C ai
	@make fclean -C gui

tests_run:
	@make tests_run -C server
	@make tests_run -C ai
	@make tests_run -C gui

zappy_gui:
	@make -C gui

zappy_server:
	@make -C server

zappy_ai:
	@make -C ai

zappy_gui_clean:
	@make clean -C gui

zappy_server_clean:
	@make clean -C server

zappy_ai_clean:
	@make clean -C ai

zappy_gui_fclean:
	@make fclean -C gui

zappy_server_fclean:
	@make fclean -C server

zappy_ai_fclean:
	@make fclean -C ai

zappy_gui_re:
	@make re -C gui

zappy_server_re:
	@make re -C server

zappy_ai_re:
	@make re -C ai

re: fclean all

zappy_gui_tests_run:
	@make tests_run -C gui

zappy_server_tests_run:
	@make tests_run -C server

zappy_ai_tests_run:
	@make tests_run -C ai

doc:
	@doxygen doc/doxygen/Doxyfile && make -C doc/doxygen/latex
	@mv doc/doxygen/latex/refman.pdf ./doc

.PHONY: doc
