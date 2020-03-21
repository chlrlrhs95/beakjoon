#include <iostream>

using namespace std;

int N;
int A[12];
int Oper[4];
int OperOrder[11];
int MAXMIN[2];

void calculate(){
    static int cnt=0;
    int B[12];
    for(int i=0;i<N;i++){
        B[i]=A[i];
    }
    for(int i=0;i<N-1;i++){
        if(OperOrder[i]==0){
            B[i+1] = B[i]+B[i+1];
        }else if(OperOrder[i]==1){
            B[i+1] = B[i]-B[i+1];
        }else if(OperOrder[i]==2){
            B[i+1] = B[i]*B[i+1];
        }else if(OperOrder[i]==3){
            B[i+1] = B[i]/B[i+1];
        }
    }
    cnt++;
    if(cnt==1){
        MAXMIN[0]=B[N-1];
        MAXMIN[1]=B[N-1];
        return ;
    }
    MAXMIN[0] = MAXMIN[0]<B[N-1]?MAXMIN[0]:B[N-1];
    MAXMIN[1] = MAXMIN[1]>B[N-1]?MAXMIN[1]:B[N-1];

}

void sol(int num=0){
    if(num==N-1){
        calculate();
        return ;
    }
    for(int i=0;i<4;i++){
        if(Oper[i]>0){
            OperOrder[num]=i;
            Oper[i]--;
            sol(num+1);
            Oper[i]++;
        }
    }
    return ;
}


int main()
{
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<4;i++){
        cin>>Oper[i];
    }
    sol();
    cout << MAXMIN[1]<<endl;
    cout<<MAXMIN[0]<<endl;
    return 0;
}
