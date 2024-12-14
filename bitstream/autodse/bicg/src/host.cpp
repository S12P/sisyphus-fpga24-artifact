#include "output.h"
#include "xcl2.hpp"


#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 5
#define SIZE_2 78
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 78
#include "memcpy_64_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"

int main(int argc, char* argv[]) {
    printf("Starting C-simulation...\n");
    // merlin_uint_64 A[79950];
    // merlin_uint_512 s[25];
    // merlin_uint_512 q[26];
    // merlin_uint_64 p[195];
    // merlin_uint_512 r[26];


    // char A[79950*64];
    // char s[25*512];
    // char q[26*512];
    // char p[195*64];
    // char r[26*512];

    float A[410*390];
    float s[390];
    float q2[410];
    float p[390];
    float r[410];

    // unsigned char A[79950][64/8];
    // unsigned char s[25][512/8];
    // unsigned char q[26][512/8];
    // unsigned char p[195][64/8];
    // unsigned char r[26][512/8];
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
    cl::Buffer A_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                   sizeof(float) * 410 * 390, A, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer ANewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }

    cl::Buffer s_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE,
                   sizeof(float) * 390, s, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer sNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer q_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE,
                   sizeof(float) * 410, q2, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer qNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer p_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                   sizeof(float) * 390, p, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer pNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer r_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                   sizeof(float) * 410, r, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer rNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    int argN = 0;
    kernel.setArg(argN++, A_0NewOCL);
    kernel.setArg(argN++, s_0NewOCL);
    kernel.setArg(argN++, q_0NewOCL);
    kernel.setArg(argN++, p_0NewOCL);
    kernel.setArg(argN++, r_0NewOCL);
    
    
    
    
    
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects(
                       {A_0NewOCL, p_0NewOCL, r_0NewOCL}, 0, nullptr,
                       nullptr));
    q.finish();
    cl::Event kernelCompute;
    OCL_CHECK(err, err = q.enqueueTask(kernel, nullptr, &kernelCompute));
    q.finish();
    kernelCompute.wait();
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({s_0NewOCL, q_0NewOCL},
                                                    CL_MIGRATE_MEM_OBJECT_HOST,
                                                    nullptr, nullptr));
    q.finish();



    printf("C-simulation passed!\n");
    uint64_t executionTime =
        kernelCompute.getProfilingInfo<CL_PROFILING_COMMAND_END>() -
        kernelCompute.getProfilingInfo<CL_PROFILING_COMMAND_START>();
    std::cout << "Time in seconds: " << (double)executionTime / pow(1000, 3)
              << "\n";
    return 0;


}
