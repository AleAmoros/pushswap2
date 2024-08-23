/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoros- <aamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:40:50 by aamoros-          #+#    #+#             */
/*   Updated: 2024/08/23 16:07:01 by aamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

void	free_split(char **str, int index)
{
	while (index-- > 0)
		free(str[index]);
	free(str);
}

int	ft_len(const char *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[j] && s[j] != c)
	{
		j++;
		i++;
	}
	return (j);
}

char	**ft_split(const char *s, char c)
{
	char	**s2;
	int		i;
	int		j;

	i = 0;
	j = -1;
	s2 = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!s2)
		return (NULL);
	while (++j < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		s2[j] = ft_substr(s, i, ft_len(s, c, i));
		if (!s2[j])
		{
			free_split(s2, j);
			return (NULL);
		}
		i += ft_len(s, c, i);
	}
	s2[j] = 0;
	return (s2);
}

bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
