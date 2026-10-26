# File-Integrity-Checker
A C++ project that detects file content changes using baseline comparison.
File Integrity Checker Using C++

Project Overview

The File Integrity Checker is a beginner-friendly C++ project that checks whether a text file's contents have changed by comparing them with a saved baseline.

Objectives

- Understand file handling in C++.
- Save a baseline copy of a file's contents.
- Detect content changes through comparison.
- Display a clear integrity status.

Features

- Create or update a baseline.
- Check file integrity.
- View the current file contents.
- View the saved baseline.
- Display a warning when content differs from the baseline.

Technologies Used

- Programming Language: C++
- Libraries: "iostream", "fstream", "string", and "limits"
- Platform: OnlineGDB

How to Use

1. Compile and run "main.cpp".
2. Create a text file named "sample.txt" in the program's working directory.
3. Select Create or Update Baseline and enter "sample.txt".
4. Select Check File Integrity to compare the file with the saved baseline.
5. Modify the file and check again to observe the result.
6. Update the baseline only when you intentionally want to accept the new contents.

Expected Results

- FILE IS SAFE: The file matches the saved baseline.
- FILE MODIFIED: The file contents differ from the saved baseline.
- ERROR: The file or baseline could not be read.

Limitations

This project compares file contents directly and does not use cryptographic hashes. It checks files when the user runs the program; it does not continuously monitor changes.
