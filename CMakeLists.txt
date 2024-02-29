cmake_minimum_required(VERSION 3.27)
project(discrete_elastic_dynamic_model_c_language)

set(CMAKE_CXX_STANDARD 17)

include_directories("./SDL2-2.26.0-allinone/x86_64-w64-mingw32/include")
link_directories("./SDL2-2.26.0-allinone/x86_64-w64-mingw32/lib")

add_executable(discrete_elastic_dynamic_model_c_language main.cpp
        Driver/sdl2_line.cpp
        Driver/sdl2_interface.h
        Driver/sdl2_hvline.cpp
        Driver/sdl2_box.cpp
        Driver/sdl2_buffer.cpp
        Driver/sdl2_interface.cpp
        Driver/sdl2_font_buffer.cpp
        Driver/sdl2_font_buffer.h
        Driver/sdl2_font.cpp
        Driver/sdl2_circle.cpp
        Driver/driver_interface.h
)

target_link_libraries(discrete_elastic_dynamic_model_c_language PRIVATE
        mingw32
        SDL2main
        SDL2
)