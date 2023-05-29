#include <stdio.h>
#include <stdlib.h>

typedef struct noeud
{
    int val;
    struct noeud *suiv;
}noeud;


noeud *cree(int valeur);
int vide(noeud *a);
noeud *empiler(noeud *a, int el);
noeud *depiler(noeud *a);
int tete(noeud *a);
int len(noeud *a);
void aff(noeud *a);
void decomp(noeud *P1, noeud **P2, noeud **P3);
noeud *fusion(noeud *P1, noeud *P2);



int main()
{
    noeud *a = cree(9);
    a = empiler(a, 7);
    a = empiler(a, 7);
    a = empiler(a, 2);
    noeud *b = cree(19);
    b = empiler(b, 3);
    b = empiler(b, 2);
    b = empiler(b, 1);

    noeud *x = fusion(a, b);
    aff(x);
}

noeud *cree(int valeur)
{
    noeud *a = malloc(sizeof(noeud));
    a->val = valeur;
    a->suiv = NULL;
    return a;
}

int vide(noeud *a)
{
    return a == NULL;
}

noeud *empiler(noeud *a, int el)
{
    noeud *x = malloc(sizeof(noeud));
    x->val = el;

    if (vide(a))
    {
        x->suiv = NULL;
        return x;
    }

    x->suiv = a;
    return x;
}

noeud *depiler(noeud *a)
{
    a = a->suiv;
    return a;
}

int tete(noeud *a)
{
    return a->val;
}

int len(noeud *a)
{
    int res = 0;
    while (!vide(a))
    {
        a = depiler(a);
        res++;
    }
    return res;
}

void aff(noeud *a)
{
    while (!vide(a))
    {
        printf("%i\n", a->val);
        a = depiler(a);
    }
}

void decomp(noeud *P1, noeud **P2, noeud **P3)
{
    while (!vide(P1))
    {
        if (tete(P1) % 2 == 0) *P2 = empiler(*P2, tete(P1));
        else *P3 = empiler(*P3, tete(P1));
        P1 = depiler(P1);
    }
}

noeud *fusion(noeud *P1, noeud *P2)
{
    noeud *P3 = NULL;
    while (!vide(P1) && !vide(P2))
    {
        if (tete(P1) < tete(P2)) 
        {
            P3 = empiler(P3, tete(P1));
            P1 = depiler(P1);
        }
        else
        {
            P3 = empiler(P3, tete(P2));
            P2 = depiler(P2);
        }
    }
    while (!vide(P1))
    {
        empiler(P3, tete(P1));
        P1 = depiler(P1);
    }
    
    while (!vide(P2))
    {
        empiler(P3, tete(P2));
        P2 = depiler(P2);
    }
    return P3;
}