#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst_node {
	double value;
	struct bst_node *parent;
	struct bst_node *left;
	struct bst_node *right;
} bst_node_t;

char *serializare(const bst_node_t *root)
{
	char *buffer = (char*)malloc(200 * sizeof(char));
	if(root != NULL)
	{
		sprintf(buffer, "(%s %.2f %s)", serializare(root->left), root->value, serializare(root->right));
		printf("%s\n", buffer);
	}
	else
		return "";
}

bst_node_t *deserialize(const char *serialized_tree);

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

void traverse_in_order(bst_node_t * const root)
{
	if(root == NULL)
		return;
	traverse_in_order(root->left);
	printf("%.2f\n", root->value);
	traverse_in_order(root->right);
} 

int main()
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
	traverse_in_order(root);
	printf("\n");
	//printf("%f\n", root->left->value);
	
	printf("%s\n", serializare(root));
	//serializare(root);
	//printf("%s\n", buffer);
	//int i = 9;
	//sprintf(buffer, "%d %d", 4, 3);
	//printf("%s\n", buffer);
	//sprintf(buffer, "%d", sprintf(buffer, "%d%d", 4, 3));
	//printf("%s\n", buffer);
	return 0;
}