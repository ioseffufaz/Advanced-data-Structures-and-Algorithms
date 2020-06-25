#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct node{
    int r;
    struct node *fg,*fd;

}node, *abin;

// Basic operations of simple binary tree
abin enrac(int x, abin g, abin d){
    abin n = (abin)malloc(sizeof(node));
    n->fd = d;
    n->fg = g;
    return n;
}

abin nouv(int r){
    abin arbre = (abin)malloc(sizeof(node));
    arbre->r = r;
    return arbre;
}
abin ag(abin a){
    if(a != NULL) return a->fg;
    return NULL;
}

abin ad(abin a){
    if(a != NULL) return a->fd;
    return NULL;
}

int racine(abin a){
    return a->r;
}
bool vide (abin a){
    return a==NULL;
}

//Secondary operations of simple binary tree
int n_nodes(abin a){
    if (a==NULL) return 0;
    return 1+ n_nodes(a->fg) + n_nodes(a->fd);
}

int n_leaf(abin a){
    if(a==NULL) return 0;
    if(a->fd ==NULL && a->fg == NULL) return 1;
    return n_leaf(a->fg)+n_leaf(a->fd);
}

int height(abin a){
    if(a==NULL) return 0;
    int hg = height(a->fg);
    int hd = height(a->fd);
    return 1 + (hg>hd?hg:hd);
}

int lce_aux(abin a, int hh){
    if (a->fg == NULL && a->fd == NULL ) return hh;
    int lceg = 0;
    if(a->fg != NULL ) lceg = lce_aux(a->fg,hh + 1);
    int lced = 0;
    if(a->fd != NULL ) lced = lce_aux(a->fd,hh + 1);

    return lced + lceg;
}
int lce(abin a){
    if(a==NULL) return 0;
    return lce_aux(a,1);
}

int lci_aux(abin a, int hh){
    if (a->fg == NULL && a->fd == NULL ) return 0;
    int lceg = 0;
    if(a->fg != NULL ) lceg = lce_aux(a->fg,hh + 1);
    int lced = 0;
    if(a->fd != NULL ) lced = lce_aux(a->fd,hh + 1);

    return hh + lced + lceg;
}
int lci(abin a){
    if(a==NULL) return 0;
    return lci_aux(a,1);
}
bool existe(abin a, int x){
    if(a==NULL) return NULL;
    if(a->r == x) return true;
    return existe(a->fg,x)|| existe(a->fd,x);
}
s

int main(void){
    printf("Hello\n");
    abin root = nouv(1);
    root->fg = nouv(2);
    root ->fd = nouv(3);
    root->fg->fg = nouv(4);
    root -> fg->fd = nouv(5);
    

}