NAME = ft_traceroute

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -lm

SRC_DIR = src
OBJ_DIR = obj
BONUS_OBJ_DIR = obj_bonus
INC_DIR = include

SRCS = $(SRC_DIR)/main.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_SRCS = $(SRCS) $(SRC_DIR)/bonus.c
BONUS_OBJS = $(BONUS_SRCS:$(SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/ft_traceroute.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re