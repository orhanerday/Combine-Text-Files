Sure, here's a README file for your repository:


# Combine Text Files

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS-lightgrey)

## Description

Combine Text Files is a Python script that reads all text files in a directory and its subdirectories and combines them into a single file with delimiters. This tool is helpful for aggregating project files before uploading to AI tools like ChatGPT, Gemini, or Claude.

## Features

- Recursively scans directories for text files
- Combines text file contents into a single file with delimiters
- Cross-platform: Supports Linux (Snapcraft) and macOS (Homebrew)

## Installation

### Linux (Snapcraft)

1. **Install Snapcraft**:
   ```bash
   sudo apt update
   sudo apt install snapd
   ```

2. **Install Combine Text Files**:
   ```bash
   sudo snap install combine-text-files
   ```

### macOS (Homebrew)

1. **Install Homebrew**:
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. **Add the Homebrew Tap**:
   ```bash
   brew tap orhanerday/tools
   ```

3. **Install Combine Text Files**:
   ```bash
   brew install combine-text-files
   ```

## Usage

Navigate to the directory you want to scan and run the script:

```bash
combine-text-files
```

The script will create a `single_file.txt` in the current directory, containing the combined contents of all text files found.

## Example

Given a directory structure:

```
Project/
|-- file1.py
|-- subdir1/
    |-- file2.js
    |-- subdir2/
        |-- file3.cs
```

Running `combine-text-files` will produce a `single_file.txt` with the contents of `file1.py`, `file2.js`, and `file3.cs` separated by delimiters.

## Development

### Prerequisites

- Python 3.x

### Cloning the Repository

```bash
git clone https://github.com/orhanerday/combine-text-files.git
cd combine-text-files
```

### Running the Script Locally

```bash
python combine_text_files.py
```

## Contributing

Contributions are welcome! Please open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Inspired by the need to aggregate project files for AI tools.

## Contact

For any inquiries, please contact [your-email@example.com](mailto:your-email@example.com).

```

Replace `orhanerday` with your actual GitHub username and `your-email@example.com` with your contact email. This README covers the installation and usage for both Linux and macOS users, provides an example, and includes standard open-source project sections.