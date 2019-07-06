cmake_minimum_required(VERSION 3.14)
project(ft_ls_c C)

set(CMAKE_EXE_LINKER_FLAGS "-L ../libft -lft")

set(CMAKE_C_STANDARD 11)

add_executable(ft_ls_c tt/main.c ft_ls.h tt/reading_directories.c tt/sorting.c)