// filename: StackType.h
#include <stdexcept>
using std::runtime_error;
// MAX_ITEMS: the maximum number of items on the stack. 
const int MAX_ITEMS = 5;

// Exception class thrown by Push when stack is full.
class FullStack : public runtime_error
{
    public:
        // Add exception message(Stack is Full!) when the constructor is initialized
		FullStack() : runtime_error("push item into full stack is invalid"){}
};

// Exception class thrown by Pop and Top when stack is emtpy.
class EmptyStack : public runtime_error
{
    public:
        // Add exception message(Stack is Empty!) when the constructor is initialized
		EmptyStack() : runtime_error("pop item in empty stack is invalid"){}
};

class StackType
{
    public:

        // Class constructor.
		StackType();

        // Function: Determines whether the stack is full.
        bool IsFull() const;

        // Function: Determines whether the stack is empty.
        bool IsEmpty() const;

        // Function: Adds newItem to the top of the stack.
        // If (stack is full), FullStack exception is thrown;
        // otherwise, newItem is at the top of the stack.
        void Push(char item);

        // Function: Removes top item from the stack.
        // If (stack is empty), EmptyStack exception is thrown;
        // otherwise, top element has been removed from stack.
        void Pop();

        // Function: Returns a copy of top item on the stack.
        // If (stack is empty), EmptyStack exception is thrown;
        // otherwise, top element has been removed from stack.
        char Top();

    private:
        int top;//作為陣列的第幾格做判斷
        char items[MAX_ITEMS];		
};

