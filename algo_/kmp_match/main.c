#include <stdio.h>
#include <string.h>

// using namespace std;

void get_next(char s[], int next[])
{
    int i = 1, j = 0;
    unsigned long t = strlen(s);
    next[1] = 0;
    while (i < t)
    {
        if (j == 0 || s[i] == s[j])
        {
            j++;
            i++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int kmp_match(char src[], char s[])
{
    // 这个算法中下标从1开始
    int i = 1, j = 1;
    int next[strlen(s)];
    get_next(s, next);
    while (i <= strlen(src) && j <= strlen(s))
    {
        if (j == 0 || src[i - 1] == s[j - 1])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > strlen(s))
        return i - strlen(s);
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    char src[] = "sdadafasafasf";
    int i = kmp_match(src, "asp");
    printf("%d\n", i);
    return 0;
}
