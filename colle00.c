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
	while ((min_cell * 4 + 5) < max)
		min_cell = min_cell + 2;
	return(min_cell);
}

void	colle00(int x)
{
	int		cn[2];
	int		middle;

	middle = (x / 2);
	cn[1] = -1;
	while (++cn[1] < x)
	{
		cn[0] = -1;
		while (++cn[0] < x)
		{
			if ((!cn[0] && !cn[1] ) || (cn[1] == x - 1 && cn[0] == x - 1))
				ft_putchar('+');
			else if ((cn[0] == x - 1 && !cn[1]) ||(cn[1] == x - 1 && !cn[0]))
				ft_putchar('+');
			else if (cn[0] == middle && cn[1] == middle)
				ft_putstr("1");
			else if (cn[1] > 0 && cn[1] < x - 1 && cn[0] > 0 && cn[0] < x - 1)
				ft_putstr(" ");
			else if ((!cn[0] || cn[0] == x - 1) && cn[1] > 0 && cn[1] < x - 1)
				ft_putchar('|');
			else
				ft_putchar('-');
		}
		ft_putchar('\n');
	}
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