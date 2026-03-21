// Include the iostream library for input/output operations (cout, cin)
#include <iostream>
// Include the string library to work with string data type
#include <string>
// Use the standard namespace to avoid writing std:: before standard functions
using namespace std;

// Define the Book class with member variables and functions
class Book {
// Private section - accessible only within the class
private:
    // Member variable to store the title of the book
    string title;
    // Member variable to store the name of the book's author
    string author;
    // Member variable to store the price of the book
    double price;

// Public section - accessible from outside the class
public:
    // Constructor function: initializes a Book object with title, author, and price
    Book(string t, string a, double p) {
        // Assign the parameter title to the member variable title
        title = t;
        // Assign the parameter author to the member variable author
        author = a;
        // Assign the parameter price to the member variable price
        price = p;
    }

    // Getter function to retrieve the price of the book
    // const means this function doesn't modify any member variables
    double getPrice() const {
        // Return the price of the book
        return price;
    }

    // Getter function to retrieve the title of the book
    // const means this function doesn't modify any member variables
    string getTitle() const {
        // Return the title of the book
        return title;
    }

    // Getter function to retrieve the author of the book
    // const means this function doesn't modify any member variables
    string getAuthor() const {
        // Return the author of the book
        return author;
    }

    // Function to display all book details in a formatted manner
    void display() const {
        // Output the title label and book's title
        cout << "Title: " << title << endl;
        // Output the author label and book's author
        cout << "Author: " << author << endl;
        // Output the price label and book's price with dollar sign
        cout << "Price: $" << price << endl;
    }
}; // End of Book class definition

// Function to find and display the most expensive book among three books
// Takes three Book objects as parameters
void findMostExpensiveBook(Book book1, Book book2, Book book3) {
    // Initialize mostExpensive with the first book
    Book mostExpensive = book1;

    // Check if the second book's price is greater than the current most expensive
    if (book2.getPrice() > mostExpensive.getPrice()) {
        // If yes, update mostExpensive to book2
        mostExpensive = book2;
    }
    // Check if the third book's price is greater than the current most expensive
    if (book3.getPrice() > mostExpensive.getPrice()) {
        // If yes, update mostExpensive to book3
        mostExpensive = book3;
    }

    // Print a header for the result
    cout << "\n=== Most Expensive Book ===" << endl;
    // Call the display function to show the most expensive book's details
    mostExpensive.display();
}

// Main function - entry point of the program
int main() {
    // Create book1 object with title, author, and price (10.99)
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 10.99);
    // Create book2 object with title, author, and price (12.50)
    Book book2("To Kill a Mockingbird", "Harper Lee", 12.50);
    // Create book3 object with title, author, and price (11.75)
    Book book3("1984", "George Orwell", 11.75);

    // Print header for displaying all books
    cout << "=== All Books ===" << endl;
    // Print separator for book 1
    cout << "\nBook 1:" << endl;
    // Call display function to show book1's details
    book1.display();

    // Print separator for book 2
    cout << "\nBook 2:" << endl;
    // Call display function to show book2's details
    book2.display();

    // Print separator for book 3
    cout << "\nBook 3:" << endl;
    // Call display function to show book3's details
    book3.display();

    // Call the function to find and display the most expensive book among the three
    findMostExpensiveBook(book1, book2, book3);

    // Return 0 to indicate successful program execution
    return 0;
}
