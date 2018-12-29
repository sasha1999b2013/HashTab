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
bool HashTab<K, V>::find_Elem_key(K k, Node<K, V> *&current) // функция по заданному ключу перемещает текущий элемент на найденный по ключу
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
void HashTab<K, V>::Search(K k, V &v)//поиск
{
	Node< K, V > *current = head;
	if (size != 0)
	{
		if (find_Elem_key(k, current))
		{
			cout << "элемент : " << current->data << "\n" << endl;
			v = current->data;
		}
		else cout << "Такого элемента нет\n" << endl;
	}
	else
	{
		cout << "Таблица пуста\n" << endl;
	}
}
template < class K, class V>
bool HashTab<K, V>::AddElem(V Y)//добавление элемента
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
bool HashTab<K, V>::DelElem(K k)//удалить элемент
{
	Node< K, V > *current = new Node< K, V >;
	if (count() == 0)
	{
		cout << "Таблица пуста\n" << endl;
		return 0;
	}
	if (!find_Elem_key(k, current))
	{
		cout << "Элемента с таким ключом нету\n" << endl;
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
	cout << "элемент удален\n" << endl;
	return 1;

}
template < class K, class V>
K HashTab<K, V>::hash_func()//просит ввести ключ до тех пор, пока не введут уникальный
{
	do
	{
		cout << "Введите уникальный ключ\n";
		cin >> key;
	} while (test_key(key));
	return key;
}
template < class K, class V>
bool HashTab<K, V>::test_key(K kfind) // проверяет, есть ли в этом списке такой ключ
{
	Node< K, V > *current = new Node< K, V >;
	current = head;
	while (current != NULL) // получить данные элемента
	{
		if (current->key == kfind) return 1;
		current = current->nextPtr;
	}
	return 0;
}
template < class K, class V>
void HashTab<K, V>::print()//печать
{
	Node<K, V> *current = new Node<K, V>;
	if (!head) // список пуст
	{
		cout << "Таблица пуста\n" << endl;
		return;
	} // конец if
	current = head;
	cout << "Список элементов: " << endl;
	while (current != NULL) // получить данные элемента
	{
		cout << "Ключ " << current->key << ' ';
		cout << "Значение " << current->data << '\n';
		current = current->nextPtr;
	} // конец while

	cout << endl;
} // конец функции print
template < class K, class V>
int HashTab<K, V>::count()//количество элементов
{
	return size;
}