/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoros- <aamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:22:45 by aamoros-          #+#    #+#             */
/*   Updated: 2024/08/23 00:08:38 by aamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	size_t	i;
	t_stack	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp ->next;
		i++;
	}
	return (i);
}

t_stack	*ft_stacknew(int content)
{
	t_stack	*i;

	i = (t_stack *)malloc(sizeof(t_stack));
	if (!i)
		return (NULL);
	i->value = content;
	i->index = -1;
	i->next = NULL;
	return (i);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lastadd;

	if (*lst)
	{
		lastadd = ft_stacklast(*lst);
		lastadd->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
	}
}

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
