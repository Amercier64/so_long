src_dir := src

src := main.c \
	   game_init.c \
	   map_init.c \
	   map_check.c \
	   lab_check.c \
	   print_error.c \
	   exit_prog.c \
	   free.c \

obj_dir := obj

obj := $(src:%.c=$(obj_dir)/%.o)

lib_dir := libs

lib := $(addprefix $(lib_dir)/, \
	  mlx_linux/libmlx_Linux.a \
	  ft_printf/libftprintf.a)

NAME := so_long

CFLAGS := -Wall -Wextra -Werror -g

INCLUDE := -I/usr/include -Ilibs/ft_printf/src -Ilibs/mlx_linux -Ilibs/ft_printf/libft

LDFLAGS := -L/usr/lib $(dir $(addprefix -L, $(lib)))

LDLIBS := -lXext -lX11 -lm -lz -lmlx_Linux -lftprintf

all: $(NAME)

$(NAME): $(obj) $(lib)
	$(CC) $(CFLAGS) $(LDFLAGS) $(obj) $(LDLIBS) -o $@ 

$(obj_dir)/%.o: $(src_dir)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

$(lib):
	$(MAKE) -C $(@D)

clean:
	$(MAKE) -C $(dir $(word 1, $(lib))) clean
	$(MAKE) -C $(dir $(word 2, $(lib))) fclean
	rm -rf $(obj_dir)


fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
