typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;
    void kernel_nlp(float alpha, float beta, float2 vA[31250], float2 vB[31250], float2 vtmp[125], float2 vx[125], float2 vy[125]) ;