typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;
    void kernel_nlp(float4 vA[30000], float4 vC4[900], float4 vsum[30000]) ;
