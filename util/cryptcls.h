//加解密文本的定义
#ifndef __MYCRYPT_H__
#define __MYCRYPT_H__
#pragma once

const int IN_BUFFER_SIZE    = 1024;
// OUT_BUFFER_SIZE is 8 bytes larger than IN_BUFFER_SIZE
// When CALG_RC2 algorithm is used, encrypted data 
// will be 8 bytes larger than IN_BUFFER_SIZE
const int OUT_BUFFER_SIZE   = IN_BUFFER_SIZE + 8; // extra padding

//加密原始字符串并以base64编码方式输出，加密密码默认为：11235813
BOOL Encrypt(const TCHAR* szRaw,TCHAR* szOut,int iOutSize,TCHAR* szKey=L"11235813");
//解密以base64方式编码的加过密的字符串并输出原始字符串，解密密码默认为：11235813
BOOL Decrypt(TCHAR* szRaw,TCHAR* szOut,int iOutSize,TCHAR* szKey=L"11235813");
BOOL GetSystemDriveSerialNumber(TCHAR* szSerialNumber,UINT iSize);
//把utf8指定的utf-8格式字符串转换为unicode字符串，结果保存在dst中，dst的大小由dstSize指定（如果dstSize为0，则返回需要的dst大小）。
BOOL ToUTF16(IN const char * utf8 ,wchar_t * dst,size_t dstSize);
//把utf16指定的unicode字符串转换为utf8字符串，结果保存在dst中，dst的大小由dstSize指定（如果dstSize为0，则返回需要的dst大小）。
BOOL FromUTF16( IN const wchar_t * utf16,char* dst,size_t dstSize);
#endif // __MYCRYPT_H__