/*
整除
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int v_min = 1, v_max = 1e9+1;
    scanf("%d", &n);
    while (n -- ){
        int a, b;
        scanf("%d%d", &a, &b);
        v_min = max(v_min,a/(b+1)+1);
        v_max = min(v_max,a/b);
    }
    
    printf("%d %d",v_min,v_max);
    
    return 0;
}