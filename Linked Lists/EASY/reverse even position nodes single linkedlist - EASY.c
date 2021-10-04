#include<stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *make(struct node *sp)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("enter a number : ");
    scanf("%d", &new->val);
    new->next = NULL;
    sp->next = new;
    return new;
}
void traverse(struct node *sp)
{
    printf("on reversing only even positions we get \n");
    while (sp != NULL)
    {
        printf("%d ", sp->val);
        sp = sp->next;
    }
}
int main()
{
    int n;
    struct node *sp1 = (struct node *)malloc(sizeof(struct node));
    sp1->next = NULL;
    struct node *head = sp1;
    struct node *head1 = sp1;
    struct node *head2 = sp1;
    printf("enter the number of nodes: ");
    scanf("%d", &n);
    if (n == 1)
    {
        printf("enter a number: ");
        scanf("%d", &sp1->val);
    }
    else if (n > 1)
    {
        printf("enter a value: ");
        scanf("%d", &sp1->val);
        for (int i = 1; i < n; i++)
        {
            sp1 = make(sp1);
        }
    }
    int y = 0, x = 0;
    int arr[n];
    int brr[n];
    while (head != NULL)
    {
        arr[y] = head->val;
        y++;
        head = head->next;
    }
    int h = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 2 == 0)
        {
            for (int j = i; j >= 2 * h; j--)
            {
                brr[x++] = arr[j];
            }
            h++;
        }
    }
    x = 0;

    while (head1 != NULL)
    {
        head1->val = brr[x++];
        head1 = head1->next;
    }
    traverse(head2);
    return 0;
}
