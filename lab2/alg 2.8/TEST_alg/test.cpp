#include "pch.h"
#include "C:/Users/Admin/source/repos/algds2024/lab2/alg 2.8/alg 2.8/alg.h"


TEST(add_new_element_test, add_new_element_result_list_returned) {
    // arrange
    int arr_elements_test[3] = { 3, 5, 4 };
    tree_t* test_tree = NULL;
    int count = 0;
    int element;
    int list_fact[3] = { 4, 3, 5 };
    //act
    while (count != 3) {
        //scanf_s("%d", &element);
        element = arr_elements_test[count];
        add_new_element(&test_tree, element);
        count++;
    }
    int* list_result = (int*)malloc(sizeof(int) * 3);
    create_list_from_tree(test_tree, list_result, 0, 3);
    // assert
    for (int i = 0; i < 3; i++) {
        ASSERT_EQ(list_fact[i], list_result[i]);
    }
    free(list_result);
    free_tree(&test_tree);
}

TEST(delete_element_test, root_deleted) {
    // arrange
    int arr_elements_test[3] = { 3, 5, 4 };
    tree_t* test_tree = NULL;
    int count = 0;
    int element;
    int list_fact[3] = { 5, 3 };
    while (count != 3) {
        //scanf_s("%d", &element);
        element = arr_elements_test[count];
        add_new_element(&test_tree, element);
        count++;
    }
    //act
    delete_element(&test_tree, 4);
    int* list_result = (int*)malloc(sizeof(int) * 2);
    create_list_from_tree(test_tree, list_result, 0, 2);
    // assert
    for (int i = 0; i < 2; i++) {
        ASSERT_EQ(list_fact[i], list_result[i]);
    }
    free(list_result);
    free_tree(&test_tree);
}

TEST(delete_element_test, not_root_deleted) {
    // arrange
    int arr_elements_test[3] = { 3, 5, 4 };
    tree_t* test_tree = NULL;
    int count = 0;
    int element;
    int list_fact[2] = { 4, 3 };
    while (count != 3) {
        //scanf_s("%d", &element);
        element = arr_elements_test[count];
        add_new_element(&test_tree, element);
        count++;
    }
    //act
    delete_element(&test_tree, 5);
    int* list_result = (int*)malloc(sizeof(int) * 2);
    create_list_from_tree(test_tree, list_result, 0, 2);
    // assert
    for (int i = 0; i < 2; i++) {
        ASSERT_EQ(list_fact[i], list_result[i]);
    }
    free(list_result);
    free_tree(&test_tree);
}

TEST(search_element_test, search_element_from_tree) {
    // arrange
    int arr_elements_test[3] = { 3, 5, 4 };
    tree_t* test_tree = NULL;
    int count = 0;
    int element;
    int list_fact[6] = { 3, NULL, 4, NULL, NULL, 5 };
    while (count != 3) {
        //scanf_s("%d", &element);
        element = arr_elements_test[count];
        add_new_element(&test_tree, element);
        count++;
    }
    //act
    search_element(&test_tree, 3);
    int* list_result = (int*)malloc(sizeof(int) * 6);
    create_list_from_tree(test_tree, list_result, 0, 6);
    // assert
    for (int i = 0; i < 3; i++) {
        ASSERT_EQ(list_fact[i], list_result[i]);
    }
    free(list_result);
    free_tree(&test_tree);
}

TEST(search_element_test, search_element_not_from_tree) {
    // arrange
    int arr_elements_test[3] = { 3, 5, 4 };
    tree_t* test_tree = NULL;
    int count = 0;
    int element;
    int list_fact[5] = { 5, 4, NULL, 3, NULL};
    while (count != 3) {
        //scanf_s("%d", &element);
        element = arr_elements_test[count];
        add_new_element(&test_tree, element);
        count++;
    }
    //act
    search_element(&test_tree, 6);
    int* list_result = (int*)malloc(sizeof(int) * 5);
    create_list_from_tree(test_tree, list_result, 0, 5);
    // assert
    for (int i = 0; i < 2; i++) {
        ASSERT_EQ(list_fact[i], list_result[i]);
    }
    free(list_result);
    free_tree(&test_tree);
}