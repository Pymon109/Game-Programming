#include <stdio.h>
#include <vector>
#include <iostream>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

void VectorMain();
void PrintVector(vector<int> v);

void DequeMain();
void PrintDeque(deque<int> dq);

void ListMain();
void PrintList(list<int> l);

void StackMain();
void QueueMain();
void PriorityQueueMain();

void SetMain();
void PrintSet(set<string> container);

void MapMain();
void PrintHashMap(map<int, string> container);

void HashMapMain();
void PrintMap(unordered_map<int, string> container);

void main()
{
	VectorMain();
	DequeMain();
	ListMain();
	StackMain();
	QueueMain();
	PriorityQueueMain();
	SetMain();
	MapMain();
	HashMapMain();
}

void VectorMain()
{
	vector<int> v;
	v.push_back(10);

	cout << "====================================Vector" << endl;
	cout << "vector size : " << v.size() << endl;
	cout << "vector capacity : " << v.capacity() << endl;
	cout << "vector element(0) : " << v[0] << endl;

	//vector insertion
	vector<int>::iterator it = v.begin();
	it = v.insert(it, 2);
	PrintVector(v);

	it = v.insert(it, 2, 3);
	PrintVector(v);

	it = v.insert(it + 2, 2, 4);
	PrintVector(v);

	//vector deletion
	v.pop_back();
	PrintVector(v);

	v.erase(v.begin() + 3);
	PrintVector(v);

	v.erase(v.begin(), v.begin() + 2);
	PrintVector(v);

	v.clear();
	PrintVector(v);

	cout << endl;
}
void PrintVector(vector<int> v)
{
	cout << "vector data : ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void DequeMain()
{
	//Deque�� Ư¡ : ���ʿ��� �߰�/������ ������ �ڷᱸ��

	/*
	deque<int> container(1);//�����̳ʻ����� ũ�⸦ ���������ϴ�.
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.resize(3); //�迭�� ũ�⸦ �����Ѵ�.
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	//1.�߰� 2.���� 3.���� 4.��λ���
	container.push_back(99); //�߰�
	container.push_front(100); //�տ��� �߰������ϴ�.
	container[1] = 20;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	deque<int>::iterator it = container.begin();//�ݺ���: ���ҿ� �����ϴ°�.
	cout << "begin+2:" << *(it + 2) << endl;//�����Ϳ����� �̿��Ͽ� �������ٰ����ϴ�.
	//���ͷ����� �տ� �߰��ȴ�.(begin-> ù��°���Ұ���)
	container.insert(it, 39); //������ ��带 �𸣴� ���� �����Ѵ�.
	it = container.end();//end-> ����������
	container.insert(it, 49); //������ ��带 �𸣴� ���� �����Ѵ�.
	//��������
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = container.begin();
	container.pop_back(); //�ǵڿ��� ����
	container.pop_front(); //�Ǿп��� ����
	it = container.begin();
	container.erase(it); //����
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	container.clear(); //��λ���
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	*/

	deque<int> dq;

	dq.push_back(10);

	cout << "====================================Deque" << endl;
	cout << "deque size : " << dq.size() << endl;
	cout << "deque element(0) : " << dq[0] << endl;

	//deque insertion
	deque<int>::iterator it = dq.begin();
	it = dq.insert(it, 2);
	PrintDeque(dq);

	it = dq.insert(it, 2, 3);
	PrintDeque(dq);

	it = dq.insert(it + 2, 2, 4);
	PrintDeque(dq);

	dq.push_front(10);
	PrintDeque(dq);

	dq.push_back(30);
	PrintDeque(dq);

	//deque deletion
	dq.pop_back();
	PrintDeque(dq);

	dq.pop_front();
	PrintDeque(dq);

	dq.erase(dq.begin() + 3);
	PrintDeque(dq);

	dq.erase(dq.begin(), dq.begin() + 2);
	PrintDeque(dq);

	dq.clear();
	PrintDeque(dq);

	cout << endl;
}
void PrintDeque(deque<int> dq)
{
	cout << "dequeu data : ";
	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
	cout << endl;
}

void ListMain()
{
	list<int> l(1);
	list<int>::iterator it = l.begin();
	*it = 10;
	//l.push_back(10);

	cout << "====================================List" << endl;
	cout << "list size : " << l.size() << endl;
	cout << "list element(0) : " << *it << endl;


	//deque insertion

	it = l.insert(it, 2);
	PrintList(l);

	it = l.insert(it, 2, 3);
	PrintList(l);

	//it = l.insert(it , 2, 4);
	//PrintList(l);

	l.push_front(10);
	PrintList(l);

	l.push_back(30);
	PrintList(l);

	//deque deletion
	l.pop_back();
	PrintList(l);

	l.pop_front();
	PrintList(l);

	l.erase(it);
	PrintList(l);

	//l.erase(l.begin() + 3);
	//PrintList(l);

	//l.erase(l.begin(), l.begin() + 2);
	//PrintList(l);

	l.clear();
	PrintList(l);

	cout << endl;
}
void PrintList(list<int> l)
{
	list<int>::iterator it = l.begin();
	cout << "list data : ";
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void StackMain()
{
	stack<int> s;
	cout << "====================================Stack" << endl;

	s.push(10);
	s.push(50);
	s.push(20);
	s.push(30);
	s.push(60);

	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;
}
void QueueMain()
{
	queue<int> q;
	cout << "====================================Queue" << endl;

	q.push(10);
	q.push(50);
	q.push(20);
	q.push(30);
	q.push(60);

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	cout << endl;
}
void PriorityQueueMain()
{
	//�켱���� ť�� ��Ʈ��
	priority_queue<int> pq;
	cout << "====================================PriorityQueue" << endl;

	pq.push(10);
	pq.push(50);
	pq.push(20);
	pq.push(30);
	pq.push(60);

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << endl;
	//�����غ��� ���� ū������ ��� (�ִ� ��Ʈ��)
}

void SetMain()
{
	//set�� ���������Ʈ��
	set<string> container;
	cout << "====================================Set" << endl;

	container.insert("�ʹ�");
	container.insert("���ޱⶱ");
	container.insert("�ٳ���");
	container.insert("���");
	container.insert("���鷻");
	container.insert("����Ƣ��");
	container.insert("������ũ");
	container.insert("����");

	PrintSet(container);

	cout << endl;
}
void PrintSet(set<string> container)
{
	cout << "set data : ";
	for (set<string>::iterator it = container.begin(); it != container.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void MapMain()
{
	map<int, string> container;
	cout << "====================================Map" << endl;

	container[0] = "Zero";
	container[1] = "One";
	container[2] = "Two";
	container[10] = "Ten";
	container[5] = "Five";

	PrintHashMap(container);

	cout << endl;
}
void PrintHashMap(map<int, string> container)
{
	cout << "map data : ";
	for (map<int, string>::iterator it = container.begin(); it != container.end(); it++)
		cout << it->first << "/" << it->second << " ";
	cout << endl;
}

void HashMapMain()
{
	unordered_map<int, string> container;
	cout << "====================================HashMap" << endl;

	container[0] = "Zero";
	container[1] = "One";
	container[2] = "Two";
	container[10] = "Ten";
	container[5] = "Five";

	PrintMap(container);

	cout << endl;
}

void PrintMap(unordered_map<int, string> container)
{
	cout << "hashMap data : ";
	for (int i = 0; i < container.size(); i++)
		cout << i << "/" << container[i] << " ";
	cout << endl;
}