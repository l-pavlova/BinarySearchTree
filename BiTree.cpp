#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int value)
	{
		data = value;
		left = right = NULL;
	}
};
class BinarySearchTree {
private:
	Node* root;

	Node* insert(Node* currNode, int value)
	{
		if (currNode == NULL)
		{
			return new Node(value);
		}
		if (currNode->data < value)
		{
			currNode->right=insert(currNode->right, value);
		}
		else
		{
			currNode->left = insert(currNode->left, value);
		}
		return currNode;

	}
	Node* find(Node* currNode, int value) 
	{
		if (currNode == NULL)
		{
			return NULL;
		}
		if (currNode->data > value)
		{
			return find(currNode->left, value);
		}
		else if (currNode->data < value)
		{
			return find(currNode->right, value);
		}
		else return currNode;
	}
	Node* remove(Node* currNode, int value)
	{
		if (currNode == NULL)
		{
			return NULL;
		}
		if (currNode->data < value)
		{
			currNode->right = remove(currNode->right, value);
		}
		else if (currNode->data > value)
		{
			currNode->left = remove(currNode->left, value);
		}
		else
		{
			if (currNode->left == NULL)
			{
				Node* temp = currNode->right;
				delete currNode;
				return temp;
			}
			Node* maxInLeftSubTree = findMax(currNode->left);
			currNode->data = maxInLeftSubTree->data;
			currNode->left = remove(currNode->left, currNode->data);
		}
		return currNode;
	}
	Node* findMin(Node* root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->left == NULL)
		{
			return root;
		}
		return findMin(root->left);
	}
	Node* findMax(Node* root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->right == NULL)
		{
			return root;
		}
		return findMax(root->right);
	}
	void printOrdered(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		printOrdered(root->left);
		cout << root->data<<" ";
		printOrdered(root->right);
	}
	void printRightLeftRoot(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		printRightLeftRoot(root->right);
		printRightLeftRoot(root->left);
		cout << root->data << " ";
	}
	void printLeafNodes(Node* root)
	{
		if (!root)
			return;
		if (!root->left && !root->right)
		{
			cout << root->data <<" ";
			return;
		}
		if (root -> left)
		{
			printLeafNodes(root->left);
		}
		if (root->right)
		{
			printLeafNodes(root->right);
		}
	}
	int findHeight(Node* root)
	{
		if (root == NULL)
		{
			return -1;
		}
		return max(findHeight(root->left), findHeight(root->right)) + 1;
	}
	Node* lowestCommonAncestor(Node* root, int v1, int v2)
	{
		if (v1 > v2)
		{
			swap(v1, v2);
		}
		if (root->data < v1)
		{
			return lowestCommonAncestor(root->right, v1, v2);
		}
		if (root->data > v2)
		{
			return lowestCommonAncestor(root->left, v1, v2);
		}
		return root;
	}
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	void insert(int value)
	{
		if (root == NULL)
		{
			root = new Node(value);
		}
		else
		{
			insert(root, value);
		}
	}
	void remove(int value)
	{
		root = remove(root, value);
	}
	bool exist(int value)
	{
		return find(root, value) != NULL;
	}
	int findMin()
	{
		if (root == NULL)
		{
			return - 1;
		}
		return findMin(root)->data;
	}
	int findMax()
	{
		if (root == NULL)
		{
			return -1;
		}
		return findMax(root)->data;
	}
	void printSorted()
	{
		printOrdered(root);
	}
	void printRightLeft()
	{
		printRightLeftRoot(root);
	}
	int Height()
	{
		return findHeight(root);
	}
	//FindSumOfOddNumbers
	private:
		int sum = 0;
	public:
		void leaves_odd(Node* root)
		{
			if (!root->left && !root->right)
			{
				if (root->data & 1)
				{
					sum += root->data;
				}
				return;
			}
			if (root->left)
			{
				leaves_odd(root->left);
			}
			if (root->right)
			{
				leaves_odd(root->right);
			}
		}
		void leaves(Node* root) {
			leaves_odd((root));
			cout << sum;
		}
		//count of left vertices and right vertices
		int lefts = 0;
		int rights = 0;
		void lefted(Node* root)
		{
			if (root != nullptr)
			{
				if (root->left)
				{
					lefts++;
					lefted(root->left);
				}
				if (root->right)
				{
					rights++;
					lefted(root->right);
				}
			}
			return;
		}
		void leftRight(Node* root) {

			lefted(root);
			cout << "[" << lefts << "," << rights << "]";
		}

};
int main()
{
	BinarySearchTree myTreeTree;
	myTreeTree.insert(5);
	myTreeTree.insert(3);
	myTreeTree.insert(4);
	myTreeTree.insert(8);
	myTreeTree.insert(42);
	myTreeTree.insert(17);
	myTreeTree.insert(16);
	myTreeTree.printSorted();
	cout<<endl<<myTreeTree.findMin();
	cout << endl;
	cout << myTreeTree.exist(13) << endl;
	myTreeTree.printRightLeft();
	cout<<endl<<myTreeTree.Height();
	cin.get();
	return 0;
}

Node* remove(Node* current, int value)
{
	if (current == NULL)
		return NULL;
	if (current->data > value)
	{
		current->left = remove(current -> left, value);
	}
	else if (current->data < value)
	{
		current->right = remove(current->right, value);
	}
	else
	{
		if (current->left == NULL)
		{
			Node*
		}
	}
}