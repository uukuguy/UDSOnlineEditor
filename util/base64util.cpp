#include "stdafx.h"
#include "base64util.h"
#include <string>    //  使用 string 类时须包含这个文件
#include <iostream>
using namespace std;

namespace base64util {

	char ntc(unsigned char n){
		if (n<26) return 'A'+n;
		if (n<52) return 'a'-26+n;
		if (n<62) return '0'-52+n;
		if (n==62) return '+';
		return '/';
	}

	unsigned char ctn(char c){
		if (c=='/') return 63;
		if (c=='+') return 62;
		if ((c>='A')&&(c<='Z')) return c-'A';
		if ((c>='a')&&(c<='z')) return c-'a'+26;
		if ((c>='0')&&(c<='9')) return c-'0'+52;
		if (c=='=') return 80;
		return 100;
	}

	int b64encode(const char *from,char *to,int length,int quads){
		// 3 个byte转换为四个字符 
		int i =0;
		char *tot=to;
		int qc=0;  // Quadcount
		unsigned char c;
		unsigned char d;
	  

		while(i<length)	{
			c=from[i];
			*to++=ntc(c/4);
			c=c*64;
		    
			i++;
		    
			if (i>=length) {
				*to++=ntc(c/4);
				*to++='=';
				*to++='=';
				break;
			}

			d=from[i];
			*to++=ntc(c/4+d/16);
			d=d*16;

			i++;

			if (i>=length) {
				*to++=ntc(d/4);
				*to++='=';
				break;
			}

			c=from[i];
			*to++=ntc(d/4+c/64);
			c=c*4;
		    
			i++;
		    
			*to++=ntc(c/4);

			qc++; // qz will never be zero, quads = 0 means no linebreaks
			if (qc==quads){
				*to++='\n';
				qc=0;
			}

		}
		// if ((quads!=0)&&(qc!=0)) *to++='\n'; // Insert last linebreak 
		return to-tot;
	}

	int b64decode(char *from,char *to,int length){
		unsigned char c,d,e,f;
		char A,B,C;
		int i;
		int add;
		char *tot=to;
		for (i=0;i+3<length;){
			add=0;
			A=B=C=0;
			c=d=e=f=100;

			while ((c==100)&&(i<length))    c=ctn(from[i++]);
			while ((d==100)&&(i<length))    d=ctn(from[i++]);
			while ((e==100)&&(i<length))    e=ctn(from[i++]);
			while ((f==100)&&(i<length))    f=ctn(from[i++]);

			if (f==100) return -1; // Not valid end

			if (c<64) 
			{
				A+=c*4;
				if (d<64) 
				{
					A+=d/16;
					B+=d*16;
					if (e<64) 
					{
						B+=e/4;
						C+=e*64;
						if (f<64) 
						{
							C+=f;
							to[2]=C;
							add+=1;
						}
						to[1]=B;
						add+=1;
					}
					to[0]=A;
					add+=1;
				}
			}
			to+=add;
			if (f==80) return to-tot; // end because '=' encountered 
		}
		return to-tot;
	}

	int b64get_encode_buffer_size(int l,int q){
		int ret;
		ret = (l/3)*4;
		if (l%3!=0) ret +=4;
		if (q!=0)
		{
			ret += (ret/(q*4));
			// if (ret%(q/4)!=0) ret ++;   // Add space for trailing \n
		}
		return ret;
	}

	int b64strip_encoded_buffer(char *buf,int length){
		int i;
		int ret=0;

		for (i=0;i<length;i++) if (ctn(buf[i])!=100) buf[ret++] = buf [i];
		  
		return ret;
	}

	int ToHexString(char *crOut, BYTE *btIn, int size)
	{
		char hexChars[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
				'A', 'B', 'C', 'D', 'E', 'F' };
		int height = 0;
		int low = 0;
		//BYTE bh = 0;
		//BYTE bl = 0;
		//TCHAR ds[100];
		
		for (int i = 0; i < size; i++)
		{
			
			height = (btIn[i] & 0xf0) >> 4;
			//memset(ds,0, sizeof(ds));
			//wsprintf(ds,_T("%d"), height);
			//MessageBox(GetForegroundWindow(),ds,_T("亿榕公文交换平台提示"),MB_OK|MB_ICONINFORMATION);
			low = btIn[i] & 0x0f;
			//memset(ds,0, sizeof(ds));
			//wsprintf(ds, _T("%d"), low);
			//MessageBox(GetForegroundWindow(),ds,_T("亿榕公文交换平台提示"),MB_OK|MB_ICONINFORMATION);
			crOut[i*2] = hexChars[height];
			crOut[i*2 + 1] = hexChars[low];
		}
		return 0;
	}

	int ToByteArray(BYTE *btOut, char *crIn, int intsize)
	{
		string str("0123456789ABCDEF");
		
		int len = intsize / 2;
		for (int i = 0; i < len; i++)
		{
			int hpos = str.find(crIn[i*2]);
			int lpos = str.find(crIn[i*2 + 1]);
			btOut[i] = (BYTE)(hpos << 4 | lpos);
		}
		return 0;
	}
}