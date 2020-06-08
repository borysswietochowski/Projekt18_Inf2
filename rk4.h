#ifndef __RK4_H__
#define __RK4_H__

// --------------------------------------------------------------------------
// Funkcja wykonuje, metodą Rungego-Kutty Iv-ego rzędu,
// jeden krok całkowania skalarnego równania rożniczkowego zwyczajnego:
//
//  dy/dx = fun(x,y),    y(x0)=y0
//
// Parametry formalne:
// x0 - wartość startowa zm. niezależnej
// y0 - wartość startowa zm. zależnej
// h  - krok całkowania
// fun(x,y) - nazwa funkcji obliczającej prawe strony
// y1 - obliczona wartość zmiennej zależnej w punkcie x0+h

double rk4( double x0, double y0, double h, double (*fun)(double, double));


// --------------------------------------------------------------------------
// Funkcja wykonuje, metodą Rungego-Kutty IV-tego rzedu,
// jeden krok całkowania wektorowego równania rożniczkowego zwyczjanego:
//
//  dY/dx = Fun(x,Y),    Y(x0)=Y0
//
// Parametry formalne:
// x0 - wartość startowa zm. niezależnej
// y0 - wartość startowa zm. zależnej (tablica n-elementowa)
// h  - krok całkowania
// n  - liczba równań
// fun(x,y,prawastr) - nazwa funkcji obliczającej prawe strony
// y1 - obliczona wartość zmiennej zależnej w punkcie x0+h
//      (tablica n-elementowa)

void vrk4( double x0, double y0[], double h, int n, void (*fun)(double, double*, double*, double, double, double), double y1[], double k, double a, double m);

#endif