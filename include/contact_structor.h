//
// Created by 우승훈 on 9/18/25.
//

#ifndef CONTACTS_STRUCTOR_H
#define CONTACTS_STRUCTOR_H
#include <stdlib.h>

typedef struct contact
{
    long id;        // 연락처 식별자
    char name[30];  // 이름
    int age;        // 나이
    char phone[15]; // 전화번호
    char memo[51];  // 메모
} CONTACT;

/*
	CONTACT struct 값을 문자열로 반환.
*/
void contact_to_string_buffered(const CONTACT *contact, char *buffer, size_t size);

/**
 * 실제 콘솔에 출력될 CONTACT 의 문자열
 * @param contact
 * @param buffer
 * @param size
 */
void contact_to_string_human_readable_buffered(const CONTACT *contact, char *buffer, size_t size);


#endif //CONTACTS_STRUCTOR_H
