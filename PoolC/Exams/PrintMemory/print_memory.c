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

typedef unsigned char	t_uc;

int	is_printable(char c)
{
  return (' ' <= c && c <= '~');
}

void	aux(t_uc n, t_uc rem)
{
  char* base = "0123456789abcdef";

  if (rem > 0)
    {
      aux(n >> 4, rem - 1);
      write(1, base + n % 16, 1);
    }
}

void	print_memory(void* addr, ssize_t size)
{
  int	i;
  t_uc	*ptr;

  ptr = (t_uc*)addr;
  while (size > 0)
    {
      i = 0;
      while (i < 16 && size - i > 0)
	{
	  aux(ptr[i], 2);
	  if (i % 2)
	    write(1, " ", 1);
	  i++;
	}
      while (++i < 17)
	{
	  write(1, "  ", 2);
	  if (i % 2)
	    write(1, " ", 1);
	}
      i = -1;
      while (++i < 16 && size - i > 0)
	if (is_printable(ptr[i]))
	  write(1, ptr + i, 1);
	else
	  write(1, ".", 1);
      write(1, "\n", 1);
      size -= 16;
      ptr += 16;
    }
}

int	main(void)
{
  int	tab[10] = {0, 23, 150, 255,
		12, 16, 21, 42};

  print_memory(tab, sizeof(tab));
  return (0);
}
