/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoros- <aamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:21:58 by aamoros-          #+#    #+#             */
/*   Updated: 2024/08/22 01:18:23 by aamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	a = (t_stack **)malloc(sizeof(t_stack));
	init_stack(a, argc, argv);
	if (is_sorted(a) == 1)
		exit(0);
	b = (t_stack **)malloc(sizeof(t_stack));
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
