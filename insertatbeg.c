#include<stdio.h>  
#include<stdlib.h>  
void insertbeginning(int);
void insertlast(int);
void traversal();
void deletebeginning(); 
void deletelast();
struct node  
{  
    int data;  
    struct node *next;  
    struct node *prev;  
};  
struct node *head;  
void main ()  
{  
    
insertbeginning(29);
insertbeginning(39);
insertlast(67);
// deletebeginning();
deletelast();
traversal();

}  
void insertbeginning(int item)  
{  
   
   struct node *ptr = (struct node *)malloc(sizeof(struct node));  
  
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
} 
void insertlast(int item){
  struct node *ptr = (struct node *) malloc(sizeof(struct node));  
   struct node *temp;  
    ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
       }  

}
void traversal(){
    struct node *temp;  
    if(head == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else   
    {  
        temp = head;  
        while(temp != NULL)  
        {  
            printf("%d\n",temp->data);  
            temp=temp->next;  
        }  
    }  
}
void deletebeginning()  
{  
     struct node *ptr;  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nNode Deleted\n"); 
} 
void deletelast()  
{  
     struct node *ptr;  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\n Last Node Deleted\n"); 
} 