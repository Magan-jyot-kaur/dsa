#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* prev;
    struct node* next;
}*start;

void insert_beg(int num)
{
    struct node* new_node = new node;
    new_node->data = num;
    new_node->next = start;
    new_node->prev = NULL;
    start = new_node;
}

void insert_end(int num)
{
    struct node* new_node = new node;
    new_node->data = num;
    new_node->next = NULL;
    if(start==NULL)
    {
        new_node->prev = NULL;
        start = new_node;
    }
    else
    {
        struct node* temp = start;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void deletion_beg()
{
    if(start==NULL)
    {
        cout<<"Underflow";
    }
    else
    {
        start = start->next;
    }
}

void deletion_end()
{
    if(start==NULL)
    {
        cout<<"underflow";
    }
    else
    {
        struct node* last = new node;
        struct node* temp = start;
        while(temp->next!=NULL)
        {
            last = temp;
            temp = temp->next;
        }
        last->next = NULL;
    }
}

void display()
{
    struct node* temp = start;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    insert_end(0);
    insert_beg(1);
    insert_beg(2);
    insert_beg(3);
    insert_end(4);
    display();
    cout<<endl;
    deletion_beg();
    deletion_beg();
    deletion_end();
    display();
    return 0;
}
