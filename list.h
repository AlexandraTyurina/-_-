#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EPS 3e-6
#define MAXLEN 60
/* define structures */
typedef struct LAPTOP{
        char *name;
        char *seria;
        int RAM;
        int nucleus;
        float rate;
        float weight;
        float par[3];
}laptops;
typedef struct LNode {
    int   id;
    laptops *comp;  /* data area */
    struct LNode  *next; /* link to next node */
}Node;

typedef struct LHead {
    int cnt;
    Node *first;
    Node *last;
}Head; /* datatype for pointer to node */
/*-----------Additional functions-----------*/
char* Choice();
char* Proverka_vvoda ();
int count_str (FILE *df);
// ----------------------------------------------------------
// -----------Functions to work with data structure-----------
/* function to clear array of string */
void ClearStringArray(char **str, int n);

/* function to clear a structure */
void ClearStructure(laptops *str0);

/* function to split string to array by separator */
char **simple_split(char *str, int length, char sep);

/* function to create structure by array of strings*/
laptops *struct_fill(char **str);

void print_header();

void struct_out(laptops *str);
// ----------------------------------------------------------
// -------------Functions to work with the list--------------
Head *MakeHead();
Node *CreateNode(FILE *df);
Node *CreateNode2();
void AddFirst(Head *MyHead, Node *NewNode);
void AddLast(Head *MyHead, Node *NewNode, Node *PrevNode);
void InsertAfter(Head *MyHead, Node *NewNode, Node *CurrentNode);
Node *SelectById(Head *MyHead, int num);
void deleteSelected(Head *MyHead, Node *CurrentNode);
void change_data_num(Node* p, int resh);
void searchfor (Head *p0, Node *p1, float (*funcname)(Node*q));
void compstr (Head *p0, Node *p1, int num);
void sort_fl(Head *p0, Node *p1, float (*funcname)(Node*q));
void sort_alf (Head *p0, Node *p1, int choice);
// ----------------------------------------------------------
/* -------------Functions to get values for sorting-------------*/
float sRAM(Node*q);
// ------------------------------------
float snucleus(Node*q);
// ------------------------------------
float srate(Node*q);
// ------------------------------------
float sweight(Node*q);
// ------------------------------------
float spar0(Node*q);
// ------------------------------------
float spar1(Node*q);
// ------------------------------------
float spar2(Node*q);
/* -----------------------------------------------------*/

#endif // LIST_H_INCLUDED
