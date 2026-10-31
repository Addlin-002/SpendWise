# SpendWise — Personal Expense Tracker

SpendWise is a command-line expense tracking application developed using C++. It helps users record daily expenses, view transactions, calculate total spending, analyze expenses by category, and generate monthly spending reports.

The project focuses on core C++ programming concepts, object-oriented programming, data structures, file handling, and input validation. It uses a CSV file to store expense records so that the data can be loaded again when the application restarts.

## Key Features

- **Expense Management:** Add expenses with an amount, category, date, and description.
- **Transaction History:** View all recorded expenses in one place.
- **Category-wise Analysis:** Calculate the total amount spent in each category using `std::unordered_map`.
- **Category Search:** Find transactions that belong to a particular category.
- **Total Spending:** Calculate the total amount spent across all recorded transactions.
- **Monthly Spending Report:** Group expenses by month using `std::map` and display monthly totals.
- **CSV File Storage:** Save and load expense records using C++ file handling.
- **Input Validation:** Handle invalid menu choices and reject negative expense amounts.

## Technical Stack

- **Programming Language:** C++
- **Data Structures:** `std::vector`, `std::unordered_map`, `std::map`
- **File Handling:** `std::ifstream`, `std::ofstream`
- **String Processing:** `std::string`, `std::stringstream`
- **Other Concepts:** Classes, structures, loops, functions, and input validation

## Data Structures and Complexity

### 1. Transaction Storage — `std::vector`

A vector stores expense records in memory. It allows the application to access and process transactions using a simple collection.

- Adding a transaction to the vector is O(1) on average when adding to the end.
- Displaying all transactions takes O(n) time.
- Calculating total spending takes O(n) time.

Here, `n` represents the number of recorded transactions.

### 2. Category-wise Spending — `std::unordered_map`

An unordered map stores each category along with its total spending. When an expense is processed, its amount is added to the corresponding category.

- Average lookup and update time is O(1).
- Processing all transactions takes O(n) average time.

### 3. Monthly Spending Report — `std::map`

A map stores monthly totals using year-month keys. The keys are maintained in sorted order, allowing the report to display months chronologically when the dates use a consistent format.

- Inserting or updating a key takes O(log m) time.
- Processing n transactions takes O(n log m) time in the general case, where m is the number of distinct months.

## Data Storage Format

Expense records are stored in `expenses.csv` using comma-separated values.

Example:

```text
1,150.00,Food,2026-10-25,Lunch at college
2,80.00,Transport,2026-10-25,Bus fare
3,500.00,Shopping,2026-10-26,T-shirt purchase
```

Each record contains the following fields:

- **ID:** Transaction identifier.
- **Amount:** Amount spent.
- **Category:** Type of expense.
- **Date:** Date of the transaction, preferably in `YYYY-MM-DD` format.
- **Description:** Short explanation of the expense.

The application loads existing records when it starts and appends new expenses to the CSV file.

## Project Structure

```text
SpendWise/
├── main.cpp
├── expenses.csv
└── README.md
```

- `main.cpp` contains the `ExpenseManager` class and the main application menu.
- `expenses.csv` stores expense records and is created when expenses are saved if the file does not already exist.
- `README.md` provides project documentation and setup instructions.

## Getting Started

### Prerequisites

- A C++ compiler such as GCC or MinGW.
- A terminal or an editor such as Visual Studio Code.

### Compilation

Clone the repository and move into the project directory:

```bash
git clone <your-github-repository-url>
cd SpendWise
```

Compile the program:

```bash
g++ -std=c++17 main.cpp -o spendwise
```

### Execution

On Windows PowerShell:

```powershell
.\spendwise.exe
```

On Linux or macOS:

```bash
./spendwise
```

## Current Limitations

- The application uses a command-line interface.
- CSV parsing assumes that fields do not contain commas.
- Category searches are case-sensitive.
- Monthly reports depend on consistently formatted dates.
- Editing and deleting existing transactions are not currently implemented.
- Budget tracking and date-range filtering are not yet available.

## Planned Improvements

The following features may be added in future versions:

1. **Undo Functionality:** Use a stack to keep track of recent changes and allow users to reverse selected operations.
2. **Advanced Search and Filtering:** Add filters based on dates, categories, and expense amounts.
3. **Improved CSV Handling:** Handle descriptions and categories containing commas more reliably.
4. **Monthly Budget Tracking:** Allow users to set spending limits and track their remaining budget.
5. **Stronger Input Validation:** Improve handling of invalid dates, amounts, and file contents.

## Learning Objectives

This project provides practical experience with:

- Object-oriented programming in C++.
- Choosing suitable data structures for different tasks.
- Basic algorithm analysis and time complexity.
- File input and output.
- Parsing and processing text data.
- Designing a menu-driven application.
- Handling invalid user input.
