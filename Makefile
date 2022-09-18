SRC_DIR = src
OBJ_DIR = bin/
INC_DIR = include

NAME = BunkerGame.exe

SRCS = $(SRC_DIR)/*.cpp $(SRC_DIR)/core/generic/*.cpp $(SRC_DIR)/game/scenes/*.cpp

CC = g++
CFLAGS = -Wextra -Wpedantic -g -I"$(INC_DIR)"
LFLAGS = -lglfw3 -L$(LLDFLAGS) -lopengl32 -lgdi32 -luser32

LLDFLAGS = -L"lib/GLFW/lib"
LINCFLAGS = -I"lib/GLFW/include"

all: $(NAME)

$(NAME): $(OBJ_DIR)
	$(CC) $(LLDFLAGS) $(LINCFLAGS) $(CFLAGS) $(OBJS) $(SRCS) -o $(OBJ_DIR)$(NAME) $(LFLAGS)


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)$(NAME)

re: clean all

run: all
	./$(OBJ_DIR)$(NAME)

.PHONY: all clean re run