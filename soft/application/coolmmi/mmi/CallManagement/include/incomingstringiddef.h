/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of COOLSAND Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("COOLSAND SOFTWARE")
*  RECEIVED FROM COOLSAND AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. COOLSAND EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES COOLSAND PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE COOLSAND SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. COOLSAND SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY COOLSAND SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND COOLSAND'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE COOLSAND SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT COOLSAND'S OPTION, TO REVISE OR REPLACE THE COOLSAND SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  COOLSAND FOR SUCH COOLSAND SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  IncomingStringIdDef.h
 *
 * Project:
 * --------
 
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 * 				HISTORY
 
 *------------------------------------------------------------------------------
 *
 *
 *------------------------------------------------------------------------------
 
 *==============================================================================
 *******************************************************************************/

/**************************************************************

	FILENAME	: IncomingStringIdDef.h

  	PURPOSE		: String ID definitions for Incoming call

 

	 

	DATE		: nov' 07, 2002

**************************************************************/
#ifndef INCOMING_STRING_ID_DEF_H
#define INCOMING_STRING_ID_DEF_H
	/* Strings */
	INC_SCR_RSK_STR,
	INC_SCR_NFY_STR,

	TITLE_STR_ACT_LIST,
	STR_USSD_REQ_CAPTION,
	STR_USSD_REQ_DISP_SCR,
	INCOMING_UNKNOWN_ERROR,
	INCOMING_DEFAULT_ERROR,
	ERROR_USSD_ABORTED,
	STR_CALL_MANAGEMENT,

	INC_MRK_ERR_STR,

	STR_UNKNOWN_CALLER,
	INC_SCR_MRK_TITLE,
	STR_ERROR,
	ERROR_UNASSIGNED_NUMBER,
	ERROR_SERVICE_NOT_ALLOWED,
	ERROR_USER_BUSY,
	ERROR_USER_NOT_RESPONDING,
	ERROR_CALL_REJECTED,
	ERROR_NUMBER_CHANGED,
	ERROR_PRE_EMPTION,
	ERROR_NUMBER_FORMAT,
	ERROR_NO_CREDIT,
	ERROR_UNRECOGNIZED_NUMBER,
	ERROR_FAIL,
	ERROR_NETWORK_FAIL,
	ERROR_NETWORK_NOT_AVAILABLE,
	ERROR_BUSY_NETWORK,
	ERROR_BARRED_CALL,
	ERROR_NOT_RESPONDING,
	ERROR_NO_ANSWER,
	ERROR_ACM_EXCEEDED,
	ERROR_UNAVAILABLE,
	ERROR_UNEXPECTED_ERROR,
	ERROR_IMSI_UNKNOWN,
	ERROR_IMEI_ERROR,
	ERROR_GPRS_NOT_ALLOWED,
	ERROR_MT_DATA_CALL,
	ERROR_NETWORK_NOT_ALLOWED,
	ERROR_COMMAND_NOT_SUPPORTED,
	ERROR_DATA_ERROR,
	ERROR_MESSAGE_TYPE_ERROR,
	ERROR_ACCESS_FAIL,
	ERROR_TIMER_EXPIRED,
	ERROR_EMERGENCY_NOT_ALLOWED,
	ERROR_NO_SERVICE,
	ERROR_INVALID_COMMAND,
	ERROR_FDN_FAIL,
	STR_MITEM_INC_OPT_ANSWER,
	STR_MITEM_INC_OPT_DEFLN,
	STR_MITEM_INC_ACT_OPT_END_ACT,
	STR_MITEM_INC_HLD_OPT_RTRV,
	STR_NFY_CALL_FWDNG_CONDITIONAL,
	STR_NFY_CALL_FWDNG_UNCONDITIONAL,
	STR_NFY_CALL_FWDED,
	STR_NFY_CALL_FWDED_CONDITIONAL,
	STR_NFY_CALL_FWDED_UNCONDITIONAL,
	STR_NFY_CALL_BUSY_FORWARDED,
	STR_NFY_CALL_FWDED_NOREPLY,
	STR_NFY_CALL_FWDED_NOT_REACHABLE,
	STR_NFY_CALL_BSYFWD,
	STR_NFY_CALL_ALL_BARRED,
	STR_NFY_CALL_ALL_OUTGOING_BARRED,
	STR_NFY_CALL_ALL_INCOMING_BARRED,
	STR_NFY_CALL_WTG,
	STR_NFY_CALL_HLD,
	STR_NFY_CALL_RTVD,
	STR_NFY_CALL_SWAP,
	STR_NFY_CALL_CONF,
	STR_NFY_CALL_SPLIT,
	STR_NFY_CALL_CUG,
	STR_NFY_CALL_CTFAC,
	TITLE_SCR_NFY,
	STR_TITLE_SCR_USSN_IND,
	STR_MSG_USSN_IND,
	STR_TITLE_SCR_USSN_MSG,
	STR_TITLE_SCR_USSD_MSG,

	STR_TITLE_SCR_USSR_IND,
	STR_MSG_USSR_IND,
	STR_TITLE_SCR_USSR_MSG,
	STR_TITLE_SCR_USSR_EDIT_MSG,
	STR_TITLE_SCR_USSD_EDIT_MSG,

	INC_SCR_NFY_CCBS_STR,
	STR_NFY_CCBS,
	CCBS_ACTIVATED_STR,

	INC_SCR_RSK_DROP_STR,
	HCL_LSK_STR,
	HCL_RSK_STR,
	TITLE_STR_HLD_LIST,
	STR_MITEM_INC_HLD_OPT_END,
	STR_MITEM_IAH_OPT_END_ACT,
	STR_MITEM_IAH_OPT_END_HLD,
	STR_MITEM_IAH_OPT_END_ALL,
	STR_MITEM_IMA_OPT_SPLIT,
	STR_MITEM_INC_OPT_DROP,
	STR_MITEM_INC_OPT_LOUDSP,
	STR_MITEM_INC_ACT_OPT_END_ACT_ACPT,
	STR_MITEM_INC_ACT_OPT_HOLD_ACT,
	STR_MITEM_INC_ACT_OPT_MUTE,
	STR_MITEM_INC_ACT_OPT_VOICE_MEMO,
	STR_MITEM_INC_ACT_OPT_SOUND_RECORDER,	
	STR_MITEM_INC_ACT_OPT_LOUDSP,
	STR_MITEM_IAH_OPT_SWAP,
	STR_MITEM_IAH_OPT_CONFER,
	STR_MITEM_IAH_OPT_TRANSFER,
	INC_SCR_RSK_REJECT_STR,
	INC_SCR_RSK_MUTE_STR,
	STR_MITEM_IAMH_ALL_HELD_END,
	STR_MITEM_INC_MHLD_OPT_RTRV,
	STR_MITEM_INC_MHLD_OPT_END,
	STR_MITEM_IMA_OPT_END_ALL_ACT,
	STR_MITEM_IMA_OPT_END_ONE_ACT,
	STR_MITEM_IMA_OPT_HOLD_CONF,
	STR_MITEM_IMAH_OPT_END_ONE_ACT,
	CALL_DEFLECT_SEARCH_LSK,
	STR_MITEM_IMA_OPT_END_ALL,
	STR_CALL_ABORTED,
	STR_CALL_ENDED,
	STR_ACM_MAX_EXCEEDED,
	STR_EMERGENCY_CALL,
	STR_DTMF_CONFIRMATION,

 
STR_CM_REDIAL,
STR_CM_REDIAL_TIMES,
STR_CM_REDIAL_NEXT_ATTEMPT,
STR_CM_REDIAL_SEC,
STR_CM_REDIAL_MIN,
#endif  //INCOMING_STRING_ID_DEF_H


