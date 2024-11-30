/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:20:53 by rhafidi           #+#    #+#             */
/*   Updated: 2024/11/30 18:34:27 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char	*save;
	struct s_list *next;
}t_list;

int	new_line(t_list *list);
void	free_malloc(t_list **list, t_list *newnode, char *buff);
t_list	*findlastnode(t_list *list);
size_t	length_to_newline (t_list *list);
void	copy_the_line(char *line, t_list *list);
char	*get_next_line(int fd);
int		is_newline(char c);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#endif