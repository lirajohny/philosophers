/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:29:46 by jlira             #+#    #+#             */
/*   Updated: 2024/04/30 14:29:10 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	int i = 0;
	printf("here %i\n", i);
	i++;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		printf("here %i\n", i);
		i++;
	}
	return (tmp);
}

t_list* create_node(t_list **head, int i)
{
    t_list* new_node;
    t_list* last;

	new_node = (t_list*)malloc(sizeof(t_list));
	if (*head != NULL)
		last = ft_lstlast(*head);
	new_node->status.number = i + 1; // philosopher number
	new_node->status.last_meal = 0; // time of last meal
	new_node->status.left_fork  = 0; 
	if (last != NULL && last->status.right_fork == 1)
		new_node->status.left_fork  = 1;
	new_node->status.right_fork  = 1;
	new_node->status.eating = 0;
	new_node->status.thinking = 0;
    new_node->prev = NULL;
    new_node->next = NULL;
    return (new_node);
}

// Função para inserir um nó no final da lista
void insert_end(t_list** head, int i)
{
    t_list* new_node;
	t_list* temp;

	new_node = create_node(head, i);
    if (*head == NULL)
        *head = new_node;
    else
	{
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void	list_init(t_list *head, t_philosophers *data, int ammount)
{
	int	i;

	i = 0;
	while (i <= ammount)
	{
		insert_end(&head ,i);
		i++;
	}
	head->status.left_fork = 1;
}
