#include <iostream>
#include <vector>
using namespace std;

int N,M;
int board[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int back_dx[4] = {0,-1,0,1};
int back_dy[4] = {1,0,-1,0};
int find_2(){
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int l=0;l<M;l++){
            if(board[i][l]==2)
                cnt++;
        }
    }
    return cnt;
}

int sol(int x,int y,int dir){
    if(board[y][x]==0){
        board[y][x]=2;
    }
    if(board[y][x]==1){
        return find_2();
    }
    for(int i=0;i<4;i++){
        int next_search_x=x+dx[dir];
        int next_search_y=y+dy[dir];
        int next_dir = dir==0?3:dir-1;
        if(board[next_search_y][next_search_x]==0){
            return sol(next_search_x,next_search_y,next_dir);
        } else {
            dir = next_dir;
        }
    }

    return sol(x+back_dx[dir],y+back_dy[dir],dir);
}

int main()
{
    int r,c,d;
    cin>> N >> M;
    cin>>r>>c>>d;
    for(int i=0;i<N;i++){
        for(int l=0;l<M;l++){
            cin>>board[i][l];
        }
    }
    cout <<sol(c,r,d)<<endl;
    return 0;
}
