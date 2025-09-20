//
// Created by 우승훈 on 9/18/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "../../include/menu_control.h"

#include <string.h>

#include "../../include/contact_control.h"

void clear_read_buffer()
{
    while (getchar() != '\n');
}

void menu_input(int *selection)
{
    printf("\n메뉴를 선택하세요 >> ");

    scanf("%d", selection);

    printf("\n");

    // 콘솔 클리어
    clear_console();
    // 입력 버퍼 지우기
    clear_read_buffer();
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
    // system("cls");      // Windows
    system("clear");    // MacOS
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
            char buffer[FILE_LINE_MAX_LENGTH];
            contact_to_string_human_readable_buffered(&contact_arr[i], buffer, FILE_LINE_MAX_LENGTH);
            puts(buffer);
            // 동적 메모리 할당 해제
            free_contact_member(&contact_arr[i]);
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

void create_contact()
{
    CONTACT_CREATOR creator;

    printf("이름을 입력하세요: ");
    fgets(creator.name, sizeof(creator.name), stdin);
    creator.name[strcspn(creator.name, "\n")] = '\0';

    printf("나이를 입력하세요: ");
    fgets(creator.age, sizeof(creator.age), stdin);
    creator.age[strcspn(creator.age, "\n")] = '\0';

    printf("전화번호를 숫자만 입력하세요: ");
    fgets(creator.phone, sizeof(creator.phone), stdin);
    creator.phone[strcspn(creator.phone, "\n")] = '\0';

    printf("메모를 입력하세요(선택사항): ");
    fgets(creator.memo, sizeof(creator.memo), stdin);
    creator.memo[strcspn(creator.memo, "\n")] = '\0';

    if (save_one_contact(&creator) == CONTACT_FAILED)
    {
        fprintf(stderr, "Error Occurred while Saving New Contact. \n");
    }
    else
    {
        puts("\n연락처가 저장되었습니다.");
    }
}
void update_contact()
{

}
void delete_contact()
{

}