/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:43:05 by viburton          #+#    #+#             */
/*   Updated: 2023/02/21 14:59:28 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void put_head(void)
{
    //police : ANSi SHADOW
    write(1,"\n██████╗ ██╗   ██╗██████╗ ████████╗ ██████╗ ███╗   ██╗    ███████╗██╗  ██╗███████╗██╗     ██╗     \n\
██╔══██╗██║   ██║██╔══██╗╚══██╔══╝██╔═══██╗████╗  ██║    ██╔════╝██║  ██║██╔════╝██║     ██║     \n\
██████╔╝██║   ██║██████╔╝   ██║   ██║   ██║██╔██╗ ██║    ███████╗███████║█████╗  ██║     ██║     \n\
██╔══██╗██║   ██║██╔══██╗   ██║   ██║   ██║██║╚██╗██║    ╚════██║██╔══██║██╔══╝  ██║     ██║     \n\
██████╔╝╚██████╔╝██║  ██║   ██║   ╚██████╔╝██║ ╚████║    ███████║██║  ██║███████╗███████╗███████╗\n\
╚═════╝  ╚═════╝ ╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═══╝    ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n\n\
", 1475);
}