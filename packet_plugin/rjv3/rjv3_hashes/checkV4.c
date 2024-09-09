#include "rjwhirlpool.h"
#include "rjmd5.h"
#include "rjtiger.h"
#include "rjripemd128.h"
#include "rjsha1.h"
#include "md5.h"
#include "checkV4.h"
#include <stdio.h>
#include <string.h>

const unsigned char array[1820] =
{
    0x20, 0x12, 0x10, 0x26, 0x13, 0x44, 0x01, 0x20, 0xD4, 0xF6, 0x7C, 0x00, 0xF8, 0xFA, 0x7C, 0x99,
    0x0C, 0x82, 0x4C, 0x00, 0xDC, 0x00, 0x21, 0x01, 0x08, 0xFB, 0x7C, 0x00, 0xB2, 0x26, 0x40, 0x58,
    0xE4, 0x6E, 0x21, 0x01, 0xD4, 0xF6, 0x7C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x97,
    0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x41, 0x00, 0x00, 0xF0, 0x41,
    0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0xC0, 0x15, 0x44, 0x00, 0x00, 0x16, 0x44,
    0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xD7, 0xE1, 0x40,
    0x00, 0x00, 0x00, 0x00, 0xC0, 0x52, 0xE3, 0x40, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xD7, 0xE1, 0x40,
    0x5A, 0x00, 0x00, 0x00, 0x00, 0x6F, 0x21, 0x01, 0x00, 0x00, 0x00, 0x00, 0xA8, 0xFC, 0x7C, 0x00,
    0xCA, 0x26, 0x40, 0x00, 0x5E, 0x2E, 0x00, 0x00, 0x08, 0xF9, 0x7C, 0x00, 0x67, 0x69, 0x4C, 0x01,
    0x30, 0x31, 0x40, 0x00, 0x89, 0x2E, 0x40, 0x00, 0x97, 0x2E, 0x40, 0x00, 0x00, 0x35, 0x40, 0x00,
    0x87, 0x69, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x75, 0x40, 0x00, 0x14, 0x6F, 0x21, 0x01,
    0x08, 0x00, 0x7C, 0x00, 0x84, 0xF7, 0x7C, 0x00, 0x90, 0xF7, 0x7C, 0x00, 0x08, 0xF9, 0x7C, 0x00,
    0xE8, 0x1E, 0x98, 0x81, 0x10, 0xFB, 0x06, 0xC9, 0xED, 0xB7, 0xDD, 0xD6, 0xA4, 0xF9, 0x7C, 0x00,
    0x10, 0x00, 0x7C, 0x00, 0x3C, 0xF8, 0x7C, 0x00, 0x14, 0xF8, 0x7C, 0x00, 0xE0, 0xFA, 0x7C, 0x00,
    0xD5, 0x68, 0xF7, 0xBF, 0x10, 0xFB, 0x00, 0x00, 0x24, 0xF8, 0x7C, 0x00, 0xEB, 0x82, 0xF8, 0xBF,
    0x08, 0xF9, 0x7C, 0x00, 0x10, 0xFB, 0x7C, 0x00, 0x3C, 0xF8, 0x7C, 0x00, 0x14, 0xF8, 0x7C, 0x00,
    0x5E, 0x69, 0x4C, 0x00, 0xCC, 0xF9, 0x7C, 0x00, 0x7C, 0xF9, 0x7C, 0x00, 0xE4, 0x6E, 0x21, 0x01,
    0x1A, 0xD0, 0xA1, 0xCD, 0xF5, 0x20, 0xC9, 0xED, 0xB7, 0xDD, 0xD6, 0xA4, 0x34, 0x31, 0x30, 0x31,
    0x30, 0x33, 0x37, 0x39, 0x31, 0x30, 0x32, 0x34, 0x31, 0x34, 0x35, 0x00, 0x08, 0xF9, 0x7C, 0x00,
    0x20, 0xF8, 0x7C, 0x00, 0x2E, 0xDE, 0xF9, 0xBF, 0x08, 0xF9, 0x7C, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x14, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31,
    0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x00, 0x00, 0x00, 0x04, 0x30, 0x30, 0x30,
    0x32, 0x00, 0x00, 0x00, 0xD4, 0xF6, 0x7C, 0x00, 0xF8, 0xFA, 0x7C, 0x00, 0x0C, 0x82, 0x4C, 0x00,
    0xDC, 0x00, 0x21, 0x01, 0x08, 0xFB, 0x7C, 0x00, 0xB2, 0x26, 0x40, 0x00, 0xE4, 0x6E, 0x21, 0x01,
    0xD4, 0xF6, 0x7C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x42, 0x00, 0x00, 0x70, 0x42, 0x00, 0x00, 0x40, 0x40,
    0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x96, 0x44, 0x00, 0x00, 0x96, 0x44, 0x00, 0x00, 0x80, 0x3F,
    0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xD7, 0xE1, 0x40, 0x00, 0x00, 0x00, 0x00,
    0xC0, 0x52, 0xE3, 0x40, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xD7, 0xE1, 0x40, 0x5A, 0x00, 0x00, 0x00,
    0x00, 0x6F, 0x21, 0x01, 0x00, 0x00, 0x00, 0x00, 0xA8, 0xFC, 0x7C, 0x00, 0xCA, 0x26, 0x40, 0x00,
    0x5E, 0x2E, 0x00, 0x00, 0x08, 0xF9, 0x7C, 0x00, 0x67, 0x69, 0x4C, 0x01, 0x30, 0x31, 0x40, 0x00,
    0x89, 0x2E, 0x40, 0x00, 0x97, 0x2E, 0x40, 0x00, 0x00, 0x35, 0x40, 0x00, 0x87, 0x69, 0x4C, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x06, 0x75, 0x40, 0x00, 0x14, 0x6F, 0x21, 0x01, 0x08, 0x00, 0x7C, 0x00,
    0x84, 0xF7, 0x7C, 0x00, 0x90, 0xF7, 0x7C, 0x00, 0x08, 0xF9, 0x7C, 0x00, 0xE8, 0x1E, 0x98, 0x81,
    0x10, 0xFB, 0x06, 0xC9, 0xED, 0xB7, 0xDD, 0xD6, 0xA4, 0xF9, 0x7C, 0x00, 0x10, 0x00, 0x7C, 0x00,
    0x3C, 0xF8, 0x7C, 0x00, 0x14, 0xF8, 0x7C, 0x00, 0xE0, 0xFA, 0x7C, 0x00, 0xD5, 0x68, 0xF7, 0xBF,
    0x10, 0xFB, 0x00, 0x00, 0x24, 0xF8, 0x7C, 0x00, 0xEB, 0x82, 0xF8, 0xBF, 0x08, 0xF9, 0x7C, 0x00,
    0x10, 0xFB, 0x7C, 0x00, 0x3C, 0xF8, 0x7C, 0x00, 0x14, 0xF8, 0x7C, 0x00, 0x5E, 0x69, 0x4C, 0x00,
    0xCC, 0xF9, 0x7C, 0x00, 0x7C, 0xF9, 0x7C, 0x00, 0xE4, 0x6E, 0x21, 0x01, 0x1A, 0xD0, 0xA1, 0xD5,
    0xC5, 0x20, 0xC9, 0xED, 0xB7, 0xDD, 0xD6, 0xA4, 0x35, 0x31, 0x30, 0x31, 0x30, 0x33, 0x37, 0x39,
    0x31, 0x30, 0x32, 0x34, 0x31, 0x31, 0x34, 0x00, 0x08, 0xF9, 0x7C, 0x00, 0x20, 0xF8, 0x7C, 0x00,
    0x2E, 0xDE, 0xF9, 0xBF, 0x08, 0xF9, 0x7C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x14, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31,
    0x31, 0x31, 0x31, 0x31, 0x31, 0x00, 0x00, 0x00, 0x04, 0x30, 0x30, 0x30, 0x33, 0x00, 0x00, 0x00,
    0xD4, 0xF6, 0x7C, 0x00, 0xF8, 0xFA, 0x7C, 0x00, 0x0C, 0x82, 0x4C, 0x00, 0xDC, 0x00, 0x21, 0x01,
    0x08, 0xFB, 0x7C, 0x00, 0xB2, 0x26, 0x40, 0x00, 0xE4, 0x6E, 0x21, 0x01, 0xD4, 0xF6, 0x7C, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x70, 0x41, 0x00, 0x00, 0x70, 0x41, 0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x00, 0x40,
    0x00, 0x00, 0x96, 0x43, 0x00, 0x00, 0x96, 0x43, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F,
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xD7, 0xE1, 0x40, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x52, 0xE3, 0x40,
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xD7, 0xE1, 0x40, 0x5A, 0x00, 0x00, 0x00, 0x00, 0x6F, 0x21, 0x01,
    0x00, 0x00, 0x00, 0x00, 0xA8, 0xFC, 0x7C, 0x00, 0xCA, 0x26, 0x40, 0x00, 0x5E, 0x2E, 0x00, 0x00,
    0x08, 0xF9, 0x7C, 0x00, 0x67, 0x69, 0x4C, 0x01, 0x30, 0x31, 0x40, 0x00, 0x89, 0x2E, 0x40, 0x00,
    0x97, 0x2E, 0x40, 0x00, 0x00, 0x35, 0x40, 0x00, 0x87, 0x69, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x06, 0x75, 0x40, 0x00, 0x14, 0x6F, 0x21, 0x01, 0x08, 0x00, 0x7C, 0x00, 0x84, 0xF7, 0x7C, 0x00,
    0x90, 0xF7, 0x7C, 0x00, 0x08, 0xF9, 0x7C, 0x00, 0xE8, 0x1E, 0x98, 0x81, 0x10, 0xFB, 0x06, 0xC9,
    0xED, 0xB7, 0xDD, 0xD6, 0xA4, 0xF9, 0x7C, 0x00, 0x10, 0x00, 0x7C, 0x00, 0x3C, 0xF8, 0x7C, 0x00,
    0x14, 0xF8, 0x7C, 0x00, 0xE0, 0xFA, 0x7C, 0x00, 0xD5, 0x68, 0xF7, 0xBF, 0x10, 0xFB, 0x00, 0x00,
    0x24, 0xF8, 0x7C, 0x00, 0xEB, 0x82, 0xF8, 0xBF, 0x08, 0xF9, 0x7C, 0x00, 0x10, 0xFB, 0x7C, 0x00,
    0x3C, 0xF8, 0x7C, 0x00, 0x14, 0xF8, 0x7C, 0x00, 0x5E, 0x69, 0x4C, 0x00, 0xCC, 0xF9, 0x7C, 0x00,
    0x7C, 0xF9, 0x7C, 0x00, 0xE4, 0x6E, 0x21, 0x01, 0x1A, 0xD0, 0xA1, 0xC2, 0xED, 0x20, 0xC9, 0xED,
    0xB7, 0xDD, 0xD6, 0xA4, 0x34, 0x31, 0x30, 0x31, 0x30, 0x33, 0x38, 0x31, 0x31, 0x30, 0x32, 0x34,
    0x31, 0x38, 0x37, 0x00, 0x08, 0xF9, 0x7C, 0x00, 0x20, 0xF8, 0x7C, 0x00, 0x2E, 0xDE, 0xF9, 0xBF,
    0x08, 0xF9, 0x7C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x31, 0x31, 0x31,
    0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31,
    0x31, 0x00, 0x00, 0x00, 0x08, 0x57, 0x61, 0x6E, 0x67, 0x44, 0x6F, 0x6E, 0x67, 0xF6, 0x7C, 0x00,
    0xF8, 0xFA, 0x7C, 0x00, 0x0C, 0x82, 0x4C, 0x00, 0xDC, 0x00, 0x21, 0x01, 0x08, 0xFB, 0x7C, 0x00,
    0xB2, 0x26, 0x40, 0x00, 0xE4, 0x6E, 0x21, 0x01, 0xD4, 0xF6, 0x7C, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x42,
    0x00, 0x00, 0xC8, 0x42, 0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x16, 0x45,
    0x00, 0x00, 0x16, 0x45, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00,
    0xC0, 0xD7, 0xE1, 0x40, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x52, 0xE3, 0x40, 0x00, 0x00, 0x00, 0x00,
    0xC0, 0xD7, 0xE1, 0x40, 0x5A, 0x00, 0x00, 0x00, 0x00, 0x6F, 0x21, 0x01, 0x00, 0x00, 0x00, 0x00,
    0xA8, 0xFC, 0x7C, 0x00, 0xCA, 0x26, 0x40, 0x00, 0x5E, 0x2E, 0x00, 0x00, 0x08, 0xF9, 0x7C, 0x00,
    0x67, 0x69, 0x4C, 0x01, 0x30, 0x31, 0x40, 0x00, 0x89, 0x2E, 0x40, 0x00, 0x97, 0x2E, 0x40, 0x00,
    0x00, 0x35, 0x40, 0x00, 0x87, 0x69, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x75, 0x40, 0x00,
    0x14, 0x6F, 0x21, 0x01, 0x08, 0x00, 0x7C, 0x00, 0x84, 0xF7, 0x7C, 0x00, 0x90, 0xF7, 0x7C, 0x00,
    0x08, 0xF9, 0x7C, 0x00, 0xE8, 0x1E, 0x98, 0x81, 0x10, 0xFB, 0x06, 0xC9, 0xED, 0xB7, 0xDD, 0xD6,
    0xA4, 0xF9, 0x7C, 0x00, 0x10, 0x00, 0x7C, 0x00, 0x3C, 0xF8, 0x7C, 0x00, 0x14, 0xF8, 0x7C, 0x00,
    0xE0, 0xFA, 0x7C, 0x00, 0xD5, 0x68, 0xF7, 0xBF, 0x10, 0xFB, 0x00, 0x00, 0x24, 0xF8, 0x7C, 0x00,
    0xEB, 0x82, 0xF8, 0xBF, 0x08, 0xF9, 0x7C, 0x00, 0x10, 0xFB, 0x7C, 0x00, 0x3C, 0xF8, 0x7C, 0x00,
    0x14, 0xF8, 0x7C, 0x00, 0x5E, 0x69, 0x4C, 0x00, 0xCC, 0xF9, 0x7C, 0x00, 0x7C, 0xF9, 0x7C, 0x00,
    0xE4, 0x6E, 0x21, 0x01, 0x00, 0xD0, 0xA1, 0xC2, 0xED, 0x20, 0xC9, 0xED, 0xB7, 0xDD, 0xD6, 0xA4,
    0x34, 0x31, 0x30, 0x31, 0x30, 0x33, 0x38, 0x31, 0x31, 0x30, 0x32, 0x34, 0x31, 0x38, 0x37, 0x00,
    0x08, 0xF9, 0x7C, 0x00, 0x20, 0xF8, 0x7C, 0x00, 0x2E, 0xDE, 0xF9, 0xBF, 0x08, 0xF9, 0x7C, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31,
    0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x00, 0x00, 0x00,
    0x03, 0x72, 0x65, 0x64, 0x67, 0x44, 0x6F, 0x6E, 0x67, 0xF6, 0x7C, 0x00, 0xF8, 0xFA, 0x7C, 0x00,
    0x0C, 0x82, 0x4C, 0x00, 0xDC, 0x06, 0x3A, 0x30, 0x3A, 0x3D, 0x2C, 0x24, 0xB2, 0x26, 0x40, 0x00,
    0xE4, 0x6E, 0x21, 0x01, 0xD4, 0xF6, 0x7C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x41, 0x00, 0x00, 0xF0, 0x41,
    0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x16, 0x44, 0x00, 0x00, 0x16, 0x44,
    0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xD7, 0xE1, 0x40,
    0x00, 0x00, 0x00, 0x00, 0xC0, 0x52, 0xE3, 0x40, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xD7, 0xE1, 0x40,
    0x5A, 0x00, 0x00, 0x00, 0x00, 0x6F, 0x21, 0x01, 0x00, 0x00, 0x00, 0x00, 0xA8, 0xFC, 0x7C, 0x00,
    0xCA, 0x26, 0x40, 0x00, 0x5E, 0x2E, 0x00, 0x00, 0x08, 0xF9, 0x7C, 0x00, 0x67, 0x69, 0x4C, 0x01,
    0x30, 0x31, 0x40, 0x00, 0x89, 0x2E, 0x40, 0x00, 0x97, 0x2E, 0x40, 0x00, 0x00, 0x35, 0x40, 0x00,
    0x87, 0x69, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x75, 0x40, 0x00, 0x14, 0x6F, 0x21, 0x01,
    0x08, 0x00, 0x7C, 0x00, 0x84, 0xF7, 0x7C, 0x00, 0x90, 0xF7, 0x7C, 0x00, 0x08, 0xF9, 0x7C, 0x00,
    0xE8, 0x1E, 0x98, 0x81, 0x10, 0xFB, 0x06, 0xC9, 0xED, 0xB7, 0xDD, 0xD6, 0xA4, 0xF9, 0x7C, 0x00,
    0x10, 0x00, 0x7C, 0x00, 0x3C, 0xF8, 0x7C, 0x00, 0x14, 0xF8, 0x7C, 0x00, 0xE0, 0xFA, 0x7C, 0x00,
    0xD5, 0x68, 0xF7, 0xBF, 0x10, 0xFB, 0x00, 0x00, 0x24, 0xF8, 0x7C, 0x00, 0xEB, 0x82, 0xF8, 0xBF,
    0x08, 0xF9, 0x7C, 0x00, 0x10, 0xFB, 0x7C, 0x00, 0x3C, 0xF8, 0x7C, 0x00, 0x14, 0xF8, 0x7C, 0x00,
    0x5E, 0x69, 0x4C, 0x00, 0xCC, 0xF9, 0x7C, 0x00, 0x7C, 0xF9, 0x7C, 0x00, 0xE4, 0x6E, 0x21, 0x01,
    0x00, 0xD0, 0xA1, 0xC2, 0xED, 0x20, 0xC9, 0xED, 0xB7, 0xDD, 0xD6, 0xA4, 0x34, 0x31, 0x30, 0x31,
    0x30, 0x33, 0x38, 0x31, 0x31, 0x30, 0x32, 0x34, 0x31, 0x38, 0x37, 0x00, 0x08, 0xF9, 0x7C, 0x00,
    0x20, 0xF8, 0x7C, 0x00, 0x2E, 0xDE, 0xF9, 0xBF, 0x08, 0xF9, 0x7C, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x14, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31,
    0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x00, 0x00, 0x00
};

const unsigned char array_1[2035] =
{
	0x20, 0x12, 0x10, 0x26, 0x13, 0x44, 0x01, 0x20, 0x63, 0x70, 0x70, 0x20, 0x3A, 0x20, 0x44, 0x65,
	0x66, 0x69, 0x6E, 0x65, 0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x6C, 0x61, 0x73, 0x73, 0x20,
	0x62, 0x65, 0x68, 0x61, 0x76, 0x69, 0x6F, 0x72, 0x73, 0x20, 0x66, 0x6F, 0x72, 0x20, 0x74, 0x68,
	0x65, 0x20, 0x61, 0x70, 0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x2E, 0x0D, 0x0A,
	0x2F, 0x2F, 0x0D, 0x0A, 0x0D, 0x0A, 0x23, 0x69, 0x6E, 0x63, 0x6C, 0x75, 0x64, 0x65, 0x20, 0x22,
	0x73, 0x74, 0x64, 0x61, 0x66, 0x78, 0x2E, 0x68, 0x22, 0x0D, 0x0A, 0x23, 0x69, 0x6E, 0x63, 0x6C,
	0x75, 0x64, 0x65, 0x20, 0x22, 0x54, 0x65, 0x73, 0x74, 0x2E, 0x68, 0x22, 0x0D, 0x0A, 0x23, 0x69,
	0x6E, 0x63, 0x6C, 0x75, 0x64, 0x65, 0x20, 0x22, 0x54, 0x65, 0x73, 0x74, 0x44, 0x6C, 0x67, 0x2E,
	0x68, 0x22, 0x0D, 0x0A, 0x0D, 0x0A, 0x23, 0x69, 0x66, 0x64, 0x65, 0x66, 0x20, 0x5F, 0x44, 0x45,
	0x42, 0x55, 0x47, 0x0D, 0x0A, 0x23, 0x64, 0x65, 0x66, 0x69, 0x6E, 0x65, 0x20, 0x6E, 0x65, 0x77,
	0x20, 0x44, 0x45, 0x42, 0x55, 0x47, 0x5F, 0x4E, 0x45, 0x57, 0x0D, 0x0A, 0x23, 0x75, 0x6E, 0x64,
	0x65, 0x66, 0x20, 0x54, 0x48, 0x49, 0x53, 0x5F, 0x46, 0x49, 0x4C, 0x45, 0x0D, 0x0A, 0x73, 0x74,
	0x61, 0x74, 0x69, 0x63, 0x20, 0x63, 0x68, 0x61, 0x72, 0x20, 0x54, 0x48, 0x49, 0x53, 0x5F, 0x46,
	0x49, 0x4C, 0x45, 0x5B, 0x5D, 0x20, 0x3D, 0x20, 0x5F, 0x5F, 0x46, 0x49, 0x4C, 0x45, 0x5F, 0x5F,
	0x3B, 0x0D, 0x0A, 0x23, 0x65, 0x6E, 0x64, 0x69, 0x66, 0x0D, 0x0A, 0x0D, 0x0A, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x0D, 0x0A, 0x2F, 0x2F, 0x20, 0x43,
	0x54, 0x65, 0x73, 0x74, 0x41, 0x70, 0x70, 0x0D, 0x0A, 0x0D, 0x0A, 0x42, 0x45, 0x47, 0x49, 0x4E,
	0x5F, 0x4D, 0x45, 0x53, 0x53, 0x41, 0x47, 0x45, 0x5F, 0x4D, 0x41, 0x50, 0x28, 0x43, 0x54, 0x65,
	0x73, 0x74, 0x41, 0x70, 0x70, 0x2C, 0x20, 0x43, 0x57, 0x69, 0x6E, 0x41, 0x70, 0x70, 0x29, 0x0D,
	0x0A, 0x09, 0x2F, 0x2F, 0x7B, 0x7B, 0x41, 0x46, 0x58, 0x5F, 0x4D, 0x53, 0x47, 0x5F, 0x4D, 0x41,
	0x50, 0x28, 0x43, 0x54, 0x65, 0x73, 0x74, 0x41, 0x70, 0x70, 0x29, 0x0D, 0x0A, 0x09, 0x09, 0x2F,
	0x2F, 0x20, 0x4E, 0x4F, 0x54, 0x45, 0x20, 0x2D, 0x20, 0x74, 0x68, 0x65, 0x20, 0x43, 0x6C, 0x61,
	0x73, 0x73, 0x57, 0x69, 0x7A, 0x61, 0x72, 0x64, 0x20, 0x77, 0x69, 0x6C, 0x6C, 0x20, 0x61, 0x64,
	0x64, 0x20, 0x61, 0x6E, 0x64, 0x20, 0x72, 0x65, 0x6D, 0x6F, 0x76, 0x65, 0x20, 0x6D, 0x61, 0x70,
	0x70, 0x69, 0x6E, 0x67, 0x20, 0x6D, 0x61, 0x63, 0x72, 0x6F, 0x73, 0x20, 0x68, 0x65, 0x72, 0x65,
	0x2E, 0x0D, 0x0A, 0x09, 0x09, 0x2F, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x44, 0x4F, 0x20, 0x4E, 0x4F,
	0x54, 0x20, 0x45, 0x44, 0x49, 0x54, 0x20, 0x77, 0x68, 0x61, 0x74, 0x20, 0x79, 0x6F, 0x75, 0x20,
	0x73, 0x65, 0x65, 0x20, 0x69, 0x6E, 0x20, 0x74, 0x68, 0x65, 0x73, 0x65, 0x20, 0x62, 0x6C, 0x6F,
	0x63, 0x6B, 0x73, 0x20, 0x6F, 0x66, 0x20, 0x67, 0x65, 0x6E, 0x65, 0x72, 0x61, 0x74, 0x65, 0x64,
	0x20, 0x63, 0x6F, 0x64, 0x65, 0x21, 0x0D, 0x0A, 0x09, 0x2F, 0x2F, 0x7D, 0x7D, 0x41, 0x46, 0x58,
	0x5F, 0x4D, 0x53, 0x47, 0x0D, 0x0A, 0x09, 0x4F, 0x4E, 0x5F, 0x43, 0x4F, 0x4D, 0x4D, 0x41, 0x4E,
	0x44, 0x28, 0x49, 0x44, 0x5F, 0x48, 0x45, 0x4C, 0x50, 0x2C, 0x20, 0x43, 0x57, 0x69, 0x6E, 0x41,
	0x70, 0x70, 0x3A, 0x3A, 0x4F, 0x6E, 0x48, 0x65, 0x6C, 0x70, 0x29, 0x0D, 0x0A, 0x45, 0x4E, 0x44,
	0x5F, 0x4D, 0x45, 0x53, 0x53, 0x41, 0x47, 0x45, 0x5F, 0x4D, 0x41, 0x50, 0x28, 0x29, 0x0D, 0x0A,
	0x0D, 0x0A, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x0D,
	0x0A, 0x2F, 0x2F, 0x20, 0x43, 0x54, 0x65, 0x73, 0x74, 0x41, 0x70, 0x70, 0x20, 0x63, 0x6F, 0x6E,
	0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x0D, 0x0A, 0x0D, 0x0A, 0x43, 0x54, 0x65,
	0x73, 0x74, 0x41, 0x70, 0x70, 0x3A, 0x3A, 0x43, 0x54, 0x65, 0x73, 0x74, 0x41, 0x70, 0x70, 0x28,
	0x29, 0x0D, 0x0A, 0x7B, 0x0D, 0x0A, 0x09, 0x2F, 0x2F, 0x20, 0x54, 0x4F, 0x44, 0x4F, 0x3A, 0x20,
	0x61, 0x64, 0x64, 0x20, 0x63, 0x6F, 0x6E, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x69, 0x6F, 0x6E,
	0x20, 0x63, 0x6F, 0x64, 0x65, 0x20, 0x68, 0x65, 0x72, 0x65, 0x2C, 0x0D, 0x0A, 0x09, 0x2F, 0x2F,
	0x20, 0x50, 0x6C, 0x61, 0x63, 0x65, 0x20, 0x61, 0x6C, 0x6C, 0x20, 0x73, 0x69, 0x67, 0x6E, 0x69,
	0x66, 0x69, 0x63, 0x61, 0x6E, 0x74, 0x20, 0x69, 0x6E, 0x69, 0x74, 0x69, 0x61, 0x6C, 0x69, 0x7A,
	0x61, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x69, 0x6E, 0x20, 0x49, 0x6E, 0x69, 0x74, 0x49, 0x6E, 0x73,
	0x74, 0x61, 0x6E, 0x63, 0x65, 0x0D, 0x0A, 0x7D, 0x0D, 0x0A, 0x0D, 0x0A, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x0D, 0x0A, 0x2F, 0x2F, 0x20, 0x54, 0x68,
	0x65, 0x20, 0x6F, 0x6E, 0x65, 0x20, 0x61, 0x6E, 0x64, 0x20, 0x6F, 0x6E, 0x6C, 0x79, 0x20, 0x43,
	0x54, 0x65, 0x73, 0x74, 0x41, 0x70, 0x70, 0x20, 0x6F, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x0D, 0x0A,
	0x0D, 0x0A, 0x43, 0x54, 0x65, 0x73, 0x74, 0x41, 0x70, 0x70, 0x20, 0x74, 0x68, 0x65, 0x41, 0x70,
	0x70, 0x3B, 0x0D, 0x0A, 0x0D, 0x0A, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F, 0x2F,
	0x2F, 0x2F, 0x2F, 0x0D, 0x0A, 0x2F, 0x2F, 0x20, 0x43, 0x54, 0x65, 0x73, 0x74, 0x41, 0x70, 0x70,
	0x20, 0x69, 0x6E, 0x69, 0x74, 0x69, 0x61, 0x6C, 0x69, 0x7A, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x0D,
	0x0A, 0x0D, 0x0A, 0x42, 0x4F, 0x4F, 0x4C, 0x20, 0x43, 0x54, 0x65, 0x73, 0x74, 0x41, 0x70, 0x70,
	0x3A, 0x3A, 0x49, 0x6E, 0x69, 0x74, 0x49, 0x6E, 0x73, 0x74, 0x61, 0x6E, 0x63, 0x65, 0x28, 0x29,
	0x0D, 0x0A, 0x7B, 0x0D, 0x0A, 0x09, 0x41, 0x66, 0x78, 0x45, 0x6E, 0x61, 0x62, 0x6C, 0x65, 0x43,
	0x6F, 0x6E, 0x74, 0x72, 0x6F, 0x6C, 0x43, 0x6F, 0x6E, 0x74, 0x61, 0x69, 0x6E, 0x65, 0x72, 0x28,
	0x29, 0x3B, 0x0D, 0x0A, 0x0D, 0x0A, 0x09, 0x2F, 0x2F, 0x20, 0x53, 0x74, 0x61, 0x6E, 0x64, 0x61,
	0x72, 0x64, 0x20, 0x69, 0x6E, 0x69, 0x74, 0x69, 0x61, 0x6C, 0x69, 0x7A, 0x61, 0x74, 0x69, 0x6F,
	0x6E, 0x0D, 0x0A, 0x09, 0x2F, 0x2F, 0x20, 0x49, 0x66, 0x20, 0x79, 0x6F, 0x75, 0x20, 0x61, 0x72,
	0x65, 0x20, 0x6E, 0x6F, 0x74, 0x20, 0x75, 0x73, 0x69, 0x6E, 0x67, 0x20, 0x74, 0x68, 0x65, 0x73,
	0x65, 0x20, 0x66, 0x65, 0x61, 0x74, 0x75, 0x72, 0x65, 0x73, 0x20, 0x61, 0x6E, 0x64, 0x20, 0x77,
	0x69, 0x73, 0x68, 0x20, 0x74, 0x6F, 0x20, 0x72, 0x65, 0x64, 0x75, 0x63, 0x65, 0x20, 0x74, 0x68,
	0x65, 0x20, 0x73, 0x69, 0x7A, 0x65, 0x0D, 0x0A, 0x09, 0x2F, 0x2F, 0x20, 0x20, 0x6F, 0x66, 0x20,
	0x79, 0x6F, 0x75, 0x72, 0x20, 0x66, 0x69, 0x6E, 0x61, 0x6C, 0x20, 0x65, 0x78, 0x65, 0x63, 0x75,
	0x74, 0x61, 0x62, 0x6C, 0x65, 0x2C, 0x20, 0x79, 0x6F, 0x75, 0x20, 0x73, 0x68, 0x6F, 0x75, 0x6C,
	0x64, 0x20, 0x72, 0x65, 0x6D, 0x6F, 0x76, 0x65, 0x20, 0x66, 0x72, 0x6F, 0x6D, 0x20, 0x74, 0x68,
	0x65, 0x20, 0x66, 0x6F, 0x6C, 0x6C, 0x6F, 0x77, 0x69, 0x6E, 0x67, 0x0D, 0x0A, 0x09, 0x2F, 0x2F,
	0x20, 0x20, 0x74, 0x68, 0x65, 0x20, 0x73, 0x70, 0x65, 0x63, 0x69, 0x66, 0x69, 0x63, 0x20, 0x69,
	0x6E, 0x69, 0x74, 0x69, 0x61, 0x6C, 0x69, 0x7A, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x72, 0x6F,
	0x75, 0x74, 0x69, 0x6E, 0x65, 0x73, 0x20, 0x79, 0x6F, 0x75, 0x20, 0x64, 0x6F, 0x20, 0x6E, 0x6F,
	0x74, 0x20, 0x6E, 0x65, 0x65, 0x64, 0x2E, 0x0D, 0x0A, 0x0D, 0x0A, 0x23, 0x69, 0x66, 0x64, 0x65,
	0x66, 0x20, 0x5F, 0x41, 0x46, 0x58, 0x44, 0x4C, 0x4C, 0x0D, 0x0A, 0x09, 0x45, 0x6E, 0x61, 0x62,
	0x6C, 0x65, 0x33, 0x64, 0x43, 0x6F, 0x6E, 0x74, 0x72, 0x6F, 0x6C, 0x73, 0x28, 0x29, 0x3B, 0x09,
	0x09, 0x09, 0x2F, 0x2F, 0x20, 0x43, 0x61, 0x6C, 0x6C, 0x20, 0x74, 0x68, 0x69, 0x73, 0x20, 0x77,
	0x68, 0x65, 0x6E, 0x20, 0x75, 0x73, 0x69, 0x6E, 0x67, 0x20, 0x4D, 0x46, 0x43, 0x20, 0x69, 0x6E,
	0x20, 0x61, 0x20, 0x73, 0x68, 0x61, 0x72, 0x65, 0x64, 0x20, 0x44, 0x4C, 0x4C, 0x0D, 0x0A, 0x23,
	0x65, 0x6C, 0x73, 0x65, 0x0D, 0x0A, 0x09, 0x45, 0x6E, 0x61, 0x62, 0x6C, 0x65, 0x33, 0x64, 0x43,
	0x6F, 0x6E, 0x74, 0x72, 0x6F, 0x6C, 0x73, 0x53, 0x74, 0x61, 0x74, 0x69, 0x63, 0x28, 0x29, 0x3B,
	0x09, 0x2F, 0x2F, 0x20, 0x43, 0x61, 0x6C, 0x6C, 0x20, 0x74, 0x68, 0x69, 0x73, 0x20, 0x77, 0x68,
	0x65, 0x6E, 0x20, 0x6C, 0x69, 0x6E, 0x6B, 0x69, 0x6E, 0x67, 0x20, 0x74, 0x6F, 0x20, 0x4D, 0x46,
	0x43, 0x20, 0x73, 0x74, 0x61, 0x74, 0x69, 0x63, 0x61, 0x6C, 0x6C, 0x79, 0x0D, 0x0A, 0x23, 0x65,
	0x6E, 0x64, 0x69, 0x66, 0x0D, 0x0A, 0x0D, 0x0A, 0x09, 0x43, 0x54, 0x65, 0x73, 0x74, 0x44, 0x6C,
	0x67, 0x20, 0x64, 0x6C, 0x67, 0x3B, 0x0D, 0x0A, 0x09, 0x6D, 0x5F, 0x70, 0x4D, 0x61, 0x69, 0x6E,
	0x57, 0x6E, 0x64, 0x20, 0x3D, 0x20, 0x26, 0x64, 0x6C, 0x67, 0x3B, 0x0D, 0x0A, 0x09, 0x69, 0x6E,
	0x74, 0x20, 0x6E, 0x52, 0x65, 0x73, 0x70, 0x6F, 0x6E, 0x73, 0x65, 0x20, 0x3D, 0x20, 0x64, 0x6C,
	0x67, 0x2E, 0x44, 0x6F, 0x4D, 0x6F, 0x64, 0x61, 0x6C, 0x28, 0x29, 0x3B, 0x0D, 0x0A, 0x09, 0x69,
	0x66, 0x20, 0x28, 0x6E, 0x52, 0x65, 0x73, 0x70, 0x6F, 0x6E, 0x73, 0x65, 0x20, 0x3D, 0x3D, 0x20,
	0x49, 0x44, 0x4F, 0x4B, 0x29, 0x0D, 0x0A, 0x09, 0x7B, 0x0D, 0x0A, 0x09, 0x09, 0x2F, 0x2F, 0x20,
	0x54, 0x4F, 0x44, 0x4F, 0x3A, 0x20, 0x50, 0x6C, 0x61, 0x63, 0x65, 0x20, 0x63, 0x6F, 0x64, 0x65,
	0x20, 0x68, 0x65, 0x72, 0x65, 0x20, 0x74, 0x6F, 0x20, 0x68, 0x61, 0x6E, 0x64, 0x6C, 0x65, 0x20,
	0x77, 0x68, 0x65, 0x6E, 0x20, 0x74, 0x68, 0x65, 0x20, 0x64, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x20,
	0x69, 0x73, 0x0D, 0x0A, 0x09, 0x09, 0x2F, 0x2F, 0x20, 0x20, 0x64, 0x69, 0x73, 0x6D, 0x69, 0x73,
	0x73, 0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x4F, 0x4B, 0x0D, 0x0A, 0x09, 0x7D, 0x0D,
	0x0A, 0x09, 0x65, 0x6C, 0x73, 0x65, 0x20, 0x69, 0x66, 0x20, 0x28, 0x6E, 0x52, 0x65, 0x73, 0x70,
	0x6F, 0x6E, 0x73, 0x65, 0x20, 0x3D, 0x3D, 0x20, 0x49, 0x44, 0x43, 0x41, 0x4E, 0x43, 0x45, 0x4C,
	0x29, 0x0D, 0x0A, 0x09, 0x7B, 0x0D, 0x0A, 0x09, 0x09, 0x2F, 0x2F, 0x20, 0x54, 0x4F, 0x44, 0x4F,
	0x3A, 0x20, 0x50, 0x6C, 0x61, 0x63, 0x65, 0x20, 0x63, 0x6F, 0x64, 0x65, 0x20, 0x68, 0x65, 0x72,
	0x65, 0x20, 0x74, 0x6F, 0x20, 0x68, 0x61, 0x6E, 0x64, 0x6C, 0x65, 0x20, 0x77, 0x68, 0x65, 0x6E,
	0x20, 0x74, 0x68, 0x65, 0x20, 0x64, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x20, 0x69, 0x73, 0x0D, 0x0A,
	0x09, 0x09, 0x2F, 0x2F, 0x20, 0x20, 0x64, 0x69, 0x73, 0x6D, 0x69, 0x73, 0x73, 0x65, 0x64, 0x20,
	0x77, 0x69, 0x74, 0x68, 0x20, 0x43, 0x61, 0x6E, 0x63, 0x65, 0x6C, 0x0D, 0x0A, 0x09, 0x7D, 0x0D,
	0x0A, 0x0D, 0x0A, 0x09, 0x2F, 0x2F, 0x20, 0x53, 0x69, 0x6E, 0x63, 0x65, 0x20, 0x74, 0x68, 0x65,
	0x20, 0x64, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x20, 0x68, 0x61, 0x73, 0x20, 0x62, 0x65, 0x65, 0x6E,
	0x20, 0x63, 0x6C, 0x6F, 0x73, 0x65, 0x64, 0x2C, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E, 0x20,
	0x46, 0x41, 0x4C, 0x53, 0x45, 0x20, 0x73, 0x6F, 0x20, 0x74, 0x68, 0x61, 0x74, 0x20, 0x77, 0x65,
	0x20, 0x65, 0x78, 0x69, 0x74, 0x20, 0x74, 0x68, 0x65, 0x0D, 0x0A, 0x09, 0x2F, 0x2F, 0x20, 0x20,
	0x61, 0x70, 0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x2C, 0x20, 0x72, 0x61, 0x74,
	0x68, 0x65, 0x72, 0x20, 0x74, 0x68, 0x61, 0x6E, 0x20, 0x73, 0x74, 0x61, 0x72, 0x74, 0x20, 0x74,
	0x68, 0x65, 0x20, 0x61, 0x70, 0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x27, 0x73,
	0x20, 0x6D, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x20, 0x70, 0x75, 0x6D, 0x70, 0x2E, 0x0D, 0x0A,
	0x09, 0x72, 0xE6, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x46, 0x41, 0x4C, 0x53, 0x45, 0x3B, 0x0D, 0x0A,
	0x7D, 0x0D, 0xE6
};


void display(const unsigned char array[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (i%32 == 0) {
            printf("\n");
        }
        if (i%8 == 0) {
            printf(" ");
        }
        printf("%02X", array[i]);
    }
}

unsigned char *computeV4(const unsigned char *src, int len)
{
    static unsigned char buf[0x100];
    static unsigned char s[20];
    memcpy(s, src, 16);

    unsigned char wtmp[160];
    int wpos = 0;
    int i;

    uint32_t v4_check_type = ((signed char)s[0] + (signed char)s[3]) % 5u;
    switch(v4_check_type)
    {
        case 0:
        {
            unsigned char mtmp[16];
            md5_ctx mctx;

            rhash_md5_init(&mctx);
            rhash_md5_update(&mctx, array, 0x71c);
            rhash_md5_final(&mctx, mtmp);
            char tbuf[10];
            for (i=0; i<16; ++i)
            {
                sprintf((char*)wtmp + wpos, "%02x", mtmp[i]);
                wpos += 2;
            }


            for (i=0; i<8; ++i)
            {
                sprintf(tbuf, "%02x", (signed char)(s[2*i]));
                strcpy((char*)wtmp + wpos, tbuf);
                wpos += strlen(tbuf);
            }

            rhash_md5_init(&mctx);
            rhash_md5_update(&mctx, array_1, 0x7f3);
            rhash_md5_final(&mctx, mtmp);
            for (i=0; i<16; ++i)
            {
                sprintf((char*)wtmp + wpos, "%02x", mtmp[i]);
                wpos += 2;
            }
            for (i=0; i<8; ++i)
            {
                sprintf(tbuf, "%02x", (signed char)(s[2*i+1]));
                strcpy((char*)wtmp + wpos, tbuf);
                wpos += strlen(tbuf);
            }
            wpos = 0x60;
            break;

        }
        case 1:
        {
            sha1_ctx sctx;
            rhash_sha1_init(&sctx);
            rhash_sha1_update(&sctx, array_1,0x7f3);
            rhash_sha1_final(&sctx, wtmp);
            wpos += 20;

            memcpy(wtmp + wpos, s, 6);
            wpos += 6;

            rhash_sha1_init(&sctx);
            rhash_sha1_update(&sctx, array,0x71c);
            rhash_sha1_final(&sctx,wtmp + wpos);
            wpos += 20;

            memcpy(wtmp + wpos, s+6, 10);
            wpos += 10;
            break;

        }
        case 2:
        {
            sha1_ctx sctx;
            rhash_sha1_init(&sctx);
            rhash_sha1_update(&sctx,array_1,0x7f3);
            rhash_sha1_final(&sctx,wtmp);
            wpos += 20;

            memcpy(wtmp + wpos, s, 6);
            wpos += 6;

            struct ampheck_ripemd128 rctx;
            ampheck_ripemd128_init(&rctx);
            ampheck_ripemd128_update(&rctx, array, 0x71c);
            ampheck_ripemd128_finish(&rctx, wtmp + wpos);
            wpos += 16;

            memcpy(wtmp + wpos, s+6, 10);
            wpos += 10;
            break;
        }
        case 3:
        {
            tiger_ctx tctx;
            rhash_tiger_init(&tctx);
            rhash_tiger_update(&tctx,array,0x71c);
            rhash_tiger_final(&tctx,wtmp);
            wpos += 24;

            memcpy(wtmp + wpos, s, 10);
            wpos += 10;

            struct ampheck_ripemd128 rctx;
            ampheck_ripemd128_init(&rctx);
            ampheck_ripemd128_update(&rctx, array_1, 0x7f3);
            ampheck_ripemd128_finish(&rctx, wtmp + wpos);
            wpos += 16;

            memcpy(wtmp + wpos, s+10, 6);
            wpos += 6;
            break;
        }
        case 4:
        {
            tiger_ctx tctx;
            rhash_tiger_init(&tctx);
            rhash_tiger_update(&tctx,array_1,0x7f3);
            rhash_tiger_final(&tctx,wtmp);
            wpos += 24;

            memcpy(wtmp + wpos, s, 8);
            wpos += 8;

            sha1_ctx sctx;
            rhash_sha1_init(&sctx);
            rhash_sha1_update(&sctx,array,0x71c);
            rhash_sha1_final(&sctx,wtmp + wpos);
            wpos += 20;

            memcpy(wtmp + wpos, s+8, 8);
            wpos += 8;
            break;
        }
        default:
        {
            return NULL;
        }

    }
    whirlpool_ctx w;
    static unsigned char digest[100];

    rhash_whirlpool_init(&w);
    rhash_whirlpool_update(&w, wtmp, wpos);
    rhash_whirlpool_final(&w, digest);


    char tbuf[10];
    for (i = 0; i<64; ++i)
    {
        sprintf(tbuf, "%02x", digest[i]);
        buf[2*i] = tbuf[0];
        buf[2*i+1] = tbuf[1];
    }
    return buf;

}

char *computePwd(const unsigned char *md5, const char* username, const char* password)
{
    static char buf[20];

    unsigned char tmp[40];
    int tmp_len=0;
    tmp_len = strlen(username);
    strcpy((char*)tmp, username);
    memcpy(tmp + tmp_len, md5, 16);
    tmp_len += 16;

    memcpy(buf, ComputeHash(tmp, tmp_len), 16);

    memset(tmp, 0, 16);
    strcpy((char*)tmp, password);

    int i;
    for (i=0; i<16; ++i)
        buf[i] ^= tmp[i];
    return buf;
}
