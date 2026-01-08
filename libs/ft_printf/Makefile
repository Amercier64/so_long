SRC_DIR := src

src := $(addprefix $(SRC_DIR)/, ft_printf.c ft_print_num.c ft_print_s.c)

OBJ_DIR := obj

obj := $(src:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) 

LIB_DIR := libft

lib := $(LIB_DIR)/libft.a

NAME := libftprintf.a

CFLAGS := -Wall -Wextra -Werror -g

INCLUDE := -Ilibft

ARFLAGS := -rcs

all: $(NAME)

$(NAME): $(lib) $(obj)
	$(AR) $(ARFLAGS) $@ $? 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

$(lib):
	$(MAKE) -C $(LIB_DIR)
	cp $(lib) ./$(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
