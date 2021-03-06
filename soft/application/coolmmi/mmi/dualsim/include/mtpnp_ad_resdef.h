/***********************************************
File name : MTPNP_AD_resdef.h
Contents : all mtpnp app resource define
History : Create by : Zhang Nan, Feb 26, 2007
************************************************/
#ifndef _MTPNP_AD_RESDEF_H_
#define _MTPNP_AD_RESDEF_H_
#ifdef __MMI_MULTI_SIM__
/*
COOLSAND platform:
...
RESOURCE_BASE_RANGE(MERCURY,	1000),
...
#define MERCURY_BASE                    ((U16) RESOURCE_BASE_MERCURY)
#define	MERCURY_BASE_MAX                ((U16) RESOURCE_BASE_MERCURY_END)
RESOURCE_BASE_TABLE_ITEM(MERCURY)
...
*/
typedef enum
{
    MTPNP_AD_STRING_BASE = MERCURY_BASE + 1,

    STRING_MTPNP_SETTING,

    STRING_MTPNP_SIM1DIAL,
    STRING_MTPNP_SIM2DIAL,

    STRING_MTPNP_EM_OP_SIDE,
    STRING_MTPNP_MASTER_TEST,
    STRING_MTPNP_SLAVE_TEST,

    /* engineer/factory mode begin */
    STRING_MTPNP_EM,
    STRING_MTPNP_CHK_RSSI,
    STRING_MTPNP_PSN_CALLBACK,
    STRING_MTPNP_PSNCALLBACK_TIP,
    STRING_MTPNP_ASSERT_SLAVE,
    STRING_MTPNP_FM_COMM,
    STRING_MTPNP_FM_MIC,
    STRING_MTPNP_FM_SPEAKER,
    STRING_MTPNP_FM_RECEIVER,
    STRING_MTPNP_FM_HEADSET,
    /* engineer/factory mode end */

    STRING_MTPNP_HELPINFO,
    STRING_MTPNP_REGISTER,
    STRING_MTPNP_REGISTER_CONFIRM,
    STRING_MTPNP_REGISTER_TIP,

    STRING_MTPNP_DM_SETTING,
    STRING_MTPNP_DM_DUALCARD,
    STRING_MTPNP_DM_CARD1,
    STRING_MTPNP_DM_CARD2,
    STRING_MTPNP_DM_CARD1_OPEN,
    STRING_MTPNP_DM_CARD2_OPEN,
    STRING_MTPNP_DM_CARD3_OPEN,
    STRING_MTPNP_DM_CARD4_OPEN,
    STRING_MTPNP_DM_FLIGHT,
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    STRING_MTPNP_DM_QUERY,
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
    STRING_MTPNP_DM_SWITCH,
    STRING_MTPNP_DM_DISABLESWTH,
    STRING_MTPNP_DM_ERROR_MODE,

    STRING_MTPNP_SEL_POWERMODE,

    STRING_MTPNP_PHONE_SETTING,
    STRING_MTPNP_PHB_EXTRA,
    STRING_MTPNP_SIM1_OWNER_NUMBER,
    STRING_MTPNP_OWNER_NUMBER,
    STRING_MTPNP_SIM3_OWNER_NUMBER,
    STRING_MTPNP_SIM4_OWNER_NUMBER,
    STRING_MTPNP_SIM1_SDL_NUMBER,
    STRING_MTPNP_SDL_NUMBER,
    STRING_MTPNP_SIM3_SDL_NUMBER,
    STRING_MTPNP_SIM4_SDL_NUMBER,
    STRING_MTPNP_SIM1_SOS_NUMBER,
    STRING_MTPNP_SOS_NUMBER,
    STRING_MTPNP_SIM3_SOS_NUMBER,
    STRING_MTPNP_SIM4_SOS_NUMBER,
    STRING_MTPNP_SHOW_OWNER_NUMBER,
    STRING_MTPNP_CARD1_SHOW_OWNER_NUMBER,

    STRING_MTPNP_SWITCH_SAME_MODE,
    STRING_MTPNP_SWITCH_DC,
    STRING_MTPNP_SWITCH_CARD1,
    STRING_MTPNP_SWITCH_CARD2,
    STRING_MTPNP_SWITCH_QUERY,
    STRING_MTPNP_SWITCH_FLIGHT,

    STRING_MTPNP_CARD1_CALL_SETTING,
    STRING_MTPNP_CALL_SETTING,
    STRING_MTPNP_CARD3_CALL_SETTING,
    STRING_MTPNP_CARD4_CALL_SETTING,
    STRING_MTPNP_CALL_ID,
    STRING_MTPNP_CLI_SET_NETWORK,
    STRING_MTPNP_CLI_HIDE_ID,
    STRING_MTPNP_CLI_SEND_ID,
    STRING_MTPNP_LINE_SWITCH,
    STRING_MTPNP_LSW_LINE1,
    STRING_MTPNP_LSW_LINE2,
    STRING_MTPNP_LINE1_SET,
    STRING_MTPNP_LINE1_SET_ERR,
    STRING_MTPNP_LINE2_SET,
    STRING_MTPNP_LINE2_SET_ERR,
    STRING_MTPNP_SETTING_LINE_SEL,
    STRING_MTPNP_LINE_SET_TITLE,

    STRING_MTPNP_CARD1_CLOSED,
    STRING_MTPNP_CARD2_CLOSED,
    STRING_MTPNP_CARD3_CLOSED,
    STRING_MTPNP_CARD4_CLOSED,
    STRING_MTPNP_SEARCHING_NW,
    STRING_MTPNP_NOSERVICE,
    STRING_MTPNP_LIMITSERVICE,
    STRING_MTPNP_NETSET_MANUAL_MODE,
    STRING_MTPNP_CARD1ABSENT,
    STRING_MTPNP_CARD2ABSENT,
    STRING_MTPNP_CARD3ABSENT,
    STRING_MTPNP_CARD4ABSENT,

    STRING_MTPNP_CARD1_SIM_BLOCK,
    STRING_MTPNP_CARD2_SIM_BLOCK,
    STRING_MTPNP_CARD3_SIM_BLOCK,
    STRING_MTPNP_CARD4_SIM_BLOCK,
    STRING_MTPNP_ENTER_CARD1PIN,
    STRING_MTPNP_ENTER_CARD2PIN,
    STRING_MTPNP_ENTER_CARD1PIN2,
    STRING_MTPNP_ENTER_CARD2PIN2,
    STRING_MTPNP_CANCEL_CARD1PIN,
    STRING_MTPNP_CANCEL_CARD2PIN,
    STRING_MTPNP_ENTER_CARD1PUK,
    STRING_MTPNP_ENTER_CARD1_NEW_PIN,
    STRING_MTPNP_ENTER_CARD2PUK,
    STRING_MTPNP_ENTER_CARD2_NEW_PIN,
    STRING_MTPNP_ENTER_PIN_AGAIN,
    STRING_MTPNP_CARD1_PIN_DONOT_MATCH,
    STRING_MTPNP_CARD1_PIN2_DONOT_MATCH,
    STRING_MTPNP_CARD2_PIN_DONOT_MATCH,
    STRING_MTPNP_CARD2_PIN2_DONOT_MATCH,
    STRING_MTPNP_CODE_VERIFIED,
    STRING_MTPNP_INCORRECT_CARD1_PUK,
    STRING_MTPNP_INCORRECT_CARD1_PUK2,
    STRING_MTPNP_INCORRECT_CARD2_PUK,
    STRING_MTPNP_INCORRECT_CARD2_PUK2,

    STRING_MTPNP_CARD1_SECURITY_SETTING,
    STRING_MTPNP_SECURITY_SETTING,
    STRING_MTPNP_CARD1_PINLOCK,
    STRING_MTPNP_CARD2_PINLOCK,
    STRING_MTPNP_CARD3_PINLOCK,
    STRING_MTPNP_CARD4_PINLOCK,
    STRING_MTPNP_CHANGE_PASSWORD,
    STRING_MTPNP_CP_PIN1,
    STRING_MTPNP_CP_SIM3_PIN1,
    STRING_MTPNP_CP_SIM4_PIN1,
    STRING_MTPNP_CP_PIN2,
    STRING_MTPNP_CP_SIM3_PIN2,
    STRING_MTPNP_CP_SIM4_PIN2, 
    STRING_MTPNP_CP_SIM1PIN1,
    STRING_MTPNP_CP_SIM1PIN2,
    STRING_MTPNP_SECURITY_CAPTION,
    STRING_MTPNP_CHANGE_PASSWORD_CAPTION,
    STRING_MTPNP_SIM1_PIN_BLOCKED,
    STRING_MTPNP_SIM1_PIN2_BLOCKED,
    STRING_MTPNP_PIN_BLOCKED_PUK,
    STRING_MTPNP_PIN_BLOCKED_PUK2,
    STRING_MTPNP_CARD1_PIN_CHANGE,
    STRING_MTPNP_CARD1_PIN2_CHANGE,
    STRING_MTPNP_CARD2_PIN_CHANGE,
    STRING_MTPNP_CARD2_PIN2_CHANGE,
    STRING_MTPNP_WRONG_CARD1_PIN,
    STRING_MTPNP_WRONG_CARD1_PIN2,
    STRING_MTPNP_WRONG_CARD2_PIN,
    STRING_MTPNP_WRONG_CARD2_PIN2,
    STRING_MTPNP_SETTING_CARD1_SIM_LOCK,
    STRING_MTPNP_SETTING_CARD1_SIM_UNLOCK,
    STRING_MTPNP_SETTING_CARD2_SIM_LOCK,
    STRING_MTPNP_SETTING_CARD2_SIM_UNLOCK,
    STRING_MTPNP_ENABLE_CARD1_PIN,
    STRING_MTPNP_ENABLE_CARD2_PIN,
    STRING_MTPNP_SETTING_CARD2_PUK,
    STRING_MTPNP_SETTING_OLD_CARD1_PIN,
    STRING_MTPNP_SETTING_NEW_CARD1_PIN,
    STRING_MTPNP_SETTING_OLD_CARD1_PIN2,
    STRING_MTPNP_SETTING_NEW_CARD1_PIN2,
    STRING_MTPNP_SETTING_OLD_CARD2_PIN,
    STRING_MTPNP_SETTING_NEW_CARD2_PIN,
    STRING_MTPNP_SETTING_OLD_CARD2_PIN2,
    STRING_MTPNP_SETTING_NEW_CARD2_PIN2,
    STRING_MTPNP_SETTING_PIN2_BLOCK_MSG,
    STRING_MTPNP_SETTING_SIM1_PUK2,
    STRING_MTPNP_SETTING_SIM1_NEW_PIN2,
    STRING_MTPNP_SETTING_ENTER_PUK2,
    STRING_MTPNP_SETTING_ENTER_NEW_PIN2,

    /* plmn begin */
    STRING_MTPNP_CARD1_NETWORK_SETUP,
    STRING_MTPNP_NETWORK_SETUP,
    STRING_MTPNP_CARD3_NETWORK_SETUP,
    STRING_MTPNP_CARD4_NETWORK_SETUP,
    STRING_MTPNP_NETWORK_SETUP_CAPTION,
    STRING_MTPNP_SELECTION_MODE,
    STRING_MTPNP_SELECTION_MODE_CAPTION,
    STRING_MTPNP_PREFERRED_NETWORKS,
    STRING_MTPNP_SELECTION_BAND,
    STRING_MTPNP_GPRS_CONNECTION,
    STRING_MTPNP_NETSET_MANUAL,
    STRING_MTPNP_NETSET_AUTOMATIC,
    STRING_MTPNP_NETSET_NEW_SEARCH,
    STRING_MTPNP_NETSET_SELECT_NETWORK,
    STRING_MTPNP_NETSET_CHOICE,
    STRING_MTPNP_NETSET_OPTIONS,
    STRING_MTPNP_NETSET_PRF_NWK_ADD,
    STRING_MTPNP_NETSET_PRF_NWK_NEW,
    STRING_MTPNP_NETSET_PRF_NWK_EDIT,
    STRING_MTPNP_NETSET_SIM2_INVALID,
    STRING_MTPNP_NETSET_CHANGE,
    STRING_MTPNP_NETSET_PRF_NWK_ADDED_ERR,
    STRING_MTPNP_NETSET_PRF_ADD_SHW_NWK_TITLE,
    STRING_MTPNP_NETSET_PRF_ADD_SHW_NWK_PRIORITY_TITLE,
    STRING_MTPNP_NETSET_PRR_MCC_CAPTION,
    STRING_MTPNP_NETSET_PRR_PR_CAPTION,
    STRING_MTPNP_NETSET_PRR_SV_CAPTION,
    STRING_MTPNP_PLMN_LIST_SORT_BY_ALPHABET,
    STRING_MTPNP_PLMN_LIST_SORT_BY_DEFAULT,
    STRING_MTPNP_NETSET_SEARCHIN_NW,
    STRING_MTPNP_NETSET_REGISTERING_NW,
    STRING_MTPNP_NETSET_NW_SELECT_FAIL,
    STRING_MTPNP_NETSET_NW_LIST_FAIL,
    STRING_MTPNP_NETSET_SELECT_NETWORK_CAPTION,
    /* plmn end */

    /* cell broadcast messages begin */
    STRING_MTPNP_SIM1_CB_MENUENTRY,
    STRING_MTPNP_CB_MENUENTRY,
    STRING_MTPNP_CB_SERVICE,
    STRING_MTPNP_CB_READ_MESSAGE,
    STRING_MTPNP_CB_CHANNELS,
    STRING_MTPNP_CB_LANGUAGE,
    STRING_MTPNP_CB_MESSAGE_BODY,
    STRING_MTPNP_CB_SELECT_CHNL,
    STRING_MTPNP_CB_CHNL_EDITOR,
    STRING_MTPNP_CB_CHNL_TITLE,
    STRING_MTPNP_CB_CHNL_TITLE_FULL_EDIT,
    STRING_MTPNP_CB_CHNL_NUMBER,
    STRING_MTPNP_CB_CHNL_LIST,
    STRING_MTPNP_CB_LANGUAGE_CAPTION,
    STRING_MTPNP_CB_CHANNELS_CAPTION,
    STRING_MTPNP_CB_CHANNEL_ENBL_OPTIONS,
    STRING_MTPNP_CB_CHANNEL_ENBL_OPTIONS_CAPTION,
    STRING_MTPNP_CB_LANGUAGE_UNSPECIFIED,
    STRING_MTPNP_CB_ERROR_MESSAGE,
    STRING_MTPNP_CB_NOT_READY_YET,
    STRING_MTPNP_SMS_CB_CHNL_FULL,
    STRING_MTPNP_CB_CHNL_DUPLICATE_NUMBER_NOT_ALLOWED,
    STRING_MTPNP_CB_CHNL_NUMBER_LEN_EXCEEDED,
    STRING_MTPNP_CB_ALL_CHANNELS_FOR_SELECT,
    STRING_MTPNP_CB_ALL_LANGUAGES_FOR_SELECT,
    STRING_MTPNP_CB_MSG_IND_INFORMATION_CAPTION,
    /* cell broadcast messages end */

    /* voice mail begin */
    STRING_MTPNP_SIM1_VMAIL_MENUENTRY,
    STRING_MTPNP_VMAIL_MENUENTRY,
    STRING_MTPNP_SIM3_VMAIL_MENUENTRY,
    STRING_MTPNP_SIM4_VMAIL_MENUENTRY,
    STRING_MTPNP_VOICE_MAIL_NOT_READY_YET,
    STRING_MTPNP_VOICE_MAIL_OPTION_ID,
    STRING_MTPNP_VM_CONNECT_TO_VOICE_ID,
    /* voice mail end */

    /* message setup begin */
    STRING_MTPNP_SIM1_MESSAGESETUP_MENUENTRY,
    STRING_MTPNP_MESSAGESETUP_MENUENTRY,
    STRING_MTPNP_SIM3_MESSAGESETUP_MENUENTRY,
    STRING_MTPNP_SIM4_MESSAGESETUP_MENUENTRY,
    STRING_MTPNP_SMS_MEMSTATUS_PREFIX_SIM,
    STRING_MTPNP_SMS_MEMSTATUS_PREFIX_PHONE,
    STRING_MTPNP_ME_STORAGE_MENUENTRY,
    STRING_MTPNP_SIM_STORAGE_MENUENTRY,
    STRING_MTPNP_PROFILE_SETTING_MENUENTRY,
    STRING_MTPNP_COMMONSETTING_MENUENTRY,
    STRING_MTPNP_PREFEREDSTORAGE_MENUENTRY,
    STRING_MTPNP_SMSSTATUS_MENUENTRY,
    STRING_MTPNP_SMSSTATUS_TITLE,
    STRING_MTPNP_PROFILE_NAME,
    STRING_MTPNP_PROFILE_SC,
    STRING_MTPNP_PROFILE_VP,
    STRING_MTPNP_PROFILE_MSG_TYPE,
    STRING_MTPNP_NEW_MASTER_MESSAGE_FROM_ID,
    STRING_MTPNP_NEW_SLAVE_MESSAGE_FROM_ID,
    STRING_MTPNP_NEW_SIM3_MESSAGE_FROM_ID,
    STRING_MTPNP_NEW_SIM4_MESSAGE_FROM_ID,
    STRING_MTPNP_MASTER_RECEIVED_SMS,
    STRING_MTPNP_SLAVE_RECEIVED_SMS,
    STRING_MTPNP_SIM3_RECEIVED_SMS,
    STRING_MTPNP_SIM4_RECEIVED_SMS,
    STRING_MTPNP_MASTER_DELIVERY_REPORT_MENUENTRY,
    STRING_MTPNP_SLAVE_DELIVERY_REPORT_MENUENTRY,
    STRING_MTPNP_SIM3_DELIVERY_REPORT_MENUENTRY,
    STRING_MTPNP_SIM4_DELIVERY_REPORT_MENUENTRY,
    /* message setup end */

    /* SMS */
    STRING_MTPNP_SMS_MASTER_DONE,
    STRING_MTPNP_SMS_SLAVE_DONE,
    STRING_MTPNP_SMS_SIM3_DONE,
    STRING_MTPNP_SMS_SIM4_DONE,
    STRING_MTPNP_MASTER_SEND_OPTIONS_CAPTION,
    STRING_MTPNP_SLAVE_SEND_OPTIONS_CAPTION,
    STRING_MTPNP_SIM3_SEND_OPTIONS_CAPTION,
    STRING_MTPNP_SIM4_SEND_OPTIONS_CAPTION,

    STRING_MTPNP_OUTBOX_MASTER_SEND_SMS,
    STRING_MTPNP_OUTBOX_SLAVE_SEND_SMS,
    STRING_MTPNP_OUTBOX_SIM3_SEND_SMS,
    STRING_MTPNP_OUTBOX_SIM4_SEND_SMS,

    STRING_MTPNP_MASTER_SENDING_SMS,
    STRING_MTPNP_SLAVE_SENDING_SMS,
    STRING_MTPNP_SIM3_SENDING_SMS,
    STRING_MTPNP_SIM4_SENDING_SMS,

    STRING_MTPNP_MASTER_MSGBOX_FORWARD,
    STRING_MTPNP_SLAVE_MSGBOX_FORWARD,
    STRING_MTPNP_SMS_COPY_TO_SIM2,
    STRING_MTPNP_SMS_MOVE_TO_SIM2,
    STRING_MTPNP_SMS_FROM_SIM2,

    STRING_MTPNP_MASTER_SMS_MEMORY_EXCEEDED,
    STRING_MTPNP_SLAVE_SMS_MEMORY_EXCEEDED,
    STRING_MTPNP_SIM3_SMS_MEMORY_EXCEEDED,
    STRING_MTPNP_SIM4_SMS_MEMORY_EXCEEDED,
    STRING_MTPNP_MASTER_DELETE_INBOX_MENUENTRY,
    STRING_MTPNP_SLAVE_DELETE_INBOX_MENUENTRY,
    STRING_MTPNP_SIM3_DELETE_INBOX_MENUENTRY,
    STRING_MTPNP_SIM4_DELETE_INBOX_MENUENTRY,
    STRING_MTPNP_MASTER_DELETE_OUTBOX_MENUENTRY,
    STRING_MTPNP_SLAVE_DELETE_OUTBOX_MENUENTRY,
    STRING_MTPNP_SIM3_DELETE_OUTBOX_MENUENTRY,
    STRING_MTPNP_SIM4_DELETE_OUTBOX_MENUENTRY,
    STRING_MTPNP_SAVE_SMS_TO_SIM1,
    STRING_MTPNP_SAVE_SMS_TO_SIM2,
    STRING_MTPNP_SAVE_SMS_TO_SIM3,
    STRING_MTPNP_SAVE_SMS_TO_SIM4,
    STRING_MTPNO_SMS_NOT_USABLE,
    /* SMS */

    /* sms show begin */
    STRING_MTPNP_SMS_MASTER_INBOX,
    STRING_MTPNP_SMS_SLAVE_INBOX,
    STRING_MTPNP_SMS_SIM3_INBOX,
    STRING_MTPNP_SMS_SIM4_INBOX,
    STRING_MTPNP_SMS_MASTER_OUTBOX,
    STRING_MTPNP_SMS_SLAVE_OUTBOX,
    STRING_MTPNP_SMS_SIM3_OUTBOX,
    STRING_MTPNP_SMS_SIM4_OUTBOX,
#ifdef  __MMI_MESSAGES_DRAFT_BOX__   
    STRING_MTPNP_SMS_MASTER_DRAFTBOX,
    STRING_MTPNP_SMS_SLAVE_DRAFTBOX,   
    STRING_MTPNP_SMS_SIM3_DRAFTBOX,
    STRING_MTPNP_SMS_SIM4_DRAFTBOX,    
#endif   
    STRING_MTPNP_SMS_SHOW_STYLE,
    STRING_MTPNP_SMS_SHOW_MIXED,
    STRING_MTPNP_SMS_SHOW_DIVIDED,
    /* sms show end */

	/* sms message waiting begin*/
    STRING_MTPNP_MASTER_VOICEMAIL_IND,
    STRING_MTPNP_SLAVE_VOICEMAIL_IND,
    STRING_MTPNP_SIM3_VOICEMAIL_IND,
    STRING_MTPNP_SIM4_VOICEMAIL_IND,
    STRING_MTPNP_MASTER_EMAIL_IND,
    STRING_MTPNP_SLAVE_EMAIL_IND,
    STRING_MTPNP_SIM3_EMAIL_IND,
    STRING_MTPNP_SIM4_EMAIL_IND,
    STRING_MTPNP_MASTER_FAX_IND,
    STRING_MTPNP_SLAVE_FAX_IND,
    STRING_MTPNP_SIM3_FAX_IND,
    STRING_MTPNP_SIM4_FAX_IND,
    STRING_MTPNP_MASTER_NET_OTHER_IND,
    
   
    
    STRING_MTPNP_SLAVE_NET_OTHER_IND,
    
	STRING_MTPNP_MASTER_VOICEMAIL_NUM_IND,
	STRING_MTPNP_MASTER_FAX_NUM_IND,
    STRING_MTPNP_MASTER_EMAIL_NUM_IND,
    STRING_MTPNP_MASTER_NET_OTHER_NUM_IND,
	STRING_MTPNP_SLAVE_VOICEMAIL_NUM_IND,
	STRING_MTPNP_SLAVE_FAX_NUM_IND,
    STRING_MTPNP_SLAVE_EMAIL_NUM_IND,
    STRING_MTPNP_SLAVE_NET_OTHER_NUM_IND,
    /* sms message waiting end*/

    /* CHAT */
#ifdef __MMI_MESSAGES_CHAT__
    STRING_MTPNP_CHOOSE_MASTER_CHAT,
    STRING_MTPNP_CHOOSE_SLAVE_CHAT,
    STRING_MTPNP_CHO0SE_SIM3_CHAT,
    STRING_MTPNP_CHOOSE_SIM4_CHAT,
    STRING_MTPNP_CHAT_NOT_SUPPORT,
#endif /* __MMI_MESSAGES_CHAT__ */
    /* CHAT */

    /* phonebook */
    STRING_MTPNP_QUERY_DELETEALL_CARD2,
    STRING_MTPNP_SIM1_STORAGE_FULL,
    STRING_MTPNP_SIM2_STORAGE_FULL,
    STRING_MTPNP_PHB_COPYALL_SIM1TOPHONE,
    STRING_MTPNP_PHB_COPYALL_PHONETOSIM1,
    STRING_MTPNP_SIM2PHB_COPYALL_SIM2TOPHONE,
    STRING_MTPNP_SIM2PHB_COPYALL_PHONETOSIM2,
    STRING_MTPNP_SIM2PHB_COPYALL_SIM1TOSIM2,
    STRING_MTPNP_SIM2PHB_COPYALL_SIM2TOSIM1,
    STRING_MTPNP_SIM2PHB_COPY_SIM2TOPHONE,
    STRING_MTPNP_SIM2PHB_COPY_SIM2TOSIM1,
    STRING_MTPNP_SIM2PHB_COPY_PHONETOSIM2,
    STRING_MTPNP_SIM2PHB_COPY_SIM1TOSIM2,
    STRING_MTPNP_SIM2PHB_MOVE_SIM2TOPHONE,
    STRING_MTPNP_SIM2PHB_MOVE_SIM2TOSIM1,
    STRING_MTPNP_SIM2PHB_MOVE_PHONETOSIM2,
    STRING_MTPNP_SIM2PHB_MOVE_SIM1TOSIM2,

    STRING_MTPNP_SIM2PHB_COPY_SIM1TOPHONE,
    STRING_MTPNP_SIM2PHB_MOVE_SIM1TOPHONE,
    STRING_MTPNP_SIM2PHB_COPY_PHONETOSIM1,
    STRING_MTPNP_SIM2PHB_MOVE_PHONETOSIM1,
    STRING_MTPNP_VCARD_SAVE_TO_SIM1,
    STRING_MTPNP_VCARD_SAVE_TO_SIM2,
    
    STRING_MTPNP_SLAVE_FIXED_DIAL,
    STRING_MTPNP_SIM1PHB_ADD_NEW_ENTRY,
    STRING_MTPNP_SIM2PHB_ADD_NEW_ENTRY,
    STRING_MTPNP_SIM1PHB_DELETEALL,
    STRING_MTPNP_SIM2PHB_DELETEALL,
    STRING_MTPNP_NLF_SIM1,
    STRING_MTPNP_NLF_ALL,
    STRING_MTPNP_SIM1_MEMORY_STATUS,
    STRING_MTPNP_SLAVE_MEMORY_STATUS,
    STRING_MTPNP_SIM2PHB_PRESTORAGE,
    STRING_MTPNP_SIM2PHB_NLF_SIM2,

    STRING_MTPNP_PHB_OPTION_IP_DIAL_SIM1,
    STRING_MTPNP_PHB_OPTION_IP_DIAL_SIM2,
    STRING_MTPNP_PHB_STORAGE_SIM2,
    STRING_MTPNP_PHB_COPY_ALL_FROM_SIM1,
    STRING_MTPNP_PHB_COPY_ALL_FROM_SIM2 ,   
    STRING_MTPNP_PHB_COPY_TO_SIM1_DONE,
    STRING_MTPNP_PHB_COPY_TO_SIM2_DONE,
    STRING_MTPNP_PHB_MOVE_TO_SIM1_DONE,
    STRING_MTPNP_PHB_MOVE_TO_SIM2_DONE,
    STRING_MTPNP_PHB_SOSLIST_INSIM1,
    STRING_MTPNP_PHB_SOSLIST_INSIM2,
/* phonebook */

    /*mtpnp call set */
    STRING_MTPNP_CALL_FORWARD,
    STRING_MTPNP_LINE_WAIT,
    STRING_MTPNP_LINE_BARRING,
    /*mtpnp call set */

    /*call history */
    STRING_MTPNP_CARD1_CALL_HISTORY,
    STRING_MTPNP_CALL_HISTORY,
    STRING_MTPNP_CARD3_CALL_HISTORY,
    STRING_MTPNP_CARD4_CALL_HISTORY,
    STRING_MTPNP_MENU8101_RECEIVED_CALLS,
    STRING_MTPNP_MENU8102_DIALED_CALLS,
    STRING_MTPNP_MENU8103_MISSED_CALLS,
    STRING_MTPNP_CHIST_OPTION_SENDSMS,
    STRING_MTPNP_CHIST_OPTION_SENDMMS,
    STRING_MTPNP_RECEIVED_CALL_LIST_OPTIONS,
    STRING_MTPNP_DIALED_CALL_LIST_OPTIONS,
    STRING_MTPNP_MISSED_CALL_LIST_OPTIONS,
    STR_RECEIVED_CAPTION,
    STR_MISSED_CAPTION,
    STR_DIALED_CAPTION,
    STRING_MTPNP_MISSED_CALL_NOTIFY,
    STRING_MTPNP_MISSED_CALL_NOTIFY_MASTER,
    STRING_MTPNP_MISSED_CALL_NOTIFY_SLAVE,
    STRING_MTPNP_MISSED_CALL_NOTIFY_SIM3,
    STRING_MTPNP_MISSED_CALL_NOTIFY_SIM4,
    STRING_MTPNP_MENU_SIM2_SMS_CAPTION,
    STRING_MTPNP_SENT_SMS_COUNT,
    STRING_MTPNP_RECV_SMS_COUNT,
    STRING_MTPNP_SCR_RESET_RCVD_SMS_CONFIRM_TEXT,
    STRING_MTPNP_SMS_COUNTER_LSK,
    STRING_MTPNP_SMS_NO_NUMBER,
    STRING_MTPNP_SMS_STRING,
    STRING_MTPNP_MENU_CALLHISTORY_RESETCALL,
    STRING_MTPNP_MENU8101_SIM1_RECEIVED_CALLS,
    STRING_MTPNP_MENU8102_SIM1_DIALED_CALLS,
    STRING_MTPNP_MENU8103_SIM1_MISSED_CALLS,
    STRING_MTPNP_MENU_SIM1_CALLHISTORY_RESETCALL,
    STRING_MTPNP_MENU_SIM1_CALL_TIME_SETUP,
    STRING_MTPNP_MENU_SIM1_CALL_COST_MAIN,
    STRING_MTPNP_MENU_SIM1_SMS_CAPTION,
    STRING_MTPNP_MENU_SIM1_GPRS_CAPTION,    
    STRING_MTPNP_MENU_RECEIVED_CALLS,
    STRING_MTPNP_MENU_DIALED_CALLS,
    STRING_MTPNP_MENU_MISSED_CALLS,
    STR_MTPNP_GLOBAL_DELETE_ALL,
    STR_MTPNP_SCR_RESETCALLS_CONFIRM_CAPTION,
    STRING_MTPNP_MENU_SIM2_CALL_TIME_SETUP,
    STRING_MTPNP_MENU_QUICK_END,
    STRING_MTPNP_MENU_QUICK_END_SET,
    STRING_MTPNP_MENU_QUICK_END_DURATION,
    STRING_MTPNP_MENU_LAST_CALL_TIME,
    STRING_MTPNP_MENU_CALL_OUT_TIME,
    STRING_MTPNP_MENU_CALL_IN_TIME,
    STRING_MTPNP_MENU_ALL_CALL_TIME,
    STRING_MTPNP_RESET_ALL_CALL_TIME,
    STRING_MTPNP_RESET_ALL_CALL_TIME_CONFIRM,
    STRING_MTPNP_MENU_CALL_COST_PROCESSING,
    STRING_MTPNP_MENU_SIM2_CALL_COST_MAIN,
    STRING_MTPNP_MENU_CALL_COST_LASTCALL,
    STRING_MTPNP_MENU_CALL_COST_ALLCOST,
    STRING_MTPNP_MENU_CALL_COST_PRICEUNIT,
    STRING_MTPNP_MENU_CALL_COST_RESETCOUNTER,
    STRING_MTPNP_MENU_CALL_COST_MAXCOUNT,
    STRING_MTPNP_ALL_CALL_COSTS_ERROR_MSG,
    STRING_MTPNP_CALL_COST_PRICEANDUNIT_VIEW_LSK,
    STRING_MTPNP_MENU_SCR_CALL_COST_PRICEANDUNIT_SET,
    STRING_MTPNP_MENU_CALL_COST_PRICEANDUNIT_SET_PRICE,
    STRING_MTPNP_MENU_CALL_COST_PRICEANDUNIT_SET_UNIT,
    STRING_MTPNP_MAX_COST_SET_CAPTION,
    STRING_MTPNP_MENU_SIM2_GPRS_CAPTION,
    STRING_MTPNP_GPRS_LAST_SENT,
    STRING_MTPNP_GPRS_LAST_RECEIVED,
    STRING_MTPNP_GPRS_ALL_SENT,
    STRING_MTPNP_GPRS_ALL_RECEIVED,
    STRING_MTPNP_GPRS_RESET_COUNTER,
    /*call history */

    STR_USSD_REQ_CAPTION_CARD2,

    SLAVE_STR_ID_CFT_SWAP_TO_SLAVE,
    SLAVE_STR_ID_CFT_SWAP_TO_MASTER,
    STR_TITLE_SCR_USSN_MSG_CARD1,
    STR_TITLE_SCR_USSN_MSG_CARD2,
    STR_USSD_REQ_CAPTION_CARD1,
    STR_TITLE_SCR_USSR_EDIT_MSG_CARD1,
    STR_TITLE_SCR_USSR_EDIT_MSG_CARD2,
    STR_TITLE_SCR_USSD_MSG_CARD1,
    STR_TITLE_SCR_USSD_MSG_CARD2,
    STR_TITLE_SCR_USSR_MSG_CARD1,
    STR_TITLE_SCR_USSR_MSG_CARD2,
    SLAVE_STR_MITEM_INC_OPT_ANSWER_CARD1,
    SLAVE_STR_MITEM_INC_OPT_ANSWER_CARD2,
    SLAVE_STR_MITEM_INC_OPT_REJECT_CARD1,
    SLAVE_STR_MITEM_INC_OPT_REJECT_CARD2,
    SLAVE_STR_MITEM_INC_ACT_OPT_HOLD_ACT_CARD1,
    SLAVE_STR_MITEM_INC_ACT_OPT_HOLD_ACT_CARD2,
    SLAVE_STR_MITEM_INC_ACT_OPT_END_ACT_CARD1,
    SLAVE_STR_MITEM_INC_ACT_OPT_END_ACT_CARD2,
    SLAVE_STR_MITEM_INC_HLD_OPT_RTRV_CARD1,
    SLAVE_STR_MITEM_INC_HLD_OPT_RTRV_CARD2,
    SLAVE_STR_MITEM_IMA_OPT_HOLD_CONF_CARD1,
    SLAVE_STR_MITEM_IMA_OPT_HOLD_CONF_CARD2,
    SLAVE_STR_DG_ENDALL,
    SLAVE_STR_MITEM_IMA_OPT_SPLIT_CARD1,
    SLAVE_STR_MITEM_IMA_OPT_SPLIT_CARD2,
    SLAVE_STR_MITEM_IMA_OPT_END_ONE_ACT_CARD1,
    SLAVE_STR_MITEM_IMA_OPT_END_ONE_ACT_CARD2,
    SLAVE_STR_MITEM_IMA_OPT_END_ALL_ACT_CARD1,
    SLAVE_STR_MITEM_IMA_OPT_END_ALL_ACT_CARD2,
    SLAVE_STR_MITEM_INC_MHLD_OPT_RTRV_CARD1,
    SLAVE_STR_MITEM_INC_MHLD_OPT_RTRV_CARD2,
    SLAVE_STR_MITEM_INC_MHLD_OPT_END_CARD1,
    SLAVE_STR_MITEM_INC_MHLD_OPT_END_CARD2,
    SLAVE_STR_MITEM_IAH_OPT_SWAP_CARD1,
    SLAVE_STR_MITEM_IAH_OPT_SWAP_CARD2,
    SLAVE_STR_MITEM_IAH_OPT_CONFER_CARD1,
    SLAVE_STR_MITEM_IAH_OPT_CONFER_CARD2,
    SLAVE_STR_MITEM_IAH_OPT_END_ACT_CARD1,
    SLAVE_STR_MITEM_IAH_OPT_END_ACT_CARD2,
    SLAVE_STR_MITEM_IAH_OPT_END_HLD_CARD1,
    SLAVE_STR_MITEM_IAH_OPT_END_HLD_CARD2,
    SLAVE_STR_MITEM_IAH_OPT_END_ALL_CARD1,
    SLAVE_STR_MITEM_IAH_OPT_END_ALL_CARD2,
    SLAVE_STR_MITEM2019_CM_ALL_ACTIVE_END_CARD1,
    SLAVE_STR_MITEM2019_CM_ALL_ACTIVE_END_CARD2,
    SLAVE_STR_MITEM_IAMH_ALL_HELD_END_CARD1,
    SLAVE_STR_MITEM_IAMH_ALL_HELD_END_CARD2,
    SLAVE_STR_ID_CFT_ACTIVE_MASTER_CALL,
    SLAVE_STR_ID_CFT_ACTIVE_SLAVE_CALL,
    SLAVE_STR_CC_MO_SELETECT_NET_CARD1,
    SLAVE_STR_CC_MO_SELETECT_NET_CARD2,
    SLAVE_STR_CC_MO_SELETECT_SELECT_NET,
    SLAVE_STR_CC_SP_SELETECT_SELECT_NET,
    SLAVE_STR_CC_CSK_SELECT_NET,
    SLAVE_STR_CC_CSK_SELETECT_CARD1,
    SLAVE_STR_CC_CSK_SELETECT_CARD2,
    SLAVE_STR_CALL_INCOMING_OPT_ACCEPT,
    SLAVE_STR_CALL_INCOMING_OPT_REJECT,
    SLAVE_STR_CALL_INCOMING_OPT_CARD1_DIALBACK,
    SLAVE_STR_CALL_INCOMING_OPT_CARD2_DIALBACK,
    SLAVE_STR_CALL_INCOMING_MIX_OPT_ACCEPT_BOTH,
    SLAVE_STR_CALL_INCOMING_MIX_OPT_REJECT_BOTH,
    SLAVE_STR_CALL_INCOMING_MIX_OPT_ACCEPTCARD1,
    SLAVE_STR_CALL_INCOMING_MIX_OPT_ACCEPTCARD2,
    SLAVE_STR_CALL_INCOMING_OPT_CARD1_IP_DIALBACK,
    SLAVE_STR_CALL_INCOMING_OPT_CARD2_IP_DIALBACK,
    SLAVE_STR_ID_CFT_OPT,
    STRING_MASTER_IP_ACTIVATE,
    STRING_SLAVE_IP_ACTIVATE,
    STRING_SIM3_IP_ACTIVATE,
    STRING_SIM4_IP_ACTIVATE,
    STRING_MASTER_IP_DEACTIVATE,
    STRING_SLAVE_IP_DEACTIVATE,
    STRING_SIM3_IP_DEACTIVATE,
    STRING_SIM4_IP_DEACTIVATE,
    SLAVE_STR_CALL_FORBIDDEN,
    /*ucm */
    STRING_MTPNP_ID_UCM_VOICE_ACTIVE,
    STRING_MTPNP_ID_UCM_VOICE_HOLD,
    STRING_MTPNP_ID_UCM_DIAL_SIM2,
    /*ucm */

    STRING_MTPNP_CALL_SIM1,
    STRING_MTPNP_CALL_SIM2,
    STRING_MTPNP_CALL_SIM3,
    STRING_MTPNP_CALL_SIM4,
    STRING_MTPNP_INCOMING_SIM1,
    STRING_MTPNP_INCOMING_SIM2,
    STRING_MTPNP_INCOMING_SIM3,
    STRING_MTPNP_INCOMING_SIM4,
    STRING_MTPNP_SIM1,
    STRING_MTPNP_SIM2,
    STRING_MTPNP_SIM3,
    STRING_MTPNP_SIM4,
    STRING_MTPNP_SRC_SELECT,
    STRING_MTPNP_DST_SELECT,

    /* SIM-ME-Lock */
    STRING_MTPNP_SIM1_ENTER_NP_MSG,
    STRING_MTPNP_SIM1_ENTER_NSP_MSG,
    STRING_MTPNP_SIM1_ENTER_SP_MSG,
    STRING_MTPNP_SIM1_ENTER_CP_MSG,
    STRING_MTPNP_SIM1_ENTER_SIMP_MSG,
    STRING_MTPNP_SIM1_ENTER_NSSP_MSG,
    STRING_MTPNP_SIM1_ENTER_SIMC_MSG,
    STRING_MTPNP_SIM2_ENTER_NP_MSG,
    STRING_MTPNP_SIM2_ENTER_NSP_MSG,
    STRING_MTPNP_SIM2_ENTER_SP_MSG,
    STRING_MTPNP_SIM2_ENTER_CP_MSG,
    STRING_MTPNP_SIM2_ENTER_SIMP_MSG,
    STRING_MTPNP_SIM2_ENTER_NSSP_MSG,
    STRING_MTPNP_SIM2_ENTER_SIMC_MSG,
    STRING_MTPNP_SIM1_WRONG_NP_MSG,
    STRING_MTPNP_SIM1_WRONG_NSP_MSG,
    STRING_MTPNP_SIM1_WRONG_SP_MSG,
    STRING_MTPNP_SIM1_WRONG_CP_MSG,
    STRING_MTPNP_SIM1_WRONG_SIMP_MSG,
    STRING_MTPNP_SIM1_WRONG_NSSP_MSG,
    STRING_MTPNP_SIM1_WRONG_SIMC_MSG,
    STRING_MTPNP_SIM2_WRONG_NP_MSG,
    STRING_MTPNP_SIM2_WRONG_NSP_MSG,
    STRING_MTPNP_SIM2_WRONG_SP_MSG,
    STRING_MTPNP_SIM2_WRONG_CP_MSG,
    STRING_MTPNP_SIM2_WRONG_SIMP_MSG,
    STRING_MTPNP_SIM2_WRONG_NSSP_MSG,
    STRING_MTPNP_SIM2_WRONG_SIMC_MSG,

    STRING_MTPNP_SIM1_AUTO_LOCKED,
    STRING_MTPNP_SIM2_AUTO_LOCKED,
    STRING_MTPNP_SIM1_SIM2_AUTO_LOCKED,
    STRING_MTPNP_SIM1_SIM2_FAIL_LOCKED,
    STRING_MTPNP_SIM1_NOT_AVAILABLE,
    STRING_MTPNP_SIM2_NOT_AVAILABLE,
    STRING_MTPNP_SIM3_NOT_AVAILABLE,
    STRING_MTPNP_SIM4_NOT_AVAILABLE,
    STRING_MTPNP_SIM1_NOT_INSERT,
    STRING_MTPNP_SIM2_NOT_INSERT,
    STRING_MTPNP_SIM3_NOT_INSERT,
    STRING_MTPNP_SIM4_NOT_INSERT,
    
	STR_ID_UCM_SIM1_VOICE_CALL,
	STR_ID_UCM_SIM2_VOICE_CALL,
	STR_ID_UCM_SIM3_VOICE_CALL,
	STR_ID_UCM_SIM4_VOICE_CALL,
	STR_ID_UCM_SIM1_VOICE_ACTIVE,
	STR_ID_UCM_SIM1_VOICE_HOLD,
	STR_ID_UCM_VOICE_CALL,
	STR_ID_UCM_NOT_ALLOW_TO_DIAL,

//wap
    STR_ID_WAP_SIMTYPE_ALWAYS_ASK,
    STR_ID_MULTI_SIM_CARD_MENU,
    MTPNP_AD_STRING_MAX
} E_MTPNP_AD_STRING_ENUM;

typedef enum
{
    MTPNP_AD_IMAGE_BASE = MERCURY_BASE + 1,

    IMG_SI_MASTER_SIGNAL_STRENGTH_L1,
    IMG_SI_SLAVE_SIGNAL_STRENGTH_L1,
    IMG_SI_CARD3_SIGNAL_STRENGTH_L1,
    IMG_SI_CARD4_SIGNAL_STRENGTH_L1,

    IMG_SI_MASTER_SIGNAL_STRENGTH_L2,
    IMG_SI_SLAVE_SIGNAL_STRENGTH_L2,
    IMG_SI_CARD3_SIGNAL_STRENGTH_L2,
    IMG_SI_CARD4_SIGNAL_STRENGTH_L2,
    
    IMG_SI_MASTER_SIGNAL_STRENGTH,
    IMG_SI_SLAVE_SIGNAL_STRENGTH,
    IMG_SI_CARD3_SIGNAL_STRENGTH,
    IMG_SI_CARD4_SIGNAL_STRENGTH,
	
    IMG_SI_MASTER_SIGNAL_CLOSED,
    IMG_SI_SLAVE_SIGNAL_CLOSED,
    IMG_SI_CARD3_SIGNAL_CLOSED,
    IMG_SI_CARD4_SIGNAL_CLOSED,

    IMG_SI_MASTER_NETWORK_CIPHER_GSM,
    IMG_SI_SLAVE_NETWORK_CIPHER_GSM,

    IMG_SI_SLAVE_ROAMING_INDICATOR,
    IMG_SI_SIM3_ROAMING_INDICATOR,
    IMG_SI_SIM4_ROAMING_INDICATOR,
    IMG_SI_MASTER_SMS_INDICATOR,
    IMG_SI_SLAVE_SMS_INDICATOR,
    IMG_SI_SIM3_SMS_INDICATOR,
    IMG_SI_SIM4_SMS_INDICATOR,
    IMG_SLAVE_CALL_FORWARD,
    IMG_SLAVE_CALL_FORWARD_L1,
    IMG_SLAVE_CALL_FORWARD_L2,

    IMG_SI_MMS_UNREAD_INDICATOR_SIM1,
    IMG_SI_MMS_UNREAD_INDICATOR_SIM2,
    IMG_SI_MMS_BUSY_INDICATOR_SIM1,
    IMG_SI_MMS_BUSY_INDICATOR_SIM2,
        
    IMG_SI_EDGE_SIM1,
    IMG_SI_GPRS_SERVICE_SIM1,
    IMG_SI_GPRS_SERVICE_SIM2,
    IMG_SI_GPRS_SERVICE_SIM3,
    IMG_SI_GPRS_SERVICE_SIM4,
    
    IMG_SI_EDGEC_SIM1,
    
    IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM1,
    IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM2,
    IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM3,
    IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM4,

    IMG_SI_EDGE_SIM2,
    IMG_SI_EDGEC_SIM2,
    
    IMG_SI_HZONE_SLAVE,
        
    MAIN_MENU_TITLE_DM_SETTINGS_ICON,
    IMG_MTPNP_SETTING,
    IMG_DM_SWITCH_PROGRESS,
    IMG_SI_CARD2_PHONESETTING,
    IMG_SI_SLAVE_CALLSETTING,
    IMG_SI_SLAVE_NETWORKSETTING,
    IMG_SI_SLAVE_SECURITYSETTING,

    IMG_SLAVE_LSW_LINE1,
    IMG_SLAVE_LSW_LINE2,
    IMG_SLAVE_LINE_SET_TITLE,

    IMG_MASTER_MESSAGE_READ,
    IMG_MASTER_MESSAGE_UNREAD,
    IMG_MASTER_MESSAGE_SENT,
    IMG_MASTER_MESSAGE_UNSENT,
    IMG_MASTER_MESSAGE_SS_NCOMP,
    IMG_SLAVE_MESSAGE_READ,
    IMG_SLAVE_MESSAGE_UNREAD,
    IMG_SLAVE_MESSAGE_SENT,
    IMG_SLAVE_MESSAGE_UNSENT,
    IMG_SLAVE_MESSAGE_SS_NCOMP,
    IMG_BOTH_INCOMING,
    SLAVE_IMG_CFT_SWAP_TO_MASTER,
    SLAVE_IMG_CFT_SWAP_TO_SLAVE,

    /*call history */
    IMG_MTPNP_CARD1_SMS_COUNTER_MENU,
    IMG_MTPNP_CARD2_SMS_COUNTER_MENU,
    IMG_MTPNP_SCR_RESETCALLS,
    IMG_MTPNP_CARD1_MENU_RECEIVED_CALLS,
    IMG_MTPNP_CARD2_MENU_RECEIVED_CALLS,
    IMG_MTPNP_CARD3_MENU_RECEIVED_CALLS,
    IMG_MTPNP_CARD4_MENU_RECEIVED_CALLS,
    IMG_MTPNP_CARD1_MENU_DIALED_CALLS,
    IMG_MTPNP_CARD2_MENU_DIALED_CALLS,
    IMG_MTPNP_CARD3_MENU_DIALED_CALLS,
    IMG_MTPNP_CARD4_MENU_DIALED_CALLS,
    IMG_MTPNP_CARD1_MENU_MISSED_CALLS,
    IMG_MTPNP_CARD2_MENU_MISSED_CALLS,
    IMG_MTPNP_CARD3_MENU_MISSED_CALLS,
    IMG_MTPNP_CARD4_MENU_MISSED_CALLS,
    IMG_MTPNP_CARD1_MENU_REJECTED_CALLS,
    IMG_MTPNP_CARD2_MENU_REJECTED_CALLS,
    IMG_MTPNP_CARD3_MENU_REJECTED_CALLS,
    IMG_MTPNP_CARD4_MENU_REJECTED_CALLS,
    IMG_MTPNP_SCR_RESETCALLS_CONFIRM,
    IMG_MTPNP_QUICK_END_MAIN_MENU,
    IMG_MTPNP_MENU_CALL_TIMES,
    IMG_MTPNP_SCR_CALL_COST_MAIN_CAP,
    IMG_MTPNP_SCR_CALL_COST_PRICEANDUNIT_SET_CAPTION,
    IMG_MTPNP_SCR_MAX_COST_GET_CAPTION,
    IMG_MTPNP_CALL_HISTORY,
    IMG_MTPNP_MENU8101_RECEIVED_CALLS,
    IMG_MTPNP_MENU8102_DIALED_CALLS,
    IMG_MTPNP_MENU8103_MISSED_CALLS,
    IMG_RECEIVED_CAPTION,
    IMG_MISSED_CAPTION,
    IMG_DIALED_CAPTION,
    IMG_MTPNP_SCR_CALL_COST_PROCESS,
    IMG_MTPNP_MISSED_CALL_NOTIFY,
    IMG_MTPNP_MISSED_CALL_NOTIFY_MASTER,
    IMG_MTPNP_MISSED_CALL_NOTIFY_SLAVE,
    IMG_SI_CARD1MISSED_CALL_INDICATOR,
    IMG_SI_CARD2MISSED_CALL_INDICATOR,
    IMG_SI_CARD3MISSED_CALL_INDICATOR,
    IMG_SI_CARD4MISSED_CALL_INDICATOR,
    IMG_SI_CARD1REJECTED_CALL_INDICATOR,
    IMG_SI_CARD2REJECTED_CALL_INDICATOR,
    IMG_SI_CARD3REJECTED_CALL_INDICATOR,
    IMG_SI_CARD4REJECTED_CALL_INDICATOR,



    /*call history */

     /*ADN*/ 
    IMG_ID_CARD1_PHB_STORAGE_SIM,
    IMG_ID_CARD2_PHB_STORAGE_SIM,
    IMG_ID_MTPNP_PHB_DELALL_FROM_SIM1,
    IMG_ID_MTPNP_PHB_DELALL_FROM_SIM2,
    IMG_ID_MTPNP_PHB_COPYALL_FROM_SIM1TOPHONE,
    IMG_ID_MTPNP_PHB_COPYALL_FROM_PHONETOSIM1,    
    IMG_ID_MTPNP_PHB_COPYALL_FROM_PHONETOSIM2,
    IMG_ID_MTPNP_PHB_COPYALL_FROM_SIM2TOPHONE,
    IMG_ID_MTPNP_PHB_COPYALL_FROM_SIM1TOSIM2,
    IMG_ID_MTPNP_PHB_COPYALL_FROM_SIM2TOSIM1,
     /*ADN*/
    /*IP dial */
    IMG_MTPNP_VICON_1, //0x01
    IMG_MTPNP_VICON_2, //0x02
    IMG_MTPNP_VICON_12,//0x03
    IMG_MTPNP_VICON_3,//0x04
    IMG_MTPNP_VICON_13, //0x05
    IMG_MTPNP_VICON_23,//0x06
    IMG_MTPNP_VICON_123,//0x07
    IMG_MTPNP_VICON_4, //0x08
    IMG_MTPNP_VICON_14,//0x09
    IMG_MTPNP_VICON_24, //0x0A
    IMG_MTPNP_VICON_124,//0x0B
    IMG_MTPNP_VICON_34,//0x0C
    IMG_MTPNP_VICON_134,//0x0D
    IMG_MTPNP_VICON_234,//0x0E
    IMG_MTPNP_VICON_1234,//0x0F
    /*IP dial */

    /* engineer/factory mode begin */
    IMG_MTPNP_FM_COMM,
    IMG_MTPNP_FM_MIC,
    IMG_MTPNP_FM_SPEAKER,
    IMG_MTPNP_FM_RECEIVER,
    IMG_MTPNP_FM_HEADSET,
    /* engineer/factory mode end */

    
    IMG_SI_UNREAD_VOICE_L1_MASTER,
    IMG_SI_UNREAD_VOICE_L2_MASTER,
    IMG_SI_UNREAD_VOICE_L1L2_MASTER,
    IMG_SI_UNREAD_FAX_L1_MASTER,
    IMG_SI_UNREAD_FAX_L2_MASTER,
    IMG_SI_UNREAD_FAX_L1L2_MASTER,
    IMG_SI_UNREAD_EMAIL_L1_MASTER,
    IMG_SI_UNREAD_EMAIL_L2_MASTER,
    IMG_SI_UNREAD_EMAIL_L1L2_MASTER,
    IMG_SI_UNREAD_NET_L1_MASTER,
    IMG_SI_UNREAD_NET_L2_MASTER,
    IMG_SI_UNREAD_NET_L1L2_MASTER,
    
    IMG_SI_UNREAD_VOICE_L1_SLAVE,
    IMG_SI_UNREAD_VOICE_L2_SLAVE,
    IMG_SI_UNREAD_VOICE_L1L2_SLAVE,
    IMG_SI_UNREAD_FAX_L1_SLAVE,
    IMG_SI_UNREAD_FAX_L2_SLAVE,
    IMG_SI_UNREAD_FAX_L1L2_SLAVE,
    IMG_SI_UNREAD_EMAIL_L1_SLAVE,
    IMG_SI_UNREAD_EMAIL_L2_SLAVE,
    IMG_SI_UNREAD_EMAIL_L1L2_SLAVE,
    IMG_SI_UNREAD_NET_L1_SLAVE,
    IMG_SI_UNREAD_NET_L2_SLAVE,
    IMG_SI_UNREAD_NET_L1L2_SLAVE,

    MTPNP_AD_IMAGE_MAX
} E_MTPNP_AD_IMAGE_ENUM;

typedef enum
{
    MTPNP_AD_SCREEN_BASE = MERCURY_BASE + 1,

    /* engineer mode begin */
    SCR_EM_DUALMODE,
    SCR_EM_OP_SET_SIDE_MENU,
    SCR_EM_CHK_RSSI,
    SCR_CALLBACKPSNPROG,
    /* engineer mode end */

    SCR_DMSETUP,

    SCR_DMHELPINFO,
    SCR_REGISTERPROG,

    SCR_DM_SWITCH_PROGRESS,

    SCR_MTPNP_DM_CALL_SETTING,
    SCR_SLAVECALLSETTING,
    SCR_CARD2_CALLER_ID_MAIN,
    SCR_ID_UCM_GENERAL_CALL_SETTING,

    SCR_DM_QUERY,

    SCR_MTPNP_DM_SHOW_OWNER_NUMBER,
    SCR_CARD2_PHONE_SETTING,
    SCR_CARD2_PHB_EXTRA,
    SCR_CARD2_OWNER_NUMBERS,
    SCR_CARD2_OWNER_NUMBER_OPTIONS,
    SCR_CARD2_OWNER_NUMBER_EDIT,
    SCR_CARD2_PHB_COPY,
    SCR_CARD2_PHB_MOVE,

    /* adn begin */
    SCR_SLAVE_INLINE_EDIT,
    /* adn end */

    /* fdn begin */
    SCR_CARD2_SECSET_FIX_DIAL,
    SCR_CARD2_SECSET_FDN_LIST,
    SCR_CARD2_SECSET_FDN_DETAILS,
    SCR_CARD2_SECSET_FDN_OPTION,
    /* fdn end */

    /* sdn and sos begin */
    SCR_MTPNP_SDN_LIST,
    SCR_MTPNP_SOS_LIST,
    /* sdn and sos end */
    /* sms begin */
    SCR_DUALMODE_MSGBOX_FORWARD,
    /* sms end */

    /* chat begin */
    SCR_CHOOSE_CHAT,
    /* chat end */

    /* message setup begin */
    SCR_MTPNP_DM_MSG_SETTINGS,
    SCR_MTPNP_MSG_SETTINGS,
    SCR_MTPNP_MSG_PROFILE_LIST,
    SCR_MTPNP_MSG_PROFILE_EDIT,
    SCR_MTPNP_MSG_COMMON_SETTINGS,
    SCR_MTPNP_MSG_MEMORY_STATUS,
    SCR_MTPNP_MSG_PREFERRED_STORAGE,
    SCR_MTPNP_MSG_BEARER_SETTINGS,
    /* message setup end */

    /* sms show begin */
    SCR_MTPNP_DM_MSG_INBOX,
    SCR_MTPNP_DM_MSG_OUTBOX,
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    SCR_MTPNP_DM_MSG_DRAFTBOX,
#endif    
    SCR_MTPNP_SMS_SHOW_STYLE,
    SCR_MTPNP_SMS_SELECT_OPTION,
    SCR_MTPNP_SMS_SAVE_SELECT_OPTION,
    /* sms show end */

    /* calllog begin */
    SCR_MTPNP_DM_CALLHIS_MAIN_MENU,
    SCR_MTPNP_CALLHIS_MAIN_MENU,
    SCR_MTPNP_DIALED_CALLHIS_LIST,
    SCR_MTPNP_RECVD_CALLHIS_LIST,
    SCR_MTPNP_MISSED_CALLHIS_LIST,
    SCR_MTPNP_MIXED_CALLHIS_LIST,
    SCR_MTPNP_DIALED_CALLHIS_INFO,
    SCR_MTPNP_RECVD_CALLHIS_INFO,
    SCR_MTPNP_MISSED_CALLHIS_INFO,
    SCR_MTPNP_DIALED_CALLHIS_OPTION,
    SCR_MTPNP_RECVD_CALLHIS_OPTION,
    SCR_MTPNP_MISSED_CALLHIS_OPTION,
    SCR_MTPNP_CALLHISTORY_RESETCALL,
    SCR_MTPNP_CALLTIME_SETUP_MAIN,
    SCR_MTPNP_SMS_COUNTER,
    SCR_MTPNP_CALL_COST_MAIN,
    SCR_MTPNP_CH_OP_WAITING,
    SCR_MTPNP_COST_SET,
    SCR_MTPNP_CALL_COST_PRICEANDUNIT_SET,
    SCR_MTPNP_CALL_HISTORY_NOTIFY,
    SCR_ID_CHIST_DUAL_CARD_MIXED_CALLLOG,
    SCR_MTPNP_GPRS_COUNTER,
    /* calllog end */

    /* plmn begin */
    SCR_MTPNP_DM_NETSET_MAIN,
    SCR_MTPNP_NETSET_MAIN,
    SCR_MTPNP_NETSET_SELECTION_MODE,
    SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST,
    SCR_MTPNP_NETSET_SHOW_PREF_NWK_OPTIONS,
    SCR_MTPNP_NETSET_ADD_NEW_NETWORK_PLMN_LIST,
    SCR_MTPNP_ADD_FROM_LIST_OPTIONS,
    SCR_MTPNP_NETSET_ADD_NEW_NETWORK_PRIORITY,
    SCR_MTPNP_NETSET_EDIT_NETWORK,
    SCR_MTPNP_NETSET_NEW_NETWORK,
    SCR_MTPNP_NETSET_MANUAL_SEARCH_PROGRESS,
    SCR_MTPNP_NETSET_MANUAL_REG_PROGRESS,
    SCR_MTPNP_NETSET_AUTO_SEARCH_PROGRESS,
    SCR_MTPNP_NETSET_SHOW_PLMN_LIST,
    SCR_MTPNP_NETSET_BAND_SELECTION,
    SCR_MTPNP_NETSET_BAND_SELECTION_PROGRESS,
    /* plmn end */

    /* cell broadcast messages begin */
    SCR_MTPNP_DM_MSG_CB_MAIN_MENU,
    SCR_MTPNP_MSG_CB_MAIN_MENU,
    SCR_MTPNP_MSG_CB_LANGUAGE,
    SCR_MTPNP_MSG_CB_CHANNEL_LIST,
    SCR_MTPNP_MSG_CB_CHANNEL_SETTINGS,
    SCR_MTPNP_MSG_CB_MESSAGE_LIST,
    SCR_MTPNP_MSG_CB_MESSAGE,
    SCR_MTPNP_MSG_CB_MESSAGE_IDLE,
    SCR_MTPNP_MSG_CB_MESSAGE_IND,
    SCR_MTPNP_MSG_CB_CHANNEL_EDIT,
    /* cell broadcast messages end */

    /* voice mail begin */
    SCR_MTPNP_DM_MSG_VOICE_MAIL,
    SCR_MTPNP_MSG_VOICE_MAIL_LIST,
    SCR_MTPNP_MSG_VOICE_MAIL_OPTION,
    SCR_MTPNP_MSG_VOICE_MAIL_EDIT,
    /* voice mail end */

    SCR_STARTUPMODESET,

    /* security setting begin */
    SCR_MTPNP_DM_SECSET,
    SCR_ENTERSLAVEPIN,
    SCR_CARD2_SECSETMAIN,
    SCR_CARD2_SECSET_CHANGE_PASSWORD,
    SCR_CARD2_SECSET_CHANGEPW_OLD_PWD,
    SCR_CARD2_SECSET_CHANGEPW_NEW_PWD,
    SCR_CARD2_SECSET_CHANGEPW_CFM_PWD,
    SCR_CARD2_SECSET_SIM_LOCK_PIN1,
    SCR_CARD2_SECSET_PUK1,
    SCR_CARD2_SECSET_PUK_NEW_PIN1,
    SCR_CARD2_SECSET_PUK_CONFIRM_PIN1,
    SCR_CARD2_SECSET_PIN2,
    SCR_CARD2_SECSET_PUK2,
    SCR_CARD2_SECSET_PUK2_NEW_PIN2,
    SCR_CARD2_SECSET_PUK2_CONFIRM_PIN2,
    SCR_CARD2_PIN_BLOCK_PUK,
    SCR_CARD2_ENTER_PUK,
    SCR_CARD2_ENTER_NEW_PIN,
    SCR_CARD2_ENTER_CONFIRM_PIN,
    SCR_CARD2_CODE_VERIFY,
    /* security setting end */

    SLAVE_DTMF_SCR_DISPLAY_ID,
    SCR_CARD2_CM_REQUESTINGUSSD,
    SCR_CARD2_USSN_MSG,
    SCR_CARD2_USSR_EDIT,
    SCR_MTPNP_SELECT_CARD,
    SLAVE_SCR_CM_ACTIVECALLSCREEN,
    SLAVE_CM_INCOMING_OPT,
    SLAVE_SCR1004_CM_DISPENDCALLDURATION,
    SLAVE_SCR1003_CM_ACTIVECALLOPTIONS,
    SLAVE_SCR_CC_MO_SELECT_NET,
    SLAVE_SCR_CC_CSK_SELECT_NET,
    SLAVE_SCR1009_CM_CALLLISTSCREEN,

    /* personalization */
    SCR_MTPNP_ENTER_NP,
    SCR_MTPNP_ENTER_NSP,
    SCR_MTPNP_ENTER_SP,
    SCR_MTPNP_ENTER_CP,
    SCR_MTPNP_ENTER_SIMP,
    SCR_MTPNP_ENTER_NSSP,
    SCR_MTPNP_ENTER_SIMC,

    SCR_MTPNP_SELECT_SIM_MENU,
    
#ifdef JATAAYU_SUPPORT
 //wap
    SCR_ID_MTPNP_WAP_SELECT_SIM,   
#endif

    MTPNP_AD_SCREEN_MAX
} E_MTPNP_AD_SCREEN_ENUM;

#endif
#endif /* _MTPNP_AD_RESDEF_H_ */
