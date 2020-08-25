#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "trie.h"
#include "helpers.h"

void insert(trie_node_t *root, char *str) {
    trie_node_t *trie = root;
    int i, aux;
    for (i = 0; i < (int)strlen(str); i++)
    {
        int aux = str[i] - 'a';
        if (trie->children[aux] == NULL)
        	{
        		trie->children[aux] = alloc_trie_node(false);
        	}
        trie = trie->children[aux];
    }
    trie->is_word_end = true;
}

bool contains(trie_node_t *root, char *str) {
    trie_node_t *trie = root;
    int aux;
    for (int i = 0; i < strlen(str); i++)
    {
        aux = str[i] - 'a';
        if (trie->children[aux] == NULL)
            return false;
        trie = trie->children[aux];
    }
    if(trie != NULL && trie->is_word_end == 1)
        return true;
}

void remove(trie_node_t *root, char *str) {
    trie_node_t *trie = root;
    int aux;
    for (int i = 0; i < strlen(str); i++)
    {
        aux = str[i] - 'a';
        trie = trie->children[aux];
    }
    if(trie != NULL && trie->is_word_end == 1)
        {
		trie->is_word_end = 0;
        }
}

char **matchings(trie_node_t *root, char *str) {
	trie_node_t *trie = root;
	int aux;
	for (int i = 0; i < strlen(str); i++)
    {
        aux = str[i] - 'a';
        trie = trie->children[aux];
    }
    char **da;
    // while(trie != NULL)
    // {
    // 	if(trie->is_word_end == 1)
    // 	{ 
    // 	}
    // 	trie = trie->children[]
    // }
  	return NULL;
}

// int main()
// {
// 	trie_node_t *root;
// 	root = alloc_trie_node(false);
// 	char *da;
// 	da = (char*)malloc(100 * sizeof(char));
// 	strcpy(da, "dorian");
// 	insert(root, da);
// 	strcpy(da, "doriana");
// 	insert(root, da);
// 	strcpy(da, "asd");
// 	insert(root, da);
// 	strcpy(da, "asd");
// 	print_trie(root);
// 	printf("%d\n", contains(root, da));
// 	return 0;
// }