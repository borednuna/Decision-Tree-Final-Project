# Decision-Tree-Final-Project
Final project for my data structure class. This implements decision tree to determine user's subject interest in computer science study. The subject interests are based on laboratories in ITS's CS major.


```
Tree Structure :

                        root
                       /    \
                      /      \
               software       data
                 |           /    \
                 |          /      \
            algorithm    database   AI
              /   \         |       |
             /     \        |       |
           yes      no     MCI      KCV
            |       / \ 
            |      /   \
         alpro   dev    network
                /  \       |
               /    \      |
          Graphics  SI    KBJ
              |      |
              |      |
             IGS    RPL

```

To run the program, go to workspace folder, then :

```
make
./main
```