#include "String.h" // include definition of class String

string::string()
    : bx(),
    mySize(0),
    myRes(15)
{
}

string::string(const char* const ptr, const size_type count)
    : bx(),
    mySize(0),
    myRes(15)
{
    if (count < 16) {
        for (int i = 0; i < count; i++) {
            bx.buf[i] = ptr[i];
        }
        mySize = count;
    }
    else {
        for (int i = 1;; i++) {
            if (count + 1 <= 16 * i) {
                myRes = 16 * i - 1;
                break;
            }
        }
        mySize = count;
        bx.ptr = new char[myRes]();
        for (int i = 0; i < count; i++) {
            bx.ptr[i] = ptr[i];
        }
    }
}

string::string(const size_type count, const char ch)
    : bx(),
    mySize(0),
    myRes(15)
{
    if (count < 16) {
        for (int i = 0; i < count; i++) {
            bx.buf[i] = ch;
        }
        mySize = count;
    }
    else {
        for (int i = 1;; i++) {
            if (count + 1 <= 16 * i) {
                myRes = 16 * i - 1;
                break;
            }
        }
        mySize = count;
        bx.ptr = new char[myRes]();
        for (int i = 0; i < count; i++) {
            bx.ptr[i] = ch;
        }
    }
}

string::string(const string& right)
    : bx(),
    mySize(0),
    myRes(15)
{
    if (right.size() < 16) {
        for (int i = 0; i < right.size(); i++) {
            bx.buf[i] = right.myPtr()[i];
        }
        mySize = right.size();
    }
    else {
        for (int i = 1;; i++) {
            if (right.size() + 1 <= 16 * i) {
                myRes = 16 * i - 1;
                break;
            }
        }
        mySize = right.size();
        bx.ptr = new char[myRes]();
        for (int i = 0; i < right.size(); i++) {
            bx.ptr[i] = right.myPtr()[i];
        }
    }
}

string::~string()
{
    if (myRes > 15)
        delete[] bx.ptr;
}

string::value_type* string::myPtr()
{
    if (myRes < 16)
        return bx.buf;
    else
        return bx.ptr;
}

const string::value_type* string::myPtr() const
{
    if (myRes < 16)
        return bx.buf;
    else
        return bx.ptr;
}

string& string::assign(const string& right)
{
    if (this != &right) // avoid self-assignment
    {
        if (right.mySize > myRes) {//原動態陣列的size較小(即right較大)
            resize(right.mySize);//將原動態陣列的size改為right的size
            for (int i = 0; i < right.mySize; i++)
                myPtr()[i] = right.myPtr()[i];//將right陣列中的值存進動態陣列中
        }
        else {//原動態陣列的size較大(即right較小)
            resize(right.mySize);//將原動態陣列的size改為right的size
            for (int i = 0; i < right.mySize; i++)
                myPtr()[i] = right.myPtr()[i];//將right陣列中的值存進動態陣列中
        }
    }

    return *this; // enables x = y = z, for example
}

void string::clear()
{
    mySize = 0;
    myPtr()[0] = value_type();
}

string::iterator string::begin()
{
    return iterator(myPtr());
}

string::const_iterator string::begin() const
{
    return const_iterator(myPtr());
}

string::iterator string::end()
{
    return iterator(myPtr() + static_cast<difference_type>(mySize));
}

string::const_iterator string::end() const
{
    return const_iterator(myPtr() + static_cast<difference_type>(mySize));
}

string::reference string::element(const size_type off)
{
    return myPtr()[off];
}

string::const_reference string::element(const size_type off) const
{
    return myPtr()[off];
}

void string::push_back(char ch)
{
    resize(mySize + 1);
    myPtr()[mySize - 1] = ch;
}

void string::pop_back()
{
    if (mySize > 0)
        --mySize;
}

string::reference string::front()
{
    return myPtr()[0];
}

string::const_reference string::front() const
{
    return myPtr()[0];
}

string::reference string::back()
{
    return myPtr()[mySize - 1];
}

string::const_reference string::back() const
{
    return myPtr()[mySize - 1];
}

const char* string::c_str() const
{
    return myPtr();
}

string::size_type string::size() const
{
    return mySize;
}

void string::resize(const size_type newSize, const char ch)
{
    size_type newMyRes = myRes * 3 / 2;
    if (newMyRes < (newSize / 16) * 16 + 15)
        newMyRes = (newSize / 16) * 16 + 15;

    if (myRes == 15 && newSize > 15) {
        pointer ptr = new value_type[newMyRes]();
        for (size_type i = 0; i < mySize; i++) {
            ptr[i] = bx.buf[i];
        }
        for (size_type i = mySize; i < newSize; i++) {
            ptr[i] = ch;
        }
        myRes = newMyRes;
        bx.ptr = ptr;
    }

    else if (newSize > myRes) {
        pointer ptr = new value_type[newMyRes]();
        for (size_type i = 0; i < mySize; i++) {
            ptr[i] = bx.ptr[i];
        }
        for (size_type i = mySize; i < newSize; i++) {
            ptr[i] = ch;
        }
        myRes = newMyRes;
        delete[]bx.ptr;
        bx.ptr = ptr;
    }
    else {
        for (size_type i = mySize; i < newSize; i++) {
            myPtr()[i] = ch;
        }
    }
    mySize = newSize;
}

string::size_type string::capacity() const
{
    return myRes;
}

bool string::empty() const
{
    return mySize == 0;
}