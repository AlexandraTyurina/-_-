#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXLEN 60
/* --------Functions for linear single-linked list-------- */
// -------------------------------------------------------
Head *MakeHead() 
{
 Head *ph=NULL;
 ph=(Head*)malloc(sizeof(Head));
 if(ph!=NULL)
 {
    ph->cnt=0;
    ph->first=NULL;
    ph->last=NULL;
 }
 return ph;
}
// -------------------------------------------------------
Node *CreateNode(FILE *df)
{
 Node *NewNode=NULL; 
 int slen;
 char **s2=NULL;
 char *s1;
 char sep=';';
 NewNode = (Node*)malloc(sizeof(Node));
 s1 = (char*)malloc(MAXLEN*sizeof(char));
 if(NewNode&&s1)
 {
    NewNode->id = 1; 
    fgets(s1,MAXLEN,df);
    slen=strlen(s1);
    s1[slen-1]='\0';
    slen=strlen(s1);
    s2=simple_split(s1,slen,sep);//ïàìÿòü âûäåëÿåòñÿ â ôóíêöèè
    if(s2!=NULL)
    {
        NewNode->comp=struct_fill(s2);
    }
    else puts("Error at data reading!");
    NewNode->comp=struct_fill(s2);
    NewNode->next = NULL; 
 }
 free(s1);
 s1=NULL;
 return NewNode; 
}
// -------------------------------------------------------
// -------------------------------------------------------
Node *CreateNode2()
{
 Node *NewNode=NULL;
 int slen, flag;
 char **s2=NULL;
 char *s1;
 char sep=';';
 NewNode = (Node*)malloc(sizeof(Node));
 s1 = (char*)malloc(MAXLEN*sizeof(char));
 if(NewNode&&s1)
 {
    NewNode->id = 1; 
    fgets(s1,MAXLEN,stdin);
    slen=strlen(s1);
    s1[slen-1]='\0';
    slen=strlen(s1);
    s2=simple_split(s1,slen,sep);//ïàìÿòü âûäåëÿåòñÿ â ôóíêöèè
    if(s2!=NULL)
    {
        proverka_str();
        NewNode->comp=struct_fill(s2);
    }
    else puts("Error at data reading!");
    NewNode->comp=struct_fill(s2);
    NewNode->next = NULL; 
 }
 free(s1);
 s1=NULL;
 return NewNode; 
}
// -------------------------------------------------------
void AddFirst(Head *MyHead, Node *NewNode)
{
 if(MyHead&&NewNode)
 {
    MyHead->first = NewNode;
    MyHead->last = NewNode;
    MyHead->cnt++;
 }
}
// -------------------------------------------------------
void AddLast(Head *MyHead, Node *NewNode, Node *PrevNode)
{
    int n;

    if(MyHead&&NewNode&&PrevNode)
    {
        n=MyHead->cnt+1;
        PrevNode->next=NewNode;
        NewNode->id=n;
        MyHead->last=NewNode;
        MyHead->cnt=n;
    }
}
// -------------------------------------------------------
void InsertAfter(Head *MyHead, Node *NewNode, Node *CurrentNode)
{
    int n;
    if(MyHead&&NewNode&&CurrentNode)
    {
        n=MyHead->cnt+1;
        if(CurrentNode->next==NULL)
        {
            CurrentNode->next=NewNode;
            MyHead->last=NewNode;
        }
        else
        {
            NewNode->next = CurrentNode->next;
            CurrentNode->next=NewNode;
        }
        NewNode->id=n;
        MyHead->cnt=n;
    }
}
// -------------------------------------------------------
Node *SelectById(Head *MyHead, int num)
{
    Node *q;
    int k;
    q=MyHead->first;
    k=MyHead->cnt; /* last node id */
    if((num>=1)&&(num<=k))
    {
        while((q->id)!=num) q=q->next;
    }
    else q=NULL;
    return q;
}
// -------------------------------------------------------
void deleteSelected(Head *MyHead, Node *CurrentNode)
{
    Node *q, *q1;

    q=MyHead->first;
    q1=MyHead->last;
    if(CurrentNode==q)
    {
        MyHead->first=CurrentNode->next;
        CurrentNode->next=NULL;
        free(CurrentNode);
    }
    else
    {
        while(q!=NULL)
        {
            if(q->next==CurrentNode)
            {
                if(CurrentNode==q1) MyHead->last=q;
                q->next=CurrentNode->next;
                CurrentNode->next=NULL;
                free(CurrentNode);
            }
            else q=q->next;
        }
    }
}
void change_data_num(Node *p, int resh)
{
    int slen;
    char* s1=NULL;
    s1 = (char*)malloc(MAXLEN*sizeof(char));
    printf ("Enter data: ");
    fgets(s1,MAXLEN,stdin);
    slen=strlen(s1);
    s1[slen-1]='\0';
    slen=strlen(s1);
    if (resh==0) p->comp->RAM = atoi(s1);
    if (resh==1) p->comp->nucleus = atoi(s1);
    if (resh==2) p->comp->rate = atof (s1);
    if (resh==3) p->comp->weight = atof (s1);
    if (resh==4) p->comp->par[0] = atof (s1);
    if (resh==5) p->comp->par[1] = atof (s1);
    if (resh==6) p->comp->par[2] = atof (s1);
    if (resh==7) p->comp->name = s1;
    if (resh==8) p->comp->seria = s1;
}
void searchfor (Head *p0, Node *p1,float (*funcname)(Node*q))
{
    char *s1;
    int slen, flag=0;
    s1 = (char*)malloc(MAXLEN*sizeof(char));
    if (s1)
    {
    printf ("Print your data: ");
    fgets(s1,MAXLEN,stdin);
    slen=strlen(s1);
    s1[slen-1]='\0';
    slen=strlen(s1);
    }
    p1=p0->first;
    while (p1!=NULL)
    {
        if ((fabs(funcname(p1)-atof(s1)))<EPS)
        {
            flag++;
            if (flag==1) print_header();
            struct_out (p1->comp);
        }
        p1=p1->next;
    }
    free (s1);
    s1 = NULL;
}
void compstr (Head *p0, Node *p1, int num)
{
    char *s1, *s2;
    int slen, flag=0;
    s1 = (char*)malloc(MAXLEN*sizeof(char));
    s2 = (char*)malloc(MAXLEN*sizeof(char));
    if (s1)
    {
    printf ("Print your data: ");
    fgets(s1,MAXLEN,stdin);
    slen=strlen(s1);
    s1[slen-1]='\0';
    slen=strlen(s1);
    }
    if (num == 7)
    {
        p1=p0->first;
        while(p1!=NULL)
        {
            s2 = p1->comp->name;
            if (strcmp(s1,s2)==0)
            {
                flag++;
                if (flag==1) print_header();
                struct_out (p1->comp);
            }
            p1=p1->next;
        }
    }
    if (num==8)
    {
        p1=p0->first;
        while(p1!=NULL)
        {
            s2 = p1->comp->seria;
            if (strcmp(s1,s2)==0)
            {
                flag++;
                if (flag==1) print_header();
                struct_out (p1->comp);
            }
            p1=p1->next;
        }
    }
    free (s1);
    s1=NULL;
    free (s2);
    s2=NULL;
}
void sort_fl(Head *p0, Node *p1, float (*funcname)(Node*q))
{
    laptops *tmp;
    int i,j;
    float v,g;
    for (i=0;i<p0->cnt;i++)
    {
        p1=p0->first;
        while (p1->next!=NULL)
        {
            v=funcname(p1);
            g=funcname(p1->next);
            if (v>g)
            {
                tmp = p1->next->comp;
                p1->next->comp = p1->comp;
                p1->comp = tmp;
            }
            p1 = p1->next;
        }
    }
}
void sort_alf (Head *p0, Node *p1, int choice)
{
    laptops *tmp;
    int i;
    tmp = (laptops*)malloc(sizeof(laptops));
    if (choice == 7)
    {
        for (i=0;i<p0->cnt;i++)
        {
            p1=p0->first;
            while (p1->next!=NULL)
            {
                if (strcmp(p1->comp->name,p1->next->comp->name)>0)
                {
                    tmp = p1->next->comp;
                    p1->next->comp = p1->comp;
                    p1->comp = tmp;
                }
            p1 = p1->next;
            }
        }
    }
    if (choice == 8)
    {
        for (i=0;i<p0->cnt;i++)
        {
            p1=p0->first;
            while (p1->next!=NULL)
            {
                if (strcmp(p1->comp->seria,p1->next->comp->seria)>0)
                {
                    tmp = p1->next->comp;
                    p1->next->comp = p1->comp;
                    p1->comp = tmp;
                }
            p1 = p1->next;
            }
        }
    }
}
/* ------------------The end of this part------------------ */
// -------------------------------------------------------
/*-----------Functions to get fields of sorting-----------*/
float sRAM(Node*q)
{
    return q->comp->RAM;
}
// ------------------------------------
float snucleus(Node*q)
{
    return q->comp->nucleus;
}
// ------------------------------------
float srate(Node*q)
{
    return q->comp->rate;
}
// ------------------------------------
float sweight(Node*q)
{
    return q->comp->weight;
}
// ------------------------------------
float spar0(Node*q)
{
    return q->comp->par[0];
}
// ------------------------------------
float spar1(Node*q)
{
    return q->comp->par[1];
}
// ------------------------------------
float spar2(Node*q)
{
    return q->comp->par[2];
}
/* -----------------------------------------------------*/

/*----------------The end of this part-----------------*/

