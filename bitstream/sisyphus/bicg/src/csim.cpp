#include "output.h"

void kernel_bicg(float A[410][390], float s[390], float q[410], float p[390],
                 float r[410]) {
  int i;
  int j;
  {

    for (j = 0; j < 390; j++) {
      s[j] = 0.0;
    }

    for (i = 0; i < 410; i++) {
      for (j = 0; j < 390; j++) {
        s[j] = s[j] + r[i] * A[i][j];
      }
    }

    for (i = 0; i < 410; i++) {
      q[i] = 0.0;
    }

    for (i = 0; i < 410; i++) {
      for (j = 0; j < 390; j++) {
        q[i] = q[i] + A[i][j] * p[j];
      }
    }
  }
}

void kernel_nlp(float2 vA[79950], float2 vs[195], float2 vq[205], float2 vp[195], float2 vr[205]);

int main() {
  printf("Starting C-simulation...\n");
  float A_ori[410][390];
  float s_ori[390];
  float q_ori[410];
  float p_ori[390];
  float r_ori[410];

  float A_new[410][390];
  float s_new[390];
  float q_new[410];
  float p_new[390];
  float r_new[410];

  int memIndex = 0;
  float val;
  for (int i0 = 0; i0 < 410; i0++) {
    for (int i1 = 0; i1 < 390; i1++) {
      val = ((float)rand() / RAND_MAX);
      A_ori[i0][i1] = val;
      A_new[i0][i1] = val;
    }
  }


  for (int i0 = 0; i0 < 390; i0++) {
    val = ((float)rand() / RAND_MAX);
    s_ori[i0] = val;
    s_new[i0] = val;
  }

  for (int i0 = 0; i0 < 410; i0++) {
    val = ((float)rand() / RAND_MAX);
    q_ori[i0] = val;
    q_new[i0] = val;
  }

  for (int i0 = 0; i0 < 390; i0++) {
    val = ((float)rand() / RAND_MAX);
    p_ori[i0] = val;
    p_new[i0] = val;
  }
  for (int i0 = 0; i0 < 410; i0++) {
    val = ((float)rand() / RAND_MAX);
    r_ori[i0] = val;
    r_new[i0] = val;
  }
  kernel_bicg(A_ori, s_ori, q_ori, p_ori, r_ori);
  kernel_nlp((float2 *)A_new, (float2 *)s_new, (float2 *)q_new, (float2 *)p_new,
             (float2 *)r_new);


  for (int i0 = 0; i0 < 390; i0++) {
    if (abs(s_ori[i0] - s_new[i0 ]) > 0.0001) {
      printf("Error in s... %d %f %f\n", i0, s_ori[i0],
             s_new[i0 * 1]);
      return 1;
    }
  }

  for (int i0 = 0; i0 < 410; i0++) {
    if (abs(q_ori[i0] - q_new[i0]) > 0.0001) {
      printf("Error in q... %d %f %f\n", i0, q_ori[i0],
             q_new[i0 * 1]);
      return 1;
    }
  }
  printf("C-simulation passed!\n");
  return 0;
}