//
// Created by 우승훈 on 25. 9. 18.
//

#include "headers/contact_control.h"
#include <string.h>
#include "headers/file_control.h"

/*
	MENU_SELECTION enum 의 PRINT_CONTACTS
	모든 연락처 출력
 */
CONTACT_STATUS get_all_contacts(CONTACT *contacts, const int max_contacts)
{
	const FILE_CONTROL_RESULT file_control_result = open_file("r");
	if (file_control_result.status == ERROR)
	{
		return FAILED;
	}
	if (file_control_result.status == OPENED_AS_NEW_FILE)
	{
		return NO_CONTACT;
	}

	FILE *rfp = file_control_result.fp;
	for (int i = 0; i < max_contacts; i++)
	{
		char str[200];
		fgets(str, 200, rfp);

		if (feof(rfp))
		{
			break;
		}

		CONTACT contact;
		deserialize_contact(&contact, str);
		contacts[i] = contact;
	}
}

/*
	MENU_SELECTION enum 의 REGISTER_CONTACT, UPDATE_CONTACT
	하나의 연락처 저장, 수정.
 */
CONTACT_STATUS save_one_contact(const CONTACT *contact)
{

}

/*
	MENU_SELECTION enum 의 DELETE_CONTACT
	하나의 연락처 삭제.
 */
CONTACT_STATUS delete_one_contact(long id)
{

}

CONTACT_STATUS deserialize_contact(CONTACT *contact, const char *str)
{
	char given_str[200];
	strcpy(given_str, str);

	char *token = strtok(given_str, ";");

	contact -> id = strtol(token, NULL, 0);
	token = strtok(NULL, ";");

	strcpy(contact -> name, token);
	token = strtok(NULL, ";");

	contact -> age = atoi(token);
	token = strtok(NULL, ";");

	strcpy(contact -> phone, token);
	token = strtok(NULL, ";");

	strcpy (contact -> memo, token != NULL ? token : "");

	return SUCCESS;
}


CONTACT_STATUS serialize_contact(const CONTACT *contact, char *str)
{

}