
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:14:47 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/18 16:58:22 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "mlx.h"

#define ORIGIN (t_point){10, 10}

typedef union	u_point
{
	int			matrix[2];
	struct
	{
		int		x;
		int		y;
	}			coord;
	struct
	{
		int		width;
		int		height;
	}			dim;
}				t_point;

typedef struct	s_work
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pixel;
	t_point		win_dim;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_work;

void	destroy(t_work *w)
{
	mlx_destroy_image(w->mlx, w->img);
	mlx_destroy_window(w->mlx, w->win);
}

void	repaint(t_work *w)
{
	for (int i = 0 ; i < 200 ; i++)
		w->pixel[(i/10) * w->line_size + i % 10 ] = 100;
}

int		key_hook(int keycode, void *param)
{
	t_work *w = param;

	printf("Key Pressed : %i\n", keycode);
	repaint(w);
	return (0);
}

int		expose_hook(void *param)
{
	t_work *w = param;

	mlx_clear_window(w->mlx, w->win);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (0);
}

int		init(t_work *w)
{
	int status;
	w->win_dim = (t_point){150, 100};

	printf("----- Initialising -----\n"); fflush(stdout);
	if (fork())
	{
		if ((w->mlx = mlx_init())) {
			printf("Mlx Successfully Created : %p\n", w->mlx); fflush(stdout);
		} else
			return (1);
		exit(0);
	}
	wait(&status);
	if (status)
		return (-1);

	if (!(w->win = mlx_new_window(w->mlx, w->win_dim.dim.width,
		w->win_dim.dim.height, "Wow Much Coolness")))
		return (2);
	printf("Win Created\n"); fflush(stdout);

	if (!(w->img = mlx_new_image(w->mlx,
		w->win_dim.dim.width - 10, w->win_dim.dim.height - 5)))
		return (3);
	printf("Img Created\n"); fflush(stdout);

	if (!(w->pixel = mlx_get_data_addr(w->img, &(w->bits_per_pixel),
		&(w->line_size), &(w->endian))))
		return (4);
	printf("Pixel Created\n"); fflush(stdout);

	printf("Expose hook : %i\n", mlx_expose_hook(w->win, &expose_hook, &w));
	printf("Key Hook : %i\n", mlx_key_hook(w->win, &key_hook, &w));
	return (0);
}

int		main(int ac, char **av)
{
	t_work	w;
	int		status;

	if (fork())
	{
		printf("Init : %i\n", init(&w));
		exit(0);
	}
	wait(&status);
	if (status)
		printf("Initialisation failed : %i\n", status);
	mlx_loop(w.mlx);
	destroy(&w);
	return (0);
}
