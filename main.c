#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "headers/menu_control.h"

int main(void)
{
    printf("\n\n========== Start Contacts Program. ==========\n\n");

    MENU_SELECTION selection;

    while (1)
    {
        print_menu();
        menu_input(&selection);

        switch (selection)
        {
        case PRINT_CONTACTS:
            print_contacts();
            break;
        case REGISTER_CONTACT:
            puts("register contact");
            break;
        case UPDATE_CONTACT:
            puts("update contact");
            break;
        case DELETE_CONTACT:
            puts("delete contact");
            break;
        case EXIT_PROGRAM:
            puts("Exiting...");
            return 0;
        }
    }
}