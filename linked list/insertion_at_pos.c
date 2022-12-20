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

void insert_pos(node **start,int pos,int num)
{
    struct node* ptr = new node;
    ptr->info = num;
    ptr->next = NULL;
    int len = 0;
    struct node* temp = *start;
    while(temp!=NULL)
        len++;
    if(len>pos)
    {
        if(*start ==NULL)
            *start = ptr;
        else
        {
        temp = *start;
        while(pos!=0)
        {
            temp = temp->next;
            pos--;
        }
        ptr->next = temp->next;
        temp->next = ptr;
        }
    }
    else
    {
        cout<<"As the position is greater than the actual length addition will be done at the end";
        if(*start==NULL)
        *start = ptr;
        else
        {
            ptr->next = *start;
            *start = ptr;
        }
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
    int pos;
    cout<<"Enter the position:";
    cin>>pos;
    insert_pos(&start,pos,5);
    display();
    return 0;
}
