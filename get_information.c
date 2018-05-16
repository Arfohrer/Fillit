/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_information.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arfohrer <arfohrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:31:02 by mabouche          #+#    #+#             */
/*   Updated: 2018/05/16 16:47:27 by arfohrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_grid(int **grid, int p)
{
	int i;

	i = 0;
	while (i < p)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int		ft_openreadclose(char *name, char *buf)
{
	int fd;
	int ret;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (ft_error("Failed to open."));
	if ((ret = read(fd, buf, BUF_SIZE)) == -1)
		return (ft_error("Failed to read."));
	else if (ret == 0)
		return (ft_error("Nothing to read."));
	else if ((ret % 21) - 20 != 0)
		return (ft_error("Too many character."));
	buf[ret] = '\0';
	close(fd);
	return (ret);
}

void	print_grid(int **grid, int size_grid, int x, int y)
{
	int index;

	index = 0;
	while (y < size_grid)
	{
		while (x < size_grid)
		{
			if (grid[y][x] == 0)
			{
				ft_putchar('.');
				x++;
			}
			else
			{
				grid[y][x] += 64;
				ft_putchar(grid[y][x]);
				x++;
			}
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}

void	solver(int ***matrice, int p)
{
	int index;
	int size_grid;
	int **grid;

	index = 0;
	while (index < p)
	{
		piece_top_left(matrice[index]);
		index++;
	}
	index = 0;
	size_grid = (carre_haut(p * 4));
	grid = create_grid(size_grid, 0);
	while (fill_grid(grid, matrice, p, index, size_grid) == 0)
	{
		free_grid(grid, size_grid);
		size_grid++;
		grid = create_grid(size_grid, 0);
	}
	print_grid(grid, size_grid, 0, 0);
}

int		main(int ac, char **av)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**dest;
	int		p;
	int		***matrice;

	if ((ret = ft_openreadclose(av[1], buf)) == 0)
		return (0);
	p = (ret - 20) / 21 + 1;
	dest = ft_createtab(buf, p);
	if (!(ft_check_error(dest)))
		return (0);
	ft_changesharp(dest);
	matrice = ft_fonction2(dest, p);
	solver(matrice, p);
	return (0);
}
