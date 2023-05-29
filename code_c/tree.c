#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
}node;

typedef node *arbre;

arbre creer_noeud(int el);
arbre fusion(int el, arbre ag, arbre ad);
int taille_abr(arbre a);
int profondeur_abr(arbre a);
int recherche_abr(int el, arbre a);
void parcours_postfixe(arbre a);
void parcours_prefixe(arbre a);
void parcours_infixe(arbre a);
arbre ajouter_abr(arbre ar, int el);
arbre supprimer_abr(arbre ar, int el);
int somme(arbre ar);
int nb_feuilles(arbre a);
int som_feuilles(arbre a);
void detruire_arbre(arbre a);
int verif(arbre a);
void chemin(arbre a, int el);
int niveau(arbre a);
int prof(arbre a, int x);
int cousin(arbre a, int x, int y);
void print_prof(arbre a, int niv);
void largeur(arbre a);
arbre build_tree();

int main()
{

    arbre a = build_tree();
    largeur(a);

}

arbre creer_noeud(int el)
{
    arbre res = malloc(sizeof(node));
    
    if (res == NULL)
    {
        printf("Erreur d'allocation\n");
        exit(1);
    }

    res->val = el;
    res->left = NULL;
    res->right = NULL;

    return res;
}

arbre fusion(int el, arbre ag, arbre ad)
{
    arbre res = creer_noeud(el);
    res->left = ag;
    res->right = ad;

    return res;
}

int taille_abr(arbre a)
{
    if (a == NULL)
    {
        return 0;
    }

    int p1;
    int p2;

    p1 = taille_abr(a->left);
    p2 = taille_abr(a->right);

    return p1 + p2 + 1;
}

int profondeur_abr(arbre a)
{
    if (a == NULL)
    {
        return 0;
    }

    int p1 = profondeur_abr(a->left);
    int p2 = profondeur_abr(a->right);

    if (p1 > p2)
    {
        return p1 + 1;
    }
    
    else
    {
        return p2 + 1;
    }

}

int recherche_abr(int el, arbre a)
{
    if (a == NULL)
    {
        return 0;
    }
    
    else if (a->val == el)
    {
        return 1;
    }

    else if (a->val > el)
    {
        return recherche_abr(el, a->left);
    }
    
    else
    {
        return recherche_abr(el, a->right);
    }
}

void parcours_postfixe(arbre a)
{
    if (a != NULL)
    {
        parcours_postfixe(a->left);
        parcours_postfixe(a->right);
        printf("%i\n", a->val);
    }
}

void parcours_prefixe(arbre a)
{
    if (a != NULL)
    {
        printf("%i\n", a->val);
        parcours_prefixe(a->left);
        parcours_prefixe(a->right);
    }
}

void parcours_infixe(arbre a)
{
    if (a != NULL)
    {
        parcours_infixe(a->left);
        printf("%i\n", a->val);
        parcours_infixe(a->right);
    }
}

arbre ajouter_abr(arbre ar, int el)
{
    if (ar == NULL)
    {
        arbre n = creer_noeud(el);
        return n;
    }
    if (el > ar->val)
    {
        ar->right = ajouter_abr(ar->right, el);
    }
    else
    {
        ar->left = ajouter_abr(ar->left, el);
    }
    return ar;
}

arbre supprimer_abr(arbre ar, int el)
{
    if (ar == NULL)
    {
        printf("Element non trouvé.\n");
        return NULL;
    }

    if (ar->val == el)
    {
        if (ar->right == NULL && ar->left == NULL)
        {
            free(ar);
            return NULL;
        }

        if (ar->right == NULL)
        {
            return ar->left;
        }

        if (ar->left == NULL)
        {
            return ar->right;
        }

        arbre successeur = ar->left;
        while (successeur->right != NULL)
        {
            successeur = successeur->right;
        }
        ar->val = successeur->val;
        ar->left = supprimer_abr(ar->left, successeur->val);
    }
    else
    {
        if (el > ar->val)
        {
            ar->right = supprimer_abr(ar->right, el);
        }
        else
        {
            ar->left = supprimer_abr(ar->left, el);
        }
    }
    return ar;
}

int somme(arbre ar)
{
    if (ar == NULL)
    {
        return 0;
    }
    
    int a = somme(ar->left);
    int b = somme(ar->right);
    return a + b + ar->val;
}

int nb_feuilles(arbre a)
{
    if (a == NULL)
    {
        return 0;
    }
    if (a->left == NULL && a->right == NULL)
    {
        return 1;
    }

    else
    {
        return nb_feuilles(a->left) + nb_feuilles(a->right);
    }
}

int som_feuilles(arbre a)
{
    if (a == NULL)
    {
        return 0;
    }
    if (a->left == NULL && a->right == NULL)
    {
        return a->val;
    }

    else
    {
        return som_feuilles(a->left) + som_feuilles(a->right);
    }
}

void detruire_arbre(arbre a)
{
    if (a != NULL)
    {
        detruire_arbre(a->left);
        detruire_arbre(a->right);
        free(a);
    }
}

int verif(arbre a)
{
    if (a == NULL) return 1;
    int x, y;
    if (a->left == NULL) x = 1;
    else x = (a->left->val < a->val);
    if (a->right == NULL) y = 1;
    else y = (a->right->val > a->val);
    return (verif(a->left) && verif(a->right)) && x && y;
}

int comparer(arbre a, arbre b)
{
    if (a == NULL && b == NULL)
    {
        return 1;
    }
    if (a != NULL && b != NULL)
    {
        if (a->val == b->val)
        {
            return (comparer(a->left, b->left) && comparer(a->right, b->right));
        }
        
        else
        {
            return 0;
        }
    }

    return 0;
}

void chemin(arbre a, int el)
{
    printf("%i - ", a->val);
    if (el < a->val)
    {
        chemin(a->left, el);
    }
    else if (el > a->val)
    {
        chemin(a->right, el);
    }
    else printf("\n");

}

int niveau(arbre a)
{
    if (a == NULL)
    {
        return 1;
    }
    if (a->left == NULL) return niveau(a->right);
    if (a->right == NULL) return niveau(a->left);
    if (profondeur_abr(a->left) != profondeur_abr(a->right))
    {
        return 0;
    }

    return (niveau(a->left) && niveau(a->right));
}

int prof(arbre a, int x)
{
    int profx = 1;
    arbre tmp = a;
    while (tmp->val != x)
    {
        if (tmp->val > x)
        {
            tmp = tmp->left;
        }

        else tmp = tmp->right;
        profx++;
    }
    return profx;
}

int cousin(arbre a, int x, int y)
{
    if (prof(a, x) != prof(a, y))
    {
        return 0;
    }

    arbre tmp = a;
    while (tmp->left->val != x && tmp->right->val != x)
    {
        if (tmp->val > x)
        {
            tmp = tmp->left;
        }

        else tmp = tmp->right;
    }

    return !((tmp->left != NULL && tmp->left->val == y) || (tmp->right != NULL && tmp->right->val == y));
}
void print_prof(arbre a, int niv)
{
    if (a == NULL) return;
    if (prof(a, a->val) == niv) printf("%i\n", a->val);
    print_prof(a->left, niv-1);
    print_prof(a->right, niv-1);
}
void largeur(arbre a)
{
    for (int i = 0; i < profondeur_abr(a) + 1; i++)
    {
        print_prof(a, i);
    }
}

arbre build_tree()
{
    int val;
    arbre root = NULL;
    while (1) {
        printf("Enter a value to insert (or -1 to stop):\n");
        scanf("%d", &val);
        if (val == -1) {
            break;
        }
        root = ajouter_abr(root, val);
    }
    return root;
}

void supp(arbre *racine, int cle)
{
    arbre curr = racine;
    while (curr->val != cle)
    {
        if (curr->val < cle)
        {
            curr = curr->right;
        }
        else curr = curr->right;
    }
    while (curr->val == cle)
    {
        
    }
}