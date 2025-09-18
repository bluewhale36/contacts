//
// Created by 우승훈 on 25. 9. 18.
//

#ifndef CONTACT_CONTROL_H
#define CONTACT_CONTROL_H

#include "contact_structor.h"

typedef enum contact_status
{
	FAILED = -1,
	SUCCESS = 0,
	CREATED = 1,
	UPDATED = 2,
	DELETED = 3,
	NO_CONTACT = 4
} CONTACT_STATUS;

/*
	MENU_SELECTION enum 의 PRINT_CONTACTS
	모든 연락처 출력
 */
CONTACT_STATUS get_all_contacts(CONTACT *contacts, const int max_contacts);

/*
	MENU_SELECTION enum 의 REGISTER_CONTACT, UPDATE_CONTACT
	하나의 연락처 저장, 수정.
 */
CONTACT_STATUS save_one_contact(const CONTACT *contact);

/*
	MENU_SELECTION enum 의 DELETE_CONTACT
	하나의 연락처 삭제.
 */
CONTACT_STATUS delete_one_contact(long id);


CONTACT_STATUS deserialize_contact(CONTACT *contact, const char *str);


CONTACT_STATUS serialize_contact(const CONTACT *contact, char *str);

#endif //CONTACT_CONTROL_H
