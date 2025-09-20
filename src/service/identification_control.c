//
// Created by 우승훈 on 9/20/25.
//

#include "../../include/identification_control.h"

#include <stdlib.h>
#include <string.h>

#include "../../include/file_control.h";

static unsigned long latest_id;


ID_STATUS get_latest_id(unsigned long *id)
{
	if (update_latest_id_from_file() != ID_ERROR)
	{
		*id = latest_id;
		return ID_SUCCESS;
	}
	return ID_ERROR;
}

ID_STATUS update_latest_id_from_file(void)
{
	const FILE_CONTROL_RESULT res = open_file("r");
	switch (res.status)
	{
	case OPENED:
		FILE *rfp = res.fp;

		long offset = -1L;
		while (1)
		{
			if (fseek(rfp, --offset, SEEK_END) >= 0)
			{
				int c = fgetc(rfp);
				if (c == (int) '\n')
				{
					char buffer[200];
					fgets(buffer, sizeof(buffer), rfp);
					char *token = strtok(buffer, ";");
					latest_id = strtoul(token, NULL, 10);
					return ID_SUCCESS;
				}
			}
			else
			{
				return ID_ERROR;
			}
		}
	case OPENED_AS_NEW_FILE:
		latest_id = 0L;
		return ID_CREATED;
	default:
		return ID_ERROR;
	}

}