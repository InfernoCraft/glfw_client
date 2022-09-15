SRC_DIR = src/
OBJ_DIR = bin/
INC_DIR = include/

NAME = game.exe

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -g -I$(INC_DIR)
LFLAGS = -lglfw3

LLDFLAGS = -L"GLFW/lib"
LINCFLAGS = -I"GLFW/include"

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(LLDFLAGS) $(LINCFLAGS) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(OBJ_DIR)$(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -f $(OBJ_DIR)$(NAME)

re: clean all

run:
	./$(NAME)

.PHONY: all clean re run