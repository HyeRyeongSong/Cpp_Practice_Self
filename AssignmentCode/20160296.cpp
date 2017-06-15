#include <iostream>

using namespace std;

template <class T> class Chain; // forward declaration

template <class T>
class ChainNode
{
    friend class Chain<T>;
private:
    T data;
    ChainNode<T> *link;
public:
    ChainNode(T element = 0, ChainNode* next = 0)
    // 0 is the default value for element and next
    {data=element; link=next;}
};

template <class T>
class Chain {
public:
    Chain()
    {
        first = 0;
        last = 0;
    }; // constructor initializing first to 0

    ~Chain()
    {
        for(ChainNode<T>* chainNode = first; chainNode != last; )
        {
            ChainNode<T>* deletedNode = chainNode;
            chainNode = chainNode->link;
            delete deletedNode;
        }
        delete last;
    }


    T Front()
    {
        return first->data;
    }

    T Back()
    {
        return last->data;
    }

    ChainNode<T>* Get(int iIndex)
    {
        ChainNode<T>* getNode = first;
        for(int i = 0; i<iIndex; ++i)
        {
            if(getNode->link == 0)
            {
                cout<< "존재하지 않는 인덱스입니다" <<endl;
                return 0;
            }
            getNode = getNode->link;
        }
        return getNode;
    }

    T GetData(int iIndex)
    {
        ChainNode<T>* getNode = first;
        for(int i = 0; i<iIndex; ++i)
        {
            if(getNode->link == 0)
            {
                cout<< "존재하지 않는 인덱스입니다" <<endl;
                return 0;
            }
            getNode = getNode->link;
        }
        return getNode->data;
    }


    void InsertFront(T element){
        if(first)
        {
            ChainNode<T> *newNode = new ChainNode<T>(element);
            newNode->link = first;
            first = newNode;
        }
        else first = last = new ChainNode<T>(element);
    }

    void InsertBack(const T& e)
    {
        if (first) {// nonempty chain
            last->link = new ChainNode<T>(e);
            last = last->link;
        }
        else first = last = new ChainNode<T>(e);
    }

    void InsertbyIndex(const T& e, int iIndex)
    {
        if(first)
        {
            ChainNode<T>* newNode = new ChainNode<T>(e, Get(iIndex));
            ChainNode<T>* preNode = Get(iIndex-1);
            preNode->link = newNode;
        }
        else InsertFront(e);
    }

    void Delete(ChainNode<T> *x, ChainNode<T> *y=0)
    {
        if (x == first) first = first->link;
        else if(x == last)
        {
            last = y;
            y->link = x->link;
        }
        else y->link = x->link;
        delete x;
    }

    void DeleteFront()
    {
        Delete(first);
    }

    void DeleteBack()
    {
        ChainNode<T>* pre;
        for(ChainNode<T>* searchNode = first; searchNode !=last; )
        {
            pre = searchNode;
            searchNode = searchNode->link;
        }
        Delete(last, pre);
    }

    void DeletebyIndex(int iIndex)
    {
        Delete(Get(iIndex), Get(iIndex-1));
    }


    void PrintAllNode()
    {
        ChainIterator * chainIterator = new ChainIterator();
        for(*chainIterator = begin(); *chainIterator != end(); ++chainIterator)
        {
            cout << chainIterator->operator->() << "  ";
        }

        cout <<endl;
    }

    ChainIterator begin() {return ChainIterator(first);}
    ChainIterator end() {return ChainIterator(0);}

    class ChainIterator {
    public:
        // typedefs required by C++ for a forward iterator omitted

        // constructor
        ChainIterator(ChainNode<T>* startNode = 0)
        {current = startNode;}

        // dereferencing operators
        T& operator*() const {return current->data;}
        T* operator->() const {return &current->data;}

        // increment
        ChainIterator& operator++()   // preincrement
        {current = current->link; return *this;}
        ChainIterator operator++(int) // postincrement
        {
            ChainIterator old = *this;
            current = current->link;
            return old;
        }

        // equality testing
        bool operator!=(const ChainIterator right) const
        {return current != right.current;}
        bool operator==(const ChainIterator right) const
        {return current == right.current;}

    private:
        ChainNode<T>* current;
    };


private:
    ChainNode<T> *first;
    ChainNode<T> *last;
};

int main()
{
    Chain<int> intlist;

    for(int i=0; i<9; ++i)
    {
        intlist.InsertBack(i+1);
    }

    intlist.PrintAllNode();

    intlist.InsertFront(0);

    intlist.PrintAllNode();

    intlist.InsertBack((10));

    intlist.PrintAllNode();

    cout << intlist.Front() << endl;

    cout << intlist.Back() << endl;

    cout << intlist.GetData(2) << endl;

    intlist.DeleteFront();

    intlist.PrintAllNode();

    intlist.DeleteBack();

    intlist.PrintAllNode();

    intlist.InsertbyIndex(100, 3);

    intlist.PrintAllNode();

    intlist.DeletebyIndex(6);

    intlist.PrintAllNode();

    return 0;
}