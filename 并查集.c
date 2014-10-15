#include <stdio.h>
#include <stdlib.h>
typedef struct spot
{
    int element;
    int father;
    int count;
} MF,*MFP;

void UNion(MFP A,int key1,int key2);
int Find(MFP A,int X);
void Creat(MFP A,int N);

int main()
{
    int N,i,X,key1,key2;
    MFP A=NULL;
    printf("������Ԫ�ظ���:");
    scanf("%d",&N);
    A=(MFP)malloc((N+1)*sizeof(MF));
    Creat(A,N);
    while(1)
    {
        scanf("%d%d",&key1,&key2);
        if(key1==0&&key2==0)
        {
            break;
        }
        UNion(A,key1,key2);
    }

    printf("\n��֮��ļ���Ϊ:element,father,count\n");
    for(i=1;i<=N;i++)
    {
        printf("%d %d\n",A[i].element,A[i].father);
    }
    printf("��������ҵ�Ԫ��:");
    scanf("%d",&X);
    printf("��Ԫ�صĸ��׽ڵ�Ϊ:\n");
    printf("\n%d",Find(A,X));
    return 0;
}
void UNion(MFP A,int key1,int key2)
{
    key1=Find(A,key1);
    key2=Find(A,key2);
    if(A[key1].count>A[key2].count)
    {
        A[key2].father=key1;
        A[key1].count=A[key1].count+A[key2].count;
    }
    else
    {
        A[key1].father=key2;
        A[key2].count=A[key2].count+A[key1].count;
    }
    return ;
}
int Find(MFP A,int X)
{
    int p;
    p=X;
    while(A[p].father!=0)
    {
        p=A[p].father;
    }
    return p;
}
void Creat(MFP A,int N)
{
    int i;
    for(i=1;i<=N;i++)
    {
        A[i].element=i;
        A[i].count=1;
        A[i].father=0;
    }
}






