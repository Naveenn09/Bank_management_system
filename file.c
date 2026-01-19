#include "bank.h"

account_t *head = NULL;
uint32_t global_txn_id = 1000;

// Save accounts + transaction ID
void save_to_file(void)
{
    FILE *fp = fopen("data/bank.dat","wb");
    if(!fp) return;

    // save txn id first
    fwrite(&global_txn_id, sizeof(global_txn_id), 1, fp);

    account_t *temp = head;
    while(temp) {
        fwrite(temp, sizeof(account_t), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
}

// Load accounts + transaction ID
void load_from_file(void)
{
    FILE *fp = fopen("data/bank.dat","rb");
    if(!fp) return;

    fread(&global_txn_id, sizeof(global_txn_id), 1, fp);

    account_t temp;
    while(fread(&temp, sizeof(account_t), 1, fp)) {
        account_t *new_acc = malloc(sizeof(account_t));
        *new_acc = temp;
        new_acc->next = head;
        head = new_acc;
    }
    fclose(fp);
}

