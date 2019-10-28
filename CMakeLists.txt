cmake_minimum_required(VERSION 3.14)
project(untitled7)

set(CMAKE_CXX_STANDARD 17)

#add_executable(untitled7 main.c sources/ft_map.c sources/ft_sdl_run.c sources/ft_draw.c sources/ft_ui.c)
add_executable(untitled7 main.cpp quickcg.cpp)

include_directories (include/ libft/ )

find_library(SDL2 SDL2 lib)
find_library(FT ft libft)

target_link_libraries(untitled7 LINK_PUBLIC ${SDL2})
target_link_libraries(untitled7 LINK_PUBLIC ${FT})

