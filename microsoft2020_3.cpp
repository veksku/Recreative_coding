#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    int min, max, i_min=0, curr_max=0, count=1; //min and max are both initialized in "if" at line 17
    int i; 
    vector<int> array;
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
    int slice_size = i_min;
    
    //the value of i is i_min (i=i_min), with that in mind we can do the following:
    if(curr_max != max)
        while(i < n){
            if(array[i] == max){
                if(slice_size != 1)
                    count++;
                break;
            }
            else if(array[i] > curr_max){
                count++;
                curr_max = array[i];
                slice_size=1;
            }
            else{
                slice_size++;
            }
            i++;
        }

    cout << count << endl;

    return 0;
}
