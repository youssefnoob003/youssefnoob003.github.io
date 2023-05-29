#include <stdio.h>
#include <stdlib.h>

typedef struct  noeud
{
    int val;
    struct noeud *p_next;
    struct noeud *p_prev;
}noeud;

noeud *liste_vide(noeud *n, int len);
noeud *inser(noeud *n, noeud *element, int pos);
noeud *sup(noeud *n, int pos);
int len(noeud *n);
void print(noeud *n);
void aff(noeud *n, int pos);

int main()
{
    noeud *n = malloc(sizeof(noeud));
    n->p_prev = NULL;
    n = liste_vide(n, 4);

    for (noeud *tmp = n; tmp != NULL; tmp = tmp->p_next)
    {
        scanf("%i", &tmp->val);
    }
    printf("********\n");

    n = sup(n, 3);
    print(n);
}

noeud *liste_vide(noeud *n, int len)
{
    if (len != 1)
    {
        noeud *tmp = malloc(sizeof(noeud));
        tmp->p_next = n;
        n->p_prev = tmp;
        return liste_vide(tmp, len - 1);
    }
    else
    {
        n->p_prev = NULL;
        return n;
    }
}

noeud *inser(noeud *n, noeud *element, int pos)
{
    if (pos == 0)
    {
        element->p_prev = NULL;
        element->p_next = n;
        n->p_prev = element;
        return element;
    }

    noeud *tmp = n;
    for (int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->p_next;
    }
    
    if (tmp->p_next == NULL)
    {
        tmp->p_next = element;
        element->p_prev = tmp;
        element->p_next = NULL;
        return n;
    }
    element->p_next = tmp->p_next;
    tmp->p_next->p_prev = element;
    tmp->p_next = element;
    element->p_prev = tmp;
    return n;
}

noeud *sup(noeud *n, int pos)
{
    if (pos == 0)
    {
        n->p_next->p_prev = NULL;
        return n->p_next;
    }
    noeud *tmp = n;
    for (int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->p_next;
    }
    if (tmp->p_next->p_next == NULL)
    {
        tmp->p_next = NULL;
        return n;
    
    }
    noeud *a = tmp->p_next;
    a->p_next->p_prev = tmp;
    tmp->p_next = a->p_next;
    free(a);
    return n;
}

int len(noeud *n)
{
    int res = 0;
    for (noeud *tmp = n; tmp->p_next != NULL; tmp = tmp->p_next)
    {
        res++;
    }
    return res;
}

void print(noeud *n)
{
    for (noeud *tmp = n; tmp != NULL; tmp = tmp->p_next)
    {
        printf("%i\n", tmp->val);
    }   
}

void aff(noeud *n, int pos)
{
    noeud *tmp = n;
    while (pos != 0)
    {
        tmp = tmp->p_next;
        pos--;
    }
    printf("element: %i\n element precedent: %i\n element suivant: %i\n", tmp->val, tmp->p_prev->val, tmp->p_next->val);
}