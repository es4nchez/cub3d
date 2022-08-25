/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:01:44 by esanchez          #+#    #+#             */
/*   Updated: 2021/10/11 17:07:04 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*temp;
	const char	*temp2;

	temp = dest;
	temp2 = src;
	if (temp == NULL && temp2 == NULL)
		return (NULL);
	while (n--)
		*temp++ = *temp2++;
	return (dest);
}
