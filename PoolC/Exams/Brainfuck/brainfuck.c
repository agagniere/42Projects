/* ************************************************************************** */
/* *                                                                        * */
/* *                                                                        * */
/* *                                                                        * */
/* *                                                                        * */
/* *                                                                        * */
/* *                                                                        * */
/* *                                                                        * */
/* *                                                                        * */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char*	next(char* str, int way)
{
  int i;

  i = 0;
  while (*str)
    {
      if (*str == '[')
	i++;
      else if (*str == ']')
	i--;
      if (i == 0)
	return (str);
      str += way;
    }
}

void	brainfuck(char* str, unsigned char* buf)
{
  if (*str == '\0')
    return ;
  else if (*str == '+')
    (*buf)++;
  else if (*str == '-')
    (*buf)--;
  else if (*str == '>')
    buf++;
  else if (*str == '<')
    buf--;
  else if (*str == '.')
    write(1, buf, 1);
  else if (*str == '[' && *buf == 0)
    str = next(str, 1);
  else if (*str == ']' && *buf != 0)
      str = next(str, -1);
  brainfuck(str + 1, buf);
}

int	main(int ac, char** av)
{
  unsigned char*	buffer;
  int			i;

  if (ac > 1)
    {
      i = -1;
      buffer = (unsigned char*)malloc(2048 * sizeof(unsigned char));
      while (++i < 2048)
	buffer[i] = 0;
      brainfuck(av[1], buffer);
    }
  write(1, "\n", 1);
  return(0);
}
