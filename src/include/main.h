#include <iostream>
#include <string>
#include <queue>
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
    void fileInputTraverse();   // start determining using file handling

    private:
    node* newNode(std::string statement, std::string leftOp, std::string rightOp);     // create new node
    node* userInputUtility(node* q);                                                   // user input traversal
    std::string fileInputTrvrs(std::queue<std::string> sequence);
    std::queue<std::string> tokenize(std::string strLine);
    node* fileTraverseHelper(node* q, std::queue<std::string> parameter);
};

void getProgramHeader();        // Get program header
