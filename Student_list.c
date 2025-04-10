#include<stdio.h>
#include<stdlib.h>

typedef struct Students{
	int roll;
	char name[25];
	struct Students *left,*right;
}stu;

stu *root =NULL;


void preorder(stu *);
void inorder(stu *);
void postorder(stu *);


void insert() {
    stu *temp = (stu*)malloc(sizeof(stu));
    printf("\nEnter student roll number: ");
    scanf("%d", &temp->roll);
    getchar(); 
    printf("Enter student name: ");
    fgets(temp->name, sizeof(temp->name), stdin);
    temp->left = temp->right = NULL;


  //  temp->name[strcspn(temp->name, "\n")] = 0;

    if (root == NULL) {
        root = temp;
        printf("Student added.\n");
        return;
    }

    stu *current = root, *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (temp->roll < current->roll)
            current = current->left;
        else
            current = current->right;
    }

    // Insert node under the parent
    if (temp->roll < parent->roll)
        parent->left = temp;
    else
        parent->right = temp;

    printf("Student added.\n");
}



void find(){
	if(root==NULL)
		printf("\nNo students available\n");
	else{
		int roll;
		stu *temp=root;
		printf("enter the roll:");
		scanf("%d",&roll);
		while(roll!=temp->roll && temp!=NULL){
			if(roll<temp->roll)
				temp=temp->left;
			else
				temp=temp->right;
		}
		if(roll==temp->roll)
			printf("\nstudent found: \nStudent name:%s",temp->name);		
		else
			printf("\nStudent not found!!\n");
	}
}



void traverse(){
	int choice;
	printf("\n1.PreOrder Traversal 2.InOrder Traversal 3.PostOrder Traversal\n");
	printf("enter your choice : ");
	scanf("%d",&choice);
	switch(choice){
		case 1:printf("\nPre-Order Traversal\n");
		       preorder(root);
		       break;
		case 2:printf("\nIn-Order Traversal\n");
		       inorder(root);
		       break;
		case 3:printf("\nPost-Order Traversal\n");
		       postorder(root);
		       break;
		default:printf("\ninvalid choice!!!\n");

	} 
}
void preorder(stu *root){
	if(root!=NULL){
		printf("\nstudent name: %s\t roll: %d",root->name,root->roll);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(stu *root){
	if(root!=NULL){
		inorder(root->left);
		printf("\nstudent name: %s\troll: %d",root->name,root->roll);
		inorder(root->right);
	}
}
void postorder(stu *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("\nstudent name: %s\troll: %d",root->name,root->roll);
	}
}


void main(){
	int choice;
	printf("\n\n***Student list Binary-Search Tree***\n");
	while(1){
		printf("\n1.add a student 2.find a student 3.Traverse 4.exit\n");
		printf("choose an option : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:insert();
			       break;
			case 2:find();
			       break;
			case 3:traverse();
			       break;
			case 4:exit(1);
			default:printf("invalid choice! Please try again\n");
		}
	}
}

