#include "bank.h"

void withdraw(void)
{
    uint32_t acc_no;
    double amount;
    printf("Enter Account Number: ");
    scanf("%u",&acc_no);

    account_t *acc = find_account(acc_no);
    if(!acc) { printf("Account not found\n"); return; }

    printf("Enter amount to withdraw: ");
    scanf("%lf",&amount);

    if(acc->balance < amount) {
        printf("Insufficient balance\n");
        return;
    }

    acc->balance -= amount;

    // add transaction
    transaction_t *t = &acc->txn[acc->txn_count % MAX_TXN];
    t->txn_id = ++global_txn_id;
    t->type   = TXN_WITHDRAW;
    t->amount = amount;
    acc->txn_count++;

    save_to_file();
    printf("Withdrawal successful.\n");
}

