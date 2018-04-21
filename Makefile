# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 18:20:16 by ldedier           #+#    #+#              #
#    Updated: 2018/04/21 16:28:59 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= scop

CC      = gcc -g

PWD = \"$(shell pwd)\"

DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CFLAGS += -DDEBUG -fsanitize=address
endif

SRCDIR   = srcs
OBJDIR   = objs
BINDIR   = .
INCLUDESDIR = includes

#MLXDIR = minilibx_macos

LIBFTDIR = libft
LIBFT_INCLUDEDIR = includes

LIBMATDIR = libmat
LIBMAT_INCLUDEDIR = includes

OK_COLOR = \x1b[32;01m
EOC = \033[0m

SRCS_NO_PREFIX = main.c ft_events.c ft_init.c ft_quit.c shader.c

INCLUDES_NO_PREFIX = scop.h

SOURCES = $(addprefix $(SRCDIR)/, $(SRCS_NO_PREFIX))

OBJECTS = $(addprefix $(OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))

INCLUDES = $(addprefix $(INCLUDESDIR)/, $(INCLUDES_NO_PREFIX))
INC = -I $(INCLUDESDIR) -I $(LIBFTDIR)/$(LIBFT_INCLUDEDIR) -I $(LIBMATDIR)/$(LIBMAT_INCLUDEDIR) 

CFLAGS = -DPATH=$(PWD) -Wall -Wextra -Werror $(INC)

SDL2 = ./frameworks/SDL2.framework/Versions/A/SDL2
SDL2_image = ./frameworks/SDL2_image.framework/Versions/A/SDL2_image
SDL2_mixer = ./frameworks/SDL2_mixer.framework/Versions/A/SDL2_mixer
SDL2_ttf = ./frameworks/SDL2_ttf.framework/Versions/A/SDL2_ttf

opti:
	@make all -j

all: $(BINDIR)/$(NAME)

debug:
	@make all DEBUG=0

#$(BINDIR)/$(NAME): $(OBJECTS)
#	@make -C $(LIBFTDIR)
#	@make -C $(MLXDIR)
#	@$(CC) -o $@ $^ -L $(LIBFTDIR) -lft -L $(MLXDIR) -lmlx -I $(MLXDIR) -framework opengl
#	@echo "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(BINDIR)/$(NAME): $(OBJECTS)
	@make -C $(LIBFTDIR)
	@make -C $(LIBMATDIR)
	@$(CC) -o $@ $^ -F ./frameworks -framework SDL2\
		-framework SDL2_image -framework SDL2_mixer -framework SDL2_ttf -framework OpenGL -framework Appkit -L $(LIBFTDIR) -lft -L $(LIBMATDIR) -lmat -fsanitize=address
	@echo "$(OK_COLOR)$(NAME) linked with success !$(EOC)"
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 $(SDL2) $(NAME)
	@install_name_tool -change @rpath/SDL2_image.framework/Versions/A/SDL2_image $(SDL2_image) $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer $(SDL2_mixer) $(NAME)
	@install_name_tool -change @rpath/SDL2_ttf.framework/Versions/A/SDL2_ttf $(SDL2_ttf) $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS) -F ./frameworks

clean:
	@make clean -C $(LIBFTDIR)
	@make clean -C $(LIBMATDIR)
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@make fclean -C $(LIBMATDIR)
	@rm -f $(BINDIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
