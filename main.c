#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#define MAXLEN 60
int main()
{
    Head *p0=NULL;
    Node *p=NULL,*p1=NULL;
    FILE *df;
    float (*sort[8])(Node*);
    char s1[MAXLEN];
    int n,resh,i,id;
    char *choice=NULL,*cal=NULL;
    sort[0] = sRAM;
    sort[1] = snucleus;
    sort[2] = srate;
    sort[3] = sweight;
    sort[4] = spar0;
    sort[5] = spar1;
    sort[6] = spar2;
    df=fopen("information.txt","r");
    if(df!=NULL)
    {
        fgets(s1,MAXLEN,df);
        printf ("%s", s1);
        while(fgets(s1,MAXLEN,df)!=NULL)
        {
            printf ("\t%s", s1);
        }
        fclose (df);
    }
    choice = Proverka_vvoda ();
    df = fopen("laptop_info.csv","r");
    n = count_str (df);
    if (n!=0)
    {
        p0=MakeHead();
        p=CreateNode(df);
        AddFirst(p0,p);
        for (i=0; i<(n-2); i++)
        {
            p1=CreateNode(df);
            InsertAfter(p0, p1,p0->last);
        }
        p1=CreateNode(df);
        AddLast(p0,p1,p0->last);
        while (atoi(choice)!=7)
        {
            if (atoi(choice)==1)
            {
                cal = choice;
                while (atoi(cal)!= 7)
                {
                    printf ("Before which item do you want to add a card?(enter its id):");
                    scanf ("%i", &id);
                    getchar();
                    p = SelectById(p0, id);
                    p1 = CreateNode2();
                    InsertAfter(p0, p1, p);
                    printf ("If you want to add another card, press any number from 1-6.Press 7 to finish adding.");
                    cal = Proverka_vvoda ();
                }
            printf ("----------------------------------------------");
            }
            if (atoi(choice)==2)
            {
                printf ("Which card do you want to edit?(enter its id)");
                scanf ("%i", &id);
                getchar();
                if ((id<0)|| (id>p0->cnt))
                {
                do
                {
                    printf ("Please, re-enter the desirable id:");
                    scanf ("%i", &id);
                    getchar();
                }while ((id<0)|| (id>p0->cnt));
                }
                while (id!=0)
                {
                p=SelectById(p0, id);
                printf ("Enter a field to edit:\n0-RAM;\n1-nucleus;\n2-rate;\n3-weight;\n4-parameter[1];\n5-parameter[2];\n6-parameter[3];\n7-name\n8-seria;\n");
                scanf ("%i", &resh);
                getchar();
                change_data_num(p,resh);
                printf ("If you want to repeat the action, enter the id of the desired card, if you want to finish editing, click 0.\n");
                scanf ("%i", &id);
                getchar();
                while ((id<0)|| (id>p0->cnt))
                {
                    printf ("Please, re-enter the desirable id(to finish editing press 0):");
                    scanf ("%i", &resh);
                    getchar();
                }
                }

            printf ("----------------------------------------------");
            }
            if (atoi(choice)==3)
            {
                printf ("Which card do you want to delete?(enter its id)");
                scanf ("%i", &id);
                getchar();
                while (id!=-1)
                {
                    p=SelectById(p0, id);
                    deleteSelected(p0, p);
                    printf ("If you want to repeat the action, enter the id of the desired card, if you want to finish editing, click -1: ");
                    scanf ("%i", &id);
                    getchar();
                }
            printf ("----------------------------------------------");
            }
            if (atoi(choice)==4)
            {
                printf ("\t--------Initial data--------\n\n");
                print_header();
                p=p0->first;
                while(p!=NULL)
                {
                    struct_out(p->comp);
                    p=p->next;
                }
            printf ("----------------------------------------------");
            }
            if (atoi(choice)==5)
            {
                printf ("Enter a field to work with:\n0-RAM;\n1-nucleus;\n2-rate;\n3-weight;\n4-parameter[1];\n5-parameter[2];\n6-parameter[3];\n7-name\n8-seria;\n");
                scanf ("%i", &resh);
                getchar();
                if ((resh>-1)&&(resh<9))
                {
                    while (resh!=-1)
                    {
                        if ((resh>=0) && (resh<7)) searchfor (p0,p1, sort[resh]);
                        if ((resh==7)||(resh==8)) compstr (p0, p, resh);
                        printf ("If you want to repeat the action, enter the number of the desired field, if you want to finish searching, click -1: ");
                        scanf ("%i", &resh);
                        getchar();
                    }
                }
                else
                {
                    while ((resh<-1)&&(resh>8))
                    {
                        printf ("Re-enter your data, please: %i", &resh);
                        getchar();
                    }
                }
            printf ("----------------------------------------------");
            }
            if (atoi(choice)==6)
            {
                printf ("Enter a field to sort:\n0-RAM;\n1-nucleus;\n2-rate;\n3-weight;\n4-parameter[1];\n5-parameter[2];\n6-parameter[3];\n7-name\n8-seria;\n");
                scanf ("%i", &resh);
                getchar();
                if ((resh>=0) && (resh<7)) sort_fl(p0,p1,sort[resh]);
                if ((resh==7)||(resh==8)) sort_alf (p0,p1,resh);
            printf ("----------------------------------------------");
            }
        choice = Proverka_vvoda ();
        }
        df = fopen("laptop_res.csv","w");
        p=p0->first;
        while(p!=NULL)
        {
            fprintf(df, "%s;%s;%i;%i;%.3f;%.3f;%.3f;%.3f;%.3f\n",p->comp->name,p->comp->seria,p->comp->RAM,p->comp->nucleus,p->comp->rate,p->comp->weight,p->comp->par[0],p->comp->par[1],p->comp->par[2]);
            p=p->next;
        }
        close(df);
        p=p0->first;
        while(p!=NULL)
        {
            p1=p->next;
            ClearStructure(p->comp);
            free(p);
            p=p1;
        }
        if(p0)free(p0);
        free(p0->first);
        if (p0) p0->first=NULL;
        free (p0->last);
        if (p0) p0->last=NULL;
        printf ("-----------------------------------------");
    }
    else printf ("It is impossible to read information from the file!");
    free (choice);
    choice=NULL;
    return 0;
}
