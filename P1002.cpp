#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP( i, n ) for ( int i = 1; i <= n; i ++ )
#define FOR( i, a, b ) for ( int i = a; i <= b; i ++ )
#define DWN( i, a, b ) for ( int i = b; i >= a; i -- )
#define RST( a, x ) memset ( a, x, sizeof ( a ) );
#define NSIZE 200
#define LSIZE 100000
#define ONLINE_JUDGE NULL

using namespace std;
int s, t, l, n, ans = ( 1 << 30 );
int pos[ NSIZE ], dp[ LSIZE ];
bool st[ LSIZE ];
int main ()
{

#ifndef ONLINE_JUDGE
	freopen ( "P1002.in", "r", stdin );
	freopen ( "P1002.out", "w", stdout );
#endif

	RST ( dp, 40 );
	scanf ( "%d%d%d%d", &l, &s, &t, &n );
	REP ( i, n ) scanf ( "%d", &pos[ i ] );
	pos[ n + 1 ] = l;
	sort ( pos + 1, pos + n + 1 );
	REP ( i, n + 1 )
	{
		if ( s == t )
		{
			if ( ( pos[ i ] - pos[ i - 1 ] ) % s == 0 ) pos[ i ] = pos[ i - 1 ] + s;
			else pos[ i ] = pos[ i - 1 ] + ( pos[ i ] - pos[ i - 1 ] ) % s;
		}
		else if ( pos[ i ] - pos[ i - 1 ] > 600 ) pos[ i ] = pos[ i - 1 ] + ( pos[ i ] - pos[ i - 1 ] ) % 600;
		if ( i <= n ) st[ pos[ i ] ] = true;
	}
	dp[ 0 ] = 0;
	l = pos[ n + 1 ];
	FOR ( i, s, l + 20 )
	{
		FOR ( j, s, t )
			dp[ i ] = min ( dp[ i ], dp[ i - j ] + st[ i ] );
		if ( i >= l ) ans = min ( ans, dp[ i ] );
	}
	printf ( "%d\n", ans );
	return 0;
}
