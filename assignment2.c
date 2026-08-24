#include <stdio.h>
#include <string.h>

struct Account {
    char name[30];
    int accountNo;
    float balance;
};

void checkBalance(struct Account *a) {
    printf("\nCurrent Balance: Rs. %.2f\n", a->balance);
}

void deposit(struct Account *a) {
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount > 0) {
        a->balance += amount;
        printf("Money deposited successfully.\n");
    } else {
        printf("Invalid amount.\n");
    }
}

void withdraw(struct Account *a) {
    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else if (amount > a->balance) {
        printf("Insufficient balance.\n");
    } else {
        a->balance -= amount;
        printf("Withdrawal successful.\n");
    }
}

void transfer(struct Account *a) {
    float amount;
    int receiverAccount;

    printf("Enter receiver account number: ");
    scanf("%d", &receiverAccount);
    printf("Enter transfer amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else if (amount > a->balance) {
        printf("Insufficient balance.\n");
    } else {
        a->balance -= amount;
        printf("Rs. %.2f transferred to account %d.\n", amount, receiverAccount);
    }
}

void displayDetails(struct Account *a) {
    printf("\n--- Account Details ---\n");
    printf("Name: %s\n", a->name);
    printf("Account Number: %d\n", a->accountNo);
    printf("Balance: Rs. %.2f\n", a->balance);
}

int main() {
    struct Account user = {"Prajwal", 123456, 5000.0};
    int choice;

    do {
        printf("\n--- ATM MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Transfer Money\n");
        printf("5. Display Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: checkBalance(&user); break;
            case 2: deposit(&user); break;
            case 3: withdraw(&user); break;
            case 4: transfer(&user); break;
            case 5: displayDetails(&user); break;
            case 6: printf("Thank you for using ATM.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}