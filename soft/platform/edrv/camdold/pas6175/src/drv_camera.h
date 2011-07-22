// Here is where all the model specific defines should be


#include "hal_i2c.h"
#include "hal_camera.h"
#include "camera_m.h"

//#define  DRV_CAM_FRAME_6    1
#define  DRV_CAM_FRAME_10    1
//#define  DRV_CAM_FRAME_12    1
typedef struct
{
    UINT32 Addr;            // Register Address
    UINT8 Data;             // Register Data
    UINT16 Wait;            // Time to wait after write
} CAM_REG_T;

typedef struct
{
    UINT16 Len;             // Size of array
    CAM_REG_T *RegVal;      // Array of registers
} CAM_REG_GROUP_T;

typedef enum
{
    CAM_MODE_IDLE,
    CAM_MODE_VIEWFINDER,
    CAM_MODE_PREP_IMG_CAPTURE,
    CAM_MODE_IMG_CAPTURE,
    CAM_MODE_PREP_VID_CAPTURE,
    CAM_MODE_VID_CAPTURE
} CAM_MODE_T;

// On FPGA platform, Pixel Clock must not be too fast or xfer screws up
#define CAM_CLK_CFG 0x81

#if 0
PRIVATE const CAM_REG_T RG_InitPowerOnQvga[] = 
{
	//PAS6175_MTK_SOP_HSIN_20100811_NORMAL.asc
	{0xEF,0x00,1},
	{0x04,0x00,1}, 
	{0x07,0xC8,1},
	{0x08,0x50,1},
	{0x09,0x00,1},
	{0x0A,0xFF,1},
	{0x0C,0x00,1},
	{0x0F,0x3A,1},
	{0x11,0x4E,1},
	{0x13,0x54,1},
	{0x14,0x21,1},
	{0x15,0x3A,1},
	{0x17,0x42,1},
	{0x19,0x3F,1}, 
	{0x1A,0x80,1},
	{0x1B,0x3F,1},
	{0x1C,0x80,1},
	{0x1F,0x50,1},
	{0x20,0x28,1},
	{0x21,0x02,1},
	{0x22,0x78,1},
	{0x23,0x30,1},//э到堵翴, 20101112, Angelo
	{0x24,0x02,1},
	{0x25,0x8C,1},
	{0x26,0x00,1},
	{0x27,0x00,1},
	{0x29,0x01,1},//Gamma
	{0x2A,0x11,1},
	{0x2B,0x20,1},
	{0x2C,0x3A,1},
	{0x2D,0x64,1},
	{0x2E,0x75,1},
	{0x2F,0x84,1},
	{0x30,0x92,1},
	{0x31,0x9F,1},
	{0x32,0xB5,1},
	{0x33,0xC7,1},
	{0x34,0xD5,1},
	{0x35,0xE0,1},
	{0x36,0xEF,1},
	{0x37,0xF8,1},
	{0x38,0xFD,1},
	{0x39,0x03,1},
	{0x45,0x00,1},
	{0x46,0x00,1},
	{0x47,0x30,1},
	{0x48,0x16,1},
	{0x49,0x10,1},
	{0x4A,0x17,1},
	{0x4B,0x7E,1},
	{0x4C,0x80,1},
	{0x4D,0xF3,1},
	{0x4E,0xDC,1},
	{0x4F,0xF7,1},
	{0x50,0x1E,1},
	{0x51,0x14,1},
	{0x52,0x09,1},
	{0x53,0x46,1},
	{0x54,0xFF,1},
	{0x55,0x28,1},
	{0x56,0x19,1},
	{0x57,0x01,1},
	{0x58,0x06,1},
	{0x59,0x04,1},
	{0x5A,0x0A,1},
	{0x5B,0x02,1},
	{0x63,0x30,1},
	{0x64,0x0A,1},
	{0x65,0x30,1},
	{0x66,0x03,1},
	{0x67,0x97,1},//No  SysFreq
	{0x68,0x31,1},//No  SysFreq
	{0x6B,0x07,1},
    {0x6C,0x14,1}, // AE max Stage 0x12 to 0x14 10fps
	{0x6D,0x28,1},
	{0x6F,0x9B,1},
	{0x70,0x11,1},
	{0x72,0x00,1},
	{0x73,0x02,1},
	{0x74,0x40,1},
	{0x75,0x02,1},
	{0x76,0x07,1},
	{0x78,0x01,1},
	{0x79,0x0C,1},
	{0x7B,0x03,1},
	{0x7D,0x00,1},
	{0x7E,0x00,1},
	{0x7F,0xFF,1},
	{0x80,0xFE,1},
	{0x81,0x12,1},
	{0x82,0x6F,1},
	{0x84,0x2C,1},
	{0x86,0x14,1},
	{0x87,0x44,1},
	{0x88,0x01,1},
	{0x89,0x00,1},
	{0x8A,0x00,1},
	{0x8B,0x00,1},
	{0x8C,0xE0,1},
	{0x8E,0x00,1},
	{0x8F,0x00,1},
	{0x90,0x00,1},
	{0x91,0x00,1},
	{0x92,0x00,1},
	{0x93,0x00,1},
	{0x94,0x00,1},
	{0x95,0x00,1},//Sensor CLK Delay
	{0x97,0x10,1},
	{0x99,0x44,1}, //Lens shading
	{0x9A,0x40,1},
	{0x9B,0x44,1},
	{0x9C,0x40,1},
	{0x9D,0x46,1},
	{0x9E,0x40,1},
	{0x9F,0x46,1},
	{0xA0,0x40,1},
	{0xA1,0x60,1},
	{0xA2,0x50,1},
	{0xA3,0x5E,1},
	{0xA4,0x50,1},
	{0xA5,0x46,1},
	{0xA6,0x50,1},
	{0xAA,0x10,1},
	{0xE0,0xF2,1},
	{0xE1,0x00,1},
	{0xE2,0x40,1},
	{0xE6,0x00,1},
	{0xE9,0x87,1},
	{0xEA,0x00,1},
	{0xEB,0x00,1},
	{0xED,0x00,1},
	{0xEE,0x3F,1},
	{0xED,0x01,1},
	
	{0xEF,0x01,1},
	{0x02,0x08,1}, // Cmd_Np to 
	{0x03,0x36,1},
	{0x04,0x5A,1},
	{0x05,0x01,1},
	{0x06,0x0F,1},
	{0x07,0x12,1},
	{0x08,0x0F,1},
	{0x09,0x17,1},
	{0x0C,0x00,1},
	{0x0D,0xCE,1},
	{0x0E,0xAC,1},
	{0x0F,0x00,1},
	{0x10,0x0F,1},
	{0x11,0x00,1},
	{0x12,0x15,1},
	{0x17,0x00,1},
	{0x18,0x00,1},
	{0x19,0x00,1},
	{0x1A,0x00,1},
	{0x1B,0xFF,1},
	{0x1C,0x00,1},
	{0x1D,0x4F,1},
	{0x1E,0x01,1},
	{0x20,0x14,1},
	{0x21,0x00,1},
	{0x22,0x08,1},
	{0x23,0x00,1},
	{0x24,0x05,1},
	{0x28,0x08,1},
	{0x2A,0x03,1},
	{0x2B,0x23,1},//
	{0x2C,0x2A,1},
	{0x2D,0x13,1},
	{0x2E,0x22,1},
	{0x2F,0x23,1},
	{0x30,0x25,1},
	{0x33,0x1A,1},
	{0x34,0x34,1},
	{0x35,0x00,1},
	{0x36,0x00,1},
	{0x37,0x00,1},
	{0x38,0x00,1},
	{0x39,0x0A,1},
	{0x3B,0x04,1},
	{0x3C,0x04,1},
	{0x3D,0x04,1},
	{0x3E,0x04,1},
	{0x41,0x06,1},
    {0x42,0x00,1},
	{0x43,0x82,1},
	{0x44,0x0C,1},
	{0x45,0x43,1},
	{0x48,0x31,1},
	{0x49,0x11,1},
	{0x4A,0x00,1},
	{0x4B,0x18,1},
	{0x50,0x03,1},
	{0x51,0x04,1},
	{0x52,0x39,1},
	{0x53,0x02,1},
    {0x58,0x00,1},
	{0x5D,0x00,1},
	{0x5E,0x3F,1},
	{0x62,0x35,1},
	{0x63,0x7F,1},
	{0x64,0x34,1},
	{0x66,0x06,1},
	{0x67,0x18,1},
	{0x68,0x07,1},
	{0x69,0x01,1},
	{0x76,0x00,1},
	{0x77,0x20,1},
    {0x78,0x0B,1},// IO Driving
	{0x7A,0x0F,1},
	{0x7C,0x03,1},
	{0x7D,0x0F,1},
	{0x7E,0x00,1},
	{0x80,0x00,1},
	{0x82,0x00,1},
	{0x91,0x00,1},
	{0x9F,0x00,1},
	{0xA1,0x04,1},
	{0xA2,0xC0,1},
	{0xA4,0x00,1},
	{0xA5,0x00,1},
	{0xA6,0x00,1},
	{0xA7,0x08,1},
	{0xA8,0x0F,1},
	{0xA9,0x00,1},
	{0xAA,0xAA,1},
	{0xAB,0x55,1},
	{0xAC,0x66,1},
	{0xB0,0x05,1},
	{0xB1,0x3F,1},
	{0xB2,0xCA,1},
	{0xB4,0x0C,1},
	{0xB6,0x0E,1},
	{0xBC,0x34,1},
	{0xBE,0x35,1},
	{0x11,0x01,1},
	
	{0xEF,0x02,1},
	{0x00,0x00,1},
	{0x18,0x88,1},//Tone
	{0x19,0xC6,1},
	{0x22,0x08,1},
	{0x24,0xFF,1},//э到堵翴, 20101112, Angelo
	{0x25,0x20,1},//э到堵翴, 20101112, Angelo
	{0x26,0x12,1},
	{0x27,0x06,1},
	{0x2A,0x80,1},
	{0x2B,0x00,1},
	{0x2C,0x14,1},//э到堵翴, 20101112, Angelo
	{0x2D,0x07,1},//э到堵翴, 20101112, Angelo
	{0x2E,0x40,1},//э到堵翴, 20101112, Angelo
	{0x2F,0x14,1},
	{0x30,0x10,1},
	{0x36,0x02,1},
	{0x37,0x86,1},
	{0x38,0x94,1},
	{0x39,0x10,1},
	{0x3A,0x8E,1},
	{0x3B,0x20,1},
	{0x3C,0x03,1},
	{0x3E,0x33,1},//CCMb
	{0x3F,0x2F,1},
	{0x40,0x30,1},
	{0x41,0x21,1},
	{0x42,0x0C,1},
	{0x43,0x40,1},
	{0x44,0x4C,1},
	{0x45,0x44,1},
	{0x46,0x44,1},
	{0x47,0x00,1},
	{0x50,0x3C,1},
	{0x51,0x02,1},
	{0x52,0x0F,1},
	{0x53,0x03,1},
	{0x54,0x01,1},
	{0x55,0x00,1},
	{0x56,0x01,1},//э到堵翴, 20101112, Angelo
	{0x57,0x01,1},//э到堵翴, 20101112, Angelo
	{0x58,0x08,1},//э到堵翴, 20101112, Angelo
	{0x59,0x00,1},
	{0x5A,0x06,1},//э到堵翴, 20101112, Angelo
	{0x5B,0x0A,1},//э到堵翴, 20101112, Angelo
	{0x5C,0x06,1},//э到堵翴, 20101112, Angelo
	{0x5D,0x02,1},
	{0x5E,0x02,1},
	{0x5F,0x0A,1},
	{0x60,0x12,1},
	{0x61,0x00,1},
	{0x62,0x01,1},
	{0x63,0x0F,1},
	{0x64,0x01,1},
	{0x65,0x48,1},//э到堵翴, 20101112, Angelo
	{0x66,0xFF,1},
	{0x69,0x0C,1},
	{0x6A,0x00,1},
	{0x9B,0x00,1},
	{0x9C,0xF2,1},
	{0x9D,0x01,1},
	{0x9E,0x40,1},
	{0x9F,0x00,1},
	{0xA0,0x00,1},
	{0xA1,0x00,1},
	{0xA2,0x00,1},
	{0xA3,0x00,1},
	{0xA4,0x02,1},
	{0xA5,0x00,1},
	{0xA6,0x02,1},
	{0xA8,0x00,1},
	{0xA9,0x20,1},
	{0xAA,0x00,1},
	{0xAB,0xF0,1},
	{0xAD,0x00,1},
	{0xAE,0x00,1},
	{0xB0,0x00,1},
	{0xB1,0x00,1},
	{0xB2,0x00,1},
	{0xB4,0x00,1},
	{0xB5,0xF0,1},
	{0xB6,0x01,1},
	{0xB7,0x40,1},
	{0xB8,0x00,1},
	{0xB9,0x00,1},
	{0xBA,0x00,1},
	{0xBB,0x00,1},
	{0xBC,0x00,1},
    {0xBD,0x00,1}, 
	{0xBE,0x01,1},//R_RGB_Dithering
	{0xBF,0x04,1},
	{0xC0,0x00,1},
	{0xC1,0x10,1},
	{0xC2,0x00,1},
	{0xC4,0x03,1},
	{0xC5,0x00,1},
	{0xC6,0x01,1},
	{0xC7,0x00,1},
	{0xC8,0x00,1},
	{0xC9,0x00,1},
	{0xCA,0x00,1},
	{0xCB,0x00,1},
	{0xCC,0x00,1},
	{0xCD,0x00,1},
	{0xCE,0x00,1},
	{0xCF,0x00,1},
	{0xD0,0x00,1},
	{0xD1,0x00,1},
	{0xD2,0x00,1},
	{0xD3,0x00,1},
	{0xD4,0x00,1},
	{0xD5,0x00,1},
	{0xD6,0x00,1},
	{0xD7,0x00,1},
	{0xD8,0x00,1},
	{0xD9,0x00,1},
	{0xDA,0x00,1},
	{0xDB,0x00,1},
	{0xDC,0x00,1},
	{0xDD,0x00,1},
	{0xDE,0x00,1},
	{0xDF,0x00,1},
	{0xE0,0x04,1},
	{0xE3,0x00,1},
	{0xE4,0x00,1},
	{0xE5,0x00,1},
	{0xE6,0x00,1},
	{0xEB,0x00,1},
	{0x00,0x01,1},
};

#else
// use this for 320x240 (VGA) capture
PRIVATE const CAM_REG_T RG_InitPowerOnQvga[] = 
{
//PAS6175_YUV_X1_0707_Panasonic_Hsin_100716_20101015.asc
	{0xEF,0x00,1},
	{0x04,0x00,1},
	{0x07,0x96,1},
	{0x08,0x50,1},
	{0x09,0x00,1},
	{0x0A,0xFF,1},
	{0x0C,0x00,1},
	{0x0F,0x3A,1},
	{0x11,0x4E,1},
	{0x13,0x5A,1},
	{0x14,0x21,1},
	{0x15,0x3A,1},
	{0x17,0x3C,1},
	{0x19,0x3F,1},
	{0x1A,0x80,1},
	{0x1B,0x3F,1},
	{0x1C,0x80,1},
	{0x1F,0x50,1},
	{0x20,0x28,1},
	{0x21,0x02,1},
	{0x22,0x78,1},
	{0x23,0x30,1},//  Angelo
	{0x24,0x02,1},
	{0x25,0x8C,1},
	{0x26,0x00,1},
	{0x27,0x00,1},
	{0x29,0x01,1},
	{0x2A,0x0E,1},
	{0x2B,0x1C,1},
	{0x2C,0x33,1},
	{0x2D,0x59,1},
	{0x2E,0x69,1},
	{0x2F,0x77,1},
	{0x30,0x83,1},
	{0x31,0x8E,1},
	{0x32,0xA1,1},
	{0x33,0xB1,1},
	{0x34,0xBE,1},
	{0x35,0xCA,1},
	{0x36,0xDC,1},
	{0x37,0xEA,1},
	{0x38,0xF6,1},
	{0x39,0x03,1},
	{0x45,0x00,1},
	{0x46,0x00,1},
	{0x47,0x30,1},
	{0x48,0x16,1},
	{0x49,0x10,1},
	{0x4A,0x17,1},
	{0x4B,0x7E,1},
	{0x4C,0x80,1},
	{0x4D,0xF3,1},
	{0x4E,0xDC,1},
	{0x4F,0xF7,1},
	{0x50,0x1E,1},
	{0x51,0x0A,1},
	{0x52,0x0B,1},
	{0x53,0x64,1},
	{0x54,0xFF,1},
	{0x55,0x28,1},
	{0x56,0x19,1},
	{0x57,0x02,1},
	{0x58,0x06,1},
	{0x59,0x04,1},
	{0x5A,0x0A,1},
	{0x5B,0x02,1},
	{0x63,0x30,1},
	{0x64,0x0A,1},
	{0x65,0x30,1},
	{0x66,0x13,1},
	{0x67,0x8D,1},
	{0x68,0x5B,1},
	{0x6B,0x07,1},
	{0x6C,0x1A,1},
	{0x6D,0x30,1},
	{0x6F,0x91,1},
	{0x70,0x00,1},
	{0x72,0x01,1},
	{0x73,0x02,1},
	{0x74,0x40,1},
	{0x75,0x02,1},
	{0x76,0x07,1},
	{0x78,0x01,1},
	{0x79,0x0C,1},
	{0x7B,0x03,1},
	{0x7D,0x00,1},
	{0x7E,0x00,1},
	{0x7F,0xFF,1},
	{0x80,0xFE,1},
	{0x81,0x01,1},
	{0x82,0x7F,1},
	{0x84,0x1A,1},
	{0x86,0x12,1},
	{0x87,0x44,1},
	{0x88,0x01,1},
	{0x89,0x00,1},
	{0x8A,0x00,1},
	{0x8B,0x00,1},
	{0x8C,0xE0,1},
	{0x8E,0x00,1},
	{0x8F,0x00,1},
	{0x90,0x00,1},
	{0x91,0x00,1},
	{0x92,0x00,1},
	{0x93,0x00,1},
	{0x94,0x00,1},
	{0x95,0x00,1},
	{0x97,0x10,1},
	{0x99,0x40,1},
	{0x9A,0x40,1},
	{0x9B,0x40,1},
	{0x9C,0x40,1},
	{0x9D,0x40,1},
	{0x9E,0x40,1},
	{0x9F,0x40,1},
	{0xA0,0x40,1},
	{0xA1,0x40,1},
	{0xA2,0x40,1},
	{0xA3,0x40,1},
	{0xA4,0x40,1},
	{0xA5,0x46,1},
	{0xA6,0x50,1},
	{0xAA,0x10,1},
	{0xE0,0xF2,1},
	{0xE1,0x00,1},
	{0xE2,0x40,1},
	{0xE6,0x00,1},
	{0xE9,0x87,1},
	{0xEA,0x00,1},
	{0xEB,0x00,1},
	{0xED,0x00,1},
	{0xEE,0x3F,1},
	{0xED,0x01,1},

	{0xEF,0x01,1},
	{0x02,0x04,1},
	{0x03,0x36,1},
	{0x04,0x5A,1},
	{0x05,0x01,1},
	{0x06,0x0F,1},
	{0x07,0x13,1},
	{0x08,0x0F,1},
	{0x09,0x15,1},
	{0x0C,0x00,1},
	{0x0D,0x5F,1},
	{0x0E,0x19,1},
	{0x0F,0x00,1},
	{0x10,0x0F,1},
	{0x11,0x00,1},
	{0x12,0x0A,1},
	{0x17,0x00,1},
	{0x18,0x00,1},
	{0x19,0x00,1},
	{0x1A,0x00,1},
	{0x1B,0xFF,1},
	{0x1C,0x00,1},
	{0x1D,0x4F,1},
	{0x1E,0x01,1},
	{0x20,0x14,1},
	{0x21,0x00,1},
	{0x22,0x08,1},
	{0x23,0x00,1},
	{0x24,0x05,1},
	{0x28,0x08,1},
	{0x2A,0x03,1},
	{0x2B,0x23,1},
	{0x2C,0x2A,1},
	{0x2D,0x13,1},
	{0x2E,0x22,1},
	{0x2F,0x23,1},
	{0x30,0x25,1},
	{0x33,0x1A,1},
	{0x34,0x34,1},
	{0x35,0x00,1},
	{0x36,0x00,1},
	{0x37,0x00,1},
	{0x38,0x00,1},
	{0x39,0x0A,1},
	{0x3B,0x04,1},
	{0x3C,0x04,1},
	{0x3D,0x04,1},
	{0x3E,0x04,1},
	{0x41,0x06,1},
	{0x42,0x00,1},
	{0x43,0x82,1},
	{0x44,0x0C,1},
	{0x45,0x43,1},
	{0x48,0x31,1},
	{0x49,0x11,1},
	{0x4A,0x00,1},
	{0x4B,0x18,1},
	{0x50,0x03,1},
	{0x51,0x04,1},
	{0x52,0x39,1},
	{0x53,0x02,1},
	{0x58,0x00,1},
	{0x5D,0x00,1},
	{0x5E,0x3F,1},
	{0x62,0x35,1},
	{0x63,0x7F,1},
	{0x64,0x34,1},
	{0x66,0x06,1},
	{0x67,0x18,1},
	{0x68,0x07,1},
	{0x69,0x01,1},
	{0x76,0x00,1},
	{0x77,0x20,1},
	{0x78,0x0B,1},
	{0x7A,0x0F,1},
	{0x7C,0x03,1},
	{0x7D,0x0F,1},
	{0x7E,0x00,1},
	{0x80,0x00,1},
	{0x82,0x00,1},
	{0x91,0x00,1},
	{0x9F,0x00,1},
	{0xA1,0x04,1},
	{0xA2,0xC0,1},
	{0xA4,0x00,1},
	{0xA5,0x00,1},
	{0xA6,0x00,1},
	{0xA7,0x08,1},
	{0xA8,0x0F,1},
	{0xA9,0x00,1},
	{0xAA,0xAA,1},
	{0xAB,0x55,1},
	{0xAC,0x66,1},
	{0xB0,0x05,1},
	{0xB1,0x3F,1},
	{0xB2,0xCA,1},
	{0xB4,0x0C,1},
	{0xB6,0x0E,1},
	{0xBC,0x34,1},
	{0xBE,0x35,1},
	{0x11,0x01,1},

	{0xEF,0x02,1},
	{0x00,0x00,1},
	{0x18,0x88,1},
	{0x19,0xC6,1},
	{0x22,0x08,1},
	{0x24,0xFF,1},//э到堵翴, 20101112, Angelo
	{0x25,0x20,1},//э到堵翴, 20101112, Angelo
	{0x26,0x12,1},
	{0x27,0x06,1},
	{0x2A,0x80,1},
	{0x2B,0x00,1},
	{0x2C,0x19,1},//э到Edge, 20110126, Angelo
	{0x2D,0x0C,1},//э到Edge, 20110126, Angelo
	{0x2E,0x40,1},//э到堵翴, 20101112, Angelo
	{0x2F,0x1A,1},
	{0x30,0x14,1},
	{0x36,0x02,1},
	{0x37,0x86,1},
	{0x38,0x8F,1},
	{0x39,0x20,1},
	{0x3A,0x8E,1},
	{0x3B,0x20,1},
	{0x3C,0x03,1},
	{0x3E,0x33,1},
	{0x3F,0x25,1},
	{0x40,0x4B,1},
	{0x41,0x10,1},
	{0x42,0x0C,1},
	{0x43,0x40,1},
	{0x44,0x4C,1},
	{0x45,0x48,1},
	{0x46,0x48,1},
	{0x47,0x00,1},
	{0x50,0x3C,1},
	{0x51,0x02,1},
	{0x52,0x0F,1},
	{0x53,0x03,1},
	{0x54,0x01,1},
	{0x55,0x00,1},
	{0x56,0x01,1},//э到堵翴, 20101112, Angelo
	{0x57,0x01,1},//э到堵翴, 20101112, Angelo
	{0x58,0x08,1},//э到堵翴, 20101112, Angelo
	{0x59,0x00,1},
	{0x5A,0x06,1},//э到堵翴, 20101112, Angelo
	{0x5B,0x0A,1},//э到堵翴, 20101112, Angelo
	{0x5C,0x02,1},//э到Edge, 20110126, Angelo
	{0x5D,0x01,1},
	{0x5E,0x01,1},
	{0x5F,0x12,1},
	{0x60,0x1F,1},
	{0x61,0x00,1},
	{0x62,0x01,1},
	{0x63,0x0F,1},
	{0x64,0x11,1},
	{0x65,0x4C,1},//э到Edge, 20110126, Angelo
	{0x66,0x96,1},
	{0x69,0x00,1},
	{0x6A,0x00,1},
	{0x9B,0x00,1},
	{0x9C,0xF2,1},
	{0x9D,0x01,1},
	{0x9E,0x40,1},
	{0x9F,0x00,1},
	{0xA0,0x00,1},
	{0xA1,0x00,1},
	{0xA2,0x00,1},
	{0xA3,0x00,1},
	{0xA4,0x02,1},
	{0xA5,0x00,1},
	{0xA6,0x02,1},
	{0xA8,0x00,1},
	{0xA9,0x20,1},
	{0xAA,0x00,1},
	{0xAB,0xF0,1},
	{0xAD,0x00,1},
	{0xAE,0x00,1},
	{0xB0,0x00,1},
	{0xB1,0x00,1},
	{0xB2,0x00,1},
	{0xB4,0x00,1},
	{0xB5,0xF0,1},
	{0xB6,0x01,1},
	{0xB7,0x40,1},
	{0xB8,0x00,1},
	{0xB9,0x00,1},
	{0xBA,0x00,1},
	{0xBB,0x00,1},
	{0xBC,0x00,1},
	{0xBD,0x01,1},
	{0xBE,0x01,1},//R_RGB_Dithering
	{0xBF,0x04,1},
	{0xC0,0x00,1},
	{0xC1,0x00,1},
	{0xC2,0x00,1},
	{0xC4,0x00,1},
	{0xC5,0x00,1},
	{0xC6,0x01,1},
	{0xC7,0x00,1},
	{0xC8,0x00,1},
	{0xC9,0x00,1},
	{0xCA,0x00,1},
	{0xCB,0x00,1},
	{0xCC,0x00,1},
	{0xCD,0x00,1},
	{0xCE,0x00,1},
	{0xCF,0x00,1},
	{0xD0,0x00,1},
	{0xD1,0x00,1},
	{0xD2,0x00,1},
	{0xD3,0x00,1},
	{0xD4,0x00,1},
	{0xD5,0x00,1},
	{0xD6,0x00,1},
	{0xD7,0x00,1},
	{0xD8,0x00,1},
	{0xD9,0x00,1},
	{0xDA,0x00,1},
	{0xDB,0x00,1},
	{0xDC,0x00,1},
	{0xDD,0x00,1},
	{0xDE,0x00,1},
	{0xDF,0x00,1},
	{0xE0,0x04,1},
	{0xE3,0x00,1},
	{0xE4,0x00,1},
	{0xE5,0x00,1},
	{0xE6,0x00,1},
	{0xEB,0x00,1},
	{0x00,0x01,1},



 };

#endif

PRIVATE const CAM_REG_T RG_InitPowerOnVga[] = 
{
	{0xfe,0x00,1},
		
	{0x1a,0x16,1},	
	{0xd2,0x10,1},   // close AEC
	{0x22,0x55,1},   // close AWB

	{0x5a,0x56,1}, 
	{0x5b,0x40,1},
	{0x5c,0x4a,1},		
	
	{0x22,0x57,1},  // Open AWB
		
	{0x03,0x01,1}, 
	{0x04,0x2c,1}, 

	/*********mclk = 26MHZ start*****************/	
	{0x01,0x5e,1},	
	{0x02,0x70,1}, 
	{0x0f,0x02,1},

	{0xe2,0x00,1},	//anti-flicker step [11:8]
	{0xe3,0x64,1},   //anti-flicker step [7:0]
		
	{0xe4,0x02,1},   //exp level 1 16.6fps
	{0xe5,0x58,1}, 
	{0xe6,0x03,1},   //exp level 2 12.5fps
	{0xe7,0x20,1}, 
	{0xe8,0x04,1},   //exp level 3 11.1fps
	{0xe9,0x4c,1}, 
	{0xea,0x07,1},   //exp level 4 5fps
	{0xeb,0xd0,1}, 

/*********mclk = 26MHZ end*****************/

	{0x05,0x00,1},
	{0x06,0x00,1},
	{0x07,0x00,1}, 
	{0x08,0x00,1}, 
	{0x09,0x01,1}, 
	{0x0a,0xe8,1}, 
	{0x0b,0x02,1}, 
	{0x0c,0x88,1}, 
	{0x0d,0x02,1}, 
	{0x0e,0x02,1}, 
	{0x10,0x22,1}, 
	{0x11,0x0d,1}, 
	{0x12,0x2a,1}, 
	{0x13,0x00,1}, 
	{0x15,0x0a,1}, 
	{0x16,0x05,1}, 
	{0x17,0x01,1}, 

	{0x1b,0x03,1}, 
	{0x1c,0xc1,1}, 
	{0x1d,0x08,1}, 
	{0x1e,0x20,1}, //0x60
	{0x1f,0x16,1},   //16 terry

	{0x5a,0x5a,1}, 
	{0x5b,0x40,1},
	{0x5c,0x4a,1},			

	{0x20,0xff,1}, 
	{0x21,0xf8,1}, 
	{0x22,0x57,1}, 
	{0x24,0xa2,1},    //a2  terry  a0 a2
	{0x25,0x0f,1},
	//output sync_mode
	{0x26,0x03,1}, 
	{0x2f,0x01,1}, 
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// grab_t ////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x30,0xf7,1}, 
	{0x31,0x40,1},
	{0x32,0x00,1}, 
	{0x39,0x04,1}, 
	{0x3a,0x20,1}, 
	{0x3b,0x20,1}, 
	{0x3c,0x02,1}, 
	{0x3d,0x02,1}, 
	{0x3e,0x02,1},
	{0x3f,0x02,1}, 
	
	//gain
	{0x50,0x24,1}, 
	
	{0x53,0x82,1}, //82 //gavin 20100817
	{0x54,0x80,1}, 
	{0x55,0x80,1}, 
	{0x56,0x82,1}, //82 //gavin 20100817
	
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// LSC_t	 ////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x8b,0x20,1}, 
	{0x8c,0x20,1}, 
	{0x8d,0x20,1}, 
	{0x8e,0x10,1}, 
	{0x8f,0x10,1}, 
	{0x90,0x10,1}, 
	{0x91,0x3c,1}, 
	{0x92,0x50,1}, 
	{0x5d,0x12,1}, 
	{0x5e,0x1a,1}, 
	{0x5f,0x24,1}, 
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// DNDD_t	  ///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x60,0x07,1}, 
	{0x61,0x0e,1}, 
	{0x62,0x0c,1}, 
	{0x64,0x03,1}, 
	{0x66,0xe8,1}, 
	{0x67,0x86,1}, 
	{0x68,0xa2,1}, 
	
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// asde_t	  ///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x69,0x20,1}, //gain high th
	{0x6a,0x0f,1}, 
	{0x6b,0x00,1}, 
	{0x6c,0x53,1}, 
	{0x6d,0x83,1}, 
	{0x6e,0xac,1}, 
	{0x6f,0xac,1}, 
	{0x70,0x15,1}, 
	{0x71,0x33,1}, 
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// eeintp_t///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x72,0xdc,1},  
	{0x73,0x80,1},  
	//for high resolution in light scene
	{0x74,0x02,1}, 
	{0x75,0x3f,1}, 
	{0x76,0x02,1}, 
	{0x77,0x54,1}, 
	{0x78,0x88,1}, 
	{0x79,0x81,1}, 
	{0x7a,0x81,1}, 
	{0x7b,0x22,1}, 
	{0x7c,0xff,1},
	
	
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// CC_t	  ///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x93,0x4a,1}, //45 //gavin 20100817
	{0x94,0x04,1}, 
	{0x95,0x09,1}, 
	{0x96,0xe0,1}, 
	{0x97,0x40,1}, 
	{0x98,0x00,1}, //f0 //gavin 20100817
	{0x9c,0x00,1}, //00 //gavin 20100817
	{0x9d,0x00,1}, //03 //gavin 20100817
	{0x9e,0x00,1}, //00 //gavin 20100817
	
	
	/////////////////////////////////////////////////////////////////////
	///////////////////////////YCP_t///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0xb1,0x40,1}, //44 //gavin 20100817
	{0xb2,0x40,1}, //44 //gavin 20100817 
	{0xb8,0x20,1}, 
	{0xbe,0x36,1}, 
	{0xbf,0x00,1}, 
	/////////////////////////////////////////////////////////////////////
	///////////////////////////AEC_t///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0xd0,0xc9,1},  
	{0xd1,0x10,1},  
//	{0xd2,0x90,1},  
	{0xd3,0x80,1},  
	{0xd5,0xf2,1}, 
	{0xd6,0x16,1},  
	{0xdb,0x92,1}, 
	{0xdc,0xa5,1},  
	{0xdf,0x23,1},   
	{0xd9,0x00,1},  
	{0xda,0x00,1},  
	{0xe0,0x09,1},

	{0xec,0x20,1},  
	{0xed,0x04,1},  
	{0xee,0xa0,1},  
	{0xef,0x40,1},  
	///////////////////////////////////////////////////////////////////
	///////////////////////////GAMMA//////////////////////////////////
	///////////////////////////////////////////////////////////////////
#if 1	
	{0x9F,0x0F,1},		   
	{0xA0,0x1D,1},  
	{0xA1,0x2D,1},
	{0xA2,0x3B,1},
	{0xA3,0x46,1},
	{0xA4,0x50,1},
	{0xA5,0x5A,1},
	{0xA6,0x6B,1},
	{0xA7,0x7B,1},
	{0xA8,0x8A,1},
	{0xA9,0x98,1},
	{0xAA,0xA5,1},
	{0xAB,0xB2,1},
	{0xAC,0xBE,1},
	{0xAD,0xD5,1},
	{0xAE,0xEB,1},
	{0xAF,0xFE,1},
#endif
	//Y_gamma
	{0xc0,0x00,1},
	{0xc1,0x0B,1},
	{0xc2,0x15,1},
	{0xc3,0x27,1},
	{0xc4,0x39,1},
	{0xc5,0x49,1},
	{0xc6,0x5A,1},
	{0xc7,0x6A,1},
	{0xc8,0x89,1},
	{0xc9,0xA8,1},
	{0xca,0xC6,1},
	{0xcb,0xE3,1},
	{0xcc,0xFF,1},

	/////////////////////////////////////////////////////////////////
	/////////////////////////// ABS_t ///////////////////////////////
	/////////////////////////////////////////////////////////////////
	{0xf0,0x02,1},
	{0xf1,0x01,1},
	{0xf2,0x00,1},  
	{0xf3,0x30,1}, 
	
	/////////////////////////////////////////////////////////////////
	/////////////////////////// Measure Window ///////////////////////
	/////////////////////////////////////////////////////////////////
	{0xf7,0x04,1}, 
	{0xf8,0x02,1}, 
	{0xf9,0x9f,1},
	{0xfa,0x78,1},

	//-----------------------------------------------------------------------------
	{0xfe,0x01,1},

	/////////////////////////////////////////////////////////////////
	///////////////////////////AWB_p/////////////////////////////////
	/////////////////////////////////////////////////////////////////
	{0x00,0xf5,1}, 
	//{0x01,0x0a,1},	
	{0x02,0x1a,1}, 
	{0x0a,0xa0,1}, 
	{0x0b,0x64,1}, //0x60 //gavin 20100817
	{0x0c,0x08,1},
	{0x0e,0x4c,1}, 
	{0x0f,0x39,1}, 
	{0x11,0x3f,1}, 
	{0x12,0x72,1}, 
	{0x13,0x39,1}, //0x13 //gavin 20100817 
	{0x14,0x42,1},  
	{0x15,0x43,1}, 
	{0x16,0xc2,1}, 
	{0x17,0xa8,1}, 
	{0x18,0x18,1},  
	{0x19,0x40,1},  
	{0x1a,0xd0,1}, 
	{0x1b,0xf5,1},  

	{0x70,0x40,1}, 
	{0x71,0x58,1},  
	{0x72,0x30,1},  
	{0x73,0x48,1},  
	{0x74,0x20,1},  
	{0x75,0x60,1},  

	{0xfe,0x00,1},
#ifdef __PROJECT_G021BQ__
	{0x14,0x10,1}, 
#else
	{0x14,0x13,1}, 
#endif
	{0xd2,0x90,1},   // open AEC at last!

	//{  0x1a, 0x16   ,1},  
	//{  0x25, 0x0f   ,1},  

};


// use this for 160*120 (QQVGA) capture
PRIVATE const CAM_REG_T RG_InitPowerOnQqvga[] = 
{
	{0xfe,0x00,1},
		
	{0x1a,0x16,1},	
	{0xd2,0x10,1},   // close AEC
	{0x22,0x55,1},   // close AWB

	{0x5a,0x56,1}, 
	{0x5b,0x40,1},
	{0x5c,0x4a,1},		
	
	{0x22,0x57,1},  // Open AWB	

	{0x03,0x01,1}, 
	{0x04,0x2c,1}, 

/*********mclk = 26MHZ start*****************/	
	{0x01,0x5e,1},	
	{0x02,0x70,1}, 
	{0x0f,0x02,1},

	{0xe2,0x00,1},	//anti-flicker step [11:8]
	{0xe3,0x64,1},   //anti-flicker step [7:0]
		
	{0xe4,0x02,1},   //exp level 1 16.6fps
	{0xe5,0x58,1}, 
	{0xe6,0x03,1},   //exp level 2 12.5fps
	{0xe7,0x20,1}, 
	{0xe8,0x04,1},   //exp level 3 11.1fps
	{0xe9,0x4c,1}, 
	{0xea,0x07,1},   //exp level 4 5fps
	{0xeb,0xd0,1}, 

/*********mclk = 26MHZ end*****************/
	
	{0x05,0x00,1},
	{0x06,0x00,1},
	{0x07,0x00,1}, 
	{0x08,0x00,1}, 
	{0x09,0x01,1}, 
	{0x0a,0xe8,1}, 
	{0x0b,0x02,1}, 
	{0x0c,0x88,1}, 
	{0x0d,0x02,1}, 
	{0x0e,0x02,1}, 
	{0x10,0x22,1}, 
	{0x11,0x0d,1}, 
	{0x12,0x2a,1}, 
	{0x13,0x00,1}, 
	{0x15,0x0a,1}, 
	{0x16,0x05,1}, 
	{0x17,0x01,1}, 

	{0x1b,0x03,1}, 
	{0x1c,0xc1,1}, 
	{0x1d,0x08,1}, 
	{0x1e,0x20,1}, //0x60
	{0x1f,0x16,1},   //16 terry

	{0x5a,0x5a,1}, 
	{0x5b,0x40,1},
	{0x5c,0x4a,1},			

	{0x20,0xff,1}, 
	{0x21,0xf8,1}, 
	{0x22,0x57,1}, 
	{0x24,0xa2,1},    //a2  terry  a0 a2
	{0x25,0x0f,1},
	//output sync_mode
	{0x26,0x03,1}, 
	{0x2f,0x01,1}, 
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// grab_t ////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x30,0xf7,1}, 
	{0x31,0x40,1},
	{0x32,0x00,1}, 
	{0x39,0x04,1}, 
	{0x3a,0x20,1}, 
	{0x3b,0x20,1}, 
	{0x3c,0x02,1}, 
	{0x3d,0x02,1}, 
	{0x3e,0x02,1},
	{0x3f,0x02,1}, 
	
	//gain
	{0x50,0x24,1}, 
	
	{0x53,0x80,1}, //82 //gavin 20100817
	{0x54,0x80,1}, 
	{0x55,0x80,1}, 
	{0x56,0x80,1}, //82 //gavin 20100817
	
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// LSC_t	 ////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x8b,0x20,1}, 
	{0x8c,0x20,1}, 
	{0x8d,0x20,1}, 
	{0x8e,0x10,1}, 
	{0x8f,0x10,1}, 
	{0x90,0x10,1}, 
	{0x91,0x3c,1}, 
	{0x92,0x50,1}, 
	{0x5d,0x12,1}, 
	{0x5e,0x1a,1}, 
	{0x5f,0x24,1}, 
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// DNDD_t	  ///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x60,0x07,1}, 
	{0x61,0x0e,1}, 
	{0x62,0x0c,1}, 
	{0x64,0x03,1}, 
	{0x66,0xe8,1}, 
	{0x67,0x86,1}, 
	{0x68,0xa2,1}, 
	
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// asde_t	  ///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x69,0x20,1}, //gain high th
	{0x6a,0x0f,1}, 
	{0x6b,0x00,1}, 
	{0x6c,0x53,1}, 
	{0x6d,0x83,1}, 
	{0x6e,0xac,1}, 
	{0x6f,0xac,1}, 
	{0x70,0x15,1}, 
	{0x71,0x33,1}, 
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// eeintp_t///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x72,0xdc,1},  
	{0x73,0x80,1},  
	//for high resolution in light scene
	{0x74,0x02,1}, 
	{0x75,0x3f,1}, 
	{0x76,0x02,1}, 
	{0x77,0x54,1}, 
	{0x78,0x88,1}, 
	{0x79,0x81,1}, 
	{0x7a,0x81,1}, 
	{0x7b,0x22,1}, 
	{0x7c,0xff,1},
	
	
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// CC_t	  ///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x93,0x4a,1}, //45 //gavin 20100817
	{0x94,0x04,1}, 
	{0x95,0x09,1}, 
	{0x96,0xe0,1}, 
	{0x97,0x40,1}, 
	{0x98,0x00,1}, //f0 //gavin 20100817
	{0x9c,0x00,1}, //00 //gavin 20100817
	{0x9d,0x00,1}, //03 //gavin 20100817
	{0x9e,0x00,1}, //00 //gavin 20100817
	
	
	/////////////////////////////////////////////////////////////////////
	///////////////////////////YCP_t///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0xb1,0x40,1}, //44 //gavin 20100817
	{0xb2,0x40,1}, //44 //gavin 20100817
	{0xb8,0x20,1}, 
	{0xbe,0x36,1}, 
	{0xbf,0x00,1}, 
	/////////////////////////////////////////////////////////////////////
	///////////////////////////AEC_t///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0xd0,0xc9,1},  
	{0xd1,0x10,1},  
//	{0xd2,0x90,1},  
	{0xd3,0x80,1},  
	{0xd5,0xf2,1}, 
	{0xd6,0x16,1},  
	{0xdb,0x92,1}, 
	{0xdc,0xa5,1},  
	{0xdf,0x23,1},   
	{0xd9,0x00,1},  
	{0xda,0x00,1},  
	{0xe0,0x09,1},

	{0xec,0x20,1},  
	{0xed,0x04,1},  
	{0xee,0xa0,1},  
	{0xef,0x40,1},  
	///////////////////////////////////////////////////////////////////
	///////////////////////////GAMMA//////////////////////////////////
	///////////////////////////////////////////////////////////////////
#if 0	
	{0x9F,0x0F,1},		   
	{0xA0,0x1D,1},  
	{0xA1,0x2D,1},
	{0xA2,0x3B,1},
	{0xA3,0x46,1},
	{0xA4,0x50,1},
	{0xA5,0x5A,1},
	{0xA6,0x6B,1},
	{0xA7,0x7B,1},
	{0xA8,0x8A,1},
	{0xA9,0x98,1},
	{0xAA,0xA5,1},
	{0xAB,0xB2,1},
	{0xAC,0xBE,1},
	{0xAD,0xD5,1},
	{0xAE,0xEB,1},
	{0xAF,0xFE,1},
#endif
	//Y_gamma
	{0xc0,0x00,1},
	{0xc1,0x0B,1},
	{0xc2,0x15,1},
	{0xc3,0x27,1},
	{0xc4,0x39,1},
	{0xc5,0x49,1},
	{0xc6,0x5A,1},
	{0xc7,0x6A,1},
	{0xc8,0x89,1},
	{0xc9,0xA8,1},
	{0xca,0xC6,1},
	{0xcb,0xE3,1},
	{0xcc,0xFF,1},

	/////////////////////////////////////////////////////////////////
	/////////////////////////// ABS_t ///////////////////////////////
	/////////////////////////////////////////////////////////////////
	{0xf0,0x02,1},
	{0xf1,0x01,1},
	{0xf2,0x00,1},  
	{0xf3,0x30,1}, 
	
	/////////////////////////////////////////////////////////////////
	/////////////////////////// Measure Window ///////////////////////
	/////////////////////////////////////////////////////////////////
	{0xf7,0x04,1}, 
	{0xf8,0x02,1}, 
	{0xf9,0x9f,1},
	{0xfa,0x78,1},

	//-----------------------------------------------------------------------------
	{0xfe,0x01,1},

	/////////////////////////////////////////////////////////////////
	///////////////////////////AWB_p/////////////////////////////////
	/////////////////////////////////////////////////////////////////
	{0x00,0xf5,1}, 
	//{0x01,0x0a,1},	
	{0x02,0x1a,1}, 
	{0x0a,0xa0,1}, 
	{0x0b,0x64,1}, //0x60 //gavin 20100817
	{0x0c,0x08,1},
	{0x0e,0x4c,1}, 
	{0x0f,0x39,1}, 
	{0x11,0x3f,1}, 
	{0x12,0x72,1}, 
	{0x13,0x39,1}, //0x13 //gavin 20100817
	{0x14,0x42,1},  
	{0x15,0x43,1}, 
	{0x16,0xc2,1}, 
	{0x17,0xa8,1}, 
	{0x18,0x18,1},  
	{0x19,0x40,1},  
	{0x1a,0xd0,1}, 
	{0x1b,0xf5,1},  

	{0x70,0x40,1}, 
	{0x71,0x58,1},  
	{0x72,0x30,1},  
	{0x73,0x48,1},  
	{0x74,0x20,1},  
	{0x75,0x60,1},  

//*****subsampleratio=2 start****//
//*****subsampleratio=4 start****//
	{0x54,0x44,1},
	{0x55,0x03,1},
	{0x56,0x00,1},
	{0x57,0x00,1},
	{0x58,0x00,1},
	{0x59,0x00,1},
//*****subsampleratio=4 end****//  
//*****subsampleratio=2 end****//  

//set subsample mode here for qqvga
	{0x53,0x82,1}, 
	{0x54,0x44,1}, 
	{0x56,0x00,1}, 
	{0x57,0x00,1}, 
	{0x58,0x00,1}, 
	{0x59,0x00,1}, 
	{0x55,0x80,1}, 


	{0xfe,0x00,1},
#ifdef __PROJECT_G021BQ__
	{0x14,0x10,1}, 
#else
	{0x14,0x13,1}, 
#endif
	{0xd2,0x90,1},   // open AEC at last!

//
	//{  0x1a, 0x16   ,1},  
	//{  0x25, 0x0f   ,1},  

};

PRIVATE const CAM_REG_T RG_VidFormatVga[] = 
{
};

PRIVATE const CAM_REG_T RG_VidFormatQvga[] = 
{
};

PRIVATE const CAM_REG_T RG_VidFormatQqvga[] = 
{
};

typedef struct
{
    // Camera information structure
    char                desc[40];	

    UINT8               snrtype;            //sensor type(RGB or YUV)
    UINT8               pclk;               //use PCLK of sensor
    UINT8               clkcfg;             //[0]: VSync delay enable; [1]: Fifo VSync delay enable; [2]: Use PCLK Negtive Edge.
    HAL_I2C_BPS_T       i2crate;            //I2C rate : KHz				
    UINT8               i2caddress;         //I2C address
    UINT8               i2cispaddress;      //ISP I2C address
    UINT8               pwrcfg;             //sensor power initial configure(SIF REG801 BIT[0]~BIT[2])
    BOOL                rstactiveh;         //sensor reset active hi/low polarity (TRUE = active hi)
    BOOL                snrrst;             //Reset sensor enable

    CAM_MODE_T          cammode;


    BOOL                capturevideo;
    BOOL                captureframe;
    UINT8               numactivebuffers;
    UINT8               currentbuf;

    UINT8               brightness;         //brightness
    UINT8               contrast;           //contrast

    CAM_FORMAT_T        format;
    UINT32              npixels;
    CAM_IMAGE_T         vidbuffer;

    CAM_REG_GROUP_T     standby;            //sensor standby register
    CAM_REG_GROUP_T     Initpoweron;        //SENSOR ISP initial configure

    CAM_REG_GROUP_T     sifpwronseq;        //Sif config sequence(Reg.800 bit0~2) when sensor power on
    CAM_REG_GROUP_T     sifstdbyseq;        //Sif config sequence(Reg.800 bit0~2) when sensor standby
    CAM_REG_GROUP_T     dsif;               //SIF initial configure
    //    TSnrSizeCfgGroup    snrSizeCfg;         //sensor size configure information

    // This 'callback' mechanism is not necessary because the encapsulation is taken
    // care of by the environment
    //    PSensorSetReg       snrSetRegCall;      //set reg callback
    //    PSensorGetReg       snrGetRegCall;
    //    PSnrIdChk           snrIdChkCall;
    //    PSnrMirrorFlip      snrMirrorFlipCall;
    //    PSnrContrast        snrContrastCall;
    //    PSnrBrightness      snrBrightnessCall;
    //    PSnrMode            snrModeCall;
    //    PSnrGetEt           snrGetEt;
    //    PSnrSetEt           snrSetEt;
    //    TFlashParm          flashparm;
    CAM_IRQ_HANDLER_T   camirqhandler;
} CAM_INFO_T;

PRIVATE volatile CAM_INFO_T gSensorInfo =
{
    "pas",      // char desc[40];	

    0,                      // UINT8 snrtype; (rgb)
    1,                      // UINT8 pclk; use or don't use PCLK of sensor???
    0,                      // UINT8 clkcfg; ???
    HAL_I2C_BPS_100K,       // UINT16 i2crate;
    0x40,                   // UINT8 i2caddress; this is the _REAL_ slave address.  
    //  The value written in phase 1 of a write cycle will be 0x42
    //  while the value just before the read will be 0x43
    0x21,                   // UINT8 i2cispaddress;
    0x02,                   // UINT8 pwrcfg;???
    TRUE,                   // BOOL rstactiveh;  // active high
    FALSE,                  // BOOL snrrst;

    CAM_MODE_IDLE,          // cammode

    FALSE,                  // Capture video mode
    FALSE,                  // Capturing single frame
    0,                      // Number of active buffers reserved by the upper layer
    0,                      // current frame buffer

    3,                      // UINT8 brightness;
    4,                      // UINT8 contrast;
    CAM_FORMAT_RGB565,      // Format
    CAM_NPIX_QVGA,           // npixels(VGA, QVGA, QQVGA...)
    NULL,                   // Video Buffer.  First frame buffer for video or image buffer

    {0, NULL},              // CAM_REG_GROUP_T standby;
    // Should start with QQVGA, but for testing, start with VGA
    //    {sizeof(RG_InitPowerOnQqvga) / sizeof(CAM_REG_T), (CAM_REG_T*)&RG_InitPowerOnQqvga}, // CAM_REG_GROUP_T Initpoweron;
    {sizeof(RG_InitPowerOnVga) / sizeof(CAM_REG_T), (CAM_REG_T*)&RG_InitPowerOnVga}, // CAM_REG_GROUP_T Initpoweron;

    {0, NULL},              // CAM_REG_GROUP_T sifpwronseq;
    {0, NULL},              // CAM_REG_GROUP_T sifstdbyseq;
    {0, NULL},              // CAM_REG_GROUP_T dsif; initial value
    NULL                    // IRQ Callback
};

// ############
// Private
// ############

// These are the commands specific to the SCCB
#define PHASE3_WR_PH1   0x11000     // Start & Write    Slave ID
#define PHASE3_WR_PH2   0x1000      // Write            Slave Register Address
#define PHASE3_WR_PH3   0x1100      // Stop & Write     Slave Register Data

#define PHASE2_WR_PH1   0x11000     // Start & Write    Slave ID
#define PHASE2_WR_PH2   0x1100      // Stop & Write     Slave Register Address (to read)

#define PHASE2_RD_PH1   0x11000     // Start & Write    Slave ID
#define PHASE2_RD_PH2   0x111       // Stop & Read & NACK   Slave Register Read Data

PRIVATE VOID camerap_WriteOneReg( UINT8 Addr, UINT8 Data);
PRIVATE VOID camerap_Delay(UINT16 Wait_mS);
PRIVATE VOID camerap_WriteReg(CAM_REG_T RegWrite);
PRIVATE UINT8 camerap_ReadReg(UINT8 Addr);
PRIVATE VOID camerap_SendRgSeq(const CAM_REG_T *RegList, UINT16 Len);
PRIVATE VOID camerap_InteruptHandler(HAL_CAMERA_IRQ_CAUSE_T cause);
PRIVATE UINT8 camerap_GetId(VOID);

