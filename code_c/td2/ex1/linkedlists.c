#include <stdio.h>
#include <stdlib.h>

typedef struct  noeud
{
    int val;
    struct noeud *suiv;
    
}noeud;

// Function declarations
int len(noeud *l);
void aff(noeud *l);
noeud *liste_vide(noeud *n, int len);
void supp(noeud *n, int pos);
void inser(noeud *n, noeud *el, int pos);
void inv(noeud *n);
void inr(noeud *n, int l);

int main()
{
    
}

// Calculates the length of the linked list recursively
int len(noeud *l)
{
    if (l->suiv != NULL)
    {
        return len(l->suiv) + 1;
    }
    else return 0;
}

// Prints the values of all nodes in the linked list
void aff(noeud *l)
{
    if (l->suiv != NULL)
    {
        printf("%i\n", l->val);
        aff(l->suiv);
    }
}

// Creates a new linked list with specified number of nodes, each initialized to 0
noeud *liste_vide(noeud *n, int len)
{
    if (len != 0)
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

// Deletes a node at the specified position in the linked list
void supp(noeud *n, int pos)
{   
    noeud *tmp = n ; 
    for (int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->suiv;
    }
    tmp->suiv = tmp->suiv->suiv;
}

// Inserts a new node at the specified position in the linked list
void inser(noeud *n, noeud *el, int pos)
{
    noeud *tmp = n ; 
    for (int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->suiv;
    }
    el->suiv = tmp->suiv;
    tmp->suiv = el;
}

// Reverses the order of nodes in the linked list
void inv(noeud *n)
{
    int l = len(n);
    noeud *a = n;
    for (int i = 0; i < l / 2; i++)
    {
        noeud *tmp = n;
        for (int j = 0; j < l - i - 1; j++)
        {
            tmp = tmp->suiv;
        }
        int x = tmp->val;
        tmp->val = a->val;
        a->val = x;
        a = a->suiv;
    }
}

// Performs a specific pattern of swapping values in the linked list
void inr(noeud *n, int l)
{
    if (len(n) > 2)
    {
        inr(n->suiv, l);
    }
    else
    {
        int x = n->val;
        n->val = n->suiv->val;
        n->suiv->val = x;
    }
    if (len(n) == 2) return;
    int x = n->val;
    n->val = n->suiv->val;
    n->suiv->val = x;
    if (len(n) == l) inr(n->suiv, l - 1);

}
