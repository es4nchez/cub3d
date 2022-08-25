/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:05:10 by esanchez          #+#    #+#             */
/*   Updated: 2021/10/11 17:05:12 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j] && (i + j) < n)
		{
			if (j == (ft_strlen(s2) - 1))
				return ((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
