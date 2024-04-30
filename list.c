/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:29:46 by jlira             #+#    #+#             */
/*   Updated: 2024/04/30 13:51:09 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

t_number	*ft_lstnew(int	i)
{
	t_number	*new_node;

	new_node = (t_number *)malloc(sizeof(t_number));
	if (!new_node)
		return (NULL);
	if (i == 0)
		new_node->left = NULL;
	else
		new_node->right->left = new_node;
	new_node->number = i + 1;
	new_node->last_meal = 0;
	new_node->left_fork  = 0;
	new_node->right_fork  = 1;
	new_node->eating = 0;
	new_node->thinking = 0;
	new_node->right = NULL;
	return (new_node);
}


t_list* create_node(t_list **head, int i)
{
    t_list* new_node;
    t_list* last;

	new_node = (t_list*)malloc(sizeof(t_list));
	last = lst_last(head);
	new_node->status.number = i + 1;
	new_node->status.last_meal = 0;
	new_node->status.left_fork  = 0;
	if (last.status.right_fork == 1)
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

void	list_init(t_philosophers *data, t_number *status, int ammount)
{
	int	i;
	t_list	*head;
	i = 0;
	while (i < ammount)
	{
		insert_end(&head ,i);
		i++;
	}
}
