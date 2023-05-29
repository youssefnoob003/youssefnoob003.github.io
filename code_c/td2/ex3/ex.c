#include <stdio.h>
#include <stdlib.h>

typedef struct  noeud
{
    int val;
    struct noeud *next;
    struct noeud *prev;

}noeud;

const int LEN = 3;

void aff(noeud *l);
noeud *liste_cree(noeud *n, int val[], int i);
noeud *ins_deb(noeud *l, noeud *el);
noeud *ins_fin(noeud *l, noeud *el);
void ins_pos(noeud *l, noeud *el, int pos);
noeud *supp_r(noeud *n, int val);

int main()
{
    noeud *n = malloc(sizeof(noeud));
    
    n->prev = NULL;

    int values[LEN];
    for (int i = 0; i < LEN; i++)
    {
        printf("donnez une valeur: ");
        scanf("%i", values + i);
    }
    
    n = liste_cree(n, values, LEN - 1);
    aff(n);

    noeud *el = malloc(sizeof(noeud));
    el->val = 544;

    printf("_______\n");

    n = supp_r(n, 3);
    aff(n);

}



noeud *ins_deb(noeud *l, noeud *el)
{
    l->prev = el;
    el->next = l;
    return el;
}

noeud *ins_fin(noeud *l, noeud *el)
{
    noeud *tmp = l;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = el;
    el->prev = tmp;
    tmp->val = el->val;
    return l;
    
}

void ins_pos(noeud *l, noeud *el, int pos)
{
    noeud *tmp = l;

    for (int i = 0; i < pos; i++)
    {
        tmp = tmp->next;
    }

    el->next = tmp->next;
    tmp->next = el;
    tmp->next->prev = el;
    el->prev = tmp;
    
}

noeud *supp_r(noeud *n, int val)
{
    if (n->val == val) n = n->next;
    noeud *tmp = n;
    while (tmp->next)
    {
        
        if (tmp->val == val)
        {
           
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            
        }
        tmp = tmp->next;
    }
    return n;
}

noeud *liste_cree(noeud *n, int val[], int i)
{
    if (i >= 0)
    {
        noeud *tmp = malloc(sizeof(noeud));
        tmp->next = n;
        n->prev = tmp;
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
    if (l->next != NULL)
    {
        printf("%i\n", l->val);
        aff(l->next);
    }
}