#pragma once
#ifndef HASH_TAB //���� ������������� ��� ������� HASH_TAB, �� ��������� ������, � ��������� ������ ������ ��� ������ �� �����,
//��� �����, ����� ��� ��������� ����������� ����� ������������� �����, �� ������ ��� �� ������� ����� ����� ������ ��-�� ��������������� ������
#define  HASH_TAB
#include<iostream>
using namespace std;

template < class K, class V>
struct Node
{
	K key; // ����
	V data; // ������
	Node< K, V > *nextPtr; // ��������� ���� � ������
	Node< K, V > *prevPtr; // ���������� ���� � ������
};
template < class K, class V>
class HashTab
{
public:
	HashTab();
	bool find_Elem_key(K k, Node<K, V> *&current); // ������� �� ��������� ����� ���������� ������� ������� �� ��������� �� �����
	void Search(K k, V &v);//�����
	bool AddElem(V Y);//���������� ��������
	bool DelElem(K k);//������� �������
	K hash_func();//������ ������ ���� �� ��� ���, ���� �� ������ ����������
	bool test_key(K kfind); // ���������, ���� �� � ���� ������ ����� ����
	void print();//������
	int count();//���������� ���������
private:
	K key; // ����
	V data; // ������
	Node< K, V > *head; // ������ ������� ������
	Node< K, V > *end; // ��������� ������� ������
	int size;
};
#endif //��������� #ifndef