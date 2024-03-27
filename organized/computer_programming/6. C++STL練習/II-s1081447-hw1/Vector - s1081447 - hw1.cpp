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
    myFirst = new int[count]();//�ؤ@�ӰʺA�x�}(�Q��myFirst�YmyFirst�@�ӫ��ХB���V�ʺA�}�C���Ĥ@��)
    myLast = myEnd = myFirst + count;//�NmyLast�MmyEnd���V�ӰʺA�}�C���̫�@��
}

// copy constructor
// Constructs a container with a copy of each of the elements in "right",
// in the same order.
vector::vector(const vector& right)
{
    int temp = right.myLast - right.myFirst;//temp�Y�W������constructor function��count�N��x�}�j�p(�Psize)
    myFirst = new int[temp]();//�ؤ@�ӰʺA�x�}(�Q��myFirst�YmyFirst�@�ӫ��ХB���V�ʺA�}�C���Ĥ@��)
    myLast = myEnd = myFirst + temp;//�NmyLast�MmyEnd���V�ӰʺA�}�C���̫�@��

    for (int i = 0; i < temp; i++)
        *(myFirst + i) = *(right.myFirst + i);//�Nright�}�C�����Ȧs�i�s�ت��ʺA�}�C��
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
        if (right.myLast - right.myFirst > myEnd - myFirst) {//��ʺA�}�C��size���p(�Yright���j)
            resize(right.myLast - right.myFirst);//�N��ʺA�}�C��size�אּright��size
            for (int i = 0; i < right.myLast - right.myFirst; i++)
                myFirst[i] = right.myFirst[i];//�Nright�}�C�����Ȧs�i�ʺA�}�C��
        }
        else {//��ʺA�}�C��size���j(�Yright���p)
            resize(right.myLast - right.myFirst);//�N��ʺA�}�C��size�אּright��size
            for (int i = 0; i < right.myLast - right.myFirst; i++)
                myFirst[i] = right.myFirst[i];//�Nright�}�C�����Ȧs�i�ʺA�}�C��
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
    int capacity = myEnd - myFirst;//�e�q�ΨӲŦX�W�h
    if (newSize <= capacity)//resize�����p��size
        myLast = myFirst + newSize;//��������myLast�Y�i
    else if (capacity / 2 + capacity <= newSize) {//newSize���j�A�L�k�Q�γW�h
        pointer ptr = new int[newSize]();//�h�����ؤ@��newSize���ʺA�}�C�Y�i
        for (int i = 0; i < myLast - myFirst; i++)
            ptr[i] = myFirst[i];//�N��ʺA�}�C�����Ʀr�s�i�s���}�C
        delete[]myFirst;//�N��ʺA�}�C�R���קK�y���q���d�y
        myFirst = ptr;//�NmyFirst���V�s�ʺA�}�C(�YmyFirst[i]���s�ʺA�}�C������i�Ӥ���)
        myLast = myEnd = ptr + newSize;//�NmyLast�MmyEnd���V�ӰʺA�}�C���̫�@��
    }
    else {//newSize�b�W�h����U�A�����ӳW�h�s�ؤ@�ӰʺA�}�C
        pointer ptr = new int[capacity / 2 + capacity]();//�W�h:�scapacity���쥻��1.5��(�p���I�᪽���˥h)
        for (int i = 0; i < myLast - myFirst; i++)
            ptr[i] = myFirst[i];//�N��ʺA�}�C�����Ʀr�s�i�s���}�C
        delete []myFirst;//�N��ʺA�}�C�R���קK�y���q���d�y
        myFirst = ptr;//�NmyFirst���V�s�ʺA�}�C(�YmyFirst[i]���s�ʺA�}�C������i�Ӥ���)
        myEnd = ptr + capacity + capacity / 2;//�NmyEnd���V�ӰʺA�}�C���̫�@��
        myLast = newSize + myFirst;//myLast���V���T����m(�YmyFirst[newSize - 1]���s�ʺA�}�C���̫�@��A�G���VmyFirst[newSize]�A�Y��capacity�٦�)
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