#include<bits/stdc++.h>
using namespace std;

class Heap {

    private:
        int n;
        int *ptr;
        static int k;

        void MakeHeap(int index){
            while(index != 1){
                if(ptr[index] > ptr[index/2]){
                    swap(ptr[index],ptr[index/2]);
                    index = index/2;
                }
                else{
                    break;
                }
            }
        }

        void Delete(int d){
            int j=1;
            swap(ptr[j],ptr[d--]);
            while(j != d){
                if(2*j == d){
                    int mx = max(ptr[j],ptr[2*j]);
                    if(mx == ptr[2*j]){
                        swap(ptr[j],ptr[2*j]);
                    }
                    break;
                }
                if(2*j > d){
                    break;
                }
                int mx = max(ptr[2*j],ptr[2*j+1]);
                if(mx == ptr[2*j]){
                    swap(ptr[j],ptr[2*j]);
                    j = 2*j;
                }
                else{
                    swap(ptr[j],ptr[2*j+1]);
                    j = (2*j+1);
                }
            }
        }
    
    public:

        Heap(int n){
            this->n = n;
            ptr = new int[this->n+1];
        }

        void Insert(int data){
            ++k;
            ptr[k] = data;
            MakeHeap(k);
        }

        void HeapSort(){
            
            int l = k;
            while(l != 1){
                Delete(l);
                --l;
            }
        }

        void Print(){
            for(int i=1;i<=k;i++){
                cout<<ptr[i]<<" ";
            }
            cout<<endl;
        }
};
int Heap :: k;

int main(){

    Heap h(6);
    h.Insert(15);
    h.Insert(27);
    h.Insert(35);
    h.Insert(14);
    h.Insert(8);
    h.Insert(5);
    h.Print();
    h.HeapSort();
    h.Print();
    return 0;
}