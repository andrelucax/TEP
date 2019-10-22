#include <iostream>
#include <numeric>

using namespace std;

// Soma todos os dígitos da strings de dígitos s
// O operador binário default é a soma
int sum(const string& s)
{
    return accumulate(s.begin(), s.end(), 0, 
        [](int a, char b) { return a + (b - '0'); });
}

int main()
{
    cout << sum("12345") << '\n';
    
    return 0;
}
