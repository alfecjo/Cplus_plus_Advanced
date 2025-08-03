#include <deque>

#include <iostream>

#include <algorithm>

#include <set>

using namespace std;

bool Compare(char _Left, char _Right)
{
    return tolower(_Left) < tolower(_Right);
}

int main()
{

    char s[] = {"lazybrownfox"};

    char pattern1[] = {"ybr"};

    char pattern2[] = {"nfo"};

    sort(s, s + 8, Compare);

    sort(pattern1, pattern1 + 3);

    sort(pattern2, pattern2 + 3);

    cout << includes(s, s + 7, pattern1, pattern1 + 3) << ", " << pattern2;

    return 0;
}
