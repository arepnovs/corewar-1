/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:35:49 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:35:51 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_ldi_func(t_car *car)
{
	car->op_tabble.nb_tours--;
}

int		get_correct_ind(int mark)
{
	int k;

	if (mark == MEM_SIZE)
		mark = 0;
	else
	{
		if (mark > MEM_SIZE)
		{
			k = mark / (MEM_SIZE);
			mark = mark % (k * (MEM_SIZE));
		}
		else if (mark < 0)
		{
			k = (mark / (-MEM_SIZE)) + 1;
			mark = mark + k * (MEM_SIZE);
		}
	}
	return (mark);
}

void	do_ldi_func(t_vm *main_struct, t_car *car)
{
	int mark;

	mark = car->pos + car->args[0].value + car->args[1].value;
	if (mark < 0 || mark > MEM_SIZE - 1)
		mark = get_correct_ind(mark);
	if (car->args[2].name == T_REG && car->args[2].value > 0 &&
			car->args[2].value <= REG_NUMBER && car->args_error)
	{
		car->reg[car->args[2].value - 1] = get_int_from_byte_code(
				main_struct->map + mark);
	}
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos + car->arg_size + 2;
		return ;
	}
	if (car->reg[car->args[2].value - 1] == 0 && car->carry == 0)
		car->carry = 1;
	else if (car->reg[car->args[2].value - 1] != 0 && car->carry == 1)
		car->carry = 0;
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
	fix_car_pos(car);
}
