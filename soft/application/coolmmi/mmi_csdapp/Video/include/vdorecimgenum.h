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
 *	  VdoRecImgEnum.h
 *
 * Project:
 * --------
 
 *
 * Description:
 * ------------
 *   Video Recorder Image ID enum.
 *
 * Author:
 * -------
 *
 *==============================================================================
 * 				HISTORY
 
 *------------------------------------------------------------------------------
 * 
 *------------------------------------------------------------------------------
 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VDORECIMGENU_H
#define _MMI_VDORECIMGENU_H

#define VDOREC_IMG_EV_BASE						(VDOREC_BASE+200)
#define VDOREC_IMG_ZOOM_BASE					(VDOREC_BASE+220)		/* reserve 20 for this */
#define VDOREC_IMG_NIGHT_BASE					(VDOREC_BASE+240)
#define VDOREC_IMG_LED_HIGHLIGHT_BASE		(VDOREC_BASE+250)	
#define VDOREC_IMG_RECORD_AUD_BASE			(VDOREC_BASE+260)
#define VDOREC_IMG_SIZE_LIMIT_BASE			(VDOREC_BASE+270)
#define VDOREC_IMG_TIME_LIMIT_BASE			(VDOREC_BASE+280)

#define VDOREC_IMG_BRIGHTNESS_BASE				(VDOREC_BASE + 290)
#define VDOREC_IMG_CONTRAST_BASE 					(VDOREC_BASE + 300)

typedef enum {
	IMG_ID_VDOREC_APP_ICON = VDOREC_BASE+1,
	IMG_ID_VDOREC_SUBLCD_ICON,  //40502
		
	/****** menu *******/
	IMG_ID_VDOREC_TO_VDOPLY,  //40503
	IMG_ID_VDOREC_CAMCODER_SETTING,  //40504
	IMG_ID_VDOREC_VIDEO_SETTING,  //40505
	IMG_ID_VDOREC_EFFECT_SETTING,   //40506
	IMG_ID_VDOREC_SELF_RECORD,	//40507
	IMG_ID_VDOREC_STORAGE,  //40508
	IMG_ID_VDOREC_RESTORE_DEFAULT,	 //40509

	/* camecoder setting */
	IMG_ID_VDOREC_WB,  //40510
	IMG_ID_VDOREC_LED_HIGHLIGHT,  //40511
	IMG_ID_VDOREC_EV,  //40512
	IMG_ID_VDOREC_NIGHT,  //40513
	IMG_ID_VDOREC_BANDING, //40514

	/* video setting */
	IMG_ID_VDOREC_VIDEO_SIZE,  //40515
	IMG_ID_VDOREC_VIDEO_QTY,  //40516
	IMG_ID_VDOREC_SIZE_LIMIT, //40517
	IMG_ID_VDOREC_TIME_LIMIT, //40518
	IMG_ID_VDOREC_RECORD_AUD,  //40519
	IMG_ID_VDOREC_VIDEO_FORMAT,  //40520


	/********** OSD **********/
	IMG_ID_VDOREC_OSD_BG,    //40521
	IMG_ID_VDOREC_OSD_BUTTOM_BAR_BG,  //40522

	/* timer */
	IMG_ID_VDOREC_OSD_TIMER_0,   //40523
	IMG_ID_VDOREC_OSD_TIMER_1,   //40524
	IMG_ID_VDOREC_OSD_TIMER_2,   //40525
	IMG_ID_VDOREC_OSD_TIMER_3,   //40526
	IMG_ID_VDOREC_OSD_TIMER_4,   //40527
	IMG_ID_VDOREC_OSD_TIMER_5,  //40528
	IMG_ID_VDOREC_OSD_TIMER_6,   //40529
	IMG_ID_VDOREC_OSD_TIMER_7,   //40530
	IMG_ID_VDOREC_OSD_TIMER_8,   //40531
	IMG_ID_VDOREC_OSD_TIMER_9,    //40532
	IMG_ID_VDOREC_OSD_TIMER_COL,	//40533

	/* state */
	IMG_ID_VDOREC_OSD_STATE_REC,  //40534
	IMG_ID_VDOREC_OSD_STATE_PAUSE,	  //40535
	IMG_ID_VDOREC_OSD_STATE_PREVIEW,   //40536

	/********** Touch Screen OSD **********/
	IMG_ID_VDOREC_TOUCH_OSD_EV_INC,  //40537
	IMG_ID_VDOREC_TOUCH_OSD_EV_INC_SEL,  //40538
	IMG_ID_VDOREC_TOUCH_OSD_EV_INC_DIS,  //40539
	IMG_ID_VDOREC_TOUCH_OSD_EV_DEC,  //40540
	IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_SEL,	//40541  
	IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_DIS,	//40542	
	IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC,  //40543
	IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_SEL, //40544
	IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_DIS,	 //40545
	IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC,  //40546
	IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_SEL,  //40547
	IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_DIS,  //40548
	IMG_ID_VDOREC_TOUCH_OSD_REC,    //40549
	IMG_ID_VDOREC_TOUCH_OSD_REC_SEL, //40550
	IMG_ID_VDOREC_TOUCH_OSD_PAUSE,  //40551
	IMG_ID_VDOREC_TOUCH_OSD_PAUSE_SEL,	 //40552
	IMG_ID_VDOREC_TOUCH_OSD_STOP,   //40553
	IMG_ID_VDOREC_TOUCH_OSD_STOP_SEL,	 //40554

	/* softkey image */
	IMG_ID_VDOREC_LSK_OPTION,  //40555
	IMG_ID_VDOREC_LSK_OPTION_SEL,	 //40556
	IMG_ID_VDOREC_LSK_PAUSE,   //40557
	IMG_ID_VDOREC_LSK_PAUSE_SEL,		//40558
	IMG_ID_VDOREC_LSK_RESUME,   //40559
	IMG_ID_VDOREC_LSK_RESUME_SEL,	  //40560	
	IMG_ID_VDOREC_RSK_BACK,  //40561
	IMG_ID_VDOREC_RSK_BACK_SEL,	 //40562
	IMG_ID_VDOREC_RSK_STOP,   //40563
	IMG_ID_VDOREC_RSK_STOP_SEL,	  //40564
	IMG_ID_VDOREC_RSK_RECORD,		/* for 23 key */  //40565
	IMG_ID_VDOREC_RSK_RECORD_SEL,	 //40566

	//guoj++ 
	IMG_ID_VDOREC_OSD_TIMER_BG,  //40567
	IMG_ID_VDOREC_OSD_STATUS_PREVIEW,  //40568
	IMG_ID_VDOREC_OSD_STATUS_RECORD,  //40569

	//zhangl++ 
	IMG_ID_VDOREC_BT,  //40570
	IMG_ID_VDOREC_CT,  //40571



	IMG_ID_VDOREC_TOTAL_COUNT


	
} vdorec_img_id_enum;


/***************** EV *******************/
typedef enum {

	IMG_ID_VDOREC_OSD_EV_START = VDOREC_IMG_EV_BASE,
#ifdef __VDOREC_FEATURE_EV_4__
	IMG_ID_VDOREC_OSD_EV_N4,   
#endif
#ifdef __VDOREC_FEATURE_EV_3__
	IMG_ID_VDOREC_OSD_EV_N3,   
#endif
#ifdef __VDOREC_FEATURE_EV_2__
	IMG_ID_VDOREC_OSD_EV_N2,  
#endif
	IMG_ID_VDOREC_OSD_EV_N1, 
	IMG_ID_VDOREC_OSD_EV_0,  
	IMG_ID_VDOREC_OSD_EV_P1,  
#ifdef __VDOREC_FEATURE_EV_2__
	IMG_ID_VDOREC_OSD_EV_P2,  
#endif
#ifdef __VDOREC_FEATURE_EV_3__
	IMG_ID_VDOREC_OSD_EV_P3,  
#endif	
#ifdef __VDOREC_FEATURE_EV_4__	
	IMG_ID_VDOREC_OSD_EV_P4,  
#endif

	IMG_ID_VDOREC_OSD_EV_END
	
} vdorec_ev_img_id_enum;

/***************** zoom *******************/
typedef enum {

	IMG_ID_VDOREC_OSD_ZOOM_START = VDOREC_IMG_ZOOM_BASE,

	IMG_ID_VDOREC_OSD_ZOOM_1,  //40721
	IMG_ID_VDOREC_OSD_ZOOM_2,   //40722
	IMG_ID_VDOREC_OSD_ZOOM_3,  //40723
	IMG_ID_VDOREC_OSD_ZOOM_4,  //40724
	IMG_ID_VDOREC_OSD_ZOOM_5,  //40725
	IMG_ID_VDOREC_OSD_ZOOM_6,
	IMG_ID_VDOREC_OSD_ZOOM_7,
	IMG_ID_VDOREC_OSD_ZOOM_8,
	IMG_ID_VDOREC_OSD_ZOOM_9,
	IMG_ID_VDOREC_OSD_ZOOM_10,
	IMG_ID_VDOREC_OSD_ZOOM_11,
	IMG_ID_VDOREC_OSD_ZOOM_12,
	IMG_ID_VDOREC_OSD_ZOOM_13,
	IMG_ID_VDOREC_OSD_ZOOM_14,
	IMG_ID_VDOREC_OSD_ZOOM_15,
	IMG_ID_VDOREC_OSD_ZOOM_16,
	
	IMG_ID_VDOREC_OSD_ZOOM_END
	
} vdorec_zoom_img_id_enum;

/***************** night *******************/
typedef enum {

	IMG_ID_VDOREC_OSD_NIGHT_START = VDOREC_IMG_NIGHT_BASE,

	IMG_ID_VDOREC_OSD_NIGHT_OFF,
	IMG_ID_VDOREC_OSD_NIGHT_ON,
	
	IMG_ID_VDOREC_OSD_NIGHT_END
	
} vdorec_night_img_id_enum;



/***************** led highlight *******************/

/* led highlight */
typedef enum {
	IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_START = VDOREC_IMG_LED_HIGHLIGHT_BASE,
	IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_OFF,
	
//#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
	/* on/off */
	IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_ON,
//#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT__ */
	
//#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__
	/* 7 color */
	IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_WHITE,			
	IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_RED,			
	IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_GREEN,				
	IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_BLUE,					
	IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_YELLOW,						
	IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_PURPLE,							
	IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_CYAN,	
//#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__ */		

	IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_END
} vdorec_led_highlight_img_id_enum;


/***************** record aud *******************/
typedef enum {

	IMG_ID_VDOREC_OSD_RECORD_AUD_START = VDOREC_IMG_RECORD_AUD_BASE,

	IMG_ID_VDOREC_OSD_RECORD_AUD_OFF,
	IMG_ID_VDOREC_OSD_RECORD_AUD_ON,
	
	IMG_ID_VDOREC_OSD_RECORD_AUD_END
	
} vdorec_record_aud_img_id_enum;



/***************** size limit *******************/
typedef enum {

	IMG_ID_VDOREC_OSD_SIZE_LIMIT_START = VDOREC_IMG_SIZE_LIMIT_BASE,

	IMG_ID_VDOREC_OSD_SIZE_LIMIT_OFF,
	IMG_ID_VDOREC_OSD_SIZE_LIMIT_1,
	IMG_ID_VDOREC_OSD_SIZE_LIMIT_2,	
	IMG_ID_VDOREC_OSD_SIZE_LIMIT_3,		
	
	IMG_ID_VDOREC_OSD_SIZE_LIMIT_END
	
} vdorec_size_limit_img_id_enum;



/***************** time limit *******************/
typedef enum {

	IMG_ID_VDOREC_OSD_TIME_LIMIT_START = VDOREC_IMG_TIME_LIMIT_BASE,

	IMG_ID_VDOREC_OSD_TIME_LIMIT_OFF,
	IMG_ID_VDOREC_OSD_TIME_LIMIT_1,
	IMG_ID_VDOREC_OSD_TIME_LIMIT_2,	
	IMG_ID_VDOREC_OSD_TIME_LIMIT_3,		
	
	IMG_ID_VDOREC_OSD_TIME_LIMIT_END
	
} vdorec_time_limit_img_id_enum;

#endif /* _MMI_VDORECIMGENU_H */


