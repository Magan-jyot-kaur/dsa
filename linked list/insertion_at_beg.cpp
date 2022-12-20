#include<iostream>
using namespace std;
struct node
{
    int info;
    node* next;
};

void insert_beg(node **start,int num)
{
    struct node* ptr = new node;
    ptr->info = num;
    ptr->next = NULL;
    if(*start==NULL)
        *start = ptr;
    else
    {
        ptr->next = *start;
        *start = ptr;
    }
}

void display(node **start)
{
    struct node *temp = *start;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp = temp->next;
    }
}
int main()
{
    struct node *start = NULL;
    insert_beg(&start,1);
    insert_beg(&start,2);
    insert_beg(&start,3);
    insert_beg(&start,4);
    display(&start);
    return 0;
}
