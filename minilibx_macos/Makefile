#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2
GREEN_OK = "\033[0;32mDONE !\033[00m"

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -rcs $(NOM) $(OBJ)
	@echo minilibx ${GREEN_OK}	

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

%.o : %.m
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ) *~
	@rm -f mlx_app
	@echo clean minilibx ${GREEN_OK}

fclean: clean
	@rm -rf $(NOM) a.out a.out.dSYM
	@echo fclean minilibx ${GREEN_OK}

re: clean all
