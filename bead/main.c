#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159

/*
Föld tömege: 5.9736 × 10sup>24 kg
Hold tömege: 7.349 × 1022 kg
Apogeum távolsága: 405.500 km
Sebesség apogeumban: 964 m/s
Perigeum távolsága: 363.300 km
Sebesség perigeumban: 1076 m/s
Gravitációs állandó: 6.67384 × 10-11 m3 kg-1 s--2
*/

int main()
{
    double Mf = 5.9736e+24;
    double Mh = 7.349e22;
    double M = Mh + Mf;
    //double Ra = 405500000;
    //double Va = 964;
    double Rp = 363300000;
    double Vp = 1076;
    double G = 6.67384e-11;
    double a = 384400000;
    double e = 0.0554;
    double fi = 0;

    int t = 0;
    double h = 1000;
    int T = 240000;
    FILE *fajl1 = fopen("plot/out.txt", "w");
    

    double *px;
    px = (double *)malloc(sizeof(double)*T);
    double *py;
    py = (double *)malloc(sizeof(double)*T);
    double *rx;
    rx = (double *)malloc(sizeof(double)*T);
    double *ry;
    ry = (double *)malloc(sizeof(double)*T);
    double *vx;
    vx = (double *)malloc(sizeof(double)*T);
    double *vy;
    vy = (double *)malloc(sizeof(double)*T);
    double *ax;
    ax = (double *)malloc(sizeof(double)*T);
    double *ay;
    ay = (double *)malloc(sizeof(double)*T);
    double *E_mech;
    E_mech = (double *)malloc(sizeof(double)*T);

    px[0] = Rp;
    py[0] = 0;
    rx[0] = Rp;
    ry[0] = 0;
    vx[0] = 0;
    vy[0] = Vp;
    ax[0] = (-G*M*rx[0])/pow(pow(rx[0],2)+pow(ry[0],2),1.5);
    ay[0] = (-G*M*ry[0])/pow(pow(rx[0],2)+pow(ry[0],2),1.5);

    while(t < T)
    {
        ax[t+1] = (-G*M*rx[t])/pow(pow(rx[t],2)+pow(ry[t],2), 1.5);
        ay[t+1] = (-G*M*ry[t])/pow(pow(rx[t],2)+pow(ry[t],2), 1.5);
        vx[t+1] = vx[t] + ax[t]*h;
        vy[t+1] = vy[t] + ay[t]*h;
        rx[t+1] = rx[t] + vx[t]*h;
        ry[t+1] = ry[t] + vy[t]*h;
        E_mech[t] = -G*Mf*Mh/(pow(pow(rx[t],2)+pow(ry[t],2),0.5))+0.5*Mh*(pow(vx[t],2)+pow(vy[t],2));

        fprintf(fajl1, "%d %f %f %f\n", t, rx[t], ry[t], E_mech[t]);
        t++;
    }

    t = 0;

    fclose(fajl1);
 
    return 0;
}
