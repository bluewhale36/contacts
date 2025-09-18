//
// Created by 우승훈 on 9/18/25.
//
#include <stdio.h>

#include "headers/menu_control.h"
#include "headers/contact_structor.h"

void menu_input(MENU_SELECTION *selection)
{
    printf("\n메뉴를 선택하세요 >> ");
    scanf("%d", selection);
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


void print_contacts()
{

}
void register_contact()
{

}
void update_contact()
{

}
void delete_contact()
{

}