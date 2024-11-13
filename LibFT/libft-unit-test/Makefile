# Define colors
GREEN := \033[0;32m
NC := \033[0m # No Color

all:
	-@rm result.log > /dev/null 2>&1
	@./addso.sh > /dev/null 2>&1
	@echo "$(GREEN)Running make in ../ with targets re so...$(NC)"
	@make -C ../ re so > /dev/null 2>&1
	@echo "$(GREEN)Running make in ./libft-unit-test...$(NC)"
	@make -C ./libft-unit-test
	@echo "$(GREEN)Executing tests...$(NC)"
	@cd ./libft-unit-test && ./run_test
	@echo "$(GREEN)Moving result.log...$(NC)"
	@mv ./libft-unit-test/result.log . > /dev/null 2>&1

clean:
	make -C ./libft-unit-test clean
	make -C ../ clean

fclean:
	make -C ./libft-unit-test fclean
	make -C ../ fclean

re:
	make -C ./libft-unit-test re

norme:
	make -C ./libft-unit-test norme

codesize:
	make -C ./libft-unit-test codesize

coffee:
	make -C ./libft-unit-test coffee

.PHONY: all clean fclean re norme codesize coffee