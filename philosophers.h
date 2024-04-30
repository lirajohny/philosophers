/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:48:06 by jlira             #+#    #+#             */
/*   Updated: 2024/04/30 14:00:12 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHISOLOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philosophers
{
	int		how_many; // how many philosophers on the table
	int		forks; // ammount of forks
	int		rounds; // rounds passed
	long	start;
	long	sleep; // time_to_sleep : will speel X miliseconds
	long	die; // time_to_die : he will die if do not eat in this period
	long	eat; // time_to_eat : takes X miliseconds to eat
} t_philosophers;

typedef struct	s_number
{
	int	number;
	long	last_meal; // when he has eaten for the last time? if time_to_die is greater he dies;
	int	left_fork; // is the left fork on the table?   0 or 1
	int	right_fork; // is the right fork on the table   0 or 1
	int	eating; // is he eating?  0 or 1
	int thinking; // is the whinking? == waiting   0 or 1
	struct s_number	*left;
	struct s_number	*right;
} t_number;

typedef struct s_list {
    t_number	status;
    struct s_list *prev;
    struct s_list *next;
} t_list;
// main.c 

// utils.c
int		ft_atoi(const char *nptr);
double	ft_atol(char *s);
void	list_init(t_list *head, t_philosophers *data, int ammount);

/*
  struct timeval {
               time_t      tv_sec;     // sec
               suseconds_t tv_usec;    // microseconds
           };
*/
#endif

