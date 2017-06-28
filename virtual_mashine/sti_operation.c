//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_sti_func(t_car *car)
{

	car->op_tabble.nb_tours--;
}



void    do_sti_func(t_vm *main_struct, t_car *car)
{
	int map_pos;

	map_pos = car->pos + (car->args[1].value + car->args[2].value) % MEM_SIZE;
	if (car->args[0].name == T_REG && car->args[0].value > 0)
	{
		put_int_on_map(main_struct->map + map_pos, car->reg[car->args[0].value - 1],
					   main_struct->color + map_pos, car->color);
	}
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos++;
		return ;
	}
	if (car->reg[car->args[2].value - 1] == 0 && car->carry == 0 &&
		car->args[2].name == 1)
		car->carry = 1;
	else if (car->reg[car->args[2].value - 1] != 0 && car->carry == 1 &&
			 car->args[2].name == 1)
		car->carry = 0;
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
	if (car->data)
		ft_memdel(&(car->data));
}
