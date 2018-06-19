//
//  main.c
//  Caesar Cipher
//
//  Created by Jonathan Alter on 1/3/17.
//  Copyright © 2017 Jonathan Alter. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void menuOptions();
void encode();
void decode();

int main(int argc, const char * argv[]) {
    
    menuOptions();
    
    return 0;
    
}

void menuOptions() { //Displays selection menu
    
    int menuResponse;
    
    printf("Enter 1 to encode a message.\n");
    printf("Enter 2 to decode a message.\n");
    printf("Enter 3 to quit Caesar Cipher.\n");
    
    scanf("%d", &menuResponse);
    
    if (menuResponse == 1) encode();
    if (menuResponse == 2) decode();
    if (menuResponse == 3) exit(0);
    
}

void encode() { //Caesar encipher method
    
    char plaintext [10000];
    int shiftKey;
    
    printf("Enter the plaintext to encode.\n");
    fgets (plaintext, 100, stdin);
    scanf("%[^\n]%*c", plaintext);
    
    printf("Enter the key shift to use for encoding.\n");
    scanf("%d", &shiftKey);
    
    if (shiftKey >= 26) {
        shiftKey = (shiftKey % 26);
    }
    
    printf("You encoded message is: \n");
    
    for (int i = 0; i < strlen(plaintext); i++) {
        
        if (isalpha(plaintext[i])) {
            
            int temp = (plaintext[i] + shiftKey);
            
            if ((isupper(plaintext[i])) && (temp > 'Z')) {
                temp = (temp - 26);
                printf("%c", temp);
            }
            
           else if ((islower(plaintext[i])) && (temp > 'z')) {
                temp = (temp - 26);
                printf("%c", temp);
            }
            
            else {
                printf("%c", temp);
            }
            
        }
        
        else {
            printf("%c", plaintext[i]);
        }
    }
    
    printf("\n \n");
    
    menuOptions();
    
}

void decode() { //Caesar decipher method
    
    char encodedtext [10000];
    int shiftKey;
    
    printf("Enter the encoded text to decode.\n");
    fgets (encodedtext, 100, stdin);
    scanf("%[^\n]%*c", encodedtext);
    
    printf("Enter the key shift used to encode the original message.\n");
    scanf("%d", &shiftKey);
    
    if (shiftKey >= 26) {
        shiftKey = (shiftKey % 26);
    }
    
    printf("Your decoded message is: \n");
    
    for (int i = 0; i < strlen(encodedtext); i++) {
        
        if (isalpha(encodedtext[i])) {
            
            int temp = (encodedtext[i] - shiftKey);
            
            if ((isupper(encodedtext[i])) && (temp < 'A')) {
                temp = (temp + 26);
                printf("%c", temp);
            }
            
            else if ((islower(encodedtext[i])) && (temp < 'a')) {
                temp = (temp + 26);
                printf("%c", temp);
            }
            
            else {
                printf("%c", temp);
            }
            
        }
        
        else {
            printf("%c", encodedtext[i]);
        }
    }
    
    printf("\n \n");
    
    menuOptions();
    
}
