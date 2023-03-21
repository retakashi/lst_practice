#include<stdio.h>
#include<stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_list
{
    char *c;
    int tail;
    struct s_list *next;
    struct s_list *prev;

} t_list;

t_list *ndptr(int argc ,char **argv)
{
    int i=0;
    t_list *ndptr;
    t_list *head;
    t_list *new;
    ndptr=malloc(sizeof(t_list));
    head=ndptr;
    ndptr->prev=NULL;
    while(i<argc-1)
    {
    ndptr->c=argv[i+1];
    ndptr->tail=0;
    new=malloc(sizeof(t_list));
    ndptr->next=new;
    new->prev=ndptr;
    ndptr=new;
    i++;
    }
    ndptr->c=NULL;
    ndptr->next=head;
    head->prev=ndptr;
    return(head);
}
int main(int argc,char **argv)
{
    int i=0;
    t_list *ndptr2;
    printf("argc: %d\n",argc);
    while(argv[i])
    printf("argv[%d]: %s\n",i,argv[i++]);
    ndptr2=ndptr(argc,argv);
    i=0;
    while(i<argc)
    {
    printf("ndptr[%d]: %s\n",i,ndptr2->c);
    printf("ndptr[%d]: %p\n",i,ndptr2);
    printf("ndptr->prev[%d]: %p\n",i,ndptr2->prev);
    printf("ndptr->next[%d]: %p\n",i++,ndptr2->next);
    ndptr2=ndptr2->next;
    }
    return(0);
}