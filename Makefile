SRC =	ft_printf.c \
		ft_writechar.c \
		
OBJS= $(SRC:.c=.o)
NAME = libftprintf.a
DPS = libftprintf.h

CC = gcc

# r es para reemplazar los nuevos files por los anteriores, c para crear la libreria si no existe
# aun y s crea un directorio para que sea mas facil aceder a las funciones

AR = ar -rcs
CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f *~ $(NAME) *.o
	

re: fclean all
