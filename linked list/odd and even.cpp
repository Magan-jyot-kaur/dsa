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

void sort(node **start)
{
    struct node *ptr = *start;
    struct node *temp = *start;
    struct node* temp2 = NULL;
    while(ptr->next!=NULL)
        ptr= ptr->next;
    struct node* new_ptr = ptr;
    while(temp->info%2==0&&temp!=ptr)
    {
        new_ptr->next = temp;
        temp = temp->next;
        new_ptr->next->next = NULL;
        new_ptr = new_ptr->next;
    }
    if(temp->info%2!=0)
    {
        *start = temp;
        while(temp!=ptr)
        {
            if((temp->info%2!=0))
            {
                temp2 = temp;
                temp = temp->next;
            }
            else
            {
                temp2->next = temp->next;
                temp->next = NULL;
                new_ptr->next = temp;
                new_ptr = temp;
                temp = temp2->next;
            }
        }
    }
    else
    {
        temp2 = temp;
    }
    if(new_ptr!=ptr && (ptr->info%2==0))
    {
        temp2->next = ptr->next;
        ptr->next = NULL;
        new_ptr->next = ptr;
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
    sort(&start);
    cout<<endl;
    display(&start);
    return 0;
}
