#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int iskeyword(char buffer1[])
{
char keyword[32][20]={"auto","int","double","float","char","void","return","do"};
int flag=0,i;
for(i=0;i<32;i++)
{
if(strcmp(keyword[i],buffer1)==0)
{
flag=1;
break;
}
}
return flag;
}

int main()
{
char ch1,buffer1[15],operator[]="+-*/%=";
FILE* fp;
int k,l=0;
fp=fopen("input.txt","r");
while((ch1=fgetc(fp))!=EOF)
{
for(k=0;k<6;k++)
{
if(ch1==operator[k])
printf("%c--is operator\n",ch1);
}
if(isalnum(ch1))
{
buffer1[l++]=ch1;
}
else if((ch1==' '||ch1=='\n')&&(l!=0))
{
buffer1[l]='\0';
l=0;
if(iskeyword(buffer1)==1)
printf("%s--is keyword\n",buffer1);
else
printf("%s--is identifier\n",buffer1);
}
}
fclose(fp);
return 0;
}

