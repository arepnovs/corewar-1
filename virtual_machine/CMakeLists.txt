cmake_minimum_required(VERSION 3.7)
project(virtual_mashine)

set(CMAKE_CXX_STANDARD 11)

find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )

set(SOURCE_FILES
        libft/ft_printf/check_nbr.c
        libft/ft_printf/check_type.c
        libft/ft_printf/ft_atoi_mod.c
        libft/ft_printf/ft_itoa_base.c
        libft/ft_printf/ft_itoa_d.c
        libft/ft_printf/ft_itoa_p.c
        libft/ft_printf/ft_list.c
        libft/ft_printf/ft_modlst.c
        libft/ft_printf/ft_nbrlen_base.c
        libft/ft_printf/ft_printf.c
        libft/ft_printf/ft_printf.h
        libft/ft_printf/ft_putstr_len.c
        libft/ft_printf/ft_round.c
        libft/ft_printf/help_check_type.c
        libft/ft_printf/help_mod_m_flag.c
        libft/ft_printf/mod_a.c
        libft/ft_printf/mod_and_print.c
        libft/ft_printf/mod_char.c
        libft/ft_printf/mod_double.c
        libft/ft_printf/mod_g.c
        libft/ft_printf/mod_i_d.c
        libft/ft_printf/mod_m_flag.c
        libft/ft_printf/mod_n.c
        libft/ft_printf/mod_r.c
        libft/ft_printf/mod_str.c
        libft/ft_printf/mod_unsigned.c
        libft/ft_printf/mod_void.c
        libft/ft_printf/processing_wint_t.c
        libft/ft_printf/read_str.c
        libft/ft_atoi.c
        libft/ft_atoi_move.c
        libft/ft_bzero.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lentoc.c
        libft/ft_lstadd.c
        libft/ft_lstadd_back.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_lstprint_str.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_nbrlen.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_array.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strsplit_lst.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/get_next_line.c
        libft/get_next_line.h
        libft/libft.h
        corewar.c
        create_players.c
        live_operation.c
        read_player_file.c
        run_operation.c
        start_battle.c
        move_carr_and_do_operations.c
        live_operation.c
        ld_operation.c
        st_operation.c
        add_operation.c
        sub_operation.c
        and_operation.c
        or_operation.c
        xor_operation.c
        error.c
        vm.h
        get_op_code.c
        zjmp_operation.c
        ldi_operation.c
        sti_operation.c
        fork_operation.c
        lld_operation.c
        lldi_operation.c
        lfork_operation.c
        aff_operation.c
        get_flags.c
        create_map.c
        operations_with_car.c
        ../op.c
        get_args_and_value.c
        visualisation.c
        visualisation.h
        put_int_on_map.c
        visualisate.c
        w_print_memory.c
        w_print_param.c
        w_print_usage.c
        put_caret_on_map.c get_args_and_values_part_2.c dump_memory.c time.c check_if_refresh.c read_commands.c create_windows.c usage.c get_args_and_values_part_3.c)
add_executable(virtual_mashine ${SOURCE_FILES})
target_link_libraries( virtual_mashine ${CURSES_LIBRARIES} )
