#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

double f( double x){
    return (6435.0*pow(x,8)-12012.0*pow(x,6)+6930.0*pow(x,4)-1260.0*pow(x,2)+35)/128.0;
}

double fp(double x){
 return (6435.0*8.0*pow(x,7)-12012.0*6.0*pow(x,5)+6930.0*4.0*pow(x,3)-1260.0*2.0*x)/128.0;
}

int main()
{
    double xNew, xOld, xR, xL;
    double err, tol, LT, RT;
    int i =0;
    
    cout<< " Enter xL: "<<endl;
    cin>> xL;
    xOld = xL;
    cout<< " Enter xR: "<<endl;
    cin>> xR;
    cout<< " Enter tolerance: "<<endl;
    cin>> tol;
    
    do{
        LT = (xOld - xL ) * fp(xOld) - f(xOld);
        RT = (xOld - xR ) * fp(xOld) - f(xOld);
        i++;
        
        if (( LT * RT) <0.0){ ///  We do Newton-Raphson       
            xNew = xOld - (f(xOld)/ fp(xOld));
            cout<< " Newton-Raphson i= "<<i << " xNew = "<<xNew<<endl;
        }
        else{  //we do Bisection
            xNew = (xR + xL)/2.0;
            cout<< " Bisection i= "<< i << " xNew = "<< xNew<<endl;
        }
        //Change xR or xL
        if((f(xL)*f(xNew))<0.0){ // Root is between xL and xNew
            xR= xNew;
        }
        else { // Root is between xR and xNew
            xL= xNew;
        }
        
        err = fabs((xNew  - xOld)/ xNew); 
        xOld = xNew;
    }while( err > tol);
    
    cout<< "Root found at: "<< setprecision(8)<<xNew<< endl;
    cout<< "Numbers of iteration: "<<i <<endl;

    return 0;
}
