#include <iostream>
#include <cassert>

template <class T>

class BinaryTree
{
private:
    struct Tnode
    {
        friend class BinaryTree;
        T value;
        Tnode *left;
        Tnode *right;
        int  counter;
        Tnode();
        Tnode(const T nodeValue ) : value(nodeValue)
        {

        }

        ~Tnode()
        {

        }
        void print (const int level = 0) const
        {
            const Tnode *current = this;
            if(current)
            {
                current->right->print(level + 1);
            }
            for (int n=0; n<level;++n)
                std::cout << "   ";

            if(current)
            {
                std::cout << current->value <<'(' << current->counter << ')'<< std::endl;
            }
            else
                std:: cout << "|" << std:: endl;
            if(current) {
                current->left->print(level + 1);
            }

        }



    };

private:
    Tnode *root;
    Tnode *emptyNode;


    BinaryTree(const BinaryTree &);

    BinaryTree & operator=( const BinaryTree& );
    void newRoot(const T rootValue )
    {
        root = new Tnode(rootValue);
        root->left  = 0;
        root->right = 0;
        root->counter = 1;
    }
    Tnode * & searchNode(T valueForSearch )
    {
        Tnode *current = root;
        while ((current != 0) && (current->value != valueForSearch)) {
            {
                if (valueForSearch < current->value) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }
        }

        if (!current)
        {
            return emptyNode;
        }
        else
        {
            return current;
        }

    }
    Tnode* insertNode(const T valueForInset, Tnode * current = 0)
    {
        if(!root)
        {
            newRoot(valueForInset);
            return root;
        }

        if(!current)
        {
            current = root;
        }

        if(current)
        {
            if (valueForInset < current->value)
            {
                if (current->left)
                {
                    insertNode(valueForInset, current->left);
                }
                else
                {
                    attachNode(current, current->left, valueForInset);
                    return current->left;
                }

            }else if(valueForInset == current->value)
            {
                return current->left;
            }
            else if(valueForInset > current->value)
            {
                if (current->right)
                {
                    insertNode(valueForInset, current->right);
                }
                else
                {
                    attachNode(current, current->right, valueForInset);

                    return current->right;
                }

            }else if(valueForInset == current->value)
            {
                return current->left;
            }
        }
        else
        if(current->value == valueForInset)
        {
            addCount(current, 1);
        }
        assert(current);

        return 0;

    }

    Tnode* minValueNode(Tnode* node)
    {
        Tnode* current = node;

        /* loop down to find the leftmost leaf */
        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    Tnode* deleteNode(const T key, Tnode * root)
    {
        if(root == nullptr)
        return root;
        if(key < root ->value)
            root->left = deleteNode( key, root->left);
        else
        if(key > root ->value)
            root->right = deleteNode( key, root->right);
        else{
            if(root->left == nullptr && root->right == nullptr)
                return nullptr;
            else if(root->left == nullptr){
                Tnode *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                Tnode *temp = root->left;
                delete root;
                return temp;
            }
            Tnode* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode( temp->value, root->right);
        }
        return root;
    }
    void attachNode(Tnode * newParent, Tnode * & newNode, T valueForInsert )
    {
        newNode = new Tnode(valueForInsert );
        newNode->left  = 0;
        newNode->right = 0;
        newNode->counter = 1;

    }

    void addCount(Tnode * current, int increment )
    {
        current->counter += increment;
    }
    void cleanup (Tnode *tempNode)

    {
        if(!tempNode)
            return;

        if(tempNode->left)

        {
            cleanup(tempNode->left);
            tempNode->left = 0;
        }

        if(tempNode->right != 0 )

        {
            cleanup(tempNode->right);
            tempNode->right = 0;
        }
        delete tempNode;

    }

    void printPre(const Tnode * tempNode) const

    {
        if(!tempNode) return;
        std::cout << tempNode->value << "  ";
        if(tempNode->left) {
            printPre(tempNode->left);
        }
        if(tempNode->right) {
            printPre(tempNode->right);
        }
    }

    void printIn(const Tnode * tempNode)  const

    {
        if(!tempNode) {
            return;
        }

        if(tempNode->left) {
            printIn(tempNode->left);
        }
        std::cout << tempNode->value << "  ";

        if(tempNode->right) {
            printIn(tempNode->right);
        }
    }


    void printPost(const Tnode * tempNode) const

    {
        if(!tempNode) {
            return;
        }
        if(tempNode->left) {
            printPost(tempNode->left);
        }
        if(tempNode->right) {
            printPost(tempNode->right);
        }
        std::cout << tempNode->value << "  ";

    }

    void search (T key, Tnode * tempNode) const
    {

        int depth = 0;
        Tnode *temp;
        temp = tempNode;
        while(temp != nullptr)
        {
            depth++;
            if(temp->value == key)
            {
                std:: cout<<"Suitable item : " << temp->value<< " on place : "<< depth <<std::endl;
                return;
            }
            else if(temp->value > key)
                temp = temp->left;
            else
                temp = temp->right;
        }
        std::cout<<"No suitable item" << std::endl;
        return;

    }

public:
    BinaryTree() : emptyNode(0) {root = 0;}
    BinaryTree(const T rootValue) : emptyNode(0)
    {
        newRoot(rootValue);
    }
    ~BinaryTree()
    {
        cleanup(root);
    }
    bool add(const T insert_value)
    {
        Tnode *ret = insertNode(insert_value);
        if(ret) {
            return true;
        }
        else
            return false;

    }

    /* bool find(T find_value)
     { Tnode *tn = searchNode(find_value);

         if(tn) return true;

         else   return false;

     }*/


    void Print() const

    {

        root->print( );
    }

    void printPreOrder( ) const

    {
        printPre(root);
        std::cout << std::endl;
    }

    void printInOrder( ) const

    {
        printIn(root);
        std::cout << std::endl;
    }

    void printPostOrder( ) const

    {
        printPost(root);
        std::cout << std::endl;
    }
    void removeItem(const T key)
    {
        Tnode* node = deleteNode(key, root);
    }
    void searchInTree(T key) const
    {
        search(key, root);
        std::cout << std::endl;
    }

};


BinaryTree<int> binaryTreeInt(14);
BinaryTree<float> binaryTreeFloat(7.0);

int main()
{
    binaryTreeInt.add(10 );
    binaryTreeInt.add(6 );
    binaryTreeInt.add(15 );
    binaryTreeInt.add(9 );
    binaryTreeInt.add(30 );
    binaryTreeInt.add(4 );
    binaryTreeInt.add(11 );
    binaryTreeInt.add(2 );
    binaryTreeInt.add(10 );

    binaryTreeInt.Print ();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    binaryTreeInt.removeItem(14);
    binaryTreeInt.Print ();

    binaryTreeInt.searchInTree(9);



    std::cout << "---------------------------------------------------------" << std::endl;

    binaryTreeFloat.add(6.5);
    binaryTreeFloat.add(3.5);
    binaryTreeFloat.add(7.5);
    binaryTreeFloat.add(14.3);
    binaryTreeFloat.add(12.9);
    binaryTreeFloat.add(10.8);

    binaryTreeFloat.Print();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    binaryTreeFloat.searchInTree(12.9);
    binaryTreeFloat.removeItem(7);
    binaryTreeFloat.Print();



    return 0;

}






















//