//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_sti_func(t_car *car)
{

	//car->data = ft_memdup(6, map, (*pos) + 1);
	car->c_for_op = 24;
	car->pos = car->pos + 7;
	ft_printf ("-> read STI instruction, data\n");
}



void    do_sti_func(t_vm *main_struct, t_car *car)
{
	car->op_type = 0;
	ft_printf("!!!!!STI!!!!!\n");
}
