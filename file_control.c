//
// Created by 우승훈 on 9/18/25.
//
#include <stdio.h>
#include <string.h>
#include "headers/file_control.h"

const char *file_path = "contacts.txt";

FILE_CONTROL_RESULT open_file(char *mode)
{
	FILE_STATUS status = ERROR;
    FILE *rfp, *wfp;

    rfp = fopen(file_path, "r");

    // 파일이 존재하지 않을 경우를 대비.
    if (rfp == NULL)
    {
    	wfp = fopen(file_path, "w");
        fclose(wfp);
        rfp = fopen(file_path, "r");
        fclose(rfp);
        status = OPENED_AS_NEW_FILE;
    }

    /*
        함수 인자로 받은 모드에 따라 파일 열기.
        적절한 모드가 없을 경우 NULL 반환.
     */
    FILE *fp;
    if (strcmp(mode, "r") == 0)
    {
		fp = fopen(file_path, "r");
        status = OPENED;
    }
    else if (strcmp(mode, "w") == 0)
    {
        fp = fopen(file_path, "w");
        status = OPENED;
    }
    else if (strcmp(mode, "a") == 0)
    {
        fp = fopen(file_path, "a");
        status = OPENED;
    }
    else
    {
        fp = NULL;
    }
    const FILE_CONTROL_RESULT result = {status, fp};
    return result;
}