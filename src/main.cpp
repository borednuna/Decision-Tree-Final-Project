#include <iostream>
#include <string>
#include <stdlib.h>
#include "./include/main.h"

int main() {
    std::cout << "Success" << std::endl;
    Tree studyTree;
    studyTree.init();
    std::cout << studyTree.isEmpty() << std::endl;
    studyTree.hardCodedInsert();
    std::cout << studyTree.root->statement << std::endl;
}
