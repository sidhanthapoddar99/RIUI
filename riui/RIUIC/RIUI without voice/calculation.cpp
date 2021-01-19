#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string conversion(char a[150]);
int siz;
int narr[52];
char carr[52];
int toInt(char c)
{
    //int flag=0;
    for(int i=0;i<siz;i++)
    {
      if(carr[i]==c)
            return narr[i];
    }
    cout<<"enter the value of "<<c<<" : ";
    char a[150];
    gets(a);
    sscanf(a,"%d", &narr[siz]);
    carr[siz]=c;
    siz++;
    return narr[siz-1];
}
struct node
{
    char value;
    node* left, *right;
};

bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}
void inorder(node *t)
{
    if(t)
    {
        inorder(t->left);
        printf("%c ", t->value);
        inorder(t->right);
    }
}
void preorder(node *t)
{
    if(t)
    {
        printf("%c ", t->value);
        preorder(t->left);
        preorder(t->right);
    }
}

void postorder(node *t)
{
    if(t)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%c ", t->value);
    }
}


node* newNode(int v)
{
    node *temp = new node;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

node* constructTree(char postfix[])
{
    stack<node *> st;
    node *t, *t1, *t2;

    for (int i=0; i<strlen(postfix); i++)
    {
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else
        {
            t = newNode(postfix[i]);
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
            t->right = t1;
            t->left = t2;
            st.push(t);
        }
    }


    t = st.top();
    st.pop();

    return t;
}
// This function receives a node of the syntax tree
// and recursively evaluates it
int eval(node* root)
{
    // empty tree
    if (!root)
        return 0;

    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return toInt(root->value);

    // Evaluate left subtree
    int l_val = eval(root->left);

    // Evaluate right subtree
    int r_val = eval(root->right);

    // Check which operator to apply
    if (root->value=='+')
        return l_val+r_val;

    if (root->value=='-')
        return l_val-r_val;

    if (root->value=='*')
        return l_val*r_val;

    //if (root->value=='/')
      //  return l_val/r_val;

    return l_val/r_val;
}
void exptree(char postfix[150])
{
    if(strlen(postfix)==0)
        gets(postfix);
    //cout<<"enter equation in postfix form to construct tree\n";
    siz=0;
    //gets(postfix);
    string sp=conversion(postfix);
    strcpy(postfix,sp.c_str());
    node* r = constructTree(postfix);
    /*printf("postorder expression is \n");
    postorder(r);
    cout<<"/ninorder expression"<<endl;
    inorder(r);
    cout<<"/npreorder expression"<<endl;
    preorder(r);*/

    cout<<"\n\nriui> the result is:   "<<eval(r)<<"\n\n";
    //return 0;
}
