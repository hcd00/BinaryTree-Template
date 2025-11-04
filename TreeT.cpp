template <class T>
TreeT<T>::TreeT()
{
    root = nullptr;
    numNodes = 0;
}

template <class T>
TreeT<T>::~TreeT()
{
}

template <class T>
TreeT<T>& TreeT<T>::operator=(const TreeT& otherTree)
{
    //Check to make sure we are not setting treeA = treeA
    if (this != &otherTree)
    {
        //Get rid of old tree before copying over otherTree
        DestroyTree(root);
        numNodes = otherTree.numNodes;
        CopyHelper(root, otherTree.root);
    }
}

template <class T>
void TreeT<T>::CopyHelper(Node*& thisTree, Node* otherTree)
{
    //base case: tree is empty
    if (otherTree == nullptr)
    {
        thisTree = nullptr;
        return;
    }
    //Create new node to place data
    thisTree = new Node;
    //deep copy of values
    thisTree->value = otherTree->value;
    //Traverse T:
    //Copy left subtree
    CopyHelper(thisTree->left, otherTree->left);
    //Copy right subtree
    CopyHelper(thisTree->right, otherTree->right);

}

//Add node to tree
template <class T>
void TreeT<T>::Add(T value)
{
    //Create new node
    Node *newNode = new Node;
    //Inst. node w/ data
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    //Edge Case: Empty root, instantiate it
    if (root == nullptr)
    {
        root = newNode;
        numNodes++;
        return;
    }

    //Set up curr & prev nodes as start points
    Node *currN = root;
    Node *prevN = nullptr;

    //traverse tree to find where to place new node.
    while (currN != nullptr)
    {
        //Update prev Node
        prevN = currN;

        //Check which direction to go:
        //Trick: arrow points where to go

        //Go into left subtree
        if (value < currN->value)
        {
            //This is how we are changing direction
            currN = currN->left;
        }
        //Go into right subtree
        else if (value > currN->value)
        {
            //Change direction to go right
            currN = currN->right;
        }
        else
        {
            //Need to free up memory if its not used
            delete newNode;
            return;
        }
    }
    //Check if new node should be placed on left or right side of the parent
    //In case this prevN would always be the parent
    if ( value < prevN->value)
    {
        prevN->left = newNode;
    }
    else
    {
        prevN->right = new Node;
        prevN->right->value = value;
    }
    numNodes++;
}

template <class T>
void TreeT<T>::Remove(T value)
{

}

template <class T>
bool TreeT<T>::Contains(T value)
{
    Node *currN = root;

    while (currN != nullptr)
    {
        //go left
        if (value < currN->value)
        {
            currN = currN->left;
        }
        //go right
        else if (value > currN->value)
        {
            currN = currN->right;
        }
        //Found match
        else
        {
            return true;
        }
    }
    //loop finished w/o finding value. Thus not contains.å
    return false;
}

template <class T>
int TreeT<T>::Size()
{
}

template <class T>
void TreeT<T>::ResetIterator(Order traverseOrder)
{
}

template <class T>
T TreeT<T>::GetNextItem()
{
}

template <class T>
void TreeT<T>::DestroyTree(Node* node)
{

}

template <class T>
void TreeT<T>::RemoveHelper(Node*& subtree, T value)
{
}

template <class T>
void TreeT<T>::DeleteNode(Node*& subtree)
{
}

template <class T>
void TreeT<T>::GetPredecessor(Node* curr, T& value)
{
}



template <class T>
void TreeT<T>::PlacePreOrder(Node* node)
{
}

template <class T>
void TreeT<T>::PlacePostOrder(Node* node)
{
}

template <class T>
void TreeT<T>::PlaceInOrder(Node* node)
{
}
