/*
** check_functions.c for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\Prog_elem\CPE_2015_Allum1
**
** Made by Julien Leleu
** Login   <Julien@epitech.net>
**
** Started on  Mon Feb 15 13:06:45 2016 Julien Leleu
** Last update Sun Feb 21 23:00:18 2016 Julien Leleu
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char	*my_read()
{
  char	buf[4096];
  char	*s;
  int	nb;
  int	i;

  i = 0;
  nb = read(0, buf, 4096);
  if (nb == 0)
    exit (84);
  s = malloc(sizeof(char) * nb);
  if (s == NULL)
    return (NULL);
  while (i < nb - 1)
    {
      s[i] = buf[i];
      i++;
    }
  s[i] = '\0';
  return (s);
}

int	is_num(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      if (str[i] == '-')
	i++;
      i++;
    }
  return (0);
}

int	allum_on_the_line(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '|')
	return (1);
      i++;
    }
  return (0);
}

int	how_many(char *str)
{
  int	i;
  int	left;

  i = 0;
  left = 0;
  while (i != 10)
    {
      if (str[i] == '|')
	left++;
      i++;
    }
  return (left);
}
