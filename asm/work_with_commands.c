/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 09:12:35 by okres             #+#    #+#             */
/*   Updated: 2017/07/05 09:14:27 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	g_size[] = {4, 4, 0, 0, 0, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4};
int g_codage_octal[] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1};

void	fill_name_and_comment(t_asm *head)
{
	int i;

	i = 0;
	while (head->comm[i])
	{
		head->header->comment[i] = head->comm[i];
		i++;
	}
	i = 0;
	while (head->name[i])
	{
		head->header->prog_name[i] = head->name[i];
		i++;
	}
}

void	write_codage_octal(t_asm *begin, int fd)
{
	int		i;
	char	op_b;

	i = 0;
	op_b = 0;
	while (i < begin->amount_of_args)
	{
		if (begin->what_args[i] == T_REG)
			op_b = (op_b << 2) + REG_CODE;
		else if (begin->what_args[i] == T_DIR)
			op_b = (op_b << 2) + DIR_CODE;
		else if (begin->what_args[i] != 0)
			op_b = (op_b << 2) + IND_CODE;
		i++;
	}
	op_b = (op_b <= 0x3 ? op_b << 2 : op_b);
	op_b = (op_b <= 0xF ? op_b << 2 : op_b);
	op_b <<= 2;
	if (ft_strcmp(begin->command, "ld") == 0 && begin->opcode == 2
			&& begin->args && begin->args[0] != NULL
			&& ft_strcmp(begin->args[0], "deflv") == 0)
		op_b = '\xd0';
	write(fd, &op_b, 1);
}

int		write_ind(int fd, char *arg, t_t type)
{
	int tmp;

	while ((*arg < 48 || *arg > 57) && *arg != '-')
		arg++;
	if (type == IND)
	{
		tmp = ft_atoi(arg);
		tmp = do_big_endian(tmp, 2);
		write(fd, &tmp, 2);
		return (2);
	}
	else
		tmp = ft_atoi(arg);
	write(fd, &tmp, 1);
	return (1);
}

int		find_lable(t_asm *begin, char *lable, int val_cur)
{
	t_asm	*node;
	int		res;

	node = begin;
	res = 0;
	while (node)
	{
		if (node->label && ft_strcmp(node->label, lable) == 0)
		{
			if (node->program_s >= val_cur)
				return (node->program_s - val_cur);
			else
				return (MAX_SHORT_INT + 1 - (val_cur - node->program_s));
		}
		node = node->next;
	}
	return (res);
}

void	write_op_code(t_asm *head, t_asm *begin, int op_c, int fd)
{
	int			i;
	static int	val_cur;
	int			val_tmp;

	val_tmp = 1;
	i = 0;
	head->cur_size = g_size[op_c - 1];
	head->cur_codage_octal = g_codage_octal[op_c - 1];
	write(fd, &op_c, 1);
	if (head->cur_codage_octal && ++val_tmp)
		write_codage_octal(begin, fd);
	while (i < begin->amount_of_args)
	{
		if (begin->what_args[i] == T_REG)
			val_tmp += write_ind(fd, begin->args[i], REG);
		else if (begin->what_args[i] == T_DIR)
			val_tmp += write_dir(val_cur, head, i, begin);
		else if (begin->what_args[i] != 0)
			val_tmp += write_ind(fd, begin->args[i], IND);
		i++;
	}
	val_cur += val_tmp;
}
