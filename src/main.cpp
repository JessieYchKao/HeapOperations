
#include "heap.h"
#include <iostream>

using namespace std;

template <typename T>
void get_actions(Heap<T> &heap)
{
    char action;
    T value;
    do
    {
        cout << "Insert(I)/Remove(R)/Size(S)/Print(P)/Exit(E): ";
        cin >> action;
        switch (action)
        {
        case 'I':
            cout << "Enter the value of the node: ";
            cin >> value;
            heap.insert(value);
            break;
        case 'R':
            heap.remove();
            break;
        case 'S':
            cout << "The size of the heap: " << heap.size() << endl;
            break;
        case 'P':
            cout << "Heap: " << endl;
            heap.print_heap();
            break;
        case 'E':
            break;
        default:
            cout << "Unsupported action, please try again." << endl;
            break;
        }
    } while (action != 'E');
}

int main()
{
    cout << "Enter the type for Heap (int/double/string): ";
    string type;
    cin >> type;
    cout << "Is it a max heap (Y/N): ";
    char is_max;
    cin >> is_max;
    if (type == "int")
    {
        Heap<int> heap(is_max == 'Y' ? true : false);
        get_actions(heap);
    }
    else if (type == "double")
    {
        Heap<double> heap(is_max == 'Y' ? true : false);
        get_actions(heap);
    }
    else if (type == "string")
    {
        Heap<string> heap(is_max == 'Y' ? true : false);
        get_actions(heap);
    }
    else
    {
        cout << "Unsupported type";
        return 1;
    }
    return 0;
}