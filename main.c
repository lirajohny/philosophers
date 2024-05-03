/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:48:11 by jlira             #+#    #+#             */
/*   Updated: 2024/05/03 14:40:49 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	start_simulation(t_list *head, t_philosophers *data)
{
	printf("simulation\n");
	t_list *ptr = head;

	while (ptr != NULL)
	{
		printf ("|| %i [p%i] %i ", ptr->status.left_fork, ptr->status.number, ptr->status.right_fork);
		ptr = ptr->next;
	}

	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		t_philosophers	data;
		t_list			*head;	

		head = NULL;
		gettimeofday(&data.time_start, NULL);
		data.start = data.time_start.tv_sec * 1000; // sec * 1000 = milisec
		data.how_many = ft_atoi(av[1]);
		data.forks = ft_atoi(av[1]);
		data.eat = ft_atol(av[3]);
		data.sleep = ft_atol(av[4]);
		if (ac == 6)
			data.rounds = ft_atoi(av[5]);
		// init list
		head = list_init(head, &data, data.how_many);
		start_simulation(head, &data);
		free(head);
	}
	else
	{
		printf("usage: ./%s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", av[0]);
	}
}
