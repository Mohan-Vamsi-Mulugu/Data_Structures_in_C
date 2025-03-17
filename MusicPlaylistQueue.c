#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct MusicPlaylistQueue{
 struct MusicPlaylistQueue *next,*prev;
 char artist[30],name[30],duration[30];
}MPQ;

MPQ *head,*tail;

void enQueue();
void deQueue();
void showPlaylist();

void main(){
int choice;
printf("\t\t***Music Playlist Queue***");
while(1){
printf("\n1.enQueue\n2.deQueue\n3.Show Playlist");
printf("\n4.exit\n\tenteryour choice:");
scanf("%d",&choice);
getchar();
switch(choice){
 case 1: enQueue();
	 break;
 case 2: deQueue();
	 break;
 case 3: showPlaylist();
 	 break;
 case 4: exit(0);
 default: printf("please enter right choice!!");
}
}
}


void enQueue(){
 MPQ *temp=(MPQ*)malloc(sizeof(MPQ));
 printf("\nenter the artist name: ");
 fgets(temp->artist,sizeof(temp->artist),stdin);
 printf("enter the name of the song: ");
 fgets(temp->name,sizeof(temp->name),stdin);
 printf("enter the duration of the song: ");
 fgets(temp->duration,sizeof(temp->duration),stdin);
 if(tail== NULL){
 temp->next=NULL;
 temp->prev=NULL;
 head=temp;
 tail=temp;
}else{
 temp->prev=tail;
 temp->next=NULL;
 tail->next=temp;
 tail=temp;
}
printf("\nthe song added successfully\n");
}

void deQueue(){
if(head==NULL)
 printf("The queue is empty!!");
else{
 if(head!=tail){
 MPQ *temp;
 temp=tail;
 tail=tail->prev;
 temp->prev=NULL;
 free(temp);
}else{
 tail->next=NULL;
 tail->prev=NULL;
 free(tail);
 head=NULL;
}
 printf("\nsong deleted successfully");
}
}

void showPlaylist(){
if(head==NULL){
 printf("\nthe Queue is empty!!");
 return;
}
else{
 MPQ *temp;
 temp=head;
 printf("\nSongs list is:");
 while(temp!=NULL){
 printf("\n\tartist name:%s\tsong name:%s\tduration is:%s",temp->artist,temp->name,temp->duration);
 temp=temp->next;
}
}
}
