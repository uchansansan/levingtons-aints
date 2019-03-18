#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    int a, b, kol_ants, kol_shagov;
    //int flag;
    freopen ("primer.txt", "r", stdin);
    scanf("%d%d%d%d",&a,&b,&kol_ants,&kol_shagov);
    printf("%d %d %d %d\n",a,b,kol_ants,kol_shagov);
    int Pole[a][b], Ants[kol_ants][4];
    FILE *out1,*out2;
    out1 = fopen ("yshel.txt", "w+");
    out2 = fopen("hodi.txt", "w+");
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++) scanf("%d    ",&Pole[i][j]);
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
    //flag = kol_ants;
    //cout << flag;
    for(int i = 0; i < kol_shagov; i++){
        for(int j = 0; j < kol_ants;  j++){
            if(Ants[j][3] == 1){
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
                    Ants[j][3] = 0;
                    //flag -= 1;
                    if(Pole[Ants[j][0]][Ants[j][1]] == 3) Pole[Ants[j][0]][Ants[j][1]] = 0;
                    if(Pole[Ants[j][0]][Ants[j][1]] == 2) Pole[Ants[j][0]][Ants[j][1]] = 1;
                    if(Pole[Ants[j][0]][Ants[j][1]] > 3) Pole[Ants[j][0]][Ants[j][1]] -= 2;
                    fprintf(out1, "%d %s - %d %s\n",i," shag",j+1,"myr");
                }
            }
        }
        fprintf(out2,"%d %s \n",i," shag");
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++)  fprintf(out2,"%d ",Pole[i][j]);
            fprintf(out2,"\n");
        }
        fprintf(out2,"\n");
        cout<<i<<"shag"<<'\n';
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++) cout<<Pole[i][j]<<" ";
            cout<<'\n';
        }
        cout<<'\n';
    }

    fclose(out1);
    fclose(out2);

}
