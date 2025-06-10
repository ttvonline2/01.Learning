{
	// Place your snippets for cpp here. Each snippet is defined under a snippet name and has a prefix, body and 
	// description. The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
	// same ids are connected.
	// Example:
	"Default code win": {
		"prefix": "shortMain",
		"body": [
			"#include \"bits/stdc++.h\"",
			"using namespace std;",
			"int main(){",
			"\t$1",
			"\treturn 0;",
			"}"
			
		],
		"description": "Log output to console"
	},
	"Default window": {
		"prefix": "fullWin",
		"body": [
			"$1#ifdef ONLINE_JUDGE",
			"#define vangtruong ios_base::sync_with_stdio(false); cin.tie(nullptr)//Expert --> delete",
			"#define hihihaha //*** debug ***//",
			"#define debug(...) //*** debug ***//",
			"#define DB(...) //*** debug ***//",
			"#include<bits/stdc++.h>",
			"#include <ext/pb_ds/assoc_container.hpp>",
			"#include <ext/pb_ds/tree_policy.hpp>",
			"using namespace std; using namespace __gnu_pbds;",
			"#define int long long",
			"#define oo 4e18",
			"#define MP make_pair",
			"#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)",
			"#define ROR(_i,_b,_a) for(int _i = (_b); _i >= (_b); _i--)",
			"#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)",
			"#define all(x) (x).begin(), (x).end()",
			"#define CR(_x,_n) (_x).clear(); (_x).resize((_n))",
			"using vb = vector<bool>; using vvb = vector<vb>; using vi = vector<int>; using vvi = vector<vi>; using vs = vector<string>; using vpi = vector<pair<int,int>>;",
			"using vc = vector<char>; using vvc = vector<vc>; using pi = pair<int,int>; int itemp = 0; string stemp = \"\"; using vvpi = vector<vector<pair<int,int>>>;",
			"template <typename T, typename Comp>",
			"using ordered_set_custom = tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>; // Comp = less<int>, less_equal<int>, greater<int>, StructComp",
			"#else",
			"#include \"D:/01.Learning/01.Algorithms/debug2.h\"",
			"#endif",
			"//**************************** CODING SPACE ****************************//",
			"",
			"void solve() {",
			"\t$2",
			"}",
			"",
			"int32_t main() {",
			"\tvangtruong; int tcs = 1; cin >> tcs;",
			"\twhile (tcs--) {solve();} hihihaha; return 0; }"
		],
		"description": "Log output to console"

	},

}