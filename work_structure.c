#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 60
char* Choice()
{
    char *choice;
    int slen;
    choice=(char*)malloc(5*sizeof(char));
    fgets(choice, 15, stdin);
    slen=strlen(choice);
    choice[slen-1]='\0';
    slen=strlen(choice);
    return choice;
}
// -------------------------------------------------------
char* Proverka_vvoda ()
{
    int choice=NULL;
    printf ("\nChoose, what you want to do: ");
    choice=Choice();
    while ((atoi(choice)<1)||(atoi(choice)>7))
    {
        printf ("\nPlease re-enter your data: ");
        choice = Choice();
    }
    return choice;
}
// -------------------------------------------------------
int proverka_str (char *str)
{
    int flag=0;
    while (flag==0)
    {

    }
}
int count_str (FILE *df)
{
    int num=0;
    char s1[MAXLEN];
    if(df!=NULL)
    {
        while(fgets(s1,MAXLEN,df)!=NULL)
        {
            num++;
        }
        rewind(df);
    }

    return num;
}
// -------------------------------------------------------
void ClearStringArray(char **str, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        free(str[i]);
        str[i]=NULL;
    }
    free(str);
    str=NULL;

}
// -------------------------------------------------------
void ClearStructure(laptops *str0)
{
    str0->name=NULL;
    str0->seria=NULL;
    free(str0->name);
    free(str0->seria);
    free(str0);
    str0=NULL;
}
// -------------------------------------------------------
char **simple_split(char *str, int length, char sep)
{
    char **str_array=NULL;
    int i,j,k,m,slen;
    int key,count;
    for(j=0,m=0; j<length; j++)
    {
        if(str[j]==sep)
            m++;
    }
    while (m!=8)
    {
        printf ("Please, re-enter the string:");
        fgets(str,MAXLEN,stdin);
        slen=strlen(str);
        str[slen-1]='\0';
        slen=strlen(str);
    }
    key=0;
    str_array=(char**)malloc((m+1)*sizeof(char*));
    if(str_array!=NULL)
    {
        for(i=0,count=0; i<=m; i++,count++)
        {
            str_array[i]=(char*)malloc(length*sizeof(char));
            if(str_array[i]!=NULL)
                key=1;
            else
            {
                key=0;
                i=m;
            }
        }
        if(key)
        {
            k=0;
            m=0;
            for(j=0; j<length; j++)
            {
                if((str[j]!=sep)&&(str[j]!='\n'))
                {
                    str_array[m][k]=str[j];
                    k++;
                }
                else
                {
                    str_array[m][k]='\0';
                    k=0;
                    m++;
                }
            }
        }
        else
        {
            ClearStringArray(str_array,count);
        }
    }
    return str_array;
}
// -------------------------------------------------------
laptops *struct_fill(char **str)
{
    laptops *str0=NULL;

    str0=(laptops*)malloc(sizeof(laptops));
    if(str0!=NULL)
    {
        str0->name=str[0];
        str0->seria=str[1];
        str0->RAM=atoi(str[2]);
        str0->nucleus=atoi(str[3]);
        str0->rate=atof(str[4]);
        str0->weight=atof(str[5]);
        str0->par[0]=atof(str[6]);
        str0->par[1]=atof(str[7]);
        str0->par[2]=atof(str[8]);
    }
    return str0;
}
// -------------------------------------------------------
void print_header()
{
    printf("|%10s|%13s| %3s | %3s | %6s | %6s | %6s | %6s | %6s |\n","name","seria","RAM","nucleous","rate","weight","parameter[1]","parameter[2]","parameter[3]");
    printf("+----------+-------------+-----+----------+--------+--------+--------------+--------------+--------------+\n");

}

void struct_out(laptops *str)
{
    printf("|%10s|%13s| %3d | %8d | %6.3f | %6.3f | %12.3f | %12.3f | %12.3f |\n",
           str->name,str->seria,str->RAM,str->nucleus,str->rate,str->weight,str->par[0],str->par[1],str->par[2]);
}
