/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:03:40 by rhafidi           #+#    #+#             */
/*   Updated: 2024/11/26 23:36:17 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	len_counter(t_list *save_buff)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (save_buff)
	{
		i = 0;
		while (save_buff->save[i] && save_buff->save[i] != '\n')
			i++;
		len += i;
		if (save_buff->save[i] == '\n')
		{
			len++;
			break ;
		}
		else
			save_buff = save_buff->next;
	}
	return (len);
}

t_list	*append_to_list(t_list **save_buff, char *buffer)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->save = ft_strdup(buffer);
	if (!new_node->save)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	if (!(*save_buff))
	{
		*save_buff = new_node;
		return (new_node);
	}
	current = (*save_buff);
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (*save_buff);
}

char	*fill_line(char *tmp_line, size_t len, t_list **save_buff)
{
	t_list	*tmp_save;
	size_t	i;
	size_t	j;
	
	i = 0;
	while ((*save_buff)->save)
	{
		j = 0;
		while ((*save_buff)->save[j] != '\0' && len >= 0)
		{
			tmp_line[i] = (*save_buff)->save[j];
			len--;
			j++;
			i++;
		}
		if (!ft_strchr((*save_buff)->save, '\n'))
		{
			tmp_save = (*save_buff)->next;
			ft_lstdelone(*save_buff, &delete);
			(*save_buff) = tmp_save;
		}
		else
		{
			ft_lstdelone(tmp_save, &delete);
		}
		if ((*save_buff)->save[j] == '\n')
			break ;
		tmp_save = (*save_buff);
	}
	return (tmp_line);
}

char	*extract_line(t_list **save_buff)
{
	char	*line;
	size_t	len;

	len = len_counter(*save_buff);
	if (len)
	{
		line = malloc(sizeof(char) * (len + 1));
		if (!line)
			return (NULL);
		line[len] = '\0';
		len--;
		line = fill_line(line, len, save_buff);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buffer;
	ssize_t			readbytes;
	static t_list	*save_buff;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((readbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[readbytes] = '\0';
		save_buff = append_to_list(&save_buff, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (readbytes < 0 || (!readbytes && !save_buff))
		return (NULL);
	line = extract_line(&save_buff);
	return (line);
}
