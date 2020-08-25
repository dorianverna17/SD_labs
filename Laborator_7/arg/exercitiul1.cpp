#include <string.h>
#include <stdio.h>

#include "helpers.h"
#include "bst_node.h"

char *serialize(const bst_node_t *root) {
	char *buffer = (char*)malloc(200 * sizeof(char));
	if(root != NULL)
	{
		sprintf(buffer, "(%s %.2f %s)", serialize(root->left), root->value, serialize(root->right));
	}
	return buffer;
}

bst_node_t *deserialize(const char *serialized_tree) {
	return NULL;
}
