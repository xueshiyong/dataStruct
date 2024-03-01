//
// Created by xue241 on 24-2-23.
//

#ifndef DATASTRUCT_VECTOR_H
#define DATASTRUCT_VECTOR_H
#include "../config.h"

template<typename T>
class Vector{
private:
    T *_first;
    T *_finish;
    T *_end;

public:
    Vector():_first(NULL), _finish(NULL), _end(NULL){}
    ~Vector(){
        delete [] _first;
        _first = _finish = _end = NULL;
    }
    Vector(Vector &v1){
        if (v1.Size() > 0){
            size_t size = Size();
            _first = new T[size];
            memcpy(_first, v1._first, sizeof(T) * size);
            if (_first != NULL){
                _finish = _first + size;
                _end = _first + size;
            }
            else{
                _first = _finish = _end = NULL;
            }
        }
    }

    Vector &operator= (Vector &v1){
        if (this != v1){
            swap(_first, v1._first);
            swap(_finish, v1._finish);
            swap(_end, v1._end);
        }
        return *this;
    }

    T operator[](size_t pos){
        assert(pos <= Size());
        return _first[pos];
    }

    Vector(size_t n, const T &val = T()):_first(NULL), _finish(NULL), _end(NULL){
        for (size_t i = 0; i < n; i++){
            Push_back(val);
        }
    }

    size_t Size();
    size_t Capacity();

    void Expand(size_t n);
    void Insert(size_t pos ,T x);
    void Push_back(T x);
    void pop_back();
    void Print(){
        T *cur = _first;
        while (cur != _finish){
            cout << *cur << " ";
            cur++;
        }
        cout << endl;
    }
};

template<typename T>
size_t Vector<T>::Size() {
    return _finish - _first;
}

template<typename T>
size_t Vector<T>::Capacity() {
    return _end - _first;
}

template<typename T>
void Vector<T>::Expand(size_t n) {
    if (n > Capacity()){
        int size = Size();
        T *temp = new T[n];
        memcpy(temp, _first, sizeof(T) * size);
        delete [] _first;
        _first = temp;
        _finish = temp + size;
        _end = temp + n;
    }
}

template<typename T>
void Vector<T>::Insert(size_t pos, T x) {
    assert(pos <= Size());
    if (_finish == _end){
        if (Capacity() == 0){ // 容量为空的情况
            Expand(3);
        }
        else{
            Expand(2 * Capacity());
        }
    }

    int end = Size() - 1;
    while (end >= int(pos)){
        _first[end + 1] = _first[end];
        end--;
    }
    _first[pos] = x;
    ++_finish;
}

template<typename T>
void Vector<T>::Push_back(T x) {
    Insert(Size(), x);
}


void test_vector(){
    Vector<int> v1(10, 20);
    for (int i = 0; i < 10; i++){
        v1.Push_back(i);
    }
    v1.Print();
    cout << v1[2] << endl;
}


#endif //DATASTRUCT_VECTOR_H
