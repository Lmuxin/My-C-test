# include<stdio.h>
void move_disk(char src,char dst)
{

    printf("%c====>%c\n",src,dst);
}
void tower(int n,char src,char mid,char dst){

if(n==1)
    {
        move_disk(src,dst);
        return ;

    }
    tower(n-1,src,dst,mid);
    move_disk(src,dst);
    tower(n-1,mid,src,dst);


}
int main(){
int disk;
printf("Number of disk:");
scanf("%d",&disk);
tower(disk,'A','B','C');



}
