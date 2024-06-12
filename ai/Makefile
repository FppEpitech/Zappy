##
## EPITECH PROJECT, 2024
## AI Zappy
## File description:
## AI Makefile
##

NAME		=	zappy_ai

TEST_NAME 	= 	zappy_ai_tests

all: $(NAME)

$(NAME):
	cp src/main.py $(NAME)
	chmod 775 $(NAME)
	cp $(NAME) ../

clean:
	rm -rf __pycache__

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f $(TEST_NAME)
	rm -f ../$(TEST_NAME)

re: fclean all

tests_run:
	cp ../tests/ai/tests/MainTest.py $(TEST_NAME)
	chmod 775 $(TEST_NAME)
	cp $(TEST_NAME) ../
# TODO #11 (https://github.com/FppEpitech/Zappy/issues/11)
