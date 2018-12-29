#pragma once
#ifndef HASH_TAB //если неопеределено это понятие HASH_TAB, то выполнять дальше, в противном случае дальше код читать не будет,
//это нужно, чтобы при повторном подключении этого заголовочного файла, он второй раз не читался иначе будут ошибки из-за переопределения класса
#define  HASH_TAB
#include<iostream>
using namespace std;

template < class K, class V>
struct Node
{
	K key; // ключ
	V data; // данные
	Node< K, V > *nextPtr; // следующий узел в списке
	Node< K, V > *prevPtr; // предыдущий узел в списке
};
template < class K, class V>
class HashTab
{
public:
	HashTab();
	bool find_Elem_key(K k, Node<K, V> *&current); // функция по заданному ключу перемещает текущий элемент на найденный по ключу
	void Search(K k, V &v);//поиск
	bool AddElem(V Y);//добавление элемента
	bool DelElem(K k);//удалить элемент
	K hash_func();//просит ввести ключ до тех пор, пока не введут уникальный
	bool test_key(K kfind); // проверяет, есть ли в этом списке такой ключ
	void print();//печать
	int count();//количество элементов
private:
	K key; // ключ
	V data; // данные
	Node< K, V > *head; // первый элемент списка
	Node< K, V > *end; // последний элемент списка
	int size;
};
#endif //закрываем #ifndef