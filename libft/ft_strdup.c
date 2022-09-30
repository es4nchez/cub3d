/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:03:37 by esanchez          #+#    #+#             */
/*   Updated: 2021/10/11 17:03:38 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*temp;

	i = -1;
	temp = malloc(ft_strlen(s) + 1);
	if (temp == NULL)
		return (NULL);
	while (s[++i] != '\0')
		temp[i] = s[i];
	temp[i] = '\0';
	return (temp);
}
