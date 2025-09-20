#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "../include/identification_control.h"
#include "../include/menu_control.h"

int main(void)
{
    // 현재 파일에서 최근 id 값 갱신.
    update_latest_id_from_file();

    printf("\n\n========== Start Contacts Program. ==========\n\n");

    int selection;

    while (1)
    {
        print_menu();
        menu_input(&selection);

        switch (selection)
        {
        case PRINT_CONTACTS:
            print_contacts();
            break;
        case CREATE_CONTACT:
            create_contact();
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
        default:
            puts("잘못 입력하였습니다.");
        }
    }
}