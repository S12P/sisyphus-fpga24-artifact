typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;
    void kernel_nlp(float alpha, float beta, float16 vtemp2[3000], float16 vC[3000], float8 vA[5000], float16 vB[3000]) ;