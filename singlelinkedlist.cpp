#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
template <typename type>

class slinkedlist
{
    // Creating Node
    struct Node
    {
        type data;
        Node *Next;
    };

    // Assiging NULL to Begin
    Node *Begin = NULL, *Begin2 = NULL;

public:
    int position;

    // Inserting At Begin
    void insertbeg(type value)
    {
        Node *tmp = new Node;
        tmp->data = value;
        tmp->Next = Begin;
        Begin = tmp;
        // count++;
    }

    // Inserting At End
    void insertEnd(type value)
    {
        Node *tmp = new Node;
        tmp->data = value;
        tmp->Next = NULL;
        if (Begin == NULL)
        {
            Begin = tmp;
        }
        else
        {
            Node *ptr = Begin;
            while (ptr->Next != NULL)
            {
                ptr = ptr->Next;
            }
            ptr->Next = tmp;
        }
        // count++;
    }

    // Inserting After
    void insertAfterposition()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {
            int count = length();
            cout << "Enter Position :";
            cin >> position;

            if (position > count)
            {
                cout << "Invalid Position.." << endl;
            }

            else
            {
                Node *tmp = new Node;
                int i = 1;
                type value;

                cout << "Enter Value : ";
                cin >> value;
                Node *p = Begin;
                while (i < position)
                {
                    p = p->Next;
                    i++;
                }
                tmp->Next = p->Next;
                tmp->data = value;
                p->Next = tmp;
                // count++;
            }
        }
    }

    // Insert Through Data
    void insertafterdata()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {
            type value, item;
            cout << "Enter After Value : ";
            cin >> value;
            Node *ptr = Begin;

            while (ptr != NULL && ptr->data != value)
            {
                ptr = ptr->Next;
            }

            if (ptr == NULL)
            {
                cout << "Element Containing Value Not Found..." << endl;
            }

            else
            {
                cout << "Enter Value To Be Inserted : ";
                cin >> item;
                Node *tmp = new Node;
                tmp->Next = ptr->Next;
                tmp->data = item;
                ptr->Next = tmp;
            }
        }
    }

    // Deleting Node At Begin
    void deleteBeg()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {
            Node *tmp;
            tmp = Begin;
            Begin = Begin->Next;
            tmp->Next = NULL;
            delete tmp;
            // count--;
        }
    }

    void deleteEnd()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {
            if (Begin->Next == NULL)
            {
                Node *tmp = Begin;
                Begin = Begin->Next;
                tmp->Next = NULL;
                delete tmp;
                // count--;
            }

            else
            {
                Node *ptr = Begin->Next, *preptr;
                while (ptr->Next != NULL)
                {
                    preptr = ptr;
                    ptr = ptr->Next;
                }

                preptr->Next = NULL;
                delete ptr;
                // count--;
            }
        }
    }

    // Deleting Node Through Position
    void Deletethroughposition()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {
            int count;
            cout << "Enter Location : ";
            cin >> position;
            count = length();

            if (position > count || position <= 0)
            {
                cout << "Invalid Position.." << endl;
            }

            else if (position == 1)
            {
                Node *tmp = Begin;
                Begin = Begin->Next;
                tmp->Next = NULL;
                delete tmp;
                // count--;
            }

            else
            {
                Node *p, *q;
                int i = 1;
                p = Begin;
                while (i < position - 1)
                {
                    p = p->Next;
                    i++;
                }
                q = p->Next;
                p->Next = q->Next;
                q->Next = NULL;

                delete q;

                // count--;
            }
        }
    }

    // Deleting Node Through Data
    void deletetd()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {
            int item;
            cout << "Enter Item No : ";
            cin >> item;

            if (Begin->data == item)
            {
                Node *ptr = Begin;
                Begin = Begin->Next;
                ptr->Next = NULL;
                delete ptr;
                // count--;
            }

            else
            {
                Node *ptr1 = Begin, *ptr2 = Begin->Next;

                while (ptr2 != NULL && ptr2->data != item)
                {
                    ptr1 = ptr2;
                    ptr2 = ptr2->Next;
                }

                if (ptr2 == NULL)
                {
                    cout << "No Element Found " << endl;
                }

                else
                {
                    ptr1->Next = ptr2->Next;
                    ptr2->Next = NULL;
                    delete ptr2;
                    // count--;
                }
            }
        }
    }

    // Linear Searching In Unsorted List
    void searchunsorted()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {
            int flag = 0;
            type value;
            cout << "Enter Value : ";
            cin >> value;
            Node *ptr = Begin;
            while (ptr != NULL)
            {
                if (ptr->data == value)
                {
                    cout << "Element Found At Address : " << ptr << endl;
                    flag = 1;
                }

                ptr = ptr->Next;
            }

            if (flag == 0)
            {
                cout << value << " Is Not Present In List." << endl;
            }
        }
    }

    // searching in sorted list
    void searchsorted()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {
            type value;
            cout << "Enter Value : ";
            cin >> value;
            Node *ptr = Begin;

            while (ptr != NULL)
            {
                if (ptr->data == value)
                {
                    cout << "Element Found At Address : " << ptr << endl;
                    break;
                }

                else if (ptr->data > value)
                {
                    cout << value << " Is Not Present In List." << endl;
                    break;
                }

                ptr = ptr->Next;
            }
        }
    }
    // Sorting The List
    void sort()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {
            Node *i = Begin, *j = Begin->Next;
            type tmp;

            while (i != NULL)
            {
                j = i->Next;
                while (j != NULL)
                {
                    if (i->data > j->data)
                    {
                        tmp = i->data;
                        i->data = j->data;
                        j->data = tmp;
                    }
                    j = j->Next;
                }
                i = i->Next;
            }
        }
    }

    // Finding length Of List
    int length()
    {
        int count = 0;
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {

            Node *ptr = Begin;

            while (ptr != NULL)
            {
                count++;
                ptr = ptr->Next;
            }

            cout << "The Length Of List is : " << count << endl;
        }

        return count;
    }

    // Traversing The List
    void traverse()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {
            Node *ptr = Begin;
            while (ptr != NULL)
            {
                cout << "->  |" << ptr->data << "  " << ptr->Next << "|   ";
                ptr = ptr->Next;
            }
        }
    }

    // To Print Splitted List
    void traversesplit()
    {
        Node *ptr = Begin2;
        cout << "\n\n Splitted ";
        while (ptr != NULL)
        {
            cout << "-> |" << ptr->data << "  " << ptr->Next << "|   ";
            ptr = ptr->Next;
        }
    }

    void max()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else
        {
            type Max = Begin->data;
            Node *ptr = Begin->Next;

            while (ptr != NULL)
            {
                if (ptr->data > Max)
                {
                    Max = ptr->data;
                }

                ptr = ptr->Next;
            }

            cout << "Maximum value In List Is : " << Max << endl;
        }
    }

    void split()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty....." << endl;
        }

        else if (Begin->Next == NULL)
        {
            cout << "Cannot Split One Node" << endl;
        }

        else
        {
            Node *ptr = Begin;
            int count = 0;
            while (ptr != NULL)
            {
                count++;
                ptr = ptr->Next;
            }
            int i = 1;
            int middle = count / 2;
            // Node *Begin2 = NULL; Important I have assigned this value goballly for printing...
            ptr = Begin;

            while (i < middle)
            {
                ptr = ptr->Next;
                i++;
            }

            Begin2 = ptr->Next;
            ptr->Next = NULL;
        }
    }
};

int main()
{
    slinkedlist<int> obj;
    int value;
    int ch, position;

    while (true)
    {
        cout << "\n\nLinked List :  \n 1.InsertBegin \n 2.InsertEnd \n 3.InsertAfterPosition \n4.InsertAfterData \n 5.Delete At Begining \n 6.Delete At End \n7.DeleteThroughdata \n8.Delete Through Position \n9.Search Unsorted \n10.Search Sorted \n11.Sorting \n12.Traversal \n13.Length \n14.Max \n15.Split" << endl;
        cout << "\nEnter Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter Value : ";
            cin >> value;
            obj.insertbeg(value);
            obj.traverse();
            break;

        case 2:
            cout << "Enter Value : ";
            cin >> value;
            obj.insertEnd(value);
            obj.traverse();
            break;

        case 3:
            obj.insertAfterposition();
            obj.traverse();
            break;

        case 4:
            obj.insertafterdata();
            obj.traverse();
            break;

        case 5:
            obj.deleteBeg();
            obj.traverse();
            break;

        case 6:
            obj.deleteEnd();
            obj.traverse();
            break;

        case 7:
            obj.deletetd();
            obj.traverse();
            break;

        case 8:
            obj.Deletethroughposition();
            obj.traverse();
            break;

        case 9:
            obj.searchunsorted();
            obj.traverse();
            break;

        case 10:
            obj.searchsorted();
            obj.traverse();
            break;

        case 11:
            obj.sort();
            obj.traverse();
            break;

        case 12:
            obj.traverse();
            break;

        case 13:
            obj.length();
            break;

        case 14:
            obj.max();
            break;

        case 15:
            obj.split();
            obj.traverse();
            obj.traversesplit();
            break;
        }
    }

    return 0;
}