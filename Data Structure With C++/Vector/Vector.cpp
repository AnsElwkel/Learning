#include "Vector.h"
Vector::Vector(int size) {
    if(size < 0 || size > MAX)
        throw out_of_range("Vector size is out of range");
    this->size = size;
    capacity = size * 2;
    arr = new int[capacity];
    for(int i = 0 ; i < size ; i ++ )
        arr[i] = 0;
}
void Vector::expand() {
    capacity *= 2;
    int* tmpArr = new int[capacity];
    for(int i = 0; i < size; i++)
        tmpArr[i] = arr[i];
    swap(arr, tmpArr);
    delete[] tmpArr;
}
void Vector::push_back(int x) noexcept(true) {
    if(size >= capacity)
        expand();
    arr[size++] = x;
}
void Vector::pop_back() noexcept(false){
    if(size <= 0)
        throw out_of_range("Vector is empty");
    size--;
}
int Vector::find(int val) const noexcept(true) {
    for(int i = 0; i < size; i++)
        if(arr[i] == val) return i + 1;
    return -1;
}
void Vector::set(int val , int index) noexcept(false) {
    if(index < 0 || index >= size) throw out_of_range("index out of range");
    arr[index] = val;
}
int Vector::get(int index) const noexcept(false){
    if(index < 0 || index >= size) throw out_of_range("index out of range");
    return arr[index];
}
int Vector::front() const noexcept(false) {
    if(!size) throw out_of_range("Vector is empty");
    return arr[0];
}
int Vector::back() const noexcept(false) {
    if(!size) throw out_of_range("Vector is empty");
    return arr[size - 1];
}
void Vector::print() const noexcept(true) {
    for(int i = 0 ; i < size; i ++)
        cout << arr[i] << endl;
}
void Vector::insert(int index , int val) {
    if(index < 0 || index >= size) throw out_of_range("index out of range");
    if(size >= capacity)
        expand();

    size++;
    for(int i = size ; i > index; i--) {
        arr[i] = arr[i - 1] ;
    }
    arr[index] = val;
}
int Vector::Size() const {
    return this->size;
}
Vector::~Vector() {
    delete[] arr;
    arr = nullptr;
}
void Vector::rightRotate(int count) noexcept(true){
    int* tmp = new int[size];
    for(int i = 0  , j = size - count; i < count ;++j, ++i)
        tmp[i] = arr[j];

    for(int i = count , j = 0; i < size; ++i , ++j)
        tmp[i] = arr[j];

    swap(arr, tmp);
    delete[] tmp;
}
void Vector::leftRotate(int count) noexcept(true){
    int tmp = arr[0];
    for(int i = 0; i < size - 1 ; i++)
        arr[i] = arr[i + 1];
    arr[size - 1] = tmp;
}

int Vector::pop(int index) {
    if(0 > index || index >= size) throw out_of_range("index out of range");
    int ret = arr[index];
    for(int i = index ; i < size - 1; i++)
        arr[i] = arr[i + 1];
    --size;
    return ret;
}
