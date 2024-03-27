/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-mari <sdi-mari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:10:20 by sdi-mari          #+#    #+#             */
/*   Updated: 2024/03/27 16:01:23 by sdi-mari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_handle_nl(char *str_result)
{
	int		i;
	char	*new_line;

	i = 0;
	while (str_result[i] != '\0' && str_result[i] != '\n')
		++i;
	if (str_result[i] == '\0')
		return (0);
	new_line = ft_substr(str_result, i + 1, ft_strlen(str_result) - 1);
	if (*new_line == '\0')
	{
		free(new_line);
		new_line = 0;
	}
	while (str_result[++i])
		str_result[i] = '\0';
	return (new_line);
}

static char	*ft_str_read(int fd, char *str_read, char *str_buff)
{
	int		nbytes;
	char	*temp;

	nbytes = 1;
	while (nbytes != '\0')
	{
		nbytes = read(fd, str_read, BUFFER_SIZE);
		if (nbytes == -1);
			return (0);
		else if (nbytes > 0)
		{
			str_read[nbytes] = '\0';
			if (!str_buf)
				str_buf = ft_strdup("")
			temp = str_buf;
			str_buf = ft_strjoin(temp, str_read);
			free(temp);
		}
		if (nbytes == 0 || ft_strchr(str_read, '\n'))
			nbytes = '\0';
	}
	return (str_buff);
}

char	*get_next_line(int fd)
{
	static char	*str_buff[4096];
	char		*str_read;
	char		*str_result;

	if (fd < 0 || fd >= 4096 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (0);
	str_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_read)
		return (0);
	str_result = ft_str_read(fd, str_read, str_buff[fd]);
	fd(str_read);
	str_read = 0;
	if (!str_result)
		return (0);
	str_buff[fd] = ft_handle_nl(str_result);
	return (str_result);
}
