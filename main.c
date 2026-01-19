#include "bank.h"

//account_t *head = NULL;

void menu(void)
{
    printf("\n------------------MENU------------------\n");
    printf("C : Create account\n");
    printf("D : Deposit\n");
    printf("R : Delete account\n");
    printf("W : Withdraw\n");
    printf("T : Transfer\n");
    printf("B : Balance enquiry\n");
    printf("H : Transaction history\n");
    printf("E : Display all accounts\n");
    printf("F : Find account\n");
    printf("S : Save to file\n");
    printf("Q : Quit\n");
    printf("----------------------------------------\n");
}

int main(void)
{
    char choice;
    load_from_file();

    while (1) {
        menu();
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case 'C': case 'c': create_account(); break;
        case 'D': case 'd': deposit(); break;
        case 'W': case 'w': withdraw(); break;
        case 'T': case 't': transfer(); break;
        case 'B': case 'b': search_account(); break;
        case 'H': case 'h': transaction_history(); break;
        case 'E': case 'e': display_all(); break;
        case 'F': case 'f': search_account(); break;
        case 'S': case 's': save_to_file(); break;
	case 'R': case 'r': delete_account(); break;
        case 'Q': case 'q': save_to_file();
            			exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

