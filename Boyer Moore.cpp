 #include <bits/stdc++.h>
 using namespace std;
 #define TOTAL_CHARS 256 
 void badCharacter(string STR, int size, int badcharacter[TOTAL_CHARS])
 {
     for (int i = 0; i < TOTAL_CHARS; i++)
         badcharacter[i] = -1;
     for (int i = 0; i < size; i++)
         badcharacter[(int)STR[i]] = i;
 }

 void BadCharacterSearch(string text, string pattern)
 {
     int m = pattern.size();
     int n = text.size();
     int badcharacter[TOTAL_CHARS];
     badCharacter(pattern, m, badcharacter); 
     int shift = 0;
     while (shift <= (n - m))
     {
         int j = m - 1;
         while (j >= 0 && pattern[j] == text[shift + j]) 
             j--;
         if (j < 0) 
         {
             cout << "Pattern occurs at the index " << shift << endl;
             shift += (shift + m < n) ? m - badcharacter[text[shift + m]] : 1;
         }
         else
             shift += max(1, j - badcharacter[text[shift + j]]);
     }
 }
 int main()
 {
     string text = "HIMYNAMEISNIRMALANALUMNIOFSAINIKSCHOOLAMARAVATHINAGAR";
     string pattern = "ANALUMNI";
     BadCharacterSearch(text, pattern);
     return 0;
 } 
