# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moabid <moabid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 19:00:55 by moabid            #+#    #+#              #
#    Updated: 2022/11/06 19:01:43 by moabid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libft.a
CFLAGS 	= 	-Wall -Wextra -Werror
RM 		= 	rm -f
AR 		= 	ar crs

YELLOW	=	\033[1;33m
NC		=	\033[0m
GREEN	=	\033[0;32m
RED		=	\033[0;31m

FILES 	= 	$(shell find . -type f -name "*.c")

all: $(NAME)

OFILES = ${FILES:.c=.o}

%.o:%.c
	@${CC} ${CFLAGS} -o $@ -c $<

${NAME} : ${OFILES} ${INC}
	@ar -rcs ${NAME} ${OFILES}
	@echo "${YELLOW}libft.a created 👍${NC}"

clean:
	@rm -f ${OFILES} ${OBONUS}

fclean : clean
	@rm -f ${NAME}
	@echo "${YELLOW}libft.a is removed 👎${NC}"

re : fclean all


.PHONY: all clean fclean re bonus norm

