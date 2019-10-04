#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct nodeType{
     int data;
     struct nodeType* link;
} *root;

root head=NULL,tail=NULL;

root create(){
    root temp=(root*)malloc(sizeof(root));
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    return temp;
}

void insertAtLast(){
     root temp=create();
     if(head == NULL){
	  head = temp;
	  tail = temp;
	  head->link = head;
     }


     else{
	    tail->link = temp;
	    tail = temp;
	    tail->link = head;
     }
}

void insertAtFirst(){

    root ptr=create();
    if(head == NULL){
	   head = ptr;
	   tail = ptr;
	   head->link = head;
    }
    else{
	   ptr->link = head;
	   head = ptr;
	   tail->link = head;
    }
}

void insertAfterANode(){
      root temp=create(), ptr=head, ktr=NULL;
      int n;
      printf("\nBefore which number you want insert: ");
      scanf("%d",&n);
      while(ptr->data != n){ ktr = ptr; ptr=ptr->link;}
      temp->link = ptr;
      ktr->link = temp;
}

void deleteFromFirst(){
    root temp = head;
    if(temp == head){
	temp = head;
	head = head->link;
	tail->link = head;
	free(temp);
    }
}

void deleteFromLast(){
      root temp = head, ctr=NULL, ktr=NULL;
      while(temp->link != head){
	   ctr = temp;
	   temp=temp->link;
      }
	ktr = temp;
	tail = ctr;
	tail->link = head;
	free(ktr);
}

void deleteFromAnywhere(){
      root temp = head, ptr=NULL;
      int n;
      printf("\nEnter the number you want to delete: ");
      scanf("%d",&n);
      while(temp->data != n){  ptr = temp; temp=temp->link;}
      ptr->link  = temp->link;
      free(temp);

}

void display(){
      root temp=head;
      printf("%d",temp);
      while(temp->link != head){
	  printf("\n%d     %d",temp->data,temp->link);
	  temp = temp->link;
      }
      printf("\n%d     %d",temp->data,temp->link);
}

int main(){
       int n;
       clrscr();
       while(1){
	   printf("\n1. insertAtFirst\n2. insertAtLast\n3. insertAfterANode\n4. deleteFromFirst\n5. deleteFromLast\n6. deleteFromAnywhere\n7. display\n8. Exit\n>>");
	   scanf("%d",&n);
	   if(n==1) insertAtFirst();
	   else if(n==2) insertAtLast();
	   else if(n==3) insertAfterANode();
	   else if(n==4) deleteFromFirst();
	   else if(n==5) deleteFromLast();
	   else if(n==6) deleteFromAnywhere();
	   else if(n==7) display();
	   else break;
       }
       return 0;
}

