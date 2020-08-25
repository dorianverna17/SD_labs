#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst_node {
	double value;
	struct bst_node *parent;
	struct bst_node *left;
	struct bst_node *right;
} bst_node_t;

typedef void (*func_t)(bst_node_t * const node);

void functie(bst_node_t *x)
{
	printf("%f\n", x->value);
}

void travers_in(bst_node_t *root)
{
	if(root == NULL)
		return;
	travers_in(root->left);
	printf("%lf\n", root->value);
	travers_in(root->right);
}
void insert_helper(bst_node_t **root, bst_node_t **new_node, double value)
{
	(*new_node)->parent = *root;
	if (*root) {
		if (value < (*root)->value)
			if((*root)->left)
				insert_helper(&(*root)->left, new_node, value);
			else
				(*root)->left = *new_node;
		else
			if (value > (*root)->value)
				if((*root)->right)
					insert_helper(&(*root)->right, new_node, value);
				else
					(*root)->right = *new_node;
			else
				printf("Elementul exista deja in arbore\n");
	}
	else
	{
		*root = *new_node;
		(*root)->left = NULL;
		(*root)->right = NULL; 
	}
}

void insert(bst_node_t **root, const double value)
{
	bst_node_t *new_node;
	new_node = malloc(sizeof(bst_node_t));
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = *root;
	insert_helper(root, &new_node, value);
}

bst_node_t *search(bst_node_t *root, const double value)
{
	if (root == NULL) 
		return NULL;
	else {
		if(root->value == value)
			{
			return root;
			}
		if(root->value > value)
			return search(root->left, value);
		if(root->value < value)
			return search(root->right, value);
	}
}

double minValue(bst_node_t *root)
{
	if(root == NULL)
		return (root->value);
	minValue((root)->left);
}

void remove_node(bst_node_t **root, const double value)
{
	if ((*root)->value == value && (*root)->parent == NULL) {
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root) = NULL;
	} else
		if ((*root)->value == value) {
			if((*root)->left == NULL && (*root)->right == NULL) {
					if((*root)->parent->left->value == value)
						(*root)->parent->left = NULL;
					else
						(*root)->parent->right = NULL;
				} else 
					if ((*root)->left == NULL) {
						(*root)->right->parent = (*root)->parent;
						(*root) = (*root)->right;
				} else
					if ((*root)->right == NULL) {
						(*root)->left->parent = (*root)->parent;
						(*root) = (*root)->left;
				} else {
						(*root)->value = minValue(*root);
						remove_node(&(*root)->right, value);
					}
		} else 
			if (value < (*root)->value) {
				remove_node(&(*root)->left, value);
		} else if(value > (*root)->value) {
			remove_node(&(*root)->right, value);
		}
}

size_t node_height(bst_node_t *node)
{
	if(node != NULL)
		return 1 + node_height(node->parent);
	else
		return 0;
}

size_t tree_height_helper(bst_node_t *root, size_t left_d, size_t right_d)
{
	if(root == NULL)
	{
		return 0;
	}
	else {
		left_d = tree_height_helper(root->left, left_d, right_d);
		right_d = tree_height_helper(root->right, left_d, right_d);
		if(left_d > right_d)
			return left_d + 1;
		else
			return right_d + 1;
	}
}

size_t tree_height(bst_node_t *root)
{
	size_t left_d = 0, right_d = 0;
	return tree_height_helper(root, left_d, right_d) - 1;
}

void traverse_in_order(bst_node_t * const root, func_t func)
{
	if(root == NULL)
		return;
	traverse_in_order(root->left, func);
	func(root);
	traverse_in_order(root->right, func);
} 

void traverse_pre_order(bst_node_t * const root, func_t func)
{
	if(root == NULL)
		return;
	func(root);
	traverse_in_order(root->left, func);
	traverse_in_order(root->right, func);
}

void traverse_post_order(bst_node_t * const root, func_t func)
{
	if(root == NULL)
		return;
	traverse_in_order(root->left, func);
	traverse_in_order(root->right, func);
	func(root);
} 

int main(void)
{
	double d;
	bst_node_t *root;
	root = malloc(sizeof(bst_node_t));
	root->parent = NULL;
	root->left = NULL;	
	root->right = NULL;
	scanf("%lf", &d);
	root->value = d;
	scanf("%lf", &d);
	while (d != -1) {
		insert(&root, d);
		scanf("%lf", &d);
	}
	printf("Inaltimea arborelui este: %ld\n", tree_height(root));
	travers_in(root);
	printf("\n");
	double s;
	printf("Ce nod vrei sa cauti?\n");
	scanf("%lf", &s);
	bst_node_t *p = search(root, s);
	printf("%lf\n", p->value);
	printf("\n");
	printf("Ce nod vrei sa stergi?\n");
	scanf("%lf", &s);
	remove_node(&root, s);
	travers_in(root);
	printf("Inaltimea arborelui este: %ld\n", tree_height(root));
	printf("Inaltimea nodului corespunzator lui root->left este %ld\n",
	node_height(root->left));
	printf("Traverse in inorder:\n");
	traverse_in_order(root, functie);
	printf("Traverse in preorder:\n");
	traverse_pre_order(root, functie);
	printf("Traverse in postorder:\n");
	traverse_post_order(root, functie);
	return 0;
}
