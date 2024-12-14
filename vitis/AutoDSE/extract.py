import re

def extract_first_perf(file_path):
    """
    Extract the first performance value from the 'Perf.' column in the table.
    
    Args:
        file_path (str): Path to the file containing the table.
    
    Returns:
        int or str: The first performance value found, or a message if not found.
    """
    try:
        with open(file_path, 'r') as file:
            for line in file:
                # Use a regex to match the 'Perf.' column value (numeric value after '|' and whitespace)
                if "BRAM" in line:
                    perf = line.split('|')[3].strip()
                    return perf
        
        return "No performance value found in the file."

    except FileNotFoundError:
        return "File not found. Please check the file path."

l = ['./autodse_without_tree_reduction/doitgen_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/symm_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/bert_100_64/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/syrk_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/atax_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/trmm_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/bert_3072_100/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/syr2k_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/bert_100_3072/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/jacobi-2d_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/2mm_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/mvt_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/bicg_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/gemver_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/heat-3d_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_without_tree_reduction/gemm_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/doitgen_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/symm_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/syrk_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/atax_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/bert_100_768/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/trmm_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/bert_3072_100/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/syr2k_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/bert_100_3072/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/jacobi-2d_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/2mm_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/3mm_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/mvt_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/bicg_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/gemver_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/heat-3d_MEDIUM/_done/work_dir/output/fast/output.rpt', './autodse_tree_reduction/gemm_MEDIUM/_done/work_dir/output/fast/output.rpt']


# Usage example
if __name__ == "__main__":
    for file_path in l:
        result = extract_first_perf(file_path)
        print(f"{file_path}: {result}")