#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct node *create_ll();
struct node *display(struct node *s);
struct node *insert_end();
struct node *insert_aftpos();
struct node *insert_beginning();
struct node *delete_beg();
struct node *delete_end();
struct node *swap_node();
struct node *delete_aftpos();

struct node1 *create_ll1();
struct node1 *display1(struct node1 *s);
struct node1 *insert_end1();
struct node1 *insert_aftpos1();
struct node1 *insert_beginning1();
struct node1 *delete_beg1();
struct node1 *delete_end1();
struct node1 *swap_node1();
struct node1 *delete_aftpos1();

struct node
{
    struct node * next;
    int flight_no;
    int landing;
    int departure;
    int passengers;
    char source[50];
    char destination[50];
    char pilotname[50];
    char gate[2];
};

struct node1
{
    struct node1 * next1;
    int flight_no1;
    int landing1;
    int departure1;
    int passengers1;
    char source1[50];
    char destination1[50];
    char pilotname1[50];
    char gate1[2];

};
struct node * start=NULL;


int main()
{

    int n;
    int o;
    int a;
    int b;
    do
    {
        printf("\n\n____Main Menu____\n");
        printf("\n   1:Arrivals");
        printf("\n   2:Departure");
        printf("\n   3:Exit");
        printf("\n\nEnter your option: ");
        scanf("%d",&o);
        switch(o)
        {
        case 1:
        {
            do
            {
                printf("\n____________ARRIVALS____________\n");
                printf("\n 1:Create a schedule of all flights arriving today");
                printf("\n 2:Add a flight");
                printf("\n 3:Cancel a flight");
                printf("\n 4:Swap positions of two flights");
                printf("\n 5:Display the list");
                printf("\n 6:Exit");
                printf("\n\nEnter your option: ");
                scanf("%d",&n);
                switch(n)
                {
                case 1:
                    start=create_ll();
                    break;
                case 2:
                    printf("\n------ADDING A FLIGHT------");
                    printf("\n\n 1)Insert at the end\n 2)Insert at beginning\n 3)Insert after position\n");
                    printf("\nEnter your choice: ");
                    scanf("%d",&a);
                    switch(a)
                    {
                    case 1:
                        start=insert_end();
                        break;
                    case 2:
                        start=insert_beginning();
                        break;
                    case 3:
                        start=insert_aftpos();
                        break;

                    }
                    break;
                case 3:
                    printf("1)Delete at the end\n2)Delete at beginning\n3)Delete after position\n");
                    scanf("%d",&b);
                    switch(b)
                    {
                    case 1:
                        start=delete_end();
                        break;
                    case 2:
                        start=delete_beg();
                        break;
                    case 3:
                        start=delete_aftpos();
                        break;
                    }
                case 4:
                    start=swap_node();
                    break;
                case 5:
                    start=display(start);
                    break;
                }
            }
            while(n!=6);

        }
        case 2:
        {
            do
            {
                printf("\n____________DEPARTURE____________\n");
                printf("\n 1:Create a schedule of all flights departing today");
                printf("\n 2:Add a flight");
                printf("\n 3:Cancel a flight");
                printf("\n 4:Swap positions of two flights");
                printf("\n 5:Display the list");
                printf("\n 6:Exit");
                printf("\n\nEnter your option: ");
                scanf("%d",&n);
                switch(n)
                {
                case 1:
                    start=create_ll1();
                    break;
                case 2:
                    printf("\n------ADDING A FLIGHT------");
                    printf("\n\n 1)Insert at the end\n 2)Insert at beginning\n 3)Insert after position\n");
                    printf("\nEnter your choice: ");
                    scanf("%d",&a);
                    switch(a)
                    {
                    case 1:
                        start=insert_end1();
                        break;
                    case 2:
                        start=insert_beginning1();
                        break;
                    case 3:
                        start=insert_aftpos1();
                        break;

                    }
                    break;
                case 3:
                    printf("1)Delete at the end\n2)Delete at beginning\n3)Delete after position\n");
                    scanf("%d",&b);
                    switch(b)
                    {
                    case 1:
                        start=delete_end1();
                        break;
                    case 2:
                        start=delete_beg1();
                        break;
                    case 3:
                        start=delete_aftpos1();
                        break;
                    }
                case 4:
                    start=swap_node1();
                    break;
                case 5:
                    start=display1(start);
                    break;
                }
            }
            while(n!=6);

        }

        }
        while(o!=3);
    }
    getch();
    return 0;
}

struct node *create_ll()
{
    struct node *new_node,*ptr;
    int flight_no,landing,departure,passengers;
    char source[50],destination[50],pilotname[50],gate[2];
    int num=0;
    while(num==0)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("\n\n--------DETAILS--------\n");
        printf("\n Enter the flightno: ");
        scanf("%d",&flight_no);
        printf("\n Enter the landing time: ");
        scanf("%d",&landing);
        printf("\n Enter the departure time: ");
        scanf("%d",&departure);
        printf("\n Enter the no of passengers: ");
        scanf("%d",&passengers);
        printf("\n Enter the source: ");
        scanf("%s",&source);
        printf("\n Enter the destination: ");
        scanf("%s",&destination);
        printf("\n Enter the pilot name: ");
        scanf("%s",&pilotname);
        printf("\n Enter the gate: ");
        scanf("%s",&gate);

        new_node->flight_no=flight_no;
        new_node->landing=landing;
        new_node->departure=departure;
        new_node->passengers=passengers;
        strcpy(new_node->source,source);
        strcpy(new_node->destination,destination);
        strcpy(new_node->pilotname,pilotname);
        strcpy(new_node->gate,gate);
        if(start==NULL)
        {
            new_node->next=NULL;
            start=new_node;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=new_node;
            new_node->next=NULL;
        }
        printf("\nEnter 0 to continue : ");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *s)
{
    struct node *ptr;
    ptr=s;
    printf("\n Flight No.  |  Landing  |  Departure  |  Passengers  |    Source    |    Destination   |    Pilot Name    |   Gate \n\n");
    while(ptr!=NULL)
    {

        printf("  %d",ptr->flight_no);
        printf("\t\t%d",ptr->landing);
        printf("\t\t%d",ptr->departure);
        printf("\t\t%d",ptr->passengers);
        printf("\t\t%s",ptr->source);
        printf("\t\t %s",ptr->destination);
        printf("\t%s",ptr->pilotname);
        printf("\t\t%s",ptr->gate);
        printf("\n\n");
        ptr=ptr->next;
    }
    return s;
}
struct node *insert_end()
{
    struct node *ptr,*new_node;
    int flight_no,landing,departure,passengers;
    char source[50],destination[50],pilotname[50],gate[2];
    new_node=(struct node *)malloc(sizeof(struct node));

    printf("\n\n--------DETAILS--------\n");
    printf("\n Enter the flightno: ");
    scanf("%d",&flight_no);
    printf("\n Enter the landing time: ");
    scanf("%d",&landing);
    printf("\n Enter the departure time: ");
    scanf("%d",&departure);
    printf("\n Enter the no of passengers: ");
    scanf("%d",&passengers);
    printf("\n Enter the source: ");
    scanf("%s",&source);
    printf("\n Enter the destination: ");
    scanf("%s",&destination);
    printf("\n Enter the pilot name: ");
    scanf("%s",&pilotname);
    printf("\n Enter the gate: ");
    scanf("%s",&gate);

    new_node->flight_no=flight_no;
    new_node->landing=landing;
    new_node->departure=departure;
    new_node->passengers=passengers;
    strcpy(new_node->source,source);
    strcpy(new_node->destination,destination);
    strcpy(new_node->pilotname,pilotname);
    strcpy(new_node->gate,gate);
    new_node->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=new_node;
    return start;
}

struct node *insert_aftpos()
{
    struct node *ptr,*new_node,*temp;
    int flight_no,landing,departure,passengers,p,c=1;
    char source[50],destination[50],pilotname[50],gate[2];
    printf("\nEnter the position after which to add data:");
    scanf("%d",&p);
    printf("\nEnter the flightno:");
    printf("\nEnter the landing time:");
    printf("\nEnter the departure time:");
    printf("\nEnter the no of passengers:");
    printf("\nEnter the source:");
    printf("\nEnter the destination");
    printf("\nEnter the pilot name");
    printf("\nEnter the gate");
    scanf("%d",&flight_no);
    scanf("%d",&landing);
    scanf("%d",&departure);
    scanf("%d",&passengers);
    scanf("%s",&source);
    scanf("%s",&destination);
    scanf("%s",&pilotname);
    scanf("%s",&gate);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->flight_no=flight_no;
    new_node->landing=landing;
    new_node->departure=departure;
    new_node->passengers=passengers;
    strcpy(new_node->source,source);
    strcpy(new_node->destination,destination);
    strcpy(new_node->pilotname,pilotname);
    strcpy(new_node->gate,gate);
    ptr=start;
    while(c!=p)
    {
        ptr=ptr->next;
        c++;
    }
    temp=ptr->next;
    ptr->next=new_node;
    new_node->next=temp;
    return start;
}

struct node *insert_beginning()
{
    struct node *ptr,*new_node;
    int flight_no,landing,departure,passengers;
    char source[50],destination[50],pilotname[50],gate[2];
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the flightno:");
    printf("\nEnter the landing time:");
    printf("\nEnter the departure time:");
    printf("\nEnter the no of passengers:");
    printf("\nEnter the source:");
    printf("\nEnter the destination");
    printf("\nEnter the pilot name");
    printf("\nEnter the gate");
    scanf("%d",&flight_no);
    scanf("%d",&landing);
    scanf("%d",&departure);
    scanf("%d",&passengers);
    scanf("%s",&source);
    scanf("%s",&destination);
    scanf("%s",&pilotname);
    scanf("%s",&gate);
    new_node->flight_no=flight_no;
    new_node->landing=landing;
    new_node->departure=departure;
    new_node->passengers=passengers;
    strcpy(new_node->source,source);
    strcpy(new_node->destination,destination);
    strcpy(new_node->pilotname,pilotname);
    strcpy(new_node->gate,gate);
    if(start==NULL)
    {
        new_node->next=NULL;
        start=new_node;
    }
    else
    {
        new_node->next=start;
        start=new_node;
    }
    return start;
}

struct node *delete_beg()
{

    struct node *ptr;
    if(start==NULL)
        printf("list is empty");
    else
    {
        ptr=start;
        start=start->next;
        free(ptr);
    }
    return start;
}

struct node *delete_end()
{
    struct node *ptr,*preptr;
    if(start==NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        ptr=start->next;
        preptr=start;
        while(ptr->next !=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(preptr == start)
        {
            start=NULL;
        }
        else
        {
            preptr->next=NULL;
        }
        free(ptr);
    }
    return start;
}

struct node *swap_node()
{
    struct node *ptr1,*ptr2,*temp11,*temp22,*temp1,*temp2;
    int p1,p2;
    int c;
    printf("\nEnter 1st Position:");
    scanf("%d",&p1);
    printf("\nEnter 2nd Position:");
    scanf("%d",&p2);
    c=1;
    ptr1=start->next;
    temp1=start;
    while(c!=p1-1)
    {
        temp1=ptr1;
        ptr1=ptr1->next;
        c++;
    }
    ptr2=start->next;
    temp2=start;
    c=1;
    while(c!=p2-1)
    {
        temp2=ptr2;
        ptr2=ptr2->next;
        c++;
    }
    temp11=ptr1->next;
    temp22=ptr2->next;
    temp1->next=ptr2;
    ptr2->next=temp11;
    temp2->next=ptr1;
    ptr1->next=temp22;
    return start;
}

struct node *delete_aftpos()
{
    struct node *ptr,*preptr;
    int r=1,q;
    printf("Enter the position to delete");
    scanf("%d",&q);
    if(start==NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        ptr=start->next;
        preptr=start;
        while(r!=q)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(preptr == start)
        {
            start=NULL;
        }
        else
        {
            preptr= ptr->next;
        }
        free(ptr);
    }
    return start;
}



struct node1 *create_ll1()
{
    struct node1 *new_node1,*ptr;
    int flight_no1,landing1,departure1,passengers1;
    char source1[50],destination1[50],pilotname1[50],gate1[2];
    int num=0;
    while(num==0)
    {
        new_node1=(struct node1 *)malloc(sizeof(struct node1));
        printf("\n\n--------DETAILS--------\n");
        printf("\n Enter the flightno: ");
        scanf("%d",&flight_no1);
        printf("\n Enter the landing1 time: ");
        scanf("%d",&landing1);
        printf("\n Enter the departure1 time: ");
        scanf("%d",&departure1);
        printf("\n Enter the no of passengers1: ");
        scanf("%d",&passengers1);
        printf("\n Enter the source1: ");
        scanf("%s",&source1);
        printf("\n Enter the destination1: ");
        scanf("%s",&destination1);
        printf("\n Enter the pilot name: ");
        scanf("%s",&pilotname1);
        printf("\n Enter the gate1: ");
        scanf("%s",&gate1);

        new_node1->flight_no1=flight_no1;
        new_node1->landing1=landing1;
        new_node1->departure1=departure1;
        new_node1->passengers1=passengers1;
        strcpy(new_node1->source1,source1);
        strcpy(new_node1->destination1,destination1);
        strcpy(new_node1->pilotname1,pilotname1);
        strcpy(new_node1->gate1,gate1);
        if(start==NULL)
        {
            new_node1->next=NULL;
            start=new_node1;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=new_node1;
            new_node1->next=NULL;
        }
        printf("\nEnter 0 to continue : ");
        scanf("%d",&num);
    }
    return start;
}

struct node1 *display1(struct node1 *s)
{
    struct node1 *ptr;
    ptr=s;
    printf("\n Flight No.  |  landing1  |  departure1  |  passengers1  |    source1    |    destination1   |    Pilot Name    |   gate1 \n\n");
    while(ptr!=NULL)
    {

        printf("  %d",ptr->flight_no1);
        printf("\t\t%d",ptr->landing1);
        printf("\t\t%d",ptr->departure1);
        printf("\t\t%d",ptr->passengers1);
        printf("\t\t%s",ptr->source1);
        printf("\t\t %s",ptr->destination1);
        printf("\t%s",ptr->pilotname1);
        printf("\t\t%s",ptr->gate1);
        printf("\n\n");
        ptr=ptr->next;
    }
    return s;
}
struct node1 *insert_end1()
{
    struct node1 *ptr,*new_node1;
    int flight_no1,landing1,departure1,passengers1;
    char source1[50],destination1[50],pilotname1[50],gate1[2];
    new_node1=(struct node1 *)malloc(sizeof(struct node1));

    printf("\n\n--------DETAILS--------\n");
    printf("\n Enter the flightno: ");
    scanf("%d",&flight_no1);
    printf("\n Enter the landing1 time: ");
    scanf("%d",&landing1);
    printf("\n Enter the departure1 time: ");
    scanf("%d",&departure1);
    printf("\n Enter the no of passengers1: ");
    scanf("%d",&passengers1);
    printf("\n Enter the source1: ");
    scanf("%s",&source1);
    printf("\n Enter the destination1: ");
    scanf("%s",&destination1);
    printf("\n Enter the pilot name: ");
    scanf("%s",&pilotname1);
    printf("\n Enter the gate1: ");
    scanf("%s",&gate1);

    new_node1->flight_no1=flight_no1;
    new_node1->landing1=landing1;
    new_node1->departure1=departure1;
    new_node1->passengers1=passengers1;
    strcpy(new_node1->source1,source1);
    strcpy(new_node1->destination1,destination1);
    strcpy(new_node1->pilotname1,pilotname1);
    strcpy(new_node1->gate1,gate1);
    new_node1->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=new_node1;
    return start;
}

struct node1 *insert_aftpos1()
{
    struct node1 *ptr,*new_node1,*temp;
    int flight_no1,landing1,departure1,passengers1,p,c=1;
    char source1[50],destination1[50],pilotname1[50],gate1[2];
    printf("\nEnter the position after which to add data:");
    scanf("%d",&p);
    printf("\nEnter the flightno:");
    printf("\nEnter the landing1 time:");
    printf("\nEnter the departure1 time:");
    printf("\nEnter the no of passengers1:");
    printf("\nEnter the source1:");
    printf("\nEnter the destination1");
    printf("\nEnter the pilot name");
    printf("\nEnter the gate1");
    scanf("%d",&flight_no1);
    scanf("%d",&landing1);
    scanf("%d",&departure1);
    scanf("%d",&passengers1);
    scanf("%s",&source1);
    scanf("%s",&destination1);
    scanf("%s",&pilotname1);
    scanf("%s",&gate1);
    new_node1=(struct node1 *)malloc(sizeof(struct node1));
    new_node1->flight_no1=flight_no1;
    new_node1->landing1=landing1;
    new_node1->departure1=departure1;
    new_node1->passengers1=passengers1;
    strcpy(new_node1->source1,source1);
    strcpy(new_node1->destination1,destination1);
    strcpy(new_node1->pilotname1,pilotname1);
    strcpy(new_node1->gate1,gate1);
    ptr=start;
    while(c!=p)
    {
        ptr=ptr->next;
        c++;
    }
    temp=ptr->next;
    ptr->next=new_node1;
    new_node1->next=temp;
    return start;
}

struct node1 *insert_beginning1()
{
    struct node1 *ptr,*new_node1;
    int flight_no1,landing1,departure1,passengers1;
    char source1[50],destination1[50],pilotname1[50],gate1[2];
    new_node1=(struct node1 *)malloc(sizeof(struct node1));
    printf("\nEnter the flightno:");
    printf("\nEnter the landing1 time:");
    printf("\nEnter the departure1 time:");
    printf("\nEnter the no of passengers1:");
    printf("\nEnter the source1:");
    printf("\nEnter the destination1");
    printf("\nEnter the pilot name");
    printf("\nEnter the gate1");
    scanf("%d",&flight_no1);
    scanf("%d",&landing1);
    scanf("%d",&departure1);
    scanf("%d",&passengers1);
    scanf("%s",&source1);
    scanf("%s",&destination1);
    scanf("%s",&pilotname1);
    scanf("%s",&gate1);
    new_node1->flight_no1=flight_no1;
    new_node1->landing1=landing1;
    new_node1->departure11=departure1;
    new_node1->passengers1=passengers1;
    strcpy(new_node1->source1,source1);
    strcpy(new_node1->destination1,destination1);
    strcpy(new_node1->pilotname1,pilotname1);
    strcpy(new_node1->gate1,gate1);
    if(start==NULL)
    {
        new_node1->next=NULL;
        start=new_node1;
    }
    else
    {
        new_node1->next=start;
        start=new_node1;
    }
    return start;
}

struct node1 *delete_beg1()
{

    struct node1 *ptr;
    if(start==NULL)
        printf("list is empty");
    else
    {
        ptr=start;
        start=start->next;
        free(ptr);
    }
    return start;
}

struct node1 *delete_end1()
{
    struct node1 *ptr,*preptr;
    if(start==NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        ptr=start->next;
        preptr=start;
        while(ptr->next !=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(preptr == start)
        {
            start=NULL;
        }
        else
        {
            preptr->next=NULL;
        }
        free(ptr);
    }
    return start;
}

struct node1 *swap_node1()
{
    struct node1 *ptr1,*ptr2,*temp11,*temp22,*temp1,*temp2;
    int p1,p2;
    int c;
    printf("\nEnter 1st Position:");
    scanf("%d",&p1);
    printf("\nEnter 2nd Position:");
    scanf("%d",&p2);
    c=1;
    ptr1=start->next;
    temp1=start;
    while(c!=p1-1)
    {
        temp1=ptr1;
        ptr1=ptr1->next;
        c++;
    }
    ptr2=start->next;
    temp2=start;
    c=1;
    while(c!=p2-1)
    {
        temp2=ptr2;
        ptr2=ptr2->next;
        c++;
    }
    temp11=ptr1->next;
    temp22=ptr2->next;
    temp1->next=ptr2;
    ptr2->next=temp11;
    temp2->next=ptr1;
    ptr1->next=temp22;
    return start;
}

struct node1 *delete_aftpos1()
{
    struct node1 *ptr,*preptr;
    int r=1,q;
    printf("Enter the position to delete");
    scanf("%d",&q);
    if(start==NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        ptr=start->next;
        preptr=start;
        while(r!=q)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(preptr == start)
        {
            start=NULL;
        }
        else
        {
            preptr= ptr->next;
        }
        free(ptr);
    }
    return start;
}
