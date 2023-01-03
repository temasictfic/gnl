/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:55:20 by sciftci           #+#    #+#             */
/*   Updated: 2022/12/30 17:13:30 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

#ifndef BUF_SIZE
 # define BUF_SIZE 64
#endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_file
{
	char	*file_str;
	int		start;
}			t_file;

size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);

#endif
