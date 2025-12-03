#include <iostream>
#include<string>
using namespace std;
class MusicStack 
{
  public:
   int stack[5];
    int size;
    int top;

    MusicStack(int s)
     {
        size = s;
        top = -1;
    }

    void push(int x) 
    {
      if (isFull()) 
        {
          cout << "Stack full, cannot add more records\n";
        } 
     else 
        {
            stack[++top] = x;
          cout << "Added Music Record ID: " << x << endl;
        }
    }

    int pop() 
    {
      if (isEmpty()) 
        {
          cout << "Stack empty Nothing to remove\n";
            return -1;
        }
         else 
        {
          cout << "Removed Music Record ID: " << stack[top] << endl;
            return stack[top--];
        }
    }

  int peek()
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty, No top record\n";
            return -1;
        }
        return stack[top];
    }
 
   bool isEmpty() 
    {
        return top == -1;
    }

  bool isFull() 
    {
        return top == size - 1;
    }

  int count() 
    {
        return top + 1;
    }

    void clear() 
    {
        top = -1;
        cout << "All music records cleared\n";
    }

    void display()
     {
      if (isEmpty()) 
        {
            cout << "Stack empty\n";
            return;
        }

        cout << "\nMusic Records in Stack:\n";
        for (int i = top; i >= 0; i--)
         {
            cout << "| " << stack[i] << " |\n";
        }
        cout << "TOP\n";
    }
};

int main() 
{
    int size;
    cout << "Enter number of music records (1 to 5): ";
    cin >> size;
    while (cin.fail() || size < 1 || size > 5)
     {
        cout << "Invalid size! Enter between 1 and 5: ";
        cin.clear();
        cin.ignore();
        cin >> size;
    }
    MusicStack ms(size);
    int choice, id;
    do 
    {
        cout << "\n--- MUSIC RECORD STACK MENU ---\n";
        cout << "1. Add Music Record (PUSH)\n";
        cout << "2. Remove Top Record (POP)\n";
        cout << "3. View Top Record (PEEK)\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Check if Stack is Full\n";
        cout << "6. Display All Music Records\n";
        cout << "7. Count Records\n";     
        cout << "8. Clear All Records\n";  
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 9) 
        {
            cout << "Invalid choice! Enter 1-9: ";
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
        switch (choice) 
        {
        case 1:
            cout << "Enter Music Record ID: ";
            cin >> id;
            while (cin.fail() || id <= 0) 
            {
                cout << "Invalid ID! Enter a positive number: ";
                cin.clear();
                cin.ignore();
                cin >> id;
            }
            ms.push(id);
            break;

        case 2:
            ms.pop();
            break;

        case 3:
            id = ms.peek();
            if (id != -1)
                cout << "Top Music Record ID: " << id << endl;
            break;

        case 4:
            cout << (ms.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
            break;

        case 5:
            cout << (ms.isFull() ? "Stack is full\n" : "Stack is not full\n");
            break;

        case 6:
            ms.display();
            break;

        case 7:
            cout << "Total Records: " << ms.count() << endl;
            break;

        case 8:
            ms.clear();
            break;

        case 9:
            cout << "Exiting\n";
            return 0;
        }

    } while(choice != 9);

    return 0;
}
