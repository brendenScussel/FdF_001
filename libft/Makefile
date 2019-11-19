NAME		= libft.a
FLAGS		= -c -Wall -Werror -Wextra
HEADER		= libft.h
GNL-HEAD	= get_next_line.h
SRCFILES	= ft_sqrt.c \
			  err_prog.c \
			  ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memccpy.c \
			  ft_memmove.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strlen.c \
			  ft_strdup.c \
			  ft_strcpy.c \
			  ft_strncpy.c \
			  ft_strcat.c \
			  ft_strncat.c \
			  ft_strlcat.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strstr.c \
			  ft_strnstr.c \
			  ft_strcmp.c \
			  ft_strncmp.c \
			  ft_atoi.c \
			  ft_atoi_base.c \
			  ft_memalloc.c \
			  ft_memdel.c \
			  ft_strnew.c \
			  ft_strdel.c \
			  ft_strclr.c \
			  ft_striter.c \
			  ft_striteri.c \
			  ft_strmap.c \
			  ft_strmapi.c \
			  ft_strequ.c \
			  ft_strnequ.c \
			  ft_strsub.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_strsplit.c \
			  ft_putchar.c \
			  ft_putstr.c \
			  ft_putendl.c \
			  ft_putnbr.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_swap.c \
			  bs_isspace.c \
			  get_next_line.c \

O_FILES 	= $(SRCFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FILES)
			ar rc $(NAME) $(O_FILES)
			ranlib $(NAME)

$(O_FILES): $(SRCFILES)
			gcc $(FLAGS) -I=$(HEADER) -I=$(GNL-HEAD) $(SRCFILES)

clean:
			rm -f $(O_FILES)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
