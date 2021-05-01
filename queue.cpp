/*#include <iostream>
using namespace std;*/

// Implementing STL Queue class */
template <typename T>
class queue {
public:
    struct node {
        T data;
        node *next;

        node()
            : data(0)
            , next(NULL) {
        }

        node(T data, node* next)
            : data(data)
            , next(next) {
        }

    };
    ~queue();
    bool empty();
    size_t size();
    T front();
    void push(T data);
    T pop();

private:
    size_t elements = 0;
    node *head;
    node *tail;
};

template <typename T>
queue<T>::~queue()
{}

template <typename T>
bool queue<T>::empty()
{
    return elements == 0;
}

template <typename T>
size_t queue<T>::size()
{
    return elements;
}

template <typename T>
T queue<T>::front()
{
    if(elements == 0)
        std::cout <<"Empty Queue"<<std::endl;
    return head->data;
}

template <typename T>
void  queue<T>::push(T data)
{
    node *newNode = new node(data, NULL);
    if(!elements)
       head = newNode;
    else
       tail->next = newNode;
    tail = newNode;
    ++elements;
}
template <typename T>
T queue<T>::pop()
{
    int pop_elem;
    if(elements == 0)
        std::cout <<"Empty Queue"<<std::endl;
    node *tmp = new node();
    if(elements != 0)
       tmp = head;
   
    pop_elem = tmp->data;
    head = head->next;
    --elements;
    delete tmp;
    return pop_elem;
}

/*int main()
{
  queue<int> q;
    q.push(5);
    q.push(4);
    q.push(6);

    cout << q.pop()<<std::endl;
}*/
