/* This file contains C++ conatiners including vector, list, map, multimap, unordered_map, set, multiset, queue, priority queue and stack */
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>

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

    set<int> S1; //unique values are allowed
    multiset<int> MS1; //duplicate values are allowed;
    S1.insert(1), S1.insert(90), S1.insert(13), S1.insert(71), S1.insert(17), S1.insert(17);
    MS1.insert(1), MS1.insert(90), MS1.insert(13), MS1.insert(71), MS1.insert(17), MS1.insert(17);
    
    queue<int> q1;
    q1.push(40);
    q1.push(50);
    q1.push(4);
    
    priority_queue<int> pq1;
    pq1.push(40);
    pq1.push(50);
    pq1.push(4);
    
    stack<int> stk1;
    stk1.push(400);
    stk1.push(500);
    stk1.push(40);
    
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

    printVal(S1);

    printVal(MS1);
    
    cout << "Values stored in the queue" << endl;
    while(!q1.empty())
    {
        cout << q1.front() << endl;
        q1.pop();
    }
    
    cout << "Values stored in the priority queue" << endl;
    while(!pq1.empty())
    {
        cout << pq1.top() << endl;
        pq1.pop();
    }
    
    cout << "Values stored in the stack" << endl;
    while(!stk1.empty())
    {
        cout << stk1.top() << endl;
        stk1.pop();
    }
    
    return 0;
}
