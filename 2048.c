/* === HEADER === */

#include "wong.h"


int ram()
{
	return (rand() % 4 + 1);
}


void	clear_tab(t_tab *toto)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while(j < 4)
		{
			toto->tab[i][j] = 0;
			j++;
		}
		i++;
	}
}


void	print_cell(int nb)
{
	printf("[");
	printf("%d", nb);
	printf("]");
}

void	add_random(t_tab *toto)
{
	int i;
	int j;

	i = ram() - 1;
	j = ram() - 1;

	if (toto->tab[i][j] == 0)
	{
		(((rand()) % 100) < 50) ? (toto->tab[i][j] = 2) : (toto->tab[i][j] = 4);
		toto->empty--;
	}
	else
		add_random(toto);
}


void	init_tab(t_tab *toto)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while(j < 4)
		{
			toto->tab[i][j] = 0;
			j++;
		}
		i++;
	}
	add_random(toto);
	add_random(toto);
}


int		main()
{
	int 	SIZE_BOARD;
	int 	SIZE_CELL;
	int 	row;
	int 	col;
	int		c;
	t_tab	toto;

	srand(time(0));
	toto.empty = 16;
	init_tab(&toto);
	initscr();
	getmaxyx(stdscr, row, col);
	keypad(stdscr, true);
	col < row ? (SIZE_BOARD = col) : (SIZE_BOARD = row);
	SIZE_CELL = ft_cell_size(SIZE_BOARD);
	//print_grid();
	colle00(SIZE_CELL, row, col, &toto);
	move(0, 0);
	refresh();
	while ((c = getch()))
	{
		if (c == 27)
			break;
	}
	sleep(1);
	endwin();
	//clear_tab(&toto);
	return (0);
}

/*
static void sigwinchHandler(int sig)
{
    struct winsize ws;
    struct sigaction sa;

	if (sigaction(SIGWINCH, &sa, NULL) == -1)
        printf("error\n");
	printf("%*d\n", (ws.ws_row / 2), sig);
}



int main()
{
    struct winsize ws;
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = sigwinchHandler;
    if (sigaction(SIGWINCH, &sa, NULL) == -1)
        printf("error\n");

    for (;;) {
        pause();                        

        if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1)
            printf("error\n");
        printf("Caught SIGWINCH, new window size: "
                "%d rows * %d columns\n", ws.ws_row, ws.ws_col);
		
    }
}
*/