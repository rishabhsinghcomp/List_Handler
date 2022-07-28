/*this is  a project(LIST_HANDLER) based on the idea to handle a list and 
perform various operation on list

**************features of list_handler*******************
1.print all elements
2.add anumber to list
3.display mean of all number of list
4.display smallest number
5.display largest number
6.quit
*7.add multiple nmber to list
*8.


////////////basic algorithm////////////
-create a list
-dispaly menu
-ask user for operation and for illegal opertion dispaly invalid choice (both lowrcase and 
uppercase charcters allowed)
-for each operation if list emty thn display emty list error
-dispaly menu after every choice and result
-for each operatrion dsipal a result message 
*/
#include <iostream>
#include <vector>
#include<limits>
#include "Histo.cpp"
using namespace std;
int main()
{
    //declaring initial variales and constant
    vector<int> array{};
    //also stroing a 'i' characyer so that it can work as an initiliser
    const vector<char> choices_list{'P','p','A','a','M','m','S','s','L','l','Q','q','k','K','c','C'};
    bool item_in_list{false};
    char choice{'p'};

    //intro
    
    
    while (choice!='q' && choice!='Q')
    {
        cout<<"Welcome to List Handler"<<endl;
        cout<<"P - Print all numbers"<<endl<<
              "A - Add a number "<<endl<<
              "M - Display Mean of numbers"<<endl<<
              "S - Display Smallest number"<<endl<< 
              "L - Display Largest number"<<endl<<
              "K - For Advanced Options"<<endl<<
              "C - To Clear the screen"<<endl<<
              "Q - Quit"<<endl;

        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        //checking if eneterd choice is correct
        for(auto itm:choices_list){
            if(itm==choice){
                item_in_list=1;
                break;
            }
            else
                item_in_list=0;
            }

            //controllin loop using choice if choice is invalid rthen reitrating loop
        if(item_in_list==0){
            cout<<"\nUnknown Selection, Please try again\n\n";
            choice='p';
            continue;
        }
        //starting exceution of selection

        //printing all elemtns
        if(choice=='p' || choice=='P'){
            if(array.size()==0){
                cout<<"\n[] - the list is empty\n\n";
                continue;
            }
            else{
                cout<<"\nDisplaying all numbers\n [ ";
                for(auto element:array){
                    cout<<element<<" ";
                }
                cout<<"]\n\n";
            }
        }

        //adding single element
        else if (choice=='a' || choice=='A'){
            int adding_element{0};
            cout<<"\n\nEnter an integer value \n";
            cin>>adding_element;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            array.push_back(adding_element);
            cout<<adding_element<<" added!\n\n";
        }
        //calculating mean
        else if(choice=='M' || choice=='m'){
            if(array.size()==0){
                cout<<"\nUnable to calculate the mean - no data!\n\n";
                continue;
            }
            else{
                int mean{0};
                for(auto element:array){
                    mean+=element;
                }
                mean/=array.size();
                cout<<"\n\nThe Mean of all elements is "<<mean<<"\n\n";
                }
        }

        //determinig smallest number 
        else if(choice=='S' || choice=='s'){
            if(array.size()==0){
                cout<<"\nUnable to determine smallest number - list is empty\n\n";
                continue;
            }
            else{
                int smallest{array.at(0)};
                for(auto element:array){
                    if(smallest>element)
                        smallest=element;
                }
                cout<<"\n\nThe Smallest number is "<<smallest<<"\n\n";
                }
        }

         //determinig largest number 
        else if(choice=='l' || choice=='L'){
            if(array.size()==0){
                cout<<"\nUnable to determine largest number - list is empty\n\n";
                continue;
            }
            else{
                int largest{0};
                for(auto element:array){
                    if(largest<element)
                        largest=element;
                }
                cout<<"\n\nThe Largest number is "<<largest<<"\n\n";
                }
        }



        //screenc clear
        else if(choice=='c'||choice=='C')
            system("clear");
            

        // this is the part where advanced options are included
        else if(choice=='k' || choice=='K'){
            system("clear");
            while(true){
                bool array_empty{0};
                if(array.size()==0){
                    cout<<"\n\nWARNING List is empty\t List must have atleast one element for advanced Settings to work\n\n";
                    cout<<"Please enter atleast one element\n  Redirecting to List element adder\n\n";
                    array_empty=1;
                }
                const vector<char> advanced_choices_list{'A','a','c','C','#','H','h','d','D'};
                //this will check if array is empty if empty then it will redirect it to list adder part
                if(array_empty==0){
                    cout<<"Welcome to List Handler"<<endl;
                    cout<<"Advanced Settings\n"<<endl;
                    cout<<"A - Adds multiple number to the list"<<endl<<
                          "H - Show Histogram of given List"<<endl<<
                          "D - To empty all the elements of list"<<endl<<
                          "C - To Clear the screen"<<endl<<
                          "# - To Return to Main Menu"<<endl;
                    cin>>choice;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
                else
                    choice='A';



                //checking if eneterd choice is correct
                for(auto itm:advanced_choices_list){
                    if(itm==choice){
                        item_in_list=1;
                        break;
                    }
                    else
                        item_in_list=0;
                }
                //controllin loop using choice if choice is invalid rthen reitrating loop
                if(item_in_list==0){
                    cout<<"\nUnknown Selection, Please try again\n\n";
                    continue;
                }

                else if (choice=='A'||choice=='a')
                {
                    int no_of_itm{0};
                    int data_item{};
                    cout<<"\n\nEnter the number of items you want to enter in the list\n";
                    cin>>no_of_itm;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<<"\n\nStart entering the items seperated by space or enter each value seperately\n\n";
                    for (int i{0}; i < no_of_itm; i++)
                    {
                        cin>>data_item;
                        array.push_back(data_item);
                    }
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<<no_of_itm<<" Integers Added to list\n\n";
                }

                //displaying histogram
                else if (choice=='H'||choice=='h')
                {
                    cout<<"\nHistogram Displayer\n\n";
                    Histogram(array.size(),array);
                    while(true){
                        char status{'/'};
                        cout<<"Press Any button to exit Histogram Displayer\n\n";
                        cin>>status;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        if(status!='/')
                            break;
                    }
                }
                else if (choice=='D'||choice=='d')
                {
                    cout<<"Enter Y to confirm choice";
                    cin>>choice;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    if(choice=='y'||choice=='Y'){
                        array.clear();
                    }
                }
                
                
                






















                else if (choice=='#')
                {
                    system("clear");
                    break;
            
                }
                
                //screenc clear
                else if(choice=='c'||choice=='C')
                    system("clear");





                



                

                
            }//while advaced setting ending


        }




    }//main while loop
        


}//main function

        

    

