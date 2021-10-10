NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRCS_DIR =	./srcs				\
			./srcs/instructions	\
			./srcs/make_stack	\
			./srcs/sorting

OBJS_DIR = ./objs
INC_DIR = ./includes


SRCS =	./srcs/main.c	\
		./srcs/instructions/pa_pb.c		\
		./srcs/instructions/rra_rrb.c	\
		./srcs/instructions/sa_sb.c		\
		./srcs/instructions/ra_rb.c		\
		./srcs/make_stack/word_is_int.c	\
		./srcs/make_stack/make_word.c	\
		./srcs/make_stack/make_stack.c	\
		./srcs/sorting/sorting_three_word.c	\
		./srcs/sorting/move_to_b.c	\
		./srcs/sorting/sorting_five_word.c	\
		./srcs/sorting/a_sorting_three_word.c	\
		./srcs/sorting/b_sorting_three_word.c	\
		./srcs/sorting/move_to_a.c	\
		./srcs/free_stacks.c		\
		./srcs/min_mid_max.c	\
		./srcs/push_swap.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INC_DIR) -c $^

clean :
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
