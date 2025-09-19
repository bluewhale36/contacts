//
// Created by 우승훈 on 25. 9. 18.
//

#include "../../include/contact_control.h"
#include <string.h>
#include "../../include/file_control.h"


int get_all_contacts(CONTACT *contacts, const int max_contacts)
{
	const FILE_CONTROL_RESULT res = open_file("r");
	if (res.status == ERROR)
	{
		return -1;
	}
	if (res.status == OPENED_AS_NEW_FILE)
	{
		close_file(res.fp);
		return 0;
	}

	FILE *rfp = res.fp;
	int i = 0;
	for (; i < max_contacts; i++)
	{
		char str[200];
		if (fgets(str, 200, rfp) == NULL)
		{
			break;
		}

		deserialize_contact(&contacts[i], str);
	}
	close_file(rfp);
	return i;
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