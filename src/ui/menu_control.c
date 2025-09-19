//
// Created by 우승훈 on 9/18/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "../../include/menu_control.h"
#include "../../include/contact_control.h"

void menu_input(MENU_SELECTION *selection)
{
    printf("\n메뉴를 선택하세요 >> ");
    scanf("%d", selection);
    printf("\n");
    clear_console();
}

void print_menu()
{
    printf("\n====================\n");
    printf("1. 연락처 전체보기 \t");
    printf("2. 연락처 등록하기 \t");
    printf("3. 연락처 수정하기 \t");
    printf("4. 연락처 삭제하기 \t");
    printf("0. 프로그램 중단");
    printf("\n====================\n");
}

void clear_console()
{
    system("clear");
}


void print_contacts()
{
    CONTACT contact_arr[100];

    int count = get_all_contacts(contact_arr, 100);
    if (count > 0)
    {
        printf("총 %d개의 연락처를 출력합니다. \n", count);
        puts("------------------------------------------------------");
        for (int i = 0; i < count; i++)
        {
            char buffer[200];
            contact_to_string_human_readable_buffered(&contact_arr[i], buffer, 200);
            puts(buffer);
        }
        puts("------------------------------------------------------");
    }
    else if (count == 0)
    {
        puts("저장된 연락처가 없습니다.");
    }
    else
    {
        puts("연락처를 불러오는 데 실패했습니다.");
    }
}

void register_contact()
{
    CONTACT contact;
    puts("새로운 연락처를 추가합니다.");

    printf("이름을 입력하세요 >> ");
    scanf("%s", contact.name);

    printf("나이를 입력하세요 >> ");
    scanf("%d", &contact.age);

    printf("전화번호를 숫자만 입력하세요 >> ");
    scanf("%s", contact.phone);

    printf("메모를 입력하세요 >> ");
    scanf("%s", contact.memo);

    contact.id = 100;

    char buffer[200];
    contact_to_string_buffered(&contact, buffer, 200);
    puts(buffer);

    save_one_contact(&contact);
}
void update_contact()
{

}
void delete_contact()
{

}