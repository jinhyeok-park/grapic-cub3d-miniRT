/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:25:48 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/17 21:16:10 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
//#include "libft.h"

void    parsing(int ac, char **av)
{
    // int     fd;
    // char    *str;

    // fd = 0;
    // if (ac != 2)
    // {
    //     printf("input file error");
    //     exit(1);
    // }
    // else
    // {
    //     fd = open(av[1], O_RDONLY);
    //     if (fd > 0)
    //     {
    //         str = get_next_line(fd);
    //         int i;

    //         i = 0;
    //         while (str[i] != "\n" || str[i] != EOF || str[i] != "\0")
    //         {
    //             if (str[i] == " " || str[i] == 9)
    //                 continue;
    //             else if (ft_isalpha(str[i]))
    //             {
    //                 if (str[i] == "s" && str[i] == "p" && str[i] == " ")
    //                 {
                        
    //                 }
    //             }
    //             else 
    //                 printf("check the file");
    //         }
    //     }
    //     else
    //         printf("open error");
    // }
}
