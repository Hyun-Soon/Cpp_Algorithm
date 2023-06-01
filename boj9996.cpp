#include <iostream>
#include <string.h>

using namespace std;

int n;
string norm;
string inp, pre, suf;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin.ignore();
	getline(cin, norm);
	int idx = norm.find('*');
	pre = norm.substr(0, idx);
	suf = norm.substr(idx + 1, norm.length());
	for (int i = 0; i < n; i++)
	{
		getline(cin, inp);
		if (inp.length() < pre.length() + suf.length())
		{
			cout << "NE\n";
			continue;
		}
		string inp_pre = inp.substr(0, pre.length());
		string inp_suf = inp.substr(inp.length() - suf.length());
		if (inp_pre == pre && inp_suf == suf)
			cout << "DA\n";
		else
			cout << "NE\n";
	}
	return 0;
}