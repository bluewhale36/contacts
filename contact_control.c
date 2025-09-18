//
// Created by 우승훈 on 25. 9. 18.
//

#include "headers/contact_control.h"
#include "headers/file_control.h"

/*
	MENU_SELECTION enum 의 PRINT_CONTACTS
	모든 연락처 출력
 */
CONTACT* get_all_contacts()
{
	FILE_CONTROL_RESULT file_control_result = open_file("r");
	if (file_control_result.fp == NULL)
	{
		return NULL;
	}
	if (file_control_result.status == OPENED_WITH_CREATION)
	{
		printf("저장된 연락처가 없습니다.");
	}

	char str[150] = "";
	FILE *rfp = file_control_result.fp;
	for (int i = 1; ; i++)
	{
		fgets(str, 150, rfp);

		if (feof(rfp))
		{
			break;
		}

	}
}

/*
	MENU_SELECTION enum 의 REGISTER_CONTACT, UPDATE_CONTACT
	하나의 연락처 저장, 수정.
 */
void save_one_contact(CONTACT contact)
{

}

/*
	MENU_SELECTION enum 의 DELETE_CONTACT
	하나의 연락처 삭제.
 */
void delete_one_contact(long id)
{

}