#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include "./include/main.h"

int main() {
    Tree studyTree;
    studyTree.init();
    studyTree.hardCodedInsert();

    int method;

    while (method != 0) {
        system("clear");
        getProgramHeader();
        std::cout << "Choose input method :" << std::endl;
        std::cout << "1.User input \t>> 2.File input \t>> 0.exit" << std::endl;
        std::cout << ">> ";
        std::cin >> method;

        switch (method) {
        case 1:
            studyTree.userInputTraverse();
            break;
        case 2:
            studyTree.fileInputTraverse();
            break;
        }
    }

    std::cout << "Exited program" << std::endl;
}
