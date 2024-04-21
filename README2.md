# M&Z Library

M&Z Library is a library management system designed to facilitate the organization and access of books in a library. The program allows you to save, retrieve, and manage books using a text file. It also provides functionality to manage queues of customers waiting for a book.

## Programming Language

- **C++**: The program is implemented in C++, a language known for its performance, efficiency, and support for `OOP` and procedural programming paradigms. The language allows for low-level memory management and precise control over data structures, making it a suitable choice for developing a library management system.

## Data Structures Used

- **Singly Linked Lists**: Used to manage a collection of books, providing dynamic allocation and efficient insertion and deletion operations.
- **Queue**: Utilized for managing queues for each book, tracking customer reservations and providing information about each book's availability.

## Books

The code allows you to save your books in a text file and then access them using the program. You can add or delete books, and these changes will be effectively reflected in the text file. You can view all the books and check the number of a specific book by typing its name.

## Queue

The code connects a queue for each book that can be accessed using its index or name.

Within the queue, there are multiple actions you can perform, such as:

- Adding a person to the queue.
- Checking whose turn it is to use the book.
- Checking a customer's number in line and how many people are ahead of them.
- Checking the status of the whole queue.

If you return to the main menu and enter the queue again, all of the data will still be reserved.

## Other

Destructors were used at the end to delete all dynamically created variables. **Note**: It is recommended to exit using the number `0` as mentioned in the program. If the program does not stop correctly, destructors will not activate, and there will be no clean-up.

## Queue and Book Management System

### Classes

#### Queue Class

- `class queue`: Represents a queue for customers waiting for a book.
- Properties:
    - `name_of_customer`: Name of the customer in the queue.
    - `next`: Pointer to the next queue node.

#### Node Class

- `class node`: Represents a book node in the linked list.
- Properties:
    - `nameofbook`: Name of the book.
    - `next`: Pointer to the next book node.
    - `first_bkqueue`: Pointer to the first node in the book queue.
    - `myque`: Pointer to a `linkedlistforqueue` instance.
- Destructor:
    - Deletes the book queue when the node is destroyed.

#### LinkedListForQueue Class

- `class linkedlistforqueue`: Represents a queue for a specific book.
- Properties:
    - `mybook`: Pointer to the book node this queue is associated with.
    - `last_bkqueue`: Pointer to the last node in the book queue.
- Methods:
    - `returnmybook()`: Returns the associated book node.
    - `setbook(book)`: Sets the associated book node.
    - `isempty()`: Checks if the queue is empty.
    - `counter()`: Returns the number of customers in the queue.
    - `ENQUEUE(noc)`: Adds a customer to the queue.
    - `DEQUEUE()`: Removes the first customer from the queue.
    - `whoami()`: Displays the current user of the book.
    - `getstatus()`: Displays the status of the queue.
    - `whenismyturn(myname)`: Displays the customer's position in the queue.

#### LinkedListForBooks Class

- `class linkedlistforbooks`: Represents a linked list of books.
- Properties:
    - `head`: Pointer to the head of the linked list.
- Methods:
    - `forbookdata()`: Loads book data from a file.
    - `isempty()`: Checks if the book list is empty.
    - `insertfirst(nob)`: Inserts a book at the beginning of the list.
    - `display()`: Displays all books in the list.
    - `counter()`: Returns the number of books in the list.
    - `returnnumObook(key)`: Displays the number of times a book appears in the list.
    - `insertlast(nob)`: Inserts a book at the end of the list.
    - `insertmiddle(nob, pos)`: Inserts a book at a specific position in the list.
    - `deletefirst()`: Deletes the first book from the list.
    - `deletelast()`: Deletes the last book from the list.
    - `deletemiddle(pos)`: Deletes a book at a specific position in the list.
    - `deletebyname(nameofbook)`: Deletes a book by its name.
    - `returnbook(pos)`: Returns a book at a specific position in the list.
    - `returnbook(book)`: Returns a book by its name.
- Destructor:
    - Saves book data to a file when the list is destroyed.

### Main Functions

#### Insert Options for Book

- Function: `insertoptionsforbook(books)`
    - Allows the user to insert books at the beginning, end, or a specific position in the list.

#### Delete Options for Book

- Function: `deleteoptionsforbook(books)`
    - Allows the user to delete books from the beginning, end, or a specific position in the list.

### Queue Management

- Function: `QUEUE(queue, choice)`
    - Allows the user to manage the queue for a specific book, such as reserving, finishing, or checking the queue.

### Main Menu

- Function: `mainmenu(books, choice)`
    - Provides a main menu for managing books and queues.

## Main Function

- Function: `main()`
    - Initializes the linked list of books and displays a welcome message.
    - Loops through the main menu to allow user interaction.

## Contact

For any questions or feedback, You can contact me via email at [mahmoudnaif788@gmail.com](mailto:mahmoudnaif788@gmail.com).
