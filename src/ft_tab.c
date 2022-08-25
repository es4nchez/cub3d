/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:29:32 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/25 22:29:36 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	concat_tab(char ***tab, char *newstr)
{
	char	**newtab;
	int		len;

	len = 0;
	while (*tab != NULL && (*tab)[len] != NULL)
		len++;
	newtab = malloc(sizeof(char *) * (len + 2));
	if (newtab == NULL)
		return (ERROR);
	len = 0;
	while (*tab != NULL && (*tab)[len] != NULL)
	{
		newtab[len] = (*tab)[len];
		len++;
	}
	newtab[len] = newstr;
	newtab[len + 1] = NULL;
	if (*tab != NULL)
		free(*tab);
	*tab = newtab;
	return (SUCCESS);
}

int	tab_len(char **tab)
{
	int	len;

	len = 0;
	while (tab != NULL && tab[len] != NULL)
		len++;
	return (len);
}

int	free_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab != NULL && tab[len] != NULL)
	{
		free(tab[len]);
		len++;
	}
	free(tab);
	return (SUCCESS);
}
