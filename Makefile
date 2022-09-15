SRC_DIR = src
OBJ_DIR = bin/
INC_DIR = include

NAME = game.exe

SRCS = $(SRC_DIR)/*.cpp
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -g -I$(INC_DIR)
LFLAGS = -lglfw3

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: clean all

run:
	./$(NAME)

.PHONY: all clean re run