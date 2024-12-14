# Sisyphus Artifact - Bitstream Evaluation

## Result

| Kernel | GF/s (Ours) | Resource Usage (Ours: BRAM, DSP, LUT(K), FF(K)) | Resource Usage (AutoDSE: BRAM, DSP, LUT(K), FF(K)) | Performance Improvement |
|--------|-------------|-------------------------------------------------|---------------------------------------------------|--------------------------|
| 2mm    | 30.57       | 510, 556, 213, 276                              | 353.5, 963, 287, 292                              | 76.98x                   |
| 3mm    | 29.89       | 611, 984, 230, 300                              | 470, 1117, 278, 306                               | 72.34x                   |
| atax   | 1.03        | 450, 173, 240, 250                              | 630.5, 452, 170, 212                              | 4.63x                    |
| bicg   | 1.02        | 451, 173, 238, 265                              | 867.5, 196, 168, 217                              | 1.80x                    |


## Running the Bitstream

To run the bitstream, use the following commands:

```sh
cd ./sisyphus/<kernel>/src/bin
./test.real.out workload-hw.xclbin
