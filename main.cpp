
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

struct Expense {
    int id;
    double amount;
    string category;
    string date;
    string description;
};

class ExpenseManager {
private:
    vector<Expense> expenses;

public:
    ExpenseManager() { 
        ifstream file("expenses.csv");
        if(file.is_open()){
            string line;
            while(getline(file,line)){
                Expense expense;
                stringstream ss(line);
                string tempID,tempAmount;
                getline(ss,tempID,',');
                getline(ss,tempAmount,',');
                getline(ss,expense.category,',');
                getline(ss, expense.date, ',');
                getline(ss,expense.description);
                expense.id=stoi(tempID);
                expense.amount=stod(tempAmount);
                expenses.push_back(expense);
            }
        }
        file.close();
     }  
    
    void writeData(int n){
        ofstream file("expenses.csv",ios::app);
        if (!file.is_open()) {
            cout << "Error opening file for writing!" << endl;
            return;
        }
        int start=expenses.size()+1;
        for(int i=start;i<start+n;i++){
            Expense data;
            cout<<"Enter the details of expense "<<i<<endl;
            data.id=i;
            while(true){
                cout<<"Enter amount: ";
                if(!(cin>>data.amount)){
                    cout<<"Invalid input! Please enter a number."<<endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                    continue;
                };
                if(data.amount<0){
                    cout<<"Invalid expense amount dectected! Try again!"<<endl;
                    continue;
                }
                break;
            }
            cin.ignore(10000, '\n');
            cout<<"Enter category: ";
            getline(cin,data.category);
            cout<<"Enter date: ";
            getline(cin,data.date);
            cout<<"Enter description: ";
            getline(cin,data.description);
            file<<data.id<<","<<data.amount<<","<<data.category<<","<<data.date<<","<<data.description<<endl;
            expenses.push_back(data);
        }
        file.close();
    }

    void displayExpenses() {
        if (expenses.empty()) {
            cout << "No expenses recorded yet.\n";
            return;
        }

        cout << "\n--- SpendWise Transactions ---\n";

        for (const Expense& expense : expenses) {
            cout << "ID: " << expense.id << '\n';
            cout << "Amount: Rs. "
                << fixed << setprecision(2)
                << expense.amount << '\n';
            cout << "Category: " << expense.category << '\n';
            cout << "Date: " << expense.date << '\n';
            cout << "Description: " << expense.description << '\n';
            cout << "---------------------------\n";
        }
    }

    double totalAmountSpent(){
        double total=0;
        for(const Expense& expense:expenses){
            total+=expense.amount;
        }
        return total;
    }

    void spendingByCategory() {
        unordered_map <string,double> processedCategories;
        for(const Expense& expense : expenses){
            processedCategories[expense.category]+=expense.amount; 
        }

        cout << "\n--- Spending by Category ---\n";
        for(const auto& pair: processedCategories){
            cout<<pair.first<<" : Rs."<<fixed<<setprecision(2)<<pair.second<<endl;
        }
    }

    void searchByCategory(string category){
        bool found=false;
        cout<<endl<<"--- Search Results ---"<<endl;
        for(const Expense& expense: expenses){
            if(expense.category==category){
                found=true;
                cout<<"ID : "<<expense.id<<endl;
                cout<<"Amount: Rs."<<fixed<<setprecision(2)<<expense.amount<<endl;
                cout<<"Category: "<<expense.category<<endl;
                cout<<"Description: "<<expense.description<<endl<<endl;
            }
        }
        if(!found){
            cout<<"Category not found!"<<endl;
        }
    }
    
    void monthlySpendingReport() {
        map<string, double> monthlyTotals;

        for (const Expense& expense : expenses) {
            if (expense.date.size() >= 7) {
                string month = expense.date.substr(0, 7);
                monthlyTotals[month] += expense.amount;
            }
        }

        if (monthlyTotals.empty()) {
            cout << "No monthly spending data available.\n";
            return;
        }

        string monthNames[] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"
        };

        cout << "\n--- Monthly Spending Report ---\n";

        for (const auto& entry : monthlyTotals) {
            string monthKey = entry.first;
            int monthNumber = stoi(monthKey.substr(5, 2));
            string year = monthKey.substr(0, 4);

            if (monthNumber < 1 || monthNumber > 12) {
                cout << monthKey << " : Rs. "
                    << fixed << setprecision(2)
                    << entry.second << '\n';
                continue;
            }

            cout << monthNames[monthNumber - 1] << " " << year
                << " : Rs. "
                << fixed << setprecision(2)
                << entry.second << '\n';
        }
    }
};








int main() {
    ExpenseManager exm;

    int n;
    cout << "WELCOME TO SPEND WISE" << endl;

    while (true) {
        cout<<"--------MENU--------"<<endl;
        cout<<"1. Add new expenses"<<endl;
        cout<<"2. View all expenses"<<endl;
        cout<<"3. View spending by category"<<endl;
        cout<<"4. Search by category"<<endl;
        cout<<"5. Total amount spent"<<endl;
        cout<<"6. Monthly Spending Report"<<endl;
        cout << "7. Exit"<<endl;
        cout<<"Enter your choise: ";
        if (!(cin >> n)) {
            cout << "Invalid menu choice. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (n==1){
            int num;
            cout << "How many expenses do you want to add? ";

            if (!(cin >> num) || num < 0) {
                cout << "Please enter a valid non-negative number.\n";

                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            exm.writeData(num);
        }
        else if(n==2){
            exm.displayExpenses();
        }

        else if(n==3){
            exm.spendingByCategory();
        }

        else if(n==4){
            string categoryToSearch;
            cout << "\nEnter category to search: ";
            getline(cin >> ws, categoryToSearch);

            exm.searchByCategory(categoryToSearch);
        }

        else if(n==5){
            cout << "Total amount spent: "
            << fixed << setprecision(2)
            << exm.totalAmountSpent()<<endl;
        }

        else if(n==6){
            exm.monthlySpendingReport();
        }
        else if(n==7){
            cout << "------ SPEND WISE TERMINATING ------\n";
            break;
        }

        else{
            cout<<"Invalid Input!";
        }
        }
    return 0;
}