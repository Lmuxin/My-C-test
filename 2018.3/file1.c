#include<stdio.h>
int main()
{
   FILE *f=fopen("E:\\C����\\2018.3\\1f.txt","r");//FILE�����д     ������˫��б��

   if(f!=NULL)//NULL�����д
   {
     printf("�ļ��Ѿ���");


     fclose(f);



   }
else
{


printf("�ʼ۴�ʧ��");



}


 while(!feof(f))
     printf("%c",fgetc(f));


return 0;


}
