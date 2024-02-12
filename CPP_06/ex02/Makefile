NAME = Identifier
FILES = main Base
OBJS_DIR = .obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
INCLUDES = #-I includes
CC = c++

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY)":::Compiling $(NAME):::"$(NONE)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo $(F_GREEN)":::✅ $(NAME) is ready ✅:::"$(NONE)

$(OBJS_DIR)%.o: %.cpp
	@echo $(CURSIVE)$(GRAY)":::Making object files:::"$(NONE)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(INCLUDES) $(CPPFLAGS) -c $< -o $@
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
F_GREEN='\e[92;5;118m'
GREEN='\033[0;32m'
GRAY='\033[2;37m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
CURSIVE='\033[3m'
