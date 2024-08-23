/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoros- <aamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:12 by aamoros-          #+#    #+#             */
/*   Updated: 2024/08/23 17:54:10 by aamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_distance(t_stack **stack, int target_index)
{
	t_stack	*current;
	int		distance;

	if (!*stack || !stack)
		return (-1);
	current = *stack;
	distance = 0;
	while (current)
	{
		if (current->index == target_index)
			return (distance);
		distance++;
		current = current->next;
	}
	return (-1);
}

int	find_min(t_stack **stack, int exclude_val)
{
	t_stack	*current;
	int		min;

	if (!*stack || !stack)
		return (0);
	current = *stack;
	min = current->index;
	while (current)
	{
		if (current->index < min && current->index != exclude_val)
			min = current->index;
		current = current->next;
	}
}

t_stack	*find_next_min(t_stack **stack)
{
	t_stack	*current;
	t_stack	*min;

	if (!*stack || !stack)
		return (0);
	current = *stack;
	min = NULL;
	while (current)
	{
		if (current->index == -1 && (!min || current->value < min->value))
			min = current;
		current = current->next;
	}
}

void	index_stack(t_stack **a)
{
	t_stack	*min_node;
	int		index;

	if (!*a || !a)
		return ;
	index = 0;
	min_node = find_next_min(a);
	while (min_node)
	{
		min_node->index = index++;
		min_node = find_next_min(a);
	}
}

int	get_max_bits(t_stack **stack)
{
	t_stack	*current;
	int		max;
	int		max_bits;

	if (!stack || !*stack)
		return (0);
	current = *stack;
	max = current->index;
	max_bits = 0;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
