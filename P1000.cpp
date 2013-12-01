#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP( i, n ) for ( int i = 1; i <= n; i ++ )
#define FOR( i, a, b ) for ( int i = a; i <= b; i ++ )
#define DWN( i, a, b ) for ( int i = b; i >= a; i -- )
#define RST( a, x ) memset ( a, x, sizeof ( a ) );
#define ONLINE_JUDGE NULL

using namespace std;
int a, b;
int main ()
{

#ifndef ONLINE_JUDGE
	freopen ( "P1000.in", "r", stdin );
	freopen ( "P1000.out", "w", stdout );
#endif

	scanf ( "%d%d", &a, &b );
	printf ( "%d\n", a + b );
	return 0;
}
