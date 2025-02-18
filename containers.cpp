/* This file contains C++ conatiners including vector, list, map, multimap and unordered_map */
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

template<typename T>
void printVal(const T& numbers)
{
    for(const auto& num: numbers)
        cout << num << endl;
}
template<typename U>
void printMap(const U & mp)
{
    for(const auto& key: mp)
        cout << key.first << "--" << key.second << endl;
}

int main()
{
    int numbers[] = {78, 65, 42, 2, 10};
    
    vector<int> v = {43,56,3,12,10};
    
    list<double> l = {98.2,43.1,28.9, 56.2, 67.9};
    
    map<int,int> mp;
    
    mp[1] = 400;
    mp[4] = 800;
    
    mp.insert(make_pair(7,1200));
    
    mp[4] = 900;
    
    unordered_map<int, int> ump;
    
    ump.insert(make_pair(17,12));
    ump.insert(make_pair(45,82));
    ump.insert(make_pair(1,13));
    ump.insert(make_pair(5,56));
    ump.insert(make_pair(7,98));
    ump.insert(make_pair(89,13));
    
    multimap<int, int> mmp;
    
    mmp.insert(make_pair(1,400));
    mmp.insert(make_pair(4,800));
    mmp.insert(make_pair(7,1200));
    mmp.insert(make_pair(4,900));
    
    printVal(numbers);
    
    sort(begin(numbers), end(numbers), greater<int>{});
    
    printVal(numbers); 

    printVal(v);
    
    sort(v.begin(), v.end());
    
    v.push_back(15);
    
    printVal(v);
    
    printVal(l);
    
    printMap(mp);
    
    printMap(ump);
    
    printMap(mmp);
    
    return 0;
}
