#pragma	once



#include "../EngineUILib/GUInterface/UIGroup.h"
#include "GLCharDefine.h"

const DWORD UIMSG_CTFINFO_LBDUP = UIMSG_USER1;

class	CD3DFontPar;
class	CBasicTextButton;
class CBasicTextBox;

class CCTFInfoDisplay : public CUIGroup
{
public:
    CCTFInfoDisplay ();
	virtual	~CCTFInfoDisplay ();

public:
	virtual void Update ( int x, int y, BYTE LB, BYTE MB, BYTE RB, int nScroll, float fElapsedTime, BOOL bFirstControl );
	virtual	void TranslateUIMessage ( UIGUID ControlID, DWORD dwMsg );
	virtual void SetGlobalPos(const D3DXVECTOR2& vPos);
	void CheckMouseState ();

public:
	void	CreateSubControl ();
	void	ShowCTFInfo ();
	void	HideCTFInfo ();

	void	ShowMPFaci();
	void	ShowMPNucl();
	void	ShowMPTher();
	void	ShowSGFaci();
	void	ShowSGNucl();
	void	ShowSGTher();
	void	ShowPHXFaci();
	void	ShowPHXNucl();
	void	ShowPHXTher();
	void	ShowNULLFaci();
	void	ShowNULLNulc();
	void	ShowNULLTher();
	void	HideNULL();

		void	UpdateSchoolWarTime( float fSchoolWarsTime );
	void	StartSchoolWarTime();
	void	EndSchoolWarTime();
	CBasicTextButton*	CreateTextButton23 ( const char* szButton, UIGUID ControlID, const char* szText );
private:
	BOOL		m_bFirstGap;
	D3DXVECTOR2	m_vGap;

	int			m_PosX;
	int			m_PosY;

	bool		m_bCHECK_MOUSE_STATE;
private:
	CUIControl*				m_pBackGroundLeft;
	CUIControl*				m_pBackGroundBody;
	CUIControl*				m_pBackGroundRight;
	CUIControl*				m_pDisplayLine1;
	CUIControl*				m_pDisplayLine2;
	
	//
		CUIControl*				m_pFacility_MP;
		CUIControl*				m_pFacility_SG;
		CUIControl*				m_pFacility_PHX;
		CUIControl*				m_pFacility_NULL;
		CUIControl*				m_pThermal_MP;
		CUIControl*				m_pThermal_SG;
		CUIControl*				m_pThermal_PHX;
		CUIControl*				m_pThermal_NULL;
		CUIControl*				m_pNuclear_MP;
		CUIControl*				m_pNuclear_SG;
		CUIControl*				m_pNuclear_PHX;
		CUIControl*				m_pNuclear_NULL;
	//
	CBasicTextBox*			m_pThermalTowerText;
	CBasicTextBox*			m_pSchoolWarTimeText;
	CBasicTextBox*			m_pFacilityTowerText;
	CBasicTextBox*			m_pNuclearTowerText;
};