#include <iostream>
using std::cout;
using std::exit;

#include "String.h" // include definition of class String

// empty string constructor (default constructor)
// Constructs an empty string, with a length of zero characters.
string::string() 
    : myData()
{
}

// from buffer
// Copies the first "count" characters from the array of characters pointed by ptr.
string::string(const char* const ptr, const size_type count)
    : myData()
{
    //運算newMyRes的大小
    for (int i = 1;; i++)
        if (count + 1 <= 16 * i) {
            myData.myRes = 16 * i - 1;
            break;
        }

    //當myRes大於15要製作一個動態陣列
    if (count > 15)
        myData.bx.ptr = new char[myData.myRes]();

    myData.mySize = count;//修改size以符合條件
    for (int i = 0; i < count; i++)
        myData.myPtr()[i] = ptr[i];//一項一項放進myPtr
}

// fill constructor
// Fills the string with "count" consecutive copies of character ch.
string::string(const size_type count, const char ch)
    : myData()
{
    //運算newMyRes的大小
    for (int i = 1;; i++)
        if (count + 1 <= 16 * i) {
            myData.myRes = 16 * i - 1;
            break;
        }

    //當myRes大於15要製作一個動態陣列
    if (count > 15)
        myData.bx.ptr = new char[myData.myRes]();

    myData.mySize = count;//修改size以符合條件
    for (int i = 0; i < count; i++)
        myData.myPtr()[i] = ch;//一項一項放進myPtr
}

// copy constructor
// Constructs a copy of "right".
string::string(const string& right)
    : myData()
{
    //運算newMyRes的大小
    for (int i = 1;; i++)
        if (right.size() + 1 <= 16 * i) {
            myData.myRes = 16 * i - 1;
            break;
        }

    //當myRes大於15要製作一個動態陣列
    if (right.size() > 15)
        myData.bx.ptr = new char[myData.myRes]();

    myData.mySize = right.size(); //修改size以符合條件
    for (int i = 0; i < right.size(); i++)
        myData.myPtr()[i] = right.myData.myPtr()[i];//一項一項放進myPtr
}

// String destructor
// Destroys the string object.
// Deallocates all the storage capacity allocated by the string.
string::~string() 
{
    if (myData.myRes > 15)
        delete[] myData.bx.ptr;
}

//   static const size_type npos = static_cast< size_type >( -1 );

// String assignment
// Assigns a new value to the string, replacing its current contents.
string& string::operator=(const string& right)
{
    if (this != &right)
    {
        resize(right.myData.mySize);//將原動態陣列的size改為right的size
        for (int i = 0; i < right.myData.mySize; i++)
            myData.myPtr()[i] = right.myData.myPtr()[i];//將right陣列中的值存進動態陣列中
    }

    return *this;
}

// Erases the contents of the string, which becomes an empty string
// (with a length of 0 characters).
void string::clear()  // erase all
{
    myData.mySize = 0;
    myData.myPtr()[0] = value_type();
}

// Returns an iterator pointing to the first character of the string.
string::iterator string::begin() 
{
    return myData.myPtr();
}

// Returns an iterator pointing to the first character of the string.
string::const_iterator string::begin() const 
{
    return const_iterator(myData.myPtr());
}

// Returns an iterator pointing to the past-the-end character of the string.
// The past-the-end character is a theoretical character
// that would follow the last character in the string.
// It shall not be dereferenced.
// If the object is an empty string, this function returns the same as string::begin.
string::iterator string::end() 
{
    return myData.myPtr() + static_cast<difference_type>(myData.mySize);
}

// Returns an iterator pointing to the past-the-end character of the string.
// The past-the-end character is a theoretical character
// that would follow the last character in the string.
// It shall not be dereferenced.
// If the object is an empty string, this function returns the same as string::begin.
string::const_iterator string::end() const 
{
    return const_iterator(myData.myPtr() + static_cast<difference_type>(myData.mySize));
}

// Returns a const_iterator pointing to the first character of the string.
string::const_iterator string::cbegin() const 
{
    return begin();
}

// Returns a const_iterator pointing to the past-the-end character of the string.
// If the object is an empty string, this function returns the same as string::cbegin.
// The value returned shall not be dereferenced.
string::const_iterator string::cend() const 
{
    return end();
}

// Returns a reference to the character at position pos in the string.
string::reference string::operator[](const size_type off) 
{
    if (off > myData.mySize)
    {
        cout << "string subscript out of range\n";
        exit(1);
    }

    return myData.myPtr()[off];
}

// Returns a reference to the character at position pos in the string.
string::const_reference string::operator[](const size_type off) const 
{
    if (off > myData.mySize)
    {
        cout << "string subscript out of range\n";
        exit(1);
    }

    return myData.myPtr()[off];
}

// Appends character ch to the end of the string, increasing its length by one.
void string::push_back(char ch)
{
    resize(myData.mySize + 1);
    myData.myPtr()[myData.mySize - 1] = ch;
}

// Erases the last character of the string,
// effectively reducing its length by one.
void string::pop_back() 
{
    if (myData.mySize > 0)
        --myData.mySize;
}

// Returns a reference to the first character of the string.
// This function shall not be called on empty strings.
string::reference string::front() 
{
    return myData.myPtr()[0];
}

// Returns a reference to the first character of the string.
// This function shall not be called on empty strings.
string::const_reference string::front() const 
{
    return myData.myPtr()[0];
}

// Returns a reference to the last character of the string.
// This function shall not be called on empty strings.
string::reference string::back() 
{
    return myData.myPtr()[myData.mySize - 1];
}

// Returns a reference to the last character of the string.
// This function shall not be called on empty strings.
string::const_reference string::back() const 
{
    return myData.myPtr()[myData.mySize - 1];
}

// Returns a pointer to an array that contains a null-terminated sequence of characters
// (i.e., a C-string) representing the current value of the string object.
const char* string::c_str() const 
{
    return myData.myPtr();
}

// Returns the length of the string, in terms of bytes.
// This is the number of actual bytes that conform the contents of the string,
// which is not necessarily equal to its storage capacity.
string::size_type string::size() const 
{
    return myData.mySize;
}

// Resizes the string to a length of "newSize" characters.
// If "newSize" is smaller than the current string length,
// the current value is shortened to its first "newSize" character,
// removing the characters beyond the "newSize"th.
// If "newSize" is greater than the current string length,
// the current content is extended by inserting at the end
// as many characters as needed to reach a size of "newSize".
// The new elements are initialized as copies of ch,
void string::resize(const size_type newSize, const char ch)
{
    //規則
    size_type newMyRes = myData.myRes * 3 / 2;
    if (newMyRes < (newSize / 16) * 16 + 15)
        newMyRes = (newSize / 16) * 16 + 15;

    //newSize > myRes時，必須新建一個陣列，因為capacity容量不足
    if (newSize > myData.myRes) {
        pointer ptr = new value_type[newMyRes]();
        for (size_type i = 0; i < myData.mySize; i++)
            ptr[i] = myData.myPtr()[i];//存放舊陣列中的字元
        for (size_type i = myData.mySize; i < newSize; i++)
            ptr[i] = ch;//補上新的字元ch
        if (myData.myRes > 15)
            delete[]myData.bx.ptr;//myRes > 15時，代表其bx.ptr有動態陣列，若不刪除會造成電腦卡慢
        myData.myRes = newMyRes;//改變myRes
        myData.bx.ptr = ptr;//將bx.ptr指向ptr，則新陣列即可被bx.ptr給呼叫
    }

    else
        for (size_type i = myData.mySize; i < newSize; i++)
            myData.myPtr()[i] = ch;//若是newSize < mySize，for迴圈不會進去；反之，for迴圈協助我們在原本的字串後面補上ch所存放的字符

    myData.mySize = newSize;//最後才將mySize改為正確的size
}

// Returns the size of the storage space currently allocated for the string,
// expressed in terms of bytes.
// This capacity is not necessarily equal to the string length.
// It can be equal or greater, with the extra space allowing the object
// to optimize its operations when new characters are added to the string.
string::size_type string::capacity() const 
{
    return myData.myRes;
}

// Returns whether the string is empty (i.e. whether its length is 0).
bool string::empty() const 
{
    return myData.mySize == 0;
}

// compare [ 0, size() ) with right for equality
bool string::equal(const string& right) const 
{
    if (right.myData.mySize != myData.mySize)
        return false;

    for (int i = myData.mySize - 1; i >= 0; i--)
        if (right.myData.myPtr()[i] != myData.myPtr()[i])
            return false;

    return true;
}

bool operator==(const string& left, const string& right) 
{
    return left.equal(right);
}