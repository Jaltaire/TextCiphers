//
//  main.c
//  Vigenère Cipher
//
//  Created by Jonathan Alter on 1/5/17.
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
    printf("Enter 3 to quit Vigenère Cipher.\n");
    
    scanf("%d", &menuResponse);
    
    if (menuResponse == 1) encode();
    if (menuResponse == 2) decode();
    if (menuResponse == 3) exit(0);
    
}

void encode() { //Vigenère encipher method
    
    char plaintext [10000];
    char keyword [1000];
    
    int keywordValue [1000];
    
    int keyCounter = 0;
    
    printf("Enter the plaintext to encode.\n");
    fgets (plaintext, 100, stdin);
    scanf("%[^\n]%*c", plaintext);
    
    printf("Enter the keyword to use for encoding.\n");
    scanf("%s", keyword);
    
    printf("\n");
    
    for (int i = 0; i < strlen(keyword); i++) {
        if (isupper(keyword[i])) {
            keywordValue[i] = (keyword[i] - 'A') % 26;
        }
        if (islower(keyword[i])) {
            keywordValue[i] = (keyword[i] - 'a') % 26;
        }
    }
    
    printf("plaintext : %s \n", plaintext);
    printf("keyphrase : ");
    
    int keyphraseCounter = 0;
    
    for (int k = 0; k < strlen(plaintext); k++) {
        
        if (isalpha(plaintext[k])) {
            printf("%c", keyword[keyphraseCounter]);
            keyphraseCounter = (keyphraseCounter + 1) % strlen(keyword);
        }
        
        else {
            printf(" ");
        }
        
    }
    
    printf("\n");
    
    printf("ciphertext: ");
    
    for (int i = 0; i < strlen(plaintext); i++) {
        
        if (isalpha(plaintext[i])) {
            
            int temp = (plaintext[i] + keywordValue[keyCounter]);
            
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
            
            keyCounter = (keyCounter + 1) % strlen(keyword);
            
        }
        
        else {
            printf("%c", plaintext[i]);
        }
    }
    
    printf("\n \n");
    
    menuOptions();
    
}

void decode() { //Vigenère decipher method
    
    char encodedText [10000];
    char keyword [1000];
    
    int keywordValue [1000];
    
    int keyCounter = 0;
    
    printf("Enter the ciphertext to decode.\n");
    fgets (encodedText, 100, stdin);
    scanf("%[^\n]%*c", encodedText);
    
    printf("Enter the keyword to used to encode the original message.\n");
    scanf("%s", keyword);
    
    printf("\n");
    
    for (int i = 0; i < strlen(keyword); i++) {
        if (isupper(keyword[i])) {
            keywordValue[i] = (keyword[i] - 'A') % 26;
        }
        if (islower(keyword[i])) {
            keywordValue[i] = (keyword[i] - 'a') % 26;
        }
    }
    
    printf("ciphertext : %s \n", encodedText);
    printf("keyphrase : ");
    
    int keyphraseCounter = 0;
    
    for (int k = 0; k < strlen(encodedText); k++) {
        
        if (isalpha(encodedText[k])) {
            printf("%c", keyword[keyphraseCounter]);
            keyphraseCounter = (keyphraseCounter + 1) % strlen(keyword);
        }
        
        else {
            printf(" ");
        }
        
    }
    
    printf("\n");
    
    printf("plaintext: ");
    
    for (int i = 0; i < strlen(encodedText); i++) {
        
        if (isalpha(encodedText[i])) {
            
            int temp = (encodedText[i] - keywordValue[keyCounter]);
            
            if ((isupper(encodedText[i])) && (temp < 'A')) {
                temp = (temp + 26);
                printf("%c", temp);
            }
            
            else if ((islower(encodedText[i])) && (temp < 'a')) {
                temp = (temp + 26);
                printf("%c", temp);
            }
            
            else {
                printf("%c", temp);
            }
            
            keyCounter = (keyCounter + 1) % strlen(keyword);
            
        }
        
        else {
            printf("%c", encodedText[i]);
        }
    }
    
    printf("\n \n");
    
    menuOptions();
    
}
