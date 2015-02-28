/* == HEADER == */

#ifndef		WONG_H
# define	WONG_H

# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <termios.h>
#include <errno.h>


# define SIZE 4
# define BOARD_SIZE 0
# define CELL_SIZE 0
# define RESET		"\033[0m"
# define BLUE_BG	"\033[0;30;44m"

enum	e_const
{
	WIN_VALUE = 2048
};

void	print_cell(int nb);
void	colle00(int x);
int		ft_cell_size(int max);


#endif