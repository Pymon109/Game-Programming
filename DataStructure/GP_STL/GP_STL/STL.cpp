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
	//Deque의 특징 : 양쪽에서 추가/삭제가 가능한 자료구조

	/*
	deque<int> container(1);//컨테이너생성시 크기를 지정가능하다.
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.resize(3); //배열의 크기를 지정한다.
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	//1.추가 2.삽입 3.삭제 4.모두삭제
	container.push_back(99); //추가
	container.push_front(100); //앞에도 추가가능하다.
	container[1] = 20;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	deque<int>::iterator it = container.begin();//반복자: 원소에 접근하는것.
	cout << "begin+2:" << *(it + 2) << endl;//포인터연산을 이용하여 랜덤접근가능하다.
	//이터레이터 앞에 추가된다.(begin-> 첫번째원소가됨)
	container.insert(it, 39); //삽입할 노드를 모르는 경우는 배제한다.
	it = container.end();//end-> 마지막원소
	container.insert(it, 49); //삽입할 노드를 모르는 경우는 배제한다.
	//순차접근
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	it = container.begin();
	container.pop_back(); //맨뒤원소 삭제
	container.pop_front(); //맨압원소 삭제
	it = container.begin();
	container.erase(it); //삭제
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	container.clear(); //모두삭제
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
	//우선순위 큐는 힙트리
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
	//실행해보면 가장 큰수부터 출력 (최대 힙트리)
}

void SetMain()
{
	//set은 레드블랙이진트리
	set<string> container;
	cout << "====================================Set" << endl;

	container.insert("초밥");
	container.insert("오메기떡");
	container.insert("바나나");
	container.insert("라멘");
	container.insert("마들렌");
	container.insert("감자튀김");
	container.insert("스테이크");
	container.insert("팝콘");

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