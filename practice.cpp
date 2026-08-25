#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

// ============================================================
//                    SYSTEM CONSTANTS
// ============================================================

const int MAX_USERS = 20;
const int MAX_TRANSACTIONS = 100;

const int ADMIN_PIN = 9999;

// ============================================================
//                    USER DATA
// ============================================================

string userName[MAX_USERS];
string accountNumber[MAX_USERS];
int userPIN[MAX_USERS];
double userBalance[MAX_USERS];

bool userActive[MAX_USERS];

string transactions[MAX_USERS][MAX_TRANSACTIONS];
int transactionCount[MAX_USERS];

int totalUsers = 4;

// ============================================================
//                    COLOR HANDLER
// ============================================================

void setColor(int color) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ============================================================
//                    SCREEN FUNCTIONS
// ============================================================

void clearScreen() { system("cls"); }

void waitForStart() {
  setColor(8);

  cout << "\n\n Press ENTER to continue...";

  cin.get();
}

// ============================================================
//                    MONEY FORMAT HELPER
// (Fixes the bug where to_string(double) printed 6 decimal
//  places, e.g. "5000.000000" instead of "5000.00")
// ============================================================

string formatMoney(double amount) {
  ostringstream out;
  out << fixed << setprecision(2) << amount;
  return out.str();
}

// ============================================================
//                    HEADER
// ============================================================

void showHeader(string title) {
  setColor(11);

  cout << "\n";
  cout << "============================================================\n";

  setColor(14);
  cout << "                 MINI ATM / BANKING SYSTEM\n";

  setColor(11);
  cout << "------------------------------------------------------------\n";

  setColor(13);
  cout << "                    " << title << "\n";

  setColor(11);
  cout << "============================================================\n";

  setColor(7);
}

// ============================================================
//                    TITLE / COVER PAGE
// ============================================================

void showTitlePage() {
  clearScreen();

  setColor(11);

  cout << "\n\n";
  cout << "============================================================\n";
  cout << "|                                                          |\n";

  setColor(14);
  cout << "|              MINI ATM / BANKING SYSTEM                  |\n";

  setColor(11);
  cout << "|                                                          |\n";
  cout << "============================================================\n";

  setColor(10);
  cout << "\n                   PROJECT PRESENTATION\n";

  setColor(7);

  cout << "\n";
  cout << " Project Title  : Mini ATM / Banking System\n";
  cout << " Program        : BS / ADP ITM\n";
  cout << " Institute      : IISAT\n";
  cout << " Submitted To   : Mam Kandeel\n";

  cout << "\n------------------------------------------------------------\n";

  setColor(13);

  cout << "\n Group Members:\n\n";

  setColor(7);

  cout << "  1. Muhammad Arham Shafi Butt\n";
  cout << "  2. Anas Naveed\n";
  cout << "  3. Seerat Fatima Butt\n";
  cout << "  4. Yashfa Arfan Butt\n";

  cout << "\n============================================================\n";

  setColor(10);
  cout << "\n                 Welcome to our System!\n";

  setColor(7);

  waitForStart();
}

// ============================================================
//                    INPUT FUNCTIONS
// ============================================================

// Safely reads integer input
int readInt(string message) {
  int value;

  for (int attempt = 0; attempt < 100; attempt++) {
    cout << message;

    if (cin >> value) {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      return value;
    }

    setColor(12);
    cout << "\n Invalid input! Please enter numbers only.\n\n";
    setColor(7);

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  return -1;
}

// Safely reads money amount
double readAmount(string message) {
  double amount;

  for (int attempt = 0; attempt < 100; attempt++) {
    cout << message;

    if (cin >> amount) {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      if (amount > 0) {
        return amount;
      }

      setColor(12);
      cout << "\n Amount must be greater than 0.\n\n";
      setColor(7);
    } else {
      setColor(12);
      cout << "\n Invalid amount! Please enter numbers only.\n\n";
      setColor(7);

      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }

  return -1;
}

// Safely reads a name (non-empty line)
string readLine(string message) {
  string value;

  for (int attempt = 0; attempt < 100; attempt++) {
    cout << message;

    getline(cin, value);

    if (!value.empty()) {
      return value;
    }

    setColor(12);
    cout << "\n This field cannot be empty.\n\n";
    setColor(7);
  }

  return "";
}

// ============================================================
//                    ACCOUNT INITIALIZATION
// ============================================================

void initializeAccounts() {
  // Account 1
  userName[0] = "Muhammad Arham Shafi Butt";
  accountNumber[0] = "1001";
  userPIN[0] = 1111;
  userBalance[0] = 50000;
  userActive[0] = true;

  // Account 2
  userName[1] = "Anas Naveed";
  accountNumber[1] = "1002";
  userPIN[1] = 2222;
  userBalance[1] = 40000;
  userActive[1] = true;

  // Account 3
  userName[2] = "Seerat Fatima Butt";
  accountNumber[2] = "1003";
  userPIN[2] = 3333;
  userBalance[2] = 35000;
  userActive[2] = true;

  // Account 4
  userName[3] = "Yashfa Arfan Butt";
  accountNumber[3] = "1004";
  userPIN[3] = 4444;
  userBalance[3] = 45000;
  userActive[3] = true;

  for (int i = 0; i < MAX_USERS; i++) {
    transactionCount[i] = 0;
  }
}

// ============================================================
//                    FIND ACCOUNT
// ============================================================

int findAccount(string account) {
  for (int i = 0; i < totalUsers; i++) {
    if (accountNumber[i] == account) {
      return i;
    }
  }

  return -1;
}

// ============================================================
//                    ADD TRANSACTION
// ============================================================

void addTransaction(int userIndex, string transaction) {
  if (transactionCount[userIndex] < MAX_TRANSACTIONS) {
    transactions[userIndex][transactionCount[userIndex]] = transaction;

    transactionCount[userIndex]++;
  }
}

// ============================================================
//                    USER LOGIN
// ============================================================

int userLogin() {
  string account;
  int pin;

  for (int attempt = 1; attempt <= 3; attempt++) {
    clearScreen();

    showHeader("USER LOGIN");

    cout << "\n Account Number: ";
    cin >> account;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int index = findAccount(account);

    if (index == -1) {
      setColor(12);
      cout << "\n Account not found.\n";
      setColor(7);

      waitForStart();
      continue;
    }

    if (!userActive[index]) {
      setColor(12);
      cout << "\n This account is currently BLOCKED by Admin.\n";
      setColor(7);

      waitForStart();
      continue;
    }

    pin = readInt(" PIN: ");

    if (pin == userPIN[index]) {
      setColor(10);

      cout << "\n Login Successful!";
      cout << "\n Welcome, " << userName[index] << "\n";

      setColor(7);

      waitForStart();
      return index;
    }

    setColor(12);
    cout << "\n Incorrect PIN!";
    cout << "\n Attempts remaining: " << 3 - attempt << "\n";

    setColor(7);

    waitForStart();
  }

  setColor(12);
  cout << "\n Too many failed login attempts.\n";
  cout << " Returning to main screen...\n";

  setColor(7);

  waitForStart();

  return -1;
}

// ============================================================
//                    ADMIN LOGIN
// ============================================================

bool adminLogin() {
  int pin;

  clearScreen();

  showHeader("ADMIN LOGIN");

  pin = readInt("\n Admin PIN: ");

  if (pin == ADMIN_PIN) {
    setColor(10);
    cout << "\n Admin Login Successful!\n";
    setColor(7);

    waitForStart();
    return true;
  }

  setColor(12);
  cout << "\n Incorrect Admin PIN!\n";
  setColor(7);

  waitForStart();
  return false;
}

// ============================================================
//                    CHECK BALANCE
// ============================================================

void checkBalance(int index) {
  clearScreen();

  showHeader("ACCOUNT BALANCE");

  cout << "\n Account Holder : " << userName[index];
  cout << "\n Account Number : " << accountNumber[index];

  cout << "\n\n------------------------------------------------------------\n";

  setColor(10);

  cout << " Available Balance : Rs. " << formatMoney(userBalance[index]);

  setColor(7);

  cout << "\n------------------------------------------------------------\n";

  waitForStart();
}

// ============================================================
//                    DEPOSIT
// ============================================================

void depositMoney(int index) {
  clearScreen();

  showHeader("DEPOSIT MONEY");

  cout << "\n Current Balance : Rs. " << formatMoney(userBalance[index]);

  cout << "\n\n";

  double amount = readAmount(" Enter Deposit Amount: Rs. ");

  if (amount == -1) {
    waitForStart();
    return;
  }

  userBalance[index] += amount;

  addTransaction(index, "Deposit       + Rs. " + formatMoney(amount));

  setColor(10);

  cout << "\n Deposit Successful!";
  cout << "\n Amount : Rs. " << formatMoney(amount);
  cout << "\n New Balance : Rs. " << formatMoney(userBalance[index]) << "\n";

  setColor(7);

  waitForStart();
}

// ============================================================
//                    WITHDRAW
// ============================================================

void withdrawMoney(int index) {
  clearScreen();

  showHeader("WITHDRAW MONEY");

  cout << "\n Available Balance : Rs. " << formatMoney(userBalance[index]);

  cout << "\n\n";

  double amount = readAmount(" Enter Withdrawal Amount: Rs. ");

  if (amount == -1) {
    waitForStart();
    return;
  }

  if (amount > userBalance[index]) {
    setColor(12);

    cout << "\n Insufficient Balance!";
    cout << "\n Transaction Cancelled.\n";

    setColor(7);
    waitForStart();
    return;
  }

  userBalance[index] -= amount;

  addTransaction(index, "Withdrawal    - Rs. " + formatMoney(amount));

  setColor(10);

  cout << "\n Withdrawal Successful!";
  cout << "\n Amount : Rs. " << formatMoney(amount);
  cout << "\n Remaining Balance : Rs. " << formatMoney(userBalance[index])
       << "\n";

  setColor(7);

  waitForStart();
}

// ============================================================
//                    TRANSFER
// ============================================================

void transferMoney(int sender) {
  clearScreen();

  showHeader("TRANSFER MONEY");

  cout << "\n Your Account : " << accountNumber[sender];

  cout << "\n Your Balance : Rs. " << formatMoney(userBalance[sender]);

  cout << "\n\n";

  string receiverAccount;

  cout << " Receiver Account Number: ";
  cin >> receiverAccount;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int receiver = findAccount(receiverAccount);

  if (receiver == -1) {
    setColor(12);
    cout << "\n Receiver account does not exist.\n";
    setColor(7);
    waitForStart();
    return;
  }

  if (receiver == sender) {
    setColor(12);
    cout << "\n You cannot transfer money to yourself.\n";
    setColor(7);
    waitForStart();
    return;
  }

  if (!userActive[receiver]) {
    setColor(12);
    cout << "\n Receiver account is blocked.\n";
    setColor(7);
    waitForStart();
    return;
  }

  cout << "\n Receiver Name : " << userName[receiver];

  double amount = readAmount("\n Transfer Amount: Rs. ");

  if (amount == -1) {
    waitForStart();
    return;
  }

  if (amount > userBalance[sender]) {
    setColor(12);

    cout << "\n Insufficient Balance!";
    cout << "\n Transfer Cancelled.\n";

    setColor(7);
    waitForStart();
    return;
  }

  // Remove money from sender
  userBalance[sender] -= amount;

  // Add money to receiver
  userBalance[receiver] += amount;

  addTransaction(sender, "Transfer      - Rs. " + formatMoney(amount) + " -> " +
                             receiverAccount);

  addTransaction(receiver, "Received      + Rs. " + formatMoney(amount) +
                               " <- " + accountNumber[sender]);

  setColor(10);

  cout << "\n Transfer Successful!";
  cout << "\n Sent To : " << userName[receiver];
  cout << "\n Amount : Rs. " << formatMoney(amount);
  cout << "\n Remaining Balance : Rs. " << formatMoney(userBalance[sender])
       << "\n";

  setColor(7);

  waitForStart();
}

// ============================================================
//                    TRANSACTION SUMMARY
// ============================================================

void transactionSummary(int index) {
  clearScreen();

  showHeader("TRANSACTION SUMMARY");

  cout << "\n Account : " << accountNumber[index];

  cout << "\n Holder  : " << userName[index];

  cout << "\n\n------------------------------------------------------------\n";

  if (transactionCount[index] == 0) {
    setColor(8);
    cout << " No transactions available.\n";
    setColor(7);
  } else {
    for (int i = 0; i < transactionCount[index]; i++) {
      cout << " " << i + 1 << ". " << transactions[index][i] << "\n";
    }
  }

  cout << "------------------------------------------------------------\n";

  setColor(10);

  cout << " Current Balance : Rs. " << formatMoney(userBalance[index]);

  setColor(7);

  cout << "\n";

  waitForStart();
}

// ============================================================
//                    USER MENU
// ============================================================

void userMenu(int index) {
  int choice;

  for (int menuLoop = 0; menuLoop < 1000; menuLoop++) {
    clearScreen();

    showHeader("USER DASHBOARD");

    setColor(10);

    cout << "\n Welcome, " << userName[index];

    setColor(7);

    cout << "\n Account: " << accountNumber[index];

    cout
        << "\n\n------------------------------------------------------------\n";

    cout << "  1. Check Balance\n";
    cout << "  2. Deposit Money\n";
    cout << "  3. Withdraw Money\n";
    cout << "  4. Transfer Money\n";
    cout << "  5. Transaction Summary\n";
    cout << "  6. Logout\n";

    cout << "\n------------------------------------------------------------\n";

    choice = readInt(" Enter your choice: ");

    switch (choice) {
    case 1:
      checkBalance(index);
      break;

    case 2:
      depositMoney(index);
      break;

    case 3:
      withdrawMoney(index);
      break;

    case 4:
      transferMoney(index);
      break;

    case 5:
      transactionSummary(index);
      break;

    case 6:
      return;

    default:
      setColor(12);
      cout << "\n Invalid choice! Please select 1 - 6.\n";
      setColor(7);
      waitForStart();
    }
  }
}

// ============================================================
//                    ADMIN: VIEW ALL USERS
// ============================================================

void viewAllAccounts() {
  clearScreen();

  showHeader("ALL ACCOUNTS");

  cout << "\n";

  for (int i = 0; i < totalUsers; i++) {
    cout << "------------------------------------------------------------\n";

    cout << " Account Number : " << accountNumber[i];
    cout << "\n Name           : " << userName[i];

    cout << "\n Balance        : Rs. " << formatMoney(userBalance[i]);

    cout << "\n Status         : ";

    if (userActive[i]) {
      setColor(10);
      cout << "ACTIVE";
    } else {
      setColor(12);
      cout << "BLOCKED";
    }

    setColor(7);

    cout << "\n";
  }

  cout << "------------------------------------------------------------\n";

  waitForStart();
}

// ============================================================
//                    ADMIN: CREATE ACCOUNT
// ============================================================

void createAccount() {
  clearScreen();

  showHeader("CREATE NEW ACCOUNT");

  if (totalUsers >= MAX_USERS) {
    setColor(12);
    cout << "\n Maximum account limit reached.\n";
    setColor(7);
    waitForStart();
    return;
  }

  // NOTE: no extra cin.ignore() here — readInt() from the previous
  // menu prompt already cleared the input buffer. Calling ignore()
  // again on an empty buffer used to make the program silently wait
  // for an extra Enter press (or swallow the name typed next).
  cout << "\n";

  string newName = readLine(" Enter Customer Name: ");

  if (newName.empty()) {
    setColor(12);
    cout << "\n Name cannot be empty.\n";
    setColor(7);
    waitForStart();
    return;
  }

  string newAccount;

  cout << " Enter Account Number: ";
  cin >> newAccount;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (findAccount(newAccount) != -1) {
    setColor(12);
    cout << "\n Account number already exists.\n";
    setColor(7);
    waitForStart();
    return;
  }

  int newPIN = readInt(" Set 4-Digit PIN: ");

  if (newPIN < 1000 || newPIN > 9999) {
    setColor(12);
    cout << "\n PIN must contain exactly 4 digits.\n";
    setColor(7);
    waitForStart();
    return;
  }

  double initialDeposit = readAmount(" Initial Deposit: Rs. ");

  if (initialDeposit == -1) {
    waitForStart();
    return;
  }

  // Only now that every field is validated do we commit the
  // new account — this avoids leaving half-written data behind
  // in the arrays if an earlier check fails.
  userName[totalUsers] = newName;
  accountNumber[totalUsers] = newAccount;
  userPIN[totalUsers] = newPIN;
  userBalance[totalUsers] = initialDeposit;
  userActive[totalUsers] = true;
  transactionCount[totalUsers] = 0;

  addTransaction(totalUsers,
                 "Account Created + Rs. " + formatMoney(initialDeposit));

  totalUsers++;

  setColor(10);

  cout << "\n Account Created Successfully!";
  cout << "\n Customer : " << userName[totalUsers - 1];

  cout << "\n Account Number : " << accountNumber[totalUsers - 1] << "\n";

  setColor(7);

  waitForStart();
}

// ============================================================
//                    ADMIN: BLOCK / UNBLOCK
// ============================================================

void manageAccount() {
  clearScreen();

  showHeader("BLOCK / UNBLOCK ACCOUNT");

  string account;

  cout << "\n Enter Account Number: ";
  cin >> account;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int index = findAccount(account);

  if (index == -1) {
    setColor(12);
    cout << "\n Account not found.\n";
    setColor(7);
    waitForStart();
    return;
  }

  cout << "\n Customer : " << userName[index];

  cout << "\n Current Status : ";

  if (userActive[index]) {
    setColor(10);
    cout << "ACTIVE";
  } else {
    setColor(12);
    cout << "BLOCKED";
  }

  setColor(7);

  cout << "\n\n 1. Block Account";
  cout << "\n 2. Unblock Account";

  int choice = readInt("\n\n Choose option: ");

  if (choice == 1) {
    userActive[index] = false;

    setColor(10);
    cout << "\n Account has been BLOCKED.\n";
  } else if (choice == 2) {
    userActive[index] = true;

    setColor(10);
    cout << "\n Account has been UNBLOCKED.\n";
  } else {
    setColor(12);
    cout << "\n Invalid option.\n";
  }

  setColor(7);

  waitForStart();
}

// ============================================================
//                    ADMIN MENU
// ============================================================

void adminMenu() {
  int choice;

  for (int menuLoop = 0; menuLoop < 1000; menuLoop++) {
    clearScreen();

    showHeader("ADMIN DASHBOARD");

    setColor(13);

    cout << "\n                    ADMIN CONTROL PANEL\n";

    setColor(7);

    cout << "\n------------------------------------------------------------\n";

    cout << "  1. View All Accounts\n";
    cout << "  2. Create New Account\n";
    cout << "  3. Block / Unblock Account\n";
    cout << "  4. Logout\n";

    cout << "\n------------------------------------------------------------\n";

    choice = readInt(" Enter your choice: ");

    switch (choice) {
    case 1:
      viewAllAccounts();
      break;

    case 2:
      createAccount();
      break;

    case 3:
      manageAccount();
      break;

    case 4:
      return;

    default:
      setColor(12);
      cout << "\n Invalid choice! Please select 1 - 4.\n";
      setColor(7);
      waitForStart();
    }
  }
}

// ============================================================
//                    FINAL SCREEN
// ============================================================

void exitScreen() {
  clearScreen();

  setColor(11);

  cout << "\n\n";
  cout << "============================================================\n";
  cout << "|                                                          |\n";

  setColor(10);

  cout << "|            MINI ATM / BANKING SYSTEM                    |\n";

  setColor(11);
  cout << "|                                                          |\n";
  cout << "============================================================\n";

  setColor(14);
  cout << "\n                     SESSION ENDED\n";

  setColor(7);

  cout << "\n Thank you for using our Banking System.\n";
  cout << " Your session has been securely closed.\n";

  cout << "\n------------------------------------------------------------\n";

  setColor(13);

  cout << "\n                        OUR TEAM\n\n";

  setColor(7);

  cout << "  1. Muhammad Arham Shafi Butt\n";
  cout << "  2. Anas Naveed\n";
  cout << "  3. Seerat Fatima Butt\n";
  cout << "  4. Yashfa Arfan Butt\n";

  cout << "\n------------------------------------------------------------\n";

  cout << " Program      : BS / ADP ITM\n";
  cout << " Institute    : IISAT\n";
  cout << " Submitted To : Mam Kandeel\n";

  cout << "\n============================================================\n";

  setColor(14);

  cout << "\n                       THANK YOU!\n\n";

  setColor(7);
}

// ============================================================
//                    MAIN MENU
// ============================================================

int main() {
  initializeAccounts();

  // Show presentation page only once
  showTitlePage();

  int choice;

  for (int mainLoop = 0; mainLoop < 1000; mainLoop++) {
    clearScreen();

    showHeader("WELCOME");

    cout << "\n";
    cout << "  1. User Login\n";
    cout << "  2. Admin Login\n";
    cout << "  3. Exit\n";

    cout << "\n------------------------------------------------------------\n";

    choice = readInt(" Enter your choice: ");

    switch (choice) {
    case 1: {
      int userIndex = userLogin();

      if (userIndex != -1) {
        userMenu(userIndex);
      }

      break;
    }

    case 2: {
      if (adminLogin()) {
        adminMenu();
      }

      break;
    }

    case 3:
      exitScreen();
      return 0;

    default:
      setColor(12);

      cout << "\n Invalid choice! Please select 1 - 3.\n";

      setColor(7);

      waitForStart();
    }
  }

  return 0;
}