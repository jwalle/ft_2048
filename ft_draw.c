/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:57:47 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/01 09:57:50 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

int		ft_cell_size(int max)
{
	int min_cell;

	min_cell = 5;
	while ((min_cell * 4 + 5) < max - 10)
		min_cell = min_cell + 2;
	return (min_cell);
}

void	draw_line(t_tab *toto, int xa, int line)
{
	int i;

	i = 0;
	mvprintw(line * toto->x, 0, "+");
	while (i < (xa * 4))
	{
		if (i % toto->x == 0 && i % xa == 0)
			mvprintw(line * toto->x, i, "+");
		else
			mvprintw(line * toto->x, i, "-");
		i++;
	}
	mvprintw(line * toto->x, i, "+");
}

void	draw_cell(t_tab *toto, int rang)
{
	int i;

	i = 0;
	while (i < (toto->x * 4))
	{
		if (i % toto->x != 0)
			mvprintw(i, rang * (toto->x * 2), "|");
		i++;
	}
}
/*
void	draw_color(int n, t_tab *toto, int i, int j, int xa)
{
	int x;
	int y;

	while ()
}*/

void	draw_cell_number(int xa, t_tab *toto)
{
	int i;
	int j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			(toto->tab[i - 1][j - 1] != 0) ?
			mvprintw(toto->x * i - (toto->x / 2), xa * j - (xa / 2),
			"%d", toto->tab[i - 1][j - 1]) :
			mvprintw(toto->x * i - (toto->x / 2), xa * j - (xa / 2), " ");
			j++;
			//draw_color(toto->tab[i - 1][j - 1], toto, toto->x * i - toto->x, xa * j - xa, xa);
		}
		i++;
	}
}

void	colle00(t_tab *toto)
{
	int line;
	int rang;
	int xa;

	clear();
	xa = toto->x * 2;
	line = 0;
	while (line < 5)
	{
		draw_line(toto, xa, line);
		line++;
	}
	rang = 0;
	while (rang < 5)
	{
		draw_cell(toto, rang);
		rang++;
	}
	draw_cell_number(xa, toto);
}

/*void	colle00(int x, int y)
{
	int		cn[2];
	int		middle;

	middle = (x / 2);
	cn[1] = -1;
	while (++cn[1] < y)
	{
		cn[0] = -1;
		while (++cn[0] < x)
		{
			ft_putstr(BLUE_BG);
			if ((!cn[0] && !cn[1] ) || (cn[1] == y - 1 && cn[0] == x - 1))
				ft_putchar('+');
			else if ((cn[0] == x - 1 && !cn[1]) ||(cn[1] == y - 1 && !cn[0]))
				ft_putchar('+');
			else if (cn[0] == middle && cn[1] == middle)
				ft_putstr("1");
			else if (cn[1] > 0 && cn[1] < y - 1 && cn[0] > 0 && cn[0] < x - 1)
				ft_putstr(" ");
			else if ((!cn[0] || cn[0] == x - 1) && cn[1] > 0 && cn[1] < y - 1)
				ft_putchar('|');
			else
				ft_putchar('-');
		}
		ft_putstr(RESET);
		ft_putchar('\n');
	}
}*/
