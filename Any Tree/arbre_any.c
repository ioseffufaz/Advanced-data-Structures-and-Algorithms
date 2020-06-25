#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>
typedef int T;
typedef struct node{
    T val;
    struct node *child,*brother;
}node, *arbre;

arbre arbrevide(){
    return NULL;
}

arbre newnode(T x,  arbre bro, arbre child){
    arbre new;
    new = (arbre)malloc(sizeof(node));
    new->brother = bro;
    new->child = child;
    new->val = x;

    return new;
}

arbre fils(arbre a){
    return a->child;
}
arbre frere(arbre a){
    return a->child;
}

bool est_vide(arbre a){
    return a==NULL;
}
bool est_feuille(arbre a){
    return a->child == NULL;
}
bool est_fils(T x, arbre a){
    if(a==NULL) return false;
    arbre f = a->child;
    while(f != NULL){
        if(f->val == x) return true;
        f = f->brother;
    }
    return false;
}

unsigned int nb_fils(arbre a){
    if(a == NULL) return 0;
    arbre f = a->child;
    unsigned int n = 0;
    while(f != NULL){
        n++;
        f = f->brother;
    }
    return n;
}

int hauteur(arbre a){
    if (a==NULL) return -1;
    int h = hauteur(a->child) + 1;
    arbre f = a->brother;
    while (f!=NULL){
        int ha = hauteur(f);
        if(ha > h) h = ha;
        f = f->brother;
    }
    return h;
}

arbre existnode(T x, arbre a){
    if(a == NULL) return NULL;
    if(a->val == x) return a;
    arbre r = existnode(x,a->child);
    if (r != NULL) return r;
    r = existnode(x,a->brother);
    return r;
}

void affiche(arbre a, unsigned int n){
    if(a==NULL) return;
    for(unsigned int i = 0; i<n; i++) printf("  ");
    printf("%d\n",a->val);
    affiche(a->child, n+1);
    affiche(a->brother,n);
}

int main(void){
    arbre a = newnode(4,
                    arbrevide(),
                    newnode(1,
                    newnode(6,
                        newnode(3,
                            arbrevide(),
                            arbrevide()),
                        arbrevide()),
                    newnode(2,
                        newnode(5,
                            arbrevide(),
                            arbrevide()),
                        arbrevide())));
    affiche(a,0);
                        


}