#include <iostream>

#include "tree234.h"
#include "node234.h"

int main()
{
    tree234 tree;

    tree.insert(1);
    tree.insert(12);
    tree.insert(8);
    tree.insert(2);
    tree.insert(25);
    tree.insert(6);
    tree.insert(14);
    tree.insert(28);
    tree.insert(17);
    tree.insert(7);
    tree.insert(52);
    tree.insert(16);
    tree.insert(48);
    tree.insert(68);
    tree.insert(3);
    tree.insert(26);
    tree.insert(29);
    tree.insert(53);
    tree.insert(55);
    tree.insert(45);

    tree.display(tree.root);

    return 0;
}