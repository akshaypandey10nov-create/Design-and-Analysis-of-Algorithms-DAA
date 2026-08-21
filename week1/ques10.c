#include <stdio.h>

int main() {
    float balance = 10000.0;
    float amount;
    float transactions[5];
    int count = 0;
    int choice, i;

    do {
        printf("\n--- ATM MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Last Five Transactions\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Current Balance: %.2f\n", balance);
        }

        else if (choice == 2) {
            printf("Enter deposit amount: ");
            scanf("%f", &amount);

            if (amount > 0) {
                balance += amount;

                if (count < 5) {
                    transactions[count] = amount;
                    count++;
                } else {
                    for (i = 0; i < 4; i++)
                        transactions[i] = transactions[i + 1];

                    transactions[4] = amount;
                }

                printf("Money deposited successfully.\n");
            } else {
                printf("Invalid amount.\n");
            }
        }

        else if (choice == 3) {
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);

            if (amount <= 0) {
                printf("Invalid amount.\n");
            }
            else if (amount > balance) {
                printf("Insufficient balance.\n");
            }
            else {
                balance -= amount;

                if (count < 5) {
                    transactions[count] = -amount;
                    count++;
                } else {
                    for (i = 0; i < 4; i++)
                        transactions[i] = transactions[i + 1];

                    transactions[4] = -amount;
                }

                printf("Money withdrawn successfully.\n");
            }
        }

        else if (choice == 4) {
            printf("\n--- Last Five Transactions ---\n");

            if (count == 0) {
                printf("No transactions available.\n");
            } else {
                for (i = 0; i < count; i++) {
                    if (transactions[i] > 0)
                        printf("Deposit: +%.2f\n", transactions[i]);
                    else
                        printf("Withdrawal: %.2f\n", transactions[i]);
                }
            }
        }

        else if (choice == 5) {
            printf("Thank you for using the ATM.\n");
        }

        else {
            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
