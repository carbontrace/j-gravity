/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:07:49 by smifsud           #+#    #+#             */
/*   Updated: 2017/05/04 14:33:10 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <math.h>

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_body
{
	double		mass;
	t_vector	position;
	t_vector	velocity;
}				t_body;

typedef struct	s_node
{
	t_body		*bodies;
	s_node		**children;
	s_node		*parent;
	size_t		start;
	size_t		end;
}				t_octant;

typedef struct	s_bounds
{
	double		xmax;
	double		xmin;
	double		ymax;
	double		ymin;
	double		zmax;
	double		zmin;
}				t_bounds;

t_octant		*octree_divide(t_octant *root);

size_t			array_len(void *ptr, size_t datasize);
int64_t			parsenbodies(char *buf);

double			finddist(t_vector pos);

int				compare_positions(const void *b1, const void *b2);
t_body			*sortbodies(t_body *bodies);
t_body			*getbodies(int fd, int64_t nbodies);

char			*barnes_hut(t_octant *root);

#endif
