#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n);
};


int Solution::singleNumber(int A[], int n){
    int start = 0; int end = n-1;

    while(end > start){
        //pick one random pivot
        int pivot = rand()%(end-start+1) + start;

        //may be there is a same num 
        int pivot_s = -1;

        int itor = start+1;

        //divide the array between start and end into two parts
        int tmp = A[start];
        A[start] = A[pivot];
        A[pivot] = tmp;
        pivot = start;

        for(int i=start+1; i<=end; i++){
            //if smaller, put it to left
            if(A[i] <= A[pivot]){
                tmp = A[itor];
                A[itor] = A[i];
                A[i] = tmp;

                if(A[itor] == A[pivot])
                    pivot_s = itor;

                itor++;
            }
        }

        //move pivot and pivot_S to itor
        //for(int i=0; i<n; i++){
        //   cout<<A[i]<<" ";
        //}
        //cout<<endl;

        if(pivot_s >= 0){
            //cout<<"pivot "<<pivot<<endl;
            //cout<<"pivot s "<<pivot_s<<endl;
            //cout<<"itor "<<itor<<endl;
            //cout<<"tmp "<<tmp<<endl;
            tmp = A[pivot_s];
            A[pivot_s] = A[itor-2];
            A[itor-2] = tmp;

            //for(int i=0; i<n; i++){
            //   cout<<A[i]<<" ";
            //}
            //cout<<endl;
        }
        else{
            //lucky enough to choose the right number
            //cout<<"number p "<<pivot<<endl;

            return A[pivot];
        }

        tmp = A[pivot];
        A[pivot] = A[itor-1];
        A[itor-1] = tmp;
        pivot = itor-1;

        //check if the single number is in left or right side
        if((itor-2-start) % 2 == 1){
            //cout<<"itor "<<itor<<endl;
            start = start;
            end = itor-3;
        }
        else{
            if(itor < end)
                start = itor; 
            else{
                //cout<<"start "<<start<<" end "<<end<<endl;
                //cout<<"pivot "<<pivot<<endl;
                //for(int i=0; i<n; i++){
                //    cout<<A[i]<<" ";
                //}
                //cout<<endl;
 
                return A[end];
            }
            end = end;
        } 
    }

    
    //for(int i=0; i<n; i++){
    //    cout<<A[i]<<" ";
    //}
    //cout<<endl;
   
    //cout<<"start "<<start<<" end "<<end<<endl;

    return A[start];

}


int main()
{
    int a[] = {17,12,5,-6,12,4,17,-5,2,-3,2,4,5,16,-3,-4,15,15,-4,-5,-6};
    //int a[] = {1,3,3};

    Solution X;

    cout<<X.singleNumber(a, 21)<<endl;

    return 0;
}

