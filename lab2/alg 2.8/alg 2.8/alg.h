#ifndef _MYINCL1_H
#define _MYINCL1_H
#include <stdio.h>
#include <stdlib.h>

 typedef struct tree_t {
	int element;
	struct tree_t* left; //меньше
	struct tree_t* right; //больше или равно
}tree_t;

void Zig_right(tree_t** tree, tree_t* x) {
	tree_t* x_tmp = x->right;
	x->right = (*tree);
	(*tree)->left = x_tmp;
	*tree = x;
}

void Zig_left(tree_t** tree, tree_t* x) {
	tree_t* x_tmp = x->left;
	x->left = (*tree);
	(*tree)->right = x_tmp;
	*tree = x;
}

void PrintTree(tree_t* tree, int count) {
	if (tree == NULL) return;
	PrintTree(tree->right, ++count);
	for (int i = 0; i < count; i++) {
		printf(" ");
	}
	printf("%i\n", tree->element);
	PrintTree(tree->left, ++count);
}

void add_new_element(tree_t** tree, int element) {
	if (*tree == NULL) {
		tree_t* new_tree = (tree_t*)malloc(sizeof(tree_t));
		new_tree->element = element;
		new_tree->left = NULL;
		new_tree->right = NULL;
		*tree = new_tree;
		return;
	}
	if (element >= (*tree)->element) {
		add_new_element(&((*tree)->right), element);
		Zig_left(tree, ((*tree)->right));
	}
	else {
		add_new_element(&((*tree)->left), element);
		Zig_right(tree, ((*tree)->left));
	}
}

void search_element(tree_t** tree, int element) {
	if ((*tree) == NULL) return; //если дерево было пустым, то сюда мы попадем, иначе нет
	if ((*tree)->element == element) {
		return;
	}
	if (element >= (*tree)->element) {
		if ((*tree)->right != NULL)
			search_element(&((*tree)->right), element);
		else
			return;
		Zig_left(tree, ((*tree)->right));
	}
	else {
		if ((*tree)->left != NULL)
			search_element(&((*tree)->left), element);
		else
			return;
		Zig_right(tree, ((*tree)->left));
	}
}

void min_to_top(tree_t** tree) {
	if (*tree == NULL) {
		return;
	}
	if ((*tree)->left == NULL) {
		return;
	}
	else {
		min_to_top(&((*tree)->left));
		Zig_right(tree, ((*tree)->left));
	}
}

void delete_element(tree_t** tree, int element) {
	search_element(tree, element);
	if ((*tree)->element == element) {
		tree_t* tmp_left = (*tree)->left;
		tree_t* tmp_right = (*tree)->right;
		free((*tree));
		if (tmp_right != NULL) {
			min_to_top(&tmp_right);
			tmp_right->left = tmp_left;
			*tree = tmp_right;
		}
		else *tree = tmp_left;
	}
}

void create_list_from_tree(tree_t* tree, int* list, int position, int size) {
	if (size <= position) return;
	if (tree == NULL) {
		list[position] = NULL;
		return;
	}
	list[position] = tree->element;
	create_list_from_tree(tree->left, list, position * 2 + 1, size);
	create_list_from_tree(tree->right, list, position * 2 + 2, size);
}

void free_tree(tree_t** tree) {
	if (*tree == NULL) return;
	free_tree(&((*tree)->left));
	free_tree(&((*tree)->right));
	free(*tree);
}

#endif // _MYINCL1_H