// circular singly linked list

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}Node;

Node* create_node()
{
Node* new_node = (Node*)malloc(sizeof(Node));
if(new_node==NULL)
  {
  printf("computer memory is full\n");
  exit(0);
  }
  return new_node;
}

Node* insert_begin(Node* start,int val)
{
  Node *new_node,*ptr;
  new_node=create_node();
  new_node->data=val;
  if(start==NULL)
  {
    start=new_node;
    start->next=start;
  }
  else
  {
    ptr=start;
    while(ptr->next!=start)
    {
      ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=start;
    start=new_node;
    return start;
  }
}
Node *insert_end(Node *start,int val)
{
  Node *new_node,*ptr;
  new_node=create_node();
  new_node->data=val;
    if(start==NULL)
  {
    start=new_node;
    new_node->next=start;
  }
  else
  {
    ptr=start;
    while(ptr->next!=start)
    {
      ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=start;
  }
return start;
}



void display(Node *start)
{
  if(start==NULL)
  {
    printf("list is empty\n");
     return;
  }
  Node *ptr=start;
  while(ptr->next!=start)
  {
    printf("%d->",ptr->data);
    ptr=ptr->next;
  }
  printf("%d->",ptr->data);
}

Node *delete_begin(Node *start)
{

  if(start==NULL)
  {
  printf("empty list\n");
  exit(0);
  }
if(start->next==start)
  {
  free(start);
  start=NULL;
  }
else
{
  Node *ptr=start;
  while(ptr->next!=start)
  {
  ptr=ptr->next;
  }
  ptr->next=start->next;
   printf("deleted value is %d\n",ptr->data);
  free(start);
  start=ptr->next;
}
return start;
}

Node *delete_end(Node *start)
{
if(start==NULL)
  {
  printf("empty list\n");
  exit(0);
  }
if(start->next==start)
    {
    free(start);
    start=NULL;
    }
else
  {
Node *ptr=start;
Node *preptr=start;
while(ptr->next!=start)
  {
    preptr=ptr;
     ptr=ptr->next;
  }
  preptr->next=start;
   printf("deleted value is %d\n",ptr->data);
  free(ptr);
 }

 return start;
}



int main()
{
Node *start=NULL;
int ch;
while(1)
{

    printf("\n1.insert at begining\n2.insert at end\n3.delete at begining\n4.delete at end\n5.display\n6.exit\nur choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
    {
      printf("ENter the element that needs to be inserted\n");
      int val;
      scanf("%d",&val);
    start=insert_begin(start,val);
    }
    break;


    case 2:
    {
      printf("ENter the element that needs to be inserted\n");
      int val;
      scanf("%d",&val);
      start=insert_end(start,val);
    }
      break;

     case 3:
    {
        start=delete_begin(start);
    printf("the  val is deleted at begining \n");
   }
     break;
    case 4:
    {
      start=delete_end(start);
      printf("the  val is deleted at ending \n");
    }
      break;

    case 5:
    {
    display(start);
    }
    break;

 case 6:
    {
    exit(0);
    break;
    }
    break;
    
    default:
    {
      exit(0);
    }
  }
}
return 0;

}// doubly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{

    int data;
    struct node *next;
      struct node *prev;
}Node;

Node* create_node()
{
Node*ptr=(Node*)malloc(sizeof(Node));
if(ptr==NULL)
  {
  printf("computer memory is full\n");
  exit(0);
  }
  return ptr;
}


void is_empty(Node * start)
{
 if(start==NULL)
 {
printf("list is empty\n");
exit(0);
 }
}



Node * insert_begin(Node * start, int val)
{
Node * new_node=create_node();
new_node->prev=NULL;
new_node->data=val;
if(start==NULL)
{
  new_node->next=NULL;
}
else
{
  new_node->next=start;
  start->prev=new_node;
}
start=new_node;
return start;
}

Node * insert_end(Node *start,int val)
{
  Node *new_node=create_node();
  new_node->next=NULL;
  new_node->data=val;
  if(start==NULL)
  {
    new_node->prev=NULL;
    start=new_node;

  }
  else
  {
    Node *ptr=start;
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;

    }
    ptr->next=new_node;
    new_node->prev=ptr;
  }
  return start;
}


Node * delete_begin(Node *start)
{

  is_empty(start);
  Node *ptr=start;
  if(start->next==NULL)
  {
    start=NULL;
  }
  else
  {
    start=start->next;
    start->prev=NULL;
  }
  printf("deleted value is %d",ptr->data);
  free(ptr);
    return start;
}


Node *delete_end(Node *start)
{
  is_empty(start);
  Node *ptr=start;
  if(start->next==NULL)
  {
    start=NULL;
  }
  else
  {
   while(ptr->next!=NULL)
   {
     ptr=ptr->next;
     ptr->prev->next=NULL;
   }
 }
 printf("deleted value is %d",ptr->data);
 free(ptr);
return start;
}


int getsize(Node *start)
{
  int size=0;
  Node *ptr=start;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
    size++;
  }
  size++;
  return size;
}



Node *insert_position(Node *start,int pos, int val)
{
Node *new_node=(Node *)malloc(sizeof(Node));
new_node->data=val;
new_node->next=NULL;
new_node->prev=NULL;
int size=getsize(start);
if(pos<0||pos>size+1)
{
  printf("INvalid position\n");
  return start;
}

if(pos==1)
{
  new_node->next=start;
  start->prev=new_node;
  start=new_node;
  return start;
}

Node *ptr=start;
int i=1;
while(i!=pos-1)
{
  ptr=ptr->next;
  i++;
}
new_node->next = ptr->next;
ptr->next->prev = new_node;
ptr->next = new_node;
new_node->prev = ptr;
return start;
}

Node* delete_at_position(Node* start, int pos)
{
    int size = getsize(start);
    if(pos < 0 || pos > size+1)
    {
        printf("Invalid position.\n");
        return start;
    }
    Node* ptr = start;
    if(pos == 1)
    {
        start = start->next;
        free(ptr);
        return start;
    }
    int i = 1;
    while(i != pos-1)
    {
        ptr = ptr->next;
        i++;
    }
    Node* temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted value is %d\n", temp->data);
    free(temp);
    return start;
}




void display(Node *start)
{
  if (start == NULL)
  {
    printf("LINK LIST IS EMPTY\n");
return;
  }
  Node*ptr=start;
  while(ptr!=NULL)
  {
    printf("%d",ptr->data);
    ptr=ptr->next;
    printf("->");
  }
  printf("\n");
}




int main()
{
Node * start=NULL;
int ch;
while(1)
{
  printf("1.insert begin\n2.insert end\n3.delete begin\n4.delete end\n5.insert at specific pos\n6.delete at specific position\n7.display\nur choice");
  scanf("%d",&ch);
  switch (ch)
  {
    case 1:
    {
      int val;
      printf("enter value to be inserted\n");
      scanf("%d",&val);
      start=insert_begin(start,val);
    }
    break;

    case 2:
    {
      int val;
      printf("enter value to be inserted\n");
      scanf("%d",&val);
      start=insert_end(start,val);

    }
    break;


    case 3:
    {
        start=delete_begin(start);
        printf("the value at begining is deleted\n");
    }
    break;

    case 4:
    {
         start=delete_end(start);
         printf("the value at the end is deleted\n");
    }
    break;

    case 5:
    {
          int pos;
          printf("enter the position at which u want to insert\n");
          scanf("%d",&pos);
          int val;
          printf("enter the value to be inserted\n");
          scanf("%d",&val);
          start=insert_position(start,pos,val);
    }
    break;


    case 6:
    {
      int pos;
      printf("Enter the position at which the value needs to be deleted: ");
      scanf("%d", &pos);
    start = delete_at_position(start, pos);
   }
    break;

    case 7:
    {

display(start);

    }
    break;


    default:
    {
      exit(0);
    }

  }
}

  return 0;

}
\\singly linked list

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node 
{
  int data;
  struct node *next;
}Node;


Node *create_node()
{
  Node* new_node=(Node*) malloc(sizeof(Node));
  if (new_node == NULL)
  {
    printf("computer memory is full\n");
    exit(0);
  }
  return new_node;
}

int getcurrent_size(Node* start)
{
int size=0;
Node *ptr=start;
while(ptr->next!=NULL)
{
  ptr=ptr->next;
  size++;
}
size++;
return size;
}




Node *insert_begin(Node *start,int val)
{

  Node *new_node=create_node();
  new_node->data=val;
  if(start==NULL)
  {
    new_node->next=NULL;
  }
    new_node->next=start;
    start=new_node;
    return start;
}


Node *insert_end(Node *start,int val)
{
  Node *new_node=create_node();
  new_node->data=val;
  new_node->next=NULL;

  if(start==NULL)
  {
    start=new_node;
    return start;
  }
  Node *ptr=start;
 while(ptr->next!=NULL)
 {
   ptr=ptr->next;
 }
ptr->next=new_node;
return start;
}

Node *insert_position(Node *start,int val,int pos)

{
  Node* new_node=create_node();
  new_node->data=val;
  new_node->next=NULL;
  int size=getcurrent_size(start);
  if(pos<0||pos>size+1)
  {
    printf("Invalid position\n");
    return start;
  }
  if (pos==1)
  {
    new_node->next=start;
    start=new_node;
    return start;
  }
  Node *ptr=start;
  int i=1;
  while(i!=pos-1)
  {
    ptr=ptr->next;
    i++;
  }
  new_node->next=ptr->next;
  ptr->next=new_node;
  return start;

}

Node* delete_position(Node*start,int pos)
{
  int size=getcurrent_size(start);
  if(pos<0||pos>size+1)
  {
    printf("Invalid position\n");
    return start;
  }

  Node *ptr=start;
  if (pos==1)
  {
  start=start->next;
  free(ptr);
  return start;
  }
  int i=1;
  while(i!=pos-1)
  {
    ptr=ptr->next;
    i++;
  }

  Node* temp=ptr->next;
  ptr->next=ptr->next->next;
  printf("deleted val is %d\n",temp->data);
  free(temp);
  return start;




}










Node *delete_begin(Node *start)
{
   if (start==NULL)
    {
  return start;
    }
  Node *ptr=start;
  int val=start->data;
  printf("the deleted element is %d",val);
  if(ptr->next==NULL)
  {
    free(ptr);
  return start;
  }
  start=start->next;
  free(ptr);
  return start;
}

Node *delete_end(Node *start)
{
  if (start==NULL)
  {
    return NULL;
  }
  Node *ptr=start;
  if(ptr->next==NULL)
  {
    free(ptr);
    return NULL;
  }
  while(ptr->next!=NULL)
  {
    Node *prevptr=start;
    ptr=start->next;
      while(ptr->next!=NULL)
        {
        prevptr=ptr;
        ptr=ptr->next;
        }
      prevptr->next=NULL;

  printf("deleted val is %d",ptr->data);
}
  free(ptr);
  return start;
}

void display(Node *start)
{
  if (start == NULL)
  {
    printf("LINK LIST IS EMPTY");

  }
  Node*ptr=start;
  while(ptr!=NULL)
  {
    printf("%d",ptr->data);
    ptr=ptr->next;
    printf("->");
  }
  printf("\n");
}

int main()
{
  Node *start=NULL;
  int ch;


  while(1)
  {

      printf("\n1.insert at begining\n2.insert at end\n3.delete at begining\n4.delete at end\n5.intert at particular position\n6.delete at particular position\n7.display\nur choice\n");
      scanf("%d",&ch);
      switch(ch)
      {
      case 1:
      {
        printf("ENter the element that needs to be inserted\n");
        int val;
        scanf("%d",&val);
      start=insert_begin(start,val);
      }
      break;


      case 2:
      {
        printf("ENter the element that needs to be inserted\n");
        int val;
        scanf("%d",&val);
        start=insert_end(start,val);
      }
        break;

       case 3:
      {
          start=delete_begin(start);
      printf("the  val is deleted at begining \n");
     }
       break;
      case 4:
      {
        start=delete_end(start);
        printf("the  val is deleted at ending \n");
      }
        break;

      case 5:
      {
          int pos,val;
          printf("enter the position at which u want the value to bw inserted\n");
          scanf("%d",&pos);
          printf("enter the value to be inserted\n");
          scanf("%d",&val);
          start=insert_position(start,val,pos);
      }
     break;

     case 6:
     {
       int pos,val;
       printf("enter the position at which u want the value to bw deleted\n");
       scanf("%d",&pos);

       start=delete_position(start,pos);

     }
    break;



      case 7:
      {
      display(start);
      }
      break;

      default:
      {
        exit(0);
      }

    }
  }
  return 0;
}
