/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:02:45 by haryu             #+#    #+#             */
/*   Updated: 2021/12/09 15:16:13 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strndup(char *str, size_t n)
{
	char	*ret;

	n = (int)n;
	if (n == -1)
		n = (int)ft_strlen(str);
	ret = (char *)ft_calloc(n * sizeof(char));
	if (!ret)
	{
		str_free(ret);
		return (NULL);
	}
	ft_memmove(ret, str, n + 1);
	str_free(str);
	return (ret);
}


static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	if (!s2)
		len2 = 0;
	else
		len2 = ft_strlen(s2);
	ret = (char *)ft_calloc(len1 + len2);
	if (ret == NULL)
	{
		free(ret);
		return (NULL);
	}
	ft_memmove(ret, s1, len1);
	if (s1)
		str_free(s1);
	ft_memmove(ret + len1, s2, len2);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_str	*backup;
	char		buff[BUFFER_SIZE + 1];
	int			read_cnt;
	char		*ret;

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	backup = (t_str *)malloc(sizeof(t_str) * 1);
	if (!backup)
	{
		free(backup);
		return (NULL);
	}
	if (!backup->read_cnt)
		backup->read_cnt = BUFFER_SIZE;
	while (1)
	{
		backup->read_cnt = read(fd, buff, BUFFER_SIZE);
		if (backup->read_cnt == -1)
		{
			free(backup);
			backup = NULL;
			return (NULL);
		}
		buff[BUFFER_SIZE] = '\0';
		backup->total = ft_strjoin(backup->total, buff);

		
	}
	return (ret);
}
