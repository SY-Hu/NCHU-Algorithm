#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

int main(){
	int number = 100;
	vector<int> arr;
    arr.assign(number,0);  
	//int arr[number] = {0};
	//unsigned long long x = 0;
	int n = 0;
	//x = pow(2, number);
	int flag = 0;
	int max = 0;
	double diff = 0.0;
	time_t start, end;

	start = time(NULL);

	while (max < number){
	    //diff = difftime(end, start);
		//if(diff >= 3600){
			//break;
	//	}
	//for(unsigned long long i = 0; i < x; i++){
		if(flag != 0){
		    arr[number-1]++;
		} 
		for(int i=number-1; i >= 0; i--){
			if(n + arr[i] == 1){
				n = 0;
				arr[i] = 1;
			}else if(n + arr[i] == 2){
				n = 1;
				arr[i] = 0;
			}else{
				n = 0;
				arr[i] = 0;
				break;
			}
		}
		int count = 0;
		for(int j = 0; j < number; j++){
			if(arr[j] == 1){
				count++;
			}
			if(flag != 0){
				cout << arr[j];
			}else{
				cout << 0;
			}
			
		}
		if(count > max){
			max = count;
		}
		cout<< "  Count" << count << "   Max" << max << endl;
		flag++;
		end = time(NULL);
	}

	cout << "Time:  " << diff << " sec" << endl;
} 
