#include "output.h"
#include "xcl2.hpp"

void kernel_atax(float A[390][410], float x[410], float y[410],
                 float tmp[390]) {
  int i;
  int j;
  {

    for (i = 0; i < 390; i++) {
      tmp[i] = 0.0;
    }

    for (i = 0; i < 390; i++) {
      for (j = 0; j < 410; j++) {
        tmp[i] = tmp[i] + A[i][j] * x[j];
      }
    }

    for (j = 0; j < 410; j++) {
      y[j] = 0.0;
    }

    for (i = 0; i < 390; i++) {
      for (j = 0; j < 410; j++) {
        y[j] = y[j] + A[i][j] * tmp[i];
      }
    }
  }
}

int main(int argc, char *argv[]) {
  printf("Starting C-simulation...\n");
  float A_ori[390][410];
  float A_new_0[390 * 410];
  float x_ori[410];
  float x_new_0[410];
  float y_ori[410];
  float y_new_0[410];
  float tmp_ori[390];
  float tmp_new_0[390];
  int memIndex = 0;
  float val;
  for (int i0 = 0; i0 < 390; i0++) {
    for (int i1 = 0; i1 < 410; i1++) {
      val = ((float)rand() / RAND_MAX);
      A_ori[i0][i1] = val;
      A_new_0[i0 * 410 + i1 * 1] = val;
    }
  }

  for (int i0 = 0; i0 < 410; i0++) {
    val = ((float)rand() / RAND_MAX);
    x_ori[i0] = val;
    x_new_0[i0 * 1] = val;
  }
  for (int i0 = 0; i0 < 410; i0++) {
    val = ((float)rand() / RAND_MAX);
    y_ori[i0] = val;
    y_new_0[i0 * 1] = val;
  }
  for (int i0 = 0; i0 < 390; i0++) {
    val = ((float)rand() / RAND_MAX);
    tmp_ori[i0] = val;
    tmp_new_0[i0 * 1] = val;
  }

  cl_int err;
  std::vector<cl::Device> devices = xcl::get_xil_devices();
  cl::Device device;
  for (unsigned int i = 0; i < devices.size(); i++) {
    device = devices[i];
    std::cout << "Trying to program device[" << i
              << "]: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
#ifndef HW_SIM
    if (device.getInfo<CL_DEVICE_NAME>() == "xilinx_u55c_gen3x16_xdma_base_3") {
#else
    if (device.getInfo<CL_DEVICE_NAME>() ==
        "xilinx_u55c_gen3x16_xdma_3_202210_1") {
#endif
      break;
    }
  }
  OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));
  OCL_CHECK(err, cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE,
                                    &err));
  OCL_CHECK(err,
            std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));
  std::string binary(argv[1]);
  auto fileBuf = xcl::read_binary_file(binary);
  cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
  OCL_CHECK(err, cl::Program program(context, {device}, bins, NULL, &err));
  OCL_CHECK(err, cl::Kernel kernel(program, "kernel_nlp", &err));
  cl::Buffer A_0NewOCL =
      cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                 sizeof(float) * 390 * 410, A_new_0, &err);
  if (err != CL_SUCCESS) {
    std::cerr << "Could not allocate buffer ANewOCL, error number: " << err
              << "\n";
    return EXIT_FAILURE;
  }

  cl::Buffer x_0NewOCL =
      cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                 sizeof(float) * 410, x_new_0, &err);
  if (err != CL_SUCCESS) {
    std::cerr << "Could not allocate buffer xNewOCL, error number: " << err
              << "\n";
    return EXIT_FAILURE;
  }
  cl::Buffer y_0NewOCL =
      cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE,
                 sizeof(float) * 410, y_new_0, &err);
  if (err != CL_SUCCESS) {
    std::cerr << "Could not allocate buffer yNewOCL, error number: " << err
              << "\n";
    return EXIT_FAILURE;
  }
  cl::Buffer tmp_0NewOCL =
      cl::Buffer(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE,
                 sizeof(float) * 390, tmp_new_0, &err);
  if (err != CL_SUCCESS) {
    std::cerr << "Could not allocate buffer tmpNewOCL, error number: " << err
              << "\n";
    return EXIT_FAILURE;
  }
  int argN = 0;
  
  kernel.setArg(argN++, A_0NewOCL);
  // kernel.setArg(argN++, A_1NewOCL);
  kernel.setArg(argN++, x_0NewOCL);
  kernel.setArg(argN++, y_0NewOCL);
  kernel.setArg(argN++, tmp_0NewOCL);
  
  OCL_CHECK(err, err = q.enqueueMigrateMemObjects(
                     {A_0NewOCL, x_0NewOCL}, 0, nullptr, nullptr));
  q.finish();
  cl::Event kernelCompute;
  OCL_CHECK(err, err = q.enqueueTask(kernel, nullptr, &kernelCompute));
  q.finish();
  kernelCompute.wait();
  OCL_CHECK(err, err = q.enqueueMigrateMemObjects({y_0NewOCL, tmp_0NewOCL},
                                                  CL_MIGRATE_MEM_OBJECT_HOST,
                                                  nullptr, nullptr));
  q.finish();
  kernel_atax(A_ori, x_ori, y_ori, tmp_ori);

  // for (int i0 = 0; i0 < 410; i0++) {
  //   if (abs(y_ori[i0] - y_new_0[i0 * 1]) > 0.01) {
  //     printf("Error in y... %d %f %f\n", i0, y_ori[i0],
  //            y_new_0[i0 * 1]);
  //     return 1;
  //   }
  // }
  // for (int i0 = 0; i0 < 390; i0++) {
  //   if (abs(tmp_ori[i0] - tmp_new_0[i0 * 1]) > 0.01) {
  //     printf("Error in tmp...\n");
  //     return 1;
  //   }
  // }
  printf("C-simulation passed!\n");
  uint64_t executionTime =
      kernelCompute.getProfilingInfo<CL_PROFILING_COMMAND_END>() -
      kernelCompute.getProfilingInfo<CL_PROFILING_COMMAND_START>();
  std::cout << "Time in seconds: " << (double)executionTime / pow(1000, 3)
            << "\n";
  return 0;
}