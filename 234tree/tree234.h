#ifndef TREE234_H_
#define TREE234_H_

#include "node234.h"

class tree234
{
public:
    node234* root;
    tree234();
    void insert(int key);
    void display(node234* node);

};

tree234::tree234()
{
    root = nullptr;
}

void tree234::insert(int key)
{
    node234* current = root;
    node234* parent = root;

    // если дерево пустое
    if (root == nullptr)
    {
        root = new node234(key);
    }
    else
    {
        while (true)
        {
            // если текущий узел не лист и не узел с 4 потомками
            // продолжаем спускаться вниз по дереву
            if (!current->isLeaf() && !current->is4Node())
            {
                parent = current;
                // если текущий узел имеет 2 потомка
                if (current->is2Node())
                {
                    if (key < current->leftKey)
                    {
                        current = current->leftLeft;
                    }
                    else
                    {
                        current = current->leftMid;
                    }
                }
                    // если текущий узел имеет 3 потомка
                else
                {
                    if (key < current->leftKey)
                    {
                        current = current->leftLeft;
                    }
                    else if (key < current->midKey)
                    {
                        current = current->leftMid;
                    }
                    else
                    {
                        current = current->rightMid;
                    }
                }
            }

                // если текущий узел имеет 4 потомка
            else if (current->is4Node())
            {
                // Если родитель имеет 1 ключ
                if (parent->is2Node())
                {
                    // Если текущий узел это правый потомок родителя
                    if (parent->leftKey < current->leftKey)
                    {
                        parent->midKey = current->midKey;
                        parent->leftMid = new node234(current->leftKey,
                                                      current->leftLeft, current->leftMid);
                        parent->rightMid = new node234(current->rightKey,
                                                       current->rightMid, current->rightRight);
                    }
                    // Если текущий узел это левый потомок родителя
                    else
                    {
                        parent->midKey = parent->leftKey;
                        parent->rightMid = parent->leftMid;
                        parent->leftKey = current->midKey;
                        parent->leftLeft = new node234(current->leftKey,
                                                       current->leftLeft, current->leftMid);
                        parent->leftMid = new node234(current->rightKey,
                                                      current->rightMid, current->rightRight);
                    }
                    // продолжаем спускаться вниз по дереву
                    // идём в левого потомка
                    if (key < parent->leftKey)
                    {
                        current = parent->leftLeft;
                    }
                        // идем в среднего потомка
                    else if (key < parent->midKey)
                    {
                        current = parent->leftMid;
                    }
                        // идём в правого потомка
                    else
                    {
                        current = parent->rightMid;
                    }

                }
                    // Если родитель имеет 2 ключа
                else if (parent->is3Node())
                {
                    // если текущий узел это правый потомок родителя
                    if (parent->midKey < current->leftKey)
                    {
                        parent->rightKey = current->midKey;
                        parent->rightMid = new node234(current->leftKey,
                                                       current->leftLeft, current->leftMid);
                        parent->rightRight = new node234(current->rightKey,
                                                         current->rightMid, current->rightRight);
                    }
                        // если текущий узел это средний потомок родителя
                    else if(parent->leftKey < current->leftKey)
                    {
                        parent->rightKey = parent->midKey;
                        parent->rightRight = parent->rightMid;
                        parent->midKey = current->midKey;
                        parent->leftMid = new node234(current->leftKey,
                                                      current->leftLeft, current->leftMid);
                        parent->rightMid = new node234(current->rightKey,
                                                       current->rightMid, current->rightRight);
                    }
                        // если текущий узел это левый потомок родителя
                    else
                    {
                        parent->rightKey = parent->midKey;
                        parent->rightRight = parent->rightMid;
                        parent->midKey = parent->leftKey;
                        parent->rightMid = parent->leftMid;
                        parent->leftKey = current->midKey;
                        parent->leftLeft = new node234(current->leftKey,
                                                       current->leftLeft, current->leftMid);
                        parent->leftMid = new node234(current->rightKey,
                                                      current->rightMid, current->rightRight);
                    }
                    // продолжаем спускаться вниз по дереву
                    // спускаемся в левого ребенка
                    if (key < parent->leftKey)
                    {
                        current = parent->leftLeft;
                    }
                    // спускаемся в левого среднего ребенка
                    else if (key < parent->midKey)
                    {
                        current = parent->leftMid;
                    }
                        // идем в правого среднего ребенка
                    else if (key < parent->rightKey)
                    {
                        current = parent->rightMid;
                    }
                        // идём в правого ребенка
                    else
                    {
                        current = parent->rightRight;
                    }
                }
                    // если узел имеет 3 ключа
                else
                {
                    root = new node234(current->midKey);
                    root->leftLeft = new node234(current->leftKey,
                                                 current->leftLeft, current->leftMid);
                    root->leftMid = new node234(current->rightKey,
                                                current->rightMid, current->rightRight);
                    parent = root;
                    // продолжаем спускаться
                    // идем в левого потомка
                    if (key < parent->leftKey)
                    {
                        current = parent->leftLeft;
                    }
                        // идем в правого потомка
                    else
                    {
                        current = parent->leftMid;
                    }
                }
            }
                // если узел не имеет 3 ключа
            else
            {
                // 1 ключ
                if (current->is2Node())
                {
                    // если добавляемый ключ должен быть левым ключем
                    if (key < current->leftKey)
                    {
                        current->midKey = current->leftKey;
                        current->leftKey = key;
                    }
                        // -//- правым ключем
                    else
                    {
                        current->midKey = key;
                    }
                }
                    // если узел имеет 2 ключа
                else
                {
                    // если добавляемый ключ должен быть левым ключем
                    if (key < current->leftKey)
                    {
                        current->rightKey = current->midKey;
                        current->midKey = current->leftKey;
                        current->leftKey = key;
                    }
                        // если добавляемый ключ должен быть средним ключем
                    else if (key < current->midKey)
                    {
                        current->rightKey = current->midKey;
                        current->midKey = key;
                    }
                        // если добавляемый ключ должен быть правым ключем
                    else
                    {
                        current->rightKey = key;
                    }
                }
                break;
            }
        }
    }
}

void tree234::display(node234* node)
{
    if (node != nullptr)
    {
        if (node->is2Node())
        {
            display(node->leftLeft);
            std::cout << node->leftKey << std::endl;
            display(node->leftMid);
        }
        else if (node->is3Node())
        {
            display(node->leftLeft);
            std::cout << node->leftKey << std::endl;
            display(node->leftMid);
            std::cout << node->midKey << std::endl;
            display(node->rightMid);
        }
        else
        {
            display(node->leftLeft);
            std::cout << node->leftKey << std::endl;
            display(node->leftMid);
            std::cout << node->midKey << std::endl;
            display(node->rightMid);
            std::cout << node->rightKey << std::endl;
            display(node->rightRight);
        }
    }
}

#endif // TREE234_H_