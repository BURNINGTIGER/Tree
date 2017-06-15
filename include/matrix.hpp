#include <iostream> 
#include <string> 
#include <fstream> 
#include <cstdint> 

using namespace std;

template <typename T>
struct Node
{
	Node *left;
	Node *right;
	T data;
};

template <typename T>
class BinaryTree;

template <typename T>
std::ostream& operator<<(std::ostream&, const BinaryTree<T>&);

template <typename T>
class BinaryTree
{
private:
	Node<T>*root;
	int count = 0;
public:
	BinaryTree();
	~BinaryTree();
	Node<T>* root_();
	unsigned int getCount()const;
	Node<T> *findNode(const T&, Node<T>*)const;
	void insertNode(const T&x);
	void deleteNode(Node<T>* temp);
	bool removeElement(Node<T>* parent, Node<T>* current, const T& val);
	bool deleteValue(const T& value);
	void write(const std::string& filename)const;
	friend std::ostream& operator<<<>(std::ostream&, const BinaryTree<T>&);
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template<typename T>
Node<T>* BinaryTree<T>::root_()
{
	return root;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	deleteNode(root);
}

template <typename T>
unsigned int BinaryTree<T>::getCount()const
{
	return count;
}

template<typename T>
Node<T>* BinaryTree<T>::findNode(const T& data, Node<T>* temp) const
{
	if (temp == 0 || data == temp->data)
		return temp;
	if (data > temp->data)
		return findNode(data, temp->right);
	else
		return findNode(data, temp->left);
}

template<typename T>
void BinaryTree<T>::insertNode(const T&x)
{
	if (findNode(x, root_())) return;
	Node<T>* Tree = new Node<T>;
	Tree->data = x;
	Tree->left = Tree->right = 0;
	Node<T>* buff = root;
	Node<T>* temp = root;
	while (temp)
	{
		buff = temp;
		if (x < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (!buff)
		root = Tree;
	else
	{
		if (x < buff->data)
			buff->left = Tree;
		else
			buff->right = Tree;
	}
	++count;
}



template<typename T>
void BinaryTree<T>::write(const std::string& filename)const
{
	ofstream file_1(filename);
	file_1 << count << "\t";
	output(file_1, root);
	file_1.close();
}

template<typename T>
void BinaryTree<T>::deleteNode(Node<T>* temp)
{
	if (!temp)
		return;
	if (temp->left)
	{
		deleteNode(temp->left);
		temp->left = nullptr;
	}

	if (temp->right)
	{
		deleteNode(temp->right);
		temp->right = nullptr;
	}
	delete temp;
}

template <typename T>
std::ostream& output(std::ostream& out, const Node<T>* node, unsigned int level)
{
	if (!node)
		return out;
	output(out, node->right, level + 1);
	for (unsigned int i = 0; i < level; i++)
		out << "\t";
	out << node->data << std::endl;
	output(out, node->left, level + 1);
	return out;
}

template<typename T>
bool BinaryTree<T>::removeElement(Node<T>* parent, Node<T>* current, const T& val)
{
	if (!current) return false;
	if (current->data == val)
	{
		if (current->left == NULL || current->right == NULL) {
			Node<T>* temp = current->left;
			if (current->right) temp = current->right;
			if (parent) {
				if (parent->left == current) {
					parent->left = temp;
				}
				else {
					parent->right = temp;
				}
			}
			else {
				this->root = temp;
			}
			delete current;
		}
		/*else {
			Node<T>* validSubs = current->right;
			while (validSubs->left) {
				validSubs = validSubs->left;
			}
			T temp = current->data;
			current->data = validSubs->data;
			validSubs->data = temp;
			return removeElement(current, current->right, temp);
		}*/
		else {
			Node<T>* validSubs = current->left;
			while (validSubs->right) {
				validSubs = validSubs->right;
			}
			validSubs->right = current->right->left;
			current->right->left = nullptr;
			current->right->left = current->left;
			if (parent == current)
				parent = current->right;
			if (parent->left == current)
				parent->left = current->right;
			if (parent->right == current)
				parent->right = current->right;
		}
		//delete current;
		count--;
		return true;
	}
	if (current->data > val)
		return removeElement(current, current->left, val);
	else
		return removeElement(current, current->right, val);
}

template<typename T>
bool BinaryTree<T>::deleteValue(const T& value)
{
	return this->removeElement(NULL, root, value);
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const BinaryTree<T>& temp)
{
	output(out, temp.root, 0);
	return out;
}
