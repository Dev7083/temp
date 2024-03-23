#include<stdio.h>  
#include<stdlib.h>  
void deletebeginning(int);
// void deletelast(int);
void traversal();
struct node  
{  
    int data;  
    struct node *next;  
    struct node *prev;  
};  
struct node *head;  
void main ()  
{
deletebeginning(29);
deletebeginning(39);
// deletelast(67);
traversal();

}  
void deletebeginning(int item)  
{  
     struct node *ptr;  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nNode Deleted\n"); 
} 
void deletelast(int item){
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