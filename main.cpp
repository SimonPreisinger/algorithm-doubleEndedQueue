#include <iostream>

class Deque {
private:
    struct Elem {
        const int content;
        Elem *next = nullptr;

        Elem(const int c, Elem *n) : content(c), next(n) {}
    };

    Elem *front = nullptr, *back = nullptr;

    void balance(){
        front=back;
        back=back->next;
    };

public:
    bool empty() { return front == nullptr && back == nullptr; }

    // vorne einfügen
    void push(const int frontInt) {
        if (front == nullptr) {
            front = new Elem(frontInt, nullptr);;
        } else {
            Elem *old = front;
            front = new Elem(frontInt, old);
        }
    };


    //vorne entfernen
    int pop() {
        if (empty())
            throw "cannot pop from empty deque";
        if(front->next == nullptr)
            balance();
        int value = front->content;
        front = front->next;
        return value;

    };

    // hinten anfügen
    void put(const int backInt) {
        Elem *elem = new Elem(backInt, nullptr);
        if(back == nullptr)
            back = new Elem(backInt, nullptr);
        else {
            Elem *old = back;
            back = new Elem(backInt, old);
        }
    };

    // hinten entfernen
    int get() {
        if (empty())
            throw "cannot pop from empty deque";
    };


    // vorne lesen ohne entfernen
    int first() {
        if (empty())
            throw "cannot pop from empty deque";
        return front->content;
    };

    // hinten lesen ohne entfernen
    int last() {
        if (empty())
            throw "cannot pop from empty deque";
        return back->content;
    };

    // wenn eine Liste leer ist, die andere aufteilen
    friend int length(Elem *);

    friend Elem *reverse(Elem *);
};


int main() {
    auto deque = new Deque();
    deque->push(1);
    // ([1], [])
    deque->put(2);
    // /[1], [2])
    deque->push(3);
    // ([3,1], [2])
    deque->put(4);
    // ([3,1], [4,2]) entspricht der double ended queue 3->1->2->4
    deque->pop(); //3
    // ([1],[4,2])
    deque->pop(); // 1
    // ([],[4,2])
    deque->pop(); // 2
    // erst wird durch balance umgebaut in ([2][4]) und dann die 2 zurück gegeben
    return 0;
}