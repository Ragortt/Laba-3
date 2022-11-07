//#include <iostream>
//using namespace std;
//
//template<typename T>
//class TQueue
//{
//private:
//    T* arr;          // массив с данными
//    int size;        // максимальное количество элементов в очереди (размер массива)
//    int begin, end;  // начало очереди  конец очереди
//    int count;       // счетчик элементов
//public:
//    TQueue(int = 100);          // конструктор по умолчанию
//    ~TQueue();                 // деструктор
//
//    void push(const T&); // добавить элемент в очередь
//    int GetSize() { return count; }
//    void pop();              // удалить элемент из очереди
//    int GetFront() { return arr[begin]; }      // прочитать первый элемент
//    bool isEmpty() { return count == 0; }      // пустая ли очередь?
//};
//
//// конструктор по умолчанию
//template<typename T>
//TQueue<T>::TQueue(int sizeQueue) :
//    size(sizeQueue),
//    begin(0), end(0), count(0)
//{
//    // дополнительный элемент поможет нам различать конец и начало очереди
//    arr = new T[size + 1];
//}
//
//// деструктор класса Queue
//template<typename T>
//TQueue<T>::~TQueue()
//{
//    delete[] arr;
//}
//
//
//// функция добавления элемента в очередь
//template<typename T>
//void TQueue<T>::push(const T& item)
//{
//    arr[end++] = item;
//    count++;
//}
//
//// функция удаления элемента из очереди
//template<typename T>
//void TQueue<T>::pop()
//{
//    T item = arr[begin++];
//    count--;
//}
//
//
//int main() {
//
//    TQueue<int>a;
//
//    a.push(13);
//    a.push(23);
//    a.push(33);
//    a.push(43);
//     
//    cout<<a.GetFront();
//    cout << endl << a.GetSize();
//    a.pop();
//    cout<<endl << a.GetFront();
//
//    cout << endl << a.GetSize();
//
//    return 0;
//}
#include <iostream>
using namespace std;

template<typename T>
class Tqueue 
{
public:
    Tqueue();
    ~Tqueue();
    void push(T data);
    T pop();
    int GetSize() { return Size; }
    T GetFront(); 
    bool isEmpty() { return Size == 0; } 

private:

    template<typename T>
    struct Node
    {
        Node* pNext;
        T data;

        Node(T data = T(), Node* pnext = nullptr)
        {
            this->data = data; 
            this->pNext = pnext;
        }
    };
    int Size;
    Node<T>* head;

};

template<typename T>
Tqueue<T>::Tqueue()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
Tqueue<T>::~Tqueue()
{
}

template<typename T>
void Tqueue<T>::push(T data)
{
    Node<T>* temp = new Node<T>(data);
    temp->pNext = 0;
    temp->data = data;

    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;        // односвязный
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
T Tqueue<T>::pop()
{
    Node<T>* temp = head;
    T f = head->data;
    head = head->pNext;
    delete temp;
    Size--;
    return f;
}

template<typename T>
T Tqueue<T>::GetFront()
{
    Node<T>* current = this->head;
    return current->data;
}


int main()
{
    setlocale(0, "");
    Tqueue<int> a;
    cout << "Заполните список" << endl;
   
    for (int i = 0; i < 7; i++)
    {  
        int c; cin >> c;
        a.push(c);
    }

 /*   a.push(13);
    a.push(23);
    a.push(33);
    a.push(43);*/

    cout<<endl<<"Первый элемент " << a.GetFront();
    cout << endl<<"Длина " << a.GetSize()<<endl<<"Произошло удаление ";
    a.pop();
    cout << endl<< "Первый элемент " << a.GetFront();

    cout << endl << "Длина " << a.GetSize() << endl << "Добавте элемент " << endl;
    a.pop();
    int c; cin >> c;
    a.push(c);

    for (int i = 0; i < a.GetSize()*sizeof(int)*2; i++)
    {
        cout << a.pop()<<endl;
    }

    return 0;
}

