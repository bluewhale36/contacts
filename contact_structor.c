//
// Created by 우승훈 on 25. 9. 18.
//

#include "headers/contact_structor.h"
#include <stdio.h>
#include <stdlib.h>

void contact_to_string_buffered(const CONTACT *contact, char *buffer, size_t size)
{
	// snprintf를 사용해 전달받은 버퍼에 안전하게 문자열을 씁니다.
	snprintf(
		buffer, size,
		"CONTACT(id=%ld, name=%s, age=%d, phone=%s, memo=%s)",
		contact -> id, contact -> name, contact -> age, contact -> phone, contact -> memo
	);
}
