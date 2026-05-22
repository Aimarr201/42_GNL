NAME=a.out

CC=cc
CFLAGS= -Wall -Werror -Wextra -I.
SANITIZE= -fsanitize=address -g3
BUFFER= -D BUFFER_SIZE=42

SRC=get_next_line.c get_next_line_utils.c
BONUSSRC=get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ=$(SRC:.c=.o)
BONUSOBJ=$(BONUSSRC:.c=.o)
HEADERS=get_next_line.h
BONUSHEADERS=get_next_line_bonus.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(SANITIZE) $(BUFFER) -o $(NAME) $(OBJ)

bonus: $(BONUSOBJ) $(BONUSHEADERS)
	$(CC) $(CFLAGS) $(SANITIZE) $(BUFFER) -o $(NAME) $(BONUSOBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(SANITIZE) $(BUFFER) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re