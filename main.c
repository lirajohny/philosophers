/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:48:11 by jlira             #+#    #+#             */
/*   Updated: 2024/04/30 13:09:11 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	main(int ac, char **av)
{
	if (ac == 4 || ac == 5)
	{
		t_philosophers	data;
		t_number		status;
		struct	timeval	start;
	
		gettimeofday(&start, NULL);
		printf("start: %li\n", start.tv_sec);
		data.start = start.tv_sec * 1000; // sec * 1000 = milisec
		printf("data.start: %li\n", data.start);
		data.how_many = ft_atoi(av[1]);
		printf("data.how_many: %i\n", data.how_many);
		data.forks = ft_atoi(av[1]);
		printf("data.forks: %i\n", data.forks);
		data.die = ft_atol(av[2]);
		printf("data.die: %li\n", data.die);
		data.eat = ft_atol(av[3]);
		printf("data.eat: %li\n", data.eat);
		data.sleep = ft_atol(av[4]);
		printf("data.sleep: %li\n", data.sleep);
		if (ac == 5)
			data.rounds = ft_atoi(av[5]);
		// init list
		list_init(&data, &status, data.how_many);


	}
	else
	{
		printf("usage: ./%s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", av[0]);
	}
}
