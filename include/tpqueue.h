// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
T* arr;
int first, last, count;

 public:
TPQueue() : arr(new T[size]), first(0), last(0), count(0) {}
~TPQueue() { delete[] arr; }
void push(const T& value) {
if (count == size) throw std::string("Full");
++count;
int position = last;
int i = first;
int j = last;
while (i < last) {
if (arr[i].prior < value.prior) {
position = i;
break;
}
i++;
}
while (j > position) {
arr[j % size] = arr[(j - 1) % size];
j--;
}
arr[(position % size)] = value;
last++;
}

T& pop() {
if (count == 0) {
throw std::string("Empty");
} else {
count--;
return arr[first++ % size];
}
}
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
