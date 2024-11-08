# Source, object, and header files
SRC     = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ     = $(SRC:.c=.o)
HEADER  = get_next_line_bonus.h

# Output executable name
NAME    = gnl.out
CC      = gcc
FLAGS   = -Wall -Wextra -Werror
RM      = rm -f

# Default rule to build the executable
all: $(NAME)

# Link object files into the gnl.out executable
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	chmod +x $(NAME)

# Rule to compile .c files into .o files
%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJ)

# Full cleanup, including the executable
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re
