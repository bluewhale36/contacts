//
// Created by 우승훈 on 25. 9. 18.
//

#include "../../include/contact_structor.h"
#include <stdio.h>
#include <stdlib.h>

void contact_to_string_buffered(const CONTACT *contact, char *buffer, size_t size)
{
	snprintf(
		buffer, size,
		"CONTACT(id=%ld, name=%s, age=%d, phone=%s, memo=%s)",
		contact -> id, contact -> name, contact -> age, contact -> phone, contact -> memo
	);
}

void contact_to_string_human_readable_buffered(const CONTACT *contact, char *buffer, size_t size)
{
	snprintf(
		buffer, size,
		"%-5ld\t%-30s%-3d\t%-16s\t%s",
		contact -> id, contact -> name, contact -> age, contact -> phone, contact -> memo
	);
}

void contact_creator_to_string(const CONTACT_CREATOR *contact, char *buffer, size_t size)
{
	snprintf(
		buffer, size,
		"CONTACT(name=%s, age=%s, phone=%s, memo=%s)",
		contact -> name, contact -> age, contact -> phone, contact -> memo
	);
}

void free_contact_member(CONTACT *contact)
{
	free(contact -> name);
	free(contact -> phone);
	free(contact -> memo);
}