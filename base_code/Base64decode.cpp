//base64decode
#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
char s1[50000];
char s2[50000];
int len;
void change()
{
    for (int i = 0; i < len;i++)
    {
        if (s1[i] >= 'A'&&s1[i] <= 'Z')
        {
            s1[i] -= 'A';
            continue;
        }
        if (s1[i] >= 'a' && s1[i] <= 'z')
        {
            s1[i]=s1[i]- 'a' + 26;
            continue;
        }
        if (s1[i] >= '0' && s1[i] <= '9')
        {
            s1[i] =s1[i]- '0' + 52;
            continue;
        }
        if (s1[i]== '+')
            s1[i]= 62;
        else
            s1[i] = 63;
    }
}
void decode()
{
    int cnt=0;
    for (int j = 0; j < len;j+=4)
    {
        s2[cnt++] = (s1[j] << 2) | (s1[j + 1] >> 4);
        if(j+2<len) s2[cnt++]=(s1[j+1]<<4)|(s1[j+2]>>2);
        if(j+3<len) s2[cnt++]=(s1[j+2]<<6)|(s1[j+3]);
    }
    s2[cnt] = '\0';
}
int main()
{
    cin >> s1;
    len = strlen(s1);
    while(s1[len-1]=='=')
    len--;
    change();
    decode();
    printf("%s\n", s2);
}