// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <random>
#include <cctype>

struct Review {
    std::string title;
    int rating;
    double price;
};

using namespace std;
bool operator<(const Review & r1, const Review & r2);
bool operator<(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2);
bool worseThan(const Review & r1, const Review & r2);
bool worseThan2(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2);
bool lowerPriceThan(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);
void ShowReview2(const shared_ptr<Review> & rr);
void ShowMenu()
{
    cout << "\nChoose one of the following orders"<<endl;
    cout << "a: default order" << endl
         << "b: name order" << endl
         << "c: rating up" << endl
         << "d: rating dowm" << endl
         << "e: price up" << endl
         << "f: price dowm" << endl
         << "q: Quit" << endl;        
}

int main()
{

    vector<Review> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(temp);
    vector<shared_ptr<Review>> spbooks(books.size());
    for (auto i = spbooks.begin();i!=spbooks.end();i++){
        *i=make_shared<Review>(*(books.begin()+(i-spbooks.begin())));
    }
    // if (books.size() > 0)
    // {
    //     cout << "Thank you. You entered the following "
    //          << books.size() << " ratings:\n"
    //           << "Rating\tBook\n";
    //     for_each(books.begin(), books.end(), ShowReview);

    //     sort(books.begin(), books.end());
    //     cout << "Sorted by title:\nRating\tBook\n";
    //     for_each(books.begin(), books.end(), ShowReview);

    //     sort(books.begin(), books.end(), worseThan);
    //     cout << "Sorted by rating:\nRating\tBook\n";
    //     for_each(books.begin(), books.end(), ShowReview);

    //     std::random_device rd; //目前应该这样使用
    //     std::mt19937 gen(rd());
    //     shuffle(books.begin(), books.end(),gen);
    //     cout << "After shuffling:\nRating\tBook\n";
    //     for_each(books.begin(), books.end(), ShowReview);
    // }
    // else
    //     cout << "No entries. ";
    if (spbooks.size()>0){
        char ch;
        cout << "Thank you. You entered the following " << spbooks.size() << " books:\n"
             << "Book\tRating\tPrice\n";
        for_each(spbooks.begin(),spbooks.end(),ShowReview2);
        ShowMenu();
        ch = cin.get();
        ch = tolower(ch);
        while (cin.get()!='\n') continue;
        while (ch != 'q')
        {
            if (ch == 'a') for_each(books.begin(),books.end(),ShowReview);
            else{
                switch(ch){
                    case 'b':sort(spbooks.begin(),spbooks.end());break;
                    case 'c':sort(spbooks.begin(),spbooks.end(),worseThan2);break;
                    case 'd':sort(spbooks.rbegin(),spbooks.rend(),worseThan2);break;
                    case 'e':sort(spbooks.begin(),spbooks.end(),lowerPriceThan);break;
                    case 'f':sort(spbooks.rbegin(),spbooks.rend(),lowerPriceThan);break;
                }
                for_each(spbooks.begin(),spbooks.end(),ShowReview2);
            }
            ShowMenu();
            ch = cin.get();
            ch = tolower(ch);
            while (cin.get()!='\n') continue;
        }
        
    }else cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}

bool operator<(const Review & r1, const Review & r2)
{
    if (r1.title < r2.title)
        return true;
    else if (r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else if (r1.title == r2.title && r1.rating == r2.rating  && r1.price < r2.price)
        return true;
    else
        return false;
}

bool worseThan(const Review & r1, const Review & r2)
{
    if (r1.rating < r2.rating)
        return true;
    else
        return false;
}


bool worseThan2(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2)
{
    if (pr1->rating < pr2->rating)
    return true;
    else
    return false;
}

bool lowerPriceThan(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2)
{
    if (pr1->price < pr2->price)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.title << "\t" << rr.rating << "\t" << rr.price<<  std::endl; 
}

void ShowReview2(const shared_ptr<Review> & rr)
{
    std::cout << rr->title << "\t" << rr->rating << "\t" << rr->price<<  std::endl; 
}

bool operator<(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2)
{
    if (pr1 ->title < pr2->title) return true;
    else return false;
}

