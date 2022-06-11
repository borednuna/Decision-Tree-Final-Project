#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <queue>
#include "./include/main.h"

void Tree::init() {
    root = NULL;
    size = 0u;
    std::cout << "Tree initialized" << std::endl;
}

int Tree::isEmpty() {
    return(root == NULL);
}

node* Tree::newNode(std::string statement, std::string leftOp, std::string rightOp) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode->statement = statement;
    newNode->leftOption = leftOp;
    newNode->rightOption = rightOp;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node* Tree::userInputUtility(node* q) {
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

std::queue<std::string> Tree::tokenize(std::string strLine) {
    std::queue<std::string> temp;
        std::string token = "";
        for (auto x = strLine.begin(); x != strLine.end(); x++) {
            if (*x == ' ') {
                temp.push(token);
                token.erase(token.begin(), token.end());
            } else {
                token = token + *x;
            }
        }
        temp.push(token);

    return temp;
}

node* Tree::fileTraverseHelper(node* q, std::queue<std::string> parameter) {
    while(q != NULL) {
        if (parameter.front() == q->leftOption) {
            parameter.pop();
            return fileTraverseHelper(q->left, parameter);
        } else if (parameter.front() == q->rightOption) { {
            parameter.pop();
            return fileTraverseHelper(q->right, parameter);
        }
        return q;
    }
}
}

std::string Tree::fileInputTrvrs(std::queue<std::string> sequence) {
    // std::cout << strIn << std::endl;
    // std::cout << sequence.front();
    // return sequence.front();
    node* temp = fileTraverseHelper(root, sequence);
    return temp->statement;
}

void Tree::fileInputTraverse() {
    system("clear");
    std::fstream inputFile, outputFile;
    inputFile.open("./src/data/input.txt", std::ios::in);
    outputFile.open("./src/data/output.txt", std::ios::out);

    if (!inputFile || !outputFile) {
        std::cout << "File not found" << std::endl;
    } else {
        std::cout << "File is open" << std::endl;
    }

    std::string strLine, strOut, userName;
    while (std::getline(inputFile, strLine)) {
        std::queue<std::string> sequence = tokenize(strLine);
        userName = sequence.front();
        sequence.pop();
        strOut = fileInputTrvrs(sequence);
    }

    std::string n = "x";
    while(n != "e") {
        std::cout << std::endl << "Input e to continue ..." << std::endl;
        std::cin >> n;
    }

    inputFile.close();
    outputFile.close();
}

void getProgramHeader() {
    std::cout << " ==================================================" << std::endl;
    std::cout << "|               Desicion Tree Program              |" << std::endl;
    std::cout << "|     Topic : CS Subject Interest Determination    |" << std::endl;
    std::cout << "|                 Hanun Shaka Puspa                |" << std::endl;
    std::cout << "|                    5025211051                    |" << std::endl;
    std::cout << " ==================================================" << std::endl << std::endl;
}
