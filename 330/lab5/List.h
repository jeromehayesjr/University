/****************************************************************************
 Jerome Hayes Jr
 List.h
 2/13/16
 This program is a header file that include three classes, List, Link,and List_Iterator,
 also their implementations. I was able to recreated linked list.
 *****************************************************************************/
#include <algorithm>
#include <iostream>

using namespace std;

#ifndef LIST_H
#define LIST_H

// List.h - a doubly-linked list


template <class T> class Link;
template <class T> class List_iterator;

template <class T>
class List
{
protected:
    Link<T> * first_link;
    Link<T> * last_link;
    unsigned int my_size;
public:
    typedef List_iterator<T> iterator;
    
    List(); //done
    List(const List<T> & l); //done
    ~List(); //done
    
    bool empty() const;     //done
    unsigned int size() const;
    T & back() const;   //done
    T & front() const;  //done
    void push_front(const T & x);   //done
    void push_back(const T & x);    //done
    void pop_front();   //done
    void pop_back(); //done
    iterator begin() const; //done
    iterator end() const;   //done
    void insert(iterator pos, const T & x); //done
    void erase(iterator & pos); //done
    void erase(iterator &start, iterator &stop);
    List<T> & operator=(const List<T> & l); //done
};

template <class T>
List<T>::List()
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
}

template <class T>
List<T>::List(const List & l)
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
    for(Link<T> * current = l.first_link; current != 0; current = current -> next_link)
        push_back(current -> value);
}

template <class T>
List<T>::~List()
{
    while(!empty())
        pop_back();
}

template <class T>
List<T> & List<T>::operator=(const List<T> & l)
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
    for(Link<T> * current = l.first_link; current != 0; current = current -> next_link)
        push_back(current -> value);
    return *this;
}

template <class T>
bool List<T>::empty() const
{
    if(my_size == 0)        //returns true if the list is empty
        return true;
    return false;
}
template <class T>
unsigned int List<T>::size() const
{
    return my_size;
}

template <class T>
T & List<T>::front() const
{
    return *begin();    //returns the value at the beginning of the list
}

template <class T>
T& List<T>::back() const
{
    return *end();      //returns the value at the end of the list
}

template <class T>
typename List<T>::iterator List <T>::begin() const
{
    return iterator(first_link);
}

template <class T>
typename List<T>::iterator List <T>::end() const
{
    return iterator(last_link);
}

template <class T>
void List<T>::push_back(const T & x)  //places new link at the end of the list
{
    Link<T> * new_link = new Link<T> (x);
    if(first_link == 0)
        first_link = last_link = new_link;
    else {
        new_link -> prev_link = last_link;
        last_link -> next_link = new_link;
        last_link = new_link;
    }
    my_size++;
}

template <class T>
void List<T>::push_front(const T & x) //places new link at the beginning of the list
{
    Link<T> * new_link = new Link<T> (x);
    if (first_link == 0)
        first_link = last_link = new_link;
    else {
        first_link -> prev_link = new_link;
        new_link -> next_link = first_link;
        first_link = new_link;
    }
    my_size++;
}

template <class T>
void List<T>::pop_back()    //removes the last link in the list
{
    Link<T> *save = last_link;
    last_link = last_link -> prev_link;
    if (last_link !=0)
        last_link -> next_link = 0;
    else
        first_link = 0;
    my_size--;
    delete save;
    
}

template <class T>
void List<T>::pop_front()   //removes the beginning link in the list
{
    Link<T> * copy = first_link;
    first_link = first_link -> next_link;
    if (first_link !=0)
        first_link -> prev_link = 0;
    else
        last_link = 0;
    my_size--;
    
    delete copy;
    
}

template <class T>
void List<T>::insert(iterator pos, const T & x)
{
    Link<T> * new_link = new Link<T> (x);
    if(new_link == 0) {
        cout << "error";
        exit(1);
    }
    my_size++;
    Link<T> *next = pos.current_link;
    if(next == 0) {
        first_link = last_link = new_link;
        return;
    }
    Link<T> *prev = pos.current_link -> prev_link;
    new_link -> next_link = next;
    new_link -> prev_link = prev;
    if (prev == 0)
        first_link = new_link;
    else
        prev -> next_link = new_link;
}

template <class T>
void List<T>:: erase(iterator & pos)
{
    erase(pos,pos);
}

template<class T>
void List<T>::erase(iterator &start, iterator &stop)
{
    Link<T> *first = start.current_link;
    Link<T> *prev = first->prev_link;
    Link<T> *last = stop.current_link;
    if (prev == 0) {
        first_link = last;
        if (last == 0) 
            last_link = 0;
        else
           last->prev_link = 0;
    }
    else {
        prev -> next_link = last;
        if(last == 0)
            last_link = prev;
        else 
            last->prev_link = prev;
    }
    while (start != stop) {
        List_iterator<T> next = start;
        ++next;
        delete start.current_link;
        start = next;
    }
}


template <class T>
class Link
{
private:
    Link(const T & x): value(x), next_link(0), prev_link(0) {}
    
    T value;
    Link<T> * next_link;
    Link<T> * prev_link;
    
    friend class List<T>;
    friend class List_iterator<T>;
};

template <class T> class List_iterator
{
public:
    typedef List_iterator<T> iterator;
    
    List_iterator(Link<T> * source_link): current_link(source_link) { }
    List_iterator(): current_link(0) { }
    List_iterator(List_iterator<T> * source_iterator): current_link(source_iterator->current_link) { }
    
    T & operator*();  // dereferencing operator   done
    iterator & operator=(const iterator & rhs); // done
    bool operator==(const iterator & rhs) const; //done
    bool operator!=(const iterator & rhs) const; //done
    iterator & operator++();  // pre-increment, ex. ++it   done
    iterator operator++(int); // post-increment, ex. it++  done
    iterator & operator--();  // pre-decrement done
    iterator operator--(int); // post-decrement done
    
protected:
    Link<T> * current_link;
    
    friend class List<T>;
};

template <class T>
T & List_iterator<T>::operator*()
{
    return current_link -> value;
}

template <class T>
List_iterator<T> & List_iterator<T>::operator++() // pre-increment
{
    current_link = current_link -> next_link;
    return *this;
}

template <class T>
List_iterator<T> List_iterator<T>::operator++(int) //post-increment
{
    List_iterator<T> copy(current_link);
    current_link = current_link -> next_link;
    return current_link;
}
template <class T>
List_iterator<T> & List_iterator<T>::operator=(const iterator & rhs)
{
    this-> current_link= rhs.current_link;
    return *this;
}

template <class T>
bool List_iterator<T>:: operator==(const iterator & rhs) const
{
    return current_link == rhs.current_link;
}

template <class T>
bool List_iterator<T>:: operator !=(const iterator & rhs) const
{
    return current_link != rhs.current_link;
}

template <class T>
List_iterator<T> & List_iterator<T>:: operator--()
{
    current_link = current_link -> prev_link;
    return *this;
}

template <class T>
List_iterator<T> List_iterator<T>::operator--(int)
{
    List_iterator<T> copy(current_link);
    current_link = current_link -> prev_link;
    return current_link;
}
#endif
