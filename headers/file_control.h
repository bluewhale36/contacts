//
// Created by 우승훈 on 9/18/25.
//

#ifndef FILE_CONTROL_H
#define FILE_CONTROL_H

#include <stdio.h>
#include "contact_structor.h"

typedef enum file_status
{
    ERROR = -1,
    CLOSED = 0,
    OPENED = 1,
    OPENED_WITH_CREATION = 2
} FILE_STATUS;

typedef struct file_control_result
{
	FILE_STATUS status;
    FILE *fp;
} FILE_CONTROL_RESULT;

const char *file_path = "../contacts.txt";

FILE_CONTROL_RESULT open_file(char *mode);
FILE_CONTROL_RESULT close_file(FILE *fp);


#endif //FILE_CONTROL_H
