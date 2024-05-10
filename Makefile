GREEN = \033[0;32m
.SILENT:

all:
	@make -C mandatory
	echo "${GREEN}Mandatory compiled"

bonus:
	@make -C bonus
	echo "${GREEN}Bonus compiled"

clean:
	@make clean -C mandatory
	@make clean -C bonus
	echo "${GREEN}Objects cleaned"

fclean:
	@make fclean -C mandatory
	@make fclean -C bonus
	echo "${GREEN}Objects and executables cleaned"

re: fclean all bonus

.PHONY: all clean fclean re bonus