/*#include "bank.h"

account_t *find_account(uint32_t acc_no)
{
    account_t *temp = head;
    while (temp) {
        if (temp->acc_no == acc_no)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void create_account(void)
{
    account_t *new = malloc(sizeof(account_t));

    printf("Enter Account Number: ");
    scanf("%u", &new->acc_no);

    if (find_account(new->acc_no)) {
        printf("Account already exists!\n");
        free(new);
        return;
    }

    printf("Enter Name: ");
    scanf("%s", new->name);

    printf("Enter Phone: ");
    scanf("%s", new->phone);

    new->balance = 0;
    new->txn_count = 0;

    new->next = head;
    head = new;

    printf("Account Created successfully\n");
}
*/

#include "bank.h"

void create_account(void)
{
    account_t *acc = malloc(sizeof(account_t));
    printf("Enter account number: ");
    scanf("%u",&acc->acc_no);

    if(find_account(acc->acc_no)) {
        printf("Account already exists!\n");
        free(acc);
        return;
    }

    printf("Enter account holder name: ");
    scanf(" %[^\n]s", acc->name);
    printf("Enter the Mobile Number: ");
    scanf("%s", acc->phone);
    printf("Enter initial balance: ");
    scanf("%lf",&acc->balance);

    acc->txn_count = 0;
    acc->next = head;
    head = acc;

    save_to_file();
    printf("Account created successfully.\n");
}

account_t* find_account(uint32_t acc_no)
{
    account_t *temp = head;
    while(temp) {
        if(temp->acc_no == acc_no)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

