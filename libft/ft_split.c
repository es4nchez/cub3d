/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:03:20 by esanchez          #+#    #+#             */
/*   Updated: 2021/10/11 17:03:23 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_splitnbr(char *s, char c)
{
	int		i;
	int		j;
	int		splits;

	i = 0;
	j = 0;
	splits = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c && i == 0)
		{
			splits++;
			i = 1;
		}
		else if (i == 1 && s[j] == c)
			i = 0;
		j++;
	}
	return (splits);
}

int	ft_linelen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

void	*ft_linefree(char **temp, int i)
{
	while (i > 0)
	{
		free(temp[i]);
		i--;
	}
	free(temp);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		splnbr;
	char	**temp;

	i = 0;
	splnbr = ft_splitnbr((char *)s, c);
	if (!s)
		return (NULL);
	temp = (char **)malloc(sizeof(char *) * (ft_splitnbr((char *)s, c) + 1));
	if (!temp)
		return (NULL);
	while (splnbr--)
	{
		while (*s != '\0' && *s == c)
			s++;
		temp[i] = ft_substr((char *)s, 0, ft_linelen((char *)s, c));
		if (!temp[i])
			return (ft_linefree(temp, i));
		s = s + ft_linelen((char *)s, c);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}
