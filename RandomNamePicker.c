#include<stdio.h>
#include<stdlib.h>

typedef struct  CircularStack{
 struct CircularStack *next;
 char name[30];
 int sno;
}CS;

CS *head=NULL;
int sno=1;

void push(){
CS *temp=(CS*) malloc (sizeof(CS));
printf("\nenter the participant name : ");
fgets(temp->name,sizeof(temp->name),stdin);
temp->sno=sno;
 sno++;
if(head==NULL){
 head=temp;
 head->next=head;
}
else{
CS *temp1=head;

 while(temp1->next!=head)
  temp1=temp1->next;
 temp1->next=temp;
 temp->next = head;
}
printf("\nparticipant added successfully \1");
}

void pop(){
if(head==NULL){
 printf("\nno participant available\n");
 return;
}else
{

 if(head->next!=head){
 sno--;
 CS *temp=head,*temp1;
 while(temp->next!=head){
 temp1=temp;
 temp=temp->next;
  }
 temp1->next=head;
 free(temp);
 temp=NULL;
 }else{
 free(head);
 head=NULL;
 sno=1;
}
}
printf("\nparticipant deleted successfully!");
}

void show(){
if(head==NULL){
 printf("\n no participants available\n");
 return;
}else{
 if(head->next==head)
 printf("\n sno: %d\tname: %s",head->sno,head->name);
else{
 CS *temp=head;
 do{
 printf("\n sno: %d\tname: %s",temp->sno,temp->name);
 temp=temp->next;
}while(temp!=head);
 
 
}
}
}


void randomPick()
{
 if(head==NULL){
 printf("\n no participants available!!");
 return;
 }
else if(head->next==head)
 printf("\n the only participant is %s ",head->name);
else{
 int rNumber=(rand() % (sno-1))+1;
 CS *temp =head;
 while(temp!=NULL && rNumber !=temp->sno)
  temp=temp->next;
 printf("\nThe lucky chosen name is %s",temp->name);
 }
}

void main(){
printf("\n\nRandom Name Picker\n\n");
printf("Description: push the names of the participants priority-wise,and start the random pick to get the random name out of the list of the participants.\nIf you want to remove a name you need to remove in the descresing order of priority.");
int choice=0;
while(1){
printf("\n1.push(add participant).\t2.pop(remove the latest participant).\n3.show participants list.\t4.get random participant.\n5.exit.\n\n");
printf("enter your choice:");
scanf("%d",&choice);
getchar();
switch(choice)
{
 case 1:push();
	break;
 case 2:pop();
	break;
 case 3:show();
	break;
 case 4:randomPick();
	break;
 case 5:exit(0);

 default: printf("\nplease enter right choice \2 !!!");
}
}
}
