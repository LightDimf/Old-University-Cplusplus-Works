#include <iostream>
#include<string>

#define byAge  Compare::compareByAge
#define byCourse  Compare::compareByCourse
#define byName  Compare::compareByName

struct student
{
	std::string name;
	int age, course;
	student()
	{
	}
	student(std::string name, int age, int course)
	{
		this->name = name;
		this->age = age;
		this->course = course;
	}
};

class BinaryTree
{
private:
	class Node
	{
	public:
		student data;
		Node *left;
		Node * right;
		Node(student data, Node* left = nullptr, Node *right = nullptr)
		{
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};
	Node *head;
	void postorder(Node* p)
	{
		if (p != NULL)
		{
			postorder(p->left);
			std::cout << "Name: " << p->data.name << " Age: " << p->data.age << " Course: " << p->data.course << "\n ";
			postorder(p->right);
		}
		else
			return;
	}
	void addElement(Node* HEAD, student st, int(*compare)(student, student))
	{
		if (HEAD != nullptr)
		{
			if (compare(HEAD->data, st) <= 0)
			{
				if (HEAD->left == nullptr)
				{
					HEAD->left = new Node(st);
				}
				else
					addElement(HEAD->left, st, compare);

			}
			else if (compare(HEAD->data, st) == 1)
			{
				if (HEAD->right == nullptr)
				{
					HEAD->right = new Node(st);
				}
				else
					addElement(HEAD->right, st, compare);
			}
		}
	}
	Node* findElement(Node* HEAD, student st, int(*compare)(student, student))
	{
		if (HEAD != nullptr)
		{
			if (HEAD->data.name == st.name)
			{
				return HEAD;
			}
			else if (compare(HEAD->data, st) <= 0)
			{
				findElement(HEAD->left, st, compare);
			}
			else if (compare(HEAD->data, st) == -1)
			{
				findElement(HEAD->right, st, compare);
			}
		}
		return nullptr;
	}
	
public:
	BinaryTree()
	{
		head = nullptr;
	}
	BinaryTree(student data)
	{
		head = new Node(data);
	}
	void add(student st, int(*compare)(student, student)) {
		addElement(head, st, compare);
	}
	void print_postorder()
	{
		postorder(head);
	}
	Node* find(student st, int (*compare)(student, student))
	{

		if (Node*result = findElement(head, st, compare))
		{
			return result;
		}
		else
			return NULL;
	};
	
};

 class Compare
{
public:
	static int compareByAge(student s1, student s2)
	{
		if (s1.age == s2.age)
			return 0;
		else if (s1.age > s2.age)
			return 1;
		else
			return -1;
	}
	static int compareByName(student s1, student s2)
	{
		if (s1.name == s2.name)
			return 0;
		else if (s1.name > s2.name)
			return 1;
		else
			return -1;
	}
	static int compareByCourse(student s1, student s2)
	{
		if (s1.course == s2.course)
			return 0;
		else if (s1.course > s2.course)
			return 1;
		else
			return -1;
	}
};


