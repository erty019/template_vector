#include <iostream>
#include "MyQueue.h"


int main()
{
    MyQueue<int> q(5);

    // Добавляем элементы в очередь
    q.Push(10);
    q.Push(20); 
    q.Push(30);
    q.Push(40);
    q.Push(50);

    // Выводим содержимое очереди
    std::cout << "Queue: " << q << std::endl;

    return 0;


	
}
