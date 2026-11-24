#include <random>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include <pdqsort.h>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace std;

  // pdqsort() with the default comparator.
  //
  {
    vector<int> v {5, 3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    vector<int> s (v);
    sort (s.begin (), s.end ());

    pdqsort (v.begin (), v.end ());
    assert (v == s);
  }

  // pdqsort() with a custom comparator.
  //
  {
    vector<int> v {5, 3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    vector<int> s (v);
    sort (s.begin (), s.end (), greater<int> ());

    pdqsort (v.begin (), v.end (), greater<int> ());
    assert (v == s);
  }

  // pdqsort_branchless() with the default comparator.
  //
  {
    vector<int> v {5, 3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    vector<int> s (v);
    sort (s.begin (), s.end ());

    pdqsort_branchless (v.begin (), v.end ());
    assert (v == s);
  }

  // Inputs above the insertion sort threshold, with duplicates, so that
  // partitioning is exercised as well.
  //
  vector<int> data (10000);
  {
    mt19937 g (42);
    uniform_int_distribution<int> d (0, 999);
    for (int& x: data)
      x = d (g);
  }

  // pdqsort() with the default comparator on a large input.
  //
  {
    vector<int> v (data);
    vector<int> s (v);
    sort (s.begin (), s.end ());

    pdqsort (v.begin (), v.end ());
    assert (v == s);
  }

  // pdqsort() with a non-default comparator on a large input.
  //
  {
    vector<int> v (data);
    vector<int> s (v);
    auto c ([] (int x, int y) {return x > y;});
    sort (s.begin (), s.end (), c);

    pdqsort (v.begin (), v.end (), c);
    assert (v == s);
  }

  // pdqsort_branchless() with a custom comparator on a large input.
  //
  {
    vector<int> v (data);
    vector<int> s (v);
    sort (s.begin (), s.end (), greater<int> ());

    pdqsort_branchless (v.begin (), v.end (), greater<int> ());
    assert (v == s);
  }

  // pdqsort() of a non-arithmetic type on a large input.
  //
  {
    vector<string> v;
    v.reserve (data.size ());
    for (int x: data)
      v.push_back (to_string (x));

    vector<string> s (v);
    sort (s.begin (), s.end ());

    pdqsort (v.begin (), v.end ());
    assert (v == s);
  }
}
