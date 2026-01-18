# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joeyscags <joeyscags@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/18 00:00:00 by joeyscags         #+#    #+#              #
#    Updated: 2026/01/18 00:00:00 by joeyscags        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bureaucrat

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++17

SRCS		= main.cpp \
			  Bureaucrat.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
