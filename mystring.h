#pragma once

class String {
private:
    size_t m_len;
    size_t m_capacity;
    char* m_arr;

public:
    String();
    String(const char* str);
    String(const char* str, size_t n);
    String(size_t n, char c);
    String(const String& str);
    String(const String& str, size_t pos, size_t len = npos);
    virtual ~String();

    size_t size() const; //������, �������� �����
    size_t capacity() const; //�����������(2*������+1), �������� �����
    void reserve(size_t n = 0);
    void clear();
    bool empty() const;

    char& at(size_t pos);
    const char& at(size_t pos) const;

    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;

    char& back();
    const char& back() const;

    char& front();
    const char& front() const;

    String& operator+=(const String& str);
    String& operator+=(const char* str);
    String& operator+=(char c);

    String& operator=(const String& str);
    String& operator=(const char* str);

    //��������� ������� ������ str � ������� pos.
    //���� pos ������ ������� ������, �� ������������� ���������� throw std::out_of_range("message");.
    String& insert(size_t pos, const String& str);
    String& insert(size_t pos, const char* str);

    //��������� �������� ��������� � ������ ������� � ������� pos � ��������� len ��������.
    //���� len ��������� npos, �� �������� ���������� � ������� pos �� ����� ������. ���� pos ������ ������� ������, �� ������������� ���������� throw    . 
    //std::out_of_range("message");.
    String& erase(size_t pos = 0, size_t len = npos);

    //��������� ������ ��������� � ������ ������� � ������� pos � ��������� len ��������.
    //���� len ��������� npos, �� �������� ���������� � ������� pos �� ����� ������.
    //���� pos ������ ������� ������, �� ������������� ���������� throw std::out_of_range("message");.
    String& replace(size_t pos, size_t len, const String& str);
    String& replace(size_t pos, size_t len, const char* str);
    String& replace(size_t pos, size_t len, size_t n, char c);

    void swap(String& str);
    const char* data() const;

    //���������� ������ ��������� str (��� ������� c) � ������. pos - ������ ������� � ������� �������� �����.
    //���� ��������� �� ����� ��� pos ������ ������� ������, ����� ��������� npos.
    size_t find(const String& str, size_t pos = 0) const;
    size_t find(const char* str, size_t pos = 0) const;
    size_t find(char c, size_t pos = 0) const;

    String substr(size_t pos = 0, size_t len = npos);

    int compare(const String& str) const;
    //����������� ��������� � ������������ ��������� size_t.
    // ��� ��������� ����� ���� ������������ � ������� ��� ��������� len, ��� �������� "�� ����� ������".
    //����� ��� ��������� ����� ���� ������������ � �������� ������������� �������� ��� �������� ���������� ����������.
    static const size_t npos = -1;

    size_t countRef(); //����� ������?
};