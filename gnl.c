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

int	char_index(char *str, char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (i);
	return (ft_strlen(str));
}

char	*read_file(int fd, char *file)
{
	ssize_t	read_bytes;
	int		new_line_index;
	char	*buf;

	buf = malloc(sizeof(char) * (BUF_SIZE + 1));
	while (1)
	{
		read_bytes = read(fd, buf, BUF_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		else if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		file = ft_strjoin(file, buf);
	}
	free(buf);
	return (file);
}

char	*get_next_line(int fd)
{
	static t_file	file;
	char			*line;
	int				next_index;

	if (!file.file_str)
	{
		file.file_str = malloc(sizeof(char));
		file.file_str[0] = '\0';
		file.file_str = read_file(fd, file.file_str);
	}
	next_index = char_index(file.file_str + file.start, '\n');
	file.afterend = file.start + next_index;
	line = ft_substr(file.file_str, file.start, file.afterend - file.start);
	file.start = file.afterend;
	return (line);
}
