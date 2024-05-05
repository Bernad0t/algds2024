#include "./alg.h"

int main() {
	int count = 0;
	int element;
	tree_t* tree = NULL;
	int arr_elements[5] = { 3, 5, 4, 8, 7 };
	while (count != 5) {
		//scanf_s("%d", &element);
		element = arr_elements[count];
		add_new_element(&tree, element);
		count++;
	}
	printf("TREE\n");
	PrintTree(tree, 0);
	search_element(&tree, 3);
	printf("FIND 3\n");
	PrintTree(tree, 0);
	/*search_element(&tree, 7);
	printf("FIND 7\n");
	PrintTree(tree, 0);
	search_element(&tree, 7);
	printf("FIND 7\n");
	PrintTree(tree, 0);
	search_element(&tree, 10);
	printf("FIND 10\n");
	PrintTree(tree, 0);*/
	/*delete_element(&tree, 5);
	printf("DELETE 5\n");
	PrintTree(tree, 0);*/
	delete_element(&tree, 3);
	printf("DELETE 3\n");
	PrintTree(tree, 0);
	free_tree(&tree);
	return 0;
}