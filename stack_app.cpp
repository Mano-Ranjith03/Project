#include<iostream>
#include<string>
using namespace std;

#define max 4;

template <class type>
class STACK
{
    type a[5];  // Fixed size for the stack
    static int TOP;
public:
    STACK()
    {
        for (int i = 0; i < 5; i++) { a[i] = 0; }  // Initialize array elements to 0
        TOP = 0;  // Initialize the static variable
    }
    void push(type x)
    {
        if (TOP >= 5)
            cout << "\x1b[31m***************Stack overflow*********************\x1b[0m\n";
        else
        {
            a[TOP++] = x;
            cout << "Element Pushed into stack\n";
        }
    }
    void display()
    {
        if (TOP == 0)
        {
            cout << "\x1b[31m--------------Stack is Empty----------------------\x1b[0m\n";
        }
        else
        {
            for (int i = TOP - 1; i >= 0; i--)
                cout << a[i] << " ";
            cout << endl;
        }
    }
    void pop()
    {
        if (TOP > 0) {
            if constexpr (!std::is_same<type, std::string>::value)
            {
                a[TOP - 1] = 0; // Reset element to 0 for non-string types
                cout << "Element Poped\n";
            }
            else
            {
                a[TOP - 1].clear();  // Clear the string for string types
                cout << "Element Poped\n";
            }
            TOP--;
        }
        else
        {
            cout << "\x1b[31m++++++++++++++++Stack underflow+++++++++++++++++\x1b[0m\n";
        }
    }
    void call(void);
};

template <class type>
int STACK<type>::TOP = 0;

int main()
{
    int op, opl, count = 0;
    STACK<int> intStack;
    STACK<char> charStack;
    STACK<float> floatStack;
    STACK<double> doubleStack;
    STACK<string> stringStack;

    while (1)
    {
        cout << "\x1b[36mEnter choice\n\x1b[0m\x1b[31m1)int   2)char  3)float   4)double   5)string    6)exit\n\x1b[0m";
        cin >> op;
        if (opl == op && opl <= 6)
        {
            int opt;
            cout << "\x1b[32m1)contine old stack  2)New stack\n\x1b[0m";
            cin >> opt;
            if (opt == 1)
            {
                switch (op)
                {
                    case 1: intStack.call(); break;
                    case 2: charStack.call(); break;
                    case 3: floatStack.call(); break;
                    case 4: doubleStack.call(); break;
                    case 5: stringStack.call(); break;
                    case 6: exit(0); break;
                    default: cout << "invalid option\n"; break;
                }
                continue;
            }
        }
        opl = op;
        switch (op)
        {
            case 1:
            {
                STACK<int> ob;
                ob.call();
                intStack = ob;
                count = 0;
            } break;
            case 2:
            {
                STACK<char> ob;
                ob.call();
                charStack = ob;
                count = 0;
            } break;
            case 3:
            {
                STACK<float> ob;
                ob.call();
                floatStack = ob;
                count = 0;
            } break;
            case 4:
            {
                STACK<double> ob;
                ob.call();
                doubleStack = ob;
                count = 0;
            } break;
            case 5:
            {
                STACK<string> ob;
                ob.call();
                stringStack = ob;
                count = 0;
            } break;
            case 6:
            {
                exit(0);
            } break;
            default:
            {
                cout << "invalid option: ";
                count++;
                if (count < 3)
                    cout << 3 - count << " chances left" << endl;
            } break;
        }

        if (count == 3)
        {
            cout << "\x1b[33m Thank you for using our Stack Application\x1b[0m\n";
            break;
        }
    }
}

template <class type>
void STACK<type>::call(void)
{
    int op1;
    cout << typeid(type).name() << "\x1b[35m stack ready to use\n\x1b[0m";
    while (1)
    {
        cout << "\x1b[36mEnter menu\t\x1b[0m\n\x1b[33m1)push\t2)pop\t3)display_stack\t4)main menu\n\x1b[0m";
        cin >> op1;
        if (op1 == 4)
            break;
        switch (op1)
        {
            case 1:
            {
                type x;
                cout << "\x1b[35mEnter int to push:\x1b[0m" << endl;
                cin >> x;
                push(x); break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3: display(); break;
        }
    }
}
