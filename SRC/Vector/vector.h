/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:01:23 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:22:05 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdlib.h>
# define RAD 0.01744

typedef	struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

t_vector		add_vector(t_vector *a, t_vector *b);
double			cos_vector(t_vector *a, t_vector *b);
double			module_vector(t_vector *a);
t_vector		mult_vector(t_vector *a, t_vector *b);
t_vector		product_vectors(t_vector *a, t_vector *b);
t_vector		scalar_vector(double c, t_vector *b);
double			dot_vector(t_vector *a, t_vector *b);
t_vector		sub_vector(t_vector *a, t_vector *b);
t_vector		*create_vector(void);
void			set_vector(t_vector *new, t_vector *set);
t_vector		division_vector(t_vector *v, double a);
t_vector		normal_vector(t_vector v);
void			construct_vector(t_vector	*v, double x, double y, double z);
void			rotation_vector(t_vector *a, t_vector *rotation);
void			anti_rotation_vector(t_vector *a, t_vector *rotation);
#endif
