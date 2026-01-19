#include "bank.h"

void delete_account(void)
{
    uint32_t acc_no;
    printf("Enter Account Number to delete: ");
    scanf("%u",&acc_no);

    account_t *curr = head, *prev = NULL;
    while(curr){
        if(curr->acc_no == acc_no){
            if(prev) prev->next = curr->next;
            else head = curr->next;
            free(curr);
            save_to_file();
            printf("Account deleted successfully\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Account not found\n");
}

