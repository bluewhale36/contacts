cmake_minimum_required(VERSION 3.30)
project(contacts C)

set(CMAKE_C_STANDARD 11)

add_executable(
        contacts
        main.c
        headers/menu_control.h menu_control.c
        headers/contact_structor.h contact_structor.c
        headers/contact_control.h contact_control.c
        headers/file_control.h file_control.c
)
