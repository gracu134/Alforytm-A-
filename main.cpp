#include <iostream>
#include <math.h>
#include <fstream>
#include <windows.h>
using namespace std;

class Krok{

public:
    int wsp_x;
    int wsp_y;
    double h;

    int wspk_x=19;
    int wspk_y=19;

    int wsps_x=0;
    int wsps_y=0;


    int wspr_x;
    int wspr_y;
    double hr;

    int koszt=0;

    void heurystyka(){

    hr=koszt+sqrt((pow((wsp_x-wspk_x),2))+(pow((wsp_y-wspk_y),2)));
    h=koszt+sqrt((pow((wsps_x-wspk_x),2))+(pow((wsps_y-wspk_y),2)));
    }

};
int main()

{




string nazwap="grid.txt";
int wym2=20;
int wym1=20;
int tab[9000];
int listz [9125];
int i=2;
int j=0;
int k=1;
int min2=0;
Krok kr0;
kr0.heurystyka();
Krok kr1;
Krok kr[19125];
kr[1].wsp_x=kr1.wsps_x;
kr[1].wsp_y=kr1.wsps_y;
kr1.heurystyka();
double min1=(2000);


int rows = wym2+1;
double **B;
B = new double*[rows];
while(rows--) B[rows] = new double[wym1+1];



std::ifstream plik(nazwap.c_str());

    for ( unsigned int i=0;i<wym2;i++)
    {
            for ( unsigned int j=0;j<wym1;j++)
            {
                plik >> B[i][j];
            }
    }

plik.close();
int A [wym2][wym1];
cout<<"\nWczytana Mapa\n\n";

    for(int i=0;i<wym2;i++)
    {
        for(int j=0;j<wym1;j++)
        {
            cout<<" "<<B[i][j];
            A[i][j]=B[i][j];
        }

        cout<<"\n";
    }












    cout<<"\n\nNacisnij ENTER aby przystapic do wyznaczania trasy "<<endl;
    cout<<"od punktu o wsp. "<<kr0.wsps_x<<" "<<kr0.wsps_y<<" do punktu o wsp. "<<kr0.wspk_x<<" "<<kr0.wspk_y;
    getchar();

    for( int k=1,koszt=1,z=0;i<=400;i++,z++){

        B[kr[k].wsp_x] [kr[k].wsp_y]=9;

        min1=(2000);

        if (kr[k].wsp_y-1>=0){
        if ( B[kr[k].wsp_x] [kr[k].wsp_y-1] ==0 ){

        kr[i].koszt=kr[k].koszt+1;
        kr[i].wsp_x=kr[k].wsp_x;
        kr[i].wsp_y=kr[k].wsp_y-1;
        kr[i].wspr_x=kr[k].wsp_x;
        kr[i].wspr_y=kr[k].wsp_y;
        kr[i].heurystyka();
        if (kr[i].wsp_x==kr[i].wspk_x && kr[i].wsp_y==kr[i].wspk_y)
            {
        //    cout<<"Cel osiagniety"<<endl;
         //   cout<<"Wsp x "<<kr[i].wsp_x<<endl;
         //   cout<<"Wsp y "<<kr[i].wsp_y<<endl;
         //   cout<<"wspr_x "<<kr[i].wspr_x<<endl;
         //   cout<<"wspr_y "<<kr[i].wspr_y<<endl;
         //   cout<<"hurystyka "<<kr[i].hr<<endl;;
        break;
        }
        tab[j]=i;

        //cout<<"Wsp x "<<kr[i].wsp_x<<endl;
       // cout<<"Wsp y "<<kr[i].wsp_y<<endl;
       // cout<<"Wspr x "<<kr[i].wspr_x<<endl;
       // cout<<"Wspr y "<<kr[i].wspr_y<<endl;
       // cout<<"hurystyka  "<<kr[i].hr<<endl;
        j++;
        }




        }

        if (kr[k].wsp_x-1>=0){
        if ( B[kr[k].wsp_x-1] [kr[k].wsp_y] ==0 ){
        i++;


        kr[i].wspr_x=kr[k].wsp_x;
        kr[i].wspr_y=kr[k].wsp_y;
        kr[i].wsp_x=kr[k].wsp_x-1;
        kr[i].wsp_y=kr[k].wsp_y;

        kr[i].koszt=kr[k].koszt+1;
        kr[i].heurystyka();

        if (kr[i].wsp_x==kr[i].wspk_x && kr[i].wsp_y==kr[i].wspk_y)
            {
        //    cout<<"Cel osiagniety"<<endl;
        //    cout<<"Wsp x "<<kr[i].wsp_x<<endl;
        //    cout<<"Wsp y "<<kr[i].wsp_y<<endl;
         //   cout<<"wspr_x "<<kr[i].wspr_x<<endl;
         //   cout<<"wspr_y "<<kr[i].wspr_y<<endl;
         //   cout<<"hurystyka "<<kr[i].hr<<endl;;
        break;

        }
        tab[j]=i;
        j++;
       // cout<<"Wsp x "<<kr[i].wsp_x<<endl;
       // cout<<"Wsp y "<<kr[i].wsp_y<<endl;
       // cout<<"Wspr x "<<kr[i].wspr_x<<endl;
       // cout<<"Wspr y "<<kr[i].wspr_y<<endl;
       // cout<<"hurystyka "<<kr[i].hr<<endl;

        }
        else
        {i--;
        j--;
        }
        }

        if (kr[k].wsp_y+1<wym1){
        if ( B[kr[k].wsp_x] [kr[k].wsp_y+1] ==0){
        i++;


        kr[i].wsp_x=kr[k].wsp_x;
        kr[i].wsp_y=kr[k].wsp_y+1;
        kr[i].wspr_x=kr[k].wsp_x;
        kr[i].wspr_y=kr[k].wsp_y;
        kr[i].koszt=kr[k].koszt+1;
        kr[i].heurystyka();

        if (kr[i].wsp_x==kr[i].wspk_x && kr[i].wsp_y==kr[i].wspk_y)
            {
       //     cout<<"Cel osiagniety"<<endl;
       //     cout<<"Wsp x "<<kr[i].wsp_x<<endl;
       //     cout<<"Wsp y "<<kr[i].wsp_y<<endl;
       //     cout<<"wspr_x "<<kr[i].wspr_x<<endl;
       //     cout<<"wspr_y "<<kr[i].wspr_y<<endl;
       //     cout<<"hurystyka "<<kr[i].hr<<endl;;
        break;
        }

         tab[j]=i;
        j++;

      //  cout<<"Wsp x "<<kr[i].wsp_x<<endl;
      //  cout<<"Wsp y "<<kr[i].wsp_y<<endl;
      //  cout<<"Wspr x "<<kr[i].wspr_x<<endl;
      //  cout<<"Wspr y "<<kr[i].wspr_y<<endl;
      //  cout<<"heurystyka "<<kr[i].hr<<endl;
        }

        }

        if (kr[k].wsp_x+1<wym2){
        if ( B[kr[k].wsp_x+1] [kr[k].wsp_y] ==0){
        i++;

        kr[i].wsp_x=kr[k].wsp_x+1;
        kr[i].wsp_y=kr[k].wsp_y;
        kr[i].wspr_x=kr[k].wsp_x;
        kr[i].wspr_y=kr[k].wsp_y;
        kr[i].koszt=kr[k].koszt+1;
        kr[i].heurystyka();

        if (kr[i].wsp_x==kr[i].wspk_x && kr[i].wsp_y==kr[i].wspk_y)
            {
       //     cout<<"Cel osiagniety"<<endl;
      //      cout<<"Wsp x "<<kr[i].wsp_x<<endl;
       //     cout<<"Wsp y "<<kr[i].wsp_y<<endl;
       //     cout<<"wspr_x "<<kr[i].wspr_x<<endl;
       //     cout<<"wspr_y "<<kr[i].wspr_y<<endl;
       //     cout<<"hurystyka "<<kr[i].hr<<endl;;

        break;
        }

        tab[j]=i;
        j++;



      //  cout<<"Wsp x "<<kr[i].wsp_x<<endl;
       // cout<<"Wsp y "<<kr[i].wsp_y<<endl;
       // cout<<"Wspr x "<<kr[i].wspr_x<<endl;
       // cout<<"Wspr y "<<kr[i].wspr_y<<endl;
       // cout<<"hurystyka "<<kr[i].hr<<endl;

        }

        }








        for(int n=0;n<=j+50;n++){

                for(int g=0;g<z;g++){

                    if (tab[n]==listz[g])
                    {
                        kr[tab[n]].hr=200;

                    }
                }

             if (kr[tab[n]].hr<min1){

                min1=kr[tab[n]].hr;
                k=tab[n];
             }



            }






        listz[z]=k;


      //  cout<<"minimum do sprawdzenia  "<<min1<<endl;
      // cout<<"adres "<<k<<endl;



    }


        //cout<<"Wsolrzedne konca :"<<kr[i].wsp_x<<" "<<kr[i].wsp_y<<endl;
      //  cout<<"Wsolrzedne rodzicow konca :"<<kr[i].wspr_x<<" "<<kr[i].wspr_y<<endl;



            int xr=kr[i].wspr_x, yr=kr[i].wspr_y;

            if (kr[i].wsp_x!=kr[i].wspk_x){
                    system( "cls" );
                cout<<"Nie znaleziono drogi"<<endl;
            } else{
            A[kr[i].wsp_x] [kr[i].wsp_y]=3;

        for( i=19125;i>2;i--){



            if (kr[i].wsp_x==xr && kr[i].wsp_y==yr){

                    A[xr][yr]=3;


              system( "cls" );

                cout<<"Wspolrzedne kroku= "<<xr<<" "<<yr<<endl;

                xr=kr[i].wspr_x;
                yr=kr[i].wspr_y;

              cout<<"\nTrasa\n\n";
            for(int i=0;i<wym2;i++)
          {
          for(int j=0;j<wym1;j++)
                   {
                       cout<<" "<<A[i][j];
                   }cout<<"\n";
               }
_sleep(500);


            }



        }

}





    return 0;
}
