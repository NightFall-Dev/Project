#pragma	once

#include "../EngineUIlib/GUInterface/UIGroup.h"

class	CQuestionItemType;
class	CQuestionItemDisplay : public CUIGroup
{
public:
	enum
	{
		SPEED_UP = NO_ID + 1,
		CRAZY_TIME,
		POWER_UP,
		EXP_TIME,

		EXP_GET,
		LUCKY,
		BOMB,
		OH_NO,

		SPEED_UP_M,
		MADNESS,		
		ATTACK_UP_M,
		HEAL,	


		TOWER_CAPTURED_SG,
		TOWER_CAPTURED_PHX,
		TOWER_CAPTURED_MP,
		TOWER_CAPTURED_SG_SCHOOL,
		TOWER_CAPTURED_PHX_SCHOOL,
		TOWER_CAPTURED_MP_SCHOOL,
		TOWER_CAPTURED_BACK,
		MAXTYPE = 20
	};

public:
	CQuestionItemDisplay ();
	virtual	~CQuestionItemDisplay ();

public:
	void	CreateSubControl ();

public:
	virtual void Update ( int x, int y, BYTE LB, BYTE MB, BYTE RB, int nScroll, float fElapsedTime, BOOL bFirstControl );

public:
	bool	START ( UIGUID cID );
	bool	RESET ( UIGUID cID );
	bool	STOP ( UIGUID cID );

	void	ALLSTOP ();

public:
	bool	KEEP_START ( UIGUID cID );
	void	KEEP_STOP ();
	bool	START_FADEINOUT( UIGUID cID );

private:
	CQuestionItemType*	m_pQI_TYPE[MAXTYPE];
	CUIControl*			m_QI_TYPE_KEEP[MAXTYPE];

	CUIControl*		m_pPositionControl;	
};