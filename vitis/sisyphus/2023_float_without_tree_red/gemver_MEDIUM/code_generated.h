typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;
    void kernel_nlp(float alpha, float beta, float16 vA[10000], float16 vu1[25], float16 ve1[25], float16 vu2[25], float16 ve2[25], float16 vw[25], float16 vx[25], float16 vy[25], float16 vz[25]) ;
