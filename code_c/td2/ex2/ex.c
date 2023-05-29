#include <stdio.h>
#include <stdlib.h>

typedef struct  noeud
{
    int val;
    struct noeud *suiv;
    
}noeud;

const int LEN = 10;

void aff(noeud *l);
noeud *ins(noeud *n, noeud *el);
noeud *liste_cree(noeud *n, int val[], int i);
noeud *red(noeud *n);
noeud *supp_r(noeud *n, int val);

int main()
{
    noeud *n = malloc(sizeof(noeud));
    
    int values[LEN];
    for (int i = 0; i < LEN; i++)
    {
        printf("donnez une valeur: ");
        scanf("%i", values + i);
    }
    
    n = liste_cree(n, values, LEN - 1);
    aff(n);

    n = red(n);
    aff(n);

}


noeud *ins(noeud *n, noeud *el)
{
    noeud *tmp = n;

    while (el->val > tmp->suiv->val)
    {
        tmp = tmp->suiv;
    }

    el->suiv = tmp->suiv;
    tmp->suiv = el;
    return n;
}

noeud *liste_cree(noeud *n, int val[], int i)
{
    if (i >= 0)
    {
        noeud *tmp = malloc(sizeof(noeud));
        tmp->suiv = n;
        tmp->val = val[i];
        return liste_cree(tmp, val, i - 1);
    }
    else 
    {
        return n;
    }
}

void aff(noeud *l)
{
    if (l->suiv != NULL)
    {
        printf("%i\n", l->val);
        aff(l->suiv);
    }
}

noeud *red(noeud *n)
{
    noeud *tmp = n;
    while (tmp)
    {
        n = supp_r(n, tmp->val);
        tmp = tmp->suiv;
    }
    return n;
    
}

noeud *supp_r(noeud *n, int val)
{
    noeud *tmp = n;
    int c = 1;
    while (tmp->suiv)
    {  
        if (tmp->suiv->val == val && c == 0)
        {
           
            tmp->suiv = tmp->suiv->suiv;
            
        }
        else if (tmp->suiv->val == val) c = 0;
        tmp = tmp->suiv;
    }
    return n;
}