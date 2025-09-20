cmake_minimum_required(VERSION 3.30)
project(contacts C)

set(CMAKE_C_STANDARD 11)

add_executable(
        contacts
        src/main.c
        include/menu_control.h src/ui/menu_control.c
        include/contact_structor.h src/model/contact_structor.c
        include/contact_control.h src/service/contact_control.c
        include/file_control.h src/persistence/file_control.c
        include/input_validation.h
        include/identification_control.h src/service/identification_control.c
)
