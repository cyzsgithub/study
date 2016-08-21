#include "doublelist.c"

int print_int(void* data)
{
    printf("%d\n",*(int*)data);
    return 0;
}
int main()
{
    pNode header=NULL;
    int i=0;
    for(;i<10;i++)
    {
        header=insertData(header, &i, i);
    }
    printList(header, print_int);
    return 0;
}
