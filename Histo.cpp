#include <iostream>
#include <vector>
using namespace std;
void Histogram(int data_items,vector <int> list)
{


    //i will be including this file to my sectio challenge so that i can show histogram so commenting unimportant part


    //below code  is vertical histogram
    // int data_items{0};
    // vector<int> array{};
    // cout << "How many data items you have\n";
    // cin >> data_items;

    // cout << "Start entering the itmes\n";
    // for (int i{0}; i < data_items; i++)
    // {
    //     int itm{0};
    //     cin >> itm;
    //     array.push_back(itm);
    // }
    //  cout << "Displaying Horizontal Histogram \n";

    int max_element{0}, min_element{0};

    for (auto element:list)
    {
        if(max_element<element)
            max_element=element;
    //     else if(min_element>element)
    //         min_element=element;
    //     cout<<element<<" ";
    //     for(int i{0};i<element;i++)
    //         cout<<"-";
    //    cout<<endl;
    }
    //cout<<" Displaying Vertical Histogram"<<endl;
    
    
    
    
    cout<<"\nEvery * represents 5th count\n\n";
    
    for(int i{max_element};i>0;i--){
        for(int j{0};j<data_items;j++){
            if(list[j]>=i){
                if(i%5==0)
                    cout<<"* ";
                else   
                   cout<<"~ ";
            }
            else
                cout<<"  ";
        }
        cout<<endl;
        
    }
    for(auto element:list){
            cout<<element<<" ";
        }
    cout<<"\n\n";
}