#include "sorting.h"

using namespace std;

int main()
{
	vector<int> vec1{6,5,4,3,2,1};
	stats<int> res;
	res = BublleSort(vec1);
	cout << res.comparison_count << " and " << res.copy_count << endl;


	return 0;
}
