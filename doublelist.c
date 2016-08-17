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
    
}

int main(void)
{
    pNode head;
    head=creatDoubleList(5);
    return 0;
}
