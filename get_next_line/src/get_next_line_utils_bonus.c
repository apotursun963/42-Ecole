/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:16:30 by atursun           #+#    #+#             */
/*   Updated: 2024/11/12 20:05:40 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	len_of_str(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*search_new_line(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*merge_str(char *leftover, char *buffer)
{
	char	*assemble;
	char	*assemble_begin_adrs;
	char	*leftover_begin_adrs;

	if (!leftover)
	{
		leftover = malloc(1);
		leftover[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	if (!(assemble = malloc(ft_len_of_str(leftover) + ft_len_of_str(buffer) + 1)));
		return (NULL);
	leftover_begin_adrs = leftover;
	assemble_begin_adrs = assemble;
	while (*leftover)
		*assemble++ = *leftover++;
	while (*buffer)
		*assemble++ = *buffer++;
	*assemble = '\0';
	free(leftover_begin_adrs);
	return (assemble_begin_adrs);
}