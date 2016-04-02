/*
** allum1.c for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\Prog_elem\CPE_2015_Allum1
**
** Made by Julien Leleu
** Login   <Julien@epitech.net>
**
** Started on  Mon Feb 15 11:11:49 2016 Julien Leleu
** Last update Sun Feb 21 19:34:56 2016 Julien Leleu
*/

#include "my.h"
#include <stdlib.h>

int	allum_left(char **board)
{
  int	i;
  int	j;
  int	left;

  i = 0;
  left = 0;
  while (i != 4)
    {
      j = 0;
      while (j != 8)
	{
	  if (board[i][j] == '|')
	    left++;
	  j++;
	}
      i++;
    }
  return (left);
}

int	main()
{
  char	**board;

  board = create_the_board();
  while (allum_left(board) != 0)
    {
      display_the_board(board, 0);
      player_turn(board);
      if (allum_left(board) == 0)
	{
	  display_the_board(board, 1);
	  my_putstr("You lost, too bad..\n");
	  the_end(board);
	  return (0);
	}
      display_the_board(board, 0);
      ia_turn(board);
      if (allum_left(board) == 0)
	{
	  display_the_board(board, 1);
	  my_putstr("I lost.. snif.. but I'll get you next time!!\n");
	  the_end(board);
	  return (0);
	}
    }
  return (0);
}
