/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:59:42 by esanchez          #+#    #+#             */
/*   Updated: 2021/10/11 16:59:45 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*temp;

	i = ft_intlen(n);
	nb = n;
	temp = malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (temp == NULL)
		return (NULL);
	if (nb < 0)
	{
		temp[0] = '-';
		nb = nb * -1;
	}
	while (nb > 9)
	{
		temp[i - 1] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	temp[i - 1] = nb + 48;
	temp[ft_intlen(n)] = '\0';
	return (temp);
}
