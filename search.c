/*#include "bank.h"

void search_account(void)
{
    uint32_t acc_no;
    printf("Enter Account Number: ");
    scanf("%u", &acc_no);

    account_t *acc = find_account(acc_no);
    if (!acc) {
        printf("Account not found\n");
        return;
    }

    printf("AccNo:%u Name:%s Balance:%.2f Phone:%s\n",
           acc->acc_no, acc->name, acc->balance, acc->phone);
}
*/

#include "bank.h"

void search_account(void)
{
    uint32_t acc_no;
    printf("Enter Account Number to find: ");
    scanf("%u",&acc_no);

    account_t *acc = find_account(acc_no);
    if(!acc){ printf("Account not found\n"); return; }

    printf("AccNo: %u | Name: %s | Balance: %.2f\n",
           acc->acc_no, acc->name, acc->balance);
}

