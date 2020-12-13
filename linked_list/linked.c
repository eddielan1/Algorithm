#include "stdlib.h"
#include "stdio.h"

struct Node {
    int data;
    struct Node *next;
} *first;

struct Node* create_node(int *input_array, int array_size) {
    
    printf("%s: array_size = %d\n", __func__, array_size);
    if (input_array == NULL|| array_size == 0) {
        printf("Invalid input parameter!\n");
        return NULL;
    }

    struct Node *tmp, *last;
    // Create first node for Linked list
    tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = input_array[0];
    tmp->next = NULL;
    first = tmp;
    last = tmp;

    // Create left nodes for linked list
    for(int i = 1; i < array_size; i++) {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->data = input_array[i];
        tmp->next = NULL;

        // Last node should point to the current temp node
        last->next = tmp;
        last = tmp;
    }

    return first;
}

void display(struct Node* input_linked_list) {
	if(input_linked_list == NULL) {
        printf("%s: Invalid input parameter\n",__func__);
		return;
	}

    // Lets start displaying the element in linked list
    struct Node *tmp = input_linked_list;
    while (tmp != NULL) {
        printf("%s: %d\n",__func__, tmp->data);
        tmp = tmp->next;
    }

    printf("Finish displaying the linked list\n");
}

int count_linked_list(struct Node *input_array_list) {
    if (input_array_list == NULL) {
        printf("%s:Invalid input parameter\n",__func__);
        return -1;
    }

    // Lets count the total number inside the linked list
    struct Node *tmp = input_array_list;
    int count = 0;
    while(tmp!=NULL) {
        count++;
        tmp=tmp->next;
    }

    printf("%s: total count is %d\n",__func__, count);
    return count;
}

int sum_linked_list(struct Node *input_linked){
    if (input_linked == NULL) {
        printf("%s: Invalid input parameter\n",__func__);
        return -1;
    }
    
    int sum = 0;
    while(input_linked != NULL) {
        sum = sum + input_linked->data;
        input_linked = input_linked->next;
    }
    printf("%s:Sum of this linked list is %d\n",__func__, sum);
    return sum;
}

void max_linked(struct Node *input) {
    if(input == NULL) {
        printf("%s: Invalid input\n",__func__);
        return;
    }

    int max = input->data;
    while(input!=NULL) {
        if(input->data > max) {
            max = input->data;
        }
        input = input->next;
    }

    printf("%s: maximum number = %d\n",__func__,max);
}

int search(struct Node *input, int target) {
    if(input == NULL) {
        printf("%s: Invalid input\n",__func__);
        return -1;
    }

    while(input != NULL) {
        if(input->data == target) {
            printf("%s: found the target \"%d\"\n",__func__, target);
            return target;
        }
        input = input->next;
    }
    // If we do not find the target value in the linked list, return -1
    return -1;

}

int moveHeadSearch(struct Node *input, int target) {
    if(input == NULL) {
        printf("%s: Invalid input\n",__func__);
        return -1;
    }

    struct Node *first_node = input;
    while(input != NULL) {
       if (target == input->data) {
            printf("%s: found the target %d\n",__func__, target);
            int tmp = first_node->data;
            first_node->data = input->data;
            input->data = tmp;
            return target;
       }
       input = input->next;
    }
    return -1;
}

int main() {
    printf("Let's study linked list data structure!\n");

    printf("Let's create a linked list!\n");
    int ret;
    int array[] = {0,1,2,3,4,5};
    int array_size = sizeof(array)/sizeof(array[0]);
	struct Node *ret_ptr = create_node(array, array_size);
	if (!ret_ptr) {
		printf("Failed to create linked list!\n");
		return -1;
	}

    display(ret_ptr);
    ret = count_linked_list(ret_ptr);
    if (ret < 0) {
        printf("Failed to count the total number of linked list\b");
        return -1;
    }
    ret = sum_linked_list(ret_ptr);
    max_linked(ret_ptr);
    search(ret_ptr, 5);
    moveHeadSearch(ret_ptr,4);
    display(ret_ptr);
    

    return 0;

}
