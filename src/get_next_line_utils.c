/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:44:24 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/01 15:44:24 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gstrlen(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_gstrjoin(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_gstrlen(s1);
	s2len = ft_gstrlen(s2);
	ptr = malloc(s1len + s2len + 1);
	if (ptr != NULL)
	{
		ft_gstrlcpy(ptr, s1, s1len + 1);
		ft_gstrlcpy(ptr + s1len, s2, s2len + 1);
	}
	free(s1);
	free(s2);
	return (ptr);
}

size_t	ft_strchr_int(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_gsubstr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (len > ft_gstrlen(s) - start)
		len = ft_gstrlen(s) - start;
	if (start > ft_gstrlen(s))
		len = 0;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len && start < ft_gstrlen(s))
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

size_t	ft_gstrlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_gstrlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
