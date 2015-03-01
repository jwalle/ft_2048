/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:19:43 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/01 10:19:47 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_H
# define WONG_H

# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <termios.h>
# include <curses.h>
# include <stdlib.h>
# include <time.h>
# define SIZE 4
# define RESET		"\033[0m"
# define BLUE_BG	"\033[0;30;44m"

enum	e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_tab
{
	int			tab[4][4];
	int			empty;
	int			size_board;
	int			x;
	int			col;
	int			row;
	int			flag1;
	int			flag2;
	int			flag3;
	int			flag4;
	int			flag5;
	int			flag6;
}				t_tab;

void			print_cell(int nb);
void			colle00(t_tab *toto);
int				ft_cell_size(int max);
void			case_up(t_tab *toto);
void			case_down(t_tab *toto);
void			case_right(t_tab *toto);
void			case_left(t_tab *toto);
void			add_random(t_tab *toto);
void			set_flags(t_tab *toto);
int				check_loser(t_tab *toto);
void			ft_init_color();

#endif
