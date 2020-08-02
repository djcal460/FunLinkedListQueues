#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

int enqueue(int x)
{
    //create a new node
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    //if null then no more space in heap
    if (t == NULL)
    {
        printf("Queue is Full./n");
        return -1;
    }
    else
    {

        t->data = x;       //add data
        t->next = NULL;    //next is null since at end
        if (front == NULL) //if first node then equal front and rear
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
    return 0;
}

int dequeue()
{
    int x = -1;
    //create a new node
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    //if null then q is empty
    if (front == NULL)
        printf("Queue is Empty./n");
    else
    {
        x = front->data;     //save data at front
        t = front;           //save t to front node
        front = front->next; //move front up
        free(t);             //free t at old node
    }
    return x;
}

void display()
{

    struct Node *p;
    p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int promptint()
{
    int fixin, input, ret = 0;
    //check valid size
    while (ret != 1 || input > INT_MAX || input < INT_MIN)
    {
        printf("Enter a valid integer: ");
        while ((fixin = getchar()) != EOF && fixin != '\n')
            ; // fix stdin
        fflush(stdin);
        ret = scanf("%d", &input);
    }
    return input;
}
int repromptsize()
{
    int fixin, input, ret = 0;
    //check valid size
    while (ret != 1 || input < 1 || input > INT_MAX)
    {
        printf("Enter a valid size: ");
        while ((fixin = getchar()) != EOF && fixin != '\n')
            ; // fix stdin
        fflush(stdin);
        ret = scanf("%d", &input);
    }
    return input;
}
int repromptchoice()
{
    int fixin, input, ret = 0;
    //check valid size
    while (ret != 1 || input > 1 || input < 3)
    {
        printf("Enter a valid choice: ");
        while ((fixin = getchar()) != EOF && fixin != '\n')
            ; // fix stdin
        fflush(stdin);
        ret = scanf("%d", &input);
    }
    return input;
}

int main()
{

    printf("Welcome to the Linked List Queue Program.\n");
    printf("Create a Queue using a Dynamic Linked List.\n");
    printf("We're dynamic baby, be any size that you want.\n");
    int ret, input, flag = 1;
    do
    {
        printf("\nWhat do you want to do with the queue?\n");
        printf("1. Queue an integer.\n");
        printf("2. Dequeue an integer.\n");
        printf("3. Display Queue.\n");

        //validate
        printf("\nEnter your choice: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 3 || input < 1)
            input = repromptchoice();

        //set the infix string
        int k, r;
        switch (input)
        {
        case 1:
            k = promptint();
            r = enqueue(k);
            if (r != -1)
                printf("Queued %d element.\n", k);
            printf("Press Any Key to Continue");
            getchar();
            getchar();
            fflush(stdin);
            break;
        case 2:
            r = dequeue();
            if (r != -1)
                printf("Dequed %d element.\n", r);
            printf("Press Any Key to Continue");
            getchar();
            getchar();
            fflush(stdin);
            break;
        case 3:
            display();
            printf("Press Any Key to Continue");
            getchar();
            getchar();
            fflush(stdin);
            break;
        }

    } while (flag);
}
