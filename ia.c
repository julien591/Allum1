/*
** IA.c for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\Prog_elem\CPE_2015_Allum1
**
** Made by Julien Leleu
** Login   <Julien@epitech.net>
**
** Started on  Wed Feb 17 10:45:40 2016 Julien Leleu
** Last update Wed Feb 17 17:53:14 2016 Julien Leleu
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	message_ia(int line, int matche)
{
  my_putstr("AI removed ");
  my_put_nbr(matche);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

int	deal_with_matches_ia(char **board, int line)
{
  int	matche;

  matche = 0;
  srand(time(NULL));
  if (line == 1)
    return (1);
  while (matche < 1 || matche > 7)
    {
      matche = rand()%(8 - 1) + 1;
      if (matche >= 1 && matche <= 7)
	{
	  if (how_many(board[line - 1]) < matche)
	    matche = 0;
	}
    }
  return (matche);
}

int	deal_with_line_ia(char **board)
{
  int	line;

  line = 0;
  srand(time(NULL));
  while (line < 1 || line > 4)
    {
      line = rand()%(5 - 1) + 1;
      if (line >= 1 && line <= 4)
	{
	  if (allum_on_the_line(board[line - 1]) == 0)
	    line = 0;
	}
    }
  return (line);
}

char	**ia_turn(char **board)
{
  int	line;
  int	matche;

  my_putstr("AI's turn...\n");
  line = deal_with_line_ia(board);
  matche = deal_with_matches_ia(board, line);
  delete(board, line, matche);
  message_ia(line, matche);
  return (board);
}
