/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:20:11 by jlira             #+#    #+#             */
/*   Updated: 2024/04/30 12:22:31 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosophers.h"

double	ft_atol(char *s)
{
	long	nbr;
	double	pow;
	int		sign;

	nbr = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		nbr = (nbr * 10) + (*s++ - 48);
	return (nbr * sign);
}
