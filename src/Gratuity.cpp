// This program will calculate the gratuity of a customer

#include <iostream>
#include <iomanip>
using namespace std;

class Tips {
    private: // Access specifier
    double taxRate;


    public: // Access specifier
    // Default Constructor
    Tips(){
    taxRate = 0.85;
    }
    // Parameterized constructor
    Tips(double tr){
    taxRate = tr;
    }

    // Function to compute the tip with two arguments: totalBill and tipRate
    double computeTip(double totalBill, double tipRate){
    return totalBill * (tipRate/100) *(1-(taxRate/100));
    }

    };

int main()
{
    cout << "This program will compute a restaurant tip based on a total bill "
            "amount and the % the patron wishes to tip the server." << endl;
    // Variaable declarations
    double taxRate;
    double totalBill;
    double tipRate;
    char answer;

    cout << "Enter tax % for this location: ";
    cin >> taxRate;

    // Input validation
    while (taxRate < 0){
        cout << "Tax % cannot be less than zero! Please re-enter tax %: ";
        cin >> taxRate;
    }

    // Creating an object of Tips with a the taxRate parameter
    Tips tip(taxRate);

   // Asking the user for information and conducting input validation
    do{
    cout << "Enter total bill amount: ";
    cin >> totalBill;
    // Input validation
    while (totalBill < 0){
        cout << "Total bill cannot be negative. Please re-enter total bill: ";
        cin >> totalBill;
    }
    cout << "Enter desired tip %: ";
    cin >> tipRate;

    // Input validation
    while (tipRate < 0){
        cout << "Tip rate cannot be negative. Please re-enter tip rate: ";
        cin >> tipRate;
    }

    cout << "The tip should be $: " << fixed << setprecision(2)
         << tip.computeTip(totalBill, tipRate)
         << endl;
    cout << "Compute another tip (y/n)?";
    cin >> answer;
    } while(answer != 'n');

    return 0;
}
