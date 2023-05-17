/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:00:43 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/05/16 13:24:31 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

int	ft_nb(char const *s, char c)
{
	int	i;
	int	check;
	int	count;

	i = 0;
	check = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && check == 0)
		{
			check = 1;
			count ++;
		}
		else if (s[i] == c && check == 1)
			check = 0;
		i++;
	}
	return (count);
}

char	*ft_puttab(int start, int end, char const *s, char c)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(*res) * (end - start + 2));
	if (!res)
		return (0);
	if (s[end + 1] == '\0' && s[end] != c)
		end = end + 1;
	while (start < end)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_free_return(char **tab, int limit)
{
	int	index;

	index = 0;
	while (index < limit)
		free(tab[index++]);
	free(tab);
	return (0);
}

static	int	ft_check_other(const char *s, char c, char d)
{
	int	i;
	int	quotes;
	int	two;

	i = 0;
	two = 0;
	quotes = 0;
	while (s[i])
	{
		if (s[i] == c && (two == 1 || two == 0))
		{
			if (quotes == 0)
			{
				two = 1;
				quotes = 1;
			}
			else if (quotes == 1)
			{
				two = 0;
				quotes = 0;
			}
		}
		else if (s[i] == d && (two == 2 || two == 0))
		{
			if (quotes == 0)
			{
				two = 2;
				quotes = 1;
			}
			else if (quotes == 1)
			{
				two = 0;
				quotes = 0;
			}
		}
		i++;
	}
	if (two != 0)
		return (1);
	else 
		return (0);
	
}

int	ft_malloc(char const *s, char c, char **tab, int j)
{
	int	start;
	int	check;
	int	i;
	char d;
	
	if (c == '\'')
		d = '\"';
	else 
		d = '\'';
	i = -1;
	check = 0;
	start = 0;
	if (ft_check_other(s, c, d) == 1)
		return (1);
	while (s[++i])
	{
		if ((s[i] != c) && check == 0)
		{
				check = 1;
				start = i;
				if (!s[i + 1])
					i--;
		}
		else if ((s[i] == c || !s[i + 1]) && check == 1)
		{
			check = 0;
			tab[j] = ft_puttab(start, i, s, c);
			if (!tab[j++])
				return (ft_free_return(tab, j - 1));
		}
	}
	return (0);
}

char	*ft_split_em(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (ft_nb(s, c) + 1));
	if (!tab)
		return (NULL);
	if (ft_malloc(s, c, tab, j) == 1)
		return (NULL);
	tab[ft_nb(s, c)] = NULL;
	str = ft_sprintf(tab);
	return (str);
}