/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:02:16 by esanchez          #+#    #+#             */
/*   Updated: 2021/10/11 17:02:17 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_tmp;
	const unsigned char	*src_tmp;

	i = 0;
	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	if (dest_tmp == NULL && src_tmp == NULL)
		return (NULL);
	if (src_tmp < dest_tmp)
		while (++i <= n)
			dest_tmp[n - i] = src_tmp[n - i];
	else
	{
		while (n--)
			*dest_tmp++ = *src_tmp++;
	}
	return (dest);
}
