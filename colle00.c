/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle	  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/03 18:08:35 by jwalle	           #+#    #+#             */
/*   Updated: 2014/08/17 20:23:25 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "wong.h"

int		ft_cell_size(int max)
{
	int min_cell;

	min_cell = 5;
	while ((min_cell * 4 + 5) < max - 10)
		min_cell = min_cell + 2;
	return(min_cell);
}

void	draw_line(int x)
{
	int	y;
	int i;

	i = 0;
	while (i < 4)
	{
		printf("+");
		y = x;
		while (y--)
			printf("-");
		i++;
	}
	printf("+\n");
}


void	draw_cell(int x)
{
	int	y;
	int i;

	i = 0;
	while (i < 4)
	{
		printf("|");
		y = x;
		while (y--)
			printf(" ");
		i++;
	}
	printf("|\n");
}

void	draw_cell_number(int x)
{
	int i;
	int j;
	char *s;

	s = "2048";

	j = x / 2 + (int)ft_strlen(s) / 2;
	i = 0;
	while (i < 4)
	{
		printf("|");
		printf("%*s", j, s);
		printf("%*s",x - j , "");
		i++;
	}
	printf("|\n");
}

void	colle00(int x)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < 4)
	{
		draw_line(x);
		j = 0;
		while(j != x)
		{
			if (j == x / 2)
				draw_cell_number(x);
			else
				draw_cell(x);
			j++;
		}
		i++;
	}
	draw_line(x);
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