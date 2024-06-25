# Combine Text Files

Combine Text Files is a command-line tool that reads all text files in a directory and its subdirectories and combines them into a single file with delimiters. This tool is helpful for aggregating project files before uploading to AI tools like ChatGPT, Gemini, or Claude.

## Description

Combine Text Files is designed to simplify the process of consolidating text files from multiple directories into one comprehensive file. This is particularly useful when preparing data for machine learning models, generating comprehensive logs, or organizing documentation.

## Features

- **Recursive Directory Scanning**: Scans all subdirectories to find text files.
- **Flexible File Detection**: Detects and reads any file containing readable text.
- **Customizable Delimiters**: Appends file content with clear delimiters for easy separation.

## Installation

### Prerequisites

- **Homebrew**: Ensure you have Homebrew installed on your system. If not, you can install it by following the instructions on the [Homebrew website](https://brew.sh).

### Steps

1. **Tap the Repository**

   Add the custom Homebrew tap for Combine Text Files:

   ```bash
   brew tap orhanerday/tools
   ```

2. **Install the Tool**

   Install Combine Text Files using Homebrew:

   ```bash
   brew install combine_text_files
   ```

## Usage

Once installed, you can use Combine Text Files directly from the command line. Navigate to the directory containing the text files you want to combine, and run the command:

```bash
combine-text-files
```

This will create a file named `single_file.txt` in the current directory, containing the combined contents of all text files found in the directory and its subdirectories, with each file's content separated by delimiters.

### Example

Suppose you have the following directory structure:

```
Project/
│
├── file1.py
├── file2.txt
├── subdir1/
│   ├── file3.md
│   └── file4.js
└── subdir2/
    └── file5.java
```

Running `combine-text-files` in the `Project` directory will produce `single_file.txt` with the content:

```
File: file1.py
------
<content of file1.py>
------
File: file2.txt
------
<content of file2.txt>
------
File: file3.md
------
<content of file3.md>
------
File: file4.js
------
<content of file4.js>
------
File: file5.java
------
<content of file5.java>
------
```

## Contributing

Contributions are welcome! If you have suggestions for improvements or new features, feel free to open an issue or submit a pull request.

## License

Combine Text Files is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Contact

For any inquiries or issues, please contact Orhan Erday at orhan@duck.com.

---

Feel free to modify any section as needed. This README provides a comprehensive guide for users to understand, install, and use the Combine Text Files tool.