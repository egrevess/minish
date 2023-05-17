/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:06:38 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/05/15 10:06:45 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../Includes/minishell.h"

static int ft_tab_str_len(char **tab)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		size = size + j;
		i++;
	}
	return (size);
}

char *ft_sprintf(char **tab)
{
	int		i;
	int		j;
	char	*str;
	int		index;

	i = 0;
	j = 0;
	index = 0;
	if (!tab)
		return (NULL);
	str = malloc(sizeof(*str) * (ft_tab_str_len(tab) + 1));
	if (!str)
		return (NULL);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			str[index] = tab[i][j];
			j++;
			index++;
		}
		i++;
	}
	str[index] = '\0';
	return (str);
}