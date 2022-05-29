#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int g_galaxy_cluster_count = 0;
array<int, 100002> g_index_of_galaxy_cluster;
array<long long, 100002> g_planet_count;

struct ClusterInfo
{
	long long planet_count;
	vector<int> galaxys;
};

vector<ClusterInfo> g_galaxy_clusters_info;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	g_index_of_galaxy_cluster.fill(INT_MAX);

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> g_planet_count[i];

	while (m--)
	{
		int start, end;
		cin >> start >> end;

		int index_of_start_galaxy = g_index_of_galaxy_cluster[start];
		int index_of_end_galaxy = g_index_of_galaxy_cluster[end];

		if (index_of_start_galaxy == index_of_end_galaxy)
		{
			//새로운 은하단 생성
			if (index_of_start_galaxy == INT_MAX)
			{
				g_galaxy_clusters_info.emplace_back(ClusterInfo{ g_planet_count[start] + g_planet_count[end], {start, end} });
				g_index_of_galaxy_cluster[start] = g_galaxy_cluster_count;
				g_index_of_galaxy_cluster[end] = g_galaxy_cluster_count;
				++g_galaxy_cluster_count;
			}
			else
			{

			}
		}
		else
		{
			int index_of_parent_galaxy = min(index_of_start_galaxy, index_of_end_galaxy);
			int index_of_child_galaxy = max(index_of_start_galaxy, index_of_end_galaxy);
			int new_galaxy;
			if (index_of_parent_galaxy == index_of_start_galaxy)
				new_galaxy = end;
			else
				new_galaxy = start;

			//새로 발견된 은하를 은하단으로 병합
			if (index_of_child_galaxy == INT_MAX)
			{
				g_galaxy_clusters_info[index_of_parent_galaxy].planet_count += g_planet_count[new_galaxy];
				g_galaxy_clusters_info[index_of_parent_galaxy].galaxys.push_back(new_galaxy);
				g_index_of_galaxy_cluster[new_galaxy] = index_of_parent_galaxy;
			}
			//은하단을 은하단에 병합
			else
			{
				auto& parent_cluster = g_galaxy_clusters_info[index_of_parent_galaxy];
				auto& child_cluster = g_galaxy_clusters_info[index_of_child_galaxy];
				parent_cluster.planet_count += child_cluster.planet_count;
				for (int galaxy : child_cluster.galaxys)
				{
					parent_cluster.galaxys.push_back(galaxy);
					g_index_of_galaxy_cluster[galaxy] = index_of_parent_galaxy;
				}
			}
		}

		cout << g_galaxy_clusters_info[g_index_of_galaxy_cluster[start]].planet_count << '\n';
	}
}