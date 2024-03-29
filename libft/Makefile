# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldedier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 18:20:16 by ldedier           #+#    #+#              #
#    Updated: 2018/04/24 16:48:46 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = libft.h ft_printf.h

ifeq ($(DEBUG), 1)
	CFLAGS += -DDEBUG -fsanitize=address
endif

SRCDIR   = srcs
OBJDIR   = objs
BINDIR   = .
INCLUDESDIR = includes

OK_COLOR = \x1b[32;01m
EOC = \033[0m

SRCS_NO_PREFIX = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
	   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
	   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
	   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	   ft_isprint.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c\
	   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
	   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
	   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
	   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
	   ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_isseparator.c ft_lstpushback.c\
	   ft_lstpop.c ft_lstlength.c ft_sort_tab.c ft_newtree.c ft_infix.c\
	   ft_prefix.c ft_postfix.c get_next_line.c ft_free_split.c\
	   ft_abs.c ft_max.c ft_min.c ft_lstnew_ptr.c ft_putchar_buff.c ft_printf.c\
	   ft_return.c ft_init.c ft_putoctal.c ft_putnbr_unsigned.c\
	   ft_putnstr.c ft_putnbr_max.c ft_puthex_max.c ft_putoctal_max.c\
	   ft_putbin.c ft_putdbl.c ft_get_buffer.c ft_putstr_non_printable.c\
	   ft_tools.c ft_prefix_pf.c ft_padding.c ft_get_casted_values.c ft_precision.c\
	   ft_mod_len.c ft_bonus_flags.c ft_flags_integer.c ft_put_wchar.c\
	   ft_flag_c_maj.c ft_put_wchar_len_3_4.c ft_flags_x_p.c\
	   ft_flags_s.c ft_flags_others.c ft_flags_o.c ft_flags_f.c\
	   ft_display_len_integer.c ft_display_len_string.c\
	   ft_display_len_wchar.c ft_display_len_p.c\
	   ft_get_casted_values_func.c ft_get_casted_values_func_2.c\
	   ft_get_casted_values_func_3.c ft_may_error.c ft_splitlen.c\
	   ft_fmax.c ft_fmin.c ft_clamp.c ft_fclamp.c ft_atof.c

SOURCES = $(addprefix $(SRCDIR)/, $(SRCS_NO_PREFIX))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))

INC_PATH = -I $(INCLUDESDIR)
INCLUDES_NO_PREFIX = libft.h ft_printf.h
INCLUDES = $(addprefix $(INCLUDESDIR)/, $(INCLUDES_NO_PREFIX))

CFLAGS += $(INC_PATH)

all: $(BINDIR)/$(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS)

$(BINDIR)/$(NAME): $(OBJECTS)
	@ar rc $@ $^
	@ranlib $(NAME)
	@echo "$(OK_COLOR)$(NAME) linked with success !$(EOC)"
clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(BINDIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
