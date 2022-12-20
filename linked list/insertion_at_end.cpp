#include<iostream>
using namespace std;
struct node
{
    int info;
    node* next;
};

void insert_end(node **start,int num)
{
    struct node* ptr = new node;
    ptr->info = num;
    ptr->next = NULL;
    if(*start==NULL)
        *start = ptr;
    else
    {
        struct node* temp = *start;
        while(temp->next!=NULL)
            temp = temp->next;
        ptr->next = temp->next;
        temp->next = ptr;
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
    insert_end(&start,1);
    insert_end(&start,2);
    insert_end(&start,3);
    insert_end(&start,4);
    display(&start);
    return 0;
}
