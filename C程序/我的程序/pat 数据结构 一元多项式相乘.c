
# include<stdio.h>
typedef struct node
{
    int coef;//系数
    int exp;//指数
    struct node*next;
    }* linklist;

    linklist creatpoly(char i);
    linklist multipoly(linklist s,linklist t);
    void outpoly(linklist head);


     int main()
    {
    linklist hsum,t,pa,pb,ha,hb;//a,b的头节点
    ha=creatpoly('a');
    printf("A=");
    outpoly(ha);
    hb=creatpoly('b');
    printf("B=");
    outpoly(hb);
    hsum=(struct node*)malloc(sizeof(struct node));
    hsum->next=NULL;
    for(pa=ha->next;pa;pa=pa->next)
    {
        for(pb=hb->next;pb;pb=pb->next)
        {
           t=malloc(sizeof(struct node)) ;
           t->coef=pb->coef*pa->coef;//系数
           t->exp=pb->exp+pa->exp;//指数
           t->next=NULL;
           hsum=multipoly(hsum,t);

        }
    }
    printf("A*B=");
    out(hsum);

    }
    linklist creatpoly(char i)
    {

        int pcoef=0,pexp=0,exp;
        linklist head ,p,q;
        head=malloc(sizeof(struct node));
        q=head;
        printf("Please input expresssion of %d:",i);
        printf("Input COEF(-1 to end:");
        scanf("%d",&pcoef);
        while(pcoef!=-1)
        {

            printf("Input EXP：");
            scanf("%d",&exp);
            p=malloc(sizeof(struct node));
            p->coef=pcoef;
            p->exp=pexp;
            q->next=p;
            q=p;
            printf("Input COEF(-1 to end):");
            scanf("%d",&pcoef);
                    }

                    q->next=NULL;
                    return head;

    }

    linklist multipoly(linklist s,linklist t)
    {
        linklist p,q;
        if(t->coef!=0)
        {

            if(s->next==NULL)
                s->next=t;
            else {
                q=s;
                p=q->next;
                for(;p&&p->exp<t->exp;p=q->next);
                if(p==NULL)
                    q->next=t;
                    else
                {
                    if(p->coef==t->exp)
                    {
                        if((p->coef+t->coef)==0)
                            q->next=p->next;
                        else
                            p->coef=p->coef+t->coef;
                    }
                    else{
                        q->next=t;
                        t->next=p;
                    }
                }
            }
        }
        return s;
    }

    void outpoly(linklist head)
    {
    linklist p;
    p=head->next;
    if(head)
    {

        do {
            if(p->coef>0)
                printf("+%dX^%d",p->coef,p->exp);
            else
                printf("%dX^%d",p->coef,p->exp);
           p= p->next;
        }
        while(p);
        printf("\n");






    }

    else
        printf("NO Date");
        }

















