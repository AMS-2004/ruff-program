#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
                  struct node
                  { 
                  	int data;
                  	struct node*Llink;
                  	struct node*Rlink;
                  	
                  	};
  struct node*head=NULL;
  
  void insertFirst()
  {
struct node*newnode;
newnode=(struct node *)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\n No Space Available");
return;
 }
        newnode->Llink=NULL;
        newnode->Rlink=NULL;
        printf("\n Enter the Element to insert:");
        scanf("%d",&newnode->data);
   if(head==NULL)
   {
   head=newnode;
   }
   else
   {
   newnode->Rlink=head;
   head->Llink=newnode;
   head=newnode;
   }
printf("\n %d Inserted successfully",newnode->data);
}

void insertLast()
{
struct node*newnode,*temp=head;
newnode=(struct node *)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\n Error:No Space Available for a new node.\n");
return;
}
 newnode->Llink=NULL;
 newnode->Rlink=NULL;
 printf("\n Enter the element to insert:");
 scanf("%d",&newnode->data);
 if(head==NULL)
 {
 head=newnode;
 }
 else
 {
 while(temp->Rlink!=NULL)
 {
 temp=temp->Rlink;
 }
 newnode->Llink=temp;
 temp->Rlink=newnode;
 }
 printf("%d Inserted successfully",newnode->data); 
  }
   void display()
   {
   struct node*temp=head;
   if(head==NULL)
     {
              printf("\n No Elements in list");
              return;
              }
else
{
printf("\n **ELEMENTS IN LIST** \n");
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->Rlink;
 }
 }
 }
void insertLocation()
{
struct node*newnode,*temp=head,*nxt;
int key;
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
 printf("\n Error :No Space available for a new node.\n");
 return;
 }
 if(head==NULL) {
    printf("\n List is empty. Inserting at first position.\n");
    head = newnode;
    newnode->Llink = newnode->Rlink = NULL;
    printf("%d Inserted successfully", newnode->data);
    return;
}

     else
     {
     printf("\n Enter the key where after you after you want to insert the element:\n");
     scanf("%d",&key);
  while(temp!=NULL && temp->data!=key)
  {
  temp=temp->Rlink;
  }
  if(temp==NULL)
  {
  printf("\n NO ELEMENT FOUND\n");
  return;
  }
printf("\n Enter the element to insert:\n");
scanf("%d",&newnode->data);
if(temp->Rlink==NULL)
{
newnode->Llink=temp;
newnode->Rlink=NULL;
temp->Rlink=newnode;
}
else
{
nxt=temp->Rlink;
newnode->Llink=temp;
newnode->Rlink=nxt;
temp->Rlink=newnode;
nxt->Llink=newnode;
}
printf("%d Inserted sucessfully",newnode->data);
}
}
void deleteFirst()
{
struct node*temp=head,*nxt;
  if(head==NULL)
  {
  printf("\n LIST EMPTY \n");
  return;
  }
  printf("\n %d is deleted",temp->data);
  if(temp->Rlink==NULL)
  {
  head=NULL;
  }
  else
  {
  nxt=temp->Rlink;
  head=nxt;
  nxt->Llink=NULL;
  }
  free(temp);
  }
  void deleteLast()
  {
struct node*temp=head,*nxt;
  if(head==NULL)
  {
  printf("\n LIST EMPTY \n");
  return;
  }
  
  if(temp->Rlink==NULL)
  {
  printf("\n %d is deleted",temp->data);
  head=NULL;
  }
  else
  {
  while(temp->Rlink!=NULL)
  {
  temp=temp->Rlink;
  }
  printf("\n %d is deleted",temp->data);
  nxt=temp->Llink;
  nxt->Rlink=NULL;
  }
 free(temp);
 }
 void deleteLocation()
 {
  struct node*temp =head,*prev,*next;
int key;
if(head==NULL)
{
printf("\n LISTS  IS EMPTY \n");
return;
}
printf("\n Enter the key which you want to delete:\n");
scanf("%d",&key);
while(temp!=NULL && temp->data!=key)
{
  temp=temp->Rlink;
}
if (temp == NULL)
{
printf("\n NO ELEMENT FOUND \n");
return;
}
if(temp->Llink == NULL) { // first node
    head = temp->Rlink;
    if(head != NULL) head->Llink = NULL;
} else if(temp->Rlink == NULL) { // last node
    temp->Llink->Rlink = NULL;
} else { // middle node
    temp->Llink->Rlink = temp->Rlink;
    temp->Rlink->Llink = temp->Llink;
}

printf("%d Deleted Successfully \n",temp->data);  
free(temp);
}

void search()
{
int key,pos=0,found=0;
struct node * temp=head;
if(head==NULL)
{
printf("\n LIST EMPTY\n");
return;
}
printf("\n Enter the key to search:");
scanf("%d",&key);
while(temp!=NULL)
{
if(temp->data==key)
{
printf("%d is found at location %d",temp->data,pos);
found=1;
}
temp=temp->Rlink;
pos++;
}
if(!found)
{
printf("\n ELEMENT NOT FOUND\n");
}
}
int main()
 {
int choice;
do
{
printf("\n ****DOUBLYLINKEDLIST****\n");
printf("\n1->InsertFirst\n2->InsertLast\n3->InsertLocation\n4->deleteFirst\n5->deleteLast\n6->deleteLocation\n7->search\n8->display\n9->Exit");
printf("\n ENTER THE CHOICE\n");
scanf("%d",&choice);

switch(choice)
{
 case 1:insertFirst();
       break;
 case 2:insertLast();
       break;
 case 3:insertLocation();
       break;
 case 4:deleteFirst();
       break;
 case 5:deleteLast();
       break;
 case 6:deleteLocation();
       break;
 case 7:search();
       break;
 case 8:display();
       break;
 case 9:printf("\nEXIT\n");
       break;
 default:printf("Enter a valid Choice");
       break;
     }
}
while(choice!=9);

}      
           


