/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pliniocode <pliniohrcode@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:14:41 by pliniocode        #+#    #+#             */
/*   Updated: 2023/04/11 17:01:09 by pliniocode       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

gcc -Wall -Wextra -Werror -o test ft_putchar.h test_ft_putchar.c

struct student 
{
    char name[50];
    float grd;
}

int main(void)
{
    struct student *stud_ptr, stud;
    stud_ptr = &stud;

    strcpy((*stud_ptr).name, "Structed");
    stud_ptr->grd = 6.7;
    printf("N: %s G: = %.2f\n", stud_ptr->name, stud.grd);

    return (0);
}