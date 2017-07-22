/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:33:10 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/02/11 22:33:42 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 19000
# define ERROR -1
# define END 0
# define LINE 1
# define FD fd % 4864
# include "../../head.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

int					get_next_line(const int fd, char **line);
typedef struct		s_line
{
	char			*tmp;
	int				define;
}					t_line;
#endif
