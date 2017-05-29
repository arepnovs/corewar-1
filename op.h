//
// Created by Anton Repnovskyi on 5/22/17.
//

#ifndef COREWAR_OP_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#define COREWAR_OP_H

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3
#define MAX_INT                 2147483647

typedef struct		header_s
{
    unsigned int		magic;
    char				prog_name[PROG_NAME_LENGTH + 1];
    unsigned int		prog_size;
    char				comment[COMMENT_LENGTH + 1];
}					header_t;

typedef struct      s_asm
{
    char            *file_name;
    char            *name;
    char            *comm;
    char            *lable;
    int             only_lable;
    int             opcode;
    int             command_num;
    char            *command;
    int             amount_of_args;
    char            what_args[3];
    int             l_flag[3];
    char            **args;
    int             bin[8];
    char            hexa[4];
    int             carry;
    int             c_oct;
    int             cycles;
    int             label_size;
    struct s_asm    *next;
}                   t_asm;

typedef struct s_op
{
    char *command;
    int args_am;
    char args[3];
    int opcode;
    int cycles;
    int oct;
} t_op;

t_asm *new_asm();
void				get_shit(t_asm *start, char *line);
void				ft_exit(int flag);
void				to_byte_code(t_asm *head);


#endif //COREWAR_OP_H

/*static t_op g_op_tab[17] = {
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
};*/