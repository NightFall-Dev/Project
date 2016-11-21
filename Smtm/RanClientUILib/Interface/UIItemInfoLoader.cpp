#include "StdAfx.h"
#include "UIInfoLoader.h"
#include "GLGaeaClient.h"
#include "GLItemMan.h"
#include "GLItemDef.h"
#include "GLItem.h"
#include "GameTextControl.h"
#include "UITextControl.h"
#include "InnerInterface.h"

#include "../EngineLib/DxCommon/DxFontMan.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace NS_ITEMINFO
{
    SITEMCUSTOM	m_sItemCustomBACK;
	BOOL		m_bShopOpenBACK;
    BOOL		m_bInMarketBACK;
	BOOL		m_bInPrivateMarketBACK;
	BOOL		m_bIsWEAR_ITEMBACK;
	WORD		m_wPosXBACK;
	WORD		m_wPosYBACK;
	BOOL		m_bITEMLINK;

	void	RESET ()
	{
		m_sItemCustomBACK.sNativeID = NATIVEID_NULL ();
		m_bShopOpenBACK = FALSE;
		m_bInMarketBACK = FALSE;
		m_bInPrivateMarketBACK = FALSE;
		m_bIsWEAR_ITEMBACK = FALSE;
		m_bITEMLINK = FALSE;
		ResetItemRender ();	
	}
	
	void AddItemRender ( SNATIVEID sICONINDEX, const char* szTexture ) 
	{ 
		CInnerInterface::GetInstance().ADDITEM_RENDER ( sICONINDEX, szTexture ); 
	} 
	
	void ResetItemRender () 
	{ 
		CInnerInterface::GetInstance().RESETITEM_RENDER ();	
	}  

	void AddTextNoSplitBig ( CString strText, D3DCOLOR dwColor )
	{
		CInnerInterface::GetInstance().ADDTEXT_NOSPLIT_BIG ( strText, dwColor );
	}
	void AddTextNoSplit ( CString strText, D3DCOLOR dwColor )
	{
		CInnerInterface::GetInstance().ADDTEXT_NOSPLIT ( strText, dwColor );
	}

	void AddTextLongestLineSplit ( CString strText, D3DCOLOR dwColor )
	{
		CInnerInterface::GetInstance().ADDTEXT_LONGESTLINE_SPLIT ( strText, dwColor );
	}

	void AddTextMultiColorSplit ( CString strText , D3DCOLOR dwColor, CString strText2 , D3DCOLOR dwColor2 )
	{
		CInnerInterface::GetInstance().ADDTEXT_MULTICOLORSPLIT ( strText, dwColor ,  strText2 , dwColor2 );
	}
	void AddTextMultiColorSplit4 ( CString strText , D3DCOLOR dwColor , CString strText2 , D3DCOLOR dwColor2 ,CString strText3 , D3DCOLOR dwColor3 ,CString strText4 , D3DCOLOR dwColor4 )
	{
		CInnerInterface::GetInstance().ADDTEXT_MULTICOLORSPLIT4 ( strText, dwColor , strText2 , dwColor2 , strText3, dwColor3 ,strText4 , dwColor4 );
	}
	void AddTextMultiColorSplit2 ( CString strText , D3DCOLOR dwColor , CString strText2 , D3DCOLOR dwColor2 ,CString strText3 , D3DCOLOR dwColor3 ,CString strText4 , D3DCOLOR dwColor4 )
	{
		CInnerInterface::GetInstance().ADDTEXT_MULTICOLORSPLIT2 ( strText, dwColor , strText2 , dwColor2 , strText3, dwColor3 ,strText4 , dwColor4 );
	}
	void AddTextMultiColorSplit3 ( CString strText , D3DCOLOR dwColor , CString strText2 , D3DCOLOR dwColor2 ,CString strText3 , D3DCOLOR dwColor3 ,CString strText4 , D3DCOLOR dwColor4 , CString strText5 , D3DCOLOR dwColor5 )
	{
		CInnerInterface::GetInstance().ADDTEXT_MULTICOLORSPLIT3 ( strText, dwColor , strText2 , dwColor2 , strText3, dwColor3 ,strText4 , dwColor4 , strText5 , dwColor5 );
	}
	void RemoveAllInfo ()
	{
		CInnerInterface::GetInstance().CLEAR_TEXT ();
	}

	char*	GetNumberWithSign ( int nValue )
	{
		static	char szNumber[128];

		if ( 0 < nValue )
		{
			StringCchPrintf ( szNumber, 128, "(+%d)", nValue );
		}
		else if ( nValue < 0 )
		{
			StringCchPrintf ( szNumber, 128, "(%d)", nValue );
		}

		return szNumber;
	}

	char*	GetNumberWithSign2 ( int nValue )
	{
		static	char szNumber[128];

		if ( 0 < nValue )
		{
			StringCchPrintf ( szNumber, 128, " +%d", nValue );
		}
		else if ( nValue < 0 )
		{
			StringCchPrintf ( szNumber, 128, " %d", nValue );
		}

		return szNumber;
	}
	void AddInfoItemAddon ( int nBasic, int nAddon, CString strFormat )
	{
		CString Text;
		CString sText;
		if ( nAddon )
		{
			//Text.Format ( "%s: %d%s", strFormat, nBasic, GetNumberWithSign ( nAddon ) );
			//AddTextNoSplit ( Text, NS_UITEXTCOLOR::WHITE );
			Text.Format ( "%s:%d", strFormat, nBasic );
			sText.Format ( "%s",GetNumberWithSign ( nAddon ) );
			AddTextMultiColorSplit( Text ,NS_UITEXTCOLOR::WHITE, sText , NS_UITEXTCOLOR::GOLD );
			//AddTextNoSplit ( Text, NS_UITEXTCOLOR::WHITE );
			//AddTextMultiColorSplit( Text , sText );
		}
		else if ( nBasic )
		{
			Text.Format ( "%s:%d", strFormat, nBasic );
			AddTextNoSplit ( Text, NS_UITEXTCOLOR::WHITE );
		}
	}

	void APPEND_ITEM_GRADE ( CString& strOrigin, BYTE uGRADE )
	{
		if ( !uGRADE ) return ;

		CString strGRADE;
		strGRADE.Format ( "+%d ", uGRADE );
		strOrigin += strGRADE;
	}

	void APPEND_ITEM_GRADE2 ( CString& strOrigin, BYTE uGRADE )
	{
		if ( !uGRADE ) return ;

		CString strGRADE;
		strGRADE.Format ( "(+%d) ", uGRADE );
		strOrigin += strGRADE;
	}

	void AddInfoItemAddon ( int nBasic, int nAddon, BYTE uGRADE, CString strFormat )
	{
		CString Text;
		CString sText;
		if ( nAddon )
		{
			//Text.Format ( "%s: %d%s", strFormat, nBasic, GetNumberWithSign( nAddon ) );
			//APPEND_ITEM_GRADE ( Text, uGRADE );
			//AddTextNoSplit ( Text, NS_UITEXTCOLOR::WHITE );

			Text.Format ( "%s:%d", strFormat, nBasic );
			sText.Format ( "%s",GetNumberWithSign ( nAddon ) );
			APPEND_ITEM_GRADE ( sText, uGRADE );
			AddTextMultiColorSplit( Text , NS_UITEXTCOLOR::WHITE , sText , NS_UITEXTCOLOR::GOLD );
			//AddTextNoSplit ( Text, NS_UITEXTCOLOR::WHITE );
		}
		else if ( nBasic )
		{
			Text.Format ( "%s: %d", strFormat, nBasic );
			APPEND_ITEM_GRADE ( Text, uGRADE );
			AddTextNoSplit ( Text, NS_UITEXTCOLOR::WHITE );
		}
	}

	void AddInfoItemAddonRange ( int nBasicMin, int nBasicMax, int nAddon, BYTE uGRADE, CString strFormat )
	{
		CString Text;
		CString sText;
		CString ssText;
		CString sssText;
		if ( nAddon )
		{
			//Text.Format ( "%s: %d%s~%d%s", strFormat, nBasicMin, GetNumberWithSign( nAddon ) );
			Text.Format ( "%s: %d", strFormat, nBasicMin );
			sText.Format ( "%s", GetNumberWithSign( nAddon ) );

			ssText.Format ( "~%d",  nBasicMax );
			sssText.Format ( "%s", GetNumberWithSign( nAddon ) );
			
			AddTextMultiColorSplit2( Text , NS_UITEXTCOLOR::WHITE , sText , NS_UITEXTCOLOR::GOLD , ssText , NS_UITEXTCOLOR::WHITE , sssText , NS_UITEXTCOLOR::GOLD );
			//AddTextMultiColorSplit( ssText , sssText );
            //APPEND_ITEM_GRADE ( Text, uGRADE );
			//AddTextNoSplit ( Text, NS_UITEXTCOLOR::WHITE );
		}
		else if ( nBasicMin || nBasicMax )
		{
			Text.Format ( "%s: %d~%d",strFormat, nBasicMin, nBasicMax );
			//APPEND_ITEM_GRADE ( Text, uGRADE );
			AddTextNoSplit ( Text, NS_UITEXTCOLOR::WHITE );
		}
	}

	void AddItemTurnInfo ( const SITEMCUSTOM &sItemCustom, const BOOL bInMarket, const BOOL bInPrivateMarket )
	{
		SITEM* pItemData = GLItemMan::GetInstance().GetItem ( sItemCustom.sNativeID );

		CString strText;

		//switch ( pItemData->sBasicOp.emItemType )
		//{
		//case ITEM_CHARM:
		//case ITEM_ARROW:
		//case ITEM_CURE:
		//case ITEM_GRINDING:
			if ( pItemData->sDrugOp.wPileNum > 1 )
			{
				WORD wPileNum = pItemData->sDrugOp.wPileNum;
				WORD wTurnNum = sItemCustom.wTurnNum;				
				if ( bInPrivateMarket )	//	개인 상점
				{
					strText.Format("%s:%d", ID2GAMEWORD("ITEM_TURN_INFO", 0 ), wTurnNum);
					AddTextNoSplit(strText,NS_UITEXTCOLOR::CHARTREUSE);

					return ;
				}

				if ( bInMarket )	wTurnNum = pItemData->GETAPPLYNUM();
				strText.Format("%s:%d/%d", ID2GAMEWORD("ITEM_TURN_INFO", 0 ), wTurnNum, wPileNum);
				AddTextNoSplit(strText,NS_UITEXTCOLOR::WHITE);
			}
			//break;
		//}
	}

	void AddInfoPetSkillItem( const SITEMCUSTOM &sItemCustom )
	{
		CString strText;

		SNATIVEID sNativeID = sItemCustom.sNativeID;
		GLPetClient* pPetClient = GLGaeaClient::GetInstance().GetPetClient();
		SITEM* pItemData = GLItemMan::GetInstance().GetItem ( sNativeID );
		SNATIVEID sSkillID = pItemData->sSkillBookOp.sSkill_ID;

		//	Note : 스킬 정보 가져옴.
		PGLSKILL pSkill = GLSkillMan::GetInstance().GetData ( sSkillID.wMainID, sSkillID.wSubID );
		if ( pSkill )
		{
			//	기본 정보
			//{
			//	//	3. 속성
			//	strText.Format("%s:%s",ID2GAMEWORD("SKILL_BASIC_INFO", 2), COMMENT::BRIGHT[pSkill->m_sLEARN.emBRIGHT].c_str());
			//	AddTextNoSplit(strText,NS_UITEXTCOLOR::PALEGREEN);
			//}

			//{
			//	//	목표 가능거리
			//	const SKILL::SBASIC& sBASIC = pSkill->m_sBASIC;		

			//	if ( sBASIC.wTARRANGE )
			//	{
			//		strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_TARGET_RANGE", 0), sBASIC.wTARRANGE);
			//		AddTextNoSplit(strText, NS_UITEXTCOLOR::WHITE );
			//	}
			//}

			//	이미 배운 스킬
			if ( pPetClient->ISLEARNED_SKILL( sSkillID ) )
			{
				AddTextNoSplit ( ID2GAMEWORD ( "ITEM_SKILL_CONDITION", 0 ), NS_UITEXTCOLOR::RED );	
				return ;
			}
		}
	}

	void AddInfoSkillItem ( const SITEMCUSTOM &sItemCustom )
	{
		CString strText;

		SNATIVEID sNativeID = sItemCustom.sNativeID;
		GLCharacter* pCharacter = GLGaeaClient::GetInstance().GetCharacter();	
		SITEM* pItemData = GLItemMan::GetInstance().GetItem ( sNativeID );
		SNATIVEID sSkillID = pItemData->sSkillBookOp.sSkill_ID;

		//	Note : 스킬 정보 가져옴.
		PGLSKILL pSkill = GLSkillMan::GetInstance().GetData ( sSkillID.wMainID, sSkillID.wSubID );
		if ( pSkill )
		{
			//	기본 정보
			{
				//	2. Skill Rank / Level
				strText.Format("Rank %d", pSkill->m_sBASIC.dwGRADE);
				//AddTextNoSplit(strText,NS_UITEXTCOLOR::WHITE);

				/*//	3. 속성
				strText.Format("%s:%s",ID2GAMEWORD("SKILL_BASIC_INFO", 2), COMMENT::BRIGHT[pSkill->m_sLEARN.emBRIGHT].c_str());
				AddTextNoSplit(strText,NS_UITEXTCOLOR::PALEGREEN);*/

				//	4. 직업
				//strText.Format ("%s:", ID2GAMEWORD("SKILL_BASIC_INFO", 3) );
				/*if ( pSkill->m_sLEARN.dwCLASS & GLCC_FIGHTER_M )		strText.AppendFormat ( "%s", COMMENT::CHARCLASS[0].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_FIGHTER_W )		strText.AppendFormat ( "%s", COMMENT::CHARCLASS[6].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_ARMS_M )			strText.AppendFormat ( "%s", COMMENT::CHARCLASS[1].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_ARMS_W )			strText.AppendFormat ( "%s", COMMENT::CHARCLASS[7].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_ARCHER_M )		strText.AppendFormat ( "%s", COMMENT::CHARCLASS[8].c_str() );				
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_ARCHER_W )		strText.AppendFormat ( "%s", COMMENT::CHARCLASS[2].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_SPIRIT_M )		strText.AppendFormat ( "%s", COMMENT::CHARCLASS[9].c_str() );				
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_SPIRIT_W )		strText.AppendFormat ( "%s", COMMENT::CHARCLASS[3].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_EXTREME_M )	strText.AppendFormat ( "%s", COMMENT::CHARCLASS[4].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_EXTREME_W )	strText.AppendFormat ( "%s", COMMENT::CHARCLASS[5].c_str() );
				//add class
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_SCIENCE_M )	strText.AppendFormat ( "%s", COMMENT::CHARCLASS[10].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_SCIENCE_W )	strText.AppendFormat ( "%s", COMMENT::CHARCLASS[11].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_ASSASIN_M )	strText.AppendFormat ( "%s", COMMENT::CHARCLASS[12].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_ASSASIN_W )	strText.AppendFormat ( "%s", COMMENT::CHARCLASS[13].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_TESTING_M )	strText.AppendFormat ( "%s", COMMENT::CHARCLASS[14].c_str() );
				if ( pSkill->m_sLEARN.dwCLASS & GLCC_TESTING_W )	strText.AppendFormat ( "%s", COMMENT::CHARCLASS[15].c_str() );*/
				
				if ( ( pSkill->m_sLEARN.dwCLASS & GLCC_FIGHTER_M ) || ( pSkill->m_sLEARN.dwCLASS & GLCC_FIGHTER_W ) )	strText.AppendFormat ( " Brawler Class" );
				if ( ( pSkill->m_sLEARN.dwCLASS & GLCC_ARMS_M ) || ( pSkill->m_sLEARN.dwCLASS & GLCC_ARMS_W ) )			strText.AppendFormat ( " Swordie Class" );
				if ( ( pSkill->m_sLEARN.dwCLASS & GLCC_ARCHER_M ) || ( pSkill->m_sLEARN.dwCLASS & GLCC_ARCHER_W ) )		strText.AppendFormat ( " Archer Class" );
				if ( ( pSkill->m_sLEARN.dwCLASS & GLCC_SPIRIT_M ) || ( pSkill->m_sLEARN.dwCLASS & GLCC_SPIRIT_W ) )		strText.AppendFormat ( " Shamman Class" );
				if ( ( pSkill->m_sLEARN.dwCLASS & GLCC_EXTREME_M ) || ( pSkill->m_sLEARN.dwCLASS & GLCC_EXTREME_W ) )	strText.AppendFormat ( " Extreme Class" );
				//add class "SCIENCE"
				if ( ( pSkill->m_sLEARN.dwCLASS & GLCC_SCIENCE_M ) || ( pSkill->m_sLEARN.dwCLASS & GLCC_SCIENCE_W ) )	strText.AppendFormat ( "Gunner Class" );
				//add class "ASSASSIN"
				if ( ( pSkill->m_sLEARN.dwCLASS & GLCC_ASSASIN_M ) || ( pSkill->m_sLEARN.dwCLASS & GLCC_ASSASIN_W ) )	strText.AppendFormat ( "Assassin Class" );
				//add class "MAGICIAN"
				if ( ( pSkill->m_sLEARN.dwCLASS & GLCC_MAGICIAN_M ) || ( pSkill->m_sLEARN.dwCLASS & GLCC_MAGICIAN_W ) )	strText.AppendFormat ( "Magician Class" );
				
				AddTextNoSplit(strText,NS_UITEXTCONTROL::GetEvaluateColor ( pItemData->sBasicOp.dwReqCharClass & pCharacter->m_emClass ) );
			}

			{
				//	목표 가능거리, 왼손, 오른손 도구
				const SKILL::SBASIC& sBASIC = pSkill->m_sBASIC;		

				if ( sBASIC.wTARRANGE )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_TARGET_RANGE", 0), sBASIC.wTARRANGE);
					AddTextNoSplit(strText, NS_UITEXTCOLOR::WHITE );
				}

				if ( (sBASIC.emUSE_LITEM && (sBASIC.emUSE_LITEM != ITEMATT_NOCARE)) || 
					(sBASIC.emUSE_RITEM && (sBASIC.emUSE_RITEM != ITEMATT_NOCARE)) )
				{
					AddTextNoSplit(ID2GAMEWORD("SKILL_CATEGORY", 1),NS_UITEXTCOLOR::LIGHTSKYBLUE);
				}

				CString strUSEITEM;
				if ( sBASIC.emUSE_LITEM )
				{
					if ( sBASIC.emUSE_LITEM != ITEMATT_NOCARE )
					{
						strText.Format( "%s:%s", 
										ID2GAMEWORD( "SKILL_ADVANCED_USE_ITEM_LR_HAND", 0), 
										ID2GAMEWORD( "SKILL_ADVANCED_USE_ITEM", sBASIC.emUSE_LITEM - 1 ) );
						AddTextNoSplit(strText, NS_UITEXTCOLOR::WHITE );
					}
				}

				if ( sBASIC.emUSE_RITEM )
				{
					if ( sBASIC.emUSE_RITEM != ITEMATT_NOCARE )
					{
						strText.Format ( "%s:%s", 
										ID2GAMEWORD( "SKILL_ADVANCED_USE_ITEM_LR_HAND", 1), 
										ID2GAMEWORD( "SKILL_ADVANCED_USE_ITEM", sBASIC.emUSE_RITEM - 1 ) );
						AddTextNoSplit(strText, NS_UITEXTCOLOR::WHITE );
					}
				}
			}

			//	이미 배운 스킬
			if ( pCharacter->GETLEARNED_SKILL ( sSkillID ) )
			{
				AddTextNoSplit ( ID2GAMEWORD ( "ITEM_SKILL_CONDITION", 0 ), NS_UITEXTCOLOR::RED );	
				return ;
			}

			//	요구치 정보
			{
				AddTextNoSplit( ID2GAMEWORD("SKILL_CATEGORY", 7), NS_UITEXTCOLOR::LIGHTSKYBLUE);

				const WORD wLevel = 0;
				SKILL::SLEARN& sLEARN = pSkill->m_sLEARN;
				SKILL::SLEARN_LVL& sLVL = sLEARN.sLVL_STEP[wLevel];
			
				//	1. 요구보유스킬
				SNATIVEID NeedSkillID = pSkill->m_sLEARN.sSKILL;			
				if ( NeedSkillID != NATIVEID_NULL() )
				{
					BOOL bVALID = FALSE;
					BOOL bNeedSkillLevel = FALSE;

					CString strNeedSkillName;
					CString strNeedSkillLevel;

					PGLSKILL pNeedSkill = GLSkillMan::GetInstance().GetData ( NeedSkillID.wMainID, NeedSkillID.wSubID );
					strNeedSkillName.Format("%s:%s", ID2GAMEWORD( "SKILL_ADVANCED_INFO", 0), pNeedSkill->GetName() );
					bVALID = pCharacter->ISLEARNED_SKILL ( NeedSkillID );			

					//	2. 요구보유스킬레벨
					if ( 0 < sLVL.dwSKILL_LVL )
					{
						strNeedSkillLevel.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO", 1), (sLVL.dwSKILL_LVL + 1) );
						bNeedSkillLevel = TRUE;

						SCHARDATA2::SKILL_MAP& map = pCharacter->m_ExpSkills;				
						SCHARDATA2::SKILL_MAP_ITER iter = map.find ( NeedSkillID.dwID );
						if ( iter != map.end() )
						{
							SCHARSKILL& rCharSkill = (*iter).second;

							//	색 조절
							bVALID = rCharSkill.wLevel >= sLVL.dwSKILL_LVL;						
						}
					}

					AddTextNoSplit(strNeedSkillName,NS_UITEXTCONTROL::GetEvaluateColor ( bVALID ));

					if ( bNeedSkillLevel )
						AddTextNoSplit(strNeedSkillLevel, NS_UITEXTCONTROL::GetEvaluateColor ( bVALID ) );
				}

				//	3. 요구경험치
				if ( 0 < sLVL.dwSKP )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO", 2), sLVL.dwSKP);				
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->m_dwSkillPoint >= sLVL.dwSKP ) );
				}

				//	4. 요구레벨
				if ( 0 < sLVL.dwLEVEL )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO", 3), sLVL.dwLEVEL);
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->GETLEVEL () >= int(sLVL.dwLEVEL) ) );
				}

				if ( 0 < sLVL.dwREBORN )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO", 4), sLVL.dwREBORN);
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->GETREBORN () >= int(sLVL.dwREBORN) ) );
				}

				if ( 0 < sLVL.dwMoneyReq )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO", 5), sLVL.dwMoneyReq );
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->m_lnMoney >= int(sLVL.dwMoneyReq ) ) );
				}
				if ( 0 < sLVL.dwPremPoint )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO", 6), sLVL.dwPremPoint );
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->m_lnPremP >= int(sLVL.dwPremPoint ) ) );
				}
				if ( 0 < sLVL.dwVotePoint )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO", 7), sLVL.dwVotePoint );
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->m_lnVoteP >= int(sLVL.dwVotePoint ) ) );
				}

				//	5. 조건 - 암광
				BOOL bValue = TRUE;
				strText.Format ( "%s", COMMENT::BRIGHT[pItemData->sBasicOp.emReqBright].c_str() );
				if ( pItemData->sBasicOp.emReqBright != BRIGHT_BOTH )
				{
					if ( pCharacter->GETBRIGHT() != pItemData->sBasicOp.emReqBright )
					{
						bValue = FALSE;
					}
				}
				AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor ( bValue ) );


				//	Stats
				//	1. 요구힘
				if ( 0 < sLVL.sSTATS.dwPow )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO_STATS", 0), sLVL.sSTATS.dwPow);
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->m_sSUMSTATS.dwPow >= sLVL.sSTATS.dwPow ) );
				}

				//	2. 요구체력
				if ( 0 < sLVL.sSTATS.dwStr )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO_STATS", 1), sLVL.sSTATS.dwStr);
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->m_sSUMSTATS.dwStr >= sLVL.sSTATS.dwStr ) );
				}

				//	3. 요구정신
				if ( 0 < sLVL.sSTATS.dwSpi )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO_STATS", 2), sLVL.sSTATS.dwSpi);
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->m_sSUMSTATS.dwSpi >= sLVL.sSTATS.dwSpi ));
				}

				//	4. 요구민첩
				if ( 0 < sLVL.sSTATS.dwDex )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO_STATS", 3), sLVL.sSTATS.dwDex);
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->m_sSUMSTATS.dwDex >= sLVL.sSTATS.dwDex ) );
				}

				//	5. 요구지력
				if ( 0 < sLVL.sSTATS.dwInt )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO_STATS", 4), sLVL.sSTATS.dwInt);
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->m_sSUMSTATS.dwInt >= sLVL.sSTATS.dwInt ) );
				}

				//	6. 요구근력
				if ( 0 < sLVL.sSTATS.dwSta )
				{
					strText.Format("%s:%d",ID2GAMEWORD( "SKILL_ADVANCED_INFO_STATS", 5), sLVL.sSTATS.dwSta);
					AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pCharacter->m_sSUMSTATS.dwSta >= sLVL.sSTATS.dwSta ) );
				}
			}
		}
	}

	void AddTextAddValue( const SITEMCUSTOM & sItemCustom, const ITEM::SSUIT & sSUIT )
	{
		CString strText;
		BOOL bLEAST_HAVE_ONE(TRUE);
		BOOL bADD_HP(FALSE), bADD_MP(FALSE), bADD_SP(FALSE), bADD_MA(FALSE);
		INT arrVALUE[EMADD_SIZE];
		SecureZeroMemory( arrVALUE, sizeof(arrVALUE) );

		for ( int i = 0; i < ITEM::SSUIT::ADDON_SIZE; ++i )
		{
			EMITEM_ADDON emTYPE = sSUIT.sADDON[i].emTYPE;

			if ( emTYPE != EMADD_NONE )
			{
				//	NOTE
				//		가산효과가 존재할경우에만 타이틀을
				//		출력하기 위해, 적어도 하나가 존재할때
				//		뿌린다는 것을 체크한다.
				if ( bLEAST_HAVE_ONE )
				{
					//AddTextNoSplit( ID2GAMEWORD ( "ITEM_CATEGORY", 10 ),NS_UITEXTCOLOR::LIGHTSKYBLUE);
					bLEAST_HAVE_ONE = FALSE;
				}

				int nVALUE = sSUIT.sADDON[i].nVALUE;

				switch ( emTYPE )
				{
				case EMADD_HP:
					if( !bADD_HP )
					{
						arrVALUE[EMADD_HP] = sItemCustom.GETADDHP();
						bADD_HP = TRUE;
					}
					break;
				case EMADD_MP:
					if( !bADD_MP )
					{
						arrVALUE[EMADD_MP] = sItemCustom.GETADDMP();
						bADD_MP = TRUE;
					}
					break;
				case EMADD_SP:
					if( !bADD_SP )
					{
						arrVALUE[EMADD_SP] = sItemCustom.GETADDSP();
						bADD_SP = TRUE;
					}
					break;
				case EMADD_MA:
					if( !bADD_MA )
					{
						arrVALUE[EMADD_MA] = sItemCustom.GETADDMA();
						bADD_MA = TRUE;
					}
					break;
				case EMADD_HITRATE:		arrVALUE[EMADD_HITRATE] += nVALUE;		break;
				case EMADD_AVOIDRATE:	arrVALUE[EMADD_AVOIDRATE] += nVALUE;	break;
				case EMADD_DAMAGE:		arrVALUE[EMADD_DAMAGE] += nVALUE;		break;
				case EMADD_DEFENSE:		arrVALUE[EMADD_DEFENSE] += nVALUE;		break;
				case EMADD_STATS_POW:	arrVALUE[EMADD_STATS_POW] += nVALUE;	break;
				case EMADD_STATS_STR:	arrVALUE[EMADD_STATS_STR] += nVALUE;	break;
				case EMADD_STATS_SPI:	arrVALUE[EMADD_STATS_SPI] += nVALUE;	break;
				case EMADD_STATS_DEX:	arrVALUE[EMADD_STATS_DEX] += nVALUE;	break;
				case EMADD_STATS_INT:	arrVALUE[EMADD_STATS_INT] += nVALUE;	break;
				case EMADD_STATS_STA:	arrVALUE[EMADD_STATS_STA] += nVALUE;	break;
				case EMADD_PA:			arrVALUE[EMADD_PA] += nVALUE;			break;
				case EMADD_SA:			arrVALUE[EMADD_SA] += nVALUE;			break;
				case EMADD_CP:			arrVALUE[EMADD_CP] += nVALUE;			break; //add cp
				};
			}
		}

		for( int i=1; i<EMADD_SIZE; ++i)
		{
			if( arrVALUE[i] != 0 )
			{
				strText.Format( "%s:%s", ID2GAMEWORD( "ITEM_ADDON_INFO", i ), GetNumberWithSign2( arrVALUE[i] ) );
				AddTextNoSplit( strText, NS_UITEXTCOLOR::LIME );
			}
		}

		if ( sItemCustom.nidDISGUISE!=SNATIVEID(false) )
		{
			SITEM* pJDisguiseData = GLItemMan::GetInstance().GetItem ( sItemCustom.nidDISGUISE );
			if ( pJDisguiseData )
			{
				if ( pJDisguiseData->sBasicOp.IsCostumeCombine() )
				{
					//add jitem
					INT arrVALUECOS[EMADD_SIZE];
					SecureZeroMemory( arrVALUECOS, sizeof(arrVALUECOS) );
	
					for ( int j = 0; j < ITEM::SSUIT::ADDON_SIZE; ++j )
					{
						EMITEM_ADDON emTYPEJ = pJDisguiseData->sSuitOp.sADDON[j].emTYPE;

						if ( emTYPEJ != EMADD_NONE )
						{
							if ( bLEAST_HAVE_ONE )
							{
								AddTextNoSplit( ID2GAMEWORD ( "ITEM_CATEGORY", 13 ),NS_UITEXTCOLOR::PALEGREEN);
								bLEAST_HAVE_ONE = FALSE;
							}

							int nVALUECOS = pJDisguiseData->sSuitOp.sADDON[j].nVALUE;
							switch ( emTYPEJ )
							{
								case EMADD_HP:			arrVALUECOS[EMADD_HP] += nVALUECOS;			break;
								case EMADD_MP:			arrVALUECOS[EMADD_MP] += nVALUECOS;			break;
								case EMADD_SP:			arrVALUECOS[EMADD_SP] += nVALUECOS;			break;
								case EMADD_MA:			arrVALUECOS[EMADD_MA] += nVALUECOS;			break;
								case EMADD_HITRATE:		arrVALUECOS[EMADD_HITRATE] += nVALUECOS;		break;
								case EMADD_AVOIDRATE:	arrVALUECOS[EMADD_AVOIDRATE] += nVALUECOS;		break;
								case EMADD_DAMAGE:		arrVALUECOS[EMADD_DAMAGE] += nVALUECOS;		break;
								case EMADD_DEFENSE:		arrVALUECOS[EMADD_DEFENSE] += nVALUECOS;		break;
								case EMADD_STATS_POW:	arrVALUECOS[EMADD_STATS_POW] += nVALUECOS;		break;
								case EMADD_STATS_STR:	arrVALUECOS[EMADD_STATS_STR] += nVALUECOS;		break;
								case EMADD_STATS_SPI:	arrVALUECOS[EMADD_STATS_SPI] += nVALUECOS;		break;
								case EMADD_STATS_DEX:	arrVALUECOS[EMADD_STATS_DEX] += nVALUECOS;		break;
								case EMADD_STATS_INT:	arrVALUECOS[EMADD_STATS_INT] += nVALUECOS;		break;
								case EMADD_STATS_STA:	arrVALUECOS[EMADD_STATS_STA] += nVALUECOS;		break;
								case EMADD_PA:			arrVALUECOS[EMADD_PA] += nVALUECOS;			break;
								case EMADD_SA:			arrVALUECOS[EMADD_SA] += nVALUECOS;			break;
								case EMADD_CP:			arrVALUECOS[EMADD_CP] += nVALUECOS;			break; //add cp
							};
						}
					}

					CString strTextCos;
					for( int i=1; i<EMADD_SIZE; ++i)
					{
						if( arrVALUECOS[i] != 0 )
						{
							strTextCos.Format( "%s:%s", ID2GAMEWORD( "ITEM_ADDON_INFOCOS", i ), GetNumberWithSign2( arrVALUECOS[i] ) );
							AddTextNoSplit( strTextCos, NS_UITEXTCOLOR::LIME );
						}		
					}
				}
			}	
		}
	}

	void LOAD_SIMPLE ( const SITEMCUSTOM &sItemCustom )
	{
		if ( m_sItemCustomBACK == sItemCustom ) return ;

		m_sItemCustomBACK = sItemCustom;

		RemoveAllInfo();

		SITEM* pItemData = GLItemMan::GetInstance().GetItem ( sItemCustom.sNativeID );
		if ( !pItemData ) return ;
		
		DWORD dwLevel = pItemData->sBasicOp.emLevel;
		//	이름
		AddTextNoSplit ( pItemData->GetName(), COMMENT::ITEMCOLOR[dwLevel] );
	}

	void LOAD ( const SITEMCUSTOM &sItemCustom, const BOOL bShopOpen, const BOOL bInMarket, const BOOL bInPrivateMarket, const BOOL bIsWEAR_ITEM, WORD wPosX, WORD wPosY, SNATIVEID sNpcNativeID, BOOL bITEMLINK )
	{	
		if ( m_sItemCustomBACK == sItemCustom && m_bShopOpenBACK == bShopOpen
			&& m_bInMarketBACK == bInMarket && m_bInPrivateMarketBACK == bInPrivateMarket
			&& m_bIsWEAR_ITEMBACK == bIsWEAR_ITEM && m_wPosXBACK == wPosX && m_wPosYBACK == wPosY && m_bITEMLINK == bITEMLINK )	return ;

		m_sItemCustomBACK = sItemCustom;
		m_bShopOpenBACK = bShopOpen;
		m_bInMarketBACK = bInMarket;
		m_bInPrivateMarketBACK = bInPrivateMarket;
		m_bIsWEAR_ITEMBACK = bIsWEAR_ITEM;
		m_wPosXBACK = wPosX;
		m_wPosYBACK = wPosY;
		m_bITEMLINK = bITEMLINK;

		RemoveAllInfo();

		if ( m_bITEMLINK )
		{
			AddTextNoSplit ( "", NS_UITEXTCOLOR::WHITE );
		}

		if ( bIsWEAR_ITEM )
		{
			AddTextNoSplit ( ID2GAMEWORD ("WEAR_ITEM" ), NS_UITEXTCOLOR::RED );
		}

		CString strText, strText2;
		BOOL bValue = FALSE;
		int nExtraValue = 0;

		GLCharacter* pCharacter = GLGaeaClient::GetInstance().GetCharacter();
		SITEM* pItemData = GLItemMan::GetInstance().GetItem ( sItemCustom.sNativeID );


		{
			//AddTextNoSplit ( ID2GAMEWORD ( "ITEM_CATEGORY", 0 ), NS_UITEXTCOLOR::YELLOW );


			//////////////////////////////////////////////////////////////////////////////////////////////////////
			//	BasicInfo
				BOOL bInsert = FALSE;
				EMITEMLEVEL emLevel = pItemData->sBasicOp.emLevel;
				strText.Format ( "%s",pItemData->GetName() );
				BYTE uGRADE = sItemCustom.GETGRADE(EMGRINDING_NUNE);
			if (!uGRADE )
			{
				strText.Format ( " %s", pItemData->GetName() );
			}
			else
			{
				strText.Format ( "+%d %s", uGRADE, pItemData->GetName() );
			}
						DWORD dwLevel = (DWORD)pItemData->sBasicOp.emLevel;
						DWORD strColorName[GRADE_LIMIT_MAX+1] = 
					{			
						NS_UITEXTCOLOR::PALEGREEN,//0
						NS_UITEXTCOLOR::PALEGREEN,//1
						NS_UITEXTCOLOR::PALEGREEN,//2
						NS_UITEXTCOLOR::PALEGREEN,//3
						NS_UITEXTCOLOR::PALEGREEN,//4
						NS_UITEXTCOLOR::SILVER,//5
						NS_UITEXTCOLOR::SILVER,//6
						NS_UITEXTCOLOR::ORANGE,//7 
						NS_UITEXTCOLOR::ORANGE,//8
						NS_UITEXTCOLOR::GOLD,//9
						NS_UITEXTCOLOR::AQUA,//10
						NS_UITEXTCOLOR::VIOLET,//11
						NS_UITEXTCOLOR::VIOLET,//12
						NS_UITEXTCOLOR::PINK,//13
						NS_UITEXTCOLOR::GREEN,//14
						NS_UITEXTCOLOR::RED//15
					};

					int ColorGrade;

					if( uGRADE > 20 ){ 
					ColorGrade = 0;
					}else{
					ColorGrade = uGRADE;
					}
					
					AddTextNoSplitBig ( "       "+strText, strColorName[ColorGrade] );
					AddTextNoSplit ( "", NS_UITEXTCOLOR::GREEN);
					if( sItemCustom.nidDISGUISE != NATIVEID_NULL() )
					{
						SITEM* pItemDisguise = GLItemMan::GetInstance().GetItem ( sItemCustom.nidDISGUISE );
						DWORD dwReqCharClass_Disguise = pItemDisguise->sBasicOp.dwReqCharClass;
						DWORD dwReqCharClass = pItemData->sBasicOp.dwReqCharClass;
						CString szClass;

			DWORD dwReqSchool = pItemDisguise->sBasicOp.dwReqSchool;
			CString strSchool, strText;
			if ( dwReqSchool )
			{
				if ( dwReqSchool==GLSCHOOL_ALL )
					{
						strSchool+="          All Campuses";
						strText.AppendFormat ("%s", strSchool.GetString());
					}
					else
					{
						if ( dwReqSchool == GLSCHOOL_00)
						{
							strSchool+="          Sacred Gate";
							strText.AppendFormat ("%s", strSchool.GetString());
						}
						if ( dwReqSchool == GLSCHOOL_01)
						{
							strSchool+="          Mystic Peak";
							strText.AppendFormat ("%s", strSchool.GetString());
						}
						if ( dwReqSchool == GLSCHOOL_02)
						{
							strSchool+="          Phoenix";
							strText.AppendFormat ("%s", strSchool.GetString());
						}						
					}
			}
						
						if( dwReqCharClass )
						{
							if ( (dwReqCharClass==GLCC_ALL_2012) && (dwReqCharClass_Disguise==GLCC_ALL_2012) )
							{
								szClass = ("/All Classes");
							}
							else if (((dwReqCharClass&GLCC_FIGHTER_M) && (dwReqCharClass_Disguise&GLCC_FIGHTER_M) &&
										(dwReqCharClass&GLCC_ARMS_M)  && (dwReqCharClass_Disguise&GLCC_ARMS_M) 	  &&	
									  (dwReqCharClass&GLCC_ARCHER_M)  && (dwReqCharClass_Disguise&GLCC_ARCHER_M)  &&	
									  (dwReqCharClass&GLCC_SPIRIT_M)  && (dwReqCharClass_Disguise&GLCC_SPIRIT_M)  &&	
									 (dwReqCharClass&GLCC_EXTREME_M)  && (dwReqCharClass_Disguise&GLCC_EXTREME_M) &&
									 (dwReqCharClass&GLCC_SCIENCE_M)  && (dwReqCharClass_Disguise&GLCC_SCIENCE_M) &&	
									 (dwReqCharClass&GLCC_ASSASIN_M)  && (dwReqCharClass_Disguise&GLCC_ASSASIN_M) &&	
									 (dwReqCharClass&GLCC_MAGICIAN_M)  && (dwReqCharClass_Disguise&GLCC_MAGICIAN_M)) 
																	  ||
									 ((dwReqCharClass&GLCC_FIGHTER_M) && (dwReqCharClass_Disguise&GLCC_FIGHTER_M) &&
										(dwReqCharClass&GLCC_ARMS_M)  && (dwReqCharClass_Disguise&GLCC_ARMS_M) 	  &&	
									  (dwReqCharClass&GLCC_ARCHER_M)  && (dwReqCharClass_Disguise&GLCC_ARCHER_M)  &&	
									  (dwReqCharClass&GLCC_SPIRIT_M)  && (dwReqCharClass_Disguise&GLCC_SPIRIT_M)  &&	
									 (dwReqCharClass&GLCC_EXTREME_M)  && (dwReqCharClass_Disguise&GLCC_EXTREME_M) &&
									 (dwReqCharClass&GLCC_SCIENCE_M)  && (dwReqCharClass_Disguise&GLCC_SCIENCE_M) &&	
									 (dwReqCharClass&GLCC_ASSASIN_M)  && (dwReqCharClass_Disguise&GLCC_ASSASIN_M))	)
							{
								szClass = ("/All Male Classes");
							}
							else if (((dwReqCharClass&GLCC_FIGHTER_W) && (dwReqCharClass_Disguise&GLCC_FIGHTER_W) &&
										(dwReqCharClass&GLCC_ARMS_W)  && (dwReqCharClass_Disguise&GLCC_ARMS_W) 	  &&	
									  (dwReqCharClass&GLCC_ARCHER_W)  && (dwReqCharClass_Disguise&GLCC_ARCHER_W)  &&	
									  (dwReqCharClass&GLCC_SPIRIT_W)  && (dwReqCharClass_Disguise&GLCC_SPIRIT_W)  &&	
									 (dwReqCharClass&GLCC_EXTREME_W)  && (dwReqCharClass_Disguise&GLCC_EXTREME_W) &&
									 (dwReqCharClass&GLCC_SCIENCE_W)  && (dwReqCharClass_Disguise&GLCC_SCIENCE_W) &&	
									 (dwReqCharClass&GLCC_ASSASIN_W)  && (dwReqCharClass_Disguise&GLCC_ASSASIN_W) &&	
									 (dwReqCharClass&GLCC_MAGICIAN_W)  && (dwReqCharClass_Disguise&GLCC_MAGICIAN_W)) 
																	  ||
									 ((dwReqCharClass&GLCC_FIGHTER_W) && (dwReqCharClass_Disguise&GLCC_FIGHTER_W) &&
										(dwReqCharClass&GLCC_ARMS_W)  && (dwReqCharClass_Disguise&GLCC_ARMS_W) 	  &&	
									  (dwReqCharClass&GLCC_ARCHER_W)  && (dwReqCharClass_Disguise&GLCC_ARCHER_W)  &&	
									  (dwReqCharClass&GLCC_SPIRIT_W)  && (dwReqCharClass_Disguise&GLCC_SPIRIT_W)  &&	
									 (dwReqCharClass&GLCC_EXTREME_W)  && (dwReqCharClass_Disguise&GLCC_EXTREME_W) &&
									 (dwReqCharClass&GLCC_SCIENCE_W)  && (dwReqCharClass_Disguise&GLCC_SCIENCE_W) &&	
									 (dwReqCharClass&GLCC_ASSASIN_W)  && (dwReqCharClass_Disguise&GLCC_ASSASIN_W))	)
							{
								szClass = ("/All Female Classes");
							}
							else
							{
								if ( (dwReqCharClass&GLCC_FIGHTER_M) && (dwReqCharClass_Disguise&GLCC_FIGHTER_M) &&
									(dwReqCharClass&GLCC_FIGHTER_W) && (dwReqCharClass_Disguise&GLCC_FIGHTER_W))
								{
									szClass+="/Brawler";
								}
								if ( (dwReqCharClass&GLCC_ARMS_M)  && (dwReqCharClass_Disguise&GLCC_ARMS_M) &&
									(dwReqCharClass&GLCC_ARMS_W)  && (dwReqCharClass_Disguise&GLCC_ARMS_W))
								{
									szClass+="/Swordie";
								}
								if ( (dwReqCharClass&GLCC_ARCHER_M)  && (dwReqCharClass_Disguise&GLCC_ARCHER_M) &&
									(dwReqCharClass&GLCC_ARCHER_W)  && (dwReqCharClass_Disguise&GLCC_ARCHER_W))
								{
									szClass+="/Archer";
								}
								if ( (dwReqCharClass&GLCC_SPIRIT_M)  && (dwReqCharClass_Disguise&GLCC_SPIRIT_M) &&
									(dwReqCharClass&GLCC_SPIRIT_W)  && (dwReqCharClass_Disguise&GLCC_SPIRIT_W))
								{
									szClass+="/Shamman";
								}
								if ( (dwReqCharClass&GLCC_EXTREME_M)  && (dwReqCharClass_Disguise&GLCC_EXTREME_M) &&
									(dwReqCharClass&GLCC_EXTREME_W)  && (dwReqCharClass_Disguise&GLCC_EXTREME_W))
								{
									szClass+="/Extreme";
								}
								if ( (dwReqCharClass&GLCC_SCIENCE_M)  && (dwReqCharClass_Disguise&GLCC_SCIENCE_M) &&
									(dwReqCharClass&GLCC_SCIENCE_W)  && (dwReqCharClass_Disguise&GLCC_SCIENCE_W))
								{
									szClass+="/Gunner";
								}
								if ( (dwReqCharClass&GLCC_ASSASIN_M)  && (dwReqCharClass_Disguise&GLCC_ASSASIN_M) &&
									(dwReqCharClass&GLCC_ASSASIN_W)  && (dwReqCharClass_Disguise&GLCC_ASSASIN_W))
								{
									szClass+="/Assassin";
								}
								if ( (dwReqCharClass&GLCC_MAGICIAN_M)  && (dwReqCharClass_Disguise&GLCC_MAGICIAN_M) && 
									(dwReqCharClass&GLCC_MAGICIAN_W)  && (dwReqCharClass_Disguise&GLCC_MAGICIAN_W))
								{
									szClass+="/Magician";
								}
							}
							
			DWORD dwReqSchool = pItemDisguise->sBasicOp.dwReqSchool;
			CString strSchool, strText;
			if ( dwReqSchool )
			{
				if ( dwReqSchool==GLSCHOOL_ALL )
					{
						strSchool+="          All Campuses";
						strText.AppendFormat ("%s", strSchool.GetString());
					}
					else
					{
						if ( dwReqSchool == GLSCHOOL_00)
						{
							strSchool+="          Sacred Gate";
							strText.AppendFormat ("%s", strSchool.GetString());
						}
						if ( dwReqSchool == GLSCHOOL_01)
						{
							strSchool+="          Mystic Peak";
							strText.AppendFormat ("%s", strSchool.GetString());
						}
						if ( dwReqSchool == GLSCHOOL_02)
						{
							strSchool+="          Phoenix";
							strText.AppendFormat ("%s", strSchool.GetString());
						}						
					}
			}

							strText.AppendFormat( "%s", szClass.GetString() );
							AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor((dwReqCharClass&pCharacter->m_emClass) && (dwReqCharClass_Disguise&pCharacter->m_emClass)&&(dwReqSchool & index2school(pCharacter->m_wSchool))));
						}
					}
					else
					{
						DWORD dwReqCharClass = pItemData->sBasicOp.dwReqCharClass;
						CString szClass;
						
						if( dwReqCharClass )
						{
							if ( dwReqCharClass==GLCC_ALL_2012)
							{
								szClass = ("/All Classes");
							}
							else if ((( dwReqCharClass & GLCC_FIGHTER_M) && ( dwReqCharClass & GLCC_ARMS_M) 	&&
									   ( dwReqCharClass & GLCC_ARCHER_M) && ( dwReqCharClass & GLCC_SPIRIT_M) 	&&
									  ( dwReqCharClass & GLCC_EXTREME_M) &&	( dwReqCharClass & GLCC_SCIENCE_M) 	&&
									  ( dwReqCharClass & GLCC_ASSASIN_M) &&	( dwReqCharClass & GLCC_MAGICIAN_M))	
																		 ||										
									 (( dwReqCharClass & GLCC_FIGHTER_M) && ( dwReqCharClass & GLCC_ARMS_M) 	&&
									   ( dwReqCharClass & GLCC_ARCHER_M) && ( dwReqCharClass & GLCC_SPIRIT_M) 	&&
									  ( dwReqCharClass & GLCC_EXTREME_M) &&	( dwReqCharClass & GLCC_SCIENCE_M) 	&&
									  ( dwReqCharClass & GLCC_ASSASIN_M))		)
							{
								szClass = ("/All Male Classes");
							}
							else if ((( dwReqCharClass & GLCC_FIGHTER_W) && ( dwReqCharClass & GLCC_ARMS_W) 	&&
									   ( dwReqCharClass & GLCC_ARCHER_W) && ( dwReqCharClass & GLCC_SPIRIT_W) 	&&
									  ( dwReqCharClass & GLCC_EXTREME_W) &&	( dwReqCharClass & GLCC_SCIENCE_W) 	&&
									  ( dwReqCharClass & GLCC_ASSASIN_W) &&	( dwReqCharClass & GLCC_MAGICIAN_W))	
																		 ||										
									 (( dwReqCharClass & GLCC_FIGHTER_W) && ( dwReqCharClass & GLCC_ARMS_W) 	&&
									   ( dwReqCharClass & GLCC_ARCHER_W) && ( dwReqCharClass & GLCC_SPIRIT_W) 	&&
									  ( dwReqCharClass & GLCC_EXTREME_W) &&	( dwReqCharClass & GLCC_SCIENCE_W) 	&&
									  ( dwReqCharClass & GLCC_ASSASIN_W))		)
							{
								szClass = ("/All Female Classes");
							}
							else
							{
								if (( dwReqCharClass & GLCC_FIGHTER_M)&&( dwReqCharClass & GLCC_FIGHTER_W))
								{
									szClass+="/Brawler";
								}
								if (( dwReqCharClass & GLCC_ARMS_M)&&( dwReqCharClass & GLCC_ARMS_W))
								{
									szClass+="/Swordie";
								}
								if (( dwReqCharClass & GLCC_ARCHER_M)&&( dwReqCharClass & GLCC_ARCHER_W))
								{
									szClass+="/Archer";
								}
								if (( dwReqCharClass & GLCC_SPIRIT_M)&&( dwReqCharClass & GLCC_SPIRIT_W))
								{
									szClass+="/Shamman";
								}
								if (( dwReqCharClass & GLCC_EXTREME_M)&&( dwReqCharClass & GLCC_EXTREME_W))
								{
									szClass+="/Extreme";
								}
								if (( dwReqCharClass & GLCC_SCIENCE_M)&&( dwReqCharClass & GLCC_SCIENCE_W))
								{
									szClass+="/Gunner";
								}
								if (( dwReqCharClass & GLCC_ASSASIN_M)&&( dwReqCharClass & GLCC_ASSASIN_W))
								{
									szClass+="/Assassin";
								}
								if (( dwReqCharClass & GLCC_MAGICIAN_M)&&( dwReqCharClass & GLCC_MAGICIAN_W))
								{
									szClass+="/Magician";
								}
							}
							
			DWORD dwReqSchool = pItemData->sBasicOp.dwReqSchool;
			CString strSchool, strText;
			if ( dwReqSchool )
			{
				if ( dwReqSchool==GLSCHOOL_ALL )
					{
						strSchool+="          All Campuses";
						strText.AppendFormat ("%s", strSchool.GetString());
					}
					else
					{
						if ( dwReqSchool == GLSCHOOL_00)
						{
							strSchool+="          Sacred Gate";
							strText.AppendFormat ("%s", strSchool.GetString());
						}
						if ( dwReqSchool == GLSCHOOL_01)
						{
							strSchool+="          Mystic Peak";
							strText.AppendFormat ("%s", strSchool.GetString());
						}
						if ( dwReqSchool == GLSCHOOL_02)
						{
							strSchool+="          Phoenix";
							strText.AppendFormat ("%s", strSchool.GetString());
						}						
					}
			}
							
							strText.AppendFormat( "%s", szClass.GetString() );
							AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor ( (dwReqCharClass & pCharacter->m_emClass)&&(dwReqSchool & index2school(pCharacter->m_wSchool))));
						}
					}

					{
								//	AdvInfo
			SCHARSTATS& rItemStats = pItemData->sBasicOp.sReqStats;
			SCHARSTATS& rCharStats = pCharacter->m_sSUMSTATS;
			EMITEM_TYPE emItemType = pItemData->sBasicOp.emItemType;

					if ( pItemData->sBasicOp.wReqPA )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION", 1), pItemData->sBasicOp.wReqPA );
						AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor ( pItemData->sBasicOp.wReqPA <= pCharacter->m_wSUM_PA ) );
					}
					//	착용조건->사격치
					if ( pItemData->sBasicOp.wReqSA )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION", 2 ), pItemData->sBasicOp.wReqSA );
						AddTextNoSplit(strText,NS_UITEXTCONTROL::GetEvaluateColor ( pItemData->sBasicOp.wReqSA <= pCharacter->m_wSUM_SA ));
					}

					//	Stats
					//	착용조건->힘
					if ( rItemStats.dwPow )
					{
						strText.Format( "%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 0 ), rItemStats.dwPow );
						AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwPow <= rCharStats.dwPow ) );
					}
					//	착용조건->체력
					if ( rItemStats.dwStr )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 1 ), rItemStats.dwStr );
						AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwStr <= rCharStats.dwStr ) );
					}
					//	착용조건->정신력
					if ( rItemStats.dwSpi)
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 2 ), rItemStats.dwSpi );
						AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwSpi <= rCharStats.dwSpi ) );
					}
					//	착용조건->민첩성
					if ( rItemStats.dwDex )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 3 ), rItemStats.dwDex );
						AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwDex <= rCharStats.dwDex ) );
					}
					//	착용조건->지력
					if ( rItemStats.dwInt  )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 4 ), rItemStats.dwInt );
						AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwInt <= rCharStats.dwInt ) );
					}
					//	착용조건->근력
					if ( rItemStats.dwSta )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 5 ), rItemStats.dwSta );
						AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwSta <= rCharStats.dwSta ) );
					}
					}
			
			//	코스춤
			if ( sItemCustom.nidDISGUISE!=SNATIVEID(false) )
			{
				SITEM* pDisguiseData = GLItemMan::GetInstance().GetItem ( sItemCustom.nidDISGUISE );

				strText.Format ( "Costume: %s"/*, ID2GAMEWORD ( "ITEM_BASIC_INFO", 3 )*/, pDisguiseData->GetName() );			
				AddTextNoSplit ( strText, NS_UITEXTCOLOR::GREENYELLOW );
			}

			//	코스츔 기간 표시
			if ( sItemCustom.tDISGUISE!=0 )
			{				
				CTime cTime(sItemCustom.tDISGUISE);
				if ( cTime.GetYear()!=1970 )
				{
					CString strExpireDate;
					strExpireDate = CInnerInterface::GetInstance().MakeString( ID2GAMEWORD("ITEM_EXPIRE_DATE"),
																				(cTime.GetYear ()%2000), 
																				cTime.GetMonth (), 
																				cTime.GetDay (), 
	 																			cTime.GetHour (), 
																				cTime.GetMinute () );

					strText.Format ( "%s:%s", ID2GAMEWORD ( "ITEM_BASIC_INFO", 7 ), strExpireDate );			
					AddTextNoSplit ( strText, NS_UITEXTCOLOR::DARKORANGE );
				}
			}

			DWORD dwCOMMISSION_MONEY = 0;

			//	2.가격
			if ( pItemData->sBasicOp.dwBuyPrice || bInPrivateMarket )
			{
				if ( bInPrivateMarket )
				{
					bool bOPENER;
					DWORD dwPrivateMarketID;
					CInnerInterface::GetInstance().GetPrivateMarketInfo ( bOPENER, dwPrivateMarketID );
					if ( bOPENER )	//	파는 사람
					{
						GLPrivateMarket &sPMarket = GLGaeaClient::GetInstance().GetCharacter()->m_sPMarket;

						const SSALEITEM *pSALE = sPMarket.GetItem ( SNATIVEID(wPosX,wPosY) ); 
						if ( pSALE )
						{
							CString strMoney = NS_UITEXTCONTROL::MAKE_MONEY_FORMAT ( pSALE->llPRICE, 3, "," );
							CString GetMoneyCon = NS_UITEXTCONTROL::MAKE_MONEY_FORMAT ( pSALE->llPRICE, 3, "" );
							strText.Format ( "%s:%s", ID2GAMEWORD ( "ITEM_BASIC_INFO", 5 ), strMoney );			
							//AddTextNoSplit ( strText, NS_UITEXTCOLOR::GOLD );
							
							LONGLONG GetMoneyColor = _ttoi64(GetMoneyCon);
							if ( GetMoneyColor >= 0 && GetMoneyColor <= 99999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::GOLD );}
							if ( GetMoneyColor >= 100000 && GetMoneyColor <= 999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::TOMATO );}
							if ( GetMoneyColor >= 1000000 && GetMoneyColor <= 9999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::MAROON );}
							if ( GetMoneyColor >= 10000000 && GetMoneyColor <= 99999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::THISTLE );}
							if ( GetMoneyColor >= 100000000 && GetMoneyColor <= 999999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::ORNAGERED );}
							if ( GetMoneyColor >= 1000000000 && GetMoneyColor <= 9999999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::HONEYDEW );}
							if ( GetMoneyColor >= 10000000000 && GetMoneyColor <= 99999999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::PERU );}
							if ( GetMoneyColor >= 100000000000 && GetMoneyColor <= 999999999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::FUCHSIA );}
							if ( GetMoneyColor >= 1000000000000  ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::FUCHSIA );}
						}						
					}
					else		//	사는 사람
					{
						PGLCHARCLIENT pCLIENT = GLGaeaClient::GetInstance().GetChar ( dwPrivateMarketID );
						if ( !pCLIENT ) return ;

						GLPrivateMarket &sPMarket = pCLIENT->m_sPMarket;

						const SSALEITEM *pSALE = sPMarket.GetItem ( SNATIVEID(wPosX,wPosY) ); 
						if ( pSALE )
						{
							CString strMoney = NS_UITEXTCONTROL::MAKE_MONEY_FORMAT ( pSALE->llPRICE, 3, "," );
							CString GetMoneyCon = NS_UITEXTCONTROL::MAKE_MONEY_FORMAT ( pSALE->llPRICE, 3, "" );
							strText.Format ( "%s:%s", ID2GAMEWORD ( "ITEM_BASIC_INFO", 5 ), strMoney );			
							//AddTextNoSplit ( strText, NS_UITEXTCOLOR::GOLD );
							
							LONGLONG GetMoneyColor = _ttoi64(GetMoneyCon);
							if ( GetMoneyColor >= 0 && GetMoneyColor <= 99999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::GOLD );}
							if ( GetMoneyColor >= 100000 && GetMoneyColor <= 999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::TOMATO );}
							if ( GetMoneyColor >= 1000000 && GetMoneyColor <= 9999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::MAROON );}
							if ( GetMoneyColor >= 10000000 && GetMoneyColor <= 99999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::THISTLE );}
							if ( GetMoneyColor >= 100000000 && GetMoneyColor <= 999999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::ORNAGERED );}
							if ( GetMoneyColor >= 1000000000 && GetMoneyColor <= 9999999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::HONEYDEW );}
							if ( GetMoneyColor >= 10000000000 && GetMoneyColor <= 99999999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::PERU );}
							if ( GetMoneyColor >= 100000000000 && GetMoneyColor <= 999999999999 ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::FUCHSIA );}
							if ( GetMoneyColor >= 1000000000000  ){ AddTextNoSplit ( strText, NS_UITEXTCOLOR::FUCHSIA );}
						}
					}
				}				
				else if ( bShopOpen && bInMarket )	// npc open , check item inside inventory ( item price inside npc)
				{
					LONGLONG dwNpcSellPrice = 0;

					volatile LONGLONG dwPrice = 0;
					volatile float fSHOP_RATE = GLGaeaClient::GetInstance().GetCharacter()->GetBuyRate();
					volatile float fSHOP_RATE_C = fSHOP_RATE * 0.01f;

					//if( sNpcNativeID.wMainID != 0 && sNpcNativeID.wSubID != 0 ) //npc itemprice fix
					{
						PCROWDATA pCrowData = GLCrowDataMan::GetInstance().GetCrowData ( sNpcNativeID );
						if( pCrowData != NULL )
						{
							LONGLONG dwNpcPrice = pCrowData->GetNpcSellPrice( pItemData->sBasicOp.sNativeID.dwID );
							//add money 2
							//no tax for vote item
							if ( pItemData->sBasicOp.emLevel == LEVEL_VOTE_ITEM )
							{
								dwPrice = pItemData->sBasicOp.dwBuyPrice;
							}
							//add money 3
							//no tax for premium item
							else if ( pItemData->sBasicOp.emLevel == LEVEL_PREMIUM_ITEM )
							{
								dwPrice = pItemData->sBasicOp.dwBuyPrice;
							}
							//add contributionpoint by CNDev
							else if ( pItemData->sBasicOp.emLevel == LEVEL_CONTRIBUTION_ITEM )
							{
								dwPrice = pItemData->sBasicOp.dwBuyPrice;
							}
							else
							{			
								if( dwNpcPrice == 0 )
								{								
									dwNpcSellPrice = pItemData->sBasicOp.dwBuyPrice;
									dwPrice = DWORD ( (float)dwNpcSellPrice * fSHOP_RATE_C );
								}
								else
								{
									dwNpcSellPrice = dwNpcPrice;
									dwPrice = dwNpcSellPrice;								
								}
							}
						}
					}				

					
					CString strMoney = NS_UITEXTCONTROL::MAKE_MONEY_FORMAT ( dwPrice, 3, "," );

					/*strText.Format( "%s:%s", ID2GAMEWORD("ITEM_BASIC_INFO", 1), strMoney );
					*/

					//add money 2 checking price red 
		
					//	커미션 액수
					//add money 2
					//no tax for vote item
					if ( pItemData->sBasicOp.emLevel == LEVEL_VOTE_ITEM )
					{
						dwCOMMISSION_MONEY  = 0;
					}
					//add money 3
					//no tax for premium item
					else if ( pItemData->sBasicOp.emLevel == LEVEL_PREMIUM_ITEM )
					{
						dwCOMMISSION_MONEY  = 0;
					}
					//add contributionpoint by CNDev
					else if ( pItemData->sBasicOp.emLevel == LEVEL_CONTRIBUTION_ITEM )
					{
						dwCOMMISSION_MONEY  = 0;
					}
					else
					{
						dwCOMMISSION_MONEY = 0/*dwPrice - dwNpcSellPrice*/;
					}
					
					D3DCOLOR dwColor = NS_UITEXTCOLOR::RED;
					/*if( dwPrice <= GLGaeaClient::GetInstance().GetCharacterLogic().m_lnMoney )
					{
						dwColor = NS_UITEXTCOLOR::PALEGREEN;
					}*/
					//add money 2

					// done price color respond with item gold price or item  premium price
					//add money 2
					if ( pItemData->sBasicOp.emLevel == LEVEL_VOTE_ITEM ) // check price color for premium items
					{
						strText.Format( "%s:%s", ID2GAMEWORD("ITEM_BASIC_INFO", 11), strMoney );

						if( dwPrice <= GLGaeaClient::GetInstance().GetCharacterLogic().m_lnVoteP )
						{
							dwColor = NS_UITEXTCOLOR::LIGHTSKYBLUE;
						}
					}
					//add money 3
					else if ( pItemData->sBasicOp.emLevel == LEVEL_PREMIUM_ITEM ) // check price color for premium items
					{
						strText.Format( "%s:%s", ID2GAMEWORD("ITEM_BASIC_INFO", 13), strMoney );

						if( dwPrice <= GLGaeaClient::GetInstance().GetCharacterLogic().m_lnPremP )
						{
							dwColor = NS_UITEXTCOLOR::LIGHTSKYBLUE;
						}
					}
					//add contributionpoint by CNDev
					else if ( pItemData->sBasicOp.emLevel == LEVEL_CONTRIBUTION_ITEM ) // check price color for premium items
					{
						strText.Format( "%s:%s", ID2GAMEWORD("ITEM_BASIC_INFO", 16), strMoney );

						if( dwPrice <= GLGaeaClient::GetInstance().GetCharacterLogic().m_lnContribP )
						{
							dwColor = NS_UITEXTCOLOR::LIGHTSKYBLUE;
						}
					}

					else
					{
						strText.Format( "%s:%s", ID2GAMEWORD("ITEM_BASIC_INFO", 1), strMoney );

						if( dwPrice <= GLGaeaClient::GetInstance().GetCharacterLogic().m_lnMoney )
						{
							dwColor = NS_UITEXTCOLOR::PALEGREEN;
						}
					}
				
					AddTextNoSplit ( strText, dwColor );
				}
				else if ( bShopOpen ) // npc open (check item price of items inside inventory not inside npc)	// 
				{
					if ( pItemData->sBasicOp.IsPointRecover() )
					{//add and modified for //add point sell
						volatile DWORD dwPrice = pItemData->GETSELLPRICE ( sItemCustom.wTurnNum );
						dwCOMMISSION_MONEY = 0;
						CString strMoney = NS_UITEXTCONTROL::MAKE_MONEY_FORMAT ( dwPrice, 3, "," );

						if ( pItemData->sBasicOp.emLevel == LEVEL_VOTE_ITEM )
						{	
							strText.Format( "%s:%s", ID2GAMEWORD("ITEM_BASIC_INFO", 14), strMoney );
							AddTextNoSplit ( strText, NS_UITEXTCOLOR::PALEGREEN );
						}
						else if ( pItemData->sBasicOp.emLevel == LEVEL_PREMIUM_ITEM )
						{	
							strText.Format( "%s:%s", ID2GAMEWORD("ITEM_BASIC_INFO", 15), strMoney );
							AddTextNoSplit ( strText, NS_UITEXTCOLOR::PALEGREEN );
						}
						else if ( pItemData->sBasicOp.emLevel == LEVEL_CONTRIBUTION_ITEM )
						{
							strText.Format( "%s:%s", ID2GAMEWORD("ITEM_BASIC_INFO", 17), strMoney );
							AddTextNoSplit ( strText, NS_UITEXTCOLOR::PALEGREEN );
						}
						else
						{
							AddTextNoSplit ( "Wrong item setting, enable only point recover if item is set to premium or vote", NS_UITEXTCOLOR::RED );
						}
					}
					else
					{//default
						volatile float fSHOP_RATE = GLGaeaClient::GetInstance().GetCharacter()->GetSaleRate();
						volatile float fSALE_DISCOUNT = fSHOP_RATE * 0.01f;

						volatile DWORD dwPrice = pItemData->GETSELLPRICE ( sItemCustom.wTurnNum );
						volatile DWORD dwSALE_PRICE = DWORD ( dwPrice * fSALE_DISCOUNT );					

						//	커미션 액수
						volatile DWORD dwDISPRICE = pItemData->GETSELLPRICE ( sItemCustom.wTurnNum );
						dwCOMMISSION_MONEY = dwDISPRICE - dwSALE_PRICE;

						CString strMoney = NS_UITEXTCONTROL::MAKE_MONEY_FORMAT ( dwSALE_PRICE, 3, "," );
						strText.Format( "%s:%s", ID2GAMEWORD("ITEM_BASIC_INFO", 12), strMoney );

						AddTextNoSplit ( strText, NS_UITEXTCOLOR::PALEGREEN );
					}

					//CString strErr;
					//strErr.Format ( "fSHOP_RATE:%f / fSALE_DISCOUNT:%f / dwPrice:%d /dwSALE_PRICE:%d ",
					//fSHOP_RATE,fSALE_DISCOUNT,dwPrice,dwSALE_PRICE );
					//MessageBox ( NULL, strErr.GetString(), "ERROR", MB_OK );

				}
			}

			//	수수료 표시
			if ( dwCOMMISSION_MONEY )
			{
				CString strMoney = NS_UITEXTCONTROL::MAKE_MONEY_FORMAT ( dwCOMMISSION_MONEY, 3, "," );
				strText.Format( "%s:%s", ID2GAMEWORD("ITEM_BASIC_INFO", 6), strMoney );

				AddTextNoSplit ( strText, NS_UITEXTCOLOR::PALEGREEN );
			}

			//	수량표시
			AddItemTurnInfo ( sItemCustom, bInMarket, bInPrivateMarket );

			//	기간표시
			if ( pItemData->IsTIMELMT () )
			{
				CTime cTime(sItemCustom.tBORNTIME);
				if ( cTime.GetYear()!=1970 )
				{
					CTimeSpan sLMT(pItemData->sDrugOp.tTIME_LMT);
					cTime += sLMT;

					CString strExpireDate;
					strExpireDate = CInnerInterface::GetInstance().MakeString ( ID2GAMEWORD("ITEM_EXPIRE_DATE"),
						(cTime.GetYear ()%2000), cTime.GetMonth (), cTime.GetDay (), cTime.GetHour (), cTime.GetMinute () );

					strText.Format ( "%s:%s", ID2GAMEWORD ( "ITEM_BASIC_INFO", 4 ), strExpireDate );			
					AddTextNoSplit ( strText, NS_UITEXTCOLOR::DARKORANGE );
				}
			}

			//	착용조건->요구 레벨
			if ( pItemData->sBasicOp.wReqLevelDW || pItemData->sBasicOp.wReqLevelUP )
			{
				bool bReqLevel = true;
				strText.Format( "%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION", 0), pItemData->sBasicOp.wReqLevelDW );
									
				if ( pItemData->sBasicOp.wReqLevelUP )
				{
					strText2.Format ( "~%d",pItemData->sBasicOp.wReqLevelUP );
					strText += strText2; 
					bReqLevel = (pItemData->sBasicOp.wReqLevelUP >= pCharacter->m_wLevel);
				}

				AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pItemData->sBasicOp.wReqLevelDW <= pCharacter->m_wLevel && bReqLevel ) );
			}
			//add reborn req
			if ( pItemData->sBasicOp.dwRebornReq )
			{
				strText.Format( "%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION", 3), pItemData->sBasicOp.dwRebornReq );
				AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( pItemData->sBasicOp.dwRebornReq <= pCharacter->m_dwReborn  ) );
			}

			//	재사용 대기시간
			if ( pItemData->sBasicOp.IsCoolTime() )
			{
				CString strTime = "";
				CTimeSpan cCoolTime( pItemData->sBasicOp.dwCoolTime );
				
				if ( cCoolTime.GetHours() > 0 )	
					strTime += CInnerInterface::GetInstance().MakeString( "%d%s ", cCoolTime.GetHours(), ID2GAMEWORD ( "ITEM_BASIC_TIME", 0 ) );
				if ( cCoolTime.GetMinutes() > 0 )	
					strTime += CInnerInterface::GetInstance().MakeString( "%d%s ", cCoolTime.GetMinutes(), ID2GAMEWORD ( "ITEM_BASIC_TIME", 1 ) );
				if ( cCoolTime.GetSeconds() > 0 )	
					strTime += CInnerInterface::GetInstance().MakeString( "%d%s ", cCoolTime.GetSeconds(), ID2GAMEWORD ( "ITEM_BASIC_TIME", 2 ) );

				strText.Format ( "%s : %s", ID2GAMEWORD ( "ITEM_BASIC_INFO", 8 ), strTime );			
				AddTextNoSplit ( strText, NS_UITEXTCOLOR::DARKORANGE );	
			}

			//	남은시간


			GLCharacter* pCharacter = GLGaeaClient::GetInstance().GetCharacter();
			if ( pCharacter && pCharacter->IsCoolTime( pItemData->sBasicOp.sNativeID ) )
			{
				CString strTime = "";
				__time64_t tCurTime =  GLGaeaClient::GetInstance().GetCurrentTime().GetTime();
				__time64_t tCoolTime = pCharacter->GetMaxCoolTime( pItemData->sBasicOp.sNativeID );				

				CTimeSpan cReTime( tCoolTime - tCurTime );

                if ( cReTime.GetHours() > 0 )	
					strTime += CInnerInterface::GetInstance().MakeString( "%d%s ", cReTime.GetHours(), ID2GAMEWORD ( "ITEM_BASIC_TIME", 0 ) );
				if ( cReTime.GetMinutes() > 0 )	
					strTime += CInnerInterface::GetInstance().MakeString( "%d%s ", cReTime.GetMinutes(), ID2GAMEWORD ( "ITEM_BASIC_TIME", 1 ) );
				if ( cReTime.GetSeconds() > 0 )	
					strTime += CInnerInterface::GetInstance().MakeString( "%d%s ", cReTime.GetSeconds(), ID2GAMEWORD ( "ITEM_BASIC_TIME", 2 ) );

				strText.Format ( "%s : %s", ID2GAMEWORD ( "ITEM_BASIC_INFO", 9 ), strTime );			
				AddTextNoSplit ( strText, NS_UITEXTCOLOR::DARKORANGE );
			}

			//////////////////////////////////////////////////////////////////////////////////////////////////////
			//	AdvInfo
			SCHARSTATS& rItemStats = pItemData->sBasicOp.sReqStats;
			SCHARSTATS& rCharStats = pCharacter->m_sSUMSTATS;
			EMITEM_TYPE emItemType = pItemData->sBasicOp.emItemType;

			switch ( emItemType )
			{
			case ITEM_SUIT:
			case ITEM_REVIVE:
			case ITEM_ANTI_DISAPPEAR:
				{
					AddTextNoSplit ( ID2GAMEWORD ( "ITEM_CATEGORY", 1 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

					BYTE uGRADE = 0;

					//	공격력
					GLPADATA &sDamage = sItemCustom.getdamage();
					nExtraValue = sItemCustom.GETGRADE_DAMAGE();
					uGRADE = sItemCustom.GETGRADE(EMGRINDING_DAMAGE);
					AddInfoItemAddonRange ( sDamage.dwLow, sDamage.dwHigh, nExtraValue, uGRADE, ID2GAMEWORD("ITEM_ADVANCED_INFO", 0) );

					//	기력치
					nExtraValue = sItemCustom.GETGRADE_DAMAGE();
					if ( nExtraValue )
					{
						uGRADE = sItemCustom.GETGRADE(EMGRINDING_DAMAGE);
						strText.Format ( "%s:+%d", ID2GAMEWORD("ITEM_ADVANCED_INFO", 8), nExtraValue );
						APPEND_ITEM_GRADE ( strText, uGRADE );
						AddTextNoSplit ( strText, NS_UITEXTCOLOR::PRIVATE );
					}

					//	방어력
					short nDefense = sItemCustom.getdefense();
					nExtraValue = sItemCustom.GETGRADE_DEFENSE();
					uGRADE = sItemCustom.GETGRADE(EMGRINDING_DEFENSE);
					AddInfoItemAddon ( nDefense, nExtraValue, uGRADE, ID2GAMEWORD("ITEM_ADVANCED_INFO", 1) );

					//	공격 거리
					if ( sItemCustom.GETATTRANGE() )
					{
						strText.Format("%s:%d",ID2GAMEWORD("ITEM_ADVANCED_INFO", 2), sItemCustom.GETATTRANGE() );
						AddTextNoSplit ( strText, NS_UITEXTCOLOR::DEFAULT );
					}

					//	명중률
					if ( sItemCustom.GETHITRATE() )
					{
						nExtraValue = 0;
						AddInfoItemAddon ( sItemCustom.GETHITRATE(), nExtraValue, ID2GAMEWORD("ITEM_ADVANCED_INFO", 3) );		
					}

					//	회피율
					if ( sItemCustom.GETAVOIDRATE() )
					{
						nExtraValue = 0;
						AddInfoItemAddon ( sItemCustom.GETAVOIDRATE(), nExtraValue, ID2GAMEWORD("ITEM_ADVANCED_INFO", 4) );
					}

					//	착용위치
					strText.Format("%s:%s ", ID2GAMEWORD("ITEM_ADVANCED_INFO", 5), COMMENT::ITEMSUIT[pItemData->sSuitOp.emSuit].c_str() );
					AddTextNoSplit (strText, NS_UITEXTCOLOR::DEFAULT );

					//	공격 속성
					if ( pItemData->sSuitOp.emAttack != ITEMATT_NOTHING )
					{
						strText.Format("%s:%s", ID2GAMEWORD("ITEM_ADVANCED_INFO", 6), COMMENT::ITEMATTACK[pItemData->sSuitOp.emAttack].c_str() );
						AddTextNoSplit ( strText, NS_UITEXTCOLOR::DEFAULT );
					}

					//	SP 소모
					const WORD wReqSP = sItemCustom.GETREQ_SP();
					if ( 0 < wReqSP )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO", 7), wReqSP );
						AddTextNoSplit ( strText, NS_UITEXTCOLOR::ORANGE );
					}
				
					//	착용조건-------------------------------------------------------------------------------------
					//	착용조건-착용가능 클래스
					AddTextNoSplit( ID2GAMEWORD ( "ITEM_CATEGORY", 2 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

					if ( pItemData->sBasicOp.dwReqSchool!=GLSCHOOL_ALL )
					{
						CString strSchool;
						if ( pItemData->sBasicOp.dwReqSchool & GLSCHOOL_00)
						{
							strSchool+=GLCONST_CHAR::strSCHOOLNAME[school2index(GLSCHOOL_00)].c_str();
							strSchool+=" ";
						}
						if ( pItemData->sBasicOp.dwReqSchool & GLSCHOOL_01)
						{
							strSchool+=GLCONST_CHAR::strSCHOOLNAME[school2index(GLSCHOOL_01)].c_str();
							strSchool+=" ";
						}
						if ( pItemData->sBasicOp.dwReqSchool & GLSCHOOL_02)
						{
							strSchool+=GLCONST_CHAR::strSCHOOLNAME[school2index(GLSCHOOL_02)].c_str();
							strSchool+=" ";
						}						

						AddTextNoSplit ( strSchool, NS_UITEXTCONTROL::GetEvaluateColor ( pItemData->sBasicOp.dwReqSchool & index2school(pCharacter->m_wSchool) ) );
					}

					if( sItemCustom.nidDISGUISE != NATIVEID_NULL() )
					{
						SITEM* pItemDisguise = GLItemMan::GetInstance().GetItem ( sItemCustom.nidDISGUISE );
						DWORD dwReqCharClass_Disguise = pItemDisguise->sBasicOp.dwReqCharClass;
						DWORD dwReqCharClass = pItemData->sBasicOp.dwReqCharClass;
						CString szClass;

						if( dwReqCharClass )
						{
							//if ( (dwReqCharClass==GLCC_ALL_NEWSEX) && (dwReqCharClass_Disguise==GLCC_ALL_NEWSEX) )
							//add class
							if ( (dwReqCharClass==GLCC_ALL_2012) && (dwReqCharClass_Disguise==GLCC_ALL_2012) )
							{
								szClass = ID2GAMEWORD("ITEM_ALL_CLASS");
							}
							else
							{
								if ( (dwReqCharClass&GLCC_FIGHTER_M) && (dwReqCharClass_Disguise&GLCC_FIGHTER_M) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_FIGHTER_M)].c_str();
									szClass+=" ";
								}
								if ( (dwReqCharClass&GLCC_FIGHTER_W) && (dwReqCharClass_Disguise&GLCC_FIGHTER_W) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_FIGHTER_W)].c_str();
									szClass+=" ";
								}

								if ( (dwReqCharClass&GLCC_ARMS_M)  && (dwReqCharClass_Disguise&GLCC_ARMS_M) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARMS_M)].c_str();
									szClass+=" ";
								}
								if ( (dwReqCharClass&GLCC_ARMS_W)  && (dwReqCharClass_Disguise&GLCC_ARMS_W) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARMS_W)].c_str();
									szClass+=" ";
								}
								if ( (dwReqCharClass&GLCC_ARCHER_M)  && (dwReqCharClass_Disguise&GLCC_ARCHER_M) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARCHER_M)].c_str();
									szClass+=" ";
								}
								if ( (dwReqCharClass&GLCC_ARCHER_W)  && (dwReqCharClass_Disguise&GLCC_ARCHER_W) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARCHER_W)].c_str();
									szClass+=" ";
								}
								if ( (dwReqCharClass&GLCC_SPIRIT_M)  && (dwReqCharClass_Disguise&GLCC_SPIRIT_M) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SPIRIT_M)].c_str();
									szClass+=" ";
								}
								if ( (dwReqCharClass&GLCC_SPIRIT_W)  && (dwReqCharClass_Disguise&GLCC_SPIRIT_W) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SPIRIT_W)].c_str();
									szClass+=" ";
								}
								if ( (dwReqCharClass&GLCC_EXTREME_M)  && (dwReqCharClass_Disguise&GLCC_EXTREME_M) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_EXTREME_M)].c_str();
									szClass+=" ";
								}
								if ( (dwReqCharClass&GLCC_EXTREME_W)  && (dwReqCharClass_Disguise&GLCC_EXTREME_W) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_EXTREME_W)].c_str();
								}
								//add class "SCIENCE"
								if ( (dwReqCharClass&GLCC_SCIENCE_M)  && (dwReqCharClass_Disguise&GLCC_SCIENCE_M) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SCIENCE_M)].c_str();
								}
								if ( (dwReqCharClass&GLCC_SCIENCE_W)  && (dwReqCharClass_Disguise&GLCC_SCIENCE_W) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SCIENCE_W)].c_str();
								}
								//add class "ASSASSIN"
								if ( (dwReqCharClass&GLCC_ASSASIN_M)  && (dwReqCharClass_Disguise&GLCC_ASSASIN_M) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ASSASIN_M)].c_str();
								}
								if ( (dwReqCharClass&GLCC_ASSASIN_W)  && (dwReqCharClass_Disguise&GLCC_ASSASIN_W) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ASSASIN_W)].c_str();
								}
								//add class "MAGICIAN"
								if ( (dwReqCharClass&GLCC_MAGICIAN_M)  && (dwReqCharClass_Disguise&GLCC_MAGICIAN_M) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_MAGICIAN_M)].c_str();
								}
								if ( (dwReqCharClass&GLCC_MAGICIAN_W)  && (dwReqCharClass_Disguise&GLCC_MAGICIAN_W) )
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_MAGICIAN_W)].c_str();
								}
							}

							strText.Format( "%s", szClass.GetString() );
							AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor( 
								(dwReqCharClass&pCharacter->m_emClass) && (dwReqCharClass_Disguise&pCharacter->m_emClass) ) );
						}
					}
					else
					{
						DWORD dwReqCharClass = pItemData->sBasicOp.dwReqCharClass;
						CString szClass;
						
						if( dwReqCharClass )
						{
							//if ( dwReqCharClass==GLCC_ALL_NEWSEX)
							//add class
							if ( dwReqCharClass==GLCC_ALL_2012)
							{
								szClass = ID2GAMEWORD("ITEM_ALL_CLASS");
							}
							else
							{
								if ( dwReqCharClass & GLCC_FIGHTER_M)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_FIGHTER_M)].c_str();
									szClass+=" ";
								}
								if ( dwReqCharClass & GLCC_FIGHTER_W)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_FIGHTER_W)].c_str();
									szClass+=" ";
								}
								if ( dwReqCharClass & GLCC_ARMS_M)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARMS_M)].c_str();
									szClass+=" ";
								}
								if ( dwReqCharClass & GLCC_ARMS_W)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARMS_W)].c_str();
									szClass+=" ";
								}
								if ( dwReqCharClass & GLCC_ARCHER_M)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARCHER_M)].c_str();
									szClass+=" ";
								}
								if ( dwReqCharClass & GLCC_ARCHER_W)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARCHER_W)].c_str();
									szClass+=" ";
								}
								if ( dwReqCharClass & GLCC_SPIRIT_M)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SPIRIT_M)].c_str();
									szClass+=" ";
								}
								if ( dwReqCharClass & GLCC_SPIRIT_W)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SPIRIT_W)].c_str();
									szClass+=" ";
								}
								if ( dwReqCharClass & GLCC_EXTREME_M)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_EXTREME_M)].c_str();
									szClass+=" ";
								}
								if ( dwReqCharClass & GLCC_EXTREME_W)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_EXTREME_W)].c_str();
								}
								//add class "SCIENCE"
								if ( dwReqCharClass & GLCC_SCIENCE_M)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SCIENCE_M)].c_str();
								}
								if ( dwReqCharClass & GLCC_SCIENCE_W)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SCIENCE_W)].c_str();
								}
								//add class "ASSASSIN"
								if ( dwReqCharClass & GLCC_ASSASIN_M)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ASSASIN_M)].c_str();
								}
								if ( dwReqCharClass & GLCC_ASSASIN_W)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ASSASIN_W)].c_str();
								}
								//add class "MAGICIAN"
								if ( dwReqCharClass & GLCC_MAGICIAN_M)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_MAGICIAN_M)].c_str();
								}
								if ( dwReqCharClass & GLCC_MAGICIAN_W)
								{
									szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_MAGICIAN_W)].c_str();
								}
								//
							}

							strText.Format( "%s", szClass.GetString() );
							AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor ( dwReqCharClass & pCharacter->m_emClass ) );
						}
					}

					//	조건 - 암광
					bValue = TRUE;
					strText.Format ( "%s", COMMENT::BRIGHT[pItemData->sBasicOp.emReqBright].c_str() );
					if ( pItemData->sBasicOp.emReqBright != BRIGHT_BOTH )
					{
						if ( pCharacter->GETBRIGHT() != pItemData->sBasicOp.emReqBright )
						{
							bValue = FALSE;
						}
					}
					AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor ( bValue ) );					

					//	착용조건->격투치
					if ( pItemData->sBasicOp.wReqPA )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION", 1), pItemData->sBasicOp.wReqPA );
						AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor ( pItemData->sBasicOp.wReqPA <= pCharacter->m_wSUM_PA ) );
					}
					//	착용조건->사격치
					if ( pItemData->sBasicOp.wReqSA )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION", 2 ), pItemData->sBasicOp.wReqSA );
						AddTextNoSplit(strText,NS_UITEXTCONTROL::GetEvaluateColor ( pItemData->sBasicOp.wReqSA <= pCharacter->m_wSUM_SA ));
					}

					//	Stats
					//	착용조건->힘
					if ( rItemStats.dwPow )
					{
						strText.Format( "%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 0 ), rItemStats.dwPow );
						AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwPow <= rCharStats.dwPow ) );
					}
					//	착용조건->체력
					if ( rItemStats.dwStr )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 1 ), rItemStats.dwStr );
						AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwStr <= rCharStats.dwStr ) );
					}
					//	착용조건->정신력
					if ( rItemStats.dwSpi)
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 2 ), rItemStats.dwSpi );
						AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwSpi <= rCharStats.dwSpi ) );
					}
					//	착용조건->민첩성
					if ( rItemStats.dwDex )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 3 ), rItemStats.dwDex );
						AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwDex <= rCharStats.dwDex ) );
					}
					//	착용조건->지력
					if ( rItemStats.dwInt  )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 4 ), rItemStats.dwInt );
						AddTextNoSplit(strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwInt <= rCharStats.dwInt ) );
					}
					//	착용조건->근력
					if ( rItemStats.dwSta )
					{
						strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_CONDITION_STATS", 5 ), rItemStats.dwSta );
						AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor ( rItemStats.dwSta <= rCharStats.dwSta ) );
					}

					//-----------------------------------------------------------------------------------------------
					//	저항값
					const int nELEC   = sItemCustom.GETRESIST_ELEC();
					const int nFIRE   = sItemCustom.GETRESIST_FIRE();
					const int nICE    = sItemCustom.GETRESIST_ICE();
					const int nPOISON = sItemCustom.GETRESIST_POISON();
					const int nSPIRIT = sItemCustom.GETRESIST_SPIRIT();

					if ( nELEC || nFIRE || nICE || nPOISON || nSPIRIT )
					{
						AddTextNoSplit ( ID2GAMEWORD ( "ITEM_CATEGORY", 3 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

						if ( nELEC )
						{
							strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_RESIST", 0 ), nELEC );	
							BYTE uGRADE = sItemCustom.GETGRADE(EMGRINDING_RESIST_ELEC);
							APPEND_ITEM_GRADE ( strText, uGRADE );
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}
						if ( nFIRE )
						{
							strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_RESIST", 1 ), nFIRE );
							BYTE uGRADE = sItemCustom.GETGRADE(EMGRINDING_RESIST_FIRE);
							APPEND_ITEM_GRADE ( strText, uGRADE );
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}
						if ( nICE )
						{
							strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_RESIST", 2 ), nICE );
							BYTE uGRADE = sItemCustom.GETGRADE(EMGRINDING_RESIST_ICE);
							APPEND_ITEM_GRADE ( strText, uGRADE );
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}
						if ( nPOISON )
						{
							strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_RESIST", 3 ), nPOISON );
							BYTE uGRADE = sItemCustom.GETGRADE(EMGRINDING_RESIST_POISON);
							APPEND_ITEM_GRADE ( strText, uGRADE );
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}
						if ( nSPIRIT )
						{
							strText.Format("%s:%d", ID2GAMEWORD("ITEM_ADVANCED_INFO_RESIST", 4 ), nSPIRIT );
							BYTE uGRADE = sItemCustom.GETGRADE(EMGRINDING_RESIST_SPIRIT);
							APPEND_ITEM_GRADE ( strText, uGRADE );
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}
					}


					//	상태이상
					EMSTATE_BLOW emBLOW = pItemData->sSuitOp.sBLOW.emTYPE;
					if ( emBLOW !=EMBLOW_NONE )
					{
						AddTextNoSplit ( ID2GAMEWORD ( "ITEM_CATEGORY", 4 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

						strText.Format("%s:%s", ID2GAMEWORD("ITEM_ADVANCED_INFO_ABNORMAL", 0 ), COMMENT::BLOW[emBLOW].c_str() );
						AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);

						strText.Format("%s:%.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_ABNORMAL", 1 ),pItemData->sSuitOp.sBLOW.fLIFE );
						AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);

						strText.Format("%s:%.2f%%", ID2GAMEWORD("ITEM_ADVANCED_INFO_ABNORMAL", 2 ),pItemData->sSuitOp.sBLOW.fRATE );
						AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);

						{
							float fVAR1 = pItemData->sSuitOp.sBLOW.fVAR1 * COMMENT::BLOW_VAR1_SCALE[emBLOW];

							if( fVAR1 != 0.0f )
							{
								if ( COMMENT::IsBLOW1_PER(emBLOW) )
									strText.Format("%s:%.2f%%", COMMENT::BLOW_VAR1[emBLOW].c_str(), fVAR1 );
								else
									strText.Format("%s:%.2f", COMMENT::BLOW_VAR1[emBLOW].c_str(), fVAR1 );

								AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
							}
						}

						{
							float fVAR2 = pItemData->sSuitOp.sBLOW.fVAR2 * COMMENT::BLOW_VAR2_SCALE[emBLOW];

							if( fVAR2 != 0.0f )
							{
								if ( COMMENT::IsBLOW2_PER(emBLOW) )
									strText.Format("%s:%.2f%%", COMMENT::BLOW_VAR2[emBLOW].c_str(), fVAR2 );
								else
									strText.Format("%s:%.2f", COMMENT::BLOW_VAR2[emBLOW].c_str(), fVAR2 );

								AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
							}
						}
					}


					//	NOTE
					//		가산 효과
					AddTextAddValue( sItemCustom, pItemData->sSuitOp );

					//	특수기능
					//
					{
						BOOL bSPAC = sItemCustom.GETINCHP() || sItemCustom.GETINCMP() || sItemCustom.GETINCSP() || sItemCustom.GETINCAP();
						BOOL bVAR_HP(FALSE), bVAR_MP(FALSE), bVAR_SP(FALSE), bVAR_AP(FALSE);

						EMITEM_VAR emITEM_VAR = pItemData->sSuitOp.sVARIATE.emTYPE;
						EMITEM_VAR emITEM_VOL = pItemData->sSuitOp.sVOLUME.emTYPE;
						if ( (emITEM_VAR!=EMVAR_NONE) || (emITEM_VOL!=EMVAR_NONE) || bSPAC )
						{
							AddTextNoSplit ( ID2GAMEWORD ( "ITEM_CATEGORY", 5 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );
						}
						
						if ( sItemCustom.nidDISGUISE!=SNATIVEID(false) )
						{
							SITEM* pJDisguiseData = GLItemMan::GetInstance().GetItem ( sItemCustom.nidDISGUISE );
							if ( pJDisguiseData )
							{
								if ( pJDisguiseData->sBasicOp.IsCostumeCombine() )
								{
									EMITEM_VAR emITEMCOS_VAR = pJDisguiseData->sSuitOp.sVARIATE.emTYPE;
									EMITEM_VAR emITEMCOS_VOL = pJDisguiseData->sSuitOp.sVOLUME.emTYPE;
								//add jitem

									float fVAR_SCALE(0);
									if ( emITEMCOS_VAR != EMVAR_NONE )
									{			
										
										fVAR_SCALE = pJDisguiseData->sSuitOp.sVARIATE.fVariate;
										CString strText2;
										fVAR_SCALE *= COMMENT::ITEMVAR_SCALE[emITEMCOS_VAR];
										strText2.Format("Costume ADD:%s %2.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_SPECIAL_ADD", emITEMCOS_VAR ), fVAR_SCALE );
										if ( COMMENT::IsITEMVAR_SCALE(emITEMCOS_VAR) )		strText2 += "%";
										AddTextNoSplit(strText2,NS_UITEXTCOLOR::PALEGREEN);
									}

									if ( emITEMCOS_VOL != EMVAR_NONE)
									{
										CString strText3;
										float fVOLUME = pJDisguiseData->sSuitOp.sVOLUME.fVolume;
										strText3.Format("Costume ADD:%s %.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_SPECIAL_ADD_VOL", emITEMCOS_VOL ), fVOLUME );
										AddTextNoSplit(strText3,NS_UITEXTCOLOR::PALEGREEN);
									}
								}
							}
						}



						//	특수기능 ( 변화율 )
						//
						float fVAR_SCALE(0);
						if ( emITEM_VAR != EMVAR_NONE )
						{
							switch ( emITEM_VAR )
							{
							case EMVAR_HP:
								bVAR_HP = TRUE;
								fVAR_SCALE = sItemCustom.GETINCHP();
								break;
							case EMVAR_MP:
								bVAR_MP = TRUE;
								fVAR_SCALE = sItemCustom.GETINCMP();
								break;
							case EMVAR_SP:
								bVAR_SP = TRUE;
								fVAR_SCALE = sItemCustom.GETINCSP();
								break;
							case EMVAR_AP:
								bVAR_AP = TRUE;
								fVAR_SCALE = sItemCustom.GETINCAP();
								break;
							default:
								fVAR_SCALE = pItemData->sSuitOp.sVARIATE.fVariate;
								break;
							};

							fVAR_SCALE *= COMMENT::ITEMVAR_SCALE[emITEM_VAR];
							strText.Format("%s %2.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_SPECIAL_ADD", emITEM_VAR ), fVAR_SCALE );
							if ( COMMENT::IsITEMVAR_SCALE(emITEM_VAR) )		strText += "%";
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}

						if ( !bVAR_HP && sItemCustom.GETINCHP() )
						{
							fVAR_SCALE = sItemCustom.GETINCHP();
							emITEM_VAR = EMVAR_HP;
							fVAR_SCALE *= COMMENT::ITEMVAR_SCALE[emITEM_VAR];
							strText.Format("%s %2.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_SPECIAL_ADD", emITEM_VAR ), fVAR_SCALE );
							if ( COMMENT::IsITEMVAR_SCALE(emITEM_VAR) )		strText += "%";
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}

						if ( !bVAR_MP && sItemCustom.GETINCMP() )
						{
							fVAR_SCALE = sItemCustom.GETINCMP();
							emITEM_VAR = EMVAR_MP;
							fVAR_SCALE *= COMMENT::ITEMVAR_SCALE[emITEM_VAR];
							strText.Format("%s %2.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_SPECIAL_ADD", emITEM_VAR ), fVAR_SCALE );
							if ( COMMENT::IsITEMVAR_SCALE(emITEM_VAR) )		strText += "%";
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}

						if ( !bVAR_SP && sItemCustom.GETINCSP() )
						{
							fVAR_SCALE = sItemCustom.GETINCSP();
							emITEM_VAR = EMVAR_SP;
							fVAR_SCALE *= COMMENT::ITEMVAR_SCALE[emITEM_VAR];
							strText.Format("%s %2.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_SPECIAL_ADD", emITEM_VAR ), fVAR_SCALE );
							if ( COMMENT::IsITEMVAR_SCALE(emITEM_VAR) )		strText += "%";
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}

						if ( !bVAR_AP && sItemCustom.GETINCAP() )
						{
							fVAR_SCALE = sItemCustom.GETINCAP();
							emITEM_VAR = EMVAR_AP;
							fVAR_SCALE *= COMMENT::ITEMVAR_SCALE[emITEM_VAR];
							strText.Format("%s %2.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_SPECIAL_ADD", emITEM_VAR ), fVAR_SCALE );
							if ( COMMENT::IsITEMVAR_SCALE(emITEM_VAR) )		strText += "%";
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}

						// 경험치 배율
						float fExpMultiple = pItemData->GetExpMultiple();
						if( fExpMultiple != 1.0f )
						{
							strText.Format("%s %2.2f%s", 
												ID2GAMEWORD( "ITEM_ADVANCED_INFO_SPECIAL_EX", 0 ), 
												fExpMultiple, 
												ID2GAMEWORD( "ITEM_ADVANCED_INFO_SPECIAL_EX", 1 ) );

							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}

						//	특수기능 ( 변화량 )
						//
						if ( emITEM_VOL != EMVAR_NONE)
						{
							if ( emITEM_VOL == EMVAR_MOVE_SPEED )
							{
								float fVOLUME = sItemCustom.GETMOVESPEED();
								strText.Format("%s %.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_SPECIAL_ADD_VOL", emITEM_VOL ), fVOLUME );
								AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
							}
							else
							{
								float fVOLUME = pItemData->sSuitOp.sVOLUME.fVolume;
								strText.Format("%s %.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_SPECIAL_ADD_VOL", emITEM_VOL ), fVOLUME );
								AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
							}
							
						}
					}

					// Note : 랜덤 수치
					if( sItemCustom.IsSetRandOpt() )
					{
						CString strDescText;

						AddTextNoSplit( ID2GAMEWORD ( "ITEM_CATEGORY", 11 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

						INT nRandOptType = sItemCustom.GETOptTYPE1();
						if( (EMR_OPT_NULL < nRandOptType) && (nRandOptType < EMR_OPT_SIZE) )
						{
							strDescText.Format( "%s:", ID2GAMEWORD("ITEM_RANDOM_OPTION", nRandOptType ) );

							float fVal = sItemCustom.GETOptVALUE1();
							if( fVal != 0.0f )
							{
								if( fVal > 0.0f) strDescText += _T('+');

								strDescText.AppendFormat( "%.2f", fVal );
								if( sItemCustom.IsPerRandOpt( nRandOptType ) ) strDescText += _T('%');

								AddTextNoSplit( strDescText, NS_UITEXTCOLOR::PRIVATE );
							}
						}

						nRandOptType = sItemCustom.GETOptTYPE2();
						if( (EMR_OPT_NULL < nRandOptType) && (nRandOptType < EMR_OPT_SIZE) )
						{
							strDescText.Format( "%s:", ID2GAMEWORD("ITEM_RANDOM_OPTION", nRandOptType ) );

							float fVal = sItemCustom.GETOptVALUE2();
							if( fVal != 0.0f )
							{
								if( fVal > 0.0f) strDescText += _T('+');

								strDescText.AppendFormat( "%.2f", fVal );
								if( sItemCustom.IsPerRandOpt( nRandOptType ) ) strDescText += _T('%');

								AddTextNoSplit( strDescText, NS_UITEXTCOLOR::PRIVATE );
							}
						}

						nRandOptType = sItemCustom.GETOptTYPE3();
						if( (EMR_OPT_NULL < nRandOptType) && (nRandOptType < EMR_OPT_SIZE) )
						{
							strDescText.Format( "%s:", ID2GAMEWORD("ITEM_RANDOM_OPTION", nRandOptType ) );

							float fVal = sItemCustom.GETOptVALUE3();
							if( fVal != 0.0f )
							{
								if( fVal > 0.0f) strDescText += _T('+');

								strDescText.AppendFormat( "%.2f", fVal );
								if( sItemCustom.IsPerRandOpt( nRandOptType ) ) strDescText += _T('%');

								AddTextNoSplit( strDescText, NS_UITEXTCOLOR::PRIVATE );
							}
						}

						nRandOptType = sItemCustom.GETOptTYPE4();
						if( (EMR_OPT_NULL < nRandOptType) && (nRandOptType < EMR_OPT_SIZE) )
						{
							strDescText.Format( "%s:", ID2GAMEWORD("ITEM_RANDOM_OPTION", nRandOptType ) );

							float fVal = sItemCustom.GETOptVALUE4();
							if( fVal != 0.0f )
							{
								if( fVal > 0.0f) strDescText += _T('+');

								strDescText.AppendFormat( "%.2f", fVal );
								if( sItemCustom.IsPerRandOpt( nRandOptType ) ) strDescText += _T('%');

								AddTextNoSplit( strDescText, NS_UITEXTCOLOR::PRIVATE );
							}
						}
					}
				}
				break;

			case ITEM_CHARM:
				{
					AddTextNoSplit ( ID2GAMEWORD ( "ITEM_CATEGORY", 1 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

					//	공격력
					GLPADATA &sDAMAGE = sItemCustom.GETDAMAGE();
					if ( sDAMAGE.dwLow || sDAMAGE.dwHigh  )
					{
						strText.Format("Talisman %s:%s~%s ", ID2GAMEWORD("ITEM_ARROW_INFO", 0 ), 
													GetNumberWithSign ( sDAMAGE.dwLow ), 
													GetNumberWithSign ( sDAMAGE.dwHigh ) );

						AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);
					}
 

					//	NOTE
					//		가산 효과
					AddTextAddValue( sItemCustom, pItemData->sSuitOp );					
				}
				break;

			case ITEM_ARROW:
				{
					AddTextNoSplit ( ID2GAMEWORD ( "ITEM_CATEGORY", 1 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

					//	공격력
					GLPADATA &sDAMAGE = sItemCustom.GETDAMAGE();
					if ( sDAMAGE.dwLow || sDAMAGE.dwHigh  )
					{
						strText.Format("Arrow %s:%s~%s ", ID2GAMEWORD("ITEM_ARROW_INFO", 0 ), 
													GetNumberWithSign ( sDAMAGE.dwLow ), 
													GetNumberWithSign ( sDAMAGE.dwHigh ) );

						AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);
					}
 

					//	NOTE
					//		가산 효과
					AddTextAddValue( sItemCustom, pItemData->sSuitOp );					
				}
				break;
				//add bullet
			case ITEM_BULLET:
				{
					AddTextNoSplit ( ID2GAMEWORD ( "ITEM_CATEGORY", 1 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

					//	공격력
					GLPADATA &sDAMAGE = sItemCustom.GETDAMAGE();
					if ( sDAMAGE.dwLow || sDAMAGE.dwHigh  )
					{
						strText.Format("Bullet %s:%s~%s ", ID2GAMEWORD("ITEM_ARROW_INFO", 0 ), 
													GetNumberWithSign ( sDAMAGE.dwLow ), 
													GetNumberWithSign ( sDAMAGE.dwHigh ) );

						AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);
					}
 

					//	NOTE
					//		가산 효과
					AddTextAddValue( sItemCustom, pItemData->sSuitOp );					
				}
				break;

			case ITEM_CURE:
				{
					AddTextNoSplit ( ID2GAMEWORD ( "ITEM_CATEGORY", 7 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

					if( pItemData->sDrugOp.wCureVolume == 0 )
					{
						strText.Format("%s",COMMENT::ITEMDRUG[pItemData->sDrugOp.emDrug].c_str());
					}
					else
					{
						strText.Format("%s:%d",COMMENT::ITEMDRUG[pItemData->sDrugOp.emDrug].c_str(), pItemData->sDrugOp.wCureVolume);
					}

					AddTextNoSplit(strText, NS_UITEXTCOLOR::DEFAULT);
				}
				break;

			case ITEM_SKILL:
				{
					AddInfoSkillItem ( sItemCustom );
				}
				break;

			case ITEM_PET_SKILL:
				{
					AddInfoPetSkillItem( sItemCustom );
				}
				break;

			case ITEM_GRINDING:
				{
					AddTextNoSplit ( ID2GAMEWORD ( "ITEM_CATEGORY_EX", 0 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );
				}
				break;

				// 경험치 획득 카드 정보
			case ITEM_VIETNAM_EXPGET:
				{
					if ( pItemData->sDrugOp.bRatio )
					{
						strText.Format(ID2GAMEWORD ("ITEM_CATEGORY_VIETNAM_EXP", 1) , pItemData->sDrugOp.wCureVolume );						
					}
					else
					{
						strText.Format(ID2GAMEWORD ("ITEM_CATEGORY_VIETNAM_EXP", 0), pItemData->sDrugOp.wCureVolume );
					}

					AddTextNoSplit(strText,NS_UITEXTCOLOR::LIGHTSKYBLUE);
				}
				break;
				// 아이템 획득 카드 정보
			case ITEM_VIETNAM_ITEMGET:
				{
					strText.Format(ID2GAMEWORD ("ITEM_CATEGORY_VIETNAM_ITEM", 0) , pItemData->sDrugOp.wCureVolume );
					AddTextNoSplit(strText,NS_UITEXTCOLOR::LIGHTSKYBLUE);
				}
				break;

			case ITEM_VEHICLE:
				{
					strText.Format(ID2GAMEWORD ("ITEM_VEHICLE_TYPE_INFO", 0) , COMMENT::VEHICLE_TYPE[pItemData->sVehicle.emVehicleType].c_str() );
					AddTextNoSplit(strText,NS_UITEXTCOLOR::LIGHTSKYBLUE);

					strText.Format( "%s %s", ID2GAMEWORD ("ITEM_VEHICLE_NAME",0), COMMENT::VEHICLE_TYPE[pItemData->sVehicle.emVehicleType].c_str() );
					AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);

					
					EMITEM_VAR emITEM_VOL = pItemData->sSuitOp.sVOLUME.emTYPE;
					//	이동속도 변화량
					//
					if ( emITEM_VOL != EMVAR_NONE)
					{
						if ( emITEM_VOL == EMVAR_MOVE_SPEED )
						{
							float fVOLUME = sItemCustom.GETMOVESPEED();
							strText.Format("%s %.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_SPECIAL_ADD_VOL", emITEM_VOL ), fVOLUME );
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}
						else
						{
							float fVOLUME = pItemData->sSuitOp.sVOLUME.fVolume;
							strText.Format("%s %.2f", ID2GAMEWORD("ITEM_ADVANCED_INFO_SPECIAL_ADD_VOL", emITEM_VOL ), fVOLUME );
							AddTextNoSplit(strText,NS_UITEXTCOLOR::PRIVATE);
						}
					}


					bool bInfo(true);

					
					VEHICLEITEMINFO_MAP_ITER iter = GLGaeaClient::GetInstance().GetCharacter()->m_mapVEHICLEItemInfo.find ( sItemCustom.dwVehicleID );
					if ( iter == GLGaeaClient::GetInstance().GetCharacter()->m_mapVEHICLEItemInfo.end() )
					{
						iter = GLGaeaClient::GetInstance().GetCharacter()->m_mapVEHICLEItemInfoTemp.find ( sItemCustom.dwVehicleID );
						if ( iter == GLGaeaClient::GetInstance().GetCharacter()->m_mapVEHICLEItemInfoTemp.end() )	bInfo = false;
					}


					if ( bInfo ) 
					{
						SVEHICLEITEMINFO sVehicleItemInfo = (*iter).second;
						for ( int i = 0; i < VEHICLE_ACCETYPE_SIZE; ++i ) 
						{
							SITEM* pItem = GLItemMan::GetInstance().GetItem ( sVehicleItemInfo.m_PutOnItems[i].sNativeID );
							if ( pItem )
							{
								strText.Format("%s %s", ID2GAMEWORD ("ITEM_VEHICLE_SLOT",i), pItem->GetName () );
								AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);
							}
						}

						strText.Format( "%s %.2f%%", ID2GAMEWORD ("ITEM_VEHICLE_BATTERY",0), sVehicleItemInfo.m_nFull/10.0f );
						AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);
					}


					AddTextNoSplit( ID2GAMEWORD ( "ITEM_CATEGORY", 2 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

					DWORD dwReqCharClass = pItemData->sBasicOp.dwReqCharClass;
					CString szClass;
					
					if( dwReqCharClass )
					{
						//if ( dwReqCharClass==GLCC_ALL_NEWSEX)
						//add class
						if ( dwReqCharClass==GLCC_ALL_2012)
						{
							szClass = ID2GAMEWORD("ITEM_ALL_CLASS");
						}
						else
						{
							if ( dwReqCharClass & GLCC_FIGHTER_M)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_FIGHTER_M)].c_str();
								szClass+=" ";
							}
							if ( dwReqCharClass & GLCC_FIGHTER_W)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_FIGHTER_W)].c_str();
								szClass+=" ";
							}
							if ( dwReqCharClass & GLCC_ARMS_M)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARMS_M)].c_str();
								szClass+=" ";
							}
							if ( dwReqCharClass & GLCC_ARMS_W)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARMS_W)].c_str();
								szClass+=" ";
							}
							if ( dwReqCharClass & GLCC_ARCHER_M)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARCHER_M)].c_str();
								szClass+=" ";
							}
							if ( dwReqCharClass & GLCC_ARCHER_W)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ARCHER_W)].c_str();
								szClass+=" ";
							}
							if ( dwReqCharClass & GLCC_SPIRIT_M)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SPIRIT_M)].c_str();
								szClass+=" ";
							}
							if ( dwReqCharClass & GLCC_SPIRIT_W)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SPIRIT_W)].c_str();
								szClass+=" ";
							}
							if ( dwReqCharClass & GLCC_EXTREME_M)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_EXTREME_M)].c_str();
								szClass+=" ";
							}
							if ( dwReqCharClass & GLCC_EXTREME_W)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_EXTREME_W)].c_str();
							}
							//add class "SCIENCE"
							if ( dwReqCharClass & GLCC_SCIENCE_M)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SCIENCE_M)].c_str();
							}
							if ( dwReqCharClass & GLCC_SCIENCE_W)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_SCIENCE_W)].c_str();
							}
							//add class "ASSASSIN"
							if ( dwReqCharClass & GLCC_ASSASIN_M)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ASSASIN_M)].c_str();
							}
							if ( dwReqCharClass & GLCC_ASSASIN_W)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_ASSASIN_W)].c_str();
							}
							//add class "MAGICIAN"
							if ( dwReqCharClass & GLCC_MAGICIAN_M)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_MAGICIAN_M)].c_str();
							}
							if ( dwReqCharClass & GLCC_MAGICIAN_W)
							{
								szClass+=COMMENT::CHARCLASS[CharClassToIndex(GLCC_MAGICIAN_W)].c_str();
							}
								//
						}

						strText.Format( "%s", szClass.GetString() );
						AddTextNoSplit ( strText, NS_UITEXTCONTROL::GetEvaluateColor ( dwReqCharClass & pCharacter->m_emClass ) );
					}					

					// Note : 랜덤 수치
					if( sItemCustom.IsSetRandOpt() )
					{
						CString strDescText;

						AddTextNoSplit( ID2GAMEWORD ( "ITEM_CATEGORY", 11 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

						INT nRandOptType = sItemCustom.GETOptTYPE1();
						if( (EMR_OPT_NULL < nRandOptType) && (nRandOptType < EMR_OPT_SIZE) )
						{
							strDescText.Format( "%s:", ID2GAMEWORD("ITEM_RANDOM_OPTION", nRandOptType ) );

							float fVal = sItemCustom.GETOptVALUE1();
							if( fVal != 0.0f )
							{
								if( fVal > 0.0f) strDescText += _T('+');

								strDescText.AppendFormat( "%.2f", fVal );
								if( sItemCustom.IsPerRandOpt( nRandOptType ) ) strDescText += _T('%');

								AddTextNoSplit( strDescText, NS_UITEXTCOLOR::PRIVATE );
							}
						}

						nRandOptType = sItemCustom.GETOptTYPE2();
						if( (EMR_OPT_NULL < nRandOptType) && (nRandOptType < EMR_OPT_SIZE) )
						{
							strDescText.Format( "%s:", ID2GAMEWORD("ITEM_RANDOM_OPTION", nRandOptType ) );

							float fVal = sItemCustom.GETOptVALUE2();
							if( fVal != 0.0f )
							{
								if( fVal > 0.0f) strDescText += _T('+');

								strDescText.AppendFormat( "%.2f", fVal );
								if( sItemCustom.IsPerRandOpt( nRandOptType ) ) strDescText += _T('%');

								AddTextNoSplit( strDescText, NS_UITEXTCOLOR::PRIVATE );
							}
						}

						nRandOptType = sItemCustom.GETOptTYPE3();
						if( (EMR_OPT_NULL < nRandOptType) && (nRandOptType < EMR_OPT_SIZE) )
						{
							strDescText.Format( "%s:", ID2GAMEWORD("ITEM_RANDOM_OPTION", nRandOptType ) );

							float fVal = sItemCustom.GETOptVALUE3();
							if( fVal != 0.0f )
							{
								if( fVal > 0.0f) strDescText += _T('+');

								strDescText.AppendFormat( "%.2f", fVal );
								if( sItemCustom.IsPerRandOpt( nRandOptType ) ) strDescText += _T('%');

								AddTextNoSplit( strDescText, NS_UITEXTCOLOR::PRIVATE );
							}
						}

						nRandOptType = sItemCustom.GETOptTYPE4();
						if( (EMR_OPT_NULL < nRandOptType) && (nRandOptType < EMR_OPT_SIZE) )
						{
							strDescText.Format( "%s:", ID2GAMEWORD("ITEM_RANDOM_OPTION", nRandOptType ) );

							float fVal = sItemCustom.GETOptVALUE4();
							if( fVal != 0.0f )
							{
								if( fVal > 0.0f) strDescText += _T('+');

								strDescText.AppendFormat( "%.2f", fVal );
								if( sItemCustom.IsPerRandOpt( nRandOptType ) ) strDescText += _T('%');

								AddTextNoSplit( strDescText, NS_UITEXTCOLOR::PRIVATE );
							}
						}
					}

				}
				break;

			case ITEM_PET_CARD:
				{
					if ( sItemCustom.dwPetID == 0 ) break;
					PETCARDINFO_MAP_ITER iter = GLGaeaClient::GetInstance().GetCharacter()->m_mapPETCardInfo.find ( sItemCustom.dwPetID );
					if ( iter == GLGaeaClient::GetInstance().GetCharacter()->m_mapPETCardInfo.end() )
					{
						iter = GLGaeaClient::GetInstance().GetCharacter()->m_mapPETCardInfoTemp.find ( sItemCustom.dwPetID );
						if ( iter == GLGaeaClient::GetInstance().GetCharacter()->m_mapPETCardInfoTemp.end() ) break;
					}

					SPETCARDINFO sPetCardInfo = (*iter).second;

					strText.Format(ID2GAMEWORD ("ITEM_PET_INFO", 0 ));
					AddTextNoSplit(strText,NS_UITEXTCOLOR::LIGHTSKYBLUE);

					strText.Format( "%s %s", ID2GAMEWORD ("ITEM_PET_NAME",0), sPetCardInfo.m_szName );
					AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);

					strText.Format( "%s %s", ID2GAMEWORD ("ITEM_PET_TYPE",0), COMMENT::PET_TYPE[sPetCardInfo.m_emTYPE].c_str() );
					AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);

					strText.Format( "%s %.2f%%", ID2GAMEWORD ("ITEM_PET_FULL",0), sPetCardInfo.m_nFull/10.0f );
					AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);
					
					SITEM* pItem = GLItemMan::GetInstance().GetItem ( sPetCardInfo.m_PutOnItems[PET_ACCETYPE_A].sNativeID );
					if ( pItem )
					{
						strText.Format("%s %s", ID2GAMEWORD ("ITEM_PET_SLOTA",0), pItem->GetName () );
						AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);
					}

					pItem = GLItemMan::GetInstance().GetItem ( sPetCardInfo.m_PutOnItems[PET_ACCETYPE_B].sNativeID );
					if ( pItem )
					{
						strText.Format("%s %s", ID2GAMEWORD ("ITEM_PET_SLOTB",0), pItem->GetName () );
						AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);
					}

					if ( sItemCustom.tDISGUISE != 0 )
					{
						CTime currentTime = GLGaeaClient::GetInstance().GetCurrentTime();
						CTime startTime   = sItemCustom.tBORNTIME;
						CTimeSpan timeSpan = currentTime - startTime;
						if( timeSpan.GetTotalSeconds() < sItemCustom.tDISGUISE )
						{
							strText.Format("[%s]", ID2GAMEWORD ("ITEM_PET_USE_SKINPACK",0) );
							AddTextNoSplit(strText,NS_UITEXTCOLOR::GOLD);
							strText.Format("%s : %dsec", ID2GAMEWORD ("CLUB_BATTLE_TIME",0), sItemCustom.tDISGUISE - timeSpan.GetTotalSeconds() );
							AddTextNoSplit(strText,NS_UITEXTCOLOR::GOLD);
						}
					}

					AddTextNoSplit( ID2GAMEWORD ("ITEM_PET_SKILLS", 0 ), NS_UITEXTCOLOR::DEFAULT );

					PETSKILL_MAP_CITER pos = sPetCardInfo.m_ExpSkills.begin();
					PETSKILL_MAP_CITER pos_end = sPetCardInfo.m_ExpSkills.end();
					for ( ;pos != pos_end; ++pos )
					{
						const PETSKILL& sPetSkill = (*pos).second;
						PGLSKILL pSKILL = GLSkillMan::GetInstance().GetData( sPetSkill.sNativeID );
						if ( pSKILL )
						{
							strText.Format("%s", pSKILL->GetName() );
							AddTextNoSplit(strText,NS_UITEXTCOLOR::DEFAULT);
						}
					}
					if (sPetCardInfo.m_bDualSkill)
					{
						strText.Format("%s: %s","Dual Skill", ID2GAMEWORD("ITEM_PET_DUAL_SKILL", 1));
						AddTextNoSplit(strText, NS_UITEXTCOLOR::DEFAULT);
					}
					else
					{
						strText.Format("%s: %s","Dual Skill", ID2GAMEWORD("ITEM_PET_DUAL_SKILL", 0));
						AddTextNoSplit(strText, NS_UITEXTCOLOR::DEFAULT);
					}
				}
				break;

				/////////

				///////////
			}
			
			if( emItemType != ITEM_PET_SKILL )
			{
				AddTextNoSplit( ID2GAMEWORD( "ITEM_CATEGORY", 8 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );

				// Note : 시귀/직귀 카드에 맵이름 좌표 출력
				if( pItemData->sDrugOp.emDrug == ITEM_DRUG_CALL_REGEN )
				{
					GLCharacter* pCharacter = GLGaeaClient::GetInstance().GetCharacter();	

					CString strName( GLGaeaClient::GetInstance().GetMapName( pCharacter->m_sStartMapID ) );
					if( strName == _T("(null)") ) strName.Empty();

					strText.Format( "%s:%s", ID2GAMEWORD("ITEM_CALL_MAP", 0 ), strName );
					AddTextNoSplit( strText, NS_UITEXTCOLOR::DEFAULT);

					SMAPNODE *pMapNode = GLGaeaClient::GetInstance().FindMapNode ( pCharacter->m_sStartMapID );
					if( pMapNode )
					{
						GLLevelFile cLevelFile;
						BOOL bOk = cLevelFile.LoadFile( pMapNode->strFile.c_str(), TRUE, NULL );
						if( bOk )
						{	
							D3DXVECTOR3 vStartPos;
							PDXLANDGATE pGate = cLevelFile.GetLandGateMan().FindLandGate( pCharacter->m_dwStartGate );
							if( pGate )
							{
								vStartPos = pGate->GetGenPos ( DxLandGate::GEN_RENDUM );
							}
							else
							{
								pGate = cLevelFile.GetLandGateMan().FindLandGate( DWORD(0) );
								if( pGate ) vStartPos = pGate->GetGenPos ( DxLandGate::GEN_RENDUM );
							}

							int nPosX(0), nPosY(0);
							cLevelFile.GetMapAxisInfo().Convert2MapPos( vStartPos.x, vStartPos.z, nPosX, nPosY );

							strText.Format( "%s:%d,%d", ID2GAMEWORD("ITEM_CALL_MAP", 1 ), nPosX, nPosY );
							AddTextNoSplit( strText, NS_UITEXTCOLOR::DEFAULT);
						}
					}
				}
				else if( pItemData->sDrugOp.emDrug == ITEM_DRUG_CALL_LASTCALL )
				{
					GLCharacter* pCharacter = GLGaeaClient::GetInstance().GetCharacter();

					if( pCharacter->m_sLastCallMapID.IsValidNativeID() )
					{
						CString strName( GLGaeaClient::GetInstance().GetMapName( pCharacter->m_sLastCallMapID ) );
						if( strName == _T("(null)") ) strName.Empty();

						strText.Format( "%s:%s", ID2GAMEWORD("ITEM_CALL_MAP", 0 ), strName );
						AddTextNoSplit( strText, NS_UITEXTCOLOR::DEFAULT);

						SMAPNODE *pMapNode = GLGaeaClient::GetInstance().FindMapNode ( pCharacter->m_sLastCallMapID );
						if( pMapNode )
						{
							GLLevelFile cLevelFile;
							BOOL bOk = cLevelFile.LoadFile( pMapNode->strFile.c_str(), TRUE, NULL );
							if( bOk )
							{	
								int nPosX(0), nPosY(0);
								cLevelFile.GetMapAxisInfo().Convert2MapPos( pCharacter->m_vLastCallPos.x, pCharacter->m_vLastCallPos.z, nPosX, nPosY );

								strText.Format( "%s:%d,%d", ID2GAMEWORD("ITEM_CALL_MAP", 1 ), nPosX, nPosY );
								AddTextNoSplit( strText, NS_UITEXTCOLOR::DEFAULT);
							}
						}
					}
					else
					{
						AddTextNoSplit( ID2GAMEWORD("ITEM_CALL_MAP", 2 ), NS_UITEXTCOLOR::RED);
					}
				}
				else if ( pItemData->sDrugOp.emDrug == ITEM_DRUG_CALL_TELEPORT )
				{
					CString strName( GLGaeaClient::GetInstance().GetMapName( pItemData->sBasicOp.sSubID ) );
					if( strName == _T("(null)") ) strName.Empty();

					strText.Format( "%s:%s", ID2GAMEWORD("ITEM_TELEPORT_MAP", 0 ), strName );
					AddTextNoSplit( strText, NS_UITEXTCOLOR::DEFAULT);

					strText.Format( "%s:%d,%d", ID2GAMEWORD("ITEM_TELEPORT_MAP", 1 ), pItemData->sBasicOp.wPosX, pItemData->sBasicOp.wPosY );
					AddTextNoSplit( strText, NS_UITEXTCOLOR::DEFAULT);
				}

				BOOL bAccept(FALSE);

				if( sItemCustom.nidDISGUISE != NATIVEID_NULL() )
				{
					bAccept = pCharacter->ACCEPT_ITEM( sItemCustom.sNativeID, sItemCustom.nidDISGUISE );
				}
				else
				{
					bAccept = pCharacter->ACCEPT_ITEM( sItemCustom.sNativeID );
				}

				if ( bAccept )
				{
					strText.Format ( "[%s]", ID2GAMEWORD("ITEM_USABLE", 0 ) );
					AddTextNoSplit(strText, NS_UITEXTCOLOR::ENABLE );

					DWORD dwNeedSP = pCharacter->CALC_ACCEPTP ( sItemCustom.sNativeID );
					if ( 0 < dwNeedSP )
					{
						strText.Format ( "%s:%d", ID2GAMEWORD("ITEM_NEEDSP" ), dwNeedSP );
						AddTextNoSplit(strText, NS_UITEXTCOLOR::PALEGREEN );
					}
				}
				else
				{
					strText.Format ( "[%s]", ID2GAMEWORD("ITEM_USABLE", 1 ) );
					AddTextNoSplit(strText, NS_UITEXTCOLOR::RED );
				}
			}

			{ // 설명
				const TCHAR * pszComment(NULL);

				if ( (emItemType != ITEM_SKILL) || (emItemType != ITEM_PET_SKILL) )
				{
					pszComment = pItemData->GetComment();
				}
				else
				{
					SNATIVEID sNativeID = sItemCustom.sNativeID;
					SITEM* pItemData = GLItemMan::GetInstance().GetItem ( sNativeID );
					SNATIVEID sSkillID = pItemData->sSkillBookOp.sSkill_ID;

					//	Note : 스킬 정보 가져옴.
					PGLSKILL pSkill = GLSkillMan::GetInstance().GetData ( sSkillID.wMainID, sSkillID.wSubID );
					if ( pSkill )
					{
						pszComment = pSkill->GetDesc();
					}
				}

				if( pszComment )
				{
					int StrLength = static_cast<int>( strlen( pszComment ) );
					if( StrLength )
					{
						AddTextNoSplit ( ID2GAMEWORD( "ITEM_CATEGORY", 9 ), NS_UITEXTCOLOR::LIGHTSKYBLUE );
						AddTextLongestLineSplit( pszComment, NS_UITEXTCOLOR::DEFAULT );
					}
				}
			}

			//add money 2
			{

				DWORD dwFlags = pItemData->sBasicOp.dwFlags;
				CString szFlag;
					
				if( dwFlags )
				{			
					if ( dwFlags & TRADE_SALE)
					{
						szFlag+=( ID2GAMEWORD( "ITEM_FLAG", 0 ));
						szFlag+=", ";
					}
					if ( dwFlags & TRADE_EXCHANGE)
					{
						szFlag+=( ID2GAMEWORD( "ITEM_FLAG", 1 ));
						szFlag+=", ";
					}
					if ( dwFlags & TRADE_THROW)
					{
						szFlag+=( ID2GAMEWORD( "ITEM_FLAG", 2 ));
						szFlag+=", ";
					}
					if ( dwFlags & TRADE_EVENT_SGL)
					{
						szFlag+=( ID2GAMEWORD( "ITEM_FLAG", 3 ));
						szFlag+=", ";
					}
					if ( dwFlags & TRADE_GARBAGE)
					{
						szFlag+=( ID2GAMEWORD( "ITEM_FLAG", 4 ));
						szFlag+=", ";
					}
					if ( dwFlags & TRADE_LOCKER)
					{
						szFlag+=( ID2GAMEWORD( "ITEM_FLAG", 5 ));
						szFlag+=", ";
					}
					//
					if ( dwFlags & ITEM_OWNERSHIP)
					{
						szFlag+=( ID2GAMEWORD( "ITEM_FLAG", 8 ));
						szFlag+=", ";
					}
					//
					if ( dwFlags & ITEM_POINT_RECOVER)
					{
						szFlag+=( ID2GAMEWORD( "ITEM_FLAG", 9 ));
						szFlag+=", ";
					}
					//
					if ( dwFlags & ITEM_COSTUME_COMBINE)
					{
						szFlag+=( ID2GAMEWORD( "ITEM_FLAG", 10 ));
						szFlag+=", ";
					}
														
				}
				if (pItemData->sBasicOp.emLevel == LEVEL_VOTE_ITEM )
				{
					szFlag+=( ID2GAMEWORD( "ITEM_FLAG", 6 ));
					szFlag+=", ";
				}
				if (pItemData->sBasicOp.emLevel == LEVEL_PREMIUM_ITEM )
				{
					szFlag+=( ID2GAMEWORD( "ITEM_FLAG", 7 ));
					szFlag+=", ";
				}

				strText.Format( "%s", szFlag.GetString() );
				AddTextNoSplit ( strText, NS_UITEXTCOLOR::LIGHTSKYBLUE );
			}
			//add ownership
			{

				DWORD dwOwner = sItemCustom.dwOwnerID;
				DWORD dwOwnerID =GLGaeaClient::GetInstance().GetCharacter()->m_dwCharID;

				if ( pItemData->sBasicOp.IsOwner() )
				{
					if (pItemData->sBasicOp.emLevel == LEVEL_VOTE_ITEM )
					{
						strText.Format( "Vote Item Owner ID: %d", dwOwner );
						if ( !( dwOwnerID == dwOwner))
						{
						AddTextNoSplit ( strText, NS_UITEXTCOLOR::RED );
						}
						else
						{
						AddTextNoSplit ( strText, NS_UITEXTCOLOR::LIGHTSKYBLUE );
						}
					}
					//
					if (pItemData->sBasicOp.emLevel == LEVEL_PREMIUM_ITEM )
					{
						strText.Format( "Premium Item Owner ID: %d", dwOwner );
						if ( !( dwOwnerID == dwOwner))
						{
						AddTextNoSplit ( strText, NS_UITEXTCOLOR::RED );
						}
						else
						{
						AddTextNoSplit ( strText, NS_UITEXTCOLOR::LIGHTSKYBLUE );
						}
					}
				}
				if ( sNpcNativeID != sItemCustom.sNativeID )  
				{ 
                sNpcNativeID = sItemCustom.sNativeID; 
         
                if ( sNpcNativeID.IsValidNativeID() ) 
                { 
                    SITEM* pItem = GLItemMan::GetInstance().GetItem ( sNpcNativeID ); 
                    if ( !pItem ) 
                    { 
                        GASSERT ( 0 && " " ); 
                        return ; 
                        ResetItemRender (); 
                    }     
                        ResetItemRender ();     
                        AddItemRender ( pItem->sBasicOp.sICONID, pItem->GetInventoryFile() );
                } 
				}
            }  
		}
	}
};
