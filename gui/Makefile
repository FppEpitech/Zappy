##
## EPITECH PROJECT, 2024
## Gui Zappy
## File description:
## Core Makefile
##

#Files
MAIN 		=	src/main.cpp

SRC			=	src/Error/Error.cpp \
				\
				src/Network/Network.cpp \
				\
				src/Engine/Engine.cpp \
				\
				src/Parsing/ServerParser.cpp \
				src/Parsing/ParseCommandLine.cpp \
				\
				src/GameDatas/Inventory.cpp \
				src/GameDatas/Player.cpp \
				src/GameDatas/Tile.cpp \
				src/GameDatas/Team.cpp \
				src/GameDatas/GameData.cpp \
				src/GameDatas/Egg.cpp \
				\
				src/Render/Render.cpp \
				src/Render/UserCamera.cpp \
				src/Render/Decoration.cpp \
				\
				src/Event/Event.cpp \
				\
				src/GUIUpdater/GUIUpdater.cpp \

TEST_FILES	=	Network/TestNetwork.cpp \
				Parsing/TestParser.cpp \
				Parsing/TestParseCommandLine.cpp \
				GameDatas/TestInventory.cpp \
				GameDatas/TestPlayer.cpp \
				GameDatas/TestTile.cpp \
				GameDatas/TestGameData.cpp \
				GameDatas/TestEgg.cpp \
				GameDatas/TestTeam.cpp \
				Render/TestCamera.cpp \
				GUIUpdater/TestGUIUpdater.cpp \
				Event/TestEvent.cpp \

OBJ			=	$(SRC:.cpp=.o)
MAIN_OBJ	=	$(MAIN:.cpp=.o)

#Name
NAME		= 	zappy_gui

# Flags
INCLUDE		= 	-I./include -I../tests/gui/tests
CXXFLAGS 	= 	-std=c++20 -Wall -Wextra -Werror -lraylib

# Colors
YELLOW 		= 	/bin/echo -e "\x1b[33m $1\x1b[0m"
GREEN 		= 	/bin/echo -e "\x1b[32m $1\x1b[0m"

# Tests
TEST_NAME 	= 	unit_tests
TEST_DIR 	= 	../tests/gui/tests/
TEST 		= 	$(addprefix $(TEST_DIR), $(TEST_FILES))
TEST_OBJ 	= 	$(TEST:.cpp=.o)
TEST_GCNO 	= 	$(SRC:.cpp=.gcno)
TEST_GCDA 	= 	$(SRC:.cpp=.gcda)
TEST_FLAGS 	= 	-Wall -Wextra -Werror --coverage -lcriterion -lraylib

CC	=	g++

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	@$(CC) $(MAIN_OBJ) $(OBJ) -o $(NAME) $(CXXFLAGS) $(INCLUDE) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")
	mv $(NAME) ../

clean:
	rm -f $(MAIN_OBJ) $(OBJ)
	@$(call GREEN,"✅ [$@] done !")

fclean: clean tests_clean
	@rm -f $(TEST_NAME)
	@rm -f ../$(NAME)
	@$(call GREEN,"✅ [$@] done !")

tests_clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TEST_GCNO) $(TEST_GCDA)
	@$(call GREEN,"✅ [$@] done !")

re:	fclean all

%.o: %.cpp
	@$(CC) -c $< -o $@ $(CXXFLAGS) $(INCLUDE) && \
	$(call YELLOW,"🆗 $<") || \
	$(call YELLOW,"❌ $<")

test_obj: $(TEST_OBJ)

obj: $(OBJ)

tests_run: fclean
	$(MAKE) obj CXXFLAGS+=--coverage
	$(MAKE) test_obj CXXFLAGS="-Wall -Wextra -Werror"
	@$(CC) -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(TEST_FLAGS) $(INCLUDE)
	./$(TEST_NAME)
	gcovr --exclude tests/

install-deps-ci:
	sudo dnf install alsa-lib-devel mesa-libGL-devel \
		libX11-devel libXrandr-devel libXi-devel \
		libXcursor-devel libXinerama-devel libatomic -y
	sudo dnf install raylib-devel -y

install-deps:
	sudo dnf update -y
	sudo dnf install alsa-lib-devel mesa-libGL-devel \
		libX11-devel libXrandr-devel libXi-devel \
		libXcursor-devel libXinerama-devel libatomic -y
	sudo dnf install raylib-devel -y
