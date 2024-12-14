typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;
    void kernel_nlp(double alpha, double beta, double16 vA[10000], double16 vu1[25], double16 ve1[25], double16 vu2[25], double16 ve2[25], double16 vw[25], double16 vx[25], double16 vy[25], double16 vz[25]) ;
