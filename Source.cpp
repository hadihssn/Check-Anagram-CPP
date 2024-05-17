#include <iostream>
using namespace std;

int calcLength(const char* string){
    int length = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

bool checkLength(const char* str1, const char* str2){
    if (calcLength(str1) == calcLength(str2))
        return true;
    return false;
}

void calcFreq(const char* string, int* freq){
    for (int i = 0; string[i] != '\0'; i++)
        freq[string[i]]++;
}

bool checkFrequencies(const char* str1, const char* str2){
    int freq1[256] = {0};
    int freq2[256] = {0};

    calcFreq(str1, freq1);
    calcFreq(str2, freq2);

    for (int i = 0; i < 256; i++)
    {
        if (freq1[i] != freq2[i])
            return false;
    }
    return true;
}

int main(){

    const char* str1 = "listen";
    const char* str2 = "siient";

    if (!checkLength(str1, str2)){
        cout << "Strings are of different lengths. Hence they cannot be anagrams\n";
        return 0;
    }

    if(!checkFrequencies(str1, str2)){
        cout << "The frequencies among letters of both words don't match. Hence they cannot be anagrams\n";
        return 0;
    }

    cout << "Both words " << str1 << " and " << str2 << " are anagrams\n";

    return 0;
}