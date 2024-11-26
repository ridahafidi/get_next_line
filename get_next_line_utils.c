/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:03:47 by rhafidi           #+#    #+#             */
/*   Updated: 2024/11/26 22:15:52 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *save)
{
	t_list	*root;

	root = malloc(sizeof(t_list));
	if (root == NULL)
		return (NULL);
	root->save = save;
	root->next = NULL;
	return (root);
}
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->save);
	free(lst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
void delete (void *s)
{
	free(s);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;
	char	*stro;

	len = 0;
	while(s[len])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	stro = str;
	while (len)
	{
		*stro = *s;
		stro++;
		s++;
		len--;
	}
	*stro = '\0';
	return (str);
}
