#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;

	struct HumanInfo
	{
		int m_Height;
		int m_ContinueCount;
	};

	stack<HumanInfo> m_Infos;
	long long count = 0;

	while (N--)
	{
		int height = 0;
		cin >> height;

		if (!m_Infos.empty())
		{
			while (!m_Infos.empty() && m_Infos.top().m_Height < height)
			{
				++count;
				count += m_Infos.top().m_ContinueCount - 1;
				if (m_Infos.size() != 1)
				{
					++count;
				}
				m_Infos.pop();
			}
		}
		
		int continuePlus = 0;
		if (!m_Infos.empty() && m_Infos.top().m_Height == height)
		{
			continuePlus = m_Infos.top().m_ContinueCount - ((m_Infos.size() == 1) ? 1 : 0);
		}

		m_Infos.emplace(HumanInfo{ height, 1 + continuePlus});
	}

	while (m_Infos.size() != 1)
	{
		count += m_Infos.top().m_ContinueCount;
		m_Infos.pop();
	}

	cout << count;
}