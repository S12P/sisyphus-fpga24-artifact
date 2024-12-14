typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;
    void kernel_nlp(double alpha, double beta, double4 vC[11000], double16 vA[3000], double4 vB[13200]) ;
