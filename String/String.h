//
// Created by xue241 on 24-2-23.
//

#ifndef DATASTRUCT_STRING_H
#define DATASTRUCT_STRING_H
#include "../config.h"

class String{
private:
    char *_str;
    int _size;
    int _capacity;

public:
    String(char *s = ""):_str(new char[strlen(s) + 1]), _size(strlen(s)), _capacity(strlen(s)){
        strcpy(_str, s);
    }

    String(const String &s){
        _str = new char[s._capacity + 1];
        memcpy(_str, s._str, s._size + 1);
        _size = s._size;
        _capacity = s._capacity;
    }

    String &operator=(String &s){
        if (this != &s){
            swap(_str, s._str);
            swap(_capacity, s._capacity);
            swap(_size, s._size);
        }
        return *this;
    }

    void reserve(int n){
        if (n > _capacity){
            char *temp = new char[n + 1];
            memcpy(temp, _str, _size + 1);
            delete [] _str;
            _str = temp;
            _capacity = n;
        }
    }

    void push_back(char ch){
        if (_size == _capacity){
            if (_capacity == 0){
                reserve(3);
            }
            else{
                reserve(2 * _capacity);
            }
            _str[_size] = ch;
            _size++;
            _str[_size] = '\0';
        }
    }

    void append(char *str){
        if (_size + strlen(str) > _capacity){
            reserve(_size + strlen(str));
        }
        memcpy(_str + _size, str, strlen(str) + 1);
        _size += strlen(str);
    }

    ~String(){
        delete [] _str;
        _str = nullptr;
        _size = _capacity = 0;
    }

    void Print(){
        cout << _str << "\t" << _size << "\t" << _capacity << endl;
    }

    size_t Size(){
        return _size;
    }

    size_t Capacity(){
        return _capacity;
    }
};
void test_string(){
    String s1("zhangxuan");
    s1.Print();
}


#endif //DATASTRUCT_STRING_H
