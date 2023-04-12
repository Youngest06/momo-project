#include <iostream>
#include <string>

using namespace std;

// Function declarations
void authenticate();
void resetPin();
void checkBalance();
void sendMoney();
void exitProgram();

// Global variables
int balance = 1000;
int pinAttempts = 0;
string pin = "0000";

int main() {
    // Display menu
    int option = 0;
    do {
        cout << "Welcome to Mobile Money Service" << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Reset/Change PIN" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Send Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;

        // Handle user's option
        switch(option) {
            case 1:
                authenticate();
                break;
            case 2:
                resetPin();
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                sendMoney();
                break;
            case 5:
                exitProgram();
                break;
            default:
                cout << "Invalid option, please try again." << endl;
        }
    } while(option != 5);

    return 0;
}

// Function definitions
void authenticate() {
    string inputPin;
    cout << "Enter your PIN: ";
    cin >> inputPin;

    if(inputPin == pin) {
        cout << "Authentication successful." << endl;
        pinAttempts = 0;
    } else {
        pinAttempts++;
        cout << "Incorrect PIN. " << 3 - pinAttempts << " attempts left." << endl;

        if(pinAttempts == 3) {
            cout << "Maximum number of attempts reached. Exiting program." << endl;
            exit(0);
        }
    }
}

void resetPin() {
    authenticate();

    string newPin;
    cout << "Enter new PIN: ";
    cin >> newPin;
    pin = newPin;

    cout << "PIN successfully changed." << endl;
}

void checkBalance() {
    authenticate();

    cout << "Your current balance is: " << balance << endl;
}

void sendMoney() {
    authenticate();

    int amount;
    cout << "Enter amount to send: ";
    cin >> amount;

    if(amount <= balance) {
        balance -= amount;
        cout << "Transaction successful. " << amount << " sent. New balance is: " << balance << endl;
    } else {
        cout << "Insufficient balance. Transaction failed." << endl;
    }
}

void exitProgram() {
    cout << "Exiting program. Thank you for using Mobile Money Service." << endl;
    exit(0);
}
