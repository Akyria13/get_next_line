########################################################################################################################
#                                                      VARIABLES                                                       #
########################################################################################################################

AUTHOR			:=		jowagner
NAME			:= 		get_next_line.a

AR				:= 		ar -rcs
CC				:= 		cc
CFLAGS			:= 		-Wall -Wextra -Werror -MD -MP


SRC				:=		$(addsuffix .c, \
						main \
						get_next_line \
						get_next_line_utils)

########################################################################################################################
#                                                      DIRECTORY                                                       #
########################################################################################################################

INC_PATH		:=		include/
SRC_PATH		:=		src/
OBJ_DIR			:= 		obj/

OBJ				:= 		$(SRC:%.c=$(OBJ_DIR)%.o)
DEP				:=		$(OBJ:%.o=%.d)

-include $(DEP)

########################################################################################################################
#                                                      TARGETS                                                         #
########################################################################################################################

all : 					.print_header $(NAME)

clean :					.print_header
							@printf "%-50b%b" "  $(YELLOW)[get_next_line/$(OBJ_DIR)] :$(RESET)" "\n"
							@rm -rf $(OBJ_DIR)
							@printf "%-50b%b" "  => $(BOLD_RED)Clean$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@printf "\n"

fclean : 				clean
							@printf "%-50b%b" "  $(YELLOW)[$(NAME)] :$(RESET)" "\n"
							@rm -f $(NAME)
							@printf "%-50b%b" "  => $(BOLD_RED)Clean$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							$(call SEPARATOR)

re : 					.print_header fclean all $(NAME)

.print_header :
							$(call TITLE)
							$(call SEPARATOR)
							$(call BUILD)
							$(call SEPARATOR)


########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

$(NAME) 		: 		$(OBJ)
							@printf "%-50b%b" "  $(YELLOW)[$(NAME)] :$(RESET)" "\n"
							@printf "%-50b%b" "  => $(BOLD_GREEN)Created$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@$(AR) -o $(NAME) $(OBJ)
							$(call SEPARATOR)

$(OBJ_DIR)%.o		:	$(SRC_PATH)%.c $(INC_PATH)get_next_line.h | $(OBJ_DIR)
							@$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

$(OBJ_DIR)			:
							@printf "%-50b%b" "  $(YELLOW)[get_next_line/$(OBJ_DIR)] :$(RESET)" "\n"
							@printf "%-50b%b" "  => $(BOLD_GREEN)Created$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@mkdir -p $(OBJ_DIR)
							@printf "\n"

########################################################################################################################
#                                                      DISPLAY                                                         #
########################################################################################################################

MAGENTA			:=		\033[0;95m
YELLOW			:=		\033[1;93m
GREEN 			:=		\033[0;32m
BLUE			:=		\033[0;94m
RED 			:=		\033[0;31m

BOLD_YELLOW 	:=		\e[1;33m
BOLD_PURPLE		:=		\e[1;35m
BOLD_GREEN		:= 		\e[1;32m
BOLD_WHITE		:=		\e[1;37m
BOLD_CYAN 		:= 		\e[1;36m
BOLD_BLUE 		:= 		\e[1;34m
BOLD_RED 		:=		\e[1;31m

RESET 			:=		\033[0m

define	TITLE
						@echo "$(MAGENTA)---------------------------------------------------$(RESET)";
						@echo "$(BOLD_RED)               _                       _       _ _              "
						@echo "$(BOLD_RED)     __ _  ___| |_     _ __   _____  _| |_    | (_)_ __   ___   "
						@echo "$(BOLD_YELLOW)    / _' |/ _ \ __|   | '_ \ / _ \ \/ / __|   | | | '_ \ / _ \  "
						@echo "$(BOLD_GREEN)   | (_) |  __/ |_    | | | |  __/>  <| |_    | | | | | |  __/  "
						@echo "$(BOLD_BLUE)    \__, |\___|\__|$(BOLD_PURPLE)___$(BOLD_BLUE)|_| |_|\___/_/\_\\___|$(BOLD_PURPLE)___$(BOLD_BLUE)|_|_|_| |_|\___|  "
						@echo "$(BOLD_BLUE)    |___/        $(BOLD_PURPLE)|_____|                 |_____|                "
endef

define PROGRESS_BAR

						@echo -n "$(BOLD_YELLOW)["
						@i=1; while [ $$i -le 3 ]; do echo -n "$(BOLD_WHITE)."; sleep 0.2; i=$$((i + 1)); done
						@echo -n "$(BOLD_YELLOW)]"
endef


define	BUILD
						@printf "%-32b%b" "  $(BOLD_CYAN)AUTHOR :$(RESET)" "$(BOLD_WHITE)$(AUTHOR)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)NAME   :$(RESET)" "$(BOLD_WHITE)$(NAME)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)CC     :$(RESET)" "$(BOLD_WHITE)$(CC)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)FLAGS  :$(RESET)" "$(BOLD_WHITE)$(CFLAGS)$(RESET)\n";
endef

define	SEPARATOR
						@printf "\n"
						@echo "$(MAGENTA)---------------------------------------------------$(RESET)";
						@printf "\n"
endef

########################################################################################################################
#                                                       PHONY TARGETS                                                  #
########################################################################################################################

.PHONY : 				all bonus clean fclean re
