#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
}*last;

void insert_beg(int num)
{
    struct node* new_node = new node;
    new_node->data = num;
    if(last==NULL)
    {
        last = new_node;
        new_node->next = last;
    }
    else
    {
        new_node->next = last->next;
        last->next = new_node;
    }
}

void insert_end(int num)
{
    struct node* new_node = new node;
    new_node->data = num;
    if(last==NULL)
    {
        last = new_node;
        new_node->next = last;
    }
    else
    {
        new_node->next = last->next;
        last->next = new_node;
        last = new_node;
    }
}

void deletion_beg()
{
    struct node* temp = last->next;
    if(last==NULL)
    {
        cout<<"Underflow";
    }
    else if(last==temp)
    {
        last==NULL;
    }
    else
    {
        last->next = temp->next;

    }
}

void display()
{
    struct node* temp = last->next;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=last->next);
}

void deletion_end()
{
    struct node* prev = new node;
    struct node* curr = last->next;
    if(last == NULL)
    {
        cout<<"underflow";
    }
    else if(last == curr)
    {
        last = NULL;
    }
    else
    {
        while(curr->next!=last->next)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = last->next;
        last = prev;
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
    deletion_end();
    display();
    return 0;
}
