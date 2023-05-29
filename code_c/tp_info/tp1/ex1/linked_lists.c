#include <stdio.h>
#include <stdlib.h>

typedef struct  noeud
{
    int val;
    struct noeud *suiv;
    
}noeud;

noeud *liste_vide(noeud *n, int len);
void inser(noeud *n, noeud *element, int pos);
void sup(noeud *n, int pos);
int len(noeud *n);
void print(noeud *n);

int main()
{
    noeud *n = malloc(sizeof(noeud));
    n->suiv = NULL;
    n = liste_vide(n, 6);
    noeud *el = malloc(sizeof(noeud));
    el->val = 3;
    inser(n, el, 1);
    
    print(n);
}


noeud *liste_vide(noeud *n, int len)
{
    if (len != 1)
    {
        noeud *tmp = malloc(sizeof(noeud));
        tmp->suiv = n;
        tmp->val = 0;
        return liste_vide(tmp, len - 1);
    }
    else 
    {
        return n;
    }
}

void inser(noeud *n, noeud *element, int pos)
{
    /*if (pos != 0)
    {
        inser(n->suiv, element, pos - 1);
        return;
    }
    else 
    {
        element->suiv = n->suiv;
        n->suiv = element;
    }*/
    noeud *tmp = n;
    for (int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->suiv;
    }
    element->suiv = tmp->suiv;
    tmp->suiv = element;
}

void sup(noeud *n, int pos)
{
    noeud *tmp = n;
    for (int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->suiv;
    }
    noeud *a = tmp->suiv;
    tmp->suiv = a->suiv;
    free(a);
}

int len(noeud *n)
{
    int res = 0;
    for (noeud *tmp = n; tmp->suiv != NULL; tmp = tmp->suiv)
    {
        res++;
    }
    return res;
}

void print(noeud *n)
{
    for (noeud *tmp = n; tmp != NULL; tmp = tmp->suiv)
    {
        printf("%i\n", tmp->val);
    }   
}
