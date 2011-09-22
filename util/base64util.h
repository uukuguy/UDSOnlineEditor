#ifndef __BASE64UTIL_H__
#define __BASE64UTIL_H__
#pragma once
namespace base64util {
	char ntc(unsigned char n);
	unsigned char ctn(char c);
	int b64encode(const char *from,char *to,int length,int quads);
	int b64decode(char *from,char *to,int length);
	int b64get_encode_buffer_size(int l,int q);
	int b64strip_encoded_buffer(char *buf,int length);
	int ToHexString(char *crOut, BYTE *btIn, int size);
	int ToByteArray(BYTE *btOut, char *crIn, int intsize);
}
#endif // __BASE64UTIL_H__