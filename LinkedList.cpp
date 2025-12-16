#include <iostream>
#include <string>
using namespace std;
class MusicGenreList
{
  public:
    struct Node
    {
        string genre;
        Node* next;
    };
     Node* head;
     MusicGenreList()
     {
        head = NULL;
      }

    void insertGenre(string genre)
     {
        Node* newNode = new Node();
        newNode->genre = genre;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            cout << "Genre added successfully\n";
            return;
         }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        cout << "Genre added successfully\n";
    }

    void deleteGenre(string genre)
     {
      if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->genre == genre)
        {
            Node* del = head;
            head = head->next;
            delete del;
            cout << "Genre deleted\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->genre != genre)
            temp = temp->next;

        if (temp->next == NULL)
        {
            cout << "Genre not found\n";
        }
        else
        {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            cout << "Genre deleted\n";
        }
    }

    void searchGenre(string genre)
    {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL)
        {
            if (temp->genre == genre)
            {
                cout << "Genre found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Genre not found\n";
    }

    void countGenres()
    {
        int count = 0;
        Node* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << "Total genres: " << count << endl;
    }

    void clearList()     // for complexity
    {
        Node* temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "All genres cleared\n";
    }

    void displayGenres()
    {
        if (head == NULL)
        {
            cout << "No genres available\n";
            return;
        }

        Node* temp = head;
        cout << "Music Genres:\n";
        while (temp != NULL)
        {
            cout << "- " << temp->genre << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    MusicGenreList list;
    int choice;
    string genre;
    do{
        cout << "\n--- MUSIC GENRE MENU ---\n";
        cout << "1. Insert Genre\n";
        cout << "2. Delete Genre\n";
        cout << "3. Search Genre\n";
        cout << "4. Count Genres\n";
        cout << "5. Display Genres\n";
        cout << "6. Clear All Genres\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 7)
        {
            cout << "Invalid choice. Enter 1-7: ";    //for validation
            cin.clear(); 
            cin.ignore(1000, '\n');
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter genre name: ";
            cin.ignore();
            getline(cin, genre);
            if (!genre.empty())
                list.insertGenre(genre);
            else
                cout << "Invalid input.\n";           //for validation
            break;

        case 2:
            cout << "Enter genre to delete: ";
            cin.ignore();
            getline(cin, genre);
            list.deleteGenre(genre);
            break;

        case 3:
            cout << "Enter genre to search: ";
            cin.ignore();
            getline(cin, genre);
            list.searchGenre(genre);
            break;

        case 4:
            list.countGenres();
            break;

        case 5:
            list.displayGenres();
            break;

        case 6:
            list.clearList();
            break;

        case 7:
            cout << "Exiting program\n";
            break;
        }
    } 
    while (choice != 7);
    return 0;
}
