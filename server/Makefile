##
## EPITECH PROJECT, 2024
## Server Zappy
## File description:
## Makefile for server
##

#Files
MAIN 		=	src/main.c

SRC			=	\

TEST_FILES	=	\

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

clean:
	rm -f $(MAIN_OBJ) $(OBJ)
	@$(call GREEN,"✅ [$@] done !")

fclean: clean tests_clean
	@rm -f $(NAME) $(TEST_NAME)
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