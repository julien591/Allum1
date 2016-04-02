/*
** board_actions.c for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\Prog_elem\CPE_2015_Allum1\reserve
**
** Made by Julien Leleu
** Login   <Julien@epitech.net>
**
** Started on  Mon Feb 15 11:20:22 2016 Julien Leleu
** Last update Sun Feb 21 19:35:57 2016 Julien Leleu
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

void	the_end(char **board)
{
  int	i;

  i = 0;
  while (i != 4)
    {
      free (board[i]);
      i++;
    }
  free (board);
}

char	**delete(char **board, int line, int nb_matches)
{
  int	i;
  int	pos;

  i = 0;
  while (board[line - 1][i] != '\0')
    {
      if (board[line - 1][i] == '|')
	pos = i;
      i++;
    }
  while (nb_matches != 0)
    {
      board[line - 1][pos] = ' ';
      pos--;
      nb_matches--;
    }
  return (board);
}

void	display_the_board(char **board, int choice)
{
  int	i;

  i = 0;
  write(1, "*********\n", 10);
  while (i != 4)
    {
      my_putstr(board[i]);
      my_putchar('\n');
      i++;
    }
  if (choice == 0)
    write(1, "*********\n\n", 11);
  else
    write(1, "*********\n", 10);
}

char	**create_the_board()
{
  char	**board;
  int	i;

  i = 0;
  board = malloc(sizeof(char *) * 5);
  if (board == NULL)
    return (NULL);
  while (i != 4)
    {
      board[i] = malloc(10);
      if (board[i] == NULL)
	return (NULL);
      i++;
    }
  board[0] = my_strcpy(board[0], "*   |   *");
  board[1] = my_strcpy(board[1], "*  |||  *");
  board[2] = my_strcpy(board[2], "* ||||| *");
  board[3] = my_strcpy(board[3], "*|||||||*");
  return (board);
}
