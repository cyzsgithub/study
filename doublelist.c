#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    void *data;
    struct _Node *pre;
    struct _Node *next;
}Node,*pNode;

pNode creatDoubleList(int n);
pNode insertData(pNode header, void *data, int position);
pNode deletePosition(pNode header, int position);
int* findData(pNode header, void *data);
int isEmpty(pNode header);
int destory(pNode header);

pNode creatDoubleList(int n)
{
    if(n>0)
    {
        pNode header;
        pNode p;
        pNode s;   
        header=(pNode)malloc(sizeof(Node));
        p=header;
        s=header;
        int i;
        for(i=1; i<n; i++)
        {
            s=(pNode)malloc(sizeof(Node));
            p->next=s;
            s->pre=p;
            p=s;
        }
        s->next=header;
        header->pre=s;
        p=NULL;
        s=NULL;
        return header;
    }
    else
    {
        return NULL;
    }
}

pNode insertData(pNode header, void *data, int position)
{
    if(header==NULL)
    {
        header=(pNode)malloc(sizeof(Node));
        header->data=data;
        header->pre=header;
        header->next=header;
        return header;
    }
    if(header != NULL && position >= 0)
    {
        pNode temp = (pNode)malloc(sizeof(Node));
        temp->data = data;
        pNode p = header;
        int i=position;
        while(i)
        {
            p=p->next;
            i--;
        }
        temp->next=p->next;
        temp->pre=p;
        p->next=temp;
        temp->next->pre=temp;
        return header;
    }
    else
    {
        return header;
    }   
}

pNode deletePosition(pNode header, int position)
{
    if(header==NULL)
    {
        return NULL;
    }
    if(header!=NULL&&position>=0)
    {
        int i=position;
        pNode temp=header;
        while(i)
        {
            temp=temp->next;
            i--;
        }
        temp->pre->next=temp->next;
        temp->next->pre=temp->pre;
        temp->pre=NULL;
        temp->next=NULL;
        free(temp);
        return header;  
    }
    else
    {
        return header;
    }
}

int * findData(pNode header, void* data)
{
    typedef struct iNode{
    int num;
    struct iNode *next;
    }iNode,*piNode;

    piNode head=(piNode)malloc(sizeof(iNode));
    piNode temp=NULL;
    piNode p=head;
    head->num=-1;
    head->next=NULL;
    int number=0; //number of findedNode
    if(data==header->data)
    {
        head->num=0;
        number++;
    }
    pNode curr=header->next;
    int i=0;
    while(curr!=header)
    {
        i=i+1;
        if(data==curr->data)
        {
            temp=(piNode)malloc(sizeof(iNode));
            temp->num=i;
            p->next=temp;
            temp->next=NULL;
            p=temp;
            number++;
        }
        curr=curr->next;
    }
    int *iarr;
    if(number!=0)
    {
        iarr=(int *)malloc(sizeof(int)*number);
        temp=head;
        int k=0;
        if(temp!=NULL)
        {
            iarr[k]=temp->num;
            p=temp;
            temp=temp->next;
            k++;
            free(p);//free only list
        }
    }
    return iarr;
}

int isEmpty(pNode header)
{
    if(header!=NULL)
        return -1;
    else
        return 0;
}

int destory(pNode header)
{
    if(header!=NULL)
    {
        pNode n=header;
        pNode p; 
        while(n!=header)
        {
            p=n;
            n=n->next;
            free(p);
        }
        return 0;
    }
    return -1;
}

int main(void)
{
    pNode head;
    head=creatDoubleList(5);
    return 0;
}
