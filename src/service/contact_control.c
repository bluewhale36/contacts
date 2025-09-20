//
// Created by 우승훈 on 25. 9. 18.
//

#include "../../include/contact_control.h"
#include <stdbool.h>
#include <string.h>
#include "../../include/file_control.h"
#include "../../include/identification_control.h"

const char phone_start_number_middle_is_4[][5] =
{
	// 3(4)-4-4 형태 (휴대폰번호, 안심번호)
	"010", "011", "050"
};
const char phone_start_number_middle_is_3[][5] =
{
	// 2(3)-3-4 형태 (지역번호)
	"02", "031", "032", "033",
	"041", "042", "043", "044",
	"051", "052", "053", "054", "055",
	"061", "062", "063", "064"
};

int get_all_contacts(CONTACT *contacts, const int max_contacts)
{
	// 파일 열기 시도
	const FILE_CONTROL_RESULT res = open_file("r");
	if (res.status == ERROR)
	{
		// 실패 시 -1 반환
		return -1;
	}
	if (res.status == OPENED_AS_NEW_FILE)
	{
		// 새로운 파일을 생성하며 열었을 경우 0 반환
		close_file(res.fp);
		return 0;
	}

	// 연락처 읽어오기 시도
	FILE *rfp = res.fp;
	int i = 0;
	for (; i < max_contacts; i++)
	{
		char str[FILE_LINE_MAX_LENGTH];
		if (fgets(str, FILE_LINE_MAX_LENGTH, rfp) == NULL)
		{
			// 파일에서 더 이상 읽어올 내용이 없을 경우 반복문 중단
			break;
		}

		deserialize_contact(&contacts[i], str);
		char buffer[200];
		contact_to_string_buffered(&contacts[i], buffer, 200);
	}
	close_file(rfp);
	// 읽어온 연락처 개수 반환
	return i;
}


CONTACT_STATUS save_one_contact(const CONTACT_CREATOR *contact_creator)
{
	CONTACT new_contact;

	/*
	 *	contact_creator 데이터를 contact 로 복사 및 id 생성
	 */
	contact_from_creator(&new_contact, contact_creator);

	// 향후 예외 처리 목적
	// if (contact_from_creator(&new_contact, contact_creator) != SUCCESS)
	// {
	// 	fprintf(stderr, "Error from converting creator to contact struct.\n");
	// 	return FAILED;
	// }

	/*
	 *	CONTACT 직렬화
	 */
	char str[FILE_LINE_MAX_LENGTH];
	if (serialize_contact(&new_contact, str) == CONTACT_FAILED)
	{
		fprintf(stderr, "Error serializing contact struct. \n");
		return CONTACT_FAILED;
	}
	/*
	 * 직렬화된 문자열에 가변 길이 할당
	 */
	char *ptr = (char*) malloc(sizeof(char) * strlen(str) + 1);
	strcpy(ptr, str);

	/*
	 *	파일에 쓰기 작업 시작
	 */
	FILE_CONTROL_RESULT res = open_file("a");
	if (res.status == OPENED)
	{
		// 파일이 열린 상태인 경우 직렬화된 문자열 작성.
		if (fputs(ptr, res.fp) < 0)
		{
			// 파일에 쓰인 문자열 없을 경우
			fprintf(stderr, "Error writing to file. \n");
			return CONTACT_FAILED;
		}
	}
	else if (res.status == ERROR)
	{
		// 파일이 정상적으로 열리지 못한 경우
		fprintf(stderr, "Error opening file. \n");
		return CONTACT_FAILED;
	}
	close_file(res.fp);

	// 사용했던 동적 메모리 전부 할당 해제
	free(ptr);
	free_contact_member(&new_contact);

	return CONTACT_CREATED;
}


CONTACT_STATUS deserialize_contact(CONTACT *contact, const char *str)
{
	char given_str[200];
	strcpy(given_str, str);

	char *token = strtok(given_str, ";");

	contact -> id = strtoul(token, NULL, 0);
	token = strtok(NULL, ";");

	contact -> name = strdup(token);
	token = strtok(NULL, ";");

	contact -> age = (unsigned short) atoi(token);
	token = strtok(NULL, ";");

	contact -> phone = strdup(token);
	token = strtok(NULL, ";");

	contact -> memo = strdup(token);

	return CONTACT_SUCCESS;
}


CONTACT_STATUS serialize_contact(const CONTACT *contact, char *str)
{
	if (
		sprintf(
			str,
			"%lu;%s;%hu;%s;%s;\n",
			contact -> id, contact -> name, contact -> age, contact -> phone, contact -> memo
		) < 0
	)
	{
		return CONTACT_FAILED;
	}
	return CONTACT_SUCCESS;
}


CONTACT_STATUS add_hyphen_to_phone_str(const char *phone_str, char *hyphened_buffer, const size_t buffer_size)
{
	// 1. 숫자와 허용된 기호의 개수를 찾는다
	int sign_count = 0, number_count = 0; // 허용된 기호의 개수, 숫자의 개수
	int number_idx[12]; // phone_str 에서 숫자의 인덱스 번호들
	int idx1 = -1; // number_idx 의 인덱스 번호
	for (int i = 0; i < strlen(phone_str); i++)
	{

		const char curr_ch = phone_str[i];
		if (curr_ch >= '0' && curr_ch <= '9')
		{
			number_count++;
			number_idx[++idx1] = i;
		}
		else if (curr_ch == '.' || curr_ch == '-' || curr_ch == ' ')
		{
			sign_count++;
		}
	}

	// 2. 지원되는 휴대폰 형식인지 검사한다
	if (sign_count + number_count != strlen(phone_str))
	{
		return UNSUPPORTED_PHONE_NUMBER;
	}

	// 3. 버퍼의 크기가 적절한지 검사한다
	if (number_count + 3 > buffer_size) // 전화번호 숫자 + 하이픈 2개 + \0
	{
		return TOO_SMALL_BUFFER;
	}

	// 4. 전달받은 전화번호의 시작 번호 형식을 찾는다
	bool is_middle_4 = false; // 전화번호 가운데 번호가 4자리인 여부
	bool is_start_number_supported = false; // 전화번호 시작 번호가 지원되는 여부
	const int phone_start_number_middle_is_4_count =
		sizeof(phone_start_number_middle_is_4) / sizeof(phone_start_number_middle_is_4[0]);
	for (int i = 0; i < phone_start_number_middle_is_4_count; i++)
	{
		if (
			strlen(strstr(phone_str, phone_start_number_middle_is_4[i])) == strlen(phone_str)
		)
		{
			is_middle_4 = true;
			is_start_number_supported = true;
			break;
		}
	}
	if (!is_start_number_supported)
	{
		// 전화번호 가운데 번호 4자리인 시작 번호를 찾지 못한 경우
		const int phone_start_number_middle_is_3_count =
		sizeof(phone_start_number_middle_is_3) / sizeof(phone_start_number_middle_is_3[0]);
		for (int i = 0; i < phone_start_number_middle_is_3_count; i++)
		{
			if (
				strlen(strstr(phone_str, phone_start_number_middle_is_3[i])) == strlen(phone_str)
			)
			{
				is_start_number_supported = true;
				break;
			}
		}
	}
	if (!is_start_number_supported)
	{
		// 어떠한 시작 번호와도 일치하지 않은 경우 지원 불가
		return UNSUPPORTED_PHONE_NUMBER;
	}

	// 6. hyphen 이 추가되어야 하는 인덱스 번호 찾는다
	int first, second;
	if (is_middle_4)
	{
		// 가운데 번호가 4자리인 경우
		if (number_count == 12)
		{
			// 050X 의 안심번호 형태의 경우
			first = 4;
		}
		else
		{
			// 010, 011 의 휴대폰 형태의 경우
			first = 3;
		}
		second = first +5;
	}
	else
	{
		// 가운데 번호가 3자리인 경우
		if (number_count == 9)
		{
			// 02 번 지역번호의 경우
			first = 2;
		}
		else
		{
			// 그 외 지역번호의 경우
			first = 3;
		}
		second = first +4;
	}

	// 7. hyphened_buffer 에 하이픈 추가된 전화번호 대입한다
	int idx2 = 0;
	for (int i = 0; i < buffer_size; i++)
	{
		if (idx2 > idx1)
		{
			// 모든 숫자를 가져온 경우
			hyphened_buffer[i] = '\0';
			break;
		}

		if (i == first || i == second)
		{
			// 하이픈 추가
			hyphened_buffer[i] = '-';
		}
		else
		{
			// i 가 하이픈을 추가할 인덱스 번호가 아닌 경우 -> 숫자 추가
			hyphened_buffer[i] = phone_str[number_idx[idx2]];
			idx2++;
		}
	}
	return CONTACT_SUCCESS;
}


CONTACT_STATUS contact_from_creator(CONTACT *contact, const CONTACT_CREATOR *contact_creator)
{
	unsigned long id;
	if (get_latest_id(&id) == ID_NOT_FOUND)
	{
		fprintf(stderr, "Could not found ID from file");
	}

	contact -> id = ++id;

	contact -> name = strdup(contact_creator -> name);

	contact -> age = (unsigned short) atoi(contact_creator -> age);

	char hyphened_buffer[15];
	add_hyphen_to_phone_str(contact_creator -> phone, hyphened_buffer, sizeof(hyphened_buffer));
	contact -> phone = strdup(hyphened_buffer);

	contact -> memo = strdup(contact_creator -> memo);

	return CONTACT_SUCCESS;
}

