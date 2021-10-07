#include<bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector<vector <T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector<vector<T>> v) {cerr << "\n"; for (auto i : v) { for( auto t : i){cerr<<t; cerr << " ";} cerr<<"\n";}}

bool isSafe(int row , int col , vector<vector<int>>& m , int n , vector<vector<bool>>& visited){
    
    if (row == -1 || row == n || col == -1 || col == n || visited[row][col] || m[row][col] == 0)
        return false;

    return true;
}

void getResult( vector<vector<int>>& m ,int n ,int row , int col , vector<string> &str , string& s , vector<vector<bool>>& visited){
    
    if (row == -1 || row == n || col == -1 || col == n || visited[row][col] || m[row][col] == 0)
        return;

    if (row == n - 1 && col == n - 1) {
        str.push_back(s);
        return;
    }

    visited[row][col] = true;

    if (isSafe(row + 1, col, m, n, visited))
    {
        s.push_back('D');
        getResult( m, n ,row + 1, col,str, s, visited);
        s.pop_back();
    }

    if (isSafe(row, col - 1, m, n, visited))
    {
        s.push_back('L');
        getResult( m, n,row, col - 1,str, s, visited);
        s.pop_back();
    }

    if (isSafe(row, col + 1, m, n, visited)) 
    {
        s.push_back('R');
        getResult(m, n,row, col + 1, str, s, visited);
        s.pop_back();
    }

    if (isSafe(row - 1, col, m, n, visited))
    {
        s.push_back('U');
        getResult(m , n , row - 1, col,str, s, visited);
        s.pop_back();
    }

    visited[row][col] = false;
}


vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    
    vector<string> str;
    string s = "";
    vector<vector<bool>> visited( n , vector<bool>( n , false));
    getResult( m , n , 0 , 0 ,str , s , visited);
    return str;     
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
fastio();

int n;
cin>>n;

vector<vector<int>> m( n ,vector<int>(  n));

for( int i = 0; i < n ;i++){
	for( int j = 0; j <n ; j++){

		cin>>m[i][j];
	}
}
 

 vector<string> res = findPath(  m ,n);

 for( auto i: res){
 	cout<<i<<"\n";
 }

return 0;

}

/*
Input:
5
1 0 0 0 0
1 1 1 1 1
1 1 1 0 1
0 0 0 0 1
0 0 0 0 1

Ouput:

DDRRURRDDD
DDRURRRDDD
DRDRURRDDD
DRRRRDDD

*/
