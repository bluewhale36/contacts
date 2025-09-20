//
// Created by 우승훈 on 9/18/25.
//

#ifndef MENU_CONTROL_H
#define MENU_CONTROL_H

typedef enum menu_selection
{
    PRINT_CONTACTS = 1,
    CREATE_CONTACT,
    UPDATE_CONTACT,
    DELETE_CONTACT,
    EXIT_PROGRAM = 0
} MENU_SELECTION;

void menu_input(int *selection);
void print_menu();
void clear_console();

/*
    각 enum 에 대응되는 함수
*/
void print_contacts();
void create_contact();
void update_contact();
void delete_contact();

#endif //MENU_CONTROL_H
