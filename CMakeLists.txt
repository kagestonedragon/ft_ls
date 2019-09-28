cmake_minimum_required(VERSION 3.14)
project(my_ft_ls C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_EXE_LINKER_FLAGS "-L /Users/kagestonedragon/my_ft_ls/libraries/ -lft")

include_directories(includes)

add_executable(my_ft_ls
        sources/main.c
        includes/ft_ls.h
        sources/parsing/parsing_options.c
        sources/miscellaneous/ft_strchr_index.c
        sources/log/ls_log.c
        sources/parsing/parsing_input.c
        sources/parsing/parsing_entry.c
        sources/miscellaneous/get_fpath.c
        sources/put/put_input_name.c
        sources/put/put.c
        sources/parsing/parsing_directory.c
        sources/free/free.c
        sources/put/put_list.c
        sources/miscellaneous/sorting.c
        sources/put/put_detailed_list.c
        sources/miscellaneous/get_integer_length.c
        sources/put/detailed_item/put_protection.c
        sources/put/detailed_item/put_link.c
        sources/put/detailed_item/put_user_name.c
        sources/put/detailed_item/put_group_name.c
        sources/put/detailed_item/put_size.c
        sources/put/detailed_item/put_time.c
        sources/put/detailed_item/put_fname.c
        sources/parsing/parsing_input.c
        sources/put/detailed_item/put_blocks.c sources/put/get_grid.c sources/miscellaneous/get_max_name.c)