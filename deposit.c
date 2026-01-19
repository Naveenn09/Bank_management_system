/*#include "bank.h"

int generate_txn_id(void)
{
    static int id = 1000;
    return ++id;
}

void deposit(void)
{
    int acc_no;
    float amt;

    printf("Enter Account Number: ");
    scanf("%u", &acc_no);

    account_t *acc = find_account(acc_no);
    if (!acc) {
        printf("Account not found\n");
        return;
    }

    printf("Enter amount: ");
    scanf("%f", &amt);

    acc->balance += amt;

    transaction_t *t = &acc->txn[acc->txn_count % MAX_TXN];
    t->txn_id = generate_txn_id();
    t->type = DEPOSIT;
    t->amount = amt;

    acc->txn_count++;

    printf("Deposit successful\n");
}
*/

#include "bank.h"

void deposit(void)
{
    uint32_t acc_no;
    double amount;
    printf("Enter Account Number: ");
    scanf("%u",&acc_no);

    account_t *acc = find_account(acc_no);
    if(!acc) { printf("Account not found\n"); return; }

    printf("Enter amount to deposit: ");
    scanf("%lf",&amount);
    acc->balance += amount;

    // add transaction
    transaction_t *t = &acc->txn[acc->txn_count % MAX_TXN];
    t->txn_id = ++global_txn_id;
    t->type   = TXN_DEPOSIT;
    t->amount = amount;
    acc->txn_count++;

    save_to_file();
    printf("Deposit successful.\n");
}

