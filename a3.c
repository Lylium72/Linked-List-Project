#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for storing Product Information
typedef struct ProductDescription{
    char productName [25];
    float productPrice;
    float productWeight;

} Product;

//node used for making a linked list
typedef struct ProductList{
    Product product;
    struct ProductList *next;

} ProList;

//----------------------------------------------------------------------------------//
void InitiateList(ProList **head){
    *head = NULL;//initiates the list
}

void InsertAtBeginning(char name[], float price, float weight, ProList **head){

    ProList *node = (ProList*)malloc(sizeof(ProList));//allocates memory for element

    //assigns element data
    strcpy(node->product.productName, name);
    node->product.productPrice = price;
    node->product.productWeight = weight;
    node->next = NULL;

    //special case for empty list
    if (*head==NULL){
        *head = node;
    }else{
        node->next = *head;
        *head = node;//initiates new node
    }
}

void InsertAtEnd(char name[], float price, float weight, ProList **head){


    ProList *node = (ProList*)malloc(sizeof(ProList));

    strcpy(node->product.productName, name);
    node->product.productPrice = price;
    node->product.productWeight = weight;
    node->next = NULL;

    if(*head==NULL){
        InsertAtBeginning(name, price, weight, head);
        return ;
    }

    ProList * current = *head;


    while(current->next!=NULL){

        current = current->next;
    }
    current->next = node;

}


void DeleteAtBeginning(ProList **head){

    if(*head!=NULL){
        ProList *node = *head;
        *head = (*head)->next;
        free(node);
    }
}

void DeleteAtEnd(ProList **head){

    ProList *current = *head;

    if(*head == NULL){
        return ;
    }

    if((*head)->next == NULL){
        return ;
    }

    while(current->next->next!=NULL){
        current = current->next;
    }

    ProList *node = current->next;
    current->next = NULL;
    free(node);
}

void PrintList(ProList *head) {

    ProList *current;
    current = head;

    while (current != NULL) {

        printf("\nName: %s\n", current->product.productName);
        printf("Price: %f\n", current->product.productPrice);
        printf("Weight: %f\n", current->product.productWeight);
        current = current->next;

    }
}

void ClearList(ProList **head){

    ProList *current  = *head;

    while(current!=NULL){
        free(*head);
        current = current->next;
        *head = current;
    }
}

//----------------------------------------------------------------------------------//

void MenuChoice(ProList *head, char choice){
    char name[25];
    float price;
    float weight;

    switch(choice){
        case 'a':
            printf("\nPlease Enter the Product Name (25 char max): ");
            scanf(" %[^\n]s", &name);

            printf("Please Enter the Product Price: ");
            scanf(" %f", &price);

            printf("Please Enter the Product Weight: ");
            scanf(" %f", &weight);

            InsertAtBeginning(name, price, weight, &head);
            break;

        case 'b':
            DeleteAtBeginning(&head);
            break;

        case 'c':
            PrintList(head);
            scanf("\n\nPress enter to continue...");
            break;

        default:
            return ;
    }
}

void Menu(ProList *head){
    char choice;

    //while(choice != 'g'){
        printf("\n\n/----------------------\\\n");
        printf("Add New Product      (a)\n");
        printf("Remove Last Product  (b)\n");
        printf("Display Product List (c)\n");
        printf("Save Product List    (d)\n");
        printf("Load Product List    (e)\n");
        printf("Delete Product List  (f)\n");
        printf("Exit Program         (g)\n");
        printf("\\----------------------/\n");
        printf("\nWhat would you like to do (lowercase only):\n");
        scanf("%c", &choice);

        if(choice == 'g'){
            //break;
        }

        //system("cls");
        MenuChoice(head, choice);
    //}
    return ;
}

int main() {

    ProList *head;
    InitiateList(&head);

    MenuChoice(head, 'a');
    PrintList(head);

    return 0;
}
