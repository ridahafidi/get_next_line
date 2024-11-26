/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:03:56 by rhafidi           #+#    #+#             */
/*   Updated: 2024/11/26 22:55:43 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char	*save;
	struct s_list *next;
}t_list;

void delete (void *s);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstnew(char *save);
char				*get_next_line(int fd);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif
#endif