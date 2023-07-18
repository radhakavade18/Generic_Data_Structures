#include <iostream>
using namespace std;

template <class T>
struct NodeS // Structure for singly Linear and Singly Circular
{
    T data;
    struct NodeS *next;
};

template <class T>
struct NodeD // Structure for doubly Linear and doubly Circular
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};
// structure is generic then we cant write typedef to the structure

//-----------------------------------------------------------------------
// class of sinlgy linear linked list
//-----------------------------------------------------------------------
// if we are using any generic element in class then class should be generic
template <class T>
class SinglyLL
{
private:
    struct NodeS<T> *First;
    int iCount;

public:
    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    NodeS<T> *temp = First;
    if (First == NULL)
    {
        cout << "Nothing to display as Linked list is empty \n";
        return;
    }
    cout << "Elements of Linked list is \n";
    while (temp != NULL)
    {
        cout << "|" << temp->data << "| ->";
        temp = temp->next;
    }
    cout << "NULL \n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    NodeS<T> *newn = new NodeS<T>;
    NodeS<T> *temp = First;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int pos)
{
    if ((pos < 0) || (pos > iCount + 1))
    {
        cout << "Invalid position \n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(No);
    }
    else if (pos == (iCount + 1))
    {
        InsertLast(No);
    }
    else
    {
        NodeS<T> *temp = First;
        NodeS<T> *newn = new NodeS<T>;
        newn->data = No;
        newn->next = NULL;

        for (int iCnt = 0; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeS<T> *temp = First;
        First = First->next;
        delete temp;

        iCount--;
    }
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeS<T> *temp = First;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    if ((pos < 0) || (pos > iCount))
    {
        cout << "Invalid position \n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp = First;
        NodeS<T> *tempX = NULL;

        for (int iCnt = 0; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}

//-----------------------------------------------------------------------
// class of sinlgy circular linked list
//-----------------------------------------------------------------------
template <class T>
class SinglyCircularLL
{
private:
    struct NodeS<T> *First;
    struct NodeS<T> *Last;
    int iCount;

public:
    SinglyCircularLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyCircularLL<T>::SinglyCircularLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCircularLL<T>::Display()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "Nothing to display as Linked list is empty \n";
        return;
    }
    cout << "Elements of Linked list is \n";
    NodeS<T> *temp = First;
    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout << "|" << temp->data << "| <->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int SinglyCircularLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCircularLL<T>::InsertFirst(T No)
{
    NodeS<T> *newn = new NodeS<T>;
    newn->next = NULL;
    newn->data = No;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCircularLL<T>::InsertLast(T No)
{
    NodeS<T> *newn = new NodeS<T>;
    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = Last->next;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCircularLL<T>::InsertAtPos(T No, int pos)
{
    if ((pos < 1) || (pos > iCount + 1))
    {
        cout << "Invalid position \n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(No);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        NodeS<T> *temp = First;
        NodeS<T> *newn = new NodeS<T>;
        newn->data = No;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCircularLL<T>::DeleteFirst()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        NodeS<T> *temp = First;
        First = First->next;
        delete temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCircularLL<T>::DeleteLast()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        NodeS<T> *temp = First;
        while (temp->next != Last)
        {
            temp = temp->next;
        }
        delete Last;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCircularLL<T>::DeleteAtPos(int pos)
{
    if ((pos < 1) || (pos > iCount))
    {
        cout << "Invalid position \n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp = First;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        NodeS<T> *tempX = NULL;
        tempX = temp->next;

        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}

//-----------------------------------------------------------------------
// class of doubly linear linked list
//-----------------------------------------------------------------------
template <class T> // if we are using any generic element then class should be generic
class DoublyLL
{
private:
    struct NodeD<T> *First;
    struct NodeD<T> *Last;
    int iCount;

public:
    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    NodeD<T> *temp = First;
    if (First == NULL)
    {
        cout << "Nothing to display as Linked list is empty \n";
        return;
    }
    cout << "Elements of Linked list is \n";
    while (temp != NULL)
    {
        cout << "|" << temp->data << "| =>";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    NodeD<T> *newn = new NodeD<T>;
    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    NodeD<T> *newn = new NodeD<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        NodeD<T> *temp = First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int pos)
{
    if ((pos < 0) || (pos > iCount + 1))
    {
        cout << "Invalid parameters \n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(No);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        NodeD<T> *newn = new NodeD<T>;
        newn->next = NULL;
        newn->prev = NULL;
        newn->data = No;

        NodeD<T> *temp = First;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next->prev = newn;
        newn->next = temp->next;

        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        NodeD<T> *temp = First;
        First = First->next;
        delete temp;
        First->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        NodeD<T> *temp = First;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    if ((pos < 0) || (pos > iCount))
    {
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = First;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        NodeD<T> *tempX = NULL;
        tempX = temp->next;

        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete tempX;

        iCount--;
    }
}

//-----------------------------------------------------------------------
// class of doubly circular linked list
//-----------------------------------------------------------------------
template <class T>
class DoublyCircularLL
{
private:
    struct NodeD<T> *First;
    struct NodeD<T> *Last;
    int iCount;

public:
    DoublyCircularLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyCircularLL<T>::DoublyCircularLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCircularLL<T>::Display()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "Nothing to display as Linked list is empty \n";
        return;
    }

    cout << "Elements of Linked list is \n";
    NodeD<T> *temp = First;
    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout << "|" << temp->data << "| <->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyCircularLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCircularLL<T>::InsertFirst(T No)
{
    NodeD<T> *newn = new NodeD<T>;
    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        First->prev = newn;
        newn->next = First;

        First = newn;
    }
    Last->next = First;
    First->prev = Last;
    iCount++;
}

template <class T>
void DoublyCircularLL<T>::InsertLast(T No)
{
    NodeD<T> *newn = new NodeD<T>;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = No;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;

        Last = newn;
    }
    Last->next = First;
    First->prev = Last;
    iCount++;
}

template <class T>
void DoublyCircularLL<T>::InsertAtPos(T No, int pos)
{
    if ((pos < 0) || (pos > iCount + 1))
    {
        cout << "Invalid parameters \n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(No);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        NodeD<T> *newn = new NodeD<T>;
        newn->next = NULL;
        newn->prev = NULL;
        newn->data = No;

        NodeD<T> *temp = First;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next->prev = newn;
        newn->next = temp->next;

        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

template <class T>
void DoublyCircularLL<T>::DeleteFirst()
{
    if (iCount == 0)
    {
        return;
    }
    if (iCount == 1)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;

        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

template <class T>
void DoublyCircularLL<T>::DeleteLast()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete First->prev;

        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

template <class T>
void DoublyCircularLL<T>::DeleteAtPos(int pos)
{
    if ((pos < 0) || (pos > iCount))
    {
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = First;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        NodeD<T> *tempX = NULL;
        tempX = temp->next;

        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete tempX;

        iCount--;
    }
}

int main()
{
    // -------- Singly LL integer --------
    cout<<"---------SINGLY LINEAR LINKED LIST---------\n";
    SinglyLL<int> sllobj1;

    sllobj1.InsertFirst(51);
    sllobj1.InsertFirst(21);
    sllobj1.InsertFirst(11);

    sllobj1.InsertLast(101);
    sllobj1.InsertLast(111);
    sllobj1.Display();
    cout << "Count of elements are :" << sllobj1.Count() << "\n";

    sllobj1.InsertAtPos(55, 4);
    sllobj1.Display();
    cout << "Count of elements are :" << sllobj1.Count() << "\n";

    sllobj1.DeleteAtPos(4);
    sllobj1.Display();
    cout << "Count of elements are :" << sllobj1.Count() << "\n";

    sllobj1.DeleteFirst();
    sllobj1.DeleteLast();
    sllobj1.Display();
    cout << "Count of elements are :" << sllobj1.Count() << "\n";

    cout<<"\n";

    // -------- Singly ll character ---------
    SinglyLL<char> sllobj2;

    sllobj2.InsertFirst('a');
    sllobj2.InsertFirst('b');
    sllobj2.InsertFirst('c');

    sllobj2.InsertLast('d');
    sllobj2.InsertLast('e');
    sllobj2.Display();
    cout << "Count of elements are :" << sllobj2.Count() << "\n";

    sllobj2.InsertAtPos('f', 4);
    sllobj2.Display();
    cout << "Count of elements are :" << sllobj2.Count() << "\n";

    sllobj2.DeleteAtPos(4);
    sllobj2.Display();
    cout << "Count of elements are :" << sllobj2.Count() << "\n";

    sllobj2.DeleteFirst();
    sllobj2.DeleteLast();
    sllobj2.Display();
    cout << "Count of elements are :" << sllobj2.Count() << "\n";

    cout<<"\n";
    cout<<"------------------------------------------------------------------ \n";
    cout<<"\n";

    // -------- Singly Circular LL integer --------
    cout<<"---------SINGLY CIRCULAR LINKED LIST---------\n";
    SinglyCircularLL<int> sclobj2;

    sclobj2.InsertFirst(51);
    sclobj2.InsertFirst(21);
    sclobj2.InsertFirst(11);

    sclobj2.InsertLast(101);
    sclobj2.InsertLast(111);
    sclobj2.Display();
    cout << "Count of elements are :" << sclobj2.Count() << "\n";

    sclobj2.InsertAtPos(55, 4);
    sclobj2.Display();
    cout << "Count of elements are :" << sclobj2.Count() << "\n";

    sclobj2.DeleteAtPos(4);
    sclobj2.Display();
    cout << "Count of elements are :" << sclobj2.Count() << "\n";

    sclobj2.DeleteFirst();
    sclobj2.DeleteLast();
    sclobj2.Display();
    cout << "Count of elements are :" << sclobj2.Count() << "\n";

    cout<<"\n";

    // -------- Singly Circular LL character ---------
    SinglyCircularLL<char> sclobj1;

    sclobj1.InsertFirst('a');
    sclobj1.InsertFirst('b');
    sclobj1.InsertFirst('c');

    sclobj1.InsertLast('d');
    sclobj1.InsertLast('e');
    sclobj1.Display();
    cout << "Count of elements are :" << sclobj1.Count() << "\n";

    sclobj1.InsertAtPos('f', 4);
    sclobj1.Display();
    cout << "Count of elements are :" << sclobj1.Count() << "\n";

    sclobj1.DeleteAtPos(4);
    sclobj1.Display();
    cout << "Count of elements are :" << sclobj1.Count() << "\n";

    sclobj1.DeleteFirst();
    sclobj1.DeleteLast();
    sclobj1.Display();
    cout << "Count of elements are :" << sclobj1.Count() << "\n";

    cout<<"\n";
    cout<<"------------------------------------------------------------------ \n";
    cout<<"\n";

    // -------- Doubly LL integer --------
    cout << "---------DOUBLY LINEAR LINKED LIST---------\n";
    DoublyLL<int> dllobj1;

    dllobj1.InsertFirst(51);
    dllobj1.InsertFirst(21);
    dllobj1.InsertFirst(11);

    dllobj1.InsertLast(101);
    dllobj1.InsertLast(111);
    dllobj1.Display();
    cout << "Count of elements are :" << dllobj1.Count() << "\n";

    dllobj1.InsertAtPos(55, 4);
    dllobj1.Display();
    cout << "Count of elements are :" << dllobj1.Count() << "\n";

    dllobj1.DeleteAtPos(4);
    dllobj1.Display();
    cout << "Count of elements are :" << dllobj1.Count() << "\n";

    dllobj1.DeleteFirst();
    dllobj1.DeleteLast();
    dllobj1.Display();
    cout << "Count of elements are :" << dllobj1.Count() << "\n";

    cout << "\n";

    // -------- Doubly ll character ---------
    DoublyLL<char> dllobj2;

    dllobj2.InsertFirst('a');
    dllobj2.InsertFirst('b');
    dllobj2.InsertFirst('c');

    dllobj2.InsertLast('d');
    dllobj2.InsertLast('e');
    dllobj2.Display();
    cout << "Count of elements are :" << dllobj2.Count() << "\n";

    dllobj2.InsertAtPos('f', 4);
    dllobj2.Display();
    cout << "Count of elements are :" << dllobj2.Count() << "\n";

    dllobj2.DeleteAtPos(4);
    dllobj2.Display();
    cout << "Count of elements are :" << dllobj2.Count() << "\n";

    dllobj2.DeleteFirst();
    dllobj2.DeleteLast();
    dllobj2.Display();
    cout << "Count of elements are :" << dllobj2.Count() << "\n";

    cout<<"\n";
    cout<<"------------------------------------------------------------------ \n";
    cout<<"\n";

    // -------- Doubly Circulat LL integer --------
    cout << "---------DOUBLY CIRCULAR LINKED LIST---------\n";
    DoublyCircularLL<int> dclobj1;

    dclobj1.InsertFirst(51);
    dclobj1.InsertFirst(21);
    dclobj1.InsertFirst(11);

    dclobj1.InsertLast(101);
    dclobj1.InsertLast(111);
    dclobj1.Display();
    cout << "Count of elements are :" << dclobj1.Count() << "\n";

    dclobj1.InsertAtPos(55, 4);
    dclobj1.Display();
    cout << "Count of elements are :" << dclobj1.Count() << "\n";

    dclobj1.DeleteAtPos(4);
    dclobj1.Display();
    cout << "Count of elements are :" << dclobj1.Count() << "\n";

    dclobj1.DeleteFirst();
    dclobj1.DeleteLast();
    dclobj1.Display();
    cout << "Count of elements are :" << dclobj1.Count() << "\n";

    cout << "\n";

    // //-------- Doubly ll character ---------
    DoublyCircularLL<char> dclobj2;

    dclobj2.InsertFirst('a');
    dclobj2.InsertFirst('b');
    dclobj2.InsertFirst('c');

    dclobj2.InsertLast('d');
    dclobj2.InsertLast('e');
    dclobj2.Display();
    cout << "Count of elements are :" << dclobj2.Count() << "\n";

    dclobj2.InsertAtPos('f', 4);
    dclobj2.Display();
    cout << "Count of elements are :" << dclobj2.Count() << "\n";

    dclobj2.DeleteAtPos(4);
    dclobj2.Display();
    cout << "Count of elements are :" << dclobj2.Count() << "\n";

    dclobj2.DeleteFirst();
    dclobj2.DeleteLast();
    dclobj2.Display();
    cout << "Count of elements are :" << dclobj2.Count() << "\n";

    cout<<"\n";
    cout<<"------------------------------------------------------------------ \n";
    cout<<"\n";

    // char ChoiceLL = '\0';
    // char dataType[20] = '\0';

    // cout << "---------------------------------------------------- \n";
    // cout << "A : Singly Linear Linked List \n";
    // cout << "B : Singly Circular Linked List \n";
    // cout << "C : Doubly Linear Linked List  \n";
    // cout << "D : Doubly Circular Linked List  \n";
    // cout << "---------------------------------------------------- \n";

    // cout << "Select Linked list that you want to play with \n";
    // cin >> ChoiceLL;

    // cout << "Enter Data types for the linked list elements \n";
    // cin >> dataType;

    // if (ChoiceLL == 'A')
    // {
    //     SinglyLL<dataType> sllobj;

    //     cout << "------------ SINGLY LINEAR LINKED LIST ------------\n";

    //     sllobj.InsertFirst(51);
    //     sllobj.InsertFirst(21);
    //     sllobj.InsertFirst(11);

    //     sllobj.InsertLast(101);
    //     sllobj.InsertLast(111);
    //     sllobj.Display();
    //     cout << "Count of elements are :" << sllobj.Count() << "\n";
    // }

    // int iValue = 0;
    // int iRet = 0;
    // int iPosition = 0;

    return 0;
}