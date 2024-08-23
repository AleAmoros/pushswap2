/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoros- <aamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:26:47 by aamoros-          #+#    #+#             */
/*   Updated: 2024/08/23 03:00:46 by aamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_132(t_stack **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	rra(stack_a);
}

void	sort_231(t_stack **stack_a)
{
	t_stack	*head;
	int		min_index;

	head = *stack_a;
	min_index = find_min(stack_a, -1);
	if (head->next->index == min_index)
		sa(stack_a);
	else
		rra(stack_a);
}

void	sort_312(t_stack **stack_a)
{
	t_stack	*head;
	int		min_index;

	head = *stack_a;
	min_index = find_min(stack_a, -1);
	if (head->next->index == min_index)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*head;
	int		min_index;
	int		next_min_index;

	head = *stack_a;
	min_index = find_min(stack_a, -1);
	next_min_index = find_min(stack_a, min_index);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min_index && head->next->index != next_min_index)
		sort_132(stack_a);
	else if (head->index == next_min_index)
		sort_231(stack_a);
	else
		sort_312(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = index_distance(stack_a, find_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
}
