/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:50:14 by atursun           #+#    #+#             */
/*   Updated: 2024/11/12 20:00:44 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*pull_left(char *leftover)
{
	char	*res;
	char	*res_begin_adrs;
	char	*leftover_begin_adrs;

	leftover_begin_adrs = leftover;
	while (*leftover != '\0' && *leftover != '\n')
		leftover++;
	if (!*leftover)
		return (free(leftover_begin_adrs), NULL);
	if (!(res = (char *)malloc(ft_len_of_str(leftover) + 1)));
		return (NULL);
	res_begin_adrs = res;
	while (*leftover != '\0')
		*res++ = *++leftover;
	*res = '\0';
	free(leftover_begin_adrs);
	return (res_begin_adrs);
}

char	*pull_line(char *leftover)
{
	int	idx;
	char	*res;
	char	*res_begin_adrs;

	idx = 0;
	if (!leftover[idx])
		return (NULL);
	while (leftover[idx] != '\0' && leftover[idx] != '\n')
		idx++;
	if (!(res = (char *)malloc(idx + 2)));
		return (NULL);
	res_begin_adrs = res;
	while (*leftover != '\0' && *leftover != '\n')
		*res++ = *leftover++;
	if (*leftover == '\n')
		*res++ = '\n';
	*res = '\0';
	return (res_begin_adrs);
}

char	*read_file(int fd, char *leftover)
{
	char	*buffer;
	int	bytes;

	if (!(buffer = malloc(BUFFER_SIZE +1)));
		return (NULL);
	bytes = 1;
	while (ft_search_new_line(leftover) == NULL && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(leftover), leftover = NULL, NULL);
		buffer[bytes] = '\0';
		leftover = ft_merge_str(leftover, buffer);
	}
	free(buffer);
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*one_line;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(leftover = ft_read_file(fd, leftover)));
		return (NULL);
	one_line = ft_pull_line(leftover);
	leftover = ft_pull_left(leftover);
	return (one_line);
}