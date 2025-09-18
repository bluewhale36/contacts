//
// Created by 우승훈 on 25. 9. 18.
//

#ifndef CONTACT_CONTROL_H
#define CONTACT_CONTROL_H

#include "contact_structor.h"

/*
	MENU_SELECTION enum 의 PRINT_CONTACTS
	모든 연락처 출력
 */
CONTACT* get_all_contacts();

/*
	MENU_SELECTION enum 의 REGISTER_CONTACT, UPDATE_CONTACT
	하나의 연락처 저장, 수정.
 */
void save_one_contact(CONTACT contact);

/*
	MENU_SELECTION enum 의 DELETE_CONTACT
	하나의 연락처 삭제.
 */
void delete_one_contact(long id);


#endif //CONTACT_CONTROL_H
