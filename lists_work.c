//
// Created by Anton Repnovskyi on 5/24/17.
//

#include "op.h"

t_op 		*init_tab(void) {
    static t_op g_op_tab[17] = {
            {"live",  1, {T_DIR},                                               1,  10,   0},
            {"ld",    2, {T_DIR | T_IND,         T_REG},                        2,  5,    1},
            {"st",    2, {T_REG, T_IND | T_REG},                                3,  5,    1},
            {"add",   3, {T_REG, T_REG, T_REG},                                 4,  10,   1},
            {"sub",   3, {T_REG, T_REG, T_REG},                                 5,  10,   1},
            {"and",   3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6,  6,    1},
            {"or",    3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7,  6,    1},
            {"xor",   3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8,  6,    1},
            {"zjmp",  1, {T_DIR},                                               9,  20,   0},
            {"ldi",   3, {T_REG | T_DIR | T_IND, T_DIR | T_REG,         T_REG}, 10, 25,   1},
            {"sti",   3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},         11, 25,   1},
            {"fork",  1, {T_DIR},                                               12, 800,  0},
            {"lld",   2, {T_DIR | T_IND,         T_REG},                        13, 10,   1},
            {"lldi",  3, {T_REG | T_DIR | T_IND, T_DIR | T_REG,         T_REG}, 14, 50,   1},
            {"lfork", 1, {T_DIR},                                               15, 1000, 0},
            {"aff",   1, {T_REG},                                               16, 2,    1},
            {0,       0, 0, 0,  0,    0}
    };
    return(g_op_tab);
}

t_asm *new_asm()
{
    t_asm *new;

    new = (t_asm *)malloc(sizeof(t_asm));
    new->file_name = ft_strnew(0);
    new->name = ft_strnew(0);
    new->comm = ft_strnew(0);
    new->lable = ft_strnew(0);
    new->carry = 98;
    new->c_oct = 0;
    new->label_size = 0;
    new->next = NULL;
    return (new);
}

char    *get_lable(char *line)
{
    int i;
    int len;
    char dupline[100];
    char *label;

    i = 0;
    len = 0;
    ft_strcpy(dupline, line);
    while (dupline[len] != ':')
        len++;
    if (dupline[len] == '\0' || dupline[len - 1] == '%')
        return(NULL);
    else
    {
        label = (char *)malloc(sizeof(char) * len);
        dupline[len] = '\0';
        ft_strcpy(label, dupline);
    }
    return(label);
}

char *get_command(char *line, t_op *g_tab) {
    int i;
    int len;
    char *command;

    i = 15;
    len = 0;
    while (i >= 0)
    {
        if (ft_strstr(line, g_tab[i].command) != 0)
        {
            command = (char *)malloc(sizeof(char) * 6);
            ft_strcpy(command, g_tab[i].command);
            return(command);
        }
        i--;
    }
    ft_exit(0);
}

char    **get_args(char *line, t_asm *start, t_op *g_tab)
{

}

void    get_shit(t_asm *start, char *line)
{
    t_op *g_tab;

    g_tab = init_tab();
    start->lable = get_lable(line);
    start->command = get_command(line, g_tab);
    start->args = get_args(line, start, g_tab);


}