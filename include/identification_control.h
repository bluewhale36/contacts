//
// Created by 우승훈 on 9/20/25.
//

#ifndef IDENTIFICATION_CONTROL_H
#define IDENTIFICATION_CONTROL_H

typedef enum id_status
{
	ID_NOT_FOUND = -4,
	ID_ERROR = -1,
	ID_SUCCESS = 0,
	ID_CREATED = 1
} ID_STATUS;

/**
 * 변수 latest_id 값을 포인터 변수에 대입한다.
 * @param latest_id 최신 ID 값을 받을 포인터
 * @return ID 값 전달 성공 시 0, 실패 시 -1, ID 값을 찾을 수 없는 경우 -4 반환.
 */
ID_STATUS get_latest_id(unsigned long *latest_id);

/**
 * 파일로부터 최근 ID 를 가져온다.
 * @return 갱신 성공 시 0, 실패 시 -1, 새로운 ID 값 생성 시 1 반환.
 */
ID_STATUS update_latest_id_from_file(void);

#endif //IDENTIFICATION_CONTROL_H
