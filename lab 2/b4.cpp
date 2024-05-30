#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

void onlyvowels(const char* s, char* t) {
    const char* vowels = "aeiouAEIOU";
    int j = 0; // Index for t
    for (int i = 0; s[i] != '\0'; ++i) {
        if (strchr(vowels, s[i])) {
            t[j++] = s[i];
        }
    }
    t[j] = '\0'; // Null-terminate the result string
}

int main() {
    // Dulustan's tests
    {
        {
            char s[]{"shinzowosasageyou"}, s1[100000]{}, ans[100000]{"iooaaeyou"};
            onlyvowels(s, s1);

            for (int i = 0; i < 99999; ++i) {
                assert(s1[i] == ans[i]);
            }
        }

        {
            char s[]{"aeyouiaoeuioaueieieuieiueuaooa"}, s1[100000]{}, ans[100000]{"aeyouiaoeuioaueieieuieiueuaooa"};
            onlyvowels(s, s1);

            for (int i = 0; i < 99999; ++i) {
                assert(s1[i] == ans[i]);
            }
        }

        {
            char s[]{"qrpvnbnhghhjjrttqkjkjkjkqqwwr"}, s1[100000]{}, ans[100000]{""};
            onlyvowels(s, s1);

            for (int i = 0; i < 99999; ++i) {
                assert(s1[i] == ans[i]);
            }
        }

        cout << "SUCCESS!" << endl;
    }

    // Student's tests
    {
        {
            char s[]{"Hello, World!"}, s1[100000]{}, ans[100000]{"eoo"};
            onlyvowels(s, s1);

            for (int i = 0; i < 99999; ++i) {
                assert(s1[i] == ans[i]);
            }
        }

        {
            char s[]{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"}, s1[100000]{}, ans[100000]{"AEIOUaeiou"};
            onlyvowels(s, s1);

            for (int i = 0; i < 99999; ++i) {
                assert(s1[i] == ans[i]);
            }
        }

        {
            char s[]{"bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"}, s1[100000]{}, ans[100000]{""};
            onlyvowels(s, s1);

            for (int i = 0; i < 99999; ++i) {
                assert(s1[i] == ans[i]);
            }
        }

        cout << "SUCCESS!" << endl;
    }

    return 0;
}
