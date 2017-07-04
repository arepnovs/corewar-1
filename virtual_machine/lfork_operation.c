/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:36:02 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:36:04 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_lfork_func(t_car *car)
{
	car->op_tabble.nb_tours--;
}

void	do_lfork_func(t_vm *main_struct, t_car *car)
{
	int dist;
	int arg_size;
	int i;

	i = 0;
	arg_size = car->op_tabble.codage_octal == 0 ? DIR_SIZE : IND_SIZE;
	dist = get_short_from_byte_code(main_struct->map + car->pos + 1,
									car->op_tabble.codage_octal);
	while (i < main_struct->players_nbr)
	{
		if (car->index == i)
			main_struct->players[i]->car = create_new_car(
					main_struct->players[i]->car, car, dist, main_struct);
		i++;
	}
	car->op_tabble.opcode = 0;
	car->pos = car->pos + arg_size + 1;
	fix_car_pos(car);
}
