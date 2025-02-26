/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:39:22 by ismherna          #+#    #+#             */
/*   Updated: 2025/02/26 12:40:33 by ismherna         ###   ########.fr       */
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