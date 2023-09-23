#include <iostream>
using namespace std;

template<class T>
struct nodo {
    T valor[5];
    nodo<T>* next;
    T* p;

    nodo(T v, nodo<T>* n = nullptr) {
        valor[0] = v;
        next = n;
        p = valor;
    }
};

template<class T>
struct tailA {
    nodo<T>* Head;
    nodo<T>* Tail;

    T* head;
    T* tail;
    T* top;

    tailA() {
        Head = nullptr;
        Tail = Head;
        head = nullptr;
        tail = head;
        top = nullptr;
    }
    void push(T v);
    int pop();
    void print();
};

int main()
{
    tailA<int> a;
    a.push(1);
    a.push(12);
    a.push(11);
    a.push(12);
    a.push(13);
    a.push(7);
    a.push(7);
    a.push(7);

    a.print();

    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();

}

template<class T>
void tailA<T>::push(T v) {

    if (!head) {
        Head = new nodo<T>(v);
        Tail = Head;
        head = Head->p;
        tail = head;
        top = Head->p;
        top += 4;
    }
    else {
        if ((tail + 1) <= (top)) {
            tail++;
            *tail = v;
        }
        else {
            Tail->next = new nodo<T>(v, Tail->next);
            Tail = Tail->next;
            tail = Tail->p;
            top = tail + 4;
            *tail = v;
        }
    }
}

template<class T>
int tailA<T>::pop() {
    nodo<T>* Tmp;
    T aux = NULL;

    if (!head || ((head + 1) == tail)) {
        cout << "VACIO\n";
    }
    else {
        top = Head->p;
        top += 4;

        if ((head + 1) <= (top)) {
            aux = *head;
            head++;
        }
        else {
            aux = *head;
            Tmp = Head;
            Head = Head->next;
            head = Head->p;
            top = head + 4;
            delete Tmp;
        }
    }

    return aux;
}

template<class T>
void tailA<T>::print() {

    top = Head->p;
    top += 4;
    T* tmp = head;
    nodo<T>* Tmp = Head;

    cout << "Head -> ";

    while (head && tmp <= tail) {
        if ((tmp <= top)) {
            cout << *tmp << " ";
        }
        else {
            Tmp = Tmp->next;
            tmp = Tmp->p;
            top = tmp + 4;
            cout << " -> " << *tmp << " ";
        }
        tmp++;
    }

    cout << "-> Tail \n";


}
