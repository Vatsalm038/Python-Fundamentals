#include <stdio.h>
#include <conio.h>
struct node
{
    int roll;
    char name[20];
    char sex[6];
    int pin;
    int marks[6];
    struct node *next;
};
struct node *head = NULL;
void insert();
void display();
void del();
void search();
void update();
void insert()
{
    int r;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Roll number : ");
    scanf("%d", &r);
    new->roll = r;
    char n[20];
    printf("\nEnter name : ");
    scanf("%s", n);
    strcpy(new->name, n);
    char s[6];
    printf("\nEnter Gender : ");
    scanf("%s", s);
    strcpy(new->sex, s);
    printf("\nEnter Pincode : ");
    scanf("%d", &new->pin);
    for (int i = 0; i < 6; i++)
    {
        printf("\nEnter marks in subject %d : ", i + 1);
        scanf("%d", &new->marks[i]);
    }
    if (head == NULL)
    {
        head = new;
        return;
    }
    if (new->roll < head->roll)
    {
        new->next = head;
        head = new;
        return;
    }
    struct node *hp;
    hp = head;
    while ((hp->next) != NULL && (hp->next->roll) < r)
    {
        hp = hp->next;
    }
    new->next = hp->next;
    hp->next = new;
    return;
}
void display()
{
    if (head == NULL)
    {
        printf("\nThe Record is empty ! ");
        return;
    }
    struct node *hp;
    hp = head;
    while (hp != NULL)
    {
        printf("\nRoll no: %d", hp->roll);
        printf("\tName: %s", hp->name);
        printf("\tGender: %s", hp->sex);
        printf("\tPincode: %d\n", hp->pin);
        for (int i = 0; i < 6; i++)
        {
            printf("\nMareks in subject %d: %d", i + 1, hp->marks[i]);
        }
        hp = hp->next;
    }
    return;
}
void del()
{
    struct node *hp, *ndel;
    if (head == NULL)
    {
        printf("\nThe Record is Empty !");
        return;
    }
    printf("\nEnter The roll no to be deleted\n");
    int d;
    scanf("%d", &d);
    hp = head;
    while (hp->next != NULL && hp->next->roll != d)
    {
        hp = hp->next;
    }
    if (hp->next->roll == -1)
    {
        printf("\nNo such Roll no. exists\n");
        return;
    }
    if (hp->next->roll == d)
    {
        ndel = hp->next;
        if (hp->next == NULL)
        {
            hp->next = NULL;
        }
        else
        {
            hp->next = ndel->next;
        }
        free(ndel);
        return;
    }
}
void search()
{
    int t = 0;
    int r;
    float p = 1;
    if (head == NULL)
    {
        printf("\nThe record is empty !\n");
        return;
    }
    struct node *hp = head;
    printf("\nEnter Roll no.\n");
    scanf("%d", &r);
    while (hp->next != NULL && hp->next->roll != r)
    {
        hp = hp->next;
    }
    if (hp->next == NULL)
    {
        printf("\nNo such roll no. exists\n");
        return;
    }
    if (hp->next->roll == r)
    {
        for (int i = 0; i < 6; i++)
        {
            t += hp->next->marks[i];
        }
        p = t * 100 / 600;
        printf("\nTotal marks: %d", t);
        printf("\nPercentage: %f", p);
        return;
    }
}
void update()
{
    struct node *hp;
    int r;
    int m[6];
    char n[20];
    char g[6];
    int p;
    if (head == NULL)
    {
        printf("\nThe Record is Empty !");
        return;
    }
    hp = head;
    printf("\nEnter Roll no.\n");
    scanf("%d", &r);
    while (hp->next != NULL && hp->next->roll != r)
    {
        hp = hp->next;
    }
    if (hp->next == NULL)
    {
        printf("\nNo such roll no. exists\n");
        return;
    }
    if (hp->next->roll == r)
    {
        int x;
        printf("\nEnter choice to update: \n1.Name \n2.Gender \n3.Pincode\n4.Marks\n ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nEnter Name: ");
            scanf("%s", n);
            strcpy(hp->next->name, n);
            break;
        case 2:
            printf("\nEnter Gender: ");
            scanf("%s", g);
            strcpy(hp->next->sex, g);
            break;
        case 3:
            printf("\nEnter pincode: ");
            scanf("%d", &p);
            hp->next->pin = p;
            break;
        case 4:
            for (int i = 0; i < 6; i++)
            {
                printf("\nEnter marks: ");
                scanf("%d", &m[i]);
                hp->next->marks[i] = m[i];
            }
            break;
        default:
            printf("\nWrong Input");
        }
        return;
    }
}
int main()
{
    head = NULL;
    int x;
    do
    {
        printf("\nEnter Choice \n1.Search \n2.Delete \n3.Add \n4.Update\n5.Display\n6.Exit \n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            search();
            break;
        case 2:
            del();
            break;
        case 3:
            insert();
            break;
        case 4:
            update();
            break;
        case 5:
            display();
            break;
        case 6:
            x = 7;
            break;
        default:
            printf("\nWrong Input\n");
        }
    } while (x < 7 && x > 0);
    return 0;
}
