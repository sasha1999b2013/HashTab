#include "pch.h"
#include "Header.h"
#include "Header1.h"
template < class K, class V>
HashTab<K, V>::HashTab()
{
	Node< K, V > *current = new Node< K, V >;
	current = NULL;
	head = NULL;
	end = head;
}
template < class K, class V>
bool HashTab<K, V>::find_Elem_key(K k, Node<K, V> *&current) // ������� �� ��������� ����� ���������� ������� ������� �� ��������� �� �����
{
	current = head;
	while (current != NULL)
	{
		if (current->key == k)
		{
			return 1;
		}
		current = current->nextPtr;
	}
	return 0;
}
template < class K, class V>
void HashTab<K, V>::Search(K k, V &v)//�����
{
	Node< K, V > *current = head;
	if (size != 0)
	{
		if (find_Elem_key(k, current))
		{
			cout << "������� : " << current->data << "\n" << endl;
			v = current->data;
		}
		else cout << "������ �������� ���\n" << endl;
	}
	else
	{
		cout << "������� �����\n" << endl;
	}
}
template < class K, class V>
bool HashTab<K, V>::AddElem(V Y)//���������� ��������
{
	Node<K, V> *temp = new Node<K, V>;
	temp->nextPtr = NULL;
	temp->data = Y;
	if (head == NULL) {
		temp->prevPtr = NULL;
		head = temp;
		head->key = hash_func();
		head->data = Y;
		end = head;
	}
	else {
		temp->prevPtr = end;
		temp->key = hash_func();
		temp->nextPtr = NULL;
		temp->prevPtr = end;
		temp->data = Y;
		end->nextPtr = temp;
		end = temp;
	}
	size++;
	cout << endl;
	return 1;
}
template < class K, class V>
bool HashTab<K, V>::DelElem(K k)//������� �������
{
	Node< K, V > *current = new Node< K, V >;
	if (count() == 0)
	{
		cout << "������� �����\n" << endl;
		return 0;
	}
	if (!find_Elem_key(k, current))
	{
		cout << "�������� � ����� ������ ����\n" << endl;
		return 0;
	}
	if (end == head)
	{
		head = end = 0;
		delete current;
	}
	else if (current == head)
	{
		head = current->nextPtr;
		delete current;
	}
	else if (current == end)
	{
		end = current->prevPtr;
		end->nextPtr = NULL;
		delete current;
	}
	else
	{
		Node<K, V> *temp = current;
		temp->prevPtr->nextPtr = current->nextPtr;
		temp->nextPtr->prevPtr = current->prevPtr;
		delete current;
	}
	size--;
	cout << "������� ������\n" << endl;
	return 1;

}
template < class K, class V>
K HashTab<K, V>::hash_func()//������ ������ ���� �� ��� ���, ���� �� ������ ����������
{
	do
	{
		cout << "������� ���������� ����\n";
		cin >> key;
	} while (test_key(key));
	return key;
}
template < class K, class V>
bool HashTab<K, V>::test_key(K kfind) // ���������, ���� �� � ���� ������ ����� ����
{
	Node< K, V > *current = new Node< K, V >;
	current = head;
	while (current != NULL) // �������� ������ ��������
	{
		if (current->key == kfind) return 1;
		current = current->nextPtr;
	}
	return 0;
}
template < class K, class V>
void HashTab<K, V>::print()//������
{
	Node<K, V> *current = new Node<K, V>;
	if (!head) // ������ ����
	{
		cout << "������� �����\n" << endl;
		return;
	} // ����� if
	current = head;
	cout << "������ ���������: " << endl;
	while (current != NULL) // �������� ������ ��������
	{
		cout << "���� " << current->key << ' ';
		cout << "�������� " << current->data << '\n';
		current = current->nextPtr;
	} // ����� while

	cout << endl;
} // ����� ������� print
template < class K, class V>
int HashTab<K, V>::count()//���������� ���������
{
	return size;
}