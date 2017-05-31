//
// Created by Yevhen Yefimov on 5/26/17.
//

#include "op.h"

t_player *add_player(int i, int n_bots)
{
    t_player    *new;

    new = (t_player *)malloc(sizeof(t_player));
    new->car = (t_car *)malloc(sizeof(t_car));
    new->name = -i;
    new->car->pos = ((MEM_SIZE * 2 / n_bots) * (i - 1));
    new->car->nb = 0;
    new->car->op_type = 0;
    new->car->c_for_op = 0;
    new->next = NULL;
    new->car->next = NULL;
    return (new);
}

void    put_car(char *map, int n_bots)
{
    t_player    *p_list;
    t_player    *ptr;
    int         i;

    p_list = add_player(1, n_bots);
    ptr = p_list;
    i = 2;
    while (i <= n_bots)
    {
        p_list->next = add_player(i, n_bots); // ????????? ??????, ?????????? ???? ?????, ????????? ???????? ??????? ??? ??????? ?????? ? ??????????? ?? ?? ?????? ???39??? ????B ??-??-??-??
        p_list = p_list->next;
        i++;
    }
    show_players_and_cars(ptr); // додаткова функцыя
    start_battle(ptr, map); // початок битви .....
}