/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoros- <aamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:55:32 by aamoros-          #+#    #+#             */
/*   Updated: 2024/08/23 18:40:13 by aamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = index_distance(stack_a, find_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int	i;

	if (is_sorted(a) || ft_stacksize(*a) == 1 || ft_stacksize(*a) == 0)
		return ;
	i = ft_stacksize(*a);
	if (i == 2)
		sa(a);
	else if (i == 3)
		sort_3(a);
	else if (i == 4)
		sort_4(a, b);
	else if (i == 5)
		sort_5(a, b);
}

void ft_print_stack(t_stack *stack)
{
	t_stack *head = stack;
	while (head)
	{
		printf("%d\n", head->value);
		head = head->next;
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int		i;
	int		j;
	int		max_bits;
	int		size;
	t_stack	*head;

	i = 0;
	max_bits = get_max_bits(a);
	size = ft_stacksize(*a);
	head = *a;
	ft_print_stack(*a);
	ft_print_stack(*b);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head = *a;
			if (((head->value >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (ft_stacksize(*b) != 0)
			pa(a, b);
		i++;
	}
}
