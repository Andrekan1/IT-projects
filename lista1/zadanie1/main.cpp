#include <iostream>
#include <math.h>
#include <map>
using namespace std;

bool isNumFirst(int n) {
    if(n % 2 == 0)
        return (n == 2);
    for(int i = 3; i <= sqrt(n); i += 2)
        if(n % i == 0)
            return false;
    return true;
}

auto seekNumDist(int n) {
    int i = 1;
    while(pow(i,2)*2 < n) {
        int a = pow(i,2);
        int b = n - a;
        int sqrt_b = sqrt(b);
        if (pow(sqrt_b,2) == b) {
            return pair<int,int>(i,sqrt_b);
        }
        i++;
    }
    return pair<int,int>(0,0);
}

bool isNumDist(int n) {
    if (isNumFirst(n) and n % 4 == 1)
        return true;
    int div = n + 1;
    int counter = 0;

    while(div > 2) {
        div--;
        if (!isNumFirst(div))
            continue;

        counter = 0;
        while(n % div == 0) {
            n /= div;
            counter++;
        }
        if(counter % 2 == 1 and div % 4 == 3)
            return false;
    }
    return true;
}

int main() {
    int n; cin >> n;
    pair<int,int> result = seekNumDist(n);
    bool ifExists = isNumDist(n);
    if(result.first == 0) {
        cout << "rozklad nie isnieje" << endl;
    } else {
        cout << n << " = " << result.first << "^2 + " << result.second << "^2" << endl;
    }
    cout << "teoria " << (ifExists ? "jest rozklad" : "nie ma") << endl;
    return 0;
}
