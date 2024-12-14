# Sisyphus Artifact - Vitis Evaluation



## AutoDSE


| Kernel          | Tree Reduction | Latency       |
|------------------|----------------|---------------|
| 2mm             | No             | 43762069      |
| atax            | No             | 84311         |
| bert_100_3072   | No             | 77658         |
| bert_100_64     | No             | 4558          |
| bert_100_768    | No             | 20058         |
| bert_3072_100   | No             | 5666451611    |
| bicg            | No             | 165347        |
| doitgen         | No             | 363782        |
| gemm            | No             | 348353        |
| gemver          | No             | 993492        |
| mvt             | No             | 23259         |
| symm            | No             | 411504        |
| syr2k           | No             | 709189        |
| syrk            | No             | 351847        |
| trmm            | No             | 134840153     |
| 2mm             | Yes            | 22488395      |
| 3mm             | Yes            | 6536456       |
| atax            | Yes            | 81205         |
| bert_100_3072   | Yes            | 64988         |
| bert_100_64     | Yes            | 3907          |
| bert_100_768    | Yes            | 18281         |
| bert_3072_100   | Yes            | 32742920      |
| bicg            | Yes            | 161168        |
| doitgen         | Yes            | 90203         |
| gemm            | Yes            | 71573         |
| gemver          | Yes            | 104057        |
| mvt             | Yes            | 20522         |
| symm            | Yes            | 411503        |
| syr2k           | Yes            | 374869        |
| syrk            | Yes            | 351847        |
| trmm            | Yes            | 134840153     |

## NLP-DSE


| Kernel           | Tree Reduction | Latency         |
|-------------------|----------------|-----------------|
| 2mm              | No             | 76924.0         |
| 3mm              | No             | 84937.0         |
| atax             | No             | 85358.0         |
| bert_100_3072    | No             | 77658.0         |
| bert_100_64      | No             | 4398.0          |
| bert_100_768     | No             | 20058.0         |
| bicg             | No             | 165347.0        |
| cnn              | No             | 982044432.0     |
| doitgen          | No             | 180581.0        |
| gemm             | No             | 150951.0        |
| gemver           | No             | 232663.0        |
| gesummv          | No             | 33403.0         |
| mvt              | No             | 23259.0         |
| symm             | No             | 363503.0        |
| syr2k            | No             | 126468.0        |
| syrk             | No             | 124308.0        |
| trmm             | No             | 104225151.0     |
| 2mm              | Yes            | 74236.0         |
| 3mm              | Yes            | 82179.0         |
| atax             | Yes            | 81388.0         |
| bert_100_3072    | Yes            | 77007.0         |
| bert_100_64      | Yes            | 3747.0          |
| bert_100_768     | Yes            | 19407.0         |
| bicg             | Yes            | 161168.0        |
| cnn              | Yes            | 1076361750.0    |
| doitgen          | Yes            | 180203.0        |
| gemm             | Yes            | 60394.0         |
| gemver           | Yes            | 39592.0         |
| gesummv          | Yes            | 31709.0         |
| mvt              | Yes            | 20522.0         |
| symm             | Yes            | 59682630.0      |
| syr2k            | Yes            | 9846782.0       |
| syrk             | Yes            | 159855.0        |
| trmm             | Yes            | 104225151.0     |

## ScaleHLS
| Kernel           | Latency         |
|------------------|-----------------|
| 2mm              | 286757.0        |
| 3mm              | 312148.0         |
| atax             | 100744.0         |
| bicg             | 96805.0        |
| cnn              | 1076361750.0    |
| doitgen          | 563152.0        |
| gemm             | 226371.0         |
| gemver           | 213237.0         |
| gesummv          | 22578.0         |
| mvt              | 15247.0         |
| symm             | 134406161.0      |
| syr2k            | 212775446.0       |
| syrk             | 19270490.0        |
| trmm             | 38406173.0     |

## HARP

We obtained the results directly from the authors.

| Kernel  | Latency | Resource Usage (%) (BRAM,DSP,LUT,FF)   |
|---------|--------------------|----------------------|
| atax    | 92,991              | 78,52,49,50          |
| bicg    | 173,704              | 75,25,35,36          |
| gemm    | 63,152            | 29,80,55,40          |
| gemver  | 265,686              | 29,28,35,19          |
| mvt     | 22,644              | 40,78,43,30          |

Note: HARP uses AMD Vitis 2021.1, so all comparisons with HARP are conducted using Vitis 2021.1.

## Sisyphus - Vitis 2021.1 (vs. HARP)

| Kernel           | Latency         |
|------------------|-----------------|
| atax             | 81580.0         |
| bicg             | 81568.0        |
| gemm             | 90268.0         |
| gemver           | 125925.0         |
| mvt              | 19292.0         |


## Sisyphus - Vitis 2023.2 


| Kernel          | Tree Reduction | Latency      |
|------------------|----------------|--------------|
| 2mm             | No             | 53,537       |
| 3mm             | No             | 81,362       |
| atax             | No             | 85,739       |
| bert_100_3072   | No             | 63,719       |
| bert_100_64     | No             | 4,169        |
| bert_100_768    | No             | 17,700       |
| bert_3072_100   | No             | 5,725,740    |
| bicg            | No             | 86,129       |
| cnn             | No             | 120,469,970  |
| doitgen         | No             | 66,601       |
| gemm            | No             | 37,658       |
| gemver          | No             | 26,648       |
| gesummv         | No             | 34,597       |
| mvt             | No             | 16,412       |
| symm            | No             | 49,687       |
| syr2k           | No             | 40,281       |
| syrk            | No             | 25,987       |
| trmm            | No             | 18,334       |
| 2mm             | Yes            | 52,157       |
| atax             | Yes            | 81,769       |
| bert_100_3072   | Yes            | 63,579       |
| bert_100_64     | Yes            | 3,940        |
| bert_100_768    | Yes            | 16,304       |
| bert_3072_100   | Yes            | 1,498,491    |
| bicg            | Yes            | 81,769       |
| cnn             | Yes            | 130,841,042  |
| doitgen         | Yes            | 66,602       |
| gemm            | Yes            | 38,994       |
| gemver          | Yes            | 22,711       |
| gesummv         | Yes            | 31,920       |
| mvt             | Yes            | 12,082       |
| symm            | Yes            | 49,697       |
| syr2k           | Yes            | 67,905       |
| syrk            | Yes            | 53,686       |
| trmm            | Yes            | 16,158       |