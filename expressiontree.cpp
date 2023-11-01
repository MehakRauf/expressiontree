#include <iostream>
#include <stdlib.h>
using namespace std;

struct tree
{
    char data;
    tree *right;
    tree *left;
};

tree *createNode(char c)
{
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = c;
    temp->right = temp->left = NULL;
    return temp;
}
bool ifOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '&' || c == '|' || c == '>' || c == '<' || c == '!')
    {
        return true;
    }
    return false;
}
tree *expressiontree(string ptfix)
{
    tree *stack[1000];
    tree *t, *t1, *t2;
    int top = -1;
    for (int i = 0; i < ptfix.length(); i++)
    {
        if (!ifOperator(ptfix[i]))
        {
            t = createNode(ptfix[i]);
            stack[++top] = t;
        }
        else
        {
            if(ptfix[i]=='&' || ptfix[i]=='|' || ptfix[i]=='!'){
                i++;
            }
            t = createNode(ptfix[i]);
            t1 = stack[top--];
            t2 = stack[top--];
            t->left = t2;
            t->right = t1;
            stack[++top] = t;
        }
    }
    return stack[top--];
}

void preorder(tree *node)
{
    if (node == nullptr)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    string ptfix ;
    cin>>ptfix;
    tree *root = expressiontree(ptfix);
    cout << "Preorder traversal of expression tree: " << endl;
    preorder(root);
    return 0;
}