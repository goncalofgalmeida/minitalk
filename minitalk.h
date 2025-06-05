/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:24:06 by g24force          #+#    #+#             */
/*   Updated: 2025/06/05 20:53:16 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "./libft/libft.h"
#include <signal.h>

typedef struct s_server_state
{
	int		len_recieved;
	int		client_status;
	int		current_bits;
	int		bit_index; // delete??
	int		msg_length;
	char	character; // delete??
	char	*message;
	__pid_t	client_pid; // delete??

}	t_server_state;

// file.c


#endif