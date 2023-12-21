SRCS_DIR = srcs
SRCS_DIR_BONUS = srcs_bonus

SRCS		=	$(SRCS_DIR)/main.c \
				$(SRCS_DIR)/start.c \
				$(SRCS_DIR)/free.c \
				$(SRCS_DIR)/execute.c \
				$(SRCS_DIR)/check.c 

SRCS_BONUS  = 	$(SRCS_DIR_BONUS)/main.c \
				$(SRCS_DIR_BONUS)/start.c \
				$(SRCS_DIR_BONUS)/free.c \
				$(SRCS_DIR_BONUS)/execute.c \
				$(SRCS_DIR_BONUS)/check.c 

OBJS		=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_BONUS 	=	$(subst $(SRCS_DIR_BONUS), $(OBJS_DIR_BONUS), $(SRCS_BONUS:.c=.o))

OBJS_DIR	=	objs
OBJS_DIR_BONUS = objs_bonus

NAME		=	pipex
NAME_BONUS	=	pipex_bonus

CC			=	cc

LIBFT		=	libft/libft.a

CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address

RM			=	rm -rf

INC			=	-Iincludes -I/usr/include -Ilibft/includes

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"



all:		$(NAME)
bonus:		$(NAME_BONUS)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS)
			@make -C libft
			$(CC) $(SRCS) $(CFLAGS) $(INC) -o $(NAME) -Llibft -lft

$(OBJS_DIR_BONUS)/%.o :	$(SRCS_DIR_BONUS)/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME_BONUS):	$(OBJS_BONUS)
			@make -C libft
			$(CC) $(SRCS_BONUS) $(CFLAGS) $(INC) -o $(NAME_BONUS) -Llibft -lft


clean:
			@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
			$(RM) $(OBJS)
			$(RM) $(OBJS_BONUS)

fclean:		clean
			@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
			$(RM) $(NAME)
			$(RM) $(NAME_BONUS)
			$(RM) *.out
			$(RM) $(OBJS_DIR)
			$(RM) $(OBJS_DIR_BONUS)
			$(RM) out
			@make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re