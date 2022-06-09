#include <iostream>
#include <string>
#include <stdlib.h>
#include "./include/main.h"

void Tree::init() {
    root = NULL;
    size = 0u;
}

int Tree::isEmpty() {
    return(root == NULL);
}

node *Tree::newNode(std::string statement, std::string leftOp, std::string rightOp) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode->statement = statement;
    newNode->leftOption = leftOp;
    newNode->rightOption = rightOp;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Tree::hardCodedInsert() {
    node* newnode = newNode(
        "Kamu ingin bekerja dengan perangkat lunak atau data ?",
        "Perangkat Lunak",
        "Data");
        root = newnode;
}
