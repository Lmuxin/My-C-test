#include<stdio.h>
int main()
{
   FILE *f=fopen("E:\\C程序\\2018.3\\1f.txt","r");//FILE必须大写     必须是双反斜杠

   if(f!=NULL)//NULL必须大写
   {
     printf("文件已经打开");


     fclose(f);



   }
else
{


printf("问价打开失败");



}


 while(!feof(f))
     printf("%c",fgetc(f));


return 0;


}
