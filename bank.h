#ifndef BANK_H
#define BANK_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_TXN  10

// Transaction types
typedef enum { TXN_DEPOSIT, TXN_WITHDRAW, TXN_TRANSFER } txn_type_t;

// Transaction structure
typedef struct {
    uint32_t txn_id;
    txn_type_t type;
    double amount;
} transaction_t;

// Account structure
typedef struct account {
    uint32_t acc_no;
    char name[MAX_NAME];
    char phone[15];
    double balance;
    transaction_t txn[MAX_TXN];
    int txn_count;
    struct account *next;
} account_t;

// Head pointer for linked list of accounts
extern account_t *head;

// Global transaction ID
extern uint32_t global_txn_id;

// Function prototypes
void create_account(void);
void deposit(void);
void withdraw(void);
void transfer(void);
void display_all(void);
void transaction_history(void);
void search_account(void);
void delete_account(void);
account_t* find_account(uint32_t acc_no);

// File handling
void save_to_file(void);
void load_from_file(void);

#endif

