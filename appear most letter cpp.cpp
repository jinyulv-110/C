/*
����ľ����а��� ABCDEF �����ַ������ʳ��������ַ������˼��Σ�

FFEEFEAAECFFBDBFBCDA
DACDEEDCCFFAFADEFBBA
FDCDDCDBFEFCEDDBFDBE
EFCAAEECEECDCDECADDC
DFAEACECFEADCBFECADF
DFBAAADCFAFFCEADFDDA
EAFAFFDEFECEDEEEDFBD
BFDDFFBCFACECEDCAFAF
EFAFCDBDCCBCCEADADAE
BAFBACACBFCBABFDAFBE
FCFDCFBCEDCEAFBCDBDD
BDEFCAAAACCFFCBBAAEE
CFEFCFDEEDCACDACECFF
BAAAFACDBFFAEFFCCCDB
FADDDBEBCBEEDDECFAFF
CDEAFBCBBCBAEDFDBEBB
BBABBFDECBCEFAABCBCF
FBDBACCFFABEAEBEACBB
DCBCCFADDCACFDEDECCC
BFAFCBFECAACAFBCFBAF


*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a=0,b=0,c=0,d=0,e=0,f=0;
  char s[21][21]={
        "FFEEFEAAECFFBDBFBCDA",
        "DACDEEDCCFFAFADEFBBA",
        "FDCDDCDBFEFCEDDBFDBE",
        "EFCAAEECEECDCDECADDC",
        "DFAEACECFEADCBFECADF",
        "DFBAAADCFAFFCEADFDDA",
        "EAFAFFDEFECEDEEEDFBD",
        "BFDDFFBCFACECEDCAFAF",
        "EFAFCDBDCCBCCEADADAE",
        "BAFBACACBFCBABFDAFBE",
        "FCFDCFBCEDCEAFBCDBDD",
        "BDEFCAAAACCFFCBBAAEE",
        "CFEFCFDEEDCACDACECFF",
        "BAAAFACDBFFAEFFCCCDB",
        "FADDDBEBCBEEDDECFAFF",
        "CDEAFBCBBCBAEDFDBEBB",
        "BBABBFDECBCEFAABCBCF",
        "FBDBACCFFABEAEBEACBB",
        "DCBCCFADDCACFDEDECCC",
        "BFAFCBFECAACAFBCFBAF"};

  for(int i=0;i<20;i++)
  {
    for(int j=0;j<20;j++)
    {
      if(s[i][j]=='A') a+=1;
      if(s[i][j]=='B') b+=1;
      if(s[i][j]=='C') c+=1;
      if(s[i][j]=='D') d+=1;
      if(s[i][j]=='E') e+=1;
      if(s[i][j]=='F') f+=1;
    }
  }
  if(b>a) a=b;
  if(c>a) a=c;
  if(d>a) a=d;
  if(e>a) a=e;
  if(f>a) a=f;
  printf("%d",a);
  return 0;
}
