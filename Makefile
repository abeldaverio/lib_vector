##
## EPITECH PROJECT, 2023
## makefile miniprintf
## File description:
## Makefile for miniprintd
##

SRC	=	$(addprefix src/,\
            $(addprefix utils/,\
                get_vector.c    \
                compare_bytes.c	\
            )   \
			init_vector.c	\
			free_vector.c	\
			push_back_vector.c	\
			resize_vector.c	\
			pop_back_vector.c	\
			vector_size.c	\
			push_front_vector.c	\
			push_index_vector.c	\
			pop_front_vector.c	\
			pop_index_vector.c	\
			concat_vector.c	\
<<<<<<< Updated upstream
=======
			quick_sort_vector.c	\
			index_of_vector.c	\
>>>>>>> Stashed changes
		)

OBJ	=	$(SRC:.c=.o)

SRC_TEST = $(addprefix tests/,\
				simple_tests.c	\
				int_tests.c	\
			)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

NAME	=	libvector.a

CPPFLAGS	=	-iquote./include

CFLAGS	+=	-Wall -Wextra

TEST_NAME = unit_tests

TEST_FLAGS	=	--coverage

TEST_LIB	=	-lcriterion

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

project:	$(NAME)
	cp $(NAME) ../
	cp include/vector.h ../../include/

clean:
	$(RM) $(OBJ)

fclean:	clean tests_clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)
	$(RM) ../include/vector.h

re:	fclean all

$(TEST_NAME):	$(OBJ_TEST)
	$(CC) -o $(TEST_NAME) $(CFLAGS) $(CPPFLAGS)	\
	$(OBJ_TEST) $(SRC)	\
	$(TEST_FLAGS) $(TEST_LIB)

tests_run:	$(TEST_NAME)
	./$(TEST_NAME)

tests_clean:
	$(RM) $(OBJ_TEST)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) coverage*
	$(RM) unit_tests

.PHONY: all clear fclean re tests_run tests_clean project
