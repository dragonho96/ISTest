#pragma once
#ifndef __DEFINE_H__
#define __DEFINE_H__

#define WINCX 450
#define WINCY 750

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

#define OBJ_NOEVENT		0
#define OBJ_DEAD		1

#define STAIR_CX 82
#define STAIR_CY 45
#define COIN_CX 15
#define COIN_CY 15

#define STAIR_INITPOS_X 200
#define STAIR_INITPOS_Y 600

#define REPEAT_MAX 5

#endif // !__DEFINE_H__
