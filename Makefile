# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 21:00:45 by nosilves          #+#    #+#              #
#    Updated: 2023/08/31 22:45:18 by nosilves         ###   ########.fr        #
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

NAME = minitalk
SERVER = server
CLIENT = client
INCLUDE = minitalk.h
INC_DIR := inc/
LIB_DIR	:= $(INC_DIR)printf/
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.
I	= -I./$(LIB_DIR)

SRC_S = server.c

SRC_C = client.c

OBJS_C = $(SRC_C:.c=.o)

OBJS_S = $(SRC_S:.c=.o)

#--------------------------IMPLICIT METHODS--------------------------#

%.o : %.c $(INCLUDE)
	@printf "${YELLOW}\rCompiling (╮°-°)╮┳━┳ ${GREEN} : $<\n"
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@


#-----------------------------FUNCTIONS-------------------------------#

all: makelib $(NAME) 

makelib:
	@$(MAKE) -C $(LIB_DIR)

$(NAME):: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_S) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJS_S) -L $(LIB_DIR) -lftprintf -o $(SERVER)

$(CLIENT): $(OBJS_C) $(INCLUDE)	
	@$(CC) $(CFLAGS) $(OBJS_C) -L $(LIB_DIR) -lftprintf -o $(CLIENT)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@echo "${RED}Cleaning... (ノಠ益ಠ)ノ彡┻━┻${GRAY}"
	$(RM) $(OBJS_C) $(OBJS_S) 

fclean: clean
	@echo "Cleaning all!!!🧼"
	@$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(NAME) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
