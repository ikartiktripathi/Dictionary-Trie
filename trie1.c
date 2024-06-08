#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100000

typedef struct trie{
	bool EOW;		// End of Word
	struct trie *arr[26];
	int byte;
//	unsigned int x; 
	char *letters;
	int count;
	char *meanptr;
}trie;

void insertInTrie(char target[], trie *tree);
void dft(trie *tree, int typ[]);

int charToInt(char x)
{
	int a = x;

	if(a>=97 && a<=122)
	{
		a=a-97;
	}
	if(a>=65 && a<=90)
	{
		a=a-65;
	}
	return a;
}

void insertInTrie(char target[], trie *tree)
{
	int i=0, j=0;
		while(target[i]!='\0' && ((((int)(target[i]))>=65 && ((int)(target[i]))<=90) || (((int)(target[i]))>=97 && ((int)(target[i]))<=122)))
		{
			if((tree->arr[charToInt(target[i])])==NULL)
			{
			trie *newNode = (trie *)malloc(sizeof(trie));
			newNode->letters = (char *)malloc(sizeof(char));
			newNode->letters[j] = ;
//			newNode->x = newNode->x + pow(2,(charToInt(target[i])));
			tree->arr[charToInt(target[i])]= newNode;
			tree=newNode;
			}
			else
			{
//			tree->x = tree->x + pow(2,(charToInt(target[i])));
			tree->letters = (char *)realloc(newNode->letters,sizeof(char));
			tree->letters[j] = ;
			tree = tree->arr[charToInt(target[i])];
			}
			i++;
		}
		tree->EOW = true;
}

void refData(trie *tree, unsigned char arr[])
{
	if(tree==NULL)
	{
		return;
	}

	int i=0;
	while(i<26)
	{
		if(tree->arr[i]!=NULL)
		{
		dft(tree->arr[i],typ);
		tree->byte++;
		}
	i++;
	}
}

// dft
void dft(trie *tree, int typ[])
{
	if(tree==NULL)
	{
		return;
	}

	int i=0;
	while(i<26)
	{
		if(tree->arr[i]!=NULL)
		{
		dft(tree->arr[i],typ);
		tree->byte++;
/*		tree->byte = tree->byte+4;
		if(tree->EOW==true)
			{
			tree->byte = tree->byte+4;
			}
*/		}
	i++;
	}
		typ[tree->byte]++;
}

void printTreeHelper(trie *tree, char word[], int level)
	{
	if(tree == NULL)
	{
		return;
	}
	if(tree->EOW)
	{
		word[level] = '\0';
		printf("%s\n", word);
	}
	int i=0;
	while(i < 26)
	{
		if(tree->arr[i] != NULL)
		{
			word[level] = i + 'a';
			printTreeHelper(tree->arr[i], word, level + 1);
		}
		i++;
	}
}

void printTree(trie *tree)
	{
		char word[100];
		printTreeHelper(tree, word, 0);
	}

int main(int argc, char *argv[])
{
	argc = argc+2;
	trie *tree = (trie *)malloc(sizeof(trie));	
	char target[100];
	int type[27]={0};

	FILE *f = fopen(argv[1],"r");
	while(fscanf(f, "%s", target) != EOF)	
	{
		insertInTrie(target,tree);
	}
	
//	printTree(tree);
	dft(tree, type);
	
	int i = 0;
	while(i<27)
	{
		printf("%d : %d\n", i, type[i]);
		i++;
	}

	return 0;
}
