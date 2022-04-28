#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol821;

/*
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 3.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.
*/

tuple<string, char, vector<int>>
testFixture1()
{
  return make_tuple("loveleetcode", 'e',
                    vector<int>{3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0});
}

/*
Input: s = "aaab", c = "b"
Output: [3,2,1,0]
*/

tuple<string, char, vector<int>>
testFixture2()
{
  return make_tuple("aaab", 'b',
                    vector<int>{3, 2, 1, 0});
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.calcDist(get<0>(f), get<1>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.calcDist(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}