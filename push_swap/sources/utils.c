/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:40:03 by atursun           #+#    #+#             */
/*   Updated: 2025/01/17 12:40:03 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int     is_stack_sorted(t_stack *stack_a, t_layout order)
{
    while (stack_a->next)
    {
        if ((order == ASCENDING && stack_a->data > stack_a->next->data)
            || (order == DESCENDING && stack_a->data < stack_a->next->data))
            return (false);
        stack_a = stack_a->next;
    }
    return (true);
}

int     stack_size(t_stack *stack)
{
    int     counter;

    counter = 0;
    while (stack != NULL)
    {
        counter++;
        stack = stack->next;
    }
    return (counter);
}

long	ft_atol(const char *str)
{
	long		result;
	int		sign;

	sign = 1;
	result = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * sign);
}