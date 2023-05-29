#include <stdio.h>
#include <stdlib.h>

typedef struct noeud
{
    int val;
    struct noeud *suiv;
}noeud;


noeud *cree(int valeur);
int vide(noeud *a);
noeud *enfiler(noeud *a, int el);
noeud *defiler(noeud *a);
int tete(noeud *a);
int len(noeud *a);
void aff(noeud *a);
void decomp(noeud *P1, noeud **P2, noeud **P3);
noeud *inser(noeud *f, int val);

int main()
{
    noeud *a = cree(4);
    a = enfiler(a, 7);
    a = enfiler(a, 7);
    a = enfiler(a, 9);
    noeud *b = cree(19);
    b = enfiler(b, 3);
    b = enfiler(b, 2);
    b = enfiler(b, 1);

    noeud *x = NULL;
    noeud *y = NULL;

    x = inser(a, 10);
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

noeud *enfiler(noeud *a, int el)
{
    noeud *x = malloc(sizeof(noeud));
    x->val = el;

    if (vide(a))
    {
        x->suiv = NULL;
        return x;
    }

    noeud *tmp = a;
    while (tmp->suiv != NULL)
    {
        tmp = tmp->suiv;
    }
    
    tmp->suiv = x;

    return a;
}

noeud *defiler(noeud *a)
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
        a = defiler(a);
        res++;
    }
    return res;
}

void aff(noeud *a)
{
    while (!vide(a))
    {
        printf("%i\n", a->val);
        a = defiler(a);
    }
}

void decomp(noeud *P1, noeud **P2, noeud **P3)
{
    while (!vide(P1))
    {
        if (tete(P1) % 2 == 0) *P2 = enfiler(*P2, tete(P1));
        else *P3 = enfiler(*P3, tete(P1));
        P1 = defiler(P1);
    }
}

noeud *inser(noeud *f, int val)
{
    noeud *tmp = NULL;
    while (!vide(f) && val > tete(f))
    {
        tmp = enfiler(tmp, tete(f));
        f = defiler(f);
    }
    tmp = enfiler(tmp, val);
    while (!vide(f))
    {
        tmp = enfiler(tmp, tete(f));
        f = defiler(f);
    }
    return tmp;
}
