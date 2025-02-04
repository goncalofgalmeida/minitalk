S_NAME = server
C_NAME = client

SRCS_DIR = ./srcs

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

S_SRC =	$(SRCS_DIR)/server.c
C_SRC = $(SRCS_DIR)/client.c

S_OBJS = $(S_SRC:.c=.o)
C_OBJS = $(C_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

all: $(S_NAME) $(C_NAME)

$(S_NAME): $(LIBFT) $(S_OBJS)
	$(CC) $(CFLAGS) $(S_OBJS) $(LIBFT) -o $(S_NAME)

$(C_NAME): $(LIBFT) $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) $(LIBFT) -o $(C_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(S_OBJS) $(C_OBJS)

fclean: clean
	$(RM) $(S_NAME) $(C_NAME) $(LIBFT)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean
	$(MAKE) all