#ifndef __HZ24X24_H__
#define __HZ24X24_H__

struct  typFNT_HZ24                 // ������ģ���ݽṹ 
{
	unsigned char  Index[3];        // ������������	
	unsigned char  Msk[72];        // ���������� 
};

struct  typFNT_HZ24 codeHZ_24[] = 
{
    "��",
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,
    0x00,0x00,0x06,0x00,0x00,0x46,0x00,0x3F,
    0xC4,0x00,0x00,0xC4,0x04,0x00,0x8F,0xFE,
    0x20,0x88,0x08,0x11,0x89,0x90,0x09,0x11,
    0x80,0x05,0x21,0x80,0x02,0x21,0x80,0x03,
    0x03,0x80,0x05,0x82,0x80,0x05,0x82,0x40,
    0x08,0xC2,0x40,0x08,0xC4,0x60,0x10,0x4C,
    0x20,0x20,0x08,0x30,0x40,0x10,0x18,0x00,
    0x60,0x0E,0x00,0x80,0x00,0x00,0x00,0x00,

    "ӭ",
    0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x02,
    0x00,0x0C,0x0E,0x00,0x06,0x72,0x08,0x04,
    0x41,0xFC,0x00,0x41,0x08,0x00,0x41,0x08,
    0x04,0x41,0x08,0x7E,0x41,0x08,0x04,0x41,
    0x08,0x04,0x41,0x08,0x04,0x41,0x08,0x04,
    0x45,0x08,0x04,0x59,0x08,0x04,0x61,0x78,
    0x04,0x41,0x18,0x04,0x01,0x00,0x1A,0x01,
    0x00,0x71,0x00,0x00,0x60,0xE0,0x02,0x00,
    0x3F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,

    "ʹ",
    0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x81,
    0x00,0x03,0x01,0x00,0x03,0x01,0x04,0x02,
    0xFF,0xFE,0x06,0x01,0x00,0x04,0x01,0x00,
    0x0E,0x21,0x18,0x0E,0x3F,0xE8,0x16,0x21,
    0x08,0x26,0x21,0x08,0x26,0x21,0x08,0x46,
    0x3F,0xF8,0x06,0x21,0x00,0x06,0x13,0x00,
    0x06,0x12,0x00,0x06,0x0A,0x00,0x06,0x06,
    0x00,0x06,0x06,0x00,0x06,0x0F,0x00,0x06,
    0x10,0xE0,0x06,0x60,0x3C,0x01,0x80,0x00,

    "��",
    0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,
    0x10,0x0F,0xFF,0xF8,0x0C,0x08,0x10,0x0C,
    0x08,0x10,0x0C,0x08,0x10,0x0C,0x08,0x10,
    0x0C,0x08,0x10,0x0F,0xFF,0xF0,0x08,0x08,
    0x10,0x08,0x08,0x10,0x08,0x08,0x10,0x08,
    0x08,0x10,0x0F,0xFF,0xF0,0x08,0x08,0x10,
    0x08,0x08,0x10,0x08,0x08,0x10,0x10,0x18,
    0x10,0x10,0x18,0x10,0x20,0x18,0x10,0x20,
    0x18,0xF0,0x40,0x00,0x30,0x00,0x00,0x00


};

#endif