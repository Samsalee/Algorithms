#include<iostream>
#include<fstream>
using namespace std;

struct ListNode
{
    int key;
    ListNode *next;
    //Constructor
    ListNode();
    ListNode(int key1,ListNode*next1=nullptr)
    {
        key=key1;
        next=next1;
    }
  
};

void RemoveNode(ListNode**HeadNode,int value)
{
    if( HeadNode==nullptr|| *HeadNode==nullptr)
    return;
    ListNode *TheDeleled=nullptr;
    if((*HeadNode)->key==value)
     {
        TheDeleled=*HeadNode;
        *HeadNode=(*HeadNode)->next;
     }
     else
     {
         ListNode *MNode=*HeadNode;
         while (MNode->next!=nullptr&&MNode->next->key!=value)
             MNode=MNode->next;
         if( MNode->next!=nullptr&&MNode->next->key==value)
         {
           TheDeleled=MNode->next;
           MNode->next=MNode->next->next;
         }
     }
     if(TheDeleled!=nullptr)
     {
         delete TheDeleled;
         TheDeleled=0;
     }  
};
void InsertInLinkedList(ListNode**headnode,int data,int position)
{
    int k=1;
    ListNode *first,*second;
    ListNode *newnode=new ListNode(data);
    if(!newnode)
    {
        printf("Memory error");
        return;
      
    }
    first=*headnode;
    if(position==1)
    {
        newnode->next=*headnode;
        *headnode=newnode;
    }
    else
    {
        //traverse the linkedlist until the position where we want to insert
        while (headnode!=nullptr&&k<position)
        {
            ++k;
            second=first;
            first=first->next;
        }
        second->next=newnode;
        newnode->next=first->next;
     }
 };
void DeleleNode(ListNode**headnode,int position)
{
    int k=1;
    ListNode *first,*second,*thedeleled;
    if (headnode==nullptr&&*headnode==nullptr)
    {
        printf("the list is empty");
        return; 
    }
    second=*headnode;
    if (position==1)
    {
        thedeleled=*headnode;
        *headnode=(*headnode)->next;
    }
    else
    {
        while (headnode!=nullptr&&k<position)
        {
            k++;
            first=second;
            second=second->next;
        }
        if(second==nullptr)
        printf("Position does not exist");
        else
        {
            thedeleled=second;
            first->next=second->next;
        }
    }
    if(thedeleled!=nullptr)
     {
         delete thedeleled;
         thedeleled=0;
     }  
};
//删除整个链表
void DeleleLinkedList(ListNode **head)
{
    ListNode *first,*second;
    first=*head;
    while (first)
    {
        second=first->next;
        delete first;
        first=second; 
    }
    head=nullptr;
     
};


int main()
{
    ListNode *head = nullptr;
    // Create first node with 12.5
    head=new ListNode(12); 
    head=new ListNode(13,head);// Create second node with 13.5
    head=new ListNode(14,head);
     head=new ListNode(15,head);
    // Print the list
    cout << "First item is " << head->key << endl;
    cout << "Second item is " << head->next->key<< endl;
    ListNode **headNode=&head;
    RemoveNode(headNode,13);
    ListNode *ptr = head;
    DeleleNode(headNode,3);
    while (ptr != nullptr)
    {
        cout << ptr->key << " "; // Process node
        ptr = ptr->next; // Move to next node
    }
    return 0;
}
