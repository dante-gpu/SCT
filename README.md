# Simil CUDA Text (SCT)

A command-line tool for text similarity analysis.

## Description

This tool calculates the similarity between text files in a given directory. It reads all `.txt` files in the specified directory, preprocesses the text, and calculates the cosine similarity between each pair of files. The tool then outputs the file pairs that have a similarity score above a given threshold.

## Functionality

1.  **File Scanning:** Scans the input directory for `.txt` files.
2.  **Text Preprocessing:**
    *   Converts all text to lowercase.
    *   Removes punctuation.
    *   Tokenizes the text into words.
3.  **Vectorization:** Creates a term frequency (TF) vector for each document.
4.  **Similarity Calculation:** Calculates the cosine similarity between all pairs of TF vectors.
5.  **Output:** Prints the file pairs with a similarity score above the specified threshold.

## Command-Line Arguments

*   `-i <input_dir>`: The input directory containing the text files. Defaults to the current directory (`.`).
*   `-t <threshold>`: The similarity threshold between 0 and 1. Defaults to `0.85`.
*   `-o <output_file>`: The output file to write the results to. Defaults to `similarity_results.csv`.

## Usage

To run the application, use the following command:

```bash
/User/Github/Projects/SCT/sct -i <input_dir> -t <threshold>
```

For example:

```bash
/User/Github/Projects/SCT/sct -i data -t 0.5
```

This will calculate the similarity between all `.txt` files in the `data` directory and output the file pairs with a similarity score above `0.5`.

## Dependencies

*   C++11 or higher
*   CMake

## Building the Project

1.  Create a build directory: `mkdir build`
2.  Navigate to the build directory: `cd build`
3.  Run CMake: `cmake ..`
4.  Build the project: `make`

## Notes

This version of the tool uses a CPU-based implementation for similarity calculation.
