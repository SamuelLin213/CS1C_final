#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>
#include <algorithm>
using std::copy;
using std::rotate;
using std::cout;
using std::endl;
/*! @file */
template <class T>
class myVector
{   // the size
    int size_v;
    // a ptr to the elements
    T *elem;
    // size + free_space
    int space;
public:
/*! default constructor
    */
    myVector() : size_v{0}, elem{nullptr}, space{0} {};
/*!
    overloaded constructor
    */
    explicit myVector(int s) : size_v{s}, elem{new T[s]}, space{s}
    {
        for (int i = 0; i < size_v; ++i)
        {
            elem[i] = 0;  // elements are initialized
        }
    }
/*! copy constructor
    */
    myVector(const myVector&src)
    {
        size_v = src.size_v;
        elem = new T[src.size_v];
        space = src.space;

        copy(src.elem, src.elem + size_v, elem); // copy elements - std::copy()
    }
/*! copy assignment
    */
    myVector& operator=(const myVector&src)
    {
        if (this != &src)
        {
            T *p = new T[src.size_v];  // allocate new space
            copy(src.elem, src.elem + src.size_v, p); // copy elements - std::copy algorithm
            delete[] elem;   // deallocate old space
            elem = p;        // reset elem
            size_v = src.size_v;
        }
        return *this;
    }
/*! move constructor
    */
    myVector(myVector&&src)
    {
        size_v = src.size_v;
        copy(src.elem, src.elem + size_v, elem);
        delete src.elem;
        src.size_v = 0;
    }
/*! move assignment
    */
    myVector& operator=(const myVector&&src)
    {
        delete [] elem;
        copy(src.elem, src.elem + size_v, elem);
        delete [] src.elem;
        return *this;
    }
/*! destructor
    */
    ~myVector()
    {
        delete [] elem;
    }
/*! access: return reference
    */
    T& operator[](int n)
    {
        return elem[n];
    }
/*! access: return reference
    */
    const T& operator[](int n) const
    {
        return elem[n];
    }
/*! the current size
    */
    int size() const
    {
        return size_v;
    }
/*! current available space
    */
    int capacity() const
    {
        return space;
    }
/*! returns the pointer to the elements
    */
    T* getElem() const
    {
        return elem;
    }
/*! growth
    */
    void resize(int newsize)
    {
        reserve(newsize);  // make the vector have newsize elements
        for (int i = size_v; i < newsize; ++i)
            elem[i] = 0;   // initialize new elements
        size_v = newsize;
    }
/*! add element
    */
    void push_back(T val)
    {
        if (space == 0)
            reserve(8);     // start with space for 8 elements
        else if (size_v == space)
            reserve(2 * space); // get more space
        elem[size_v] = val;    // add val at end
        ++size_v;       // inc the size (size_v is the number of elements)
    }
/*! get more space
    */
    void reserve(int newalloc)
    {
        if (newalloc > space)
        {
            T* tempAr = new T[newalloc];

            for (int i = 0; i < size_v; ++i)
            {
                tempAr[i] = elem[i];
            }
            for (int i = size_v; i < newalloc; ++i)
            {
                T temp{};
                tempAr[i] = temp;
            }
            delete[] elem;
            elem = tempAr;
            tempAr = nullptr;

            space = newalloc;
        }
    }

    using iterator = T*;
    using const_iterator = const T*;
/*! points to first element
    */
    iterator begin()
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }
/*! points to first element
    */
    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }
/*! points to one beyond the last element
    */
    iterator end()
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }
/*! insert a new element v before p
    */
    iterator insert(iterator p, const T& v)
    {
        iterator tempPtr = nullptr;

        // make sure we have space
        if (size_v >= space)
            reserve(1);

        for (tempPtr = &elem[size_v]; tempPtr > p; --tempPtr)
            *tempPtr = *(tempPtr - 1);  // shift array element to the right

        tempPtr = nullptr;

        // the place to put the value
        *p = v;

        // copy element one position to the right
        // insert value
        ++size_v;

        return p;
    }
    /*! remove element pointed to by p
    */
    iterator erase(iterator p)
    {
        if (p == end())
            return p;
        for (iterator pos = p+1; pos != end(); ++pos)
            *(pos - 1) = *pos;  // copy element one position to the left
        --size_v;
        return p;
    }

    /*! print all elements in the vector
    */
    void print() const
    {
        for (int i = 0; i < size_v; ++i)
        {
            cout << elem[i] << " ";
        }
    }
};

#endif /* VECTOR_H */
