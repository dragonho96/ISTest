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
#define COIN_CX 48
#define COIN_CY 48

#define STAIR_INITPOS_X 2000
#define STAIR_INITPOS_Y 600

#define BACKGROUND_STREET_CX 4000
#define BACKGROUND_STREET_CY 775
#define BACKGROUND_SKY_CX 4000
#define BACKGROUND_SKY_CY 1850

#define REPEAT_MAX 5

#endif // !__DEFINE_H__
