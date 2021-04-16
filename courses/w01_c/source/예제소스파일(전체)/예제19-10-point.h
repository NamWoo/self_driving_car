// 파일 이름을 '예제19-10-point.h'에서 point.h로 바꿔 사용하세요.

#ifndef _POINT_H_   // _POINT_H_ 매크로명이 정의되어 있지 않으면
#define _POINT_H_   // _POINT_H_ 매크로명 정의

typedef struct
{
	int x;          // x좌표
	int y;          // y좌표
} Point;

#endif              // #ifndef _POINT_H_의 끝