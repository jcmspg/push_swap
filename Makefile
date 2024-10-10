NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
POSTCC = -I $(INC_DIR) -I $(SRC_DIR) \
         -L $(INC_DIR)/lib_ft -lft \


SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc

# List of all .c files in the src directory
SRC_FILES = $(shell find $(SRC_DIR) -name "*.c")

# List of all .o files in the obj directory
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Pattern rule to compile each .c file into an .o file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(SRC_DIR) -c $< -o $@

# Rule to create the final executable
$(NAME): $(OBJ_FILES)
	@echo "Building $(NAME)..."
	@make -C $(INC_DIR)/lib_ft > /dev/null 2>&1 || { echo "Failed to build lib_ft"; exit 1; }
	@$(CC) $(CFLAGS) $(OBJ_FILES) \
		$(INC_DIR)/lib_ft/libft.a \
		$(POSTCC) -o $(NAME) || { echo "Linking failed."; exit 1; }
	@echo "Compilation complete. Executable: $(NAME)"

all:  $(NAME)

bonus: all

clean:
	@rm -rf $(OBJ_DIR) sources.mk
	@make clean -C $(INC_DIR)/lib_ft > /dev/null 2>&1
	@echo "Clean complete."

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(INC_DIR)/lib_ft > /dev/null 2>&1 || make clean -C $(INC_DIR)/lib_ft > /dev/null 2>&1
	@echo "Full clean complete."

re: fclean all

.PHONY: all clean fclean re