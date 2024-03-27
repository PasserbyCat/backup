#include "Vector.h" // include definition of class vector 

// empty container constructor (default constructor)
// Constructs an empty container, with no elements.
vector::vector()
{
    myFirst = myLast = myEnd = nullptr;
}

// fill constructor
// Constructs a container with "count" elements.
// Each element is initialized as 0.
vector::vector(const size_type count)
{
    myFirst = new int[count]();//建一個動態矩陣(利用myFirst即myFirst一個指標且指向動態陣列的第一位)
    myLast = myEnd = myFirst + count;//將myLast和myEnd指向該動態陣列的最後一位
}

// copy constructor
// Constructs a container with a copy of each of the elements in "right",
// in the same order.
vector::vector(const vector& right)
{
    int temp = right.myLast - right.myFirst;//temp即上面那個constructor function的count代表矩陣大小(同size)
    myFirst = new int[temp]();//建一個動態矩陣(利用myFirst即myFirst一個指標且指向動態陣列的第一位)
    myLast = myEnd = myFirst + temp;//將myLast和myEnd指向該動態陣列的最後一位

    for (int i = 0; i < temp; i++)
        *(myFirst + i) = *(right.myFirst + i);//將right陣列中的值存進新建的動態陣列中
}

// Vector destructor
// Destroys the container object.
// Deallocates all the storage capacity allocated by the vector.
vector::~vector()
{
    if (myFirst != nullptr)
        delete[] myFirst;
}

// Adds a new element at the end of the vector, after its current last element.
// The content of val is copied to the new element.
// This effectively increases the vector size by one,
// which causes an automatic reallocation of the allocated storage space
// if and only if the new vector size surpasses the current vector capacity.
void vector::push_back(const value_type& val)
{
    size_type originalSize = size();
    resize(originalSize + 1);
    myFirst[originalSize] = val;
}

// Assigns new contents to the container, replacing its current contents,
// and modifying its size accordingly.
// Copies all the elements from "right" into the container
// (with "right" preserving its contents).
vector& vector::assign(const vector& right)
{
    if (this != &right) // avoid self-assignment
    {
        if (right.myLast - right.myFirst > myEnd - myFirst) {//原動態陣列的size較小(即right較大)
            resize(right.myLast - right.myFirst);//將原動態陣列的size改為right的size
            for (int i = 0; i < right.myLast - right.myFirst; i++)
                myFirst[i] = right.myFirst[i];//將right陣列中的值存進動態陣列中
        }
        else {//原動態陣列的size較大(即right較小)
            resize(right.myLast - right.myFirst);//將原動態陣列的size改為right的size
            for (int i = 0; i < right.myLast - right.myFirst; i++)
                myFirst[i] = right.myFirst[i];//將right陣列中的值存進動態陣列中
        }
    }

    return *this; // enables x = y = z, for example
}

// Resizes the vector so that it contains newSize elements.
// If newSize is smaller than the current vector size,
// the content is reduced to its first newSize elements, removing those beyond.
// If newSize is greater than the current vector size,
// the content is expanded by inserting at the end
// as many elements as needed to reach a size of newSize.
// The new elements are initialized as 0.
// If newSize is also greater than the current vector capacity,
// an automatic reallocation of the allocated storage space takes place.
void vector::resize(const size_type newSize)
{
    int capacity = myEnd - myFirst;//容量用來符合規則
    if (newSize <= capacity)//resize成較小的size
        myLast = myFirst + newSize;//直接改變myLast即可
    else if (capacity / 2 + capacity <= newSize) {//newSize極大，無法利用規則
        pointer ptr = new int[newSize]();//則直接建一個newSize的動態陣列即可
        for (int i = 0; i < myLast - myFirst; i++)
            ptr[i] = myFirst[i];//將原動態陣列中的數字存進新的陣列
        delete[]myFirst;//將原動態陣列刪除避免造成電腦卡頓
        myFirst = ptr;//將myFirst指向新動態陣列(即myFirst[i]為新動態陣列中的第i個元素)
        myLast = myEnd = ptr + newSize;//將myLast和myEnd指向該動態陣列的最後一位
    }
    else {//newSize在規則條件下，必須照規則新建一個動態陣列
        pointer ptr = new int[capacity / 2 + capacity]();//規則:新capacity為原本的1.5倍(小數點後直接捨去)
        for (int i = 0; i < myLast - myFirst; i++)
            ptr[i] = myFirst[i];//將原動態陣列中的數字存進新的陣列
        delete []myFirst;//將原動態陣列刪除避免造成電腦卡頓
        myFirst = ptr;//將myFirst指向新動態陣列(即myFirst[i]為新動態陣列中的第i個元素)
        myEnd = ptr + capacity + capacity / 2;//將myEnd指向該動態陣列的最後一位
        myLast = newSize + myFirst;//myLast指向正確的位置(即myFirst[newSize - 1]為新動態陣列的最後一位，故指向myFirst[newSize]，即使capacity還有)
    }
}

// Removes the last element in the vector,
// effectively reducing the container size by one.
void vector::pop_back()
{
    if (size() > 0)
        --myLast;
}

// Removes all elements from the vector (which are destroyed),
// leaving the container with a size of 0.
// A reallocation is not guaranteed to happen,
// and the vector capacity is not guaranteed to change due to calling this function.
void vector::clear()
{
    myLast = myFirst;
}

// Returns an iterator pointing to the first element in the vector.
// If the container is empty, the returned iterator value shall not be dereferenced.
vector::pointer vector::begin()
{
    return myFirst;
}

// Returns the number of elements in the vector.
// This is the number of actual objects held in the vector,
// which is not necessarily equal to its storage capacity.
vector::size_type vector::size()
{
    return (myLast - myFirst);
}

// Returns the size of the storage space currently allocated for the vector,
// expressed in terms of elements.
// This capacity is not necessarily equal to the vector size.
// It can be equal or greater, with the extra space allowing to accommodate
// for growth without the need to reallocate on each insertion.
vector::size_type vector::capacity()
{
    return (myEnd - myFirst);
}

// Returns a reference to the element at position "pos" in the vector container.
vector::value_type& vector::element(const size_type pos)
{
    return myFirst[pos];
}