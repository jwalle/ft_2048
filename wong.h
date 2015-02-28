/* == HEADER == */

#ifndef		WONG_H
# define	WONG_H

# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <termios.h>
# include <curses.h>

# define SIZE 4
# define BOARD_SIZE 0
# define CELL_SIZE 0
# define RESET		"\033[0m"
# define BLUE_BG	"\033[0;30;44m"

enum	e_const
{
	WIN_VALUE = 2048
};

typedef struct 	e_tab
{
	int 		tab[4][4];
}				t_tab;

void	print_cell(int nb);
void	colle00(int x, int row, int col, t_tab *toto);
int		ft_cell_size(int max);


#endif