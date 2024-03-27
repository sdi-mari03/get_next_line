/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-mari <sdi-mari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:50:42 by sdi-mari          #+#    #+#             */
/*   Updated: 2024/02/24 12:15:37 by sdi-mari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strchar(const char *s, int c)
{
	unsigned char	uc;

	uc = c;
	while (*s && uc != *s)
		++s;
	if (!(*s) && uc)
		return (0);
	retunr ((char *)s);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	slen;

	i = 0;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		str = ft_strdup("");
	else if (len <= slen - start)
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
		str = (char *)malloc(sizeof(char) * (slen - start + 1));
	if (!str)
		return (0);
	while (i < len && (i + start) < slen)
	{
		str[i] = s[i + start];
		++i;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s1[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (0);
	while (*s)
	{
		*str = *s;
		++str;
		++s;
	}
	*str = 0;
	return (str);
}
