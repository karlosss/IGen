double artcomp1(double x) {
    return (((x<=-1141846027407.5315)||(!(x<=8549048570.46506)))?((1.0/(x+1.0))+((1.0/(x-1.0))-(2.0/x))):((((x+1.0)*((x*1.0)-((x-1.0)*2.0)))+(1.0*(x*(x-1.0))))/((x-1.0)*(x*(x+1.0)))));
}


double artcomp2(double x, double y) {
    return (((sqrt(2.0*(x+(sqrt((x*x)+(y*y))))))<=0.0)?((1.0/2.0)*((sqrt(2.0*(y*y)))/(sqrt((sqrt((x*x)+(y*y)))-x)))):(((sqrt(2.0*(x+(sqrt((x*x)+(y*y))))))<=3.107942901120382e+76)?((sqrt(2.0*(x+(sqrt((x*x)+(y*y))))))*(1.0/2.0)):((1.0/2.0)*(sqrt(2.0*(y*(y/((sqrt((x*x)+(y*y)))-x))))))));
}


int main() {
    double res1;
    res1 = artcomp1(10.0);
    double res2;
    res2 = artcomp1(100000000000.0);
    double res3;
    res3 = artcomp1(1e+101);
    double res4;
    res4 = artcomp1((-10.0));
    double res5;
    res5 = artcomp1((-100000000000.0));
    double res6;
    res6 = artcomp1((-1e+101));
    double res;
    res = artcomp2((-10.1), 2.1);
    return 0;
}

