#include "output.h"
#include "xcl2.hpp"

#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#include "memcpy_256_1d.h"
#define SIZE_1 190
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 25
#define SIZE_2 8
#include "memcpy_256_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 8
#define SIZE_2 190
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 210
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 220
#include "memcpy_128_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"


int main(int argc, char* argv[]) {
    printf("Starting C-simulation...\n");
    // merlin_uint_64 E[17100];
    // merlin_uint_256 A[4500];
    // merlin_uint_64 B[19000];
    // merlin_uint_64 F[19950];
    // merlin_uint_128 C[10450];
    // merlin_uint_64 D[23100];
    // merlin_uint_64 G[18900];

    float E[180 * 190];
    float A[180 * 200];
    float B[ 200 * 190];
    float F[190 * 210];
    float C[190 * 220];
    float D[220 * 210];
    float G[180 * 210];

    int memIndex = 0;

    cl_int err;
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device;
    for (unsigned int i = 0; i < devices.size(); i++) {
        device = devices[i];
        std::cout << "Trying to program device[" << i
                  << "]: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
#ifndef HW_SIM
        if (device.getInfo<CL_DEVICE_NAME>() ==
            "xilinx_u55c_gen3x16_xdma_base_3") {
#else
        if (device.getInfo<CL_DEVICE_NAME>() ==
            "xilinx_u55c_gen3x16_xdma_3_202210_1") {
#endif
            break;
        }
    }
    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, cl::CommandQueue q(context, device,
                                      CL_QUEUE_PROFILING_ENABLE, &err));
    OCL_CHECK(err,
              std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));
    std::string binary(argv[1]);
    auto fileBuf = xcl::read_binary_file(binary);
    cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
    OCL_CHECK(err, cl::Program program(context, {device}, bins, NULL, &err));
    OCL_CHECK(err, cl::Kernel kernel(program, "kernel_nlp", &err));
    cl::Buffer E_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE,
                   sizeof(float) * 180 * 190, E, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer ENewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer A_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                   sizeof(float) * 180 * 200, A, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer ANewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer B_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                   sizeof(float) * 200 * 190, B, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer BNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer F_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE,
                   sizeof(float) * 190 * 210, F, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer FNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer C_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                   sizeof(float) * 190 * 220, C, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer CNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer D_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                   sizeof(float) * 220 * 210, D, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer DNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer G_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE,
                   sizeof(float) * 180 * 210, G, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer GNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    int argN = 0;
    kernel.setArg(argN++, E_0NewOCL);
    kernel.setArg(argN++, A_0NewOCL);
    kernel.setArg(argN++, B_0NewOCL);
    kernel.setArg(argN++, F_0NewOCL);
    kernel.setArg(argN++, C_0NewOCL);
    kernel.setArg(argN++, D_0NewOCL);
    kernel.setArg(argN++, G_0NewOCL);
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects(
                       {A_0NewOCL, B_0NewOCL, C_0NewOCL, D_0NewOCL}, 0, nullptr,
                       nullptr));
    q.finish();
    cl::Event kernelCompute;
    OCL_CHECK(err, err = q.enqueueTask(kernel, nullptr, &kernelCompute));
    q.finish();
    kernelCompute.wait();
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects(
                       {E_0NewOCL, F_0NewOCL, G_0NewOCL},
                       CL_MIGRATE_MEM_OBJECT_HOST, nullptr, nullptr));
    q.finish();

    printf("C-simulation passed!\n");
    uint64_t executionTime =
        kernelCompute.getProfilingInfo<CL_PROFILING_COMMAND_END>() -
        kernelCompute.getProfilingInfo<CL_PROFILING_COMMAND_START>();
    std::cout << "Time in seconds: " << (double)executionTime / pow(1000, 3)
              << "\n";
    return 0;


}
