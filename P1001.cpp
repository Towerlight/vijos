#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP( i, n ) for ( int i = 1; i <= n; i ++ )
#define FOR( i, a, b ) for ( int i = a; i <= b; i ++ )
#define DWN( i, a, b ) for ( int i = b; i >= a; i -- )
#define RST( a, x ) memset ( a, x, sizeof ( a ) );
#define QN q[ i ].name
#define QS1 q[ i ].scr1
#define QS2 q[ i ].scr2
#define QT q[ i ].stu
#define QW q[ i ].west
#define QP q[ i ].pap
#define QZ q[ i ].prz
#define QO q[ i ].pos
#define TRUE == 'Y'
#define NSIZE 102
#define ONLINE_JUDGE NULL

using namespace std;
struct arr
{
	char name[ 30 ], stu[ 3 ], west[ 3 ];
	int scr1, scr2, pap, prz, pos;
};
int n, ans = 0;
arr q[ NSIZE ];
bool cmp ( arr a, arr b )
{
	if ( a.prz != b.prz ) return a.prz > b.prz;
	return a.pos < b.pos;
}
int main ()
{

#ifndef ONLINE_JUDGE
	freopen ( "P1001.in", "r", stdin );
	freopen ( "P1001.out", "w", stdout );
#endif

	scanf ( "%d", &n );
	REP ( i, n )
	{
		scanf ( "%s%d%d%s%s%d", QN, &QS1, &QS2, QT, QW, &QP );
		QZ = 0; QO = i;
		if ( QS1 > 80 && QP ) QZ += 8000;
		if ( QS1 > 85 && QS2 > 80 ) QZ += 4000;
		if ( QS1 > 90 ) QZ += 2000;
		if ( QS1 > 85 && QW[ 0 ] TRUE ) QZ += 1000;
		if ( QS2 > 80 && QT[ 0 ] TRUE ) QZ += 850;
		ans += QZ;
	}
	sort ( q + 1, q + n + 1, cmp );
	printf ( "%s\n%d\n%d\n", q[ 1 ].name, q[ 1 ].prz, ans );
	return 0;
}
