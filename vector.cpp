#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

int main() 
{
  string artistName;
  cout << "Enter an artist name: ";
    getline(cin, artistName);

    vector<char> v;
for (int i = 0; i < artistName.length(); i++) 
{
     v.push_back(artistName[i]);
}

  int left = 0;
   int right = v.size() - 1;

while (left < right) 
    {
     char a = tolower(v[left]);
    char b = tolower(v[right]);

     if (a == ' ') 
        { 
            left++; 
            continue; 
        }
       if (b == ' ') 
        { 
            right--;
             continue;
             }

        if (a != b) 
        {
          cout << "Not a palindrome";
          return 0;
        }
        left++;
        right--;
      }
     cout << "Palindrome";
    return 0;
}
