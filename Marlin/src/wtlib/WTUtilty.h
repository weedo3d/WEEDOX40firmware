#ifndef WT_UTILTY_H
#define WT_UTILTY_H

#include <stdbool.h>

bool startsWith(const char *str1, const char *str2);

uint16_t hexStringConvert(const char *hexStr, uint8_t *pBinArray);

// 解析长字符串中指定字符串对应的值
uint8_t extractFront(const char* source, char* ident, char* valString);

// utf8转unicode
int Utf8ToUnicode(const char* pInput, char* pOutput);

// 版本比较
bool VersionCompare(char* oldVersion, char* newVersion);

#endif