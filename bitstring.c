#include<stdio.h>
#include<stdlib.h>
# define MAX 50

void display(int arr[],int size);
void union_(int abit[],int bbit[],int result[],int usize);
void intersect(int abit[],int bbit[],int result[],int usize);
void differ(int abit[],int bbit[],int result[],int usize);

int main()
{
    int uset[MAX],aset[MAX],bset[MAX],abit[MAX],bbit[MAX],result[MAX];
    int usize,asize,bsize;
    int i,j,ch;
    printf("universal set\n");
    printf("enter size:");
    scanf("%d",&usize);
    printf("\nenter elements\n");
    for(i=0;i<usize;i++)
    {
        scanf("%d",&uset[i]);
    }
    printf("set 1\n");
    printf("enter size:");
    scanf("%d",&asize);
    printf("\nenter elements\n");
    for(i=0;i<asize;i++)
    {
        scanf("%d",&aset[i]);
    }
    printf(" set 2\n");
    printf("enter size:");
    scanf("%d",&bsize);
    printf("\nenter elements\n");
    for(i=0;i<bsize;i++)
    {
        scanf("%d",&bset[i]);
    }
    for(i=0;i<usize;i++)
    {
        for(j=0;j<asize;j++)
        {
            if(uset[i]==aset[j])
            {
                abit[i]=1;
                break;
            }
            else abit[i]=0;
            
        }
    }
    
    for(i=0;i<usize;i++)
    {
        for(j=0;j<bsize;j++)
        {
            if(uset[i]==bset[j])
            {
                bbit[i]=1;
                break;
            }
            else bbit[i]=0;
            
        }
    }
    while(1)
    {
        printf("\n1.Display\n2.Bit vectors\n3.Union\n4.Intersection\n5.Difference\n6.Exit\nENTER UR CHOICE:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("universal set :\n");
                display(uset,usize);
                printf("\nset 1\n");
                display(aset,asize);
                printf("\nset 2\n");
                display(bset,bsize);
                break;
            case 2:
                printf("\nbit vector 1 : \n");
                display(abit,usize);
                printf("\nbit vector 2 : \n");
                display(bbit,usize);
                break;
             case 3:
                 printf("union : \n");
                 union_(abit,bbit,result,usize);
                 display(result,usize);
                 break;
             case 4:
                 printf("intersection :\n");
                 intersect(abit,bbit,result,usize);
                 display(result,usize);
                 break;
             case 5:
                 printf("difference :\n");
                 differ(abit,bbit,result,usize);
                 display(result,usize);
                 break;
             case 6:
                 exit(0);
                 break;
             default:
                 printf("invalid\n");
                 break;
             
        }
    }
}

void display(int arr[],int size)
{
    printf("{");
    for(int i=0;i<size;i++)
    {
        printf("%d",arr[i]);
        if(i<size-1) printf(",");
    }
    printf("}");
}
void union_(int abit[],int bbit[],int result[],int usize)
{
    for(int i=0;i<usize;i++)
    {
        result[i]=abit[i]|bbit[i];
    }
}

void intersect(int abit[],int bbit[],int result[],int usize)
{
    for(int i=0;i<usize;i++)
    {
        result[i]=abit[i]&bbit[i];
    }
}

void differ(int abit[],int bbit[],int result[],int usize)
{
    for(int i=0;i<usize;i++)
    {
        result[i]=abit[i]&~bbit[i];
    }
}