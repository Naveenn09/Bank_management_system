#include "bank.h"

void transfer(void)
{
    uint32_t src_acc_no, dst_acc_no;
    double amount;
    printf("Enter Source Account: ");
    scanf("%u",&src_acc_no);
    printf("Enter Destination Account: ");
    scanf("%u",&dst_acc_no);
    printf("Enter amount: ");
    scanf("%lf",&amount);

    account_t *src = find_account(src_acc_no);
    account_t *dst = find_account(dst_acc_no);

    if(!src || !dst) { printf("Account not found\n"); return; }
    if(src->balance < amount) { printf("Insufficient balance\n"); return; }

    src->balance -= amount;
    dst->balance += amount;

    // ONE txn ID for both accounts
    uint32_t txn_id = ++global_txn_id;

    transaction_t *t1 = &src->txn[src->txn_count % MAX_TXN];
    t1->txn_id = txn_id;
    t1->type   = TXN_TRANSFER;
    t1->amount = amount;
    src->txn_count++;

    transaction_t *t2 = &dst->txn[dst->txn_count % MAX_TXN];
    t2->txn_id = txn_id;
    t2->type   = TXN_TRANSFER;
    t2->amount = amount;
    dst->txn_count++;

    save_to_file();
    printf("Transfer successful.\n");
}

