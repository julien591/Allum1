/*
** my.h for my.h in /home/leleu_j/rendu/Piscine_C_J09/include
**
** Made by leleu julien
** Login   <leleu_j@epitech.net>
**
** Started on  Thu Oct  8 14:37:09 2015 leleu julien
** Last update Sun Feb 21 19:35:06 2016 Julien Leleu
*/

#ifndef	READ_SIZE
# define READ_SIZE (50)
#endif /* !READ_SIZE */

#ifndef		MY_H_
# define	MY_H_
void	my_putstr(char *str);
void	my_putchar(char c);
char	*my_strcpy(char *dest, char *src);
int	my_getnbr(char *str);
char	**create_the_board();
void	display_the_board( char **board, int choice);
char	**player_turn(char **board);
int	is_num(char *str);
int	allum_on_the_line(char *str);
char	*my_read();
int	how_many(char *str);
char	**delete(char **board, int line, int nb_matches);
void	my_put_nbr(int nb);
char	**ia_turn(char **board);
void	the_end(char **board);
#endif /* !MY_H_ */
