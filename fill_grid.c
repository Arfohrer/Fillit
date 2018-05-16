/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:22:54 by mabouche          #+#    #+#             */
/*   Updated: 2018/05/07 17:22:56 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
int **create_grid(int P, int n);

int carre_haut(int P);

int test_piece(int **piece, int x, int y, int **start, int size_grid)
{
   
    int l;
    int c;

    l = 0;
    c = 0;
    while(l <= 3)
    {
        while(c <= 3)
            {   
                if (piece[l][c] != 0 && (x + c >= size_grid || y + l >= size_grid))
                    return(0);
                if(piece[l][c] != 0 && start[y + l][x + c] != 0)            
                    return(0);
                c++;
            }            
            c = 0;
            l++;
        }
    return(1);
}


int **fill_piece(int **piece, int x, int y, int **start, int P, int **grid, int size_grid)
{
   
    int l;
    int c;

    l = 0;
    c = 0;
    while(l <= 3)
    {
        while(c <= 3)
        {
            if (piece[l][c] != 0)
                start[y + l][x + c] = piece[l][c];
            c++;
        }
        c = 0;
        l++;
    }
    return(grid);
}

int **erase_piece(int piece, int **start, int size_grid)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(y < size_grid)
    {
        while(x < size_grid)
        {
            if(start[y][x] == piece)
                start[y][x] = 0;
            x++;
        }
        x = 0;
        y++;
}
    return(start);
}

int fill_grid(int **grid, int ***matrice, int P, int index, int size_grid)
{

    int x;
    int y; 

    x = 0;
    y = 0;
   if(index != (P))
   {
        while ((x * y) < (size_grid * size_grid))
        {
            if(test_piece(matrice[index], x, y, grid, size_grid))
            {
                grid = fill_piece(matrice[index], x, y, grid, P, grid, size_grid);
                if(fill_grid(grid, matrice, P, ++index, size_grid) == 1)
                    return(1);
                grid = erase_piece(--index + 1, grid, size_grid);
            }
            if (x < size_grid)
                x++;
            else
            {
                x = 0;
                y++;
            }
        }
        x = 0;
        y = 0;
        return(0);
    }
   return(1);
   }

