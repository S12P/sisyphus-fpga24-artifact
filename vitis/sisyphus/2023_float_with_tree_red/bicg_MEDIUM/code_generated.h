typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;
    void kernel_nlp(float2 vA[79950], float2 vs[195], float2 vq[205], float2 vp[195], float2 vr[205]) ;