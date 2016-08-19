#include "doublelist.c"
int main()
{
    pNode header;
    int i=0;
    for(;i<10;i++)
    {
        header=insertData(header, &i, i);
    }
    printList(header);
    return 0;
}
