/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arfohrer <arfohrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:04:43 by arfohrer          #+#    #+#             */
/*   Updated: 2018/05/16 16:48:11 by arfohrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 676

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

int		ft_check_error(char **str);
int		ft_error(char *str);
int		ft_usage(void);
int		**create_grid(int size_grid, int n);
int		**piece_top_left(int **tab);
int		top_max(int **tab);
void	put_left(int **tab);
void	put_top(int **tab);
int		**piece_top_left(int **tab);
int		fill_grid(int **grid, int ***matrice, int p, int index, int size_grid);
int		**erase_piece(int piece, int **start, int size_grid);
int		**fill_piece(int **piece, int x, int y,
		int **start, int p, int **grid, int size_grid);
int		test_piece(int **piece, int x, int y, int **start, int size_grid);
int		carre_haut(int p);
int		ft_check_error(char **str);
int		ft_error(char *str);
void	print_grid(int **grid, int size_grid, int x, int y);
int		ft_openreadclose(char *name, char *buf);
void	ft_changesharp(char **dest);
void	ft_fonction(char *piece, int **matrice);
int		***ft_fonction2(char **dest, int nbpiece);
char	**ft_createtab(char *buf, int p);

#endif
