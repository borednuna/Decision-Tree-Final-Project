#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "./include/main.h"

void Tree::init() {
    root = NULL;
    size = 0u;
    std::cout << "Tree initialized" << std::endl;
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

node *Tree::userInputUtility(node* q) {
    int opt;
    while(q != NULL) {
        system("clear");
        std::cout << q->statement << std::endl;
        if (q->leftOption != " " && q->rightOption != " ")
            std::cout << "1." << q->leftOption << "\t2." << q->rightOption << std::endl;
        std::cout << std::endl << ">> ";
        std::cin >> opt;

        if (opt == 1) {
            return Tree::userInputUtility(q->left);
        } else if (opt == 2) {
            return Tree::userInputUtility(q->right);
        } else {
            return q;
        }
    }
    return q;
}

void Tree::userInputTraverse() {
    node* temp = userInputUtility(root);
    std::cout << "Done traverse" << std::endl;
    return;
}

void Tree::hardCodedInsert() {
    node* newnode = newNode(
        "Kamu ingin bekerja dengan perangkat lunak atau data ?",
        "Perangkat_Lunak",
        "Data"
    );
    root = newnode;
    size++;

    newnode = newNode(
        "Apakah kamu suka mengerjakan sesuatu yang berhubungan dengan algoritma ?",
        "Ya",
        "Tidak"
    );
    root->left = newnode;
    size++;

    newnode = newNode(
        "Kamu lebih tertarik pada database atau kecerdasan buatan ?",
        "Database",
        "Kecerdasan_Buatan"
    );
    root->right = newnode;
    size++;

    newnode = newNode(
        "Peminatan : Alpro",
        " ",
        " "
    );
    root->left->left = newnode;
    size++;

    newnode = newNode(
        "Kamu lebih tertarik pada software development atau jaringan ?",
        "Software_Development",
        "Jaringan"
    );
    root->left->right = newnode;
    size++;

    newnode = newNode(
        "Peminatan : MCI",
        " ",
        " "
    );
    root->right->left = newnode;
    size++;

    newnode = newNode(
        "Peminatan : KCV",
        " ",
        " "
    );
    root->right->right = newnode;
    size++;

    newnode = newNode(
        "Kamu lebih tertarik pada hal-hal yang berkaitan dengan grafis atau sistem informasi ?",
        "Grafis",
        "Sistem_Informasi"
    );
    root->left->right->left = newnode;
    size++;

    newnode = newNode(
        "Peminatan : KBJ",
        " ",
        " "
    );
    root->left->right->right = newnode;
    size++;

    newnode = newNode(
        "Peminatan : IGS",
        " ",
        " "
    );
    root->left->right->left->left = newnode;
    size++;

    newnode = newNode(
        "Peminatan : RPL",
        " ",
        " "
    );
    root->left->right->left->right = newnode;
    size++;

    std::cout << "Done building tree" << std::endl << std::endl;
}
