/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 19:23:16 by mjuli             #+#    #+#             */
/*   Updated: 2020/07/27 01:02:18 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		copy_from_buf(t_gnl_state *state, size_t len)
{
	char	*new_line;

	if (!(new_line = malloc(state->size + len + 1)))
	{
		if (state->line != NULL)
			free(state->line);
		state->line = NULL;
		state->size = 0;
		return (0);
	}
	if (state->line != 0)
	{
		ft_memcpy(new_line, state->line, state->size);
		free(state->line);
	}
	ft_memcpy(new_line + state->size, state->buffer + state->offset, len);
	state->line = new_line;
	state->size += len;
	state->offset += len;
	state->line[state->size] = '\0';
	return (1);
}

char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*ret_str;

	size = ft_strlen(s) + 1;
	ret_str = (char *)malloc(size);
	if (ret_str)
		ft_memcpy(ret_str, s, size);
	return (ret_str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src_p;
	char		*dst_p;

	dst_p = dest;
	src_p = src;
	while (n--)
		*dst_p++ = *src_p++;
	return (dest);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void*)p);
		p++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
