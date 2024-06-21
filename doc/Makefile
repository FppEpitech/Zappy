##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Makefile for zappy doc
##

NAME	= doxygen

all: $(NAME)

$(NAME):
	@make ai-doc
	@make gui-doc
	@make server-doc

ai-doc:
	@doxygen doxygen/Doxyfile-ai && make -C doxygen/latex
	@mv doxygen/latex/refman.pdf ./ai-doc/doxygen-auto-doc.pdf
	mkdir -p ./ai-doc/website-doc
	@cp doxygen/html/* ./ai-doc/website-doc -r

gui-doc:
	@doxygen doxygen/Doxyfile-gui && make -C doxygen/latex
	@mv doxygen/latex/refman.pdf ./gui-doc/doxygen-auto-doc.pdf
	mkdir -p ./gui-doc/website-doc
	@cp doxygen/html/* ./gui-doc/website-doc -r

server-doc:
	@doxygen doxygen/Doxyfile-server && make -C doxygen/latex
	@mv doxygen/latex/refman.pdf ./server-doc/doxygen-auto-doc.pdf
	mkdir -p ./server-doc/website-doc
	@cp doxygen/html/* ./server-doc/website-doc -r

install-deps:
	sudo dnf install doxygen-latex

.PHONY: ai-doc gui-doc server-doc doxygen
