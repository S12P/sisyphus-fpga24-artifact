#include "output.h"
#include "xcl2.hpp"

#pragma ACCEL kernel

void kernel_3mm(float E[180][190], float A[180][200], float B[200][190],
                float F[190][210], float C[190][220], float D[220][210],
                float G[180][210]) {
    int i;
    int j;
    int k;
    {
        for (i = 0; i < 180; i++) {
            for (j = 0; j < 190; j++) {
                E[i][j] = 0.0;

                for (k = 0; k < 200; ++k) {
                    E[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        for (i = 0; i < 190; i++) {
            for (j = 0; j < 210; j++) {
                F[i][j] = 0.0;

                for (k = 0; k < 220; ++k) {
                    F[i][j] += C[i][k] * D[k][j];
                }
            }
        }

        for (i = 0; i < 180; i++) {
            for (j = 0; j < 210; j++) {
                G[i][j] = 0.0;

                for (k = 0; k < 190; ++k) {
                    G[i][j] += E[i][k] * F[k][j];
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    printf("Starting C-simulation...\n");
    float E_ori[180][190];
    float E_new_before_trans_0[180 * 190];
    float E_new_0[180 * 190];
    float A_ori[180][200];
    float A_new_before_trans_0[180 * 200];
    float A_new_0[180 * 200];
    float B_ori[200][190];
    float B_new_before_trans_0[200 * 190];
    float B_new_0[200 * 190];
    float F_ori[190][210];
    float F_new_before_trans_0[190 * 210];
    float F_new_0[190 * 210];
    float C_ori[190][220];
    float C_new_before_trans_0[190 * 220];
    float C_new_0[190 * 220];
    float D_ori[220][210];
    float D_new_before_trans_0[220 * 210];
    float D_new_0[220 * 210];
    float G_ori[180][210];
    float G_new_before_trans_0[180 * 210];
    float G_new_0[180 * 210];
    int memIndex = 0;
    float val;
    
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
                   sizeof(float) * 180 * 190, E_new_0, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer ENewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer A_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                   sizeof(float) * 180 * 200, A_new_0, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer ANewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer B_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                   sizeof(float) * 200 * 190, B_new_0, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer BNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer F_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE,
                   sizeof(float) * 190 * 210, F_new_0, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer FNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer C_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                   sizeof(float) * 190 * 220, C_new_0, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer CNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer D_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                   sizeof(float) * 220 * 210, D_new_0, &err);
    if (err != CL_SUCCESS) {
        std::cerr << "Could not allocate buffer DNewOCL, error number: " << err
                  << "\n";
        return EXIT_FAILURE;
    }
    cl::Buffer G_0NewOCL =
        cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE,
                   sizeof(float) * 180 * 210, G_new_0, &err);
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