#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    int a, b, kol_ants, kol_shagov;
    freopen ("primer.txt", "r", stdin);
    scanf("%d%d%d%d",&a,&b,&kol_ants,&kol_shagov);
    printf("%d %d %d %d\n",a,b,kol_ants,kol_shagov);
    int Pole[a][b], Ants[kol_ants][4];
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++) scanf("%d",&Pole[i][j]);
        scanf("\n");
    }
    for(int i = 0; i < kol_ants; i++){
        int x, y, napravlenie;
        scanf("%d%d%d",&x,&y,&napravlenie);
        Ants[i][0] = y - 1;
        Ants[i][1] = x - 1;
        Ants[i][2] = napravlenie;
        Ants[i][3] = 1;
        Pole[y-1][x-1] += 2;
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++) cout<<Pole[i][j]<<" ";
        cout<<'\n';
    }
    cout<<'\n';
    for(int i = 0; i < kol_shagov; i++){
    cout<<i<<" shag"<<'\n';
        for(int j = 0; j < kol_ants, Ants[j][3] == 1; j++){
            Pole[Ants[j][0]][Ants[j][1]] -= 2;
            if(Pole[Ants[j][0]][Ants[j][1]] <= 1 and i != 0){
                if(Pole[Ants[j][0]][Ants[j][1]] == 1) Pole[Ants[j][0]][Ants[j][1]] = 0;
                else Pole[Ants[j][0]][Ants[j][1]] = 1;
            }
            if(Ants[j][2] == 1) Ants[j][0] -= 1;
            if(Ants[j][2] == 2) Ants[j][1] -= 1;
            if(Ants[j][2] == 3) Ants[j][0] += 1;
            if(Ants[j][2] == 4) Ants[j][1] += 1;
            Pole[Ants[j][0]][Ants[j][1]] += 2;
            if(Pole[Ants[j][0]][Ants[j][1]] % 2 == 1){
                if(Ants[j][2] == 4) Ants[j][2] = 1;
                else Ants[j][2] += 1;
            }
            else{
                if(Ants[j][2] == 1) Ants[j][2] = 4;
                else Ants[j][2] -= 1;
            }
            if((Ants[j][0] == 0 && Ants[j][2] == 1) || (Ants[j][0] == a-1 && Ants[j][2] == 3) || (Ants[j][1] == 0 && Ants[j][2] == 2) || (Ants[j][1] == b-1 && Ants[j][2] == 4)){
                Ants[j][3] == 0;
                if(Pole[Ants[j][0]][Ants[j][1]] == 3) Pole[Ants[j][0]][Ants[j][1]] = 0;
                if(Pole[Ants[j][0]][Ants[j][1]] == 2) Pole[Ants[j][0]][Ants[j][1]] = 1;
                if(Pole[Ants[j][0]][Ants[j][1]] > 3) Pole[Ants[j][0]][Ants[j][1]] -= 2;
                freopen ("yshel.txt", "w+", stdout);
                printf("%d %d",i,j+1);
                fclose(stdout);
            }
        }
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++) cout<<Pole[i][j]<<" ";
            cout<<'\n';
        }
        cout<<'\n';
    }
}