#include <stdio.h>
#include <string.h>
#define KEYMAT_SIZE 5

void createKeyMatrix(char[], char[][KEYMAT_SIZE]);
void initializeKeyMatrix(char[][KEYMAT_SIZE]);
void printKeyMatrix(char[][KEYMAT_SIZE]);
int isPresent(char, char[][KEYMAT_SIZE]);
void Insert(char, char[]);

int main(int argc, char *argv[])
{
	//char keyword[100];

	printf("\t\tPlayFair Cipher\n");
	printf("\t------------------------------------\n");
	char pt[] = "hello how are you";
	char ct[100];

	char keyword[] = "POKHARA";
	char keymatrix[5][5];

	initializeKeyMatrix(keymatrix);
	createKeyMatrix(keyword, keymatrix);
	printKeyMatrix(keymatrix);

}

int isPresent(char ch, char mat[][KEYMAT_SIZE])
{
	for (int i = 0; i < KEYMAT_SIZE; i++)
	{
		for (int j = 0; j < KEYMAT_SIZE; j++)
		{
			if (ch == mat[i][j])
				return 1;
		}
	}
	return 0;
}

void Insert(char ch, char km[][KEYMAT_SIZE])
{
	int i, j;
	int flag = 1;
	for (i = 0; i < KEYMAT_SIZE; i++)
	{
		for (j = 0; j < KEYMAT_SIZE; j++)
		{
			if (km[i][j] == '\0')
			{
				km[i][j] = ch;
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			break;
	}
}

void initializeKeyMatrix(char km[][5])
{
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			km[i][j] = '\0';
}

/// key matrix that contains keyword and other alphabets without duplicate
void createKeyMatrix(char kw[], char km[][KEYMAT_SIZE])
{
	int i, k;
	for (i = 0; i < strlen(kw); i++)
	{
		if (kw[i] == '\0')
			continue;
		if (!isPresent(kw[i], km))
			Insert(kw[i], km);
	}

	for (char ch = 'A'; ch <= 'Z'; ch++)
	{
		if (ch == 'J')
			continue;
		if (!isPresent(ch, km))
			Insert(ch, km);
	}
}

void printKeyMatrix(char km[][5])
{
	int i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%c  ", km[i][j]);
		}
		printf("\n");
	}
}
