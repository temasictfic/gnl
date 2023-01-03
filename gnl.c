/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:55:03 by sciftci           #+#    #+#             */
/*   Updated: 2022/12/30 17:14:23 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t	next_line_index(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (ft_strlen(str));
}

char	*read_file(int fd, char *file)
{
	ssize_t	read_bytes;
	char	*buf;


	file = malloc(sizeof(char));
	file[0] = '\0';
	buf = malloc(sizeof(char) * (BUF_SIZE + 1));
	while (1)
	{
		read_bytes = read(fd, buf, BUF_SIZE);
		if (read_bytes <= 0)
		{
			if (read_bytes == -1)
				file = NULL;
			break ;
		}
		buf[read_bytes] = '\0';
		file = ft_strjoin(file, buf);
	}
	free(buf);
	return (file);
}

char	*get_next_line(int fd)
{
	static char		*file;
	char			*next_line;
	size_t			next_index;

	if (!file)
		file = read_file(fd, file);
	next_index = next_line_index(file);
	next_line = ft_substr(file, 0, next_index);
	file += next_index;
	return (next_line);
}
