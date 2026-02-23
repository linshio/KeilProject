#ifndef __Nixie__H__
#define __Nixie__H__
void Nixie_Scan(unsigned char slot,number);
void NixieLoop(void);
void Nixie_SetBuf(unsigned char location,number);
#endif