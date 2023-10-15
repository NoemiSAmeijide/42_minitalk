# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefie                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 16:07:12 by nosilves          #+#    #+#              #
#    Updated: 2023/06/15 21:12:01 by nosilves         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------COLORS-------------------------------#
BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

#-------------------------------VARIABLES-----------------------------#

NAME = libftprintf.a
INCLUDE = includes/ft_printf.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
 
SRC = ft_printf.c ft_printf_c.c ft_printf_hexa.c ft_printf_nbr.c \
	  ft_printf_pointer.c ft_printf_string.c ft_printf_unsigned.c


OBJ = $(SRC:.c=.o)

#--------------------------IMPLICIT METHODS--------------------------#

%.o : %.c $(INCLUDE)
	@printf "${YELLOW}\rCompiling (╮°-°)╮┳━┳ ${GREEN} : $<\n"
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

#-----------------------------FUNCTIONS-------------------------------#

all: $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	ar rcs $(NAME) $(OBJ)

clean:
	@echo "${RED}Cleaning... (ノಠ益ಠ)ノ彡┻━┻${GRAY}"
	$(RM) $(OBJ)

fclean: clean
	@echo "Cleaning all!!!🧼"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
