//
// Created by 우승훈 on 9/18/25.
//

#ifndef CONTACTS_STRUCTOR_H
#define CONTACTS_STRUCTOR_H

#include <stdlib.h>
#define FILE_LINE_MAX_LENGTH 200 // 파일 한 줄당 최대 길이 (예상)

typedef struct contact
{
    unsigned long id;		// 연락처 식별자
    char *name;				// 이름
    unsigned short age;		// 나이
    char *phone;			// 전화번호
    char *memo;				// 메모
} CONTACT;

/**
 *
 * @param contact 문자열로 볼 CONTACT
 * @param buffer 문자열 버퍼
 * @param size 버퍼 사이즈
 */
void contact_to_string_buffered(const CONTACT *contact, char *buffer, size_t size);

/**
 * 실제 콘솔에 출력될 CONTACT 의 문자열
 * @param contact 연락처 데이터
 * @param buffer 문자열 버퍼
 * @param size 버퍼 사이즈
 */
void contact_to_string_human_readable_buffered(const CONTACT *contact, char *buffer, size_t size);

/**
 * 연락처 저장 또는 갱신 시 표준 입력에서 받는 내용을 전달 받는 struct.
 */
typedef struct contact_creator
{
	char name[31];		// 이름
	char age[4];		// 나이
	char phone[15];		// 전화번호
	char memo[51];		// 메모
} CONTACT_CREATOR;

/**
 * 디버깅 용 toString 함수
 * @param contact 문자열로 볼 CONTACT_CREATOR
 * @param buffer 입력 버퍼
 * @param size 버퍼 길이
 */
void contact_creator_to_string(const CONTACT_CREATOR *contact, char *buffer, size_t size);

void free_contact_member(CONTACT *contact);

#endif //CONTACTS_STRUCTOR_H
