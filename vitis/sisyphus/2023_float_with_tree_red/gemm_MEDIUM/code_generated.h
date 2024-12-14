typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;
    void kernel_nlp(float alpha, float beta, float4 vC[11000], float16 vA[3000], float4 vB[13200]) ;
