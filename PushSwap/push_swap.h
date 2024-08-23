/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoros- <aamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:21:18 by aamoros-          #+#    #+#             */
/*   Updated: 2024/08/23 04:08:58 by aamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				push(t_stack **stack, t_stack *new);
t_stack				*pop(t_stack **stack);
void				swap(t_stack **stack);
t_stack				*rotate(t_stack **stack);
t_stack				*reverse_rotate(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				radix_sort(t_stack **a, t_stack **b);
void				sort_132(t_stack **stack_a);
void				sort_231(t_stack **stack_a);
void				sort_312(t_stack **stack_a);
void				sort_3(t_stack **stack_a);
void				sort_4(t_stack **stack_a, t_stack **stack_b);
void				sort_5(t_stack **stack_a, t_stack **stack_b);
void				simple_sort(t_stack **stack_a, t_stack **stack_b);
void				error(void);
void				free_stack(t_stack **stack);
void				free_str(char **str);
int					duplicate(int num, char **argv, int index);
char				**argc2(char *argv2);
bool				check_int(const char *num);
void				check_args(int argc, char **argv);
int					is_sorted(t_stack **stack);
int					index_distance(t_stack **stack, int target_index);
int					find_min(t_stack **stack, int exclude_val);
t_stack				*find_next_min(t_stack **stack);
void				index_stack(t_stack **a);
int					get_max_bits(t_stack **stack);
void				init_stack(t_stack **a, int argc, char **argv);
void				sort_stack(t_stack **a, t_stack **b);
int					ft_stacksize(t_stack *lst);
t_stack				*ft_stacknew(int content);
void				ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_stacklast(t_stack *lst);
int					ft_atoi(const char *str);
static int			ft_count_words(const char *str, char c);
static char			*ft_strndup(const char *s, size_t n);
static char			**ft_split_words(const char *s, char c,
						char **s2, int num_words);
char				**ft_split(const char *s, char c);
bool				ft_isdigit(int c);
void				free_split(char **str, int index);
int					ft_len(const char *s, char c, int i);
int					ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_substr(const char *s, unsigned int start, size_t len);

#endif