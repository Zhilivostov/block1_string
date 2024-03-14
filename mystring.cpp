#pragma warning(disable : 4996) // костыль дл€ strcpy и strncpy
#pragma warning(disable : 6386) // костыль дл€ 33 строки (m_arr[n] = '\0')

#include "mystring.h"
#include <algorithm> //подключает std::min
#include <cstring> //подключает strlen - считает количество символов до детерменированного нул€, strcpy - копирует содержимое второй строки в первую, strncpy
#include <stdexcept>

String::String():
m_len(0), m_capacity(2*m_len+1), m_arr(new char[m_capacity]())
{
	*m_arr = '\0';
}

String::String(const char* str):
m_len(strlen(str)), m_capacity(2*m_len+1), m_arr(new char[m_capacity]())
{
	strcpy(m_arr, str);
}

String::String(const char* str, size_t n):
m_len(std::min(n, strlen(str))), m_capacity(2*m_len+1), m_arr(new char[m_capacity]()) // min на случай если n больше размера str
{
	strncpy(m_arr, str, std::min(n, strlen(str)));
}

String::String(size_t n, char c):
m_len(n), m_capacity(2*n+1), m_arr(new char[m_capacity]())
{
	int i;
	for (i = 0; i < n; i++)
		m_arr[i] = c;
	m_arr[n] = '\0';
}

String::String(const String& str):
m_len(str.m_len), m_capacity(str.m_capacity), m_arr(new char[m_capacity]())
{
	strcpy(m_arr, str.m_arr);
}

String::String(const String& str, size_t pos, size_t len):
m_len(std::min(len, str.m_len) - pos), m_capacity(2*m_len+1), m_arr(new char[m_capacity]())
{
	strncpy(m_arr, str.m_arr + pos, std::min(len, str.m_len));
}

String::~String()
{
	delete[] m_arr;
}

size_t String::size() const
{
	return m_len;
}

size_t String::capacity() const
{
	return m_capacity;
}

void String::reserve(size_t n) //увеличивает длину строки
{
	m_capacity = 2 * n + 1;
	char* new_arr = new char[m_capacity]();
	strcpy(new_arr, m_arr);
	delete[] m_arr;
	m_len = n;
	m_arr = new_arr;
}

void String::clear()
{
	delete[] m_arr;
	m_len = 0;
	m_capacity = 2 * m_len + 1;
	m_arr = new char[m_capacity]();
	*m_arr = '\0';
}

bool String::empty() const
{
	return m_len == 0;
}

char& String::at(size_t pos)
{
	if (pos >= m_len)
		throw std::out_of_range("¬ыход за границы строки");
	return m_arr[pos];
}

const char& String::at(size_t pos) const
{
	if (pos >= m_len)
		throw std::out_of_range("¬ыход за границы строки");
	return m_arr[pos];
}

char& String::operator[](size_t pos)
{
	return at(pos);
}

const char& String::operator[](size_t pos) const
{
	return at(pos);
}

char& String::back()
{
	return at(m_len - 2);
}

const char& String::back() const
{
	return at(m_len - 2);
}

char& String::front()
{
	return at(0);
}

const char& String::front() const
{
	return at(0);
}

String& String::operator+=(const String& str)
{
	reserve(m_len + str.m_len + 1);
	strcat(m_arr, str.m_arr); //объедин€ет строки и ставит нуль-символ в конце новой строки
	return *this;
}

String& String::operator+=(const char* str)
{
	reserve(m_len + strlen(str) + 1);
	strcat(m_arr, str); //объедин€ет строки и ставит нуль-символ в конце новой строки
	return *this;
}

String& String::operator+=(char c)
{
	if (m_len == m_capacity)
		reserve(m_len + 1);
	m_arr[m_len + 1] = c;
	return *this;
}

String& String::operator=(const String& str)
{
	if (this != &str)
		String(str).swap(*this);
	return *this;
}

String& String::operator=(const char* str)
{
	String(str).swap(*this);
	return *this;
}

String& String::insert(size_t pos, const String& str)
{
	if (pos > m_len)
		throw std::out_of_range("¬ыход за границы строки");
	if (pos + strlen(str.m_arr) > m_capacity)
		reserve(pos + strlen(str.m_arr));
	int i;
	int j = 0;
	for (i = pos; i < m_len; i++)
	{
		m_arr[i] = str.m_arr[j];
		j++;
	}
	return *this;
}

String& String::insert(size_t pos, const char* str)
{
	if (pos > m_len)
		throw std::out_of_range("¬ыход за границы строки");
	if (pos + strlen(str) > m_capacity)
		reserve(pos + strlen(str));
	int i;
	int j = 0;
	for (i = pos; i < m_len; i++)
	{
		m_arr[i] = str[j];
		j++;
	}
	return *this;
}

String& String::erase(size_t pos, size_t len)  //временна€ заглушка!
{
	if (pos > m_len)
		throw std::out_of_range("¬ыход за границы строки");
	/*if (len != npos)
	{
		for (int i = 0; i < len; i++)
			m_arr[pos+i] = 
	}
	else
	{

	}*/

	return *this;
}

String& String::replace(size_t pos, size_t len, const String& str)  //временна€ заглушка!
{
	if (pos > m_len)
		throw std::out_of_range("¬ыход за границы строки");


	return *this;
}

String& String::replace(size_t pos, size_t len, const char* str)  //временна€ заглушка!
{
	if (pos > m_len)
		throw std::out_of_range("¬ыход за границы строки");


	return *this;
}

String& String::replace(size_t pos, size_t len, size_t n, char c)  //временна€ заглушка!
{
	if (pos > m_len)
		throw std::out_of_range("¬ыход за границы строки");


	return *this;
}

void String::swap(String& str)
{
	if (this != &str)
	{
		std::swap(m_len, str.m_len);
		std::swap(m_capacity, str.m_capacity);
		std::swap(m_arr, str.m_arr);
	}

}

const char* String::data() const
{
	return m_arr;
}

size_t String::find(const String& str, size_t pos) const // используем только дл€ чтени€, модифицировать ничего не нужно
{
	if (pos > m_len)
		return npos;
	char* ptr = strstr(m_arr + pos, str.m_arr);
	if (ptr != nullptr)
		return ptr - m_arr;
	else
		return npos;
}

size_t String::find(const char* str, size_t pos) const
{
	if (pos > m_len)
		return npos;
	char* ptr = strstr(m_arr + pos, str);
	if (ptr != nullptr)
		return ptr - m_arr;
	else
		return npos;
}

size_t String::find(char c, size_t pos) const
{
	if (pos > m_len)
		return npos;
	size_t i;
	for (i = pos; i < m_len; i++)
	{
		if (m_arr[i] == c)
			return i;
	}
	return npos;
}

String String::substr(size_t pos, size_t len)
{
	String str(this->m_arr, pos, len);
	return str;
}

int String::compare(const String& str) const
{
	return strcmp(this->m_arr, str.m_arr); //сравнивает посимвольно строки
}

size_t String::countRef()  //пока не используетс€! не понимаю где и как именно использовать COW и reference counting!?
{
	return size_t();
}
