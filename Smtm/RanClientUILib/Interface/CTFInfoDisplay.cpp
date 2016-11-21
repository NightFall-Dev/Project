#include "StdAfx.h"

#include "CTFInfoDisplay.h"
#include "../EngineUILib/GUInterface/BasicTextBox.h"
#include "d3dfont.h"
#include "GLGaeaClient.h"
#include "UITextControl.h"
#include "GameTextControl.h"
#include "CTFInfoDisplay.h"
#include "InnerInterface.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CCTFInfoDisplay::CCTFInfoDisplay ()
	: m_pBackGroundLeft( NULL )
	, m_pBackGroundBody ( NULL )
	, m_pBackGroundRight( NULL )
	, m_pDisplayLine1( NULL )
	, m_pDisplayLine2( NULL )
	, m_pThermalTowerText( NULL )
		,m_pFacility_MP( NULL )
		,m_pFacility_SG( NULL )
		,m_pFacility_PHX( NULL )
		,m_pFacility_NULL( NULL )
		,m_pThermal_MP( NULL )
		,m_pThermal_SG( NULL )
		,m_pThermal_PHX( NULL )
		,m_pThermal_NULL( NULL )
		,m_pNuclear_MP( NULL )
		,m_pNuclear_SG( NULL )
		,m_pNuclear_PHX( NULL )
		,m_pNuclear_NULL( NULL )
	, m_pFacilityTowerText( NULL )
	, m_pNuclearTowerText( NULL )
	, m_pSchoolWarTimeText ( NULL )

{
}

CCTFInfoDisplay::~CCTFInfoDisplay ()
{
}
 
void CCTFInfoDisplay::CreateSubControl ()
{
	CD3DFontPar* pFont = DxFontMan::GetInstance().LoadDxFont ( _DEFAULT_FONT, 10, _DEFAULT_FONT_SHADOW_FLAG );
	

	m_pBackGroundLeft = new CUIControl;
	m_pBackGroundLeft->CreateSub ( this, "INFO_CTF_DISPLAY_BACKGROUND_LEFT", UI_FLAG_DEFAULT );	
	m_pBackGroundLeft->SetVisibleSingle ( TRUE );
	m_pBackGroundLeft->SetControlNameEx ( "Back Ground Left" );
	RegisterControl ( m_pBackGroundLeft );

	m_pBackGroundBody = new CUIControl;
	m_pBackGroundBody->CreateSub ( this, "INFO_CTF_DISPLAY_BACKGROUND_BODY", UI_FLAG_DEFAULT );	
	m_pBackGroundBody->SetVisibleSingle ( TRUE );
	m_pBackGroundBody->SetControlNameEx ( "Back Ground BODY" );
	RegisterControl ( m_pBackGroundBody );

	m_pBackGroundRight = new CUIControl;
	m_pBackGroundRight->CreateSub ( this, "INFO_CTF_DISPLAY_BACKGROUND_RIGHT", UI_FLAG_DEFAULT );	
	m_pBackGroundRight->SetVisibleSingle ( TRUE );
	m_pBackGroundRight->SetControlNameEx ( "Back Ground Right" );
	RegisterControl ( m_pBackGroundRight );

	m_pDisplayLine1 = new CUIControl;
	m_pDisplayLine1->CreateSub ( this, "INFO_CTF_DISPLAY_LINE_1", UI_FLAG_DEFAULT );	
	m_pDisplayLine1->SetVisibleSingle ( TRUE );
	RegisterControl ( m_pDisplayLine1 );

	m_pDisplayLine2 = new CUIControl;
	m_pDisplayLine2->CreateSub ( this, "INFO_CTF_DISPLAY_LINE_2", UI_FLAG_DEFAULT );	
	m_pDisplayLine2->SetVisibleSingle ( TRUE );
	RegisterControl ( m_pDisplayLine2 );

	m_pFacility_NULL = new CUIControl;
	m_pFacility_NULL->CreateSub ( this, "FACILITY_NULL", UI_FLAG_DEFAULT );	
	m_pFacility_NULL->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pFacility_NULL );

	m_pNuclear_NULL = new CUIControl;
	m_pNuclear_NULL->CreateSub ( this, "NUCLEAR_NULL", UI_FLAG_DEFAULT );	
	m_pNuclear_NULL->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pNuclear_NULL );

	m_pThermal_NULL = new CUIControl;
	m_pThermal_NULL->CreateSub ( this, "THERMAL_NULL", UI_FLAG_DEFAULT );	
	m_pThermal_NULL->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pThermal_NULL );

	m_pNuclear_MP = new CUIControl;
	m_pNuclear_MP->CreateSub ( this, "NUCLEAR_MP_CAPTURED", UI_FLAG_DEFAULT );	
	m_pNuclear_MP->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pNuclear_MP );

	m_pNuclear_SG = new CUIControl;
	m_pNuclear_SG->CreateSub ( this, "NUCLEAR_SG_CAPTURED", UI_FLAG_DEFAULT );	
	m_pNuclear_SG->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pNuclear_SG );

	m_pNuclear_PHX = new CUIControl;
	m_pNuclear_PHX->CreateSub ( this, "NUCLEAR_PHX_CAPTURED", UI_FLAG_DEFAULT );	
	m_pNuclear_PHX->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pNuclear_PHX );

	m_pThermal_MP = new CUIControl;
	m_pThermal_MP->CreateSub ( this, "THERMAL_MP_CAPTURED", UI_FLAG_DEFAULT );	
	m_pThermal_MP->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pThermal_MP );

	m_pThermal_SG = new CUIControl;
	m_pThermal_SG->CreateSub ( this, "THERMAL_SG_CAPTURED", UI_FLAG_DEFAULT );	
	m_pThermal_SG->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pThermal_SG );

	m_pThermal_PHX = new CUIControl;
	m_pThermal_PHX->CreateSub ( this, "THERMAL_PHX_CAPTURED", UI_FLAG_DEFAULT );	
	m_pThermal_PHX->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pThermal_PHX );

	m_pFacility_MP = new CUIControl;
	m_pFacility_MP->CreateSub ( this, "FACILITY_MP_CAPTURED", UI_FLAG_DEFAULT );	
	m_pFacility_MP->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pFacility_MP );

	m_pFacility_SG = new CUIControl;
	m_pFacility_SG->CreateSub ( this, "FACILITY_SG_CAPTURED", UI_FLAG_DEFAULT );	
	m_pFacility_SG->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pFacility_SG );

	m_pFacility_PHX = new CUIControl;
	m_pFacility_PHX->CreateSub ( this, "FACILITY_PHX_CAPTURED", UI_FLAG_DEFAULT );	
	m_pFacility_PHX->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pFacility_PHX );

	m_pThermalTowerText = new CBasicTextBox;
	m_pThermalTowerText->CreateSub ( this, "THERMAL_TOWER_TEXT" );
	m_pThermalTowerText->SetFont ( pFont );
	m_pThermalTowerText->SetTextAlign ( TEXT_ALIGN_CENTER_X );
	RegisterControl ( m_pThermalTowerText );

	m_pFacilityTowerText = new CBasicTextBox;
	m_pFacilityTowerText->CreateSub ( this, "FACILITY_TOWER_TEXT" );
	m_pFacilityTowerText->SetFont ( pFont );
	m_pFacilityTowerText->SetTextAlign ( TEXT_ALIGN_CENTER_X );
	RegisterControl ( m_pFacilityTowerText );

	m_pNuclearTowerText = new CBasicTextBox;
	m_pNuclearTowerText->CreateSub ( this, "NUCLEAR_TOWER_TEXT" );
	m_pNuclearTowerText->SetFont ( pFont );
	m_pNuclearTowerText->SetTextAlign ( TEXT_ALIGN_CENTER_X );
	RegisterControl ( m_pNuclearTowerText );

	CBasicTextBox* pSchoolWarTimeText = new CBasicTextBox;
	pSchoolWarTimeText->CreateSub ( this, "MINIMAP_SCHOOLWAR_TIME_TEXT" );
	pSchoolWarTimeText->SetFont ( pFont );
	pSchoolWarTimeText->SetTextAlign ( TEXT_ALIGN_CENTER_X );
	RegisterControl ( pSchoolWarTimeText );
	m_pSchoolWarTimeText = pSchoolWarTimeText;
}

void CCTFInfoDisplay::SetGlobalPos(const D3DXVECTOR2& vPos)
{
	CUIGroup::SetGlobalPos( vPos );
}

void CCTFInfoDisplay::TranslateUIMessage ( UIGUID ControlID, DWORD dwMsg )
{

	if ( !m_bCHECK_MOUSE_STATE )
	{
		CheckMouseState ();
		m_bCHECK_MOUSE_STATE = true;
	}

}


void CCTFInfoDisplay::Update ( int x, int y, BYTE LB, BYTE MB, BYTE RB, int nScroll, float fElapsedTime, BOOL bFirstControl )
{	
	m_bCHECK_MOUSE_STATE = false;

	m_PosX = x;
	m_PosY = y;

	CUIGroup::Update ( x, y, LB, MB, RB, nScroll, fElapsedTime, bFirstControl );

	if ( IsExclusiveSelfControl() )
	{
		SetGlobalPos ( D3DXVECTOR2 ( x - m_vGap.x, y - m_vGap.y ) );
	}
}
void CCTFInfoDisplay::UpdateSchoolWarTime( float fSchoolWarsTime )
{
	CString strCombine;
	strCombine.Format ( "%s %02d:%02d", ID2GAMEWORD( "SCHOOL_WAR_BATTLE_TIME", 0 ), (DWORD)fSchoolWarsTime/60, (DWORD)fSchoolWarsTime%60 );
	m_pSchoolWarTimeText->SetOneLineText( strCombine, NS_UITEXTCOLOR::GOLD );
}

void CCTFInfoDisplay::StartSchoolWarTime()
{
	if( m_pSchoolWarTimeText ) m_pSchoolWarTimeText->SetVisibleSingle( TRUE );
}

void CCTFInfoDisplay::EndSchoolWarTime()
{
	if( m_pSchoolWarTimeText ) m_pSchoolWarTimeText->SetVisibleSingle( FALSE );
}
void CCTFInfoDisplay::ShowCTFInfo()
{
	if ( !m_pThermalTowerText ) return;
	if ( !m_pFacilityTowerText ) return;
	if ( !m_pNuclearTowerText ) return;

	m_pThermalTowerText->ClearText();
	m_pFacilityTowerText->ClearText();
	m_pNuclearTowerText->ClearText();

	CString strThermalTower;
	CString strFacilityTower;
	CString strNuclearTower;

	strThermalTower.Format( "Thermal" );
	m_pThermalTowerText->AddText( strThermalTower, NS_UITEXTCOLOR::GOLD );

	strFacilityTower.Format( "Facility" );
	m_pFacilityTowerText->AddText( strFacilityTower, NS_UITEXTCOLOR::GOLD );

	strNuclearTower.Format( "Nuclear" );
	m_pNuclearTowerText->AddText( strNuclearTower, NS_UITEXTCOLOR::GOLD );

	m_pBackGroundLeft->SetVisibleSingle ( TRUE );
	m_pBackGroundBody->SetVisibleSingle ( TRUE );
	m_pBackGroundRight->SetVisibleSingle ( TRUE );
	m_pDisplayLine1->SetVisibleSingle ( TRUE );
	m_pDisplayLine2->SetVisibleSingle ( TRUE );

	m_pThermalTowerText->SetVisibleSingle ( TRUE );
	m_pFacilityTowerText->SetVisibleSingle ( TRUE );
	m_pNuclearTowerText->SetVisibleSingle ( TRUE );
}
void CCTFInfoDisplay::CheckMouseState ()
{
	const DWORD dwMsg = GetMessageEx ();
	if ( CHECK_MOUSE_IN ( dwMsg ) )
	{
		if( UIMSG_LB_DUP & dwMsg )
		{
			// 윈도우를 디폴트 포지션으로 이동
			AddMessageEx( UIMSG_CTFINFO_LBDUP );
			SetDiffuse ( D3DCOLOR_ARGB ( 0xFF, 0xFF, 0xFF, 0xFF ) );
			return ;
		}
		
		if ( dwMsg & UIMSG_LB_DOWN )
		{
			//	단독 컨트롤로 등록하고,
			SetExclusiveControl();	

			//	최초 포지션 갭을 기록한다.
			if ( !m_bFirstGap )
			{
				UIRECT rcPos = GetGlobalPos ();
				m_vGap.x = m_PosX - rcPos.left;
				m_vGap.y = m_PosY - rcPos.top;
				m_bFirstGap = TRUE;

				SetDiffuse ( D3DCOLOR_ARGB ( 0xB4, 0xFF, 0xFF, 0xFF ) );
			}
		}
		else if ( CHECK_LB_UP_LIKE ( dwMsg ) )
		{
			//	단독 컨트롤을 해제하고
			ResetExclusiveControl();
			//	최초 포지션갭을 해제한다.
			m_bFirstGap = FALSE;				

			SetDiffuse ( D3DCOLOR_ARGB ( 0xFF, 0xFF, 0xFF, 0xFF ) );
		}
	}
	//	컨트롤 영역밖에서 버튼을 떼는 경우가 발생하더라도
	else if ( CHECK_LB_UP_LIKE ( dwMsg ) )		
	{								
		//	단독 컨트롤을 해제하고,
		ResetExclusiveControl();
		//	최초 포지션갭을 해제한다.
		m_bFirstGap = FALSE;					

		SetDiffuse ( D3DCOLOR_ARGB ( 0xFF, 0xFF, 0xFF, 0xFF ) );
	}
}
void CCTFInfoDisplay::ShowMPFaci()
{
	HideNULL();
	m_pFacility_SG->SetVisibleSingle ( FALSE );
	m_pFacility_MP->SetVisibleSingle ( TRUE );
	m_pFacility_PHX->SetVisibleSingle ( FALSE );
}
void CCTFInfoDisplay::ShowMPNucl()
{
	HideNULL();
	m_pNuclear_SG->SetVisibleSingle ( FALSE );
	m_pNuclear_MP->SetVisibleSingle ( TRUE );
	m_pNuclear_PHX->SetVisibleSingle ( FALSE );
}
void CCTFInfoDisplay::ShowMPTher()
{	
	HideNULL();
	m_pThermal_SG->SetVisibleSingle ( FALSE );
	m_pThermal_MP->SetVisibleSingle ( TRUE );
	m_pThermal_PHX->SetVisibleSingle ( FALSE );
}

void CCTFInfoDisplay::ShowSGFaci()
{
	HideNULL();
	m_pFacility_SG->SetVisibleSingle ( TRUE );
	m_pFacility_MP->SetVisibleSingle ( FALSE );
	m_pFacility_PHX->SetVisibleSingle ( FALSE );
}
void CCTFInfoDisplay::ShowSGNucl()
{
	HideNULL();
	m_pNuclear_SG->SetVisibleSingle ( TRUE );
	m_pNuclear_MP->SetVisibleSingle ( FALSE );
	m_pNuclear_PHX->SetVisibleSingle ( FALSE );
}
void CCTFInfoDisplay::ShowSGTher()
{
	HideNULL();
	m_pThermal_SG->SetVisibleSingle ( TRUE );
	m_pThermal_MP->SetVisibleSingle ( FALSE );
	m_pThermal_PHX->SetVisibleSingle ( FALSE );
}

void CCTFInfoDisplay::ShowPHXFaci()
{
	HideNULL();
	m_pFacility_SG->SetVisibleSingle ( FALSE );
	m_pFacility_MP->SetVisibleSingle ( FALSE );
	m_pFacility_PHX->SetVisibleSingle ( TRUE );
}
void CCTFInfoDisplay::ShowPHXNucl()
{
	HideNULL();
	m_pNuclear_SG->SetVisibleSingle ( FALSE );
	m_pNuclear_MP->SetVisibleSingle ( FALSE );
	m_pNuclear_PHX->SetVisibleSingle ( TRUE );
}
void CCTFInfoDisplay::ShowPHXTher()
{
	HideNULL();
	m_pThermal_SG->SetVisibleSingle ( FALSE );
	m_pThermal_MP->SetVisibleSingle ( FALSE );
	m_pThermal_PHX->SetVisibleSingle ( TRUE );
}
void CCTFInfoDisplay::ShowNULLFaci()
{
	m_pFacility_NULL->SetVisibleSingle ( TRUE );
}
void CCTFInfoDisplay::ShowNULLNulc()
{
	m_pNuclear_NULL->SetVisibleSingle ( TRUE );
}
void CCTFInfoDisplay::ShowNULLTher()
{
	m_pThermal_NULL->SetVisibleSingle ( TRUE );
}
void CCTFInfoDisplay::HideNULL()
{
	m_pThermal_NULL->SetVisibleSingle ( FALSE );
	m_pNuclear_NULL->SetVisibleSingle ( FALSE );
	m_pFacility_NULL->SetVisibleSingle ( FALSE );
}
void CCTFInfoDisplay::HideCTFInfo()
{
	m_pBackGroundLeft->SetVisibleSingle ( FALSE );
	m_pBackGroundBody->SetVisibleSingle ( FALSE );
	m_pBackGroundRight->SetVisibleSingle ( FALSE );
	m_pDisplayLine1->SetVisibleSingle ( FALSE );
	m_pDisplayLine2->SetVisibleSingle ( FALSE );

	m_pThermalTowerText->SetVisibleSingle ( FALSE );
	m_pFacilityTowerText->SetVisibleSingle ( FALSE );
	m_pNuclearTowerText->SetVisibleSingle ( FALSE );

	m_pNuclear_SG->SetVisibleSingle ( FALSE );
	m_pNuclear_MP->SetVisibleSingle ( FALSE );
	m_pNuclear_PHX->SetVisibleSingle ( FALSE );

	m_pThermal_SG->SetVisibleSingle ( FALSE );
	m_pThermal_MP->SetVisibleSingle ( FALSE );
	m_pThermal_PHX->SetVisibleSingle ( FALSE );

	m_pFacility_SG->SetVisibleSingle ( FALSE );
	m_pFacility_MP->SetVisibleSingle ( FALSE );
	m_pFacility_PHX->SetVisibleSingle ( FALSE );

	HideNULL();
}