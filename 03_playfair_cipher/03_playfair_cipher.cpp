#include "pch.h"
#include "playfair_lib.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	//char keyword[100];

	printf("\t\tPlayFair Cipher\n");
	printf("\t------------------------------------\n");
	char plain_text[] = "hellohowareyou";
	char cipher_text[100] = "";

	printf("Plain Text: %s\n", plain_text);
	printf("------------------------------\n");
	printf("Keymatrix\n--------------\n");

	char keyword[] = "POKHARA";
	char keymatrix[5][5];

	
	initializeKeyMatrix(keymatrix);
	createKeyMatrix(keyword, keymatrix);
	printKeyMatrix(keymatrix);

	//Encrypt the plain text
	playfair_encrypt(keymatrix, plain_text, cipher_text);

	printf("Cipher Text: %s\n", cipher_text);
	return 0;
}
