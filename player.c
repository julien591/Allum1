/*
** player.c for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\Prog_elem\CPE_2015_Allum1
**
** Made by Julien Leleu
** Login   <Julien@epitech.net>
**
** Started on  Mon Feb 15 13:38:00 2016 Julien Leleu
** Last update Tue Mar  1 19:13:22 2016 Julien Leleu
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void	message_player(int line, int matche)
{
  my_putstr("Player removed ");
  my_put_nbr(matche);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

int	deal_with_matches_player(char **board, int line)
{
  char	*s;
  int	matche;

  s = my_read();
  if (is_num(s) == 1 || my_getnbr(s) < 0 || s[0] == '\0')
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      free (s);
      return (-1);
    }
  matche = my_getnbr(s);
  if (matche == 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      free (s);
      return (-1);
    }
  if (matche > 7 || how_many(board[line - 1]) < matche)
    {
      my_putstr("Error: not enought matches on this line\n");
      free (s);
      return (-1);
    }
  free (s);
  return (matche);
}

int	deal_with_line_player(char **board)
{
  char	*s;
  int	line;

  s = my_read();
  if (is_num(s) == 1 || my_getnbr(s) < 0 || s[0] == '\0')
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      free (s);
      return (-1);
    }
  line = my_getnbr(s);
  if (line < 1 || line > 4)
    {
      my_putstr("Error: this line is out of range\n");
      free (s);
      return (-1);
    }
  if (allum_on_the_line(board[line - 1]) == 0)
    {
      my_putstr("Error: this line is empty\n");
      free (s);
      return (-1);
    }
  free (s);
  return (line);
}

char	**player_turn(char **board)
{
  int	line;
  int	matche;

  line = -1;
  matche = -1;
  my_putstr("Your turn:\n");
  while (line == -1 && matche == -1)
    {
      my_putstr("Line: ");
      line = deal_with_line_player(board);
      if (line != -1)
	{
	  my_putstr("Matches: ");
	  matche = deal_with_matches_player(board, line);
	}
      if (matche == -1)
	line = -1;
    }
  delete(board, line, matche);
  message_player(line, matche);
  return (board);
}
