/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:16:40 by moabid            #+#    #+#             */
/*   Updated: 2022/11/27 17:16:42 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

struct s_map	*ft_lstnew_map(void *content)
{
	struct s_map	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->line = content;
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_back_map(struct s_map **alst, struct s_map *new)
{
	struct s_map	*tmp;

	tmp = *alst;
	if (*alst == NULL)
		*alst = new;
	else
		(ft_lstlast_map(*alst))->next = new;
}

void	ft_lstclear_map(struct s_map **lst)
{
	struct s_map	*tmp;
	struct s_map	*next;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

int	ft_lstsize_map(struct s_map *lst)
{
	struct s_map	*tmp;
	int				i;

	i = 0;
	if (!lst)
		return (i);
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	**map_list_create(struct s_map *lst)
{
	struct s_map	*tmp;
	int				i;
	int				j;
	char			**tab;

	tmp = lst;
	tab = ft_malloc(sizeof(char *) * (ft_lstsize_map(lst) + 1));
	i = 0;
	while (i < ft_lstsize_map(lst))
	{
		tab[i] = malloc(sizeof(char) * (ft_strlen(tmp->line) + 1));
		if (!tab[i])
			return (NULL);
		j = 0;
		while (tmp->line[j] != '\0')
		{
			tab[i][j] = tmp->line[j];
			j++;
		}
		tab[i][j] = '\0';
		tmp = tmp->next;
		i++;
	}
	return (tab);
}
