#include<stdio.h>
#include<string.h>

//Structure for the linked list
struct node{
int roll_no;
char name[70];
float cgpa;
struct node *next;
};

//Pointer to the start
struct node *start=NULL;

//Insertion at the first
void insertFirst()
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the name of the student:\t");
    fflush(stdin);
    scanf("%[^\n]s",p->name);
    printf("Enter the roll number:\t");
    scanf("%d",&p->roll_no);
    printf("Enter the CGPA:\t");
    scanf("%f",&p->cgpa);
    p->next=NULL;
    if(start==NULL){
        start=p;
    }
    else{
        p->next=start;
        start=p;
    }
}

//Insertion a the end of the list
void insertLast()
{
    struct node *p,*temp;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the name of the student:\t");
    fflush(stdin);
    scanf("%[^\n]s",p->name);
    printf("Enter the roll number:\t");
    scanf("%d",&p->roll_no);
    printf("Enter the CGPA:\t");
    scanf("%f",&p->cgpa);
    p->next=NULL;
    if(start==NULL){
        start=p;
    }
    else{
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=p;
    }
}

//Insertion in after the roll number
void insertInbetween()
{
    struct node *temp,*p;
    int n;
    temp=start;
    if(start==NULL){
        printf("The list is empty\n");
        return 0;
    }
    display();
    printf("Enter the roll number after which you want to insert the node:\t");
    scanf("%d",&n);
    while(temp!=NULL){
        if(temp->roll_no == n){
            p=(struct node *)malloc(sizeof(struct node));
            printf("Enter the name of the student:\t");
            fflush(stdin);
            scanf("%[^\n]s",p->name);
            printf("Enter the roll number:\t");
            scanf("%d",&p->roll_no);
            printf("Enter the CGPA:\t");
            scanf("%f",&p->cgpa);
            p->next=temp->next;
            temp->next=p;
            return 0;
        }
        temp=temp->next;
    }
    printf("The roll number doesn't exist\n");
}

//Delete the last node
void deleteLast()
{
    struct node *temp,*t;
    temp=start;
    if(start==NULL)
        printf("\nList is empty\n");
    else if(start->next==NULL)
    {
        free(start);
        start=NULL;
    }
    else{
        while(temp->next!=NULL)
        {
            t=temp;
            temp=temp->next;
        }
        free(t->next);
        t->next=NULL;
    }
}

//Delete the first node
void deleteFirst()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
        printf("\nThe list is empty\n");
    else{
        start=start->next;
        free(temp);
    }
}

//Deletion of the roll number entered
void deleteInbetween()
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

//Display all the elements
void display()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
        printf("\nThe list is empty\n");
    else{
        printf("ROLL NO\t\tNAME\t\tCGPA\n");
        while(temp!=NULL)
        {
            printf("%d\t\t%s\t\t%f\n",temp->roll_no,temp->name,temp->cgpa);
            temp=temp->next;
        }
    }
}
//Main
void main()
{
    int choice;
    while(1)
    {
        printf("\n==============================\n");
        printf("LINEAR LINKED LIST\n");
        display();
        printf("\n");
        printf("==============================\n");
        printf("1.INSERT AT BEGINNING\n2.INSERT AT END\n3.INSERT IN BETWEEN\n4.DELETE AT BEGINNING\n5.DELETE AT END\n");
        printf("6.DELETE IN BETWEEN\n7.SEARCH BY ROLL NUMBER\n8.SEARCH BY NAME\n9.SEARCH BY CGPA\n10.DISPLAY\n11.EXIT\n");
        printf("==============================\n");
        printf("Choose any one of the above:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertFirst();
                    break;
            case 2: insertLast();
                    break;
            case 4: deleteFirst();
                    break;
            case 5: deleteLast();
                    break;
            case 10: display();
                    break;
            case 7: searchByRoll();
                    break;
            case 8: searchByName();
                    break;
            case 9: searchByCGPA();
                    break;
            case 3: insertInbetween();
                    break;
            case 6: deleteInbetween();
                    break;
            default: printf("Invalid choice\n");
                    break;
            case 11: exit(0);

        }
    }
}


