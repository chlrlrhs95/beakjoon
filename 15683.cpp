#include <iostream>

using namespace std;

int board[10][10];
pair<int,int> CCTV[10];
int cctvNum=0;
int N,M;

          /*µ¿ ³² ¼­ ºÏ*/
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void find_cctv(){
    for(int i=0;i<N;i++){
        for(int l=0;l<M;l++){
            if(board[i][l]!=0 && board[i][l]!=6){
                pair<int,int> p = make_pair(i,l);
                CCTV[cctvNum++]=p;
            }
        }
    }
}

void fill_area(int x,int y,int moniorCase,int dir,int fil){
    if(moniorCase==1){
        while(x>=0 && x<M && y>=0 && y<N){
            if(board[y][x]==6) break;
            if(board[y][x]<=0){
                board[y][x]+=fil;
            }
            x=x+dx[dir];
            y=y+dy[dir];
        }
    } else if(moniorCase==2){
        for(int i=0;i<2;i++){
            int xx=x;
            int yy=y;
            while(xx>=0 && xx<M && yy>=0 && yy<N){
                if(board[yy][xx]==6) break;
                if(board[yy][xx]<=0){
                    board[yy][xx]+=fil;
                }
                xx=xx+dx[dir];
                yy=yy+dy[dir];
            }
            dir+=2;
        }
    } else if(moniorCase==3){
        for(int i=0;i<2;i++){
            int xx=x;
            int yy=y;
            while(xx>=0 && xx<M && yy>=0 && yy<N){
                if(board[yy][xx]==6) break;
                if(board[yy][xx]<=0){
                    board[yy][xx]+=fil;
                }
                xx=xx+dx[dir];
                yy=yy+dy[dir];
            }
            dir=dir+1;
            dir=dir%4;
        }
    } else if(moniorCase==4){
        for(int i=0;i<3;i++){
            int xx=x;
            int yy=y;
            while(xx>=0 && xx<M && yy>=0 && yy<N){
                if(board[yy][xx]==6) break;
                if(board[yy][xx]<=0){
                    board[yy][xx]+=fil;
                }
                xx=xx+dx[dir];
                yy=yy+dy[dir];
            }
            dir=dir+1;
            dir=dir%4;
        }
    } else if(moniorCase==5){
        for(int i=0;i<4;i++){
            int xx=x;
            int yy=y;
            while(xx>=0 && xx<M && yy>=0 && yy<N){
                if(board[yy][xx]==6) break;
                if(board[yy][xx]<=0){
                    board[yy][xx]+=fil;
                }
                xx=xx+dx[dir];
                yy=yy+dy[dir];
            }
            dir=dir+1;
            dir=dir%4;
        }
    }
}

int calculate(){
    int sum=0;
    for(int i=0;i<N;i++){
        for(int l=0;l<M;l++){
            if(board[i][l]==0)
                sum++;
        }
    }
    return sum;
}

int monitor(int num){
    if(num==cctvNum){
        return calculate();
    }
    int MAX=987654321;
    int y=CCTV[num].first;
    int x=CCTV[num].second;
    switch(board[y][x]){
        case 1:
            for(int l=0;l<4;l++){
                fill_area(x,y,board[y][x],l,-1);
                int ret = monitor(num+1);
                fill_area(x,y,board[y][x],l,1);
                MAX=MAX<ret?MAX:ret;
            }
            break;

        case 2:
            for(int l=0;l<2;l++){
                fill_area(x,y,board[y][x],l,-1);
                int ret = monitor(num+1);
                fill_area(x,y,board[y][x],l,1);
                MAX=MAX<ret?MAX:ret;
            }
            break;

        case 3:
            for(int l=0;l<4;l++){
                fill_area(x,y,board[y][x],l,-1);
                int ret = monitor(num+1);
                fill_area(x,y,board[y][x],l,1);
                MAX=MAX<ret?MAX:ret;
            }
            break;
        case 4:
            for(int l=0;l<4;l++){
                fill_area(x,y,board[y][x],l,-1);
                int ret = monitor(num+1);
                fill_area(x,y,board[y][x],l,1);
                MAX=MAX<ret?MAX:ret;
            }
            break;
        case 5:
            fill_area(x,y,board[y][x],0,-1);
            MAX = monitor(num+1);
            fill_area(x,y,board[y][x],0,1);
            break;
    }

    return MAX;
}

int main()
{

    cin>> N>>M;
    for(int i=0;i<N;i++){
        for(int l=0;l<M;l++){
            cin>>board[i][l];
        }
    }
    find_cctv();
    cout << monitor(0)<< endl;
    return 0;
}
