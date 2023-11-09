NAME = zombie
FILES = main
OBJS_DIR = .obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
CFLAGES = -Wall -Werror -Wextra -std=c++98
CC = c++

# .cpp.o:
	# @$(CC) $(CFLAGES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY)":::Compiling $(NAME) :::"$(NONE)
	@$(CC) $(CFLAGES) $(OBJS) -o $(NAME)
	@echo $(GREEN)":::✅ $(NAME) is ready ✅:::"$(NONE)

$(OBJS_DIR)%.o: $(FILES)%.cpp
	@echo $(CURSIVE)$(GRAY)":::Making object files:::"$(NONE)
	@mkdir -p $(OBJS_DIR)
	@CC $(CFLAGES) -c $< -o $@
clean:
	@echo $(CURSIVE)$(GRAY)":::Deleting executable:::"$(NONE)
	@rm -rf $(OBJS_DIR)
	@echo $(RED)":::Deleted:::"$(NONE)

fclean: clean
	@echo $(CURSIVE)$(GRAY)":::Deleting executable:::"$(NONE)
	@rm -rf $(NAME)
	@echo $(RED)":::Deleted:::"$(NONE)

re: fclean all

.PHONY:all clean fclean re 

NONE='\033[0m'
GREEN='\e[92;5;118m'
GRAY='\033[2;37m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
CURSIVE='\033[3m'
