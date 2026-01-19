#include "bank.h"

void display_all(void)
{
    account_t *temp = head;

    if (!temp) {
        printf("No accounts found\n");
        return;
    }
    printf("----------------------------------------------------------------------------------\n");
    while (temp) {
        printf("| AccNo: %-6u | Name: %-14s | Phone: %-14s | Balance: %-6.2f |\n",
               temp->acc_no, temp->name, temp->phone, temp->balance);
    printf("----------------------------------------------------------------------------------\n");
        temp = temp->next;
    }
}
