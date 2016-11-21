#include "StdAfx.h"
#include "SkillImage.h"
#include "../EngineUILib/GUInterface/BasicProgressBar.h"
#include "GLGaeaClient.h"
#include "SkillFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CSkillImage::CSkillImage ()
	: m_pSkillProcess ( NULL )
	, m_pd3dDevice ( NULL )
	, m_TotElapsedTime(0.0f)
	, m_bSkillUsed(false)
	, m_bSkillEnd(false)
	, m_bTwinkle(true)
{
}

CSkillImage::~CSkillImage ()
{
}

void CSkillImage::CreateProgressBar ()
{
	CBasicProgressBar* pSkillProcess = new CBasicProgressBar;
	pSkillProcess->CreateSub ( this, "SKILL_IMAGE_PROGRESS" );
	pSkillProcess->CreateOverImage ( "SKILL_IMAGE_PROGRESS_OVER" );
	pSkillProcess->SetType ( CBasicProgressBar::VERTICAL );
	pSkillProcess->SetOverImageUseRender ( TRUE );
	pSkillProcess->SetOverImageDiffuse ( NS_SKILL::RECHARGECOLOR );
	pSkillProcess->SetControlNameEx ( "프로그래스바" );	
	RegisterControl ( pSkillProcess );
	m_pSkillProcess = pSkillProcess;
}

HRESULT CSkillImage::InitDeviceObjects ( LPDIRECT3DDEVICEQ pd3dDevice )
{
	HRESULT hr = S_OK;
	hr = CUIGroup::InitDeviceObjects ( pd3dDevice );
	if ( FAILED ( hr ) ) return hr;

	m_pd3dDevice = pd3dDevice;

	return S_OK;
}

void CSkillImage::Update ( int x, int y, BYTE LB, BYTE MB, BYTE RB, int nScroll, float fElapsedTime, BOOL bFirstControl )
{
	CUIGroup::Update ( x, y, LB, MB, RB, nScroll, fElapsedTime, bFirstControl );

	if( m_bSkillUsed && m_bSkillEnd )
	{
		m_TotElapsedTime += fElapsedTime;

		if( m_TotElapsedTime < 0.3f )		m_pSkillProcess->SetPercent(0);
		else if( m_TotElapsedTime < 0.6f )	m_pSkillProcess->SetPercent(1);
		else if( m_TotElapsedTime < 0.9f )	m_pSkillProcess->SetPercent(0);
		else if( m_TotElapsedTime < 1.2f )	m_pSkillProcess->SetPercent(1);
		else
		{
			m_pSkillProcess->SetPercent(0);
			m_TotElapsedTime = 0.0f;
			m_bSkillEnd = false;
			m_bSkillUsed = false;
		}
	}
}

void CSkillImage::SetSkillProcess ( SNATIVEID sNativeID )
{
	if ( !m_pSkillProcess )
	{
		GASSERT ( 0 && "프로그래스바가 만들어지지 않았습니다." );
		return ;
	}

	PGLSKILL pSkill = GLSkillMan::GetInstance().GetData ( sNativeID.wMainID, sNativeID.wSubID );
	if ( !pSkill )	return ;

	WORD wPCLEVEL = GLGaeaClient::GetInstance().GetCharacter()->GETLEVEL();

	//	최대 지연시간
	SCHARSKILL* pCharSkill = GLGaeaClient::GetInstance().GetCharacter()->GETLEARNED_SKILL ( sNativeID );
	if ( pCharSkill )
	{
		const float fDelayTime = pSkill->m_sAPPLY.sDATA_LVL[pCharSkill->wLevel].fDELAYTIME;
		float fSkillDelayTime = GLOGICEX::SKILLDELAY(pSkill->m_sBASIC.dwGRADE,pCharSkill->wLevel,wPCLEVEL,fDelayTime);	

		//	현재 지연시간
		float fCurTime = 0.0f;

		DELAY_MAP &map = GLGaeaClient::GetInstance().GetCharacter()->m_SKILLDELAY;
		if ( !map.empty() )
		{
			DELAY_MAP_ITER iter = map.find ( sNativeID.dwID );
			if ( iter!= map.end() ) fCurTime = (*iter).second;
		}

		if( m_bTwinkle && fCurTime == 0.0f ) 
		{
			m_bSkillEnd = true;
			return;
		}
		else					
		{
			m_bSkillEnd = false;
		}

		if ( fSkillDelayTime == 0.0f )
		{
			fSkillDelayTime = 1.0f;
		}

		const float fPercent = fCurTime / fSkillDelayTime;
		m_pSkillProcess->SetPercent ( fPercent );

		m_bSkillUsed = true;
	}
}

void	CSkillImage::CreateSubControl ()
{	
	CreateProgressBar ();
}

void CSkillImage::SetSkill ( SNATIVEID sNativeID )
{
	if ( sNativeID == NATIVEID_NULL () )
	{
		return ;
	}

	PGLSKILL pSkill = GLSkillMan::GetInstance().GetData ( sNativeID.wMainID, sNativeID.wSubID );
	if ( !pSkill )
	{
		return ;
	}

	SNATIVEID sICONINDEX = pSkill->m_sEXT_DATA.sICONINDEX;
	CString	  strTextureName = pSkill->m_sEXT_DATA.strICONFILE.c_str();	

	//	이전 프레임과 ICONID와
	//	텍스쳐 이름이 같다는 것은
	//	아래의 작업을 더 이상 진행할 필요가 없다는 것을 의미한다.
	if ( (sICONINDEX == m_sICONINDEX) &&
		(strTextureName == CUIControl::GetTextureName()) )
	{
		return ;
	}
	
	CUIControl::SetTexturePos ( NS_SKILL::GetIconTexurePos ( sICONINDEX ) );
	CUIControl::SetTextureName ( strTextureName.GetString () );
	m_sICONINDEX = sICONINDEX;

	if ( m_pd3dDevice ) CUIControl::InitDeviceObjects ( m_pd3dDevice );
}

void CSkillImage::ResetSkill ()
{
	CUIControl::DeleteDeviceObjects ();
	CUIControl::SetTextureName ( NULL );
	m_sICONINDEX = NATIVEID_NULL ();
}