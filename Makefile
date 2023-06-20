##
## EPITECH PROJECT, 2022
## minishell1
## File description:
## makefile
##

SRC = ./src/exec.c \
	./src/fonctions.c \
	./src/main.c \
	./src/list.c \
	./src/minishell.c \
	./src/my_cd.c \
	./src/my_setenv.c \
	./src/my_unsetenv.c \
	./src/str_to_array.c \
	./src/shell_fonctions.c \
	./src/my_strcpy.c \
	./src/multicommand.c \
	./src/exec_list.c \
	./src/redirection.c \
	./src/exec_array.c \
	./src/path.c \
	./src/handle_quotes.c \
	./src/output_redirect.c \
	./src/fonctions_bis.c \
	./src/prompt.c \
	./src/separators.c \
	./src/conditions.c \
	./src/alias_command.c \
	./src/alias_command_bis.c \
	./src/history.c \
	./src/local_var.c \
	./src/error_local_var.c \
	./src/set_unset_local.c \
	./src/print_local_var.c \

TARGET = 42sh
OBJ = $(SRC:.c=.o)
all : $(TARGET)

$(TARGET) :
	gcc -g3 -o $(TARGET) $(SRC)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)

re : fclean all
