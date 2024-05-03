/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:29:46 by jlira             #+#    #+#             */
/*   Updated: 2024/05/03 14:39:59 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	ft_free(t_list **list)
{
	t_list	*current;
	t_list	*next;

	current = *list;
	while (current != NULL)
	{
		next = current->next;
		//free(current->content);
		free(current);
		current = next;
	}
	list = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	int i = 0;
	i++;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

t_list* create_node(t_list **head, int i)
{
    t_list* new_node;
    t_list* last;

	last = NULL;
	new_node = (t_list*)malloc(sizeof(t_list));
	if (!new_node)
		ft_free(&new_node);
	if (*head != NULL)
		last = ft_lstlast(*head);
	new_node->status.number = i + 1; // philosopher number
	new_node->status.last_meal = 0; // time of last meal
	new_node->status.left_fork  = 0; 
	if (last != NULL)
	{
		if (last->status.right_fork == 1)
			new_node->status.left_fork  = 1;
	}
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

t_list	*list_init(t_list *head, t_philosophers *data, int ammount)
{
	int	i;

	i = 0;
	while (i < ammount)
	{
		insert_end(&head ,i);
		printf(">>>>>>>>>>>> \t >>> created %i\n", i + 1);
		i++;
	}
	head->status.left_fork = 1;
}
