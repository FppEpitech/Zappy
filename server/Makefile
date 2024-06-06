##
## EPITECH PROJECT, 2024
## Server Zappy
## File description:
## Makefile for server
##

#Files
MAIN 		=	src/main.c

SRC			=	src/list/list.c \
				src/list/remove.c \
				src/list/add.c \
				\
				src/app/app.c \
				\
				src/ai/ai.c \
				src/ai/team.c \
				src/ai/cmd/handler.c \
				src/ai/cmd/move.c \
				\
				src/gui/gui.c \
				\
				src/server/run.c \
				src/server/quit.c \
				src/server/client.c \
				src/server/server.c \
				src/server/read/read_data.c \
				src/server/read/connection.c \
				src/server/write/write_data.c \
				\
				src/game/game.c \
				\
				src/parsing/help.c					\
				src/parsing/parse_positive_int.c	\
				src/parsing/parse_client.c			\
				src/parsing/parse_port.c			\
				src/parsing/parse_height.c			\
				src/parsing/parse_width.c			\
				src/parsing/arguments.c				\
				src/parsing/parse_names.c			\
				src/parsing/parse_frequency.c		\
				\
				src/map/map.c						\

TEST_FILES	=	list/list_test.c \
				communication/communication_test.c \
				parsing/help_test.c					\
				parsing/parse_positive_int_tests.c	\
				parsing/parse_client_tests.c		\
				parsing/parse_width_tests.c			\
				parsing/parse_height_tests.c		\
				parsing/parse_port_tests.c			\
				parsing/parse_frequency_tests.c		\
				parsing/parse_arguments_tests.c		\
				parsing/parse_names_tests.c			\
				map/map_test.c \

OBJ			=	$(SRC:.c=.o)
MAIN_OBJ	=	$(MAIN:.c=.o)

#Name
NAME		= 	zappy_server

# Flags
INCLUDE		= -I./include
CXXFLAGS 	= -Wall -Wextra -Werror

# Colors
YELLOW 		= /bin/echo -e "\x1b[33m $1\x1b[0m"
GREEN 		= /bin/echo -e "\x1b[32m $1\x1b[0m"

# Tests
TEST_NAME 	= unit_tests
TEST_DIR 	= tests/
TEST 		= $(addprefix $(TEST_DIR), $(TEST_FILES))
TEST_OBJ 	= $(TEST:.c=.o)
TEST_GCNO 	= $(SRC:.c=.gcno)
TEST_GCDA 	= $(SRC:.c=.gcda)
TEST_FLAGS 	= -Wall -Wextra -Werror --coverage -lcriterion

CC = gcc

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	@$(CC) $(MAIN_OBJ) $(OBJ) -o $(NAME) $(CXXFLAGS) $(INCLUDE) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")
	cp $(NAME) ../

clean:
	rm -f $(MAIN_OBJ) $(OBJ)
	@$(call GREEN,"✅ [$@] done !")

fclean: clean tests_clean
	@rm -f $(NAME) $(TEST_NAME)
	@rm -f ../$(NAME)
	@$(call GREEN,"✅ [$@] done !")

tests_clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TEST_GCNO) $(TEST_GCDA)
	@$(call GREEN,"✅ [$@] done !")

re:	fclean all

%.o: %.c
	@$(CC) -c $< -o $@ $(CXXFLAGS) $(INCLUDE) && \
	$(call YELLOW,"🆗 $<") || \
	$(call YELLOW,"❌ $<")

test_obj: $(TEST_OBJ)

obj: $(OBJ)

tests_run: fclean
	$(MAKE) obj CXXFLAGS+=--coverage
	$(MAKE) test_obj
	@$(CC) -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(TEST_FLAGS) $(INCLUDE)
	./$(TEST_NAME)
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
