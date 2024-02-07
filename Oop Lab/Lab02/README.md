# Lab tasks

1. **You are tasked with creating a C++ function that swaps the elements between two variables.\
Implement a recursive function named `recursiveSwap` that takes two variables as parameters and
recursively swaps their values.** \
e.g. Input : `a = 5, b = 10`    Output : `a = 10, b = 5`

1. **Imagine you are tasked with creating a program to manage a library&#39;s book inventory. Each book
has attributes such as `title`, `author`, `publication year`, and `genre`. Design a struct that effectively
represents a book as a real-world entity. Then, write a simple program in a language of your choice that utilizes this struct to demonstrate the creation, modification, and display of book information.**

    - Extend the program to manage multiple books in an array.
    - Implement a function to search for a book by title or author.
    - Allow the user to input new books and update existing book information interactively.

1. **You are given an array of integers and a target sum. Your task is to implement a recursive function in C++ that determines if there exists a subset of the array whose elements add up to the given target sum.**

    - Write a recursive function named `hasSubsetSum` that takes `an array of integers`, the `array's size`, and `a target sum` as input and returns a boolean indicating whether there exists a subset with the given sum.
    - The function signature should be: `bool hasSubsetSum(int arr[], int size, int targetSum)`.

1. **You are tasked with implementing a simple Student Registration System in C++. Define two structures, `Register` and `Student`, where Register contains attributes `courseId` and `courseName`, and Student inherits from Register while having additional attributes such as `studentId`, `firstName`, `lastName`, `cellNo`, and `email`. Your goal is to create an array of Student structures to store information for five students.**\
    Write a C++ program that accomplishes the following tasks:
    1. Implement the `Register` and `Student` structures.
    1. Inherit the Register structure in the Student structure.
    1. Create an array of Student structures to store information for `5` students.
    1. Take input for each student, including their `courseId`, `courseName`, `studentId`, `firstName`, `lastName`, `cellNo`, and `email`.
    1. Display the information for all `5` students.

1. **You are tasked with building a simple product management system for an online store.**
    - Create a function that allows the addition of a new product to the system. The function should take parameters such as product `name`, `price`, `quantity`, and any other relevant details.
    - Implement a function that takes a `product ID` as input and displays detailed information about the product, including its `name`, `price`, `quantity` in stock, and any other relevant details.
    - Design a function that enables the update of product information. It should take a product `ID` as well as the new details `(e.g., updated price, quantity, etc.)` and modify the existing product&#39;s information accordingly.
    - Create a function that removes a product from the system based on its product `ID`. Ensure that the inventory is updated after the removal.

1. **You are required to write a C++ program that calculates the Least `Common Multiple (LCM)` and `Greatest Common Divisor (GCD)` of two numbers. Implement two separate recursive functions, `calculateLCM` and `calculateGCD`, each handling the corresponding task.**
