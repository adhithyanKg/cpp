/* This file contains lambda functions, vector and algorithm */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <double> salaries = {98000, 115000,45000, 87000, 100000, 28000};
    
    vector <double> filtered_salaries;
    
    vector <double> increased_salaries;
    
    double threshold, hike_percent;
    cout <<"enter threshold: "<<endl;
    cin >> threshold;
    
    cout <<"enter hike percent: "<<endl;
    cin >> hike_percent;
    
    copy_if(salaries.begin(), salaries.end(), back_inserter(filtered_salaries), [threshold](double salaries){return salaries>threshold;} );
    
    transform(filtered_salaries.begin(), filtered_salaries.end(), back_inserter(increased_salaries), [hike_percent](double salaries){return salaries*(hike_percent/100);});
    
    sort(increased_salaries.begin(), increased_salaries.end(), greater<double>{});
    
    cout<<"Employee salaries"<<endl;
    for (const auto& salary: salaries){
        cout<<salary<<endl;
    }
    
    cout<<"Filtered salaries"<<endl;
    for (const auto& salary: filtered_salaries){
        cout<<salary<<endl;
    }
    
    cout<<"Increased salaries"<<endl;
    for (const auto& salary: increased_salaries){
        cout<<salary<<endl;
    }
    
    return 0;
    
}
