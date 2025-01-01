/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:35:19 by atursun           #+#    #+#             */
/*   Updated: 2024/10/24 10:44:52 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t num_blocks, size_t block_size)
{
	char	*str;

	if (!(str = (char *)malloc(num_blocks * block_size)))
		return (NULL);
	ft_bzero(str, num_blocks * block_size);
	return (str);
}