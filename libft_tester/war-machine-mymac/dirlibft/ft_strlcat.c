/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:44:09 by haryu             #+#    #+#             */
/*   Updated: 2021/11/22 15:40:46 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *restrict dst, \
		const char *restrict src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	ret;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= dstsize)
		ret = srclen + dstsize;
	else
	{
		i = 0;
		while (i < (dstsize - dstlen - 1))
		{
			if (srclen == 0)
				break ;
			*(char *)(dst + dstlen + i) = *(char *)(src + i);
			i++;
			if (*(char *)(src + i) == '\0')
				break ;
		}
		*(char *)(dst + dstlen + i) = '\0';
		ret = dstlen + srclen;
	}
	return (ret);
}
