typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;
    void kernel_nlp(float16 vx1[25], float16 vx2[25], float16 vy_1[25], float16 vy_2[25], float16 vA[10000]) ;