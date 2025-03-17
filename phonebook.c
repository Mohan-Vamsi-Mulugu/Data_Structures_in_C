#include<string.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct phone{
 char name[30];
 char number[10];
 struct phone *next;
}phone;
phone *head=NULL;

void addContact();
void find();
void deleteContact();
void showContacts();


int main(){

 int x;
 printf("\t***welcome to phonebook***\n");
while(1){
 printf("\nOptions:\n1.Add Contact\t2.Show Contacts\t3.Find Contact\t4.Delete Contact\t5.Exit");
 printf("\nchoose one option: "); 
 scanf("%d",&x);
 switch(x){
 case 1:addContact();
	break;
 case 2:showContacts();
	break;
 case 3:find();
	break;
 case 4:deleteContact();
	break;
 case 5:exit(0);
 default: printf("incorrect choice,please try again!!");
}
}
}





void addContact(){
phone *temp=(phone *) malloc (sizeof(phone));
temp->next=NULL;
 printf("\nenter the name of the contact: ");
 scanf("%29s",temp->name);
 printf("enter the phone number: ");
 scanf("%9s",temp->number); 
  printf("\nContact name:%s \nPhone Number:%s\n",temp->name ,temp->number);
 if(head==NULL){
  head=temp;
  head->next=NULL;
}
 else{
 temp->next=head;
 head=temp;
}
}
void showContacts(){
 if(head==NULL)
  printf("the Phonebook is empty!!! ");
 else{
 phone *temp;
 temp=head;
 while (temp!=NULL){
  printf("\nContact name:%s \nPhone Number:%s\n",temp->name ,temp->number);
  temp=temp->next;
}
}

}

void find(){
 if(head==NULL){
 printf("the PhoneBook is empty!!");
}else{
phone *temp = head;
 printf("\n1.search by name\n2.search by number\nchoose an option:");
 int a;
 scanf("%d",&a);
 char target[30];
 if(a==1){
 printf("enter the name:");
 scanf("%s",target);
 while(temp!=NULL && strcmp(temp->name,target)!=0)
  temp=temp->next;
 if(temp!=NULL)
  printf("\nContact found\n name: %s \t phone no.: %s",temp->name,temp->number);
 else
  printf("\nContact not found");
}else if(a==2){
  printf("enter the number:");
 scanf("%s",target);
 while(temp!=NULL && strcmp(temp->number,target)!=0)
  temp=temp->next;
 if(temp!=NULL)
  printf("\nContact found\n name: %s \t phone no.: %s",temp->name,temp->number);
 else
  printf("\nContact not found");
}else
 printf("incorrect option");

}
}

void deleteContact()
{

 if(head ==NULL) 
  printf("\nPhoneBook is empty!!");

else{
phone *temp = head;
 phone *temp1=NULL;
 printf("\n1.Delete by name\n2.Delete by number\nchoose an option:");
 int a;
 scanf("%d",&a);
 char target[30];
 if(a==1){
 printf("enter the name:");
 scanf("%s",target);
 while(temp!=NULL && strcmp(temp->name,target)!=0){
  temp1=temp;
  temp=temp->next;
}if(strcmp(head->name,target)==0){
  temp=head;
  head=temp->next; 
 temp->next=NULL;
printf("\nContact deleted Successfully");
}else if(!strcmp(temp->name,target)){
  temp1->next=temp->next;
  temp->next = NULL;
  printf("\nContact deleted successfully");
}else
  printf("\nContact not found");
}else if(a==2){
  printf("enter the number:");
  scanf("%s",target);
  while(temp!=NULL && strcmp(temp->number,target)!=0){
  temp1=temp;
  temp=temp->next;
}if(strcmp(head->number,target)==0){
temp=head;
head=temp->next;
temp->next=NULL;
printf("\nContact deleted successfully\n");
}else if(!strcmp(temp->number,target)){
  temp1->next=temp->next;
  printf("Contact deleted successfully");
} else
  printf("\nContact not found");
}else
 printf("incorrect option");
free(temp);
}
}




