#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void LPSArray(char* pattern, int M, int* lps);

void KMPSearch(char* pattern, char* txt)
{
	int M = strlen(pattern);
	int N = strlen(txt);
	int lps[M];

	LPSArray(pattern, M, lps);

	int i = 0; 
	int j = 0; 
	while ((N - i) >= (M - j)) {
		if (pattern[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			cout << "Found pattern at " <<  i - j << "th location.";
			j = lps[j - 1];
		}

		else if (i < N && pattern[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

void LPSArray(char* pattern, int M, int* lps)
{

	int len = 0;

	lps[0] = 0; 
	int i = 1;
	while (i < M) {
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else 
		{
			
			if (len != 0) {
				len = lps[len - 1];

			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
	char txt[] = "ABCDABABCCBAB";
	char pattern[] = "ABABCABAB";
	KMPSearch(pattern, txt);
	return 0;
}
