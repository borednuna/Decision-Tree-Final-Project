#include <iostream>
#include <string>
#include <stdlib.h>

struct node {
    node *left;
    node *right;
    std::string statement;
    std::string rightOption;
    std::string leftOption;
};

class Tree {
    public:
    node *root;                 // declare root node
    unsigned int size;          // declare Tree size

    void init();                // init Tree
    int isEmpty();              // return if tree is empty as boolean integer
    void hardCodedInsert();     // insert hardcoded parameters to tree
    void userInputTraverse();   // start determining using user input

    private:
    node* newNode(std::string statement, std::string leftOp, std::string rightOp);     // create new node
    node* userInputUtility(node* q);
};
