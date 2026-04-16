#include<iostream>
#include<cctype>

int main()
{
    char ch;
    while (std::cin.get(ch) && ch!='@'){
        if (!(isalnum(ch)&&(!isalpha(ch)))){
            if (isupper(ch)) ch=tolower(ch);
            else if(islower(ch)) ch=toupper(ch);
            std::cout << ch;
        }
    }
    return 0;
}