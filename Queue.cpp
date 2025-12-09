#include <iostream>
#include<string>
#include<queue>
using namespace std;

class MusicQueue 
{
public:
    int arr[10];     
    int frontIndex;
    int rearIndex;
    int size;

    MusicQueue(int s) 
    {
        if (s > 10) s = 10;
        size = s;
        frontIndex = -1;
        rearIndex = -1;
    }

    bool isEmpty() 
    {
        return (frontIndex == -1);
    }

    bool isFull() 
    {
        return (rearIndex + 1 == size);
    }

    void enqueue(int n) 
    {
        if (isFull()) 
        {
            cout << "Queue Overflow, Cannot insert\n";
            return;
        }
        if (isEmpty()) 
        {
            frontIndex = rearIndex = 0;
        } 
        else 
        {
            rearIndex++;
        }
        arr[rearIndex] = n;
        cout << "Inserted: " << n << endl;
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue Underflow, Nothing to remove\n";
            return;
        }

        cout << "Removed: " << arr[frontIndex] << endl;

        if (frontIndex == rearIndex) 
        {
            frontIndex = rearIndex = -1;
        } 
        else
         {
            frontIndex++;
        }
    }

    int front() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty. No front element.\n";
            return -1;
        }
        return arr[frontIndex];
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue Elements: ";
        for (int i = frontIndex; i <= rearIndex; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int count() {                              //for complexity

        if (isEmpty()) return 0;
        return (rearIndex - frontIndex + 1);
    }
};

int main() 
{
    int size;
    cout << "Enter queue size (1-10): ";
    cin >> size;

    while (cin.fail() || size < 1 || size > 10)
     {
        cout << "Invalid size, Enter between 1 and 10: ";          //Validation
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> size;
    }

    MusicQueue q(size);
    int choice, val;

    do 
    {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. View Front\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display Queue\n";
        cout << "7. Count Elements\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 8) 
        {
            cout << "Invalid choice, Enter between 1-8: ";       //Validation
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> choice;
        }

        switch (choice) 
        {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                while (cin.fail())
                 {
                    cout << "Invalid input, Enter a valid number: ";         
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cin >> val;
                }
                q.enqueue(val);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                val = q.front();
                if (val != -1)
                    cout << "Front element: " << val << endl;
                break;

            case 4:
                cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;

            case 5:
                cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n");
                break;

            case 6:
                q.display();
                break;

            case 7:
                cout << "Total elements: " << q.count() << endl;
                break;

            case 8:
                cout << "Exiting \n";
                break;
        }
    } 
    while (choice != 8);
    return 0;
}
