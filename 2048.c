/* === HEADER === */

#include "wong.h"

/*void	print_grid()
{
	 int i;
	 int j;

	 i = 0;
	 while (i < SIZE)
	 {
	 	j = 0;
	 	while (j < SIZE)
	 	{
	 		//print_cell(i);
	 		colle00(5, );
	 		j++;
	 	}
	 	printf("\n");
	 	i++;
	 }
}*/



void	print_cell(int nb)
{
	printf("[");
	printf("%d", nb);
	printf("]");
}


void	init_tab(int **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while(j < 3)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}


int		main()
{
	int SIZE_BOARD;
	int SIZE_CELL;
	int row;
	int col;
	int **tab;

	tab = malloc(sizeof(int)* 16);
	init_tab(tab);
	initscr();
	getmaxyx(stdscr, row, col);
	printf("line %d\n", row);
	printf("columns %d\n", col);
	col < row ? (SIZE_BOARD = col) : (SIZE_BOARD = row);
	SIZE_CELL = ft_cell_size(SIZE_BOARD);
	printf("SIZE_BOARD = %d\n", SIZE_BOARD);
	printf("SIZE_CELL = %d\n", SIZE_CELL);
	//print_grid();
	colle00(SIZE_CELL, row, col, tab);
	refresh();
	getch();
	endwin();

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