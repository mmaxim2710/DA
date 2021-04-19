#ifndef NODE234_H_
#define NODE234_H_

class node234
{
public:
    // ключи
    int leftKey;
    int midKey;
    int rightKey;

    // указатели на потомков
    node234* leftLeft;
    node234* leftMid;
    node234* rightMid;
    node234* rightRight;

    node234();
    node234(int key);
    node234(int key, node234* left, node234* right);

    bool is2Node();
    bool is3Node();
    bool is4Node();
    bool isLeaf();
};

node234::node234()
{
    leftKey = 0;
    midKey = 0;
    rightKey = 0;
    leftLeft = nullptr;
    leftMid = nullptr;
    rightMid = nullptr;
    rightRight = nullptr;
}

node234::node234(int key)
{
    leftKey = key;
    midKey = 0;
    rightKey = 0;
    leftLeft = nullptr;
    leftMid = nullptr;
    rightMid = nullptr;
    rightRight = nullptr;
}

node234::node234(int key, node234* left, node234* right)
{
    leftKey = key;
    midKey = 0;
    rightKey = 0;
    leftLeft = left;
    leftMid = right;
    rightMid = nullptr;
    rightRight = nullptr;
}

bool node234::is2Node()
{
    return (leftKey != 0 && midKey == 0 && rightKey == 0);
}

bool node234::is3Node()
{
    return (leftKey != 0 && midKey != 0 && rightKey == 0);
}

bool node234::is4Node()
{
    return (leftKey != 0 && midKey != 0 && rightKey != 0);
}

bool node234::isLeaf()
{
    return (leftLeft == nullptr && leftMid == nullptr &&
            rightMid == nullptr && rightRight == nullptr);
}

#endif // NODE234_H_