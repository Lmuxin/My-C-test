# include<stdio.h>
int main()
{
char c;
int letter=0,space=0,number=0,other=0;

printf("please input characters:");
while((c=getchar())!='\n')
 {
 if(c>'a'&&c<'z'||c>'A'&&c<'Z')
 letter++;
 else if(c=' ')
 space++;
 else if(c>='0'&&c<='9')
 number++;
 else other++;
 }

 printf("��ĸ������letter=%d\n",letter);
  printf("�ո�������space=%d\n",space);
   printf("����������number=%d\n",number);
    printf("����������other=%d\n",other);
 return 0;

}
