#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct sll{
    int data;
    struct sll*next;                  // self referencing pointer structure 
};

void createlist(struct sll*node)
{
     char ch;
    int i;
    printf("\n ENTER THE DATA OF NODE \n");
    scanf("%d",&node->data);
    node->next=NULL;
    ch=getchar();
    i++;
    printf("\n ENTER 'N' TO STOP AND ANY CHARACTER TO CONTINUE \n");
    while(ch != 'N')
    {
        node->next=(struct sll*)malloc(sizeof(struct sll));
        if(node->next==NULL)
        {
            printf("\n MEMORY IS NOT ALLOCATED \n");
            exit(0);
        }
        node=node->next;
        printf("\n ENTER THE DATA OF  NODE \n",i);
        scanf("%d",&node->data);
        node->next=NULL;
        printf("\n PRESS 'N' TO STOP AND ANY KEY TO CONTINUE \n");
        ch=getchar();
        i++;
    }
};
void displaylist(struct sll*node)
{
while(node!=NULL)
{
    printf("%d\t",node-> data);
    node=node ->next;
}
printf("\n");
}
struct sll* partition(struct sll*node) 
{int p;
printf("\n Enter the position \n");
scanf("%d",&p);

    struct sll* lessHead = NULL; // Head of the list with elements less than pivot
    struct sll* lessTail = NULL; // Tail of the list with elements less than pivot
    struct sll* greaterHead = NULL; // Head of the list with elements greater than or equal to pivot
    struct sll* greaterTail = NULL; // Tail of the list with elements greater than or equal to pivot

    struct sll* current = node;

    while (current != NULL) {
        if (current->data < p) {
            if (lessHead == NULL) {
                lessHead = lessTail = current;
            } else {
                lessTail->next = current;
                lessTail = current;
            }
        } else {
            if (greaterHead == NULL) {
                greaterHead = greaterTail = current;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }
        current = current->next;
    }

    // Connect the two partitions
    if (lessTail != NULL) {
        lessTail->next = greaterHead;
    }

    if (greaterTail != NULL) {
        greaterTail->next = NULL;
    }

    return lessHead != NULL ? lessHead : greaterHead;
    displaylist(node);
}

int count(struct sll*node)
{
    int i=0;
    while( node != 0)
    {
        node=node->next;
        i++;
    }
    printf("%d",i+1);
}
int search(struct sll*node)
{
    int index=0;
    int x;
    printf("\n ENTER THE NODE VALUE TO BE SEARCHED \n");
    scanf("%d",&x);
    while(node!=NULL)
    {
        if(x==node->data)
        {
        {
            printf("\n YOUR POSITION IS %d \n",index+1);
            return index;
        }
        index++;
        node = node->next;
        }
    }
        printf("\n element not found \n");
       return -1;
    
    
}
void insert_begin(struct sll*node)
{
    struct sll*start;
    struct sll*new;
    new=(struct sll*)malloc(sizeof(struct sll));
    if(new==NULL)
    {
        printf("\n MEMORY IS NOT ALLOCATED");
        exit(0);
    }
    printf("NEW DATA");
    scanf("%d",&new->data);
    new->next=node;
    node=new;
    start=node;
    displaylist(node);
}
/*void insert_end(struct sll*node)
{
    struct sll*new;
    new=(struct sll*)malloc(sizeof(struct sll));
    if (new == NULL)
    {
        printf("MEMORY IS NOT ALLOCATED SUCCESSFULLY");
        exit(0);
    }
    printf("\n READ THE DATA OF NEW \n");
    scanf("%d",&new->data);
    new->next=NULL;
    while(node->next!=NULL)
    {
        node=node->next;
    }
    node->next=new;
    displaylist(node);
}*/
void insert_end(struct sll*node)
{
    struct sll* new_node = (struct sll*)malloc(sizeof(struct sll));
    if (new_node == NULL)
    {
        printf("MEMORY IS NOT ALLOCATED SUCCESSFULLY");
        exit(0);
    }
    
    printf("\n READ THE DATA OF NEW NODE: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    
    if (node == NULL)
    {
        // If the list is empty, make the new node the head of the list
        node= new_node;
    }
    else
    {
        // Traverse to the end of the list and insert the new node
        struct sll* current = node;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    
    // Call displaylist with the updated head of the list
    displaylist(node);
}
void insert(struct sll*node)
{
    int p;
    struct sll *new;
new=(struct sll*)malloc(sizeof(struct sll));
printf("\n Enter the data :\n");
scanf("%d",&new->data);
printf("\n Enter the position \n");
scanf("%d",&p);
    if (p == 0) {
        new->next = node;
        node=new;
        displaylist(node);
        return;
    }
int position=0;
    struct sll* current = node;

    while (current != NULL &&  position < p - 2) 
    {
        current = current->next;
        position++;
    }
    if (current == NULL) {
        printf("\nInvalid position\n");
        free(new); // Free the allocated memory
        return;
    }

    new->next = current->next;
    current->next = new;
    displaylist(node); // Display the updated list
}

void delete_begin(struct sll*node)
{
    struct sll*temp;
    temp=node;
    node=node->next;
    free(temp);
    displaylist(node);
}

/*void delete_begin(struct sll*node)
{
    if (node == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct sll* temp = node;
    node = node->next;
    free(temp);

    printf("First node deleted.\n");
    displaylist(node); // Display the updated list
}*/

void delete_end(struct sll*node)
{
    if(node==NULL)
    {
        printf("\n list is empty cannot delete \n");
        exit(0);

    }
    struct sll*temp=node;
    struct sll*prev=NULL;
    while(temp -> next != NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL)
    {
        free(node);
    }
    prev->next=NULL;
    free(temp);
}
void delete(struct sll*node) {
     int position;
    printf("\n Enter the position: \n");
    scanf("%d",&position);
    if (node == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (position == 0) {
        struct sll* temp = node;
        node =node->next;
        free(temp);
        printf("Node at position %d deleted.\n", position);
        return;
    }

    struct sll* current =node;
    struct sll* prev = NULL;
    int currentPosition = 0;

    while (current != NULL && currentPosition < position) {
        prev = current;
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position. Node not found at position %d.\n", position);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Node at position %d deleted.\n", position);
    delete_end(node);
    displaylist(node);
}
void insertAfter(struct sll*node) 
{ 
struct sll*new;
 new=(struct sll*)malloc(sizeof(struct sll));
 if(new==NULL)
 {
    printf("\n MEMORY NOT ALLOCATED SUCCESSFULLY \n");
    exit(0);
 }
printf("\n ENTER THE DATA FOR NODE \n");
scanf("%d",&new->data);
    if (node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    new->next = node->next;
    node->next = new;
    displaylist(node);
}
void deleteafter(struct sll*node)
{
    struct sll*new;
    new=(struct sll*)malloc(sizeof(struct sll));
    if(new==NULL)
    {
        printf("\n MEMORY NOT ALLOCATED SUCCESSFULLY \n");
        exit(0);
    }
    if (node == NULL || node->next == NULL) {
        printf("Invalid operation: The previous node is NULL or there is no node after it.\n");
        return;
    }
     struct sll* temp = node;
    node->next = temp->next;
    free(temp);
    displaylist(node);
}
    void sort(struct sll *node) {
    if (node == NULL || node->next == NULL) {
        return; // List is empty or has only one element, no need to sort
    }

    struct sll* sortedList = NULL;
    struct sll* current = node;

    while (current != NULL) {
        struct sll* next = current->next;
        if (sortedList == NULL || current->data <= sortedList->data) {
            current->next = sortedList;
            sortedList = current;
        } else {
            struct sll* temp = sortedList;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    node = sortedList;
    displaylist(node);
}
void reverseList(struct sll* node) {
    struct sll* prev = NULL;
    struct sll* current = node;
    struct sll* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    node = prev; // Update the head to point to the new first node
    displaylist(node);
      }

    int main()
    {
        int choice;
        struct sll*node;
      
        node=(struct sll*)malloc(sizeof(struct sll));
        if(node==NULL)
        {
            printf("memory allocated not successfully");
            exit(0);
        }
        createlist(node);
        while(1)
        {
        printf("\n .............................................................\n");
        printf("\n SELECT ANY ONE CHOICE FROM FOLLOWING \n");
        printf("\n..............................................................\n");
        printf("\n PRESS 1 FOR DISPLAYING YOUR ELEMENTS IN NODE \n PRESS 2 FOR COUNT OF NODES\n PRESS 3 SEARCHING AN ELEMENTS \n PRESS 4 INSERTING A NODE IN BEGINNING\n PRESS 5 INSERTING A NODE AT END\n PRESS 6 DELETING AN ELEMENT IN BEGIN \n PRESS 7 DELETING AN ELEMENT IN END\n PRESS 8 TO QUIT \n PRESS 9 TO INSERT NODE AT ANY POSITION \n PRESS 10 TO DELETE ELEMENT AT ANY POSITION \n PRESS 11 INSERTION AFTER ANY NODE \n PRESS 12 DELETION AFTER ANY NODE \n PRESS 13 SORTING LIST \n PRESS 14 REVERSING THE LIST \n PRESS 15 PARTITION OF LINKED LIST \n");
        printf("ENTER YOUR CHOICE");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):
            printf("\n Displaying list\n");
            displaylist(node);
            break;
            case(2):
            printf("\n no of node present is: ");
            delete_end(node);
            count(node);
            break;
            case(3):
            delete_end(node);
            search(node);
            break;
            case(4):
            insert_begin(node);
            break;
            case(5):
            insert_end(node);
            break;
            case(6):
            printf("\n DATA IS \n");
            delete_begin(node);
            break;
            case(7):
            printf("\n DATA IS \n");
            delete_end(node);
            break;
            case(8):
           exit(0);
            break;
            case(9):
            insert(node);
            break;
            case(10):
            delete(node);
            displaylist(node);
            break;
            case(11):
            insertAfter(node);
            break;
            case(12):
            deleteafter(node);
            break;
            case(13):
            sort(node);
            break;
            case(14):
            reverseList(node);
            break;
            case(15):
            partition(node);
            break;
            default:
            printf("\n INVALID SELECTION \n");
            break;
        }
    }
    }



