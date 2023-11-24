#include <iostream>
#include <vector>

using namespace std;

int n, m, k, already_know, know_head, ret;
int	head[54];
vector<int> v[54];

int get_head(int man)
{
	if (head[man] == man)
		return (man);
	if (head[man] == know_head)
		return (know_head);
	return (get_head(head[man]));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		head[i] = i;
	for (int i = 1; i <= k; i++)
	{
		cin >> already_know;
		if (know_head == 0)
			know_head = already_know;
		head[already_know] = know_head;
	}

	for (int i = 0; i < m; i++)
	{
		int num_of_participants;
		int man;
		int know_flag = 0;
		int before = 0;

		cin >> num_of_participants;
		for (int j = 0; j < num_of_participants; j++)
		{
			cin >> man;
			v[i].push_back(man);
			if (get_head(man) == know_head)
			{
				know_flag = 1;
				continue ;
			}
			if (j != 0 && before != 0)
				head[man] = before;
			before = man;
		}
		if (know_flag == 1)
			head[get_head(before)] = know_head;
	}

	for (int i = 0; i < m; i++)
	{
		if (get_head(v[i][0]) != know_head)
			ret++;
	}

	cout << ret << '\n';
	return 0;
}