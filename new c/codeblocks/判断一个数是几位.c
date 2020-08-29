# include<stdio.h>
int main()
{
    int num;//输入的数字
    int  wei;//位数
    int ge;//个位
    int shi;//十位
    int bai;//白
    int qian;//千
    int wan;//万

    printf("pleae input a num between 0 and 99999:");
    scanf("num=%d",&num);
    if(num>9999)
        wei=5;
   else  if(num>999)
            wei =4;
     else if(num>99)
                wei=3;
    else if(num>9)
                wei=2;                                           //这种方法貌似比较笨
    else wei=1;
            printf("位数是wei=%d\n",wei);

wan=num/10000;
qian=(num-wan*10000)/1000;
bai=(num-wan*10000-qian*1000)/100;
shi=(num-wan*10000-qian*1000-bai*100)/10;
ge=num-wan*10000-qian*1000-bai*100-shi*10;
printf("各位数字是：wan=%d,qian=%d,bai=%d,shi=%d,ge=%d\n",wan,qian,bai,shi,ge);
printf("逆序数字是：");
switch(wei)
{

    case 1:printf("%d",ge);break;
    case 2:printf("%d,%d",ge,shi);break;
    case 3:printf("%d,%d,%d",ge,shi,bai);break;
    case 4:printf("%d,%d,%d,%d",ge,shi,bai,qian);break;;
    case 5:printf("%d,%d,%d,%d,%d",ge,shi,bai,qian,wan);break;

            }



 return 0;
}
