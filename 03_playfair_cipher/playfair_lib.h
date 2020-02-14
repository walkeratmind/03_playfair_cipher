#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEYMAT_SIZE 5

void createKeyMatrix(char[], char[][KEYMAT_SIZE]);
void initializeKeyMatrix(char[][KEYMAT_SIZE]);
void printKeyMatrix(char[][KEYMAT_SIZE]);
int isPresent(char, char[][KEYMAT_SIZE]);
void Insert(char, char[]);

void playfair_encrypt(char km[][KEYMAT_SIZE], char pt[], char ct[]);

int findRow(char ch, char km[][KEYMAT_SIZE]);
int findColumn(char ch, char km[][KEYMAT_SIZE]);


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

void InsertInCipherText(char ch, char ct[])
{
	ct[strlen(ct)] = ch;
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
		//printf(" ------------------------\n");
		for (j = 0; j < 5; j++)
		{
			printf(" %c  ", km[i][j]);
			//printf("|");
		}
		printf("\n");
	}
	//printf(" ------------------------\n");

}

//Encryption work goes here
void playfair_encrypt(char km[][KEYMAT_SIZE], char pt[], char ct[])
{
	//first character and second char
	char fc, sc;
	//first char row, second char row, first char column, second char column
	int fcr, scr, fcc, scc;

	int temp;
	int pos = 0;

	for (int i = 0; i < strlen(pt); i = i + 2)
	{
		fc = pt[i];
		sc = pt[i + 1];

		//break loop if plain text ends
		if (fc == '\0' && sc == '\0')
		{
			break;
		}

		if (fc == sc || sc == '\0')
		{
			sc = 'X';
			i = i - 1;
		}

		fcr = findRow(fc, km);
		fcc = findColumn(fc, km);

		scr = findRow(sc, km);
		scc = findColumn(sc, km);

		//for diff row , diff column
		if (fcr != scr && fcc != scc)
		{
			temp = fcc;
			fcc = scc;
			scc = temp;
		}

		//if same row
		if (fcc == scc)
		{
			fcr = (fcr + 1) % (KEYMAT_SIZE);
			scr = (scr + 1) % KEYMAT_SIZE;

		}

		//if same column
		if (fcr == scr)
		{
			fcc = (fcc + 1) % KEYMAT_SIZE;
			scc = (scc + 1) % KEYMAT_SIZE;

		}

		ct[pos++] = km[fcr][fcc];
		ct[pos++] = km[scr][scc];
	}
}

int findRow(char ch, char km[][KEYMAT_SIZE])
{
	int row;
	for (int i = 0; i < KEYMAT_SIZE; i++) {
		for (int j = 0; j < KEYMAT_SIZE; j++)
		{
			if (toupper(ch) == km[i][j])
				return i;	//return row of that char
		}
	}
	return -1;
}

int findColumn(char ch, char km[][KEYMAT_SIZE])
{
	for (int i = 0; i < KEYMAT_SIZE; i++) {
		for (int j = 0; j < KEYMAT_SIZE; j++)
		{
			if (toupper(ch) == km[i][j])
				return j;	//return row of that char
		}
	}
	return -1;
}



