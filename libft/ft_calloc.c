/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:58:26 by esanchez          #+#    #+#             */
/*   Updated: 2021/10/11 16:58:29 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int	*unic_ptr;

	unic_ptr = malloc(nmemb * size);
	if (!unic_ptr)
		return (NULL);
	ft_bzero(unic_ptr, size * nmemb);
	return (unic_ptr);
}
