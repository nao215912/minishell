ESC_CLEAR_SCREEN		?=	\x1b[2J
ESC_CLEAR_CURRENT_LINE	?=	\x1b[2K\r

ESC_DEFAULT ?=	\x1b[0m
ESC_BOLD	?=	\x1b[1m
ESC_UNDER	?=	\x1b[4m
ESC_REV		?=	\x1b[7m

ESC_BLACK		?=	\x1b[30m
ESC_RED			?=	\x1b[31m
ESC_GREEN		?=	\x1b[32m
ESC_YELLOW		?=	\x1b[33m
ESC_BLUE		?=	\x1b[34m
ESC_PURPLE		?=	\x1b[35m
ESC_CYAN		?=	\x1b[36m
ESC_WHITE		?=	\x1b[37m

ESC_BACK_BLACK		?=	\x1b[40m
ESC_BACK_RED		?=	\x1b[41m
ESC_BACK_GREEN		?=	\x1b[42m
ESC_BACK_YELLOW		?=	\x1b[43m
ESC_BACK_BLUE		?=	\x1b[44m
ESC_BACK_PURPLE		?=	\x1b[45m
ESC_BACK_CYAN		?=	\x1b[46m
ESC_BACK_GRAY		?=	\x1b[47m

NAME	=	minishell

CC	=	gcc

CFLAGS		=	-I $(shell brew --prefix readline)/include -Wall -Werror -Wextra
READLINE	=	-lreadline -L$(shell brew --prefix readline)/lib

VPATH = \
	srcs:\
	srcs/builtin:\
	srcs/env:\
	srcs/exec:\
	srcs/exit_status:\
	srcs/expansion:\
	srcs/lexer:\
	srcs/libft:\
	srcs/parser:\
	srcs/signal:\
	srcs/utils

INCDIR	=	./include
OBJDIR	=	./objs
DPSDIR	=	./dps

BUILTIN = \
	exec_builtin.c \
	is_builtin.c \
	msh_bi_cd.c \
	msh_bi_echo.c \
	msh_bi_env.c \
	msh_bi_exit.c \
	msh_bi_export.c \
	msh_bi_pwd.c \
	msh_bi_unset.c \
	msh_get_builtin.c

ENV = \
	add_env.c \
	clear_env.c \
	del_env.c \
	get_env.c \
	init_env.c \
	new_env.c

EXEC = \
	cleanup_exec_command.c \
	exec_command.c \
	executor_clear.c \
	format_command.c \
	format_path.c \
	here_doc.c \
	prepare_exec_command.c \
	restore_fd.c \
	setup_redirects.c

EXIT_STATUS = \
	exit_status.c \
	get_exit_status.c \
	set_exit_status.c

EXPANSION = \
	expand_env.c \
	expansion.c \
	expansion_dq.c \
	expansion_sp.c \
	expansion_sq.c \
	is_env_ch.c

LEXER = \
	get_op_func.c \
	is_brackets_closed.c \
	lexer.c \
	op_dri_to_node.c \
	op_dro_to_node.c \
	op_other_to_node.c \
	op_pipe_to_node.c \
	op_ri_to_node.c \
	op_ro_to_node.c \
	op_to_node.c \
	remove_brackets.c \
	token_clear.c

LIBFT = \
	ft_atoi.c \
	ft_charskip.c \
	ft_isdigit.c \
	ft_isdigitstr.c \
	ft_memmove.c \
	ft_put_str_fd.c \
	ft_putendl_fd.c \
	ft_spaceskip.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strncmp.c

PARSER = \
	node_add_back.c \
	node_clear.c \
	parser.c

SIGNAL = \
	child_signal.c \
	heredoc_signal.c \
	parent_signal.c

UTILS = \
	clear_string_array.c \
	is_number.c \
	is_number_string.c \
	is_space.c \
	msh_atoi.c \
	skip_space.c \
	skip_until_ch.c \
	substr.c \
	xclose.c \
	xdup.c \
	xdup2.c \
	xfork.c \
	xmalloc.c \
	xperror.c \
	xpipe.c \
	xwaitpid.c

SRCS = \
	$(BUILTIN) \
	$(ENV) \
	$(EXEC) \
	$(EXIT_STATUS) \
	$(EXPANSION) \
	$(LEXER) \
	$(LIBFT) \
	$(PARSER) \
	$(SIGNAL) \
	$(UTILS) \
	main.c

OBJS	=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DPS		=	$(addprefix $(DPSDIR)/, $(notdir $(SRCS:.o=.d)))

all:	$(OBJDIR)  $(DPSDIR) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(READLINE)
	@printf "$(ESC_CLEAR_CURRENT_LINE)$(ESC_GREEN)$(NAME): All files compiled$(ESC_DEFAULT)✅\n"

$(OBJDIR)/%.o: %.c
	@$(CC) $(CFLAGS) -I $(INCDIR) -MMD -MP -MF $(DPSDIR)/$(notdir $(<:.c=.d)) -c $< -o $@
	@$(shell $(eval n = $(shell find ./srcs/. -type f | wc -l)) \
		$(eval m = $(shell find ./objs/. -type f | wc -l)) \
		$(eval p = $(shell echo "($m*100/$n*100)/100" | bc)))
	@printf "$(ESC_CLEAR_CURRENT_LINE)$(ESC_YELLOW)$p%%\t($(notdir $<))$(ESC_DEFAULT)"


-include $(DPS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(DPSDIR):
	mkdir -p $(DPSDIR)

clean:
	@rm -rf $(DPSDIR)
	@rm -rf $(OBJDIR)

fclean:	clean
	@rm -f $(NAME)

re: fclean
	@make -C .

.PHONY: all clean fclean re dir print