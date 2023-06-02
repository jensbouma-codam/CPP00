# Program variables
NAME		= megaphone
FILES		= megaphone.cpp

# Compilation variables
SRC_DIR		= src
BUILD_DIR	= build
TARGET		= bin
CC			= g++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -O2
SRC			= $(addprefix $(SRC_DIR)/, $(FILES))
OBJECTS		= $(SRC:%.cpp=$(BUILD_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	@mkdir -p $(TARGET)
	@$(CC) $(CFLAGS) $(LIBS) $(INC_DIR) -o $(TARGET)/$@ $^

$(BUILD_DIR)/%.o:%.cpp
	@mkdir -p $(dir $@)
	@printf "%-25.25s%s\n" "Build" "$(notdir $<)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re
