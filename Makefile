##
## Makefile for Makefile in /home/paskal/rendu/System_Unix/PSU_2016_malloc/
##
## Made by Paskal Arzel
## Login   <paskal.arzel@epitech.eu>
##
## Started on  Tue Jan 24 14:13:29 2017 Paskal Arzel
## Last update Thu Feb 23 15:41:29 2017 Paskal Arzel
##

ECHO	= /bin/echo -e
DEFAULT	= "\033[00m"
GREEN	= "\033[0;32m"
TEAL	= "\033[1;36m"
RED	= "\033[0;31m"
BLUE	= "\033[0;34m"

DIRINC	= include

SRC_NM	=  $(DIR_NM)nm.c \
					$(DIR_NM)sym.c \
					$(DIR_NM)sort.c \
					$(DIR_NM)arch.c \
					$(DIR_IN)init.c \
					$(DIR_IN)init_longname.c \
					$(DIR_IN)init_arch.c \
					$(DIR_IN)set_base.c \
					$(DIR_PR)print_arch.c \
					$(DIR_PR)print.c

SRC_OBJ	=	 $(DIR_OBJ)objdump.c \
					$(DIR_OIN)init.c \
					$(DIR_OPR)print.c \
					$(DIR_OPR)calc_print.c \
					$(DIR_OPR)print_line.c

DIR = src/

DIR_NM = src/nm/

DIR_OIN = $(DIR_OBJ)init/

DIR_OPR = $(DIR_OBJ)print/

DIR_PR = $(DIR_NM)print/

DIR_IN = $(DIR_NM)init/

DIR_OBJ = src/objdump/

CC	= gcc

RM	= rm -f

FLAG	=	-Wall \
		-Wextra \
		-Werror \
		-fpic \
		-I$(DIRINC) \
		-g

NAME_NM	= my_nm

NAME_OBJ = my_objdump

OBJS_OBJ	=	$(SRC_OBJ:.c=.o)

OBJS_NM	=	$(SRC_NM:.c=.o)

all:   nm objdump

objdump:	$(OBJS_OBJ)
	gcc -o $(NAME_OBJ) $(SRC_OBJ) $(FLAG)

nm:	$(OBJS_NM)
	gcc -o $(NAME_NM) $(SRC_NM) $(FLAG)

clean:
		$(RM) $(OBJS_OBJ)
		$(RM) $(OBJS_NM)

fclean:		clean
		$(RM) $(NAME_NM)
		$(RM) $(NAME_OBJ)

re: fclean all

renm: fclean nm

reobj: fclean objdump

.c.o:
	@gcc -shared $(LIB) $(FLAG) -c $< -o $@ && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
	$(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

.PHONY: all clean fclean re $(NAME) message .c.o
