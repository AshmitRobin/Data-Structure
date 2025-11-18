#include <iostream>
#include <string>
#include <cctype>
using namespace std;
    int main() 
    {
      string artistName;
      cout <<"Enter an artist name: ";
    getline(cin, artistName);

      const char *left=artistName.c_str();
      const char *right=artistName.c_str() + artistName.length()-1;

    while (left < right) 
   {
     char a=tolower(*left);
     char b=tolower(*right);

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
        }cout << "Palindrome";
    return 0; }