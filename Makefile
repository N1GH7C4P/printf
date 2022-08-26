
#Variables

NAME		= libftprintf.a
PRINTFLIB	= ftprintf
INCLUDE		= -I include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= src/
TEST_DIR	= test/
TEST_EXE	= run_test
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -O3 -fPIE
RM			= rm -f
AR			= ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	dstring formatting_a formatting_b ft_ftoa ft_itoabase handlers modifications printf ft_ftoa_helpers modify_integers
TEST_FILES	=	*

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
TEST 		= 	$(addprefix $(TEST_DIR), $(addsuffix .test.c, $(TEST_FILES)))

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

clean:
			@$(RM) -rf $(OBJ)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

test:		re
			${CC} ${TEST} -L . -l ${PRINTFLIB} -o ${TEST_EXE}
			./${TEST_EXE}
			
.PHONY:		all clean fclean re norm