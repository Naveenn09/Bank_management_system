/*#include "bank.h"
#include <stdio.h>
#include <stdint.h>

void transfer(void)
{
    uint32_t src, dst;
    float amt;

    printf("Enter Source Account: ");
    scanf("%u", &src);
    printf("Enter Destination Account: ");
    scanf("%u", &dst);

    account_t *s = find_account(src);
    account_t *d = find_account(dst);

    if (!s || !d) {
        printf("Invalid account\n");
        return;
    }

    printf("Enter amount: ");
    scanf("%f", &amt);

    if (s->balance < amt) {
        printf("Insufficient balance\n");
        return;
    }

    s->balance -= amt;
    d->balance += amt;

    printf("Transfer successful\n");
}

void transfer(void)
{
    uint32_t src_acc, dst_acc;
    float amount;

    printf("Enter Source Account: ");
    scanf("%u", &src_acc);

    printf("Enter Destination Account: ");
    scanf("%u", &dst_acc);

    printf("Enter amount: ");
    scanf("%f", &amount);

    account_t *src = find_account(src_acc);
    account_t *dst = find_account(dst_acc);

    if (!src || !dst) {
        printf("Invalid account number\n");
        return;
    }

    if (src->balance < amount) {
        printf("Insufficient balance\n");
        return;
    }

    src->balance -= amount;
    dst->balance += amount;

    uint32_t itxn_id = ++global_txn_id;

    transaction_t *t1 = &src->txn[src->txn_count % MAX_TXN];
    t1->txn_id = itxn_id;
    t1->type   = TRANSFER;
    t1->amount = amount;
    src->txn_count++;

    transaction_t *t2 = &dst->txn[dst->txn_count % MAX_TXN];
    t2->txn_id = itxn_id;
    t2->type   = TRANSFER;
    t2->amount = amount;
    dst->txn_count++;

//    save_txn_id();
//    save_accounts();

    printf("Transfer successful\n");
}
*/


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

