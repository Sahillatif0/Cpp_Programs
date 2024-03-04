# Lab06

## Task-01

Consider a banking system where you have a `BankAccount` class representing individual accounts. Each BankAccount object contains a pointer to an array of transactions representing the account history.\
For that, Create class `BankAccount` which contains the private member variables `int accountId`, `double balance` to store account information. `int* transactionHistory` is a pointer to an array storing transaction history and int `numTransactions` used to stores the number of transactions.

### Also class have following Public Member Functions:

+ **Constructor** that initializes account information and allocates memory for the transaction
history, copying provided transactions.
+ **Copy constructor** that creates a new BankAccount object as a copy of another BankAccount
object, including its transaction history.
+ **Destructor** that deallocates memory allocated for the transaction history.
+ **display() Function:** function to output the account details including the account ID, balance, and transaction history.
+ **updateTransactionHistory() Function:** This function updates the transaction history of the BankAccount object. It deletes the existing transaction history, allocates memory for the new transaction history, and copies the new transaction data into the allocated memory.

### Main Function:

+ Create a BankAccount object with initial account details and transaction history.
+ Create a copy of the original account.
+ Displays the details of both the original and copied accounts using the display() function.
+ Now , call updateTransactionHistory() Function to update the transaction history of the original account to observe the changes.
+ Now call the display function to see the changes.

## Task-02

Consider that You're working on Images to handle images in your graphics application. Each Image object contains a pointer to image data stored in memory. You are asked to create `Image` Class: The Image class represents an image with `width`, `height`, and `image data` as private. The data member represents the image data stored in memory. It's a pointer to a block of memory where the actual pixel values of the image are stored.

### Also class have following Public Member Functions:

+ Create Constructor: Constructor that initializes the width, height, and data pointer. It dynamically allocates memory for the image data and copies the provided data. By copying the provided image data, the Image class creates an independent copy of the data. This means that modifications made to the original image data outside the class won't affect the internal representation of the image within the Image object.
+ Create Copy constructor that creates a new Image object as a copy of another Image object.
  + It allocates memory for the image data and copies the data from the original image.
+ Class must have Destructor that deallocates the memory allocated for the image data.
+ Create void display(): Displays the image data.
+ Create the updateData function: that takes original image data and updates those values which are 0 are less than 0 with any random value between the range of 1<=255

### Main Function:

+ Create an Image object with dimensions 2x3 and initialize it with sample data.
+ Creates a copy of the original image.
+ Displays the data of both the original and copied images using the display() function.
+ After that call the updateData function and then call the display() function again to verify that changes are made in both original and copied data.

## Task-03

You have been hired to develop a program for a hair salon that keeps track of appointments made, total earnings, and the average cost per appointment using static members and functions.

Your task is to define a class that represents an appointment at the salon. The class should have private data members that store information about the appointment, and static data members that keep track of the total number of appointments made and the total earnings from all appointments.

### Also class have following Public Member Functions:

+ Define a constructor for the appointment class that takes arguments for the appointment details and updates the static data members accordingly. Additionally, you should define public member functions that allow access to the appointment details.
+ Finally, you should define a static function that calculates and returns the average cost of all the appointments made. This function should use the static data members to perform the calculation.

### Main Function: 

In the main function, you should create several instances of the appointment class with different appointment details, and then call the static function to calculate the average cost of all the appointments made. This will allow you to verify that the program is correctly keeping track of appointments and earnings

## Task-04

You have been asked to write a program that calculates the batting average and strike rate for a cricket player. The program should take as input the total number of runs scored by the player and the total number of balls faced, and should output the batting average and strike rate.

+ To calculate the batting average, divide the total runs scored by the number of times the player has been dismissed (i.e., gotten out). To calculate the strike rate, divide the total runs scored by the total number of balls faced and multiply the result by 100.

+ To implement this program, create an inline function that takes the total number of runs scored and the number of times the player has been dismissed as arguments, and returns the batting average.
+ Create another inline function that takes the total number of runs scored and the total number of balls faced as arguments, and returns the strike rate.

>Demonstrate the functions using main function

## Task-05

Consider a School Management System. You are required to create two classes, `Student` and `Course`. Each student can enroll in multiple courses. The Course class should have the following properties: `course code (string)`, `course name (string)`, and `course credit hours (integer)`. The Student class should have the following properties: `student ID (string)`, `student name (string)`, and a `list of enrolled courses (an array of Course objects)`.

### The Student class should have the following member functions:

+ A constructor that initializes the student ID and name.
+ A function named "enroll" that takes a Course object as input and adds it to the list of enrolled courses for the student.
+ A function named "drop" that takes a Course object as input and removes it from the list of enrolled courses for the student.
+ A function named "getTotalCreditHours" that returns the total number of credit hours for all courses the student is currently enrolled in.
+ A function named "printEnrolledCourses" that prints out the course code, name, and credit hours for all courses the student is currently enrolled in.
