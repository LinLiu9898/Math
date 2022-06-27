#include "bits/stdc++.h"
using namespace std;

#define int int64_t
#define trav(i, a) for(auto& i: a)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define si(a) ((int)(a).size())
#define ins insert
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int MOD = 1e9 + 7;
const int INF = 1e18;
const string nl = "\n";

void remove(string& s, string p) {
	int n = si(p);
	for(string::size_type i = s.find(p); i != string::npos; i = s.find(p)) {
		s.erase(i, n);
	}
}

void replace(string& s, string target, string act) {
	size_t pos = s.find(target);
	while(pos != string::npos) {
		s.replace(pos, si(target), act);
		pos = s.find(target, pos + si(act));
	}
}

string change(string s) {
	string p = s;
	replace(p, "\\begin{asy}", "[asy]");
	replace(p, "\\end{asy}", "[/asy]");
	replace(p, "\\begin{proof}", "[i]Proof.[/i]");
	remove(p, "\\end{proof}");
	remove(p, "\\bigskip");
	remove(p, "\\eject");
	remove(p, "\\newpage");
	replace(p, "\\dang", "\\measuredangle");
	replace(p, "\\dg", "^\\circ");
	for(int i = 1; i <= 20; ++i) {
		string cur = "\\textbf{Claim ";
		cur += to_string(i);
		cur += ".}";
		string cur1 = "[color=blue][b]Claim ";
		cur1 += to_string(i);
		cur1 += ".[/b][/color]";
		replace(p, cur, cur1);
		cur = "\\textbf{Claim ";
		cur += to_string(i);
		cur += ":}";
		cur1 = "[color=blue][b]Claim ";
		cur1 += to_string(i);
		cur1 += ".[/b][/color]";
		replace(p, cur, cur1);
	}
	return p;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	vector<string> ans;
	string s;
	while(s != "lin liu") {
		getline(cin, s);
		//string p;
		//for(int i = 0; i < si(s); ++i) {
		//if(s[i] == '\\') {
		//p += s[i];
		//p += s[i];
		//} else {
		//p += s[i];
		//}
		//}
		//cout << p << nl;
		//s = p;
		if(s == "") {
			ans.pb("");
		} else {
			s = change(s);
			//replace(s, "asy", "asymptote");
			ans.pb(s);
		}
	}
	cout << nl << nl << nl << nl << nl << nl << nl << nl;
	cout << "OUTPUT-----------------------------------------" << nl;
	ans.pop_back();
	trav(i, ans) {
		cout << i << nl;
	}
}
