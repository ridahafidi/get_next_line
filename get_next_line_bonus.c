/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:20:47 by rhafidi           #+#    #+#             */
/*   Updated: 2024/12/01 15:26:08 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	append_to_list(t_list **list, char *buff)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = findlastnode(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->save = buff;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	char	*buffer;
	ssize_t	readbytes;

	while (!new_line(*list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[readbytes] = '\0';
		append_to_list(list, buffer);
	}
}

char	*get_line(t_list **list)
{
	size_t	line_length;
	char	*line;

	line_length = length_to_newline(*list);
	line = malloc(sizeof(char) * (line_length + 1));
	if (!line)
		return (NULL);
	line[line_length] = '\0';
	copy_the_line(line, *list);
	return (line);
}

void	trimlist(t_list **list)
{
	t_list	*lastnode;
	t_list	*newnode;
	char	*buff;
	int		i;
	int		j;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	newnode = malloc(sizeof(t_list));
	if (!buff || !newnode)
		return ;
	lastnode = findlastnode(*list);
	i = 0;
	j = 0;
	while (lastnode->save[i] && lastnode->save[i] != '\n')
		i++;
	i++;
	while (lastnode->save[i])
		buff[j++] = lastnode->save[i++];
	buff[j] = '\0';
	newnode->save = buff;
	newnode->next = NULL;
	free_malloc(list, newnode, buff);
}

char	*get_next_line(int fd)
{
	static t_list	*list[1024];
	char			*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&list[fd], fd);
	if (!list[fd])
		return (NULL);
	line = get_line(&list[fd]);
	trimlist(&list[fd]);
	return (line);
}
