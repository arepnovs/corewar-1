//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_sub_func(t_car *car)
{
	//car->data = ft_memdup(4, map, (*pos) + 1);
    car->c_for_op = 9;
    car->pos = car->pos + 5;
    ft_printf ("-> зчитали інструкцію і її аргументи SUB = %s\n");
}



void    do_sub_func(t_vm *main_struct, t_car *car)
{
    car->op_type = 0;
    ft_printf("SUB!!!!!\n");
}