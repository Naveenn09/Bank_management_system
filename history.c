#include "bank.h"

char* txn_type_str(txn_type_t type) {
    switch(type){
        case TXN_DEPOSIT: return "DEPOSIT";
        case TXN_WITHDRAW: return "WITHDRAW";
        case TXN_TRANSFER: return "TRANSFER";
    }
    return "UNKNOWN";
}

void transaction_history(void)
{
    uint32_t acc_no;
    printf("Enter Account Number: ");
    scanf("%u",&acc_no);

    account_t *acc = find_account(acc_no);
    if(!acc) { printf("Account not found\n"); return; }
    if(acc->txn_count == 0) { printf("No transaction history available\n"); return; }

    int start = acc->txn_count > MAX_TXN ? acc->txn_count - MAX_TXN : 0;
    printf("Last Transactions:\n---------------------------------\n");
    for(int i = start; i < acc->txn_count; i++){
        transaction_t *t = &acc->txn[i % MAX_TXN];
        printf("TxnID: %u | Type: %s | Amount: %.2f\n",
               t->txn_id, txn_type_str(t->type), t->amount);
    }
}

