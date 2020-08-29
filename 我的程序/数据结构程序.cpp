# include <stdio.h>
Seqlist*init_Seqlist()
{
    Seqlist*L;
    L=(Seqlist*)malloc(sizeo(Seqlist));
    L->last=-1;
    return L;

}
int main()
{
    Seqlist*L;
    Seqlist*init_Seqlist();
    L=Init_Seqlist();
}
