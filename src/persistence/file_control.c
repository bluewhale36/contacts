//
// Created by 우승훈 on 9/18/25.
//
#include "../../include/file_control.h"
#include <stdbool.h> // bool 타입을 사용하기 위해 추가
#include <stdio.h>

const char *file_path = "../data/contacts.txt";

FILE_CONTROL_RESULT open_file(char *mode)
{
    FILE_STATUS status;
    FILE *fp;
    bool file_existed = true;

    // 1. 파일이 존재 여부 확인
    FILE *check_fp = fopen(file_path, "r");
    if (check_fp == NULL)
    {
        file_existed = false;
    }
    else
    {
        // 확인을 위해서 열었던 파일은 즉시 닫음
        fclose(check_fp);
    }

    // 2. 요청받은 실제 모드로 파일 열기
    fp = fopen(file_path, mode);

    // 3. 파일 열기 성공 여부와 존재 여부를 조합하여 최종 상태 결정
    if (fp == NULL)
    {
        // fp == null 일 경우 파일 열기 실패 -> ERROR 반환
        status = ERROR;
    }
    else
    {
        // 파일을 성공적으로 열었을 때,
        if (!file_existed)
        {
            // 이전에 파일이 존재하지 않던 상태 -> OPENED_AS_NEW_FILE
            status = OPENED_AS_NEW_FILE;
        }
        else
        {
            // 이전에 파일이 존재 -> OPENED
            status = OPENED;
        }
    }

    const FILE_CONTROL_RESULT result = {status, fp};
    return result;
}

FILE_STATUS close_file(FILE *fp)
{
    const int result = fclose(fp);

    if (result == EOF)
    {
        return ERROR;
    }

    return CLOSED;
}
