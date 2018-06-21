#include <iostream>
using namespace std;

class inventory
{
private:
    struct stackNode
    {
        int serialNum;
        int manufactDate;
        int lotNum;
        stackNode *next;
    };
    stackNode *top;

public:
    //constructor
    inventory()
    {
        top = nullptr;
    }
    //destructor
    ~inventory();

    void push(int);
    void pop (int &);
    bool isEmpty();
};

inventory::~inventory()
{
    stackNode *nodePtr = nullptr, *nextNode = nullptr;

    //position  nodePtr to the top of the stack
    nodePtr = top;

    //traverse the list deleting each node
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}
void inventory::push(int num)
{
    stackNode *newNode = nullptr; // points to new node

    //allocate a new node and store a number there
    newNode = new stackNode;

    newNode->serialNum = num;

    //if there are no nodes in the list, make newNode the first node
    if (isEmpty())
    {

        top = newNode;
        newNode->next = nullptr;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}
void inventory::pop (int &num)
{

    stackNode *temp = nullptr; // temporary pointer
    if (isEmpty())
    {
        cout<<"There are no parts in the bin."<<endl;
    }
    else
    {
        num=top->serialNum;
        temp=top->next;
        delete top;
        top = temp;
    }
}
bool inventory::isEmpty()
{
    bool status;

    if(!top)
        status=true;
    else
        status=false;

    return status;
}
int main()
{
    int catchVar;
    int serialNum;

    inventory stack;

    while(serialNum != 0)
        {
    cout<<"Please enter your serial number. Enter 0 to exit. : ";
    cin>>serialNum;

    if(serialNum == 0)
    {
     break;
    }
    else {
    stack.push(serialNum);

    cout<<"Popping last entered serial number: ";
    stack.pop(catchVar);
    cout<<catchVar<<endl;
    }
        }
    return 0;
}
