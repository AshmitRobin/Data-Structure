#include <iostream>
#include <list>
#include <string>
using namespace std;

class MusicList
{
    list<string> songs;

public:
    void insertSong(const string& song)
    {
        songs.push_back(song);
        cout << "Song inserted successfully\n";
    }

    void deleteSong(const string& song)
    {
        if (songs.empty())
        {
            cout << "List is empty\n";
            return;
        }

        for (auto it = songs.begin(); it != songs.end(); ++it)
        {
            if (*it == song)
            {
                songs.erase(it);
                cout << "Song deleted successfully\n";
                return;
            }
        }
        cout << "Song not found\n";
    }

    void searchSong(const string& song)
    {
        int pos = 1;
        for (auto it = songs.begin(); it != songs.end(); ++it)
        {
            if (*it == song)
            {
                cout << "Song found at position " << pos << endl;
                return;
            }
            pos++;
        }
        cout << "Song not found\n";
    }

    void countSongs()
    {
        cout << "Total number of songs: " << songs.size() << endl;
    }

    void displaySongs()
    {
        if (songs.empty())
        {
            cout << "No songs in the list\n";
            return;
        }

        cout << "Music List:\n";
        for (const auto& song : songs)
            cout << "- " << song << endl;
    }
};

int main()
{
    MusicList ml;
    int choice;
    string song;

    do
    {
        cout << "1. Insert Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Search Song\n";
        cout << "4. Count Songs\n";
        cout << "5. Display Songs\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        while (choice < 1 || choice > 6)
        {
            cin.clear();
            cout << "Invalid choice: ";           //validation
            cin >> choice;
        }
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "Enter song name: ";
            getline(cin, song);
            if (!song.empty())
                ml.insertSong(song);
            else
                cout << "Invalid input\n";
            break;

        case 2:
            cout << "Enter song to delete: ";
            getline(cin, song);
            ml.deleteSong(song);
            break;

        case 3:
            cout << "Enter song to search: ";
            getline(cin, song);
            ml.searchSong(song);
            break;

        case 4:
            ml.countSongs();
            break;

        case 5:
            ml.displaySongs();
            break;

        case 6:
            cout << "Exiting program\n";
            break;
        }
    } 
    while (choice != 6);
    return 0;
}
