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
				src/ai/stuck.c \
				src/ai/ai_destroy.c \
				src/ai/die.c \
				\
				src/ai/cmd/handler.c \
				src/ai/cmd/move.c \
				src/ai/cmd/look/look_handler.c \
				src/ai/cmd/look/look_north.c \
				src/ai/cmd/look/look_east.c \
				src/ai/cmd/look/look_south.c \
				src/ai/cmd/look/look_west.c \
				src/ai/cmd/other/other_handler.c \
				src/ai/cmd/other/take_cmd.c \
				src/ai/cmd/other/set_cmd.c \
				src/ai/cmd/other/fork_cmd.c \
				src/ai/cmd/other/dead_cmd.c \
				src/ai/cmd/other/connect_nbr_cmd.c \
				src/ai/cmd/eject/eject_handler.c \
				src/ai/cmd/eject/eject_player.c \
				src/ai/cmd/eject/eject_egg.c \
				src/ai/cmd/broadcast/broadcast_cmd.c \
				src/ai/cmd/broadcast/calcul_k.c \
				src/ai/cmd/incantation/incantation_handler.c \
				src/ai/cmd/incantation/check_incantation.c \
				src/ai/cmd/object_info.c \
				src/ai/cmd/incantation/update_status.c \
				src/ai/cmd/incantation/level_up.c \
				\
				src/gui/gui.c \
				src/gui/handler.c \
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
				src/game/win.c \
				\
				src/utils.c							\
				\
				src/parsing/help.c					\
				src/parsing/parse_client.c			\
				src/parsing/parse_port.c			\
				src/parsing/parse_height.c			\
				src/parsing/parse_width.c			\
				src/parsing/arguments.c				\
				src/parsing/parse_names.c			\
				src/parsing/parse_frequency.c		\
				src/parsing/destroy_parsing.c 		\
				\
				src/map/map.c						\
				\
				src/gui/communication/loop.c		\
				src/gui/communication/msz.c			\
				src/gui/communication/tna.c			\
				src/gui/communication/sgt.c			\
				src/gui/communication/sst.c			\
				src/gui/communication/bct.c			\
				src/gui/communication/mct.c			\
				src/gui/communication/ppo.c			\
				src/gui/communication/plv.c			\
				src/gui/communication/pin.c			\
				src/gui/communication/pnw.c			\
				src/gui/communication/pex.c			\
				src/gui/communication/pbc.c			\
				src/gui/communication/pfk.c			\
				src/gui/communication/pdr.c			\
				src/gui/communication/pgt.c			\
				src/gui/communication/pdi.c			\
				src/gui/communication/seg.c			\
				src/gui/communication/smg.c			\
				src/gui/communication/suc.c			\
				src/gui/communication/sbp.c			\
				src/gui/communication/pic.c			\
				src/gui/communication/pie.c			\
				src/gui/communication/enw.c			\
				src/gui/communication/edi.c			\
				src/gui/communication/ebo.c			\

TEST_FILES	=	list/list_test.c 					\
				communication/communication_test.c 	\
				parsing/help_test.c					\
				parsing/parse_positive_int_tests.c	\
				parsing/parse_client_tests.c		\
				parsing/parse_width_tests.c			\
				parsing/parse_height_tests.c		\
				parsing/parse_port_tests.c			\
				parsing/parse_frequency_tests.c		\
				parsing/parse_arguments_tests.c		\
				parsing/parse_names_tests.c			\
				map/map_test.c 						\
				ai/move_command.c 					\
				gui/commands/tests_loop.c			\
				gui/commands/tests_bct.c			\
				gui/commands/tests_ebo.c			\
				gui/commands/tests_edi.c			\
				gui/commands/tests_enw.c			\
				gui/commands/tests_mct.c			\
				gui/commands/tests_msz.c			\
				gui/commands/tests_pbc.c			\
				gui/commands/tests_pdi.c			\
				gui/commands/tests_pdr.c			\
				gui/commands/tests_pex.c			\
				gui/commands/tests_pfk.c			\
				gui/commands/tests_pgt.c			\
				gui/commands/tests_pic.c			\
				gui/commands/tests_pie.c			\
				gui/commands/tests_pin.c			\
				gui/commands/tests_plv.c			\
				gui/commands/tests_pnw.c			\
				gui/commands/tests_ppo.c			\
				gui/commands/tests_sbp.c			\
				gui/commands/tests_seg.c			\
				gui/commands/tests_sgt.c			\
				gui/commands/tests_smg.c			\
				gui/commands/tests_sst.c			\
				gui/commands/tests_suc.c			\
				gui/commands/tests_tna.c			\

OBJ			=	$(SRC:.c=.o)
MAIN_OBJ	=	$(MAIN:.c=.o)

#Name
NAME		= 	zappy_server

# Flags
INCLUDE		= -I./include
CXXFLAGS 	= -Wall -Wextra -Werror -lm

# Colors
YELLOW 		= /bin/echo -e "\x1b[33m $1\x1b[0m"
GREEN 		= /bin/echo -e "\x1b[32m $1\x1b[0m"

# Tests
TEST_NAME 	= unit_tests
TEST_DIR 	= ../tests/server/tests/
TEST 		= $(addprefix $(TEST_DIR), $(TEST_FILES))
TEST_OBJ 	= $(TEST:.c=.o)
TEST_GCNO 	= $(SRC:.c=.gcno)
TEST_GCDA 	= $(SRC:.c=.gcda)
TEST_FLAGS 	= -Wall -Wextra -Werror --coverage -lcriterion -lm

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
