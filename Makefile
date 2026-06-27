# ══════════════════════════════════════════════════════════════════════════════
#  🌈  P H I L O S O P H E R S   —   M A K E F I L E
#  Replace the placeholder source files under SOURCES with your actual .c files
# ══════════════════════════════════════════════════════════════════════════════

NAME       := philo

SRC_DIR    := src
INC_DIR    := include
OBJ_DIR    := build
LIBFT_DIR  := ./ft_libft
PRINTF_DIR := ./ft_printf

LIBFT      := $(LIBFT_DIR)/libft.a
LIBPRINTF  := $(PRINTF_DIR)/libftprintf.a

CC         := cc
CFLAGS     := -Wall -Wextra -Werror -pthread
INCLUDES   := -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

LDLIBS     := -lpthread


# ══════════════════════════════════════════════════════════════════════════════
#  🌈  C O L O R S   &   S T Y L E
# ══════════════════════════════════════════════════════════════════════════════

RESET          = \033[0m
BOLD           = \033[1m
DIM            = \033[2m
ITALIC         = \033[3m

# ── Pride rainbow ─────────────────────────────────────────────────────────────
RED            = \033[38;5;196m
ORANGE         = \033[38;5;208m
YELLOW         = \033[38;5;226m
GREEN          = \033[38;5;46m
CYAN           = \033[38;5;51m
BLUE           = \033[38;5;33m
PURPLE         = \033[38;5;129m
PINK           = \033[38;5;213m
MAGENTA        = \033[38;5;201m
WHITE          = \033[38;5;231m
GRAY           = \033[38;5;245m

# ── Trans flag ────────────────────────────────────────────────────────────────
TRANS_BLUE     = \033[38;5;75m
TRANS_PINK     = \033[38;5;218m
TRANS_WHITE    = \033[38;5;231m

# ── Bi flag ───────────────────────────────────────────────────────────────────
BI_PINK        = \033[38;5;205m
BI_PURPLE      = \033[38;5;93m
BI_BLUE        = \033[38;5;27m


# ══════════════════════════════════════════════════════════════════════════════
#  🌈  A N I M A T I O N S
# ══════════════════════════════════════════════════════════════════════════════

define LOADING_ANIMATION
	@echo -n "$(CYAN)$(BOLD)  Loading$(RESET)"
	@for i in 1 2 3; do \
		echo -n "$(CYAN).$(RESET)"; \
		sleep 0.2; \
	done
	@echo ""
endef

define PROGRESS_BAR
	@echo -n "  $(BOLD)$(RED)▓$(ORANGE)▓$(YELLOW)▓$(GREEN)▓$(CYAN)▓$(BLUE)▓$(PURPLE)▓$(MAGENTA)▓$(PINK)▓$(RED)▓$(ORANGE)▓$(YELLOW)▓$(GREEN)▓$(CYAN)▓$(BLUE)▓$(PURPLE)▓$(MAGENTA)▓$(PINK)▓$(RED)▓$(ORANGE)▓$(RESET) "
	@echo "$(BOLD)$(GREEN)100%$(RESET)"
endef


# ══════════════════════════════════════════════════════════════════════════════
#  🏳️‍🌈  H E A D E R   S C R E E N
# ══════════════════════════════════════════════════════════════════════════════

define PRIDE_HEADER
	@clear
	@echo ""
	@echo "$(BOLD)$(RED)  ╔══════════════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(RED)  ║$(ORANGE)                                                                      $(RED)║$(RESET)"
	@echo "$(BOLD)$(ORANGE)  ║$(YELLOW)                 ██████╗ ██╗  ██╗██╗██╗      ██████  	         $(ORANGE)║$(RESET)"
	@echo "$(BOLD)$(YELLOW)  ║$(GREEN)                 ██╔══██╗██║  ██║██║██║     ██╔═══██ 	         $(YELLOW)║$(RESET)"
	@echo "$(BOLD)$(GREEN)  ║$(CYAN)                 ██████╔╝███████║██║██║     ██║   ██║    	         $(GREEN)║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║$(BLUE)                 ██╔═══╝ ██╔══██║██║██║     ██║   ██║    	         $(CYAN)║$(RESET)"
	@echo "$(BOLD)$(BLUE)  ║$(PURPLE)                 ██║     ██║  ██║██║███████╗╚██████  	         $(BLUE)║$(RESET)"
	@echo "$(BOLD)$(PURPLE)  ║$(MAGENTA)                 ╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ 	         $(PURPLE)║$(RESET)"
	@echo "$(BOLD)$(MAGENTA)  ║$(PINK)                                                                      $(MAGENTA)║$(RESET)"
	@echo "$(BOLD)$(PINK)  ║$(RED)     $(RED)🍝  $(ORANGE)eat  $(YELLOW)·  $(GREEN)think  $(CYAN)·  $(BLUE)sleep  $(PURPLE)·  $(MAGENTA)repeat  $(PINK)·  $(RED)but never die  🍴$(PINK)     $(PINK)║$(RESET)"
	@echo "$(BOLD)$(RED)  ║$(ORANGE)                                                                      $(RED)║$(RESET)"
	@echo "$(BOLD)$(ORANGE)  ║$(YELLOW)     $(TRANS_PINK)BUILD SYSTEM v1.0$(YELLOW)  ·  $(TRANS_BLUE)42 School Edition$(YELLOW)  ·  $(TRANS_WHITE)be yourself 🏳️‍⚧️$(YELLOW)       $(ORANGE)║$(RESET)"
	@echo "$(BOLD)$(YELLOW)  ║$(GREEN)                                                                      $(YELLOW)║$(RESET)"
	@echo "$(BOLD)$(GREEN)  ╚══════════════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@sleep 1
endef


# ══════════════════════════════════════════════════════════════════════════════
#  ✅  S U C C E S S   S C R E E N
# ══════════════════════════════════════════════════════════════════════════════

define SUCCESS_SCREEN
	@echo ""
	@echo "$(BOLD)$(GREEN)  ╔═══════════════════════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(GREEN)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(GREEN)  ║       COMPILATION COMPLETED — NO PHILOSOPHER WAS HARMED IN THIS BUILD        ║$(RESET)"
	@echo "$(BOLD)$(GREEN)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   ███████╗██╗   ██╗ ██████╗ ██████╗███████╗███████╗███████╗███████╗███████╗  ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   ██╔════╝██║   ██║██╔════╝██╔════╝██╔════╝██╔════╝██╔════╝██╔════╝██╔════╝  ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   ███████╗██║   ██║██║     ██║     █████╗  ███████╗███████╗███████╗███████╗  ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   ╚════██║██║   ██║██║     ██║     ██╔══╝  ╚════██║╚════██║╚════██║╚════██║  ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   ███████║╚██████╔╝╚██████╗╚██████╗███████╗███████║███████║███████║███████║  ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   ╚══════╝ ╚═════╝  ╚═════╝ ╚═════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝  ║$(RESET)"
	@echo "$(BOLD)$(GREEN)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(GREEN)  ║   $(YELLOW)🌈  $(NAME) is ready · you are seen · you are loved · go eat 🍝$(GREEN)         ║$(RESET)"
	@echo "$(BOLD)$(GREEN)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(GREEN)  ╚═══════════════════════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
endef


# ══════════════════════════════════════════════════════════════════════════════
#  🧹  C L E A N   S C R E E N
# ══════════════════════════════════════════════════════════════════════════════

define CLEAN_SCREEN
	@echo ""
	@echo "$(BOLD)$(ORANGE)  ╔═══════════════════════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(ORANGE)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(ORANGE)  ║              SWEEPING THE GLITTER OFF THE FLOOR 🧹✨                         ║$(RESET)"
	@echo "$(BOLD)$(ORANGE)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(YELLOW)  ║   ██████╗██╗     ███████╗ █████╗ ███╗  ██╗██╗███╗  ██╗ ██████╗              ║$(RESET)"
	@echo "$(BOLD)$(YELLOW)  ║  ██╔════╝██║     ██╔════╝██╔══██╗████╗ ██║██║████╗ ██║██╔════╝              ║$(RESET)"
	@echo "$(BOLD)$(YELLOW)  ║  ██║     ██║     █████╗  ███████║██╔██╗██║██║██╔██╗██║██║  ███╗             ║$(RESET)"
	@echo "$(BOLD)$(YELLOW)  ║  ██║     ██║     ██╔══╝  ██╔══██║██║╚████║██║██║╚████║██║   ██║             ║$(RESET)"
	@echo "$(BOLD)$(YELLOW)  ║  ╚██████╗███████╗███████╗██║  ██║██║ ╚███║██║██║ ╚███║╚██████╔╝             ║$(RESET)"
	@echo "$(BOLD)$(YELLOW)  ║   ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚══╝╚═╝╚═╝  ╚══╝ ╚═════╝             ║$(RESET)"
	@echo "$(BOLD)$(ORANGE)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(ORANGE)  ║   $(RED)🔴 $(ORANGE)🟠 $(YELLOW)🟡 $(GREEN)🟢 $(BLUE)🔵 $(PURPLE)🟣$(ORANGE)  The slate is clean — a fresh start awaits you          ║$(RESET)"
	@echo "$(BOLD)$(ORANGE)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(ORANGE)  ╚═══════════════════════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
endef


# ══════════════════════════════════════════════════════════════════════════════
#  🔄  R E B U I L D   S C R E E N
# ══════════════════════════════════════════════════════════════════════════════

define REBUILD_SCREEN
	@echo ""
	@echo "$(BOLD)$(MAGENTA)  ╔═══════════════════════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(MAGENTA)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(MAGENTA)  ║        🏳️‍🌈  REBORN — BECAUSE REINVENTING YOURSELF IS ALWAYS VALID  🏳️‍🌈       ║$(RESET)"
	@echo "$(BOLD)$(MAGENTA)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(PINK)  ║   ██████╗ ███████╗██████╗  ██████╗ ██████╗ ███╗  ██╗                         ║$(RESET)"
	@echo "$(BOLD)$(PINK)  ║   ██╔══██╗██╔════╝██╔══██╗██╔═══██╗██╔══██╗████╗ ██║                         ║$(RESET)"
	@echo "$(BOLD)$(PINK)  ║   ██████╔╝█████╗  ██████╔╝██║   ██║██████╔╝██╔██╗██║                         ║$(RESET)"
	@echo "$(BOLD)$(PINK)  ║   ██╔══██╗██╔══╝  ██╔══██╗██║   ██║██╔══██╗██║╚████║                         ║$(RESET)"
	@echo "$(BOLD)$(PINK)  ║   ██║  ██║███████╗██████╔╝╚██████╔╝██║  ██║██║ ╚███║                         ║$(RESET)"
	@echo "$(BOLD)$(PINK)  ║   ╚═╝  ╚═╝╚══════╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚══╝                         ║$(RESET)"
	@echo "$(BOLD)$(MAGENTA)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(MAGENTA)  ║   $(TRANS_PINK)Starting fresh compilation cycle...$(MAGENTA)                                      ║$(RESET)"
	@echo "$(BOLD)$(MAGENTA)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(MAGENTA)  ╚═══════════════════════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@sleep 1
endef


# ══════════════════════════════════════════════════════════════════════════════
#  📖  H E L P   S C R E E N
# ══════════════════════════════════════════════════════════════════════════════

define HELP_SCREEN
	@echo ""
	@echo "$(BOLD)$(CYAN)  ╔═══════════════════════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║                   🌈  MAKEFILE COMMAND REFERENCE  🌈                         ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   $(GREEN)make$(CYAN)  /  $(GREEN)make all$(CYAN)    →  Compile $(NAME) and all dependencies            ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   $(YELLOW)make clean$(CYAN)         →  Remove all object files                          ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   $(ORANGE)make fclean$(CYAN)        →  Remove objects + executable                      ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   $(MAGENTA)make re$(CYAN)            →  Full rebuild (fclean + all)                      ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   $(BLUE)make help$(CYAN)          →  Show this glorious help screen                  ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║   $(TRANS_PINK)🏳️‍⚧️  You are valid. Your code is valid. Keep going.  🏳️‍⚧️$(CYAN)               ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ║                                                                               ║$(RESET)"
	@echo "$(BOLD)$(CYAN)  ╚═══════════════════════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
endef


# ══════════════════════════════════════════════════════════════════════════════
#  📁  S O U R C E S   — add your .c files here
# ══════════════════════════════════════════════════════════════════════════════

SOURCES := \
	src/YOUR_FILE_HERE.c
#	src/another_file.c   ← uncomment and fill as needed

OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


# ══════════════════════════════════════════════════════════════════════════════
#  🎯  R U L E S
# ══════════════════════════════════════════════════════════════════════════════

all: header $(LIBFT) $(LIBPRINTF) $(NAME)
	@$(call PROGRESS_BAR)
	@$(call SUCCESS_SCREEN)


header:
	@$(call PRIDE_HEADER)


$(NAME): $(OBJECTS)
	@echo ""
	@echo "$(BOLD)$(MAGENTA)  Linking $(NAME)...$(RESET)"
	@$(call LOADING_ANIMATION)
	@$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf \
		$(LDLIBS) -o $@
	@echo "$(BOLD)$(GREEN)  ✓ $(NAME) linked$(RESET)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo -n "$(GRAY)  compiling $< $(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BOLD)$(GREEN)✓$(RESET)"


$(LIBFT):
	@echo "$(BOLD)$(BI_PINK)  building libft...$(RESET)"
	@$(call LOADING_ANIMATION)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "$(BOLD)$(BI_BLUE)  ✓ libft ready$(RESET)"


$(LIBPRINTF):
	@echo "$(BOLD)$(BI_PURPLE)  building libftprintf...$(RESET)"
	@$(call LOADING_ANIMATION)
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR)
	@echo "$(BOLD)$(BI_BLUE)  ✓ libftprintf ready$(RESET)"


clean:
	@$(call CLEAN_SCREEN)
	@$(call LOADING_ANIMATION)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR) clean
	@echo "$(BOLD)$(GREEN)  ✓ object files removed$(RESET)"


fclean: clean
	@echo "$(BOLD)$(RED)  Executing deep cleanup — out with the old, in with the new 🌈$(RESET)"
	@$(call LOADING_ANIMATION)
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR) fclean
	@echo "$(BOLD)$(GREEN)  ✓ executables removed$(RESET)"


re: fclean
	@$(call REBUILD_SCREEN)
	@$(MAKE) all


help:
	@$(call HELP_SCREEN)


.PHONY: all header clean fclean re help