/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:03:40 by rhafidi           #+#    #+#             */
/*   Updated: 2024/11/28 23:25:45 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	append_to_list(t_list **list, char *buff)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = lastnode(*list);
	new_node = malloc(sizeof(t_list));

	if (!new_node)
		return (NULL);
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->save = buff;
	new_node->next = NULL;
}
void	create_list(t_list **list,int fd)
{
	char	*buffer;
	ssize_t	readbytes;
	
	while (!new_line(*list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[readbytes] = '\0';
		append_to_list(&list, buffer);
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
	t_list	*current;
	t_list	*next;

	while(*list)
	{
		if(new_line(*list))
			break;
		else
			{
				next = (*list)->next;
				(*list)->save = NULL;
				free(*list);
				*list = next;
				free(next); 
			}
		*list = (*list)->next;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, BUFFER_SIZE) < 0)
		return (NULL);
	create_list(&list, fd);
	line = get_line(&list);
	trimlist(&list);
	return (line);
}
