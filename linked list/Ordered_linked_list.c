#include<stdio.h>
//Program for ordered linked list based on the roll number.
//Structure for the linked list.
struct node{
int roll_no;
char name[70];
float cgpa;
struct node *next;
};

//start pointer to the list
struct node *start=NULL;

void insertion()
{
    struct node *p,*temp,*t;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the name of the student:\t");
    fflush(stdin);
    scanf("%[^\n]s",p->name);
    printf("Enter the roll number:\t");
    scanf("%d",&p->roll_no);
    printf("Enter the CGPA:\t");
    scanf("%f",&p->cgpa);
    p->next=NULL;

    //check if the list is empty
    if(start==NULL){
            start=p;
    }
    //check if the element is the smallest
    else if(p->roll_no < start->roll_no){
        p->next=start;
        start=p;

    }
    /*//check if only one element
    else if(start->next == NULL){
        if(start->roll_no < p->roll_no){
            start->next=p;
        }
    }*/
    else{
        temp=start;
        //search for the value of the temp bigger than p
        while(temp->next!=NULL && temp->next->roll_no <= p->roll_no)
        {
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
        }
}

//Deletion of the roll number entered
void deletion()
{
    struct node *temp,*t;
    int n;
    temp=start;
    if(start==NULL){
        printf("The list is empty\n");
    }
    display();
    printf("Enter the roll number which you want to delete:\t");
    scanf("%d",&n);
    while(temp!=NULL){
        if(start->next==NULL && start->roll_no==n)
        {
            t=start;
            free(t);
            start=NULL;
            return 0;
        }
        if(temp->roll_no == n){
            t->next=temp->next;
            free(temp);
            return 0;
        }
        t=temp;
        temp=temp->next;
    }
printf("There is no such element\n");
}
/*void deletion()
{
    struct node *temp,*t;
    int roll;
    //check if the list is empty.
    if(start==NULL){
        printf("DELETION NOT POSSIBLE AS THE LIST IS EMPTY\n");
        exit(0);
    }
    //searching begins for deletion
    printf("Enter the roll number to be deleted:\t");
    scanf("%d",&roll);
    //check if only one element present
    if(start->next==NULL && start->roll_no==roll){
        temp=start;
        free(temp);
        start=NULL;
        return 0;
    }
    //if not one element
    else{
        while(temp!=NULL){
            if(temp->roll_no == roll){
            t->next=temp->next;
            free(temp);
            printf("Deletion was successful\n");
            return 0;
            }
            t=temp;
            temp=temp->next;
        }
    }
    printf("There s no such roll number existing\n");
}*/

//Search by the roll number
void searchByRoll()
{
    struct node *temp;
    int roll;
    temp=start;
    printf("Enter the roll number:\t");
    scanf("%d",&roll);
    printf("\n");
    while(temp!=NULL)
    {
        if(temp->roll_no == roll)
        {
            printf("The Roll no. exist its details are:\n");
            printf("ROLL NO\t\tNAME\t\tCGPA\n");
            printf("%d\t\t%s\t\t%f\n",temp->roll_no,temp->name,temp->cgpa);
            return 0;
        }
        temp=temp->next;
    }
    printf("No such element exist\n");
}

//Search by name
void searchByName()
{
    struct node *temp;
    char name[70];
    int count=0;
    temp=start;
    printf("Enter the name number:\t");
    fflush(stdin);
    scanf("%[^\n]s",name);
    printf("\n");
    while(temp!=NULL)
    {
        if(strcmp(temp->name,name) == 0)
        {
            printf("The name exist its details are:\n");
            printf("ROLL NO\t\tNAME\t\tCGPA\n");
            printf("%d\t\t%s\t\t%f\n",temp->roll_no,temp->name,temp->cgpa);
            count++;
        }
        temp=temp->next;
    }
    if(count==0)
        printf("No such element exist\n");
}

//Search by cgpa
void searchByCGPA()
{
    struct node *temp;
    float cg;
    int count=0;
    temp=start;
    printf("Enter the CGPA number:\t");
    scanf("%f",&cg);
     while(temp!=NULL)
    {
        if(temp->cgpa == cg)
        {
            printf("The cgpa exist its details are:\n");
            printf("ROLL NO\t\tNAME\t\tCGPA\n");
            printf("%d\t\t%s\t\t%f\n",temp->roll_no,temp->name,temp->cgpa);
            count++;
        }
        temp=temp->next;
    }
    if(count==0)
        printf("No such element exist\n");
}

void display()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
        printf("\nThe list is currently empty\n");
    else{
        printf("ROLL NO\t\tNAME\t\tCGPA\n");
        while(temp!=NULL)
        {
            printf("%d\t\t%s\t\t%f\n",temp->roll_no,temp->name,temp->cgpa);
            temp=temp->next;
        }
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("\n==============================\n");
        printf("ORDERED LINKED LIST\n");
        display();
        printf("==============================\n");
        printf("1.INSERTION\n 2.DELETION BY ROLL NUMBER\n3.SEARCH BY NAME\n4.SEARCH BY ROLL NUMBER\n");
        printf("5.SEARCH BY CGPA\n6.DISPLAY\n7.EXIT\n");
        printf("==============================\n");
        printf("Choose any one of them:\t");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertion();
                    break;
            case 2: deletion();
                    break;
            case 3: searchByName();
                    break;
            case 4: searchByRoll();
                    break;
            case 5: searchByCGPA();
                    break;
            case 6: display();
                    break;
            case 7: exit(0);
            default: printf("Wrong choice entered\n");
                    break;
        }
    }
}

