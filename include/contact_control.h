//
// Created by 우승훈 on 25. 9. 18.
//

#ifndef CONTACT_CONTROL_H
#define CONTACT_CONTROL_H

#include "contact_structor.h"

typedef enum contact_status
{
	TOO_SMALL_BUFFER = -3,
	UNSUPPORTED_PHONE_NUMBER = -2,
	FAILED = -1,
	SUCCESS = 0,
	CREATED = 1,
	UPDATED = 2,
	DELETED = 3,
	NO_CONTACT = 4
} CONTACT_STATUS;

extern const char phone_start_number_middle_is_4[][5];
extern const char phone_start_number_middle_is_3[][5];

/**
모든 연락처를 파일에서 읽어옵니다.
@return 성공 시 읽어온 연락처의 개수, 실패 시 -1
 */
int get_all_contacts(CONTACT *contacts, const int max_contacts);

/*
	MENU_SELECTION enum 의 REGISTER_CONTACT, UPDATE_CONTACT
	하나의 연락처 저장, 수정.
 */
CONTACT_STATUS save_one_contact(const CONTACT *contact);

/*
	MENU_SELECTION enum 의 DELETE_CONTACT
	하나의 연락처 삭제.
 */
CONTACT_STATUS delete_one_contact(const CONTACT *contact);

/**
 * 문자열을 역직렬화 하여 CONTACT 에 값을 대입.
 * @param contact 문자열에서 변환될 CONTACT 메모리 주소
 * @param str 파일의 문자열
 * @return
 */
CONTACT_STATUS deserialize_contact(CONTACT *contact, const char *str);

/**
 * CONTACT 를 직렬화하여 문자열에 값을 대입.
 * @param contact 직렬화할 CONTACT
 * @param str 직렬화된 값이 대입되는 문자열 메모리 주소
 * @return
 */
CONTACT_STATUS serialize_contact(const CONTACT *contact, char *str);

CONTACT_STATUS add_hyphen_to_phone_str(const char *phone_str, char *hyphened_buffer, const size_t buffer_size);

#endif //CONTACT_CONTROL_H
