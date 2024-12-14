#ifndef PROMETHEUS_H
#define PROMETHEUS_H




#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>

#include <algorithm>
#include <cstring>
#include <iostream>

typedef hls::vector<float, 16> float16;
typedef hls::vector<float, 8> float8;
typedef hls::vector<float, 4> float4;
typedef hls::vector<float, 2> float2;
typedef hls::vector<float, 1> float1;

// void kernel_nlp(merlin_uint_64 A[79950],merlin_uint_512 x[26],merlin_uint_512 y[26],merlin_uint_512 tmp[25]);
#endif  // PROMETHEUS_H
