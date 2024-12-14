import os


ll = os.listdir(".")

for l in ll:
    mini = float("inf")
    mlut = 0
    mff = 0
    mbram = 0
    mdsp = 0
    muram = 0
    if "_evaluation" in l and "." not in l:
        for l2 in os.listdir(f"{l}/"):
            if "only_nlp" in l2 and "." not in l2:
                # if "_done" not in os.listdir(f"{l}/{l2}/"):
                #     continue
                if "merlin.rpt" in os.listdir(f"{l}/{l2}/"):
                    f = open(f"{l}/{l2}/merlin.rpt", "r")
                    lines = f.readlines()
                    f.close()
                    for k, line in enumerate(lines):
                        if "Kernel" in line:
                            dd = lines[k+2].split("|")
                            lat = dd[2].split("(")[0].strip()
                            lut = dd[3].split("(")[-1].split("%")[0].replace("~", "")
                            ff = dd[4].split("(")[-1].split("%")[0].replace("~", "")
                            bram = dd[5].split("(")[-1].split("%")[0].replace("~", "")
                            dsp = dd[6].split("(")[-1].split("%")[0].replace("~", "")
                            uram = dd[7].split("(")[-1].split("%")[0].replace("~", "")
                            try:
                                lat = float(lat)
                            except:
                                lat = float("inf")
                            lut = int(lut)
                            ff = int(ff)
                            bram = int(bram)
                            dsp = int(dsp)
                            uram = int(uram)
                            if lut > 100 or ff > 100 or bram > 100 or dsp > 100 or uram > 100:
                                lat = float("inf")
                            if lat < mini:
                                mini=lat
                                mlut = lut
                                mff = ff
                                mbram = bram
                                mdsp = dsp
                                muram = uram
    print(l, mini, mdsp, mbram, mlut, mff, muram)  