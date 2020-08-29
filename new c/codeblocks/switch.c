# include<stdio.h>
int main()
{
    float li,jiang;
    printf("please input ÀûÈó£º");
    scanf("li=%f",&li);
   int grade=li/100000;
    /*switch(li/100000)*///
    switch(grade)
    {
    case 0:jiang=li*0.1;break;
    case 1:jiang=100000*0.1+(li-100000)*0.075;break;
    case 2:
    case 3:jiang=100000*0.1+100000*0.075+(li-200000)*0.05;break;
    case 4:
    case 5:jiang=100000*0.1+100000*0.075+200000*0.05+(li-400000)*0.03;break;
    case 6:
    case 7:
    case 8:
    case 9:jiang=100000*0.1+100000*0.075+200000*0.05+200000*0.03+(li-600000)*0.015;break;
    case 10:jiang=jiang=100000*0.1+100000*0.075+200000*0.05+200000*0.03+600000*0.015+(li-1000000)*0.01;break;


    }
     printf("½±½ğÊÇ£ºjiang=%f\n",jiang);
        return 0;

}
