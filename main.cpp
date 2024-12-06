#include "sorting.h"

using namespace std;

int main()
{
	vector<int> vec1{ 1,2,3,5,4,6,7,8,9,10,11,12 };
	vector<int> vec2{1,2,3,5,4,6,7,8,9,10,11,12};
	stats<int> res;
	stats<int> res2;

	res = BublleSort(vec1);
	res2 = CombSort(vec2);

	cout << res.comparison_count << " and " << res.copy_count << endl;
	cout << res2.comparison_count << " and " << res2.copy_count << endl;

	return 0;
}
