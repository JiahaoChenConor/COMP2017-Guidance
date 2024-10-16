/*
    Bank System

    Program1：maintain a list of bank accounts
    Program2: do some operations BAlANCE/DEPOSIT/Withdraw

    shared memory (store bank accounts info)
    named pipe => pass info




						BAlANCE			+-------------+
	+---------+      <-------------     |   ATM1      |
	|		  |							+-------------+
	|	Bank  |			WITHDRAW
	|		  |      <-------------     +-------------+
	|         |     					|   ATM2      |
	+---------+							+-------------+
			\                            /
			 \							/
			  \						   /
					Shared memory

					account info


    1. ATM pass operations to bank, bank do some change in shared memory
    2. after finish, ATM read from shared memory

    /for convinence, this program just print in bank. 
    for the shared memory
    you need to syn to make sure there is no race condition.
    like using semphore 
    /
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#define SOME_DATA (24)

float getBalance(char* filepath, char* cardNum, char* pin){
    char* block = NULL;
    int fd = open(filepath, O_RDWR);
    struct stat stat_b;
    fstat(fd, &stat_b);

    block = mmap(NULL, stat_b.st_size, PROT_WRITE | PROT_READ,
            MAP_SHARED, fd, 0);

    if(block == MAP_FAILED) {
        perror("MAP Failed");
        close(fd);
        return -1;
    }

    
    // find cardNum then balance
    char* card = "cardNum: ";
    char cardNumBuff[30];
    
    strcpy(cardNumBuff, card);
    strcpy(cardNumBuff + 9, cardNum);
    
  
    char* card_ptr = strstr(block, cardNumBuff);
    char* pin_ptr = strstr(card_ptr, "pin: ");
    char store_pin[5];
    memset(store_pin, 0, 5);
    strncpy(store_pin, pin_ptr + 5, 4); // 5 is offset from "pin: "
  
    if (strcmp(store_pin, pin) != 0){
        printf("wrong pin");
        return -1;
    }

   
    char* balance_ptr = strstr(card_ptr, "balance: ");

    // not until the end of the memory
    char balance[99];
    int i = 0;
    for (; *(balance_ptr + i) != '\n' &&  balance_ptr + i - block < stat_b.st_size; i++){
        printf("%c", *(balance_ptr + i));
        balance[i] = *(balance_ptr + i);
        
    }

    printf("\n");
    balance[i] = '\0';


    // balance: 12   split it 
    char *token = strtok(balance," ");
    token = strtok(NULL, " ");

    munmap(block, stat_b.st_size);
    close(fd);
    
    return atof(token);
}



void change_balance(char* filepath, char* cardNum, float change, char* pin){
    char* block = NULL;
    int fd = open(filepath, O_RDWR);
    struct stat stat_b;
    fstat(fd, &stat_b);

    block = mmap(NULL, stat_b.st_size, PROT_WRITE | PROT_READ,
            MAP_SHARED, fd, 0);

    if(block == MAP_FAILED) {
        perror("MAP Failed");
        close(fd);
        return;
    }


    // find cardNum then balance
    char* card = "cardNum: ";
    char cardNumBuff[30];

    strcpy(cardNumBuff, card);
    strcpy(cardNumBuff + 9, cardNum);
    

    char* card_ptr = strstr(block, cardNumBuff);
    char* balance_ptr = strstr(card_ptr, "balance: ");

    float originalBalance = getBalance(filepath, cardNum, pin);
    
    float newBalance = originalBalance + change;
    printf("new balance: %f\n", newBalance);

    // transfer float to string
    char newBalanceS[50]; //size of the number
    memset(newBalanceS, 0, 50);
    sprintf(newBalanceS, "%g", newBalance);
    
    // retrieve the length of original balance
    int i = 0;
    for ( ; *(balance_ptr + i) != '\n' &&  balance_ptr + i - block < stat_b.st_size; i++);

    // change the balance
    memcpy(balance_ptr + 9, newBalanceS, i);

    
    // remember to unmap.
    munmap(block, stat_b.st_size);
    close(fd);
    
}


void readPipe(){
    int fd1;

    // FIFO file path
    char * myfifo = "myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);

    char str1[80];

    // First open in read only and read
    while (1)
    {
        fd1 = open(myfifo, O_RDONLY);
        // blocking until there is 80 bytes data in pipe
        int bytes = read(fd1, str1, 80);
        if (bytes != 80){
            perror("Error");
        }
        // Print the read string 
        printf("FROM ATM operation: %s\n", str1);

        // process the ATM operations
        // split by space
        for (char *token = strtok(str1," "); token != NULL; token = strtok(NULL, " "))
        {   
            // compare with string needed be replaced 
            if (strcmp(token, "BAlANCE") == 0) {
                char* cardNum = strtok(NULL, " ");
                
                char* pin = strtok(NULL, " ");
                getBalance("accounts.txt", cardNum, pin);
                break;

            } else if (strcmp(token, "DEPOSIT") == 0){
                // TODO: deposit
                // try by yourself
                
            }else if (strcmp(token, "WITHDRAW") == 0){
                char* amount = strtok(NULL, " ");
                char* cardNum = strtok(NULL, " ");
                char* pin = strtok(NULL, " ");
                change_balance("accounts.txt", cardNum, 0 - atof(amount), pin);
                break;
            }else{
                printf("not exists this operation");
                break;
            }
        }
        close(fd1);
    }
  

    
  
}


// ./mmap_with_files data.txt
int main(int argc, char** argv) {

    readPipe();
    // change_balance("accounts.txt", "1111222233334444", 12, "1234");
    // getBalance("accounts.txt", "1111222233334444", "1234");

}


