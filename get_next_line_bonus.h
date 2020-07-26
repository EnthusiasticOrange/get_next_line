/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 19:24:48 by mjuli             #+#    #+#             */
/*   Updated: 2020/07/27 01:30:36 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD	1024

typedef	struct	s_gnl_state
{
	int		is_initialized;
	char	buffer[BUFFER_SIZE];
	int		fd;
	ssize_t	bytes_read;
	ssize_t	offset;
	char	*line;
	size_t	size;
	int		end_found;

}				t_gnl_state;

void			gnl_state_init(t_gnl_state *state, int fd);
int				gnl_state_update(t_gnl_state *state);
int				copy_from_buf(t_gnl_state *state, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);

int				get_next_line(int fd, char **line);

#endif
