/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoros- <aamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:33:34 by aamoros-          #+#    #+#             */
/*   Updated: 2024/08/23 02:41:01 by aamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate(int num, char **argv, int index)
{
	index++;
	while (argv[index])
	{
		if (ft_atoi(argv[index]) == num)
			return (1);
		index++;
	}
	return (0);
}

char	**argc2(char *argv2)
{
	char	**args;

	args = ft_split(argv2, ' ');
	return (args);
}

bool	check_int(const char *num)
{
	if (num == NULL || *num == '\0')
		return (false);
	if (*num == '-' || *num == '+')
	{
		if (*(num + 1) == '\0')
			return (false);
		num++;
	}
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (false);
		num++;
	}
	return (true);
}

void	check_args(int argc, char **argv)
{
	char	**args;
	int		i;
	int		num;

	i = 1;
	if (argc < 2)
		error();
	if (argc == 2)
		args = argc2(argv[1]);
	else
		args = argv;
	while (args[i])
	{
		if (!check_int(args[i]))
			error();
		num = ft_atoi(args[i]);
		if (num < INT_MIN || num > INT_MAX || duplicate(num, args, i))
			error();
		i++;
	}
	if (argc == 2)
		free_str(args);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
