/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:31:34 by prebeca           #+#    #+#             */
/*   Updated: 2024/11/12 12:42:15 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void rush(int x, int y);

int main(int argc, char *argv[])
{
    if (argc == 3) {
        rush(atoi(argv[1]), atoi(argv[2]));
    } else {
        printf("Usage: ./rush x y\n");
    }
    return 0;
}

