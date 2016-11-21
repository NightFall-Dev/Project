#include "stdafx.h"

#include "DxEffectBlur.h"

//	Note : 정적 변수 생성.
//
DWORD	DxEffectBlur::m_dwEffect;

/*
char DxEffectBlur::m_strEffect[] =
{
	"vs.1.1	\n"

	//;--------------------------------------------------------------------  
	//;	버텍스가 예전 World 에 적용 --------- r0 에 등록

	"m4x3 r0, v0, c32	\n"

	//;--------------------------------------------------------------------  
	//;	버텍스가 현재의 World  에 적용 --------- r1 에 등록
	"m4x3 r1, v0, c10	\n"	

	//;--------------------------------------------------------------------  
	//;	잔상 벡터를 만든다.. --------- r2 에 등록

	//	; 현재의 정점위치 - 예전의 정점위치
	"add r2.xyz, r1, - r0	\n"	

	//	; c22.z = blurFraction 잔상의 길이를 늘린다.
	"mul r2.xyz, r2, c29.z	\n"	

	//;--------------------------------------------------------------------  
	//;	잔상벡터와 노멀벡터를 내적. --------- r2.w 에 등록

	//	노멀벡터를 World 의 로 변환시킨다.
	"m3x3 r3, v3, c10	\n"

	//	잔상벡터와 노멀벡터를 내적한다.
	"dp3 r2.w, r2, r3	\n"	

	//;--------------------------------------------------------------------  
	//;		점들을 변환 시켜주는 작업 --------- r4 에 등록

	//; if r2.w < 0, then r4 = r0, else r4 = r1
	//;		<<<-------- 물체 이동방향 -------
	//;       (이 면은 0보다 크다)-> |폴리곤| <-(이 면은 0보다 작다)
	"slt  r3.w,   r2.w,  c28.x	\n"	//	; r2.w 가 0 보다 작으면 1 아니면 0 
	"mad  r4.xyz, r3.w, -r2, r1	\n"	//	; 현재의 버텍스를 잔상벡터 만큼 빼준다.
	"expp r4.w,   v0.x			\n"	// 	; generate constant 1.0 (이것이 뭐지?)

	//;--------------------------------------------------------------------  
	//;		정점들을 뿌려준다.완성품
	"m4x4 r5, r4, c14	\n"
	"m4x4 oPos, r5, c18	\n"

	//;--------------------------------------------------------------------  
	//;		디퓨즈 칼라를 넣어준다. 알파값도..

	//; compute alpha component depending on length of motion vector
	"dp3 r2.w, r2,  r2		\n"	//	; 잔상벡터를.. 제곱 -> 길이^2
	"rsq r1.w, r2.w			\n"	//		; 1/길이
	"mul r2.w, r2.w, r1.w	\n"	//	; r2.w now contains length(motion vec)  길이

	//; now compute r2.w = 1 - length(motion vec)/extent
	"mad r2.w, -r2.w, c29.x, c29.y	\n"	//	; (-길이 * 2.0f/Radius) + 1.0f

	//; clamp color and alpha to minimum values
	"max r5, c30, r2.w	\n"	//	; kBlurAlpha(0.0f)예전의 알파값을 보다 큰것을 넣어준다.

	//; select color and alpha based on whether we use current or previous transform
	"add r5,  r5, -c31	\n"	//	; 위의 계산 값을 현재의 칼라값으로 빼준다.

	//; 현재 칼라는 기본으로 있고, 이동하는 방향이 앞면이냐 뒷면이냐에 의해 
	//;위의 값을 빼주는냐 마느냐가 결정된다.
	"mad oD0, r3.w, r5, c31	\n"	//
	
};
*/

//	Note : 모션 블러의 잔상 뿌리기
//
DWORD	DxEffectBlur::dwBlurDVertexShader[] = {
	0xfffe0101, 0x0004fffe, 0x454c4946, 0x72756c62,
	0x73762e44, 0x6c620068, 0x0002fffe, 0x454e494c,
	0x00000001, 0x0002fffe, 0x454e494c, 0x00000002,
	0x0002fffe, 0x454e494c, 0x00000003, 0x0002fffe,
	0x454e494c, 0x00000004, 0x0002fffe, 0x454e494c,
	0x00000005, 0x0002fffe, 0x454e494c, 0x00000005,
	0x00000015, 0x800f0000, 0x90e40000, 0xa0e40020,
	0x0002fffe, 0x454e494c, 0x00000006, 0x0002fffe,
	0x454e494c, 0x00000007, 0x0002fffe, 0x454e494c,
	0x00000008, 0x0002fffe, 0x454e494c, 0x00000008,
	0x00000015, 0x800f0001, 0x90e40000, 0xa0e4000a,
	0x0002fffe, 0x454e494c, 0x00000009, 0x0002fffe,
	0x454e494c, 0x0000000a, 0x0002fffe, 0x454e494c,
	0x0000000a, 0x00000002, 0x80070002, 0x80e40001,
	0x81e40000, 0x0002fffe, 0x454e494c, 0x0000000b,
	0x0002fffe, 0x454e494c, 0x0000000c, 0x0002fffe,
	0x454e494c, 0x0000000d, 0x0002fffe, 0x454e494c,
	0x0000000d, 0x00000005, 0x80070002, 0x80e40002,
	0xa0aa001d, 0x0002fffe, 0x454e494c, 0x0000000e,
	0x0002fffe, 0x454e494c, 0x0000000f, 0x0002fffe,
	0x454e494c, 0x00000010, 0x0002fffe, 0x454e494c,
	0x00000010, 0x00000017, 0x800f0003, 0x90e40003,
	0xa0e4000a, 0x0002fffe, 0x454e494c, 0x00000011,
	0x0002fffe, 0x454e494c, 0x00000012, 0x0002fffe,
	0x454e494c, 0x00000013, 0x0002fffe, 0x454e494c,
	0x00000013, 0x00000008, 0x80080002, 0x80e40002,
	0x80e40003, 0x0002fffe, 0x454e494c, 0x00000014,
	0x0002fffe, 0x454e494c, 0x00000015, 0x0002fffe,
	0x454e494c, 0x00000015, 0x0000000c, 0x80080003,
	0x80ff0002, 0xa000001c, 0x0002fffe, 0x454e494c,
	0x00000016, 0x0002fffe, 0x454e494c, 0x00000016,
	0x00000004, 0x80070004, 0x80ff0003, 0x81e40002,
	0x80e40001, 0x0002fffe, 0x454e494c, 0x00000017,
	0x0002fffe, 0x454e494c, 0x00000017, 0x0000004e,
	0x80080004, 0x90000000, 0x0002fffe, 0x454e494c,
	0x00000018, 0x0002fffe, 0x454e494c, 0x00000019,
	0x0002fffe, 0x454e494c, 0x0000001a, 0x0002fffe,
	0x454e494c, 0x0000001a, 0x00000014, 0x800f0005,
	0x80e40004, 0xa0e4000e, 0x0002fffe, 0x454e494c,
	0x0000001b, 0x0002fffe, 0x454e494c, 0x0000001b,
	0x00000014, 0xc00f0000, 0x80e40005, 0xa0e40012,
	0x0002fffe, 0x454e494c, 0x0000001c, 0x0002fffe,
	0x454e494c, 0x0000001d, 0x0002fffe, 0x454e494c,
	0x0000001e, 0x0002fffe, 0x454e494c, 0x0000001e,
	0x00000008, 0x80080002, 0x80e40002, 0x80e40002,
	0x0002fffe, 0x454e494c, 0x0000001f, 0x0002fffe,
	0x454e494c, 0x0000001f, 0x00000007, 0x80080001,
	0x80ff0002, 0x0002fffe, 0x454e494c, 0x00000020,
	0x0002fffe, 0x454e494c, 0x00000020, 0x00000005,
	0x80080002, 0x80ff0002, 0x80ff0001, 0x0002fffe,
	0x454e494c, 0x00000021, 0x0002fffe, 0x454e494c,
	0x00000022, 0x0002fffe, 0x454e494c, 0x00000023,
	0x0002fffe, 0x454e494c, 0x00000023, 0x00000004,
	0x80080002, 0x81ff0002, 0xa000001d, 0xa055001d,
	0x0002fffe, 0x454e494c, 0x00000024, 0x0002fffe,
	0x454e494c, 0x00000025, 0x0002fffe, 0x454e494c,
	0x00000026, 0x0002fffe, 0x454e494c, 0x00000026,
	0x0000000b, 0x800f0005, 0xa0e4001e, 0x80ff0002,
	0x0002fffe, 0x454e494c, 0x00000027, 0x0002fffe,
	0x454e494c, 0x00000028, 0x0002fffe, 0x454e494c,
	0x00000028, 0x00000002, 0x800f0005, 0x80e40005,
	0xa1e4001f, 0x0002fffe, 0x454e494c, 0x00000029,
	0x0002fffe, 0x454e494c, 0x0000002a, 0x0002fffe,
	0x454e494c, 0x0000002a, 0x00000004, 0xd00f0000,
	0x80ff0003, 0x80e40005, 0xa0e4001f, 0x0000ffff
	
};

DWORD	DxEffectBlur::m_dwSavedStateBlock(0x00000000);
DWORD	DxEffectBlur::m_dwEffectStateBlock(0x00000000);