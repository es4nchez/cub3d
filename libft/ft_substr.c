/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:05:40 by esanchez          #+#    #+#             */
/*   Updated: 2021/10/11 17:05:42 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tmp = (char *)malloc(sizeof(*s) * (len + 1));
	if (!tmp)
		return (NULL);
	while (s[i])
	{
		if (len > j && start <= i)
		{
			tmp[j] = s[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}
