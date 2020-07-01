// ex10.cpp -- using smart pointer and STL function
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
    std::string title;
    int rating;
    float price;
};

bool operator<(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2);
bool worseThan(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2);
bool FillReview(Review & rr);

int main()
{
    using namespace std;

    vector<shared_ptr<Review>> books;

    while (1) {
	shared_ptr<Review> temp (new Review);
	if (FillReview(*temp))
	    books.push_back(temp);
	else
	    break;
    }
    
    if (books.size() > 0) {
	cout << "You entered the following "
	     << books.size() << " ratings:\n"
	     << "Rating\tBook\n";
        cout << "\nRating\tPrice\tBook\n";
        for (auto x: books)
	    cout << x->rating << '\t' << x->price << '\t' << x->title << endl;
	sort(books.begin(), books.end());
	cout << "Sorted by title:\nRating\tPrice\tBook\n";
        for (auto x: books)
	    cout << x->rating << '\t' << x->price << '\t' << x->title << endl;
	sort(books.begin(), books.end(), worseThan);
	cout << "Sorted by rating:\nRating\tPrice\tBook\n";
        for (auto x: books)
	    cout << x->rating << '\t' << x->price << '\t' << x->title << endl;
    }

    return 0;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter the book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
	return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
	return false;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
	return false;
    while (std::cin.get() != '\n')
	continue;
    return true;
}

bool worseThan(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2)
{
    if (r1->rating > r2->rating)
	return true;
    else
	return false;
}
bool operator<(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2)
{
    if (r1->title > r2->title)
	return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
	return true;
    else if (r1->title == r2->title && r1->rating == r2->rating && r1->price < r2->price)
	return true;
    else
	return false;
}
