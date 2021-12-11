/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:23:40 by haryu             #+#    #+#             */
/*   Updated: 2021/12/10 16:33:08 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (len-- > 0 && tmp_dst)
			*tmp_dst++ = *tmp_src++;
		*tmp_dst = '\0';
	}
	else
	{
		*(tmp_dst + len) = '\0';
		while (len-- && tmp_dst)
			*(tmp_dst + len) = *(tmp_src + len);
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//문장 전체를 지울 땐 head 부터싹 free
//fd 단일만 정리 되었을 시 하나만 free
//내부 일부만 프리가 필요할 때
