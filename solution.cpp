#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <string>
using namespace sol821;
using namespace std;

/*takeaways
  - re-calculate the distance for
    those that will be affected
    whenever a new occurrence of 'c' is found
*/

vector<int> Solution::calcDist(string s, char c)
{
  /* last index of the c found */
  auto cIndx = -1;
  auto result = vector<int>(s.size());

  for (auto i = 0; i < s.size(); i++)
  {
    if (s[i] == c)
    {

      /* update the distance for those that
         wil be affected by the introduction a
         new occurrence of 'c'
         - everything after cIndx should
           be recalculated
         - cIndx+1...i...s.size()
           - these are all affected by the
             introduction of a new occurrence
             of char 'c'
      */
      for (auto j = cIndx + 1; j < s.size(); j++)
        result[j] = cIndx == -1 ? i - j
                                : min(j - cIndx, abs(i - j));
      cIndx = i;
    }
  }

  return result;
}