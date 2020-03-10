#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    int min, max, i_min=0, curr_max=0, count=1; //min is initialized in "if" at line 15
    int i; 
    vector<int> array;
    stack<int> every_max;
    cin >> n; 

    for(i=0; i < n; i++){ //here we will collect the input and memorize the values of min, max and i_min
        int value;
        cin >> value;
        array.push_back(value);
        if(i == 0){
            min = value;
            max = value;
        }
        else if(min > value){
            i_min = i;
            min = value;
        }
        else if(max < value)
            max = value;
    }

    for(i=0; i <= i_min; i++){
        if(curr_max < array[i])
            curr_max = array[i];
    }
    bool slice_size; //this boolean represents whether or not the slice cointains more than 1 element
    i_min >= 1 ? slice_size = true : slice_size = false; 
    
    //the value of i is i_min (i=i_min), with that in mind we can do the following:
    if(curr_max != max)
        while(i < n){
            if(array[i] == max){
                if(slice_size)
                    count++;
                break;
            }
            else if(array[i] > curr_max){
                count++;
                every_max.push(curr_max);
                curr_max = array[i];
                slice_size=false;
            }
            else{
                while(!every_max.empty() && every_max.top() > array[i]){
                    count--;
                    every_max.pop();
                }
                slice_size=true;
            }
            i++;
        }

    cout << count << endl;

    return 0;
}
