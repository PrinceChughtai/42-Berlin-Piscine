NAME = rush-02

SRCS = src/main.c src/ft_functions.c src/convert_dictionary.c src/check.c src/get_numbers.c src/dict_check.c src/string_management.c

OBJS = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra

all:	${NAME}

${NAME}: ${OBJS}
	cc -o ${NAME} ${SRCS} ${FLAGS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean
