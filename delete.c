/*#include "bank.h"

void delete_account(void)
{
    uint32_t acc_no;
    printf("Enter Account Number to delete: ");
    scanf("%u", &acc_no);

    if (!head) {
        printf("No accounts exist.\n");
        return;
    }

    account_t *temp = head;
    account_t *prev = NULL;

    // Traverse linked list
    while (temp != NULL) {
        if (temp->acc_no == acc_no) {
            // Found the account
            if (prev == NULL) {
                // Head needs to be deleted
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);  // Free memory
            printf("Account %u deleted successfully.\n", acc_no);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Account %u not found.\n", acc_no);
}
*/

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

