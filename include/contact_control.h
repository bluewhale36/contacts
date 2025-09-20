//
// Created by 우승훈 on 25. 9. 18.
//

#ifndef CONTACT_CONTROL_H
#define CONTACT_CONTROL_H

#include "contact_structor.h"

typedef enum contact_status
{
	NO_CONTACT = -4,
	TOO_SMALL_BUFFER = -3,
	UNSUPPORTED_PHONE_NUMBER = -2,
	CONTACT_FAILED = -1,
	CONTACT_SUCCESS = 0,
	CONTACT_CREATED = 1,
	CONTACT_UPDATED = 2,
	CONTACT_DELETED = 3,
} CONTACT_STATUS;

extern const char phone_start_number_middle_is_4[][5];
extern const char phone_start_number_middle_is_3[][5];


/**
 * 파일에서 max_contacts 만큼의 연락처를 조회하여 출력.<br/>
 * 호출 위치에서 각 CONTACT 요소에 대해 free_contact_members(contact) 함수 실행 필요.
 * @param contacts CONTACT 배열
 * @param max_contacts 한번에 최대로 가져올 연락처 개수
 * @return
 */
int get_all_contacts(CONTACT *contacts, const int max_contacts);

/**
 * 인자로 받은 CONTACT_CREATOR 에 대해 연락처를 파일에 저장.<br/>
 * 구현 위치에서 CONTACT 를 생성한 후, free_contact_members(contact) 함수 실행 필요.
 * @param contact_creator 표준 입력 데이터를 받은 CONTACT_CREATOR
 * @return
 */
CONTACT_STATUS save_one_contact(const CONTACT_CREATOR *contact_creator);

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

/**
 * CONTACT_CREATOR 의 데이터를 CONTACT 에 저장시키는 함수
 * @param contact 데이터가 저장될 CONTACT
 * @param contact_creator 값을 가지고 있는 CONTACT_CREATOR
 * @return CONTACT 에 데이터 저장 성공 시 0 반환. 실패 시 -1 반환.
 */
CONTACT_STATUS contact_from_creator(CONTACT *contact, const CONTACT_CREATOR *contact_creator);

#endif //CONTACT_CONTROL_H
