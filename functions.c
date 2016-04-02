/*
** functions.c for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\Prog_elem\CPE_2015_Allum1
**
** Made by Julien Leleu
** Login   <Julien@epitech.net>
**
** Started on  Wed Feb 10 11:58:41 2016 Julien Leleu
** Last update Mon Feb 15 14:37:47 2016 Julien Leleu
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_getnbr(char *str)
{
  int	sign;
  int	result;

  sign = 1;
  result = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	sign = - sign;
      str = str + 1;
    }
         while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      if (result > 214748364)
	return (0);
      if (result == 214748364 && *str > 7 && sign == 1)
	return (0);
      if (result == 214748364 && *str > 8 && sign == -1)
	return (0);
      result = result * 10 + *str - 48;
      str = str + 1;
    }
  if (sign == -1)
           result = - result;
  return (result);
}

char	*my_strcpy(char *dest, char *src)
{
  int i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

void	my_put_nbr(int nb)
{
  int result;
  int diviseur;

  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb = -nb;
	}
      diviseur = 1;
      while ((nb/diviseur) >= 10)
	diviseur = diviseur * 10;
      while (diviseur > 0)
	{
	  result = (nb/diviseur) % 10;
	  my_putchar(48 + result);
	  diviseur = diviseur / 10;
	}
    }
}
